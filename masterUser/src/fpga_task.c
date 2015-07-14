/*============================================================================
==============================================================================
                      
                              fpga_task.c
 
==============================================================================
Remarks:

      sekeleton to create the sample task

============================================================================*/

// system headers
#include "SL_system_headers.h"

/* SL includes */
#include "SL.h"
#include "SL_user.h"
#include "SL_tasks.h"
#include "SL_task_servo.h"
#include "SL_kinematics.h"
#include "SL_dynamics.h"
#include "SL_collect_data.h"
#include "SL_shared_memory.h"
#include "SL_man.h"

// call_mmap.c - A sample of python embedding (calling python functions from within C code)
// 
#include <python2.7/Python.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

#ifdef WIN32	// Windows includes
#include <Windows.h>
#include <process.h>
#define sleep(x) Sleep(1000*x)
HANDLE hFile, handle, map;
#else			// POSIX includes
//#include <pthread.h>
#include <sys/mman.h>

#endif


 

/* defines */





/* local variables */
static double start_time = 0.0;
static double freq;
static double amp;
static SL_DJstate  target[N_DOFS+1];
static int        use_invdyn     = TRUE;
static double		inertia_gain 				= 0.425;

#define NZEROS 4
#define NPOLES 4
#define GAIN   1.112983215e+06
static float xv[N_DOFS+1][NZEROS+1], yv[N_DOFS+1][NPOLES+1];
static float xa[N_DOFS+1][NZEROS+1], ya[N_DOFS+1][NPOLES+1];
static SL_DJstate  joint_filt_state[N_DOFS+1];

/* global functions */
#include <sys/stat.h>
#include <unistd.h>


/* global variables   */
char* g_fpga2robot = NULL;
char* g_robot2fpga = NULL;
char *homePath  ;   // environmental variable to use relative path. 
struct stat statbuf;   

/* local functions */
static int  init_fpga_task(void);
static int  run_fpga_task(void);
static int  change_fpga_task(void);

static SL_DJstate	extra_joint_state_filter(int);


/*****************************************************************************
******************************************************************************
Function Name	: add_fpga_task
Date		: Feb 1999
Remarks:

adds the task to the task menu

******************************************************************************
Paramters:  (i/o = input/output)

none

*****************************************************************************/
void
add_fpga_task( void )

{
  int i, j;
  
  addTask("Fpga Task", init_fpga_task, 
	  run_fpga_task, change_fpga_task);

}    

/*****************************************************************************
******************************************************************************
  Function Name	: init_fpga_task
  Date		: Dec. 1997

  Remarks:

  initialization for task

******************************************************************************
  Paramters:  (i/o = input/output)

       none

 *****************************************************************************/

/* error statement */
void err_sys(const char* x) 
{ 
    perror(x); 
    exit(1); 
}


static int 
init_fpga_task(void)
{
  int j, i;
  int ans;
  static int firsttime = TRUE;
  
 

  //enter code
    /* get home path */
    homePath= getenv ("HOME");
  
 
     //////////////////////////////////////////////////////////////////////////
    // Create a MMAP
    //////////////////////////////////////////////////////////////////////////
#ifdef WIN32
	/*// Create a 4K memory-mapped file (MMF)
	hFile = CreateFile((LPCTSTR) "input.dat", 
		GENERIC_WRITE | GENERIC_READ, 
		FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, 
		OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	
	if(hFile == INVALID_HANDLE_VALUE) 
	{
		// Failed to create file 
		return 1;
	}

	map = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 1024, "MMAPShmem");
	g_fpga2robot = (char *) MapViewOfFile (map, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0); 
	*/
#else



    printf("buffer_size: %d\n\n", statbuf.st_size);
	
	int fd_i;
    char* fgpa2robot_FilePath;
    fgpa2robot_FilePath = strncat(homePath, "/prog/masterUser/src/fpga2robot.dat", 100);  //max number of characers to be concatinated :100
    if((fd_i = open(fgpa2robot_FilePath, O_RDWR)) == -1)
	{
        printf("Couldn't open 'fpga2robot.dat'\n");
   	}
   	g_fpga2robot = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd_i, 0);
    
    if (g_fpga2robot == MAP_FAILED) {
        close(fd_i);
        perror("Error mmapping the file");
        exit(EXIT_FAILURE);
    }
    
    int fd_o;
    if((fd_o = open("/Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/src/robot2fpga.dat", O_RDWR)) == -1)
    {
        printf("Couldn't open 'robot2fpga.dat'\n");
    }
    lseek(fd_o, 0, SEEK_SET);
    g_robot2fpga = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd_o, 0);
    
    if (g_robot2fpga == MAP_FAILED) {
        close(fd_o);
        perror("Error mmapping the file");
        exit(EXIT_FAILURE);
    }
#endif

    if(g_fpga2robot != NULL)
    {	
        printf("Wrapper has created a MMAP for file 'fpga2robot.dat'\n");
    }

    if(g_robot2fpga != NULL)
    {   
        printf("Wrapper has created a MMAP for file 'robot2fpga.dat'\n");
    }
    
    /* find size of input file */
    if (fstat (fd_i, &statbuf) < 0)
        err_sys ("fstat error");

	system("/Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/src/py/py_mmap.py &");
  //end code



  
  

  if (firsttime){
    firsttime = FALSE;
    freq = 0.1; // frequency
    amp  = 0.5; // amplitude
  }

  // prepare going to the default posture
  bzero((char *)&(target[1]),N_DOFS*sizeof(target[1]));
  for (i=1; i<=N_DOFS; i++)
    target[i] = joint_default_state[i];

  // go to the target using inverse dynamics (ID)
  if (!go_target_wait_ID(target)) 
    return FALSE;

  // ready to go
  ans = 999;
  while (ans == 999) {
    if (!get_int("Enter 1 to start or anthing else to abort ...",ans,&ans))
      return FALSE;
  }
  
  // only go when user really types the right thing
  if (ans != 1) 
    return FALSE;




  start_time = task_servo_time;
  printf("start time = %.3f, task_servo_time = %.3f\n", 
	 start_time, task_servo_time);

  return TRUE;
}

/*****************************************************************************
******************************************************************************
  Function Name	: run_fpga_task
  Date		: Dec. 1997

  Remarks:

  run the task from the task servo: REAL TIME requirements!

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
static int 
run_fpga_task(void)
{
  int j, i;

  double task_time;
  double omega;  char * pPath;
  float tmpdata;
  float currentAngle;
  float currentAngularVel;
  
    // Random testing code


   //printf("The Main process has writen %d to MMAP.\n", i);
    sscanf(g_fpga2robot, "%f", &tmpdata);
    //printf("fpga -> robot : %f\n", tmpdata);
		


  // NOTE: all array indices start with 1 in SL

  task_time = task_servo_time - start_time;
  omega     = 2.0*PI*freq;
  
  	// some extra filtering for better inertial compensation (inherited from Michael Mistry's program)
	for (i=1; i<=N_DOFS; ++i)
	{
		joint_filt_state[i]					= extra_joint_state_filter(i);
	}

//   for (i=R_EB; i<=R_EB; ++i) {
//       target[i].th   = joint_default_state[i].th + tmpdata;
//     target[i].th   = joint_default_state[i].th +
//       amp*sin(omega*task_time);
//     target[i].thd   = amp*omega*cos(omega*task_time);
//     target[i].thdd  =-amp*omega*omega*sin(omega*task_time);
//   }

  // the following variables need to be assigned
//   for (i=1; i<=N_DOFS; ++i) {
//     joint_des_state[i].th   = target[i].th;
//     joint_des_state[i].thd  = target[i].thd;
//     joint_des_state[i].thdd = target[i].thdd;
//     joint_des_state[i].uff  = tmpdata;
//   }
  
  
    //tmpdata = tmpdata *3.14 / 180;   // convert to radian
    //printf("angle= %f\n", tmpdata);  // 
    
    //joint_des_state[R_EB].th = tmpdata; // in radian; //angular position 

  

    
    /* this copies the input file to the output file */
 //   memcpy(g_robot2fpga, g_fpga2robot,  statbuf.st_size);
    
    
     /* writeing attempts */
//    fwrite(&deltaLen, sizeof(double), 1, g_robot2fpga);
//fprintf

    //write(fd_o, "%f", currentLen);
    

    
    //*g_robot2fpga = currentLen;
      

for (i=1; i<=N_DOFS; ++i)
		{
           // gainControl = 0.1;
			// The one that is very noisy is the joint acceleration sensing, that's why we are using the filtered version of it
			// (joint_filt_state[i].thdd), instead of the unfiltered one (joint_state[i].thdd). Joint position (joint_state[i].th) and joint velocity (joint_state[i].thd)
			// on the other hand are not so noisy, so we are using the original (unfiltered) one.
			if (i == R_EB)
			{
				joint_des_state[i].th   = joint_state[i].th;
				joint_des_state[i].thd  = joint_state[i].thd;
                // joint_des_state[i].thdd  = joint_state[i].thdd; // use filter
                 joint_des_state[i].thdd = joint_filt_state[i].thdd * inertia_gain;	// multiplication by inertia gain here is maybe for reducing the risk of the system becoming unstable???

				//joint_des_state[i].thdd = joint_filt_state[i].thdd * inertia_gain;	// multiplication by inertia gain here is maybe for reducing the risk of the system becoming unstable???
				//joint_des_state[i].uff  = 0.0;
              
			}
			else
			{
				joint_des_state[i].th   = joint_des_state[i].th;	// don't change the joint_des_state;
				joint_des_state[i].thd  = 0.0;
				joint_des_state[i].thdd = 0.0;
				joint_des_state[i].uff  = 0.0;
			}
		}


    // compute inverse dynamics torques
  //   SL_InverseDynamics(joint_state, joint_des_state, endeff);
    SL_InvDynNE(joint_state,joint_des_state,endeff,&base_state,&base_orient);

     joint_des_state[R_EB].uff += tmpdata; // torque  += may be too slow for the reflex? 
    printf("input torque to robot= %f\n", tmpdata);  // 
  
    
       
   // joint_des_state[R_EB].th  = joint_state[R_EB].th;    
    //joint_des_state[R_EB].thd  = joint_state[R_EB].thd;      
    //joint_des_state[R_EB].thdd = joint_state[R_EB].thdd;    // acceleration data bad? just don't use it. 
    
    currentAngle =  joint_state[R_EB].th;     //Angle will calculate position
    currentAngularVel =  joint_state[R_EB].thd;   // Angular velocity
    //printf("currentLen in robot: %f\n", currentLen);
    
    sprintf(g_robot2fpga, "%.4f\t%.4f\n", currentAngle, currentAngularVel);

  return TRUE;
}


/*****************************************************************************
******************************************************************************
  Function Name	: extra_joint_state_filter
  Date			: Jan 2012

  Remarks:

  does some extra polynomial filtering on the velocities and 
  accelerations

******************************************************************************
  Parameters:  (i/o = input/output)

  \param[in]   i: DOF to be filtered

 *****************************************************************************/
static SL_DJstate 
extra_joint_state_filter(int i)
{
	SL_DJstate  filtered_output[N_DOFS+1];

    /* position is not filtered */
    filtered_output[i].th = joint_state[i].th;
  
    /* velocity filtering */
    xv[i][0] = xv[i][1]; xv[i][1] = xv[i][2]; xv[i][2] = xv[i][3]; xv[i][3] = xv[i][4]; 
    xv[i][4] = joint_state[i].thd / GAIN;
    yv[i][0] = yv[i][1]; yv[i][1] = yv[i][2]; yv[i][2] = yv[i][3]; yv[i][3] = yv[i][4]; 
    yv[i][4] =   (xv[i][0] + xv[i][4]) + 4 * (xv[i][1] + xv[i][3]) + 6 * xv[i][2]
               + ( -0.8485559993 * yv[i][0]) + (  3.5335352195 * yv[i][1])
               + ( -5.5208191366 * yv[i][2]) + (  3.8358255406 * yv[i][3]);
    filtered_output[i].thd = yv[i][4];

    /* acceleration filtering */
    xa[i][0] = xa[i][1]; xa[i][1] = xa[i][2]; xa[i][2] = xa[i][3]; xa[i][3] = xa[i][4]; 
    xa[i][4] = joint_state[i].thdd / GAIN;
    ya[i][0] = ya[i][1]; ya[i][1] = ya[i][2]; ya[i][2] = ya[i][3]; ya[i][3] = ya[i][4]; 
    ya[i][4] =   (xa[i][0] + xa[i][4]) + 4 * (xa[i][1] + xa[i][3]) + 6 * xa[i][2]
               + ( -0.8485559993 * ya[i][0]) + (  3.5335352195 * ya[i][1])
               + ( -5.5208191366 * ya[i][2]) + (  3.8358255406 * ya[i][3]);
    filtered_output[i].thdd = ya[i][4];
    
    return filtered_output[i];
}



/*****************************************************************************
******************************************************************************
  Function Name	: change_fpga_task
  Date		: Dec. 1997

  Remarks:

  changes the task parameters

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
static int 
change_fpga_task(void)
{
  int    ivar;
  double dvar;

  get_int("This is how to enter an integer variable",ivar,&ivar);
  get_double("This is how to enter a double variable",dvar,&dvar);

  return TRUE;

}


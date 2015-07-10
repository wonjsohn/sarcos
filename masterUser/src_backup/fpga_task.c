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

/* global functions */
#include <sys/stat.h>
#include <unistd.h>


/* global variables   */
char* g_fpga2robot = NULL;
char* g_robot2fpga = NULL;
struct stat statbuf;   

/* local functions */
static int  init_fpga_task(void);
static int  run_fpga_task(void);
static int  change_fpga_task(void);

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
    if((fd_i = open("/Network/Servers/duerer/guest/prog/masterUser/src/fpga2robot.dat", O_RDWR)) == -1)
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
    if((fd_o = open("/Network/Servers/duerer/guest/prog/masterUser/src/robot2fpga.dat", O_RDWR)) == -1)
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

	system("/Network/Servers/duerer/guest/prog/masterUser/src/py/py_mmap.py &");
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
  double omega;

  float tmpdata;
  float currentAngle;
  
    // Random testing code


   //printf("The Main process has writen %d to MMAP.\n", i);
    sscanf(g_fpga2robot, "%f", &tmpdata);
    //printf("fpga -> robot : %f\n", tmpdata);
		


  // NOTE: all array indices start with 1 in SL

  task_time = task_servo_time - start_time;
  omega     = 2.0*PI*freq;

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
   // printf("input torque to robot= %f\n", tmpdata);  // 
  
    joint_des_state[R_EB].uff = tmpdata; // torque 
    joint_des_state[R_EB].th  = joint_state[R_EB].th;    
    joint_des_state[R_EB].thd  = joint_state[R_EB].thd;    
    joint_des_state[R_EB].thdd = joint_state[R_EB].thdd;    
    
    currentAngle =  joint_state[R_EB].th; 
    //printf("currentLen in robot: %f\n", currentLen);
    
    /* this copies the input file to the output file */
 //   memcpy(g_robot2fpga, g_fpga2robot,  statbuf.st_size);
    
    
     /* writeing attempts */
//    fwrite(&deltaLen, sizeof(double), 1, g_robot2fpga);
//fprintf

    //write(fd_o, "%f", currentLen);
    
    sprintf(g_robot2fpga, "%f\n", currentAngle);
    //*g_robot2fpga = currentLen;
      


  // compute inverse dynamics torques
//   SL_InverseDynamics(joint_state, joint_des_state, endeff);

  
    
    

  return TRUE;
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


/*============================================================================
==============================================================================
                      
                              python_task_velocity_control.c
 
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
char* g_py2robot_velocity_control = NULL;
char* g_robot2py_velocity_control = NULL;
char *homePath  ;   // environmental variable to use relative path. 
char *homePath_copy  ;   // environmental variable to use relative path. 
struct stat statbuf;   

/* local functions */
static int  init_python_task_velocity_control(void);
static int  run_python_task_velocity_control(void);
static int  change_python_task_velocity_control(void);




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
add_python_task_velocity_control( void )

{
  int i, j;
  
  addTask("Replay recorded data (Velocity Control)", init_python_task_velocity_control, 
	  run_python_task_velocity_control, change_python_task_velocity_control);

}    

/*****************************************************************************
******************************************************************************
  Function Name	: init_python_task
  Date		: Aug. 2013

  Remarks:

  Open up a Python script and pass control variables in

******************************************************************************
  Paramters:  (i/o = input/output)

       none

 *****************************************************************************/

/* error statement */


void py_velocity_control_err_sys(const char* x) 
{ 
    perror(x); 
    exit(1); 
}


static int 
init_python_task_velocity_control(void)
{
  int j, i;
  int ans;
  static int firsttime = TRUE;
  
 

  //enter code
    /* get home path */
    homePath= getenv ("HOME");
    homePath_copy= getenv ("HOME");
  
 
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
		// Failed to create file homePath
		return 1;
	}

	map = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 1024, "MMAPShmem");
	g_fpga2robot = (char *) MapViewOfFile (map, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0); 
	*/
#else



 printf("buffer_size: %d\n\n", statbuf.st_size);
	
	int fd_i;
    char* py2robot_FilePath;
    py2robot_FilePath = strncat(homePath, "/prog/masterUser/src/py2robot.dat", 100);  //max number of characers to be concatinated :100
    if((fd_i = open(py2robot_FilePath, O_RDWR)) == -1)
	{
        printf("Couldn't open 'py2robot.dat'\n");
   	}
   	g_py2robot_velocity_control = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd_i, 0);
    
    if (g_py2robot_velocity_control == MAP_FAILED) {
        close(fd_i);
        perror("Error mmapping the file");
        exit(EXIT_FAILURE);
    }
    
    int fd_o;
    //char* robot2fpga_FilePath;
    //robot2fpga_FilePath = strncat(homePath_copy, "/prog/masterUser/src/robot2fpga.dat", 100);  //max number of characers to be concatinated :100
    if((fd_o = open("/Network/Servers/duerer/guest/prog/masterUser/src/robot2py.dat", O_RDWR)) == -1)
   // if((fd_o = open(robot2fpga_FilePath, O_RDWR)) == -1)
    {
        printf("Couldn't open 'robot2py.dat'\n");
    }
    lseek(fd_o, 0, SEEK_SET);
    g_robot2py_velocity_control = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd_o, 0);
    
    if (g_robot2py_velocity_control == MAP_FAILED) {
        close(fd_o);
        perror("Error mmapping the file");
        exit(EXIT_FAILURE);
    }
#endif

    if(g_py2robot_velocity_control != NULL)
    {	
        printf("Wrapper has created a MMAP for file 'py2robot.dat'\n");
    }

    if(g_robot2py_velocity_control != NULL)
    {   
        printf("Wrapper has created a MMAP for file 'robot2py.dat'\n");
    }
    
    /* find size of input file */
    if (fstat (fd_i, &statbuf) < 0)
        py_err_sys ("fstat error");

	system("/Network/Servers/duerer/guest/prog/masterUser/src/py/py2robot_velocity_control.py &");
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
  Function Name	: run_python_task
  Date		: Aug. 2013

  Remarks:

  run the task from the task servo: REAL TIME requirements!

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
static int 
run_python_task_velocity_control(void)
{
  int j, i;
  static int count=0;


  double task_time;
  double omega;  char * pPath;
  float tmpdata;
  float currentAngle;
  float currentAngularVel;
  
    // Random testing code


	
    sscanf(g_py2robot_velocity_control, "%f", &tmpdata); // read elbow Force from python?

		


  // NOTE: all array indices start with 1 in SL

  task_time = task_servo_time - start_time;
  omega     = 2.0*PI*freq;



        joint_des_state[R_EB].thd =  tmpdata;  
           
        currentAngle =  joint_state[R_EB].th;     //Angle will calculate position
        currentAngularVel =  joint_state[R_EB].thd;   // Angular velocity

	sprintf(g_robot2py_velocity_control, "%.4f\t%.4f\n", currentAngle, currentAngularVel); // write elbow angle and velocity from robot?

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
change_python_task_velocity_control(void)
{
  int    ivar;
  double dvar;

  get_int("This is how to enter an integer variable",ivar,&ivar);
  get_double("This is how to enter a double variable",dvar,&dvar);

  return TRUE;

}


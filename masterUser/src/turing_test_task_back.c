/*============================================================================
==============================================================================
                      
                              turing_test_task.c
 
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
#include "time.h"

// file input output
#include <stdlib.h>
#include <stdio.h>
#include <time.h>



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
#define  ARRAYLEN 	 10000

/* local variables */
static double start_time = 0.0;
static double freq0, freq1, freq2;
static double amp0, amp1, amp2;
static SL_DJstate  target[N_DOFS+1];
static int        use_invdyn     = TRUE;

static int k = 0; //index for Array read from txt. 
static double pos2DArray[3]; // (coeff0, coeff1, coeff2) : offset, poscoeff, velcoeff

/* global functions */



/* local functions */
static int  init_turing_test_task(void);
static int  run_turing_test_task(void);
static int  change_turing_test_task(void);

/*****************************************************************************
******************************************************************************
Function Name	: add_turing_test_task
Date		: Feb 1999
Remarks:

adds the task to the task menu

******************************************************************************
Paramters:  (i/o = input/output)

none

*****************************************************************************/
void
add_turing_test_task( void )

{
  int i, j;
  
  addTask("turing_test_task", init_turing_test_task, 
	  run_turing_test_task, change_turing_test_task);

}    

/*****************************************************************************
******************************************************************************
  Function Name	: init_turing_test_task
  Date		: Dec. 1997

  Remarks:

  initialization for task

******************************************************************************
  Paramters:  (i/o = input/output)

       none

 *****************************************************************************/

/* error statement 
void err_sys(const char* x) 
{ 
    perror(x); 
    exit(1); 
}
*/

static int 
init_turing_test_task(void)
{
  int j, i;
  int ans;
  static int firsttime = TRUE;

  // prepare going to the default posture
  bzero((char *)&(target[1]),N_DOFS*sizeof(target[1]));
  for (i=1; i<=N_DOFS; i++)
	target[i] = joint_default_state[i];

  // go to the target using inverse dynamics (ID)
  if (!go_target_wait_ID(target))
	return FALSE;


  
  if (firsttime){
    firsttime = FALSE;
    freq0 = 0.5; // frequency
    freq1 = 0.9; 
    freq2 = 1.4; 
    amp0  = 1.0/2; // amplitude
    amp1  = 3.0/2;
    amp2  = 6.0/2;
  }

  // prepare going to the default posture

/*
  bzero((char *)&(target[1]),N_DOFS*sizeof(target[1]));
  for (i=1; i<=N_DOFS; i++)
    target[i] = joint_default_state[i];
*/

 // read coefficient array from txt. (pos / vel / force)
  FILE *fp = fopen("regressionData/regressionCoeff.txt", "r"); 
  if (!fp) {
    fprintf(stderr, "Can't open file.\n");
    //exit(EXIT_FAILURE);
  }

  double temp;
  int p = 0;
 
    //read lines 
    const char s[2] = ",";
    char *token;
    int m;
    if(fp != NULL)
    {
        char line[100]; //10 is enough per line
        fgets(line, sizeof line, fp);
        
            token = strtok(line, s);
            for(m=0;m<3;m++)  // m: number of coeff
            {	
		
		printf("%f\t",atof(token));
		pos2DArray[m] = atof(token);
		token = strtok(NULL,s);	

/*
                if(m==0)
                {   
		    //printf("%i\t", m);
                   
		    pos2DArray[0] = atof(token);
                } else {
	            token = strtok(NULL,s);
		    //printf("%i\t", m);
                    printf("%f\n",atof(token));
		    pos2DArray[1] = atof(token);

                }       
*/
            }
	
        
        fclose(fp);
    }

/*
  int l;
  for (l = 0; l < ARRAYLEN ; l++) {
      printf("pos2dArray %i,  %f\n", l, pos2DArray[l][0]);
  }
*/
printf("a0:%f, a1:%f, a2:%f\n", pos2DArray[0], pos2DArray[1],pos2DArray[2]);


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


  // start data collection
  scd();
  printf("Data collection started\n");

  return TRUE;
}

/*****************************************************************************
******************************************************************************
  Function Name	: run_turing_test_task
  Date		: Dec. 1997

  Remarks:

  run the task from the task servo: REAL TIME requirements!

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
static int 
run_turing_test_task(void)
{
  int j, i;

  double task_time;
  double omega0, omega1, omega2, torque;
  double posCoef, velCoef, loadCoef, gravity;
  double gainControl;

 

/*
posCoef = -3.734;
velCoef = 0.713;
loadCoef = 0.921;
*/
/*
posCoef = -1.4703;
velCoef = -0.1102;
loadCoef = 1.1288;
*/
gravity = 8.0;
loadCoef = 0.921;

task_time = task_servo_time - start_time;


joint_des_state[R_EB].th   = joint_state[R_EB].th;
joint_des_state[R_EB].thd  = joint_state[R_EB].thd;
joint_des_state[R_EB].thdd = joint_state[R_EB].thdd;


omega0 = joint_state[R_EB].th;  
omega1 = joint_state[R_EB].thd;
torque = joint_state[R_EB].load;


//goal: find a coefficients posCoef, velCoef, loadCoef really fast!!
// regress on ufb and *add gravity* 

gainControl = 0.6;
//joint_des_state[R_EB].uff =(pos2DArray[0]+ pos2DArray[1]*omega0 + pos2DArray[2]*omega1)*0.1 + gravity ; // + (loadCoef*torque)*1.0; //+ gravity; 
joint_des_state[R_EB].uff = (pos2DArray[0]+ pos2DArray[1]*omega0 + pos2DArray[2]*omega1)*gainControl ; // + (loadCoef*torque)*1.0; //+ gravity;   // no gravity since it should have been taken care in playback - record stage. 

//joint_des_state[R_EB].uff = tmpdata; // torque
//joint_des_state[R_EB].uff = gravity;//(posCoef*omega0 + velCoef*omega1 + loadCoef*torque)*(0.1) + gravity;
//joint_des_state[R_EB].uff = (posCoef*omega0 + velCoef*omega1 + loadCoef*torque)*0.1;

  // compute inverse dynamics torques
  //SL_InverseDynamics(joint_state, joint_des_state, endeff);
  SL_InvDynNE(joint_state,joint_des_state,endeff,&base_state,&base_orient);
  
  return TRUE;
}

/*****************************************************************************
******************************************************************************
  Function Name	: change_turing_test_task
  Date		: Dec. 1997

  Remarks:

  changes the task parameters

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
static int 
change_turing_test_task(void)
{
  int    ivar;
  double dvar;

  get_int("This is how to enter an integer variable",ivar,&ivar);
  get_double("This is how to enter a double variable",dvar,&dvar);

  return TRUE;

}



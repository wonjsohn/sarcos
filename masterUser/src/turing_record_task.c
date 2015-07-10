/*============================================================================
==============================================================================
                      
                            turing_record_task.c
  
==============================================================================
Remarks:
 
    Generates an analoge pulse out of the physical oscilloscope for
    sincronization purposes
 
============================================================================*/
 
// system headers
#include "SL_system_headers.h"
 
// SL includes
#include "SL.h"
#include "SL_user.h"
#include "SL_tasks.h"
#include "SL_task_servo.h"
#include "SL_kinematics.h"
#include "SL_dynamics.h"
#include "SL_collect_data.h"
#include "SL_shared_memory.h"
#include "SL_man.h"
#include "SL_oscilloscope.h" //Oscilloscope library (physical and virtual)
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 
// defines
 
// local variables
static double start_time = 0.0;
static SL_DJstate  target[N_DOFS+1];
static double wait_time = 10.00;
static int ivar = 0; flag = 0;

static double R_TL_threshold = 0.08; // threshold of activate/inactivate thumb-in (R_TL) switch
 
// global functions
 
// local functions
static int  init_turing_record_task(void);
static int  run_turing_record_task(void);
static int  change_turing_record_task(void);
 
 
/*****************************************************************************
******************************************************************************
Function Name    : add_turing_record_task
Date     : June 2014
Remarks:
 
adds the task to the task menu
 
******************************************************************************
Paramters:  (i/o = input/output)
 
none
 
*****************************************************************************/
void
add_turing_record_task( void )
 
{
  int i, j;
  
  addTask("turing_record_task", init_turing_record_task,
       run_turing_record_task, change_turing_record_task);
 
}   
 
/*****************************************************************************
******************************************************************************
  Function Name    : init_turing_record_task
  Date       : June 2014
 
  Remarks:
 
  initialization for task
 
******************************************************************************
  Paramters:  (i/o = input/output)
 
    none
 
 *****************************************************************************/
static int
init_turing_record_task(void)
{
  int j, i;
  int ans;
  char string[100];
  static int firsttime = TRUE;

  if (firsttime){
    firsttime = FALSE;
    //freq = 0.1; // frequency
    //amp  = 0.5; // amplitude
  }

 
  // prepare going to the default posture
  bzero((char *)&(target[1]),N_DOFS*sizeof(target[1]));
  for (i=1; i<=N_DOFS; i++)
    target[i] = joint_default_state[i];
 
  // go to the target using inverse dynamics (ID)
  if (!go_target_wait_ID(target))
    return FALSE;
 

 
  /* add trigger signal to virtual oscilloscope:    
  add the variable name to prog/masterUser/prefs/task_default.osc*/
  updateOscVars();
 
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
  //scd();
  //printf("Data collection started\n");
 
  return TRUE;
}
 
/*****************************************************************************
******************************************************************************
  Function Name    : run_turing_record_task
  Date       : June 2014
 
  Remarks:
 
  run the task from the task servo: REAL TIME requirements!
 
******************************************************************************
  Paramters:  (i/o = input/output)
 
  none
 
 *****************************************************************************/
static int
run_turing_record_task(void)
{
  double task_time, gravity;
  int j, i;
  gravity = 8.0; 

  // NOTE: all array indices start with 1 in SL

  task_time = task_servo_time - start_time;

  // osciallates one DOF 

		//for (i=1; i<=N_DOFS; ++i) {

	joint_des_state[R_EB].th   = joint_state[R_EB].th;
	joint_des_state[R_EB].thd  = joint_state[R_EB].thd;
	joint_des_state[R_EB].thdd = joint_state[R_EB].thdd;
	//target[R_EB].th   = joint_state[R_EB].th;
	//target[R_EB].thd  = joint_state[R_EB].thd;
	//target[R_EB].thdd = joint_state[R_EB].thdd;

	joint_des_state[R_EB].uff =  0.0;  // DOES NOT MATTER if this is 0 (since the sole purpose of this stage is to get trajectory)
		/*
		  if (task_time >= wait_time & flag == 0)
			{
				stopcd();
				saveData();
				flag = 1;
			}
		*/
		  // compute inverse dynamics torques
		//}
   SL_InvDynNE(joint_state,joint_des_state,endeff,&base_state,&base_orient);//inverse dynamic for gravity compensation?


	

  return TRUE;
}

/*****************************************************************************
******************************************************************************
  Function Name    : change_turing_record_task
  Date       : June 2014
 
  Remarks:
 
  changes the task parameters
 
******************************************************************************
  Paramters:  (i/o = input/output)
 
  none
 
 *****************************************************************************/
static int
change_turing_record_task(void)
{
 
  //double dvar;
 
  get_int("Enter 1 to perturb elbow:",ivar,&ivar);
  //printf("Input var = %i\n",ivar);
  //get_double("This is how to enter a double variable",dvar,&dvar);
 
  return TRUE;
 
}

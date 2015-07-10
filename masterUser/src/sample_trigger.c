/*============================================================================
==============================================================================
                      
                              sample_trigger.c
 
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

/* defines */

/* local variables */
static double start_time = 0.0;
static double freq0, freq1, freq2;
static double amp0, amp1, amp2;
static SL_DJstate  target[N_DOFS+1];
static int        use_invdyn     = TRUE;

/* global functions */

/* local functions */
static int  init_sample_trigger(void);
static int  run_sample_trigger(void);
static int  change_sample_trigger(void);

/*****************************************************************************
******************************************************************************
Function Name	: add_sample_trigger
Date		: Feb 1999
Remarks:

adds the task to the task menu

******************************************************************************
Paramters:  (i/o = input/output)

none

*****************************************************************************/
void
add_sample_trigger( void )

{
  int i, j;
  
  addTask("Sample trigger", init_sample_trigger, 
	  run_sample_trigger, change_sample_trigger);

}    

/*****************************************************************************
******************************************************************************
  Function Name	: init_sample_trigger
  Date		: Dec. 1997

  Remarks:

  initialization for task

******************************************************************************
  Paramters:  (i/o = input/output)

       none

 *****************************************************************************/
static int 
init_sample_trigger(void)
{
  int j, i;
  int ans;
  static int firsttime = TRUE;
  
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
  Function Name	: run_sample_trigger
  Date		: Dec. 1997

  Remarks:

  run the task from the task servo: REAL TIME requirements!

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
static int 
run_sample_trigger(void)
{
  int j, i;

  double task_time;
  double omega0, omega1, omega2, torque;
  double posCoef, velCoef, loadCoef, gravity;


posCoef = -3.734;
velCoef = 0.713;
loadCoef = 0.921;

/*
posCoef = -1.4703;
velCoef = -0.1102;
loadCoef = 1.1288;
*/
gravity = 7.3;

  // NOTE: all array indices start with 1 in SL

  task_time = task_servo_time - start_time;

/* Servo actuationxr
  omega0     = 2.0*PI*freq0;
  omega1     = 2.0*PI*freq1;
  omega2     = 2.0*PI*freq2;
  joint_des_state[R_EB].uff = amp0*sin(omega0*task_time)+amp1*sin(omega1*task_time)+amp2*sin(omega2*task_time)+rand()%1;
*/

/*
  for (i=R_EB; i<=R_EB; ++i) {
    target[i].th   = joint_default_state[i].th +
      amp*sin(omega*task_time);
    //target[i].thd   = amp*omega*cos(omega*task_time);
    //target[i].thdd  =-amp*omega*omega*sin(omega*task_time);
  }
*/

  // the following variables need to be assigned
  //for (i=1; i<=N_DOFS; ++i) {
   // joint_des_state[i].th   = joint_state[i].th;
   // joint_des_state[i].thd  = joint_state[i].thd;
   // joint_des_state[i].thdd = joint_state[i].thdd;
    //joint_des_state[i].uff  = 0.0;
  //}

joint_des_state[R_EB].th   = joint_state[R_EB].th;
joint_des_state[R_EB].thd  = joint_state[R_EB].thd;
joint_des_state[R_EB].thdd = joint_state[R_EB].thdd;


omega0 = joint_state[R_EB].th-1.5;
omega1 = joint_state[R_EB].thd;
torque = joint_state[R_EB].load;


//joint_des_state[R_EB].uff = gravity;//
joint_des_state[R_EB].uff = (posCoef*omega0 + velCoef*omega1 + loadCoef*torque)*(0.5) + gravity;

  // compute inverse dynamics torques
  //SL_InverseDynamics(joint_state, joint_des_state, endeff);

  return TRUE;
}

/*****************************************************************************
******************************************************************************
  Function Name	: change_sample_trigger
  Date		: Dec. 1997

  Remarks:

  changes the task parameters

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
static int 
change_sample_trigger(void)
{
  int    ivar;
  double dvar;

  get_int("This is how to enter an integer variable",ivar,&ivar);
  get_double("This is how to enter a double variable",dvar,&dvar);

  return TRUE;

}


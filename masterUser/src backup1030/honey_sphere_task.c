/*============================================================================
==============================================================================
                      
                              honey_sphere_task.c
 
==============================================================================
Remarks:

      sekeleton to create the honey_sphere task

============================================================================*/

// SL general includes of system headers
#include "SL_system_headers.h"

#include "SL.h"
#include "SL_user.h"
#include "utility.h"
#include "SL_dynamics.h"
#include "SL_task_servo.h"
#include "SL_tasks.h"
#include "SL_collect_data.h"
#include "SL_shared_memory.h"
#include "SL_man.h"
#include "SL_kinematics.h"
#include "SL_filters.h"
#include "SL_objects.h"

/* defines */

/* local variables */
static SL_DJstate  goto_state[N_DOFS+1];
static double      kv_gain    = 30.0;
static double      kv_gain_in = 10.0;
static double      kp_gain    = 1500.0;
static  struct {
  float    pos[N_CART+1];
  float    scale[N_CART+1];
} cube;


/* global functions */
int test_run(void);


/* local functions */
static int  init_honey_sphere_task(void);
static int  run_honey_sphere_task(void);
static int  change_honey_sphere_task(void);

/*****************************************************************************
******************************************************************************
Function Name	: add_honey_sphere_task
Date		: Feb 1999
Remarks:

adds the task to the task menu

******************************************************************************
Paramters:  (i/o = input/output)

none

*****************************************************************************/
void
add_honey_sphere_task( void )

{
  int i, j;
  
  addTask("Honey Sphere Task", init_honey_sphere_task, 
	  run_honey_sphere_task, change_honey_sphere_task);

}    

/*****************************************************************************
******************************************************************************
  Function Name	: init_honey_sphere_task
  Date		: Dec. 1997

  Remarks:

  initialization for task

******************************************************************************
  Paramters:  (i/o = input/output)

       none

 *****************************************************************************/
static int 
init_honey_sphere_task(void)
{
  int j, i;
  int ans;

  /* go to a save posture */
  bzero((char *)&(goto_state[1]),N_DOFS*sizeof(goto_state[1]));
  for (i=1; i<=N_DOFS; ++i) {
    goto_state[i].th = joint_default_state[i].th;
  }

  if (!go_target_wait_ID(goto_state))
    return FALSE;

  cube.pos[_X_] = .35;
  cube.pos[_Y_] = .40;
  cube.pos[_Z_] = .0;
  cube.scale[_X_] = .1;
  cube.scale[_Y_] = .1;
  cube.scale[_Z_] = .1;
  sendUserGraphics("cube",&cube,sizeof(cube));

  /* ready to go */
  ans = 999;
  while (ans == 999) {
    if (!get_int("Enter 1 to start or anthing else to abort ...",ans,&ans))
      return FALSE;
  }
  
  if (ans != 1) 
    return FALSE;
  
  return TRUE;
}

/*****************************************************************************
******************************************************************************
  Function Name	: run_honey_sphere_task
  Date		: Dec. 1997

  Remarks:

  run the task from the task servo: REAL TIME requirements!

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
static int 
run_honey_sphere_task(void)
{
  int j, i;
  int    in_object_flag;
  double f[N_CART+1];
  int    at_cube_walls = TRUE;
  double misc,aux;

  /* check whether we are within the sphere */
  in_object_flag = TRUE;
  for (i=1; i<=N_CART; ++i)
    if (fabs(cart_state[RIGHT_HAND].x[i] - cube.pos[i]) > cube.scale[i])
      in_object_flag = FALSE;

  // inverse dynamics
  for (i=1; i<=N_DOFS; ++i) {
    joint_des_state[i].th   = joint_state[i].th;
    joint_des_state[i].thd  = joint_state[i].thd;
    joint_des_state[i].thdd = 0.0;
    joint_des_state[i].uff  = 0.0;
  }
  
  SL_InvDynNE(joint_state,joint_des_state,endeff,&base_state,&base_orient);

  /* create a repelling force from the entire cube in direction of the closest face */
  j = 0;
  misc = 1.e10;
  for (i=1; i<=N_CART; ++i) {
    f[i] = 0.0;
    aux  = cart_state[RIGHT_HAND].x[i] - cube.pos[i];
    if (fabs(aux) < cube.scale[i] && in_object_flag) {
      if (cube.scale[i] - fabs(aux) < misc) {
	misc = cube.scale[i] - fabs(aux);
	j = i;
      }
    }

  }

  if (in_object_flag) {
    double sat = 50.0;

    aux  = cart_state[RIGHT_HAND].x[j] - cube.pos[j];
    aux = kp_gain * (macro_sign(aux)*cube.scale[j] - aux);
    if (fabs(aux) > sat)
      aux = macro_sign(aux)*sat;
    f[j] += aux;

    for (i=1; i<=N_CART; ++i)
      f[i] +=  - kv_gain*cart_state[RIGHT_HAND].xd[i];

  }
  
  /* create a repelling force from the cube walls */
  /*
    double tol = 0.025;
  for (i=1; i<=N_CART; ++i)
    if (fabs(cart_state[RIGHT_HAND].x[i] - cube.pos[i]) > cube.scale[i]+tol)
      at_cube_walls = FALSE;

  for (i=1; i<=N_CART; ++i) {
    double aux;

    f[i] = 0.0;

    aux = cart_state[RIGHT_HAND].x[i] - (cube.pos[i] + cube.scale[i]);
    if (fabs(aux) < tol && at_cube_walls)
      f[i] += kp_gain * (macro_sign(aux)*tol - aux) - kv_gain*cart_state[RIGHT_HAND].xd[i];

    aux = cart_state[RIGHT_HAND].x[i] - (cube.pos[i] - cube.scale[i]);
    if (fabs(aux) < tol  && at_cube_walls)
      f[i] += kp_gain * (macro_sign(aux)*tol - aux) - kv_gain*cart_state[RIGHT_HAND].xd[i];

  }
  */
  
  /* create a damping term if in the honey sphere */
  /*
  if (in_object_flag)
    for (i=1; i<=N_CART; ++i)
      f[i] += -kv_gain_in*cart_state[RIGHT_HAND].xd[i];
  */
  
  /* Jacobian transpose */
  for (i=1; i<=R_WAA; ++i)
    for (j=1; j<=N_CART; ++j)
      joint_des_state[i].uff += J[j][i]*f[j];

  for (i=1; i<=N_DOFS; ++i) {
    // add a small stability term
    joint_des_state[i].thd   = joint_state[i].thd * 0.9;
    joint_des_state[i].uff  += (joint_default_state[i].th-joint_state[i].th)*1.0;
  }

  return TRUE;


}

/*****************************************************************************
******************************************************************************
  Function Name	: change_honey_sphere_task
  Date		: Dec. 1997

  Remarks:

  changes the task parameters

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
static int 
change_honey_sphere_task(void)
{

  double aux;

  get_double("positin gain",kp_gain,&aux);
  if (aux >= 0 && aux < 5000)
    kp_gain = aux;

  get_double("damping gain",kv_gain,&aux);
  if (aux >= 0 && aux < 50)
    kv_gain = aux;

  get_double("inside cube damping gain",kv_gain_in,&aux);
  if (aux >= 0 && aux < 20)
    kv_gain_in = aux;

  return TRUE;

}


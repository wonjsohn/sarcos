/*============================================================================
==============================================================================
                      
                              haptic_task.c
 
==============================================================================
Remarks:

      creates a haptic virtual object

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
#include "SL_filters.h"
#include "SL_unix_common.h"

/* defines */
enum ObjTypes {
  _NONE_,
  _CUBE_,
  _SPHERE_
};

/* local variables */
static SL_DJstate  goto_state[N_DOFS+1];
static double      kv_gain      = 50.0;
static double      kp_gain      = 1000.0;
static double      inertia_gain = 0.5;
static int         last_in_object_flag = FALSE;
static int         object_type = _NONE_;
static double      max_rebound_vel = 10.0;


static  struct {
  float    pos[N_CART+1];
  float    scale[N_CART+1];
  float    force[N_CART+1];
  float    cpos[N_CART+1];
  int      id; // id=1 for cube, id=2 for ball
} obj;

/* variables for filtering */
static Filter ff[N_CART+1];

#define NZEROS 4
#define NPOLES 4
#define GAIN   1.112983215e+06
static float xv[N_DOFS+1][NZEROS+1], yv[N_DOFS+1][NPOLES+1];
static float xa[N_DOFS+1][NZEROS+1], ya[N_DOFS+1][NPOLES+1];
static SL_DJstate  joint_filt_state[N_DOFS+1];


/* global functions */
int test_run(void);

/* local functions */
static int        init_haptic_task(void);
static int        run_haptic_task(void);
static int        change_haptic_task(void);
static SL_DJstate extra_filter(int);


/*****************************************************************************
******************************************************************************
Function Name	: add_haptic_task
Date		: Feb 1999
Remarks:

adds the task to the task menu

******************************************************************************
Paramters:  (i/o = input/output)

none

*****************************************************************************/
void
add_haptic_task( void )

{
  int i, j;
  
  addTask("Haptic Task", init_haptic_task, 
	  run_haptic_task, change_haptic_task);

}    

/*****************************************************************************
******************************************************************************
  Function Name	: init_haptic_task
  Date		: Dec. 1997

  Remarks:

  initialization for task

******************************************************************************
  Paramters:  (i/o = input/output)

       none

 *****************************************************************************/
static int 
init_haptic_task(void)
{
  int j, i;
  int ans;

  // zero the filters 
  for (i=1; i<=N_CART; ++i) {
    ff[i].cutoff = 40;
    for (j=0; j<=FILTER_ORDER; ++j)
      ff[i].raw[j] = ff[i].filt[j] = 0;
  }

  // cube or sphere or nothing?
  get_int("Which object kind? None=0 Cube=1 Sphere=2",object_type,&object_type);
  if (object_type < _NONE_ || object_type > _SPHERE_)
    object_type = _NONE_;

  // go to a save posture 
  bzero((char *)&(goto_state[1]),N_DOFS*sizeof(goto_state[1]));
  for (i=1; i<=N_DOFS; ++i)
    goto_state[i].th = joint_default_state[i].th;

  if (!go_target_wait_ID(goto_state))
    return FALSE;

  obj.pos[_X_] = .35;
  obj.pos[_Y_] = .40;
  obj.pos[_Z_] = .0;
  obj.scale[_X_] = .1;
  obj.scale[_Y_] = .1;
  obj.scale[_Z_] = .1;
  obj.id         = object_type;
  sendUserGraphics("hapticObject",&obj,sizeof(obj));

  // initialize filter variables 
  for(i=1; i<N_DOFS; i++) {
     for(j=1; j<NZEROS; j++) {
       xv[i][j]=0.0;
       xa[i][j]=0.0;
     }
     for(j=1; j<NPOLES; j++) {
       yv[i][j]=0.0;
       ya[i][j]=0.0;
     }
   }

  // ready to go 
  ans = 999;
  while (ans == 999) {
    if (!get_int("Enter 1 to start or anthing else to abort ...",ans,&ans))
      return FALSE;
  }
  
  if (ans != 1) 
    return FALSE;

  last_in_object_flag = FALSE;

  return TRUE;
}

/*****************************************************************************
******************************************************************************
  Function Name	: run_haptic_task
  Date		: Dec. 1997

  Remarks:

  run the task from the task servo: REAL TIME requirements!

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
static int 
run_haptic_task(void)
{
  int j, i;
  int    in_object_flag;
  double f[N_CART+1];
  double d[N_CART+1];
  double nd[N_CART+1];
  double misc,aux,aux2;
  static int face_index;

  // some extra filtering for better inertial compensation
  for (i=1; i<=N_DOFS; ++i)
    joint_filt_state[i] = extra_filter(i);


  // check whether we are in the object
  in_object_flag = TRUE;
  
  switch (object_type) {
    
  case _SPHERE_:
    aux = 0.0;
    for (i=1; i<=N_CART; ++i)
      aux += sqr((cart_state[RIGHT_HAND].x[i] - obj.pos[i])/obj.scale[i]);
    
    if (sqrt(aux) >= 1.0)
      in_object_flag = FALSE;

    break;
    
  case _CUBE_:
    for (i=1; i<=N_CART; ++i)
      if (fabs(cart_state[RIGHT_HAND].x[i] - obj.pos[i]) > obj.scale[i])
	in_object_flag = FALSE;
    
    break;

  default:
    in_object_flag = FALSE;

  }

  // zero all contact forces
  for (i=1; i<=N_CART; ++i)
    f[i] = 0.0;

  // only execute if R_TL is below threshold
  if (joint_state[R_TL].th < 0.08) {

    // inverse dynamics for dynamic compensation
    for (i=1; i<=N_DOFS; ++i) {
      joint_des_state[i].th   = joint_filt_state[i].th;
      joint_des_state[i].thd  = joint_filt_state[i].thd;
      joint_des_state[i].thdd = joint_filt_state[i].thdd * inertia_gain;
      joint_des_state[i].uff  = 0.0;
    }
    
    SL_InvDynNE(joint_state,joint_des_state,endeff,&base_state,&base_orient);
    
    // create a repelling force from the entire obj in direction of the closest face
    if (in_object_flag ) {
      double sat = 50.0;
      double scale_vel;
      
      switch (object_type) {
	
      case _SPHERE_:
	
	// compute the normalized displacement vector
	aux = 0.0;
	for (i=1; i<=N_CART; ++i) {
	  nd[i] = (cart_state[RIGHT_HAND].x[i] - obj.pos[i])/obj.scale[i];
	  aux += sqr(nd[i]);
	}
	aux = 1.-sqrt(aux); // the differnce from the normalized sphere surface
	
	// compute the unnormalized difference form the surface
	for (i=1; i<=N_CART; ++i) 
	  d[i] = nd[i]*aux*obj.scale[i];
	
	// does the movement velocity go into the sphere or away?
	aux = 0.0;
	for (i=1; i<=N_CART; ++i) 
	  aux += nd[i]*cart_state[RIGHT_HAND].xd[i];
	
	// what is the current total velocity
	scale_vel = 0;
	for (i=1; i<=N_CART; ++i) 
	  scale_vel += sqr(cart_state[RIGHT_HAND].xd[i]);
	scale_vel = sqrt(scale_vel);
	
	// compute contact force
	for (i=1; i<=N_CART; ++i) {
	  
	  f[i] = d[i] * kp_gain;
	  
	  // if the velocity goes into the object, use damping gain 
	  if (aux < 0) 
	    f[i] += -kv_gain*cart_state[RIGHT_HAND].xd[i]*fabs(nd[i]);
	  else 
	    if (scale_vel < max_rebound_vel)
	      f[i] += -kv_gain*cart_state[RIGHT_HAND].xd[i]*fabs(nd[i]);
	    else
	      f[i] += -kv_gain*cart_state[RIGHT_HAND].xd[i]/scale_vel*max_rebound_vel*fabs(nd[i]);
	  
	  // saturate contact force
	  if (fabs(f[i]) > sat)
	    f[i] = macro_sign(f[i])*sat;
	  
	}
	
	break;
	
      case _CUBE_:
	if (!last_in_object_flag) {
	  
	  // first, compute the displacement vector from the nearest surface
	  misc = 1.e10;
	  for (i=1; i<=N_CART; ++i) {
	    
	    aux  = obj.scale[i] - (cart_state[RIGHT_HAND].x[i] - obj.pos[i]);
	    if (fabs(aux) < misc) {
	      misc = fabs(aux);
	      face_index = i;
	    }
	    
	    aux  = -obj.scale[i] - (cart_state[RIGHT_HAND].x[i] - obj.pos[i]);
	    if (fabs(aux) < misc) {
	      misc = fabs(aux);
	      face_index = -i;
	    }
	    
	  }
	  
	} else {
	  
	  j = abs(face_index);
	  misc = fabs(macro_sign(face_index)*obj.scale[j] - 
		      (cart_state[RIGHT_HAND].x[j] - obj.pos[j]));
	  
	}
	
	// determine the displacement vector
	for (i=1; i<=N_CART; ++i)
	  nd[i] = d[i] = f[i] = 0.0;
	
	d[abs(face_index)] = macro_sign(face_index)*misc;
	nd[abs(face_index)] = macro_sign(face_index);
	
	// what is the current total velocity
	scale_vel = 0;
	for (i=1; i<=N_CART; ++i) 
	  scale_vel += sqr(cart_state[RIGHT_HAND].xd[i]);
	scale_vel = sqrt(scale_vel);
	
	// the contact force
	for (i=1; i<=N_CART; ++i) {
	  
	  f[i] = d[i] * kp_gain;
	  
	  // if the velocity goes into the object, use damping gain 
	  double max_rebound_vel = 0.1;
	  if ( macro_sign(cart_state[RIGHT_HAND].xd[i]) != macro_sign(d[i]) )
	    f[i] += -kv_gain*cart_state[RIGHT_HAND].xd[i]*fabs(nd[i]);
	  else {
	    if (scale_vel < max_rebound_vel)
	      aux = cart_state[RIGHT_HAND].xd[i]*fabs(nd[i]);
	    else
	      aux = cart_state[RIGHT_HAND].xd[i]/scale_vel*max_rebound_vel*fabs(nd[i]);
	    f[i] += - kv_gain*aux;
	  }
	  
	  // saturate contact force
	  if (fabs(f[i]) > sat)
	    f[i] = macro_sign(f[i])*sat;
	  
	}
	break;
	
	
      default:
	
	;
	
	
      }
      
      
    } // if (in_object_flag)
    
    /* filter the force */
    for (i=1; i<=N_CART; ++i)
      f[i] = filt(f[i],&(ff[i]));
    
    /* Jacobian transpose */
    for (i=1; i<=N_DOFS; ++i)
      for (j=1; j<=N_CART; ++j)
	joint_des_state[i].uff += J[j][i]*f[j];
    
    
    for (i=1; i<=N_DOFS; ++i) {
      // add a small stability term in the PD servo
      joint_des_state[i].thd   = joint_state[i].thd * 1.0;
      //joint_des_state[i].uff  += (joint_default_state[i].th-joint_state[i].th)*1.0;
    }

  } else { // if the thumb did not trigger the task

    // inverse dynamics for dynamic compensation
    for (i=1; i<=N_DOFS; ++i) {
      joint_des_state[i].th   = joint_des_state[i].th; // don't change the joint_des_state
      joint_des_state[i].thd  = 0.0;
      joint_des_state[i].thdd = 0.0;
      joint_des_state[i].uff  = 0.0;
    }
    
    SL_InvDynNE(joint_state,joint_des_state,endeff,&base_state,&base_orient);

  }
  
  // graphics
  for (i=1; i<=N_CART; ++i) {
    if (in_object_flag)
      obj.force[i] = f[i];
    else
      obj.force[i] = 0.0;
    obj.cpos[i]  = cart_state[RIGHT_HAND].x[i];
  }
  
  sendUserGraphics("hapticObject",&obj,sizeof(obj));
  
  last_in_object_flag = in_object_flag;
  
  
  return TRUE;


}

/*****************************************************************************
******************************************************************************
  Function Name	: change_haptic_task
  Date		: Dec. 1997

  Remarks:

  changes the task parameters

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
static int 
change_haptic_task(void)
{

  double aux;

  get_double("inertial comp gain",inertia_gain,&aux);
  if (aux >= 0 && aux < 1)
    inertia_gain = aux;

  get_double("positin gain",kp_gain,&aux);
  if (aux >= 0 && aux < 5000)
    kp_gain = aux;

  get_double("damping gain",kv_gain,&aux);
  if (aux >= 0 && aux < 80)
    kv_gain = aux;

  get_double("max rebound velocity",max_rebound_vel,&aux);
  if (aux >= 0)
    max_rebound_vel = aux;

  return TRUE;

}


/*****************************************************************************
******************************************************************************
  Function Name	: extra_filter
  Date		: Jan 2012

  Remarks:

  does some extra polynomial filtering on the velocities and 
  accelerations

******************************************************************************
  Paramters:  (i/o = input/output)

  \param[in]   i: DOF to be filtered

 *****************************************************************************/
static SL_DJstate 
extra_filter(int i)
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










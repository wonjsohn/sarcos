/*============================================================================
==============================================================================
                      
                    elbow_perturbation.c
 
==============================================================================
Remarks:

      The hack for "gravity compensation" on the Master Arm Robot:
      Using a PD Control in the feed-forward path, but when the
      resulting control law torque is bigger than a threshold, the set point
      of the PD Control follows the current state/position.

Written by	: Giovanni Sutanto (gsutanto@usc.edu)
Date		: 1st January 2015

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

enum CompensationType
{
	_GRAVITY_						= 1,
	_GRAVITY_CORIOLIS_				= 2,
	_GRAVITY_INERTIAL_				= 3,
	_GRAVITY_INERTIAL_NO_CORIOLIS_	= 4,
};

/* local variables */

static double start_time = 0.0;
static SL_DJstate	goto_state[N_DOFS+1];
//static double		inertia_gain 				= 0.5;					// inherited inertia compensation parameter from Michael Mistry's program
static double		inertia_gain 				= 0.425;
static double		R_TL_threshold				= 0.08;					// threshold of activate/inactivate thumb-in (R_TL) switch
static int			compensation_type			= _GRAVITY_INERTIAL_;

/* variables for Dragging PD Control */
static double		drag_threshold				= 0.75;
static double		kp_drag_gain				= 5.0;
static double		kd_drag_gain				= 0.1;
static double		kd_damping_factor			= 50.0;
static SL_DJstate	joint_des_drag_state[N_DOFS+1];
static double		f_saturation				= 50.0;					// saturation force

/* variables for filtering */
static Filter ff[N_CART+1];

#define NZEROS 4
#define NPOLES 4
#define GAIN   1.112983215e+06
static float xv[N_DOFS+1][NZEROS+1], yv[N_DOFS+1][NPOLES+1];
static float xa[N_DOFS+1][NZEROS+1], ya[N_DOFS+1][NPOLES+1];
static SL_DJstate  joint_filt_state[N_DOFS+1];


/* global functions */
void				add_elbow_perturbation(void);

/* local functions */
static int 			init_elbow_perturbation(void);
static int			run_elbow_perturbation(void);
static SL_DJstate	extra_joint_state_filter(int);
static int			change_elbow_perturbation(void);


/*****************************************************************************
******************************************************************************
Function Name	: add_elbow_perturbation
Date			: Feb 1999
Remarks:

adds the task to the task menu

******************************************************************************
Parameters:  (i/o = input/output)

none

*****************************************************************************/
void
add_elbow_perturbation( void )
{
	int i, j;

	addTask("Elbow Perturbation", init_elbow_perturbation,
			run_elbow_perturbation, change_elbow_perturbation);
}

/*****************************************************************************
******************************************************************************
  Function Name	: init_elbow_perturbation
  Date			: January 2015

  Remarks:

  initialization for task

******************************************************************************
  Parameters:  (i/o = input/output)

       none

 *****************************************************************************/
static int 
init_elbow_perturbation(void)
{
	int j, i;
	int ans;

	// go to a save posture
	bzero((char *)&(goto_state[1]),N_DOFS*sizeof(goto_state[1]));
	for (i=1; i<=N_DOFS; ++i)
	{
		goto_state[i].th = joint_default_state[i].th;
	}

	if (!go_target_wait_ID(goto_state))
	{
		return FALSE;
	}

	// initialize desired joint drag state
	for (i=1; i<=N_DOFS; ++i)
	{
		joint_des_drag_state[i].th = joint_state[i].th;
	}

	// zero the filters
	for (i=1; i<=N_CART; ++i)
	{
		ff[i].cutoff = 40;
		for (j=0; j<=FILTER_ORDER; ++j)
		{
			ff[i].raw[j] = ff[i].filt[j] = 0;
		}
	}

	// initialize filter variables
	for(i=1; i<=N_DOFS; i++)
	{
		for(j=1; j<=NZEROS; j++)
		{
			xv[i][j]=0.0;
			xa[i][j]=0.0;
		}
		for(j=1; j<=NPOLES; j++)
		{
			yv[i][j]=0.0;
			ya[i][j]=0.0;
		}
	}

	// ready to go
	ans = 999;
	while (ans == 999)
	{
		if (!get_int("Enter 1 to start or anthing else to abort ...",ans,&ans))
		{
			return FALSE;
		}
	}

	if (ans != 1)
	{
		return FALSE;
	}
    
    start_time = task_servo_time;
    printf("start time = %.3f, task_servo_time = %.3f\n",
     start_time, task_servo_time);
    

	return TRUE;
}

/*****************************************************************************
******************************************************************************
  Function Name	: run_elbow_perturbation
  Date			: January 2015

  Remarks:

  run the task from the task servo: REAL TIME requirements!

******************************************************************************
  Parameters:  (i/o = input/output)

  none

 *****************************************************************************/
static int 
run_elbow_perturbation(void)
{
	int 	i;
	double	tau;
    double task_time;
        
    task_time = task_servo_time - start_time;

	// some extra filtering for better inertial compensation (inherited from Michael Mistry's program)
	for (i=1; i<=N_DOFS; ++i)
	{
		joint_filt_state[i]					= extra_joint_state_filter(i);
	}

	if (joint_state[R_TL].th < R_TL_threshold) // if joint R_TL is below threshold (thumb-in switch is activated)
	{
		for (i=1; i<=N_DOFS; ++i)
		{
			// The one that is very noisy is the joint acceleration sensing, that's why we are using the filtered version of it
			// (joint_filt_state[i].thdd), instead of the unfiltered one (joint_state[i].thdd). Joint position (joint_state[i].th) and joint velocity (joint_state[i].thd)
			// on the other hand are not so noisy, so we are using the original (unfiltered) one.
			if (i == R_EB)
			{
				joint_des_state[i].th   = joint_state[i].th;
				joint_des_state[i].thd  = joint_state[i].thd;
				joint_des_state[i].thdd = joint_filt_state[i].thdd * inertia_gain;	// multiplication by inertia gain here is maybe for reducing the risk of the system becoming unstable???
				joint_des_state[i].uff  = 0.0;
			}
			else
			{
				joint_des_state[i].th   = joint_des_state[i].th;	// don't change the joint_des_state;
				joint_des_state[i].thd  = 0.0;
				joint_des_state[i].thdd = 0.0;
				joint_des_state[i].uff  = 0.0;
			}
		}

		SL_InvDynNE(joint_state,joint_des_state,endeff,&base_state,&base_orient);

		for (i=1; i<=N_DOFS; ++i)
		{
			if (i == R_EB)
			{
				// Command joint PD servo to track the current state, in other words, cancel out the joint feedback control:
				joint_des_state[i].th			= joint_state[i].th;
				joint_des_state[i].thd			= joint_state[i].thd;
				joint_des_state[i].thdd			= joint_state[i].thdd;

				if (i < R_TL)
				{
					tau								= kp_drag_gain * (joint_des_drag_state[i].th-joint_state[i].th);
					//tau								= kp_drag_gain * (joint_des_drag_state[i].th-joint_state[i].th) +
					//								  exp(-kd_damping_factor*fabs(joint_state[i].thd)) * kd_drag_gain * (-joint_state[i].thd);
					if (fabs(tau) > f_saturation)
					{
						tau							= macro_sign(tau) * f_saturation;
					}
					joint_des_state[i].uff			+= tau;

					if (fabs(tau) > drag_threshold)
					{
						joint_des_drag_state[i].th	= joint_state[i].th;
					}
				}
			}
		}
	}
	else // if (joint_state[R_TL].th >= R_TL_threshold), or in other words if (thumb-in switch is NOT activated)
	{
		// inverse dynamics for dynamic compensation
		for (i=1; i<=N_DOFS; ++i)
		{
			joint_des_state[i].th   = joint_des_state[i].th;	// don't change the joint_des_state;
			joint_des_state[i].thd  = 0.0;
			joint_des_state[i].thdd = 0.0;
			joint_des_state[i].uff  = 0.0;
		}

		SL_InvDynNE(joint_state,joint_des_state,endeff,&base_state,&base_orient);
	}
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
  Function Name	: change_elbow_perturbation
  Date			: January 2015

  Remarks:

  changes the task parameters

******************************************************************************
  Parameters:  (i/o = input/output)

  none

 *****************************************************************************/
static int
change_elbow_perturbation(void)
{
	double	aux;
	int		aux_int;

	get_double("drag threshold",drag_threshold,&aux);
	if ((aux >= 0.0) && (aux <= 10.0))
	{
		drag_threshold			= aux;
	}

	get_double("joint drag state P gain",kp_drag_gain,&aux);
	if ((aux >= 0.0) && (aux <= 10.0))
	{
		kp_drag_gain			= aux;
	}

	get_double("joint drag state D gain",kd_drag_gain,&aux);
	if ((aux >= 0.0) && (aux <= 1.0))
	{
		kd_drag_gain			= aux;
	}

	get_double("velocity-dependent D control damping",kd_damping_factor,&aux);
	if ((aux >= 0.0) && (aux <= 1000.0))
	{
		kd_damping_factor		= aux;
	}

	get_int("compensation type? _GRAVITY_=1; _GRAVITY_CORIOLIS_=2; _GRAVITY_INERTIAL_=3; _GRAVITY_INERTIAL_NO_CORIOLIS_=4",compensation_type,&aux_int);
	if ((aux_int>=_GRAVITY_) && (aux_int<=_GRAVITY_INERTIAL_NO_CORIOLIS_))
	{
		compensation_type		= aux_int;
	}

	get_double("inertial comp gain",inertia_gain,&aux);
	if (aux >= 0 && aux < 1)
	{
		inertia_gain = aux;
	}

	return TRUE;
}

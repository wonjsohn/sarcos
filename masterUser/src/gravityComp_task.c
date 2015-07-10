/*============================================================================
==============================================================================
                      
                              gravityComp_task.c
 
==============================================================================
Remarks:

      simple task to do gravity compensation

============================================================================*/

/* vxWorks includes */
#include "SL_system_headers.h"
#ifndef VX
#endif

/* private includes */
#include "SL.h"
#include "SL_user.h"
#include "SL_common.h"
#include "SL_tasks.h"
#include "SL_task_servo.h"
#include "SL_kinematics.h"
#include "SL_dynamics.h"
#include "mdefs.h"
#include "utility.h"
#include "SL_collect_data.h"

/* defines */

/* local variables */
static SL_DJstate  target[N_DOFS+1];
static double controller_gain_th[N_DOFS+1];;
static double controller_gain_thd[N_DOFS+1];;
static double controller_gain_int[N_DOFS+1];;
static double DampScale=1.0;    // Scales the damping on all joints
static int fieldon = 0;     // TRUE if the force field should be on

/* global functions */

/* local functions */
static int  init_gravityComp_task(void);
static int  run_gravityComp_task(void);
static int  change_gravityComp_task(void);

/* for filtering */
static SL_DJstate filter(int);
#define NZEROS 4
#define NPOLES 4
#define GAIN   1.112983215e+06
static float xv[N_DOFS+1][NZEROS+1], yv[N_DOFS+1][NPOLES+1];
static float xa[N_DOFS+1][NZEROS+1], ya[N_DOFS+1][NPOLES+1];
static SL_DJstate  joint_filt_state[N_DOFS+1];
//static SL_DJstate  filtered_state[N_DOFS+1];

/* for end-effector forcefield */
static Vector xd;
static Matrix B;
static Matrix J7T;
static Vector u_field;
static double fieldGain = 0.1;

static double fieldtorque;

/*****************************************************************************
******************************************************************************
Function Name	: add_gravityComp_task
Date		: Feb 1999
Remarks:

adds the task to the task menu

******************************************************************************
Paramters:  (i/o = input/output)

none

*****************************************************************************/
void
add_gravityComp_task( void )

{
  int i, j;
  static int firsttime = TRUE;

  if (firsttime) {
    firsttime = FALSE;
    
    addTask("Gravity Compensation Task", init_gravityComp_task, 
	  run_gravityComp_task, change_gravityComp_task);

    /* add variables to data collection */
    addVarToCollect((char *)&(fieldon),"force-field","-",INT,FALSE);

    addVarToCollect((char *)&(joint_filt_state[1].thd),"R_SFE_filt_thd","rad/s",DOUBLE,FALSE);
    addVarToCollect((char *)&(joint_filt_state[2].thd),"R_SAA_filt_thd","rad/s",DOUBLE,FALSE);
    addVarToCollect((char *)&(joint_filt_state[3].thd),"R_HR_filt_thd","rad/s",DOUBLE,FALSE);  
    addVarToCollect((char *)&(joint_filt_state[4].thd),"R_EB_filt_thd","rad/s",DOUBLE,FALSE);
    addVarToCollect((char *)&(joint_filt_state[5].thd),"R_WR_filt_thd","rad/s",DOUBLE,FALSE);
    addVarToCollect((char *)&(joint_filt_state[6].thd),"R_WFE_filt_thd","rad/s",DOUBLE,FALSE);
    addVarToCollect((char *)&(joint_filt_state[7].thd),"R_WAA_filt_thd","rad/s",DOUBLE,FALSE);  

    addVarToCollect((char *)&(joint_filt_state[1].thdd),"R_SFE_filt_thdd","rad/s^2",DOUBLE,FALSE);
    addVarToCollect((char *)&(joint_filt_state[2].thdd),"R_SAA_filt_thdd","rad/s^2",DOUBLE,FALSE);
    addVarToCollect((char *)&(joint_filt_state[3].thdd),"R_HR_filt_thdd","rad/s^2",DOUBLE,FALSE);  
    addVarToCollect((char *)&(joint_filt_state[4].thdd),"R_EB_filt_thdd","rad/s^2",DOUBLE,FALSE);
    addVarToCollect((char *)&(joint_filt_state[5].thdd),"R_WR_filt_thdd","rad/s^2",DOUBLE,FALSE);
    addVarToCollect((char *)&(joint_filt_state[6].thdd),"R_WFE_filt_thdd","rad/s^2",DOUBLE,FALSE);
    addVarToCollect((char *)&(joint_filt_state[7].thdd),"R_WAA_filt_thdd","rad/s^2",DOUBLE,FALSE);

    addVarToCollect((char *)&(fieldtorque),"fieldtorque","N/m",DOUBLE,FALSE);
  }
    /* read the control gains and max controls  */


  if (!read_gains("Gains.cf",controller_gain_th, controller_gain_thd, controller_gain_int))
  //if (!read_gains(controller_gain_th, controller_gain_thd, controller_gain_int))
      printf("Error reading Gains.cf\n");
 
   

}    

/*****************************************************************************
******************************************************************************
  Function Name	: init_gravityComp_task
  Date		: Dec. 1997

  Remarks:

  initialization for task

******************************************************************************
  Paramters:  (i/o = input/output)

       none

 *****************************************************************************/
static int 
init_gravityComp_task(void)
{
  int ans;
  int j,i;

  static int firsttime = TRUE;
  
  if (firsttime == TRUE) {
    xd = my_vector(1,3);
    B = my_matrix(1,3,1,3);
    J7T = my_matrix(1,7,1,3);
    u_field = my_vector(1,7);

    B[1][1] = -10.1;
    B[1][2] = -11.2;
    B[1][3] = 0.0;
    B[2][1] = -11.2;
    B[2][2] = -11.1;
    B[2][3] = 0.0;
    B[3][1] = 0.0;
    B[3][2] = 0.0;
    B[3][3] = 1.0;


    //for (i=1;i<=3;i++) {
    //  for (j=1;j<=3;j++) {
    //if (i==j) {
    //  B[i][j] = -1.0;
    //}
    //else {
    //  B[i][j] = 0.0;
    //}
    //}
    //}
    firsttime = FALSE;
  }


  /* go to a save posture */
  bzero((char *)&(target[1]),N_DOFS*sizeof(target[1]));

  for (i=1; i<=N_DOFS; ++i) {
    target[i].th = joint_default_state[i].th;
  }
    
  if (!go_target_wait_ID(target))
    return FALSE;

   /* initialize filter variables */
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
  Function Name	: run_gravityComp_task
  Date		: Dec. 1997

  Remarks:

  run the task from the task servo: REAL TIME requirements!

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
static int 
run_gravityComp_task(void)
{
  int j,i;

  // Damping Gains (index starts at 1)
  //double Kdamp[N_DOFS+1] = {0.0, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.1, 0.1, 0.1}; 
  double Kdamp[N_DOFS+1] = {0.0, 0.07, 0.07, 0.07, 0.07, 0.07, 0.07, 0.07, 0.1, 0.1, 0.1}; 
  // double Kdamp[N_DOFS+1] = {0.0, 0.2, 0.2, 0.5, 0.5, 1.0, 0.5, 0.5, 1, 1, 1}; 

  // Coriolus Compensation Gains 
  double Kcori[N_DOFS+1] = {0.0, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 0.00, 0.00, 0.00};
  // double Kcori[N_DOFS+1] = {0.0, 0.30, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.00, 0.00, 0.00};
  // double Kcori[N_DOFS+1] = {0.0, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00};

  // Inertia Compensation Gains 
  double Kiner[N_DOFS+1] = {0.0, 0.40, 0.40, 0.30, 0.35, 0.00, 0.4, 0.4, 0.00, 0.00, 0.00};
  // double Kiner[N_DOFS+1] = {0.0, 1.00, 1.00, 1.00, 1.00, 0.50, 1.00, 1.00, 0.00, 0.00, 0.00}; 
  //double Kiner[N_DOFS+1] = {0.0, 0.20, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.00, 0.00, 0.00};
  // double Kiner[N_DOFS+1] = {0.0, 0.50, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.00, 0.00, 0.00};
  // double Kiner[N_DOFS+1] = {0.0, 0.00, 0.00, 0.00, 0.00, 0.00, 0.0, 0.0, 0.00, 0.00, 0.00};
 
  // Integer gains (how fast desired state becomes actual state)  
  //double Kint[N_DOFS+1]  = {0.0, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.001, 0.001, 0.001};
  double Kint[N_DOFS+1]  = {0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.001, 0.001, 0.001};
  //double Kint[N_DOFS+1]  = {0.0, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.001, 0.001, 0.001};

  // Dead Zone Threshold 
  double thres[N_DOFS+1] = {0.0, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.05, 0.05, 0.05};
  
  // To shut off Inertia,Coriolus Compensation
  //double Kcori[N_DOFS+1] = {0.0, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00};
  //double Kiner[N_DOFS+1] = {0.0, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00};
  
  for (i=1; i<=N_DOFS; ++i) {
    joint_filt_state[i] = filter(i);
  }
  
  if (joint_state[8].th < 0.08) {  // Hold down thumb to trigger Grav. Comp.

    // Gravity Compensation
    for (i=1; i<=N_DOFS; ++i) {
      if (fabs(joint_state[i].th-joint_des_state[i].th) > thres[i]){
        joint_des_state[i].th += (joint_state[i].th-joint_des_state[i].th)*Kint[i];
      }
    }

    // add compensation relative to the current state of the robot
    for (i=1; i<=N_DOFS; ++i) {
      // Gravity Compensation
	 target[i].th   = joint_state[i].th;
      // Coriolus Compensation
	 target[i].thd  = Kcori[i]*joint_filt_state[i].thd;
      // Inertia Compensation
	 target[i].thdd = Kiner[i]*joint_filt_state[i].thdd;
      
	 // Damping (to be premultiplied by inertia matrix)
         //  if (i != 5 ) {
         //    target[i].thdd += (0.0 - joint_state[i].thd ) * Kdamp[i] * DampScale * controller_gain_thd[i];
	 //  }
      
	 target[i].uff  = 0.0;
    }
      
    SL_InvDynNE(NULL,target,endeff,&base_state,&base_orient);
 
    // assign compensation torques
    for (i=1; i<=N_DOFS; ++i) {
      if (i==1 || i==2 || i==3 || i==4 || i==6 || i==7 || i==5) { 
	// Use my own damping (not premultiplied by the inertia matrix)
	joint_des_state[i].uff = 
	  target[i].uff + (0.0 - joint_filt_state[i].thd) * Kdamp[i] * DampScale * controller_gain_thd[i];
	
        // Cancel damping in the motor servo
	joint_des_state[i].thd = joint_state[i].thd;  
      }
      else {
        // Do not use my own damping
	joint_des_state[i].uff   = target[i].uff;
      }
    }

    fieldtorque = 0.0;
    /* FORCE FIELDS GO HERE */
    switch (fieldon) {
      case 1:
        joint_des_state[4].uff += joint_filt_state[2].thd * fieldGain + joint_filt_state[1].thd * fieldGain;
        break;
      case 2:
        if (joint_state[1].thd > 0.0) {
          joint_des_state[5].uff += joint_state[1].thd * -0.5;
        }
        break;
      case 3:
        joint_des_state[2].uff += joint_state[3].thd * 1.0;
        break;
      case 4:
        joint_des_state[1].uff += joint_state[4].thd * 1.0;
        break;
      case 5:
        joint_des_state[4].uff += joint_state[3].thd * -1.0;
        break;
      case 6:
        if (joint_state[1].thd > 0.0) {
          joint_des_state[3].uff += joint_state[1].thd * 1.0;
        }
        break;
      case 7: //end-effector:
        for (i=1;i<=7;i++) {
	  for (j=1;j<=3;j++) {
	    J7T[i][j] = J[j][i];
	  }
	}
	for (i=1;i<=3;i++) {
	  xd[i] = cart_state[1].xd[i];
	}
	if (!mat_mult(J7T,B, J7T))
	  return FALSE;
	if (!mat_vec_mult(J7T, xd, u_field))
	  return FALSE;
        for (i=1;i<=7;i++) {
	  joint_des_state[i].uff += fieldGain*u_field[i];
	}
	fieldtorque = fieldGain*u_field[1];
        break;    
    }
  }

  return TRUE;
}

/*****************************************************************************
******************************************************************************
  Function Name	: change_gravityComp_task
  Date		: Dec. 1997

  Remarks:

  changes the task parameters

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
static int 
change_gravityComp_task(void)
{
  int aux;
  double auxd;
 
  get_int("Force Field",0,&aux);
  if (aux == 1 || aux == 7) {
    fieldon=aux;
  }
  else {
    fieldon=0;
  }


  //if (fieldon == 7) {
    get_double("Field Gain",0.0,&auxd);
    if (auxd < 0.0) {
      auxd = 0.0;
    }
    if (auxd > 5.0) {
      auxd = 0.0;
      printf("For safety, keep gain lower than 5.0\n");
    }
    fieldGain = auxd;

    //}

  printf("Field is now: %d\n",fieldon);  
  printf("Field Gain is now %f\n",fieldGain);

  //this is probably a bad idea, but good for debuging.....
  //get_double("Damp Scale", 1.0, &aux);
  
  // DampScale = aux;
  
  return TRUE;
}


static SL_DJstate 
filter(int i)
  { 
    SL_DJstate  filtered_output[N_DOFS+1];
  
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



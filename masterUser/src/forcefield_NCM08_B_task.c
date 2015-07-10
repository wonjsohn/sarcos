/*============================================================================
==============================================================================
                      
                              forcefield_task.c
 
==============================================================================
Remarks:

      task to do force field experiments with gravity compensation

============================================================================*/

/* system headers */
#include "SL_system_headers.h"

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
#include "jacobian_comp.h"
#include "SL_unix_common.h"
#include "SL_userGraphics.h"

/* defines */

/* local variables */
static SL_DJstate  target[N_DOFS+1];
static SL_DJstate  home_target[N_DOFS+1];
static double controller_gain_th[N_DOFS+1];;
static double controller_gain_thd[N_DOFS+1];;
static double controller_gain_int[N_DOFS+1];;

// Variables for goto_target
static SL_DJstate joint_goto_state[N_DOFS+1];
static SL_DJstate joint_increment[N_DOFS+1];;
static double goto_speed = 0.5;
static int n_steps;
static int n_goto_steps;
static double max_range=0;

// Variables and Flags for the forcefield experiment
static int goHome = TRUE;      // TRUE if we are in the goHome state (i.e. arm is returning to home)
static int initGotoTarget=TRUE;    // TRUE if we need to initialize goto_target
static int trial=0;   
static int beepFlag = TRUE;    // TRUE if there should be a beep at the beginning of trial
static int fieldon = FALSE;     // TRUE if the force field should be on
static int saving = FALSE;   // TRUE if data being saved
static int expTrigger = FALSE; // triggers start and end of experiment
static int expOn = FALSE;      // TRUE if experiment is currently running
static int gravCompOn = FALSE; // TRUE if gravity compesation should be on
static int startLocation = 0;
static int saveData_tid;
static int numtrials=170;
static int num_catch=10;  //number of catch trials in a catch trial block
static int num_begin=100; //minimum number of trials before a catch-trial
static double time_step;
static double target_radius=0.1;
static double trial_time = 0.0;
static double time_in_target = 0.0;
static double MAX_trial_time = 1.4;
static double req_time_in_target = 0.2;
static SL_Cstate reach_target;
static double target_dist;
static double beep_timer = 0.0;
static double MAX_beep_timer = 0.25;
static int beepCycle = 0;
static double hand_vel; //hand velocity magnitude
static float balls[2+1][N_CART+1];

// Variables for filtering 
static SL_DJstate filter(int);
#define NZEROS 4
#define NPOLES 4
#define GAIN   1.112983215e+06
static float xv[N_DOFS+1][NZEROS+1], yv[N_DOFS+1][NPOLES+1];
static float xa[N_DOFS+1][NZEROS+1], ya[N_DOFS+1][NPOLES+1];
static SL_DJstate  joint_filt_state[N_DOFS+1];


/* for catch trials */
static int catch_trial(void);
static int catches_finished=0;
static int catch_padding=0;
static int catch_index;
/*
static int catch_seq[] = 
  {0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,
   0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1};
*/

static int catch_seq[] = 
  {0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,

   0,0,0,0,0,1,0,0,0,1,
   0,0,0,0,1,0,0,0,0,1,
   0,0,0,0,1,

   1,1,1,1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,1,1,1,

   //   1,1,1,1,1,1,1,1,1,1,
   //   1,1,1,1,1,1,1,1,1,1,

   1,1,0,1,1,1,1,1,1,0,
   1,1,1,1,0,1,1,1,0,1,
   1,1,1,1,0};

/* global functions */

/* local functions */
static int  init_forcefield_B_task(void);
static int  run_forcefield_B_task(void);
static int  change_forcefield_B_task(void);

static int  goto_target(SL_DJstate*, double);
static int  select_target(SL_DJstate*, int); 
static double dist_to_target(void);

static enum block { 
                 NULLTRAIN = 1, // Field off, No catch trials 
		 FORCETRAIN, // Field on, No catch trials
		 TEST       // field on or off, depending on catch_seq, may include catch trials
               } blocktype;


// forcefield type
static enum fields {
  NULLFIELD = 1,  // no force field
  JOINTSPACE,     // joint space force field
  JOINTSPACE2,
  TASKSPACE,      // task space force field
  NULLSPACE       // null space force field
} fieldtype;

//Variables mostly for data collection and analysis
static Vector u_field;
static Vector u_field_A;  // general joint space forcefield
static Vector u_field_B;  // task space forcefield
static Vector u_field_C;  // null space forcefield
static double u_field_data[8]; //used for data collection
static double u_field_A_data[8]; //used for data collection
static double u_field_B_data[8]; //used for data collection
static double u_field_C_data[8]; //used for data collection
static double u_field_MAX[8];
static double u_field_MIN[8];
static int u_field_CLIP;
static double u_field_norm;
static double u_field_A_norm;
static double u_field_B_norm;
static double u_field_C_norm;
static Vector qd;

/* for joint-space forcefield */
static Matrix A;

/* for end-effector forcefield */
static Vector xd;
static Matrix B;
static Matrix J7T;
static double fieldGain = 1.0;

/* for null-space forcefield */
static Matrix C;
static Matrix W;
static JacobianAcc J_3x7;
static double det;

// for random forcefields
static double switchProb = 1.0;
static double sigmaField = 0.0;

/*****************************************************************************
******************************************************************************
Function Name	: add_forcefield_task
Date	: May 2005
Remarks:

adds the task to the task menu

******************************************************************************
Paramters:  (i/o = input/output)

none

*****************************************************************************/
void
add_forcefield_B_task( void )

{
  int i, j;
  
  addTask("Force Field Task (NCM08_B)", init_forcefield_B_task, 
	  run_forcefield_B_task, change_forcefield_B_task);

  /* add variables to data collection */
  addVarToCollect((char *)&(fieldon),"force-field","-",INT,FALSE);
  addVarToCollect((char *)&(startLocation),"start_location","-",INT,FALSE);
  

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

  addVarToCollect((char *)&(u_field_data[1]),"R_SFE_u_field","Nm",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_data[2]),"R_SAA_u_field","Nm",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_data[3]),"R_HR_u_field","Nm",DOUBLE,FALSE);  
  addVarToCollect((char *)&(u_field_data[4]),"R_EB_u_field","Nm",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_data[5]),"R_WR_u_field","Nm",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_data[6]),"R_WFE_u_field","Nm",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_data[7]),"R_WAA_u_field","Nm",DOUBLE,FALSE);  

  addVarToCollect((char *)&(u_field_A_data[1]),"R_SFE_u_field_A","Nm",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_A_data[2]),"R_SAA_u_field_A","Nm",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_A_data[3]),"R_HR_u_field_A","Nm",DOUBLE,FALSE);  
  addVarToCollect((char *)&(u_field_A_data[4]),"R_EB_u_field_A","Nm",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_A_data[5]),"R_WR_u_field_A","Nm",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_A_data[6]),"R_WFE_u_field_A","Nm",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_A_data[7]),"R_WAA_u_field_A","Nm",DOUBLE,FALSE);  

  addVarToCollect((char *)&(u_field_B_data[1]),"R_SFE_u_field_B","Nm",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_B_data[2]),"R_SAA_u_field_B","Nm",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_B_data[3]),"R_HR_u_field_B","Nm",DOUBLE,FALSE);  
  addVarToCollect((char *)&(u_field_B_data[4]),"R_EB_u_field_B","Nm",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_B_data[5]),"R_WR_u_field_B","Nm",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_B_data[6]),"R_WFE_u_field_B","Nm",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_B_data[7]),"R_WAA_u_field_B","Nm",DOUBLE,FALSE);  

  addVarToCollect((char *)&(u_field_C_data[1]),"R_SFE_u_field_C","Nm",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_C_data[2]),"R_SAA_u_field_C","Nm",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_C_data[3]),"R_HR_u_field_C","Nm",DOUBLE,FALSE);  
  addVarToCollect((char *)&(u_field_C_data[4]),"R_EB_u_field_C","Nm",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_C_data[5]),"R_WR_u_field_C","Nm",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_C_data[6]),"R_WFE_u_field_C","Nm",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_C_data[7]),"R_WAA_u_field_C","Nm",DOUBLE,FALSE);  

  addVarToCollect((char *)&(fieldGain),"fieldGain","gain",DOUBLE,FALSE);
  addVarToCollect((char *)&(switchProb),"switchProb","prob",DOUBLE,FALSE);
  addVarToCollect((char *)&(sigmaField),"sigmaField","stddev",DOUBLE,FALSE);
  addVarToCollect((char *)&(det),"determinant","-",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_CLIP),"u_field_CLIP","-",INT,FALSE);
  addVarToCollect((char *)&(u_field_norm),"u_field_norm","-",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_A_norm),"u_field_A_norm","-",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_B_norm),"u_field_B_norm","-",DOUBLE,FALSE);
  addVarToCollect((char *)&(u_field_C_norm),"u_field_C_norm","-",DOUBLE,FALSE);
  addVarToCollect((char *)&(target_dist),"target_dist","m",DOUBLE,FALSE);
  addVarToCollect((char *)&(trial_time),"trial_time","m",DOUBLE,FALSE);
  addVarToCollect((char *)&(time_in_target),"time_in_target","m",DOUBLE,FALSE);
  addVarToCollect((char *)&(hand_vel),"hand_vel","m/s",DOUBLE,FALSE);

  /* read the control gains and max controls  */
  if (!read_gains("Gains.cf", controller_gain_th, controller_gain_thd, controller_gain_int))
    printf("Cannot read Gains.cf!\n");
}    

/*****************************************************************************
******************************************************************************
  Function Name	: init_forcefield_task
  Date		: May 2005

  Remarks:

  initialization for task

******************************************************************************
  Paramters:  (i/o = input/output)

       none

 *****************************************************************************/
static int 
init_forcefield_B_task(void)
{
  int j, i;
  int ans;

  static int firsttime = TRUE;

  if (firsttime == TRUE) {
    qd = my_vector(1,7);
    xd = my_vector(1,3);
    B = my_matrix(1,3,1,3);
    J7T = my_matrix(1,7,1,3);
    u_field = my_vector(1,7);
    u_field_A = my_vector(1,7);
    u_field_B = my_vector(1,7);
    u_field_C = my_vector(1,7);
    W = my_matrix(1,7,1,7);
    init_jacobian(&J_3x7,3,7);
    firsttime = FALSE;
  }

  time_step = 1./(double)task_servo_rate;
  MAX_trial_time = 2.5;
  trial_time = 0.0;
  time_in_target = 0.0;
  beepCycle = 0;
  reach_target.x[_X_] = 0.0;
  reach_target.x[_Y_] = 0.0;
  reach_target.x[_Z_] = 0.0;

  //initialize weight matrix (for psuedoinverses)
  for (i=1;i<=7;i++) {
    for (j=1;j<=7;j++) {
      if (i==j) 
        W[i][j] = 1.0;
      else
	W[i][j] = 0.0;
    }
  }
  //hand tuned Weight matrix
  W[1][1] = 0.3;
  W[2][2] = 0.3;
  W[3][3] = 0.4;
  W[4][4] = 0.5;
  W[5][5] = 0.5;
  W[6][6] = 100.0;
  W[7][7] = 100.0;

  //Maximum force field torques allowed (for safety)
  u_field_MAX[1] = 12.0;
  u_field_MAX[2] = 7.0;
  u_field_MAX[3] = 7.0;
  u_field_MAX[4] = 9.0;
  u_field_MAX[5] = 3.0;
  u_field_MAX[6] = 3.0;
  u_field_MAX[7] = 3.0;

  for (i=1;i<=7;i++) {
    u_field_MIN[i] = -1.0*u_field_MAX[i];
  }

  /* SFN07 Forcefield:
     B[1][1] = -10.1;
     B[1][2] = -11.2;
     B[1][3] = 0.0;
     B[2][1] = -11.2;
     B[2][2] = 11.1;
     B[2][3] = 0.0;
     B[3][1] = 0.0;
     B[3][2] = 0.0;
     B[3][3] = 1.0;
  */

  /* NCM08_A Forcefield: */
  /*
  B[1][1] = 0.0;
  B[1][2] = 10.0;
  B[1][3] = 0.0;
  B[2][1] = 0.0;
  B[2][2] = 0.0;
  B[2][3] = 0.0;
  B[3][1] = 0.0;
  B[3][2] = 0.0;
  B[3][3] = 0.0;
  */

  /* Experimental Forcefield */
  /*
     B[1][1] = -10.1;
     B[1][2] = -11.2;
     B[1][3] = -4.0;
     B[2][1] = -11.2;
     B[2][2] = 11.1;
     B[2][3] = 7.0;
     B[3][1] = -4.0;
     B[3][2] = 7.0;
     B[3][3] = 0.0;
  */

  B[1][1] = 0.0;
  B[1][2] = 1.0;
  B[1][3] = 0.0;
  B[2][1] = -1.0;
  B[2][2] = 0.0;
  B[2][3] = -1.0;
  B[3][1] = 0.0;
  B[3][2] = 1.0;
  B[3][3] = 0.0;
 

  /* go to a save posture */
  bzero((char *)&(target[1]),N_DOFS*sizeof(target[1]));

  for (i=1; i<=N_DOFS; ++i) {
    target[i].th = joint_default_state[i].th;
  }   

 
  startLocation=0;
  select_target(home_target,0);
  
  blocktype=NULLTRAIN; 
  goHome=TRUE;
  initGotoTarget=TRUE;
  saving = FALSE;
  fieldtype = NULLFIELD;

  trial = 0;
  catches_finished = 0;
  catch_padding = 0;  
  catch_index = 0;

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
  Function Name	: run_forcefield_task
  Date		: May 2005

  Remarks:

  run the task from the task servo: REAL TIME requirements!

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
static int 
run_forcefield_B_task(void)
{

  int j, i;
  static int wait_ticks = 0;

  // Hand tuned parameters for gravity/inertia compensation
  double Kdamp[N_DOFS+1] = {0.0, 0.07, 0.07, 0.07, 0.07, 0.07, 0.07, 0.07, 0.1, 0.1, 0.1}; 
  double Kcori[N_DOFS+1] = {0.0, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 0.00, 0.00, 0.00};
  //double Kiner[N_DOFS+1] = {0.0, 0.80, 0.80, 0.60, 0.70, 0.00, 0.8, 0.8, 0.00, 0.00, 0.00};
  double Kiner[N_DOFS+1] = {0.0, 0.40, 0.40, 0.30, 0.35, 0.00, 0.4, 0.4, 0.00, 0.00, 0.00};
  double Kint[N_DOFS+1]  = {0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.001, 0.001, 0.001};
  double thres[N_DOFS+1] = {0.0, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.05, 0.05, 0.05};
  
  int ans;  


  for (i=1; i<=N_DOFS; ++i) {
    joint_filt_state[i] = filter(i);
  } 
 
  hand_vel = 0.0;
  for (i=1;i<=3;i++) {
    hand_vel += cart_state[1].xd[i]*cart_state[1].xd[i];
  }
  hand_vel = sqrt(hand_vel);

  target_dist = dist_to_target();

  // return robot to starting position
  if (goHome==TRUE && saving == FALSE) {    
    
    // The only purpose of the following printfs, is so when using the robot, I can see when the experiment is over
    if (trial >= numtrials) {
      //if (catches_finished >= num_catch) {
      printf("=====================================================================================\n");
      printf("=====================================================================================\n");
      printf("=====================================================================================\n");
      printf("=====================================================================================\n");
      printf("=====================================  FINISHED  ====================================\n");
      printf("=====================================================================================\n");
      printf("=====================================================================================\n");
      printf("=====================================================================================\n");
      printf("=====================================================================================\n");
      //startLocation=0;
    }
   
    //load the starting position into home_target
    select_target(home_target,startLocation); 

    //goto the home position
    if (goto_target(home_target,goto_speed)==1) {

       //robot has reached home, reset flags
       goHome=FALSE;  
       // initGotoTarget=TRUE;
       expOn=FALSE;
       saving=FALSE;
       gravCompOn=FALSE;
       beepFlag=TRUE;
       beepCycle = 0;

       if (blocktype==FORCETRAIN) {
         fieldon=TRUE;
       }
       else if (blocktype==TEST) {
         fieldon=catch_trial();
       }
       else { //blocktype==NULLTRAIN
         fieldon=FALSE;
       }
       
       printf("Trial %d/%d ready:\n",trial+1,numtrials);
       //if (fieldon == TRUE) 
       //   printf("Force Field ON\n");
       //else
       //   printf("Force Field OFF\n");
    }      
  } // end GoHome
  
  else {

    /******  beeping does not work with current mandrake version 10.0 ******/
    if (beepFlag==TRUE) {
      //logMsg("Beep! %c\n",0x7,0,0,0,0,0);
      beepFlag=FALSE;
    }
    
    if (expOn == TRUE) {
      expTrigger = TRUE;
      trial_time += time_step;
      if ((target_dist <= target_radius) && (hand_vel <= 0.1)) {
	time_in_target += time_step;
      } 
      else {
	time_in_target = 0.0;
      }
    }
    else {
      expTrigger = FALSE;
      trial_time = 0.0;
      time_in_target = 0.0;
    }

    if (joint_state[8].th < 0.08) { //Thumb trigger
      //if (joint_state[10].th < -0.3) { //finger trigger
      if (beepCycle == 0) {
	beepCycle = 1;
        if (expOn == FALSE && saving == FALSE) {
	  scd();
        }
      }
    }
   
    if (beepCycle == 1) {
      beep_timer = 0.0;
      logMsg("Beep1! %c\n",0x7,0,0,0,0,0);
      beepCycle = 2;
    }
    if (beepCycle == 2) {
      beep_timer += time_step;
      if (beep_timer > MAX_beep_timer) {
	beep_timer = 0.0;
	beepCycle = 3;
	logMsg("Beep2! %c\n",0x7,0,0,0,0,0);
      }
    }
    if (beepCycle == 3) {
      beep_timer += time_step;
      if (beep_timer > MAX_beep_timer) {
	beep_timer = 0.0;
	beepCycle = 4;
	logMsg("Beep3! %c\n",0x7,0,0,0,0,0);
      }
    }
    if (beepCycle == 4) {
      beep_timer += time_step;
      if (beep_timer > 0.1) {
	beep_timer = 0.0;
	beepCycle = 5;
	expTrigger = TRUE;
      }
    }
      
   
    //else {
    //  expTrigger = FALSE;
    //}
    if (trial_time > MAX_trial_time) {
      logMsg("Too much time! %c\n",0x7,0,0,0,0,0);
      expTrigger = FALSE;
    }
    if (time_in_target > req_time_in_target) {
      expTrigger = FALSE;
    }


    if (expTrigger == TRUE) {
      if (expOn == FALSE && saving == FALSE) {
        gravCompOn = TRUE;
        expOn = TRUE;
        //scd();
      }
    }
    else {
      gravCompOn = FALSE;
      if (expOn == TRUE) {
        stopcd();
	sendCommandLineCmd("saveData");
        saving = TRUE;
        expOn = FALSE;
	wait_ticks = task_servo_rate;
        ++trial;
        logMsg("\n****** Trial %d/%d Complete *****\n",trial,numtrials,i,i,i,i);
	logMsg("**  Time = %.3f\n",trial_time,i,i,i,i,i);
	logMsg("**  Dist to Target = %.3f\n",target_dist,i,i,i,i,i);
	logMsg("**  Time in Target = %.3f\n",time_in_target,i,i,i,i,i);
	logMsg("**  Catches Completed: %d/%d\n",catches_finished,num_catch,i,i,i,i);
	logMsg("**********************************\n\n",i,i,i,i,i,i);
      }
    }    

    if (saving == TRUE) { 
      if (--wait_ticks < 0) { //Don't go home until done saving
        saving=FALSE;
	goHome=TRUE;  
      }
    }

    if (gravCompOn == TRUE) {
      // Gravity Compensation
      for (i=1; i<=N_DOFS; ++i) {
	if (fabs(joint_state[i].th-joint_des_state[i].th) > thres[i]){
	  joint_des_state[i].th += (joint_state[i].th-joint_des_state[i].th)*Kint[i];
	}
      }

      // add gravity compensation relative to the current state of the robot
      for (i=1; i<=N_DOFS; ++i) { 
      // Gravity Compensation
	 target[i].th   = joint_state[i].th;
      // Coriolus Compensation
	 target[i].thd  = Kcori[i]*joint_filt_state[i].thd;
      // Inertia Compensation
	 target[i].thdd = Kiner[i]*joint_filt_state[i].thdd;
           
         target[i].uff  = 0.0;
      }

      SL_InverseDynamics(NULL,target,endeff);

      // assign compensation torques
      for (i=1; i<=N_DOFS; ++i) {
        if (i==1 || i==2 || i==3 || i==4 || i==5 || i==6 || i==7) { 
	  // Use my own damping (not premultiplied by the inertia matrix)
	  joint_des_state[i].uff = target[i].uff + (0.0 - joint_filt_state[i].thd) * Kdamp[i] * controller_gain_thd[i];
    
          // Cancel damping in the motor servo
	  joint_des_state[i].thd = joint_state[i].thd;  
        }
        else {
          // Do not use my own damping
	  joint_des_state[i].uff   = target[i].uff;
        }
      }

      
      for (i=1;i<=3;i++) {
	for (j=1;j<=7;j++) {
	  J_3x7.J[i][j] = J[i][j];
	}
      }
      compute_detJWJT(&J_3x7,W,&det);
      //compute_inv_and_null_W(&J_3x7,W);
      compute_inv_and_null(&J_3x7);
      for (i=1;i<=7;i++) {
        u_field[i]   = 0.0;
	u_field_A[i] = 0.0;
	u_field_B[i] = 0.0;
	u_field_C[i] = 0.0;
        qd[i] = 0.0;
      }   
      //qd[4] = joint_filt_state[1].thd + joint_filt_state[2].thd; 
      //qd[4] = joint_filt_state[1].thd + joint_filt_state[2].thd; 
      qd[5] = cart_state[1].xd[_X_] - cart_state[1].xd[_Y_];;

      //u_field_A[4] = qd[4]; //SFN04 Forcefield
      if (fieldtype == JOINTSPACE2) {
	//u_field_A[3] = joint_filt_state[1].thd + joint_filt_state[2].thd; 
	u_field_A[3] = joint_filt_state[4].thd; 
      }
      else {
	u_field_A[4] = joint_filt_state[1].thd + joint_filt_state[2].thd; 
      }
      //if (!mat_vec_mult(J_3x7.JhJT, qd, u_field_B))  //task space forcefield)
      //return FALSE;
      
      //if (!mat_vec_mult(J_3x7.NT, qd, u_field_C)) //null space forcefield
      //return FALSE;

      for (i=1;i<=3;i++) {
        xd[i] = cart_state[1].xd[i];
      }
 
      if (!mat_vec_mult(B, xd, xd))
	return FALSE;
      if (!mat_vec_mult(J_3x7.JT, xd, u_field_B))  //task space forcefield
        return FALSE;


      if (!mat_vec_mult(J_3x7.N, qd, u_field_C)) //null space forcefield
	return FALSE;
    
      u_field_norm = 0.0;
      u_field_A_norm = 0.0;
      u_field_B_norm = 0.0;
      u_field_C_norm = 0.0;

      for (i=1;i<=7;i++) {
	u_field_A_data[i] = u_field_A[i]; //for data collection only
	u_field_A_norm += u_field_A[i]*u_field_A[i];
 	u_field_B_data[i] = u_field_B[i]; //for data collection only
	u_field_B_norm += u_field_B[i]*u_field_B[i];
 	u_field_C_data[i] = u_field_C[i]; //for data collection only
	u_field_C_norm += u_field_C[i]*u_field_C[i];
      }

      u_field_A_norm = sqrt(u_field_A_norm);
      u_field_B_norm = sqrt(u_field_B_norm);
      u_field_C_norm = sqrt(u_field_C_norm);

      /* FORCE FIELDS GO HERE */
      if (fieldon==TRUE) {

	for (i=1;i<=7;i++) {
          if (fieldtype == JOINTSPACE || fieldtype == JOINTSPACE2) {
	    u_field[i] = fieldGain*u_field_A[i];
	  }
	  else if (fieldtype == TASKSPACE) {
	    u_field[i] = fieldGain*u_field_B[i];
	  }
	  else if(fieldtype == NULLSPACE) {
	    u_field[i] = fieldGain*u_field_C[i];
	  }
	  else {
	    u_field[i] = 0.0;
	  }

          //SAFETY CHECK
	  u_field_CLIP = FALSE;
	  if (u_field[i] > u_field_MAX[i]) {
	    u_field[i] = u_field_MAX[i];
	    u_field_CLIP = TRUE;
	    printf("------CLIPPING FORCE FIELD TORQUE------ Joint[%d]\n",i);
	  }
          if (u_field[i] < u_field_MIN[i]) {
	    u_field[i] = u_field_MIN[i];
	    u_field_CLIP = TRUE;
	    printf("------CLIPPING FORCE FIELD TORQUE------ Joint[%d]\n",i);
	  }
	  
          joint_des_state[i].uff += u_field[i];

	  u_field_data[i] = u_field[i]; //for data collection only
          u_field_norm += u_field[i]*u_field[i];
	}
	u_field_norm = sqrt(u_field_norm);
      }
    }     
  }
  return TRUE;
}

/*****************************************************************************
******************************************************************************
  Function Name	: change_forcefield_task
  Date		: May 2005

  Remarks:

  changes the task parameters

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
static int 
change_forcefield_B_task(void)
{
  double aux;
  int auxi;
  int skip;
  int setGoHome;

  setGoHome=0;
  skip=0; 
 
  get_int("Enter 1 to reset block, or 2 to change block parameters",0,&auxi);
  if (auxi==1) {
    trial=0;
    catches_finished=0;
    catch_index = 0;
    setGoHome=1;
  }

  else if (auxi==2) { 
    get_int("Block Type: 1=NULLTRAIN 2=FORCETRAIN 3=TEST",blocktype,&auxi);
    if (blocktype != auxi) {
      blocktype = auxi;
    }
  
    
    get_int("Start Location",startLocation,&auxi);
    if (startLocation != auxi) {
      startLocation=auxi;
      setGoHome=1;
      /*
      if (skip != 1) {
        get_int("Start Location changed! Reset block?",1,&auxi);
        if (auxi==1) {
          trial=0;
          catches_finished=0;
          skip=1;
        }  
      }
      */       
    }
    

    if (skip==0) {
      //get_double("switch Probability",switchProb,&aux);
      //if (aux < 0.0 || aux > 1.0) {
      //  printf("Invalid probability entered, setting switchProb to 0.0\n");
      //aux = 0.0;
      //}
      //switchProb = aux;

      get_int("Field Type: 1=NULLFIELD  2=JOINTSPACE 3=JOINTSPACE2 4=TASKSPACE  5=NULLSPACE",fieldtype,&auxi);
      if (fieldtype != auxi) {
	fieldtype = auxi;
      }

      get_double("fieldGain",fieldGain,&aux);
      if (aux < 0.0 || aux > 20.0) {
	printf("Gain out of safety range, setting fieldGain to 1.0\n");
	aux = 1.0;
      }
      fieldGain = aux;

      /*
      get_double("sigmaField",sigmaField,&aux);
      if (aux < 0.0 || aux > 0.7) {
	printf("sigmaField out of safety range, setting fieldGain to 0.0\n");
	aux = 0.0;
      }
      sigmaField = aux;
      */

      get_int("Trial number [current value]",trial,&auxi);
      trial=auxi;  
      /*  
      get_int("Catches finished [current value]",catches_finished,&auxi);
      catches_finished=auxi;
      */ 
      get_int("Number of Trials in Block",numtrials,&auxi);
      numtrials=auxi;
      /*
      get_int("Number if catch trials in a catch trial block",num_catch,&auxi);
      num_catch=auxi;
      
      get_int("Number of non-catches before first catch",num_begin,&auxi);
      num_begin=auxi;
   
      get_double("Goto Home speed",goto_speed,&aux);
      goto_speed=aux;
      */
      get_int("Reset block?",0,&auxi); 
      if (auxi==1) {
        trial=0;
        catches_finished=0;
        catch_index = 0;
        skip=1;
        setGoHome=1;
      }

    }
  }
 
  if (setGoHome==1)
    goHome=TRUE;

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

static int
catch_trial(void)
  {
    int num_space=1;  //NOT IMPLEMENTED YET minimum number of trials in between catch-trials
    double prob;

    //if (trial < num_begin) {
    //  return 0;
    //}
    if (trial < numtrials) {

      //PRECOMPUTED SEQUENCE 
      //if (catch_seq[catch_index++] == 1) {
      printf("trial is %d\n",trial);
      if (catch_seq[trial] == 1) {
	catches_finished++;
	return 1;
      }
      else
        return 0;

      //OLD ALGORITHM
      //prob=(num_catch-catches_finished)/ (double) (numtrials-trial);
      //printf("prob=%f\n",prob); //DEBUG printf 
      //if (prob_experiment(prob)) {
      //  catches_finished++;
      //  return 1;
      //}
      //else
      //  return 0;
  
      //NEW ALGORITHM
      // catch padding is the number of regular trials, before a catch trial is allowed.
      //   thus we prevent 2 or catch trials in a row)
      //if (catch_padding <= 0) {
      //  catches_finished++;
      //  catch_padding = random_number(10,4);  //at least 4 to 10 regular trials before a catch
      //  return 1;
      //}
      //else {
      //catch_padding--;
      //   return 0;
      //}

    }
    else {
      catches_finished = 0;
    }
    return 0;
  }

static int
goto_target(SL_DJstate* target_des, double speed)
  {
  //initialize start position - run once each time the robot must return home
  int i,j;

  if (initGotoTarget==TRUE) {

      if (speed > 2.0) {
        speed = 2.0;
      }      
      if (speed < 0.0) {
        speed = 0.5;
      }

      max_range = 0;
      
      //set desired vel, acc, uff to zero      
      for (i=1; i<=n_dofs; ++i) {
        target_des[i].thd  = 0.0;
        target_des[i].thdd = 0.0;
        target_des[i].uff = 0.0;
      }

      SL_InvDynNE(NULL,target,endeff,&base_state,&base_orient);

      for (i=1; i<=n_dofs; ++i) {
        joint_goto_state[i] = target_des[i];
      }

      check_range(joint_goto_state);

  
      for (i=1; i<=n_dofs; ++i) {      
        if (fabs(joint_goto_state[i].th - joint_des_state[i].th) > max_range)
          max_range = fabs(joint_goto_state[i].th - joint_des_state[i].th);
      }

      n_steps = 0;
      n_goto_steps = max_range/speed*task_servo_rate;

      if (n_goto_steps == 0) {
        for (i=1; i<=n_dofs; ++i) {
          if (fabs(joint_goto_state[i].uff - joint_des_state[i].uff) != 0)
            n_goto_steps = task_servo_rate;
          }
        if (n_goto_steps == 0) {
	  n_goto_steps = task_servo_rate;
          //return TRUE;
        }
      }
      for (i=1; i<=n_dofs; ++i) {
        joint_increment[i].th = (joint_goto_state[i].th - joint_des_state[i].th)/
          (double) n_goto_steps;
        joint_increment[i].uff = (joint_goto_state[i].uff - joint_des_state[i].uff)/
          (double) n_goto_steps;
        joint_increment[i].thd = 0;
      }
      initGotoTarget=FALSE;
    } // end initGotoTarget

    for (i=1; i<=n_dofs; ++i) {
      joint_des_state[i].th   += joint_increment[i].th;
      joint_des_state[i].thd   = 0.0;
      joint_des_state[i].uff  += joint_increment[i].uff;
    }
    if (++n_steps >= n_goto_steps) {
      //robot has reached target
      initGotoTarget=TRUE;
      balls[1][_X_] = cart_des_state[RIGHT_HAND].x[_X_];
      balls[1][_Y_] = cart_des_state[RIGHT_HAND].x[_Y_];
      balls[1][_Z_] = cart_des_state[RIGHT_HAND].x[_Z_];
      sendUserGraphics("forceField",&(balls[1]),sizeof(float)*N_CART);
      return 1;
    }
    return 0;      
  } // end GoHome


//Select the starting posture of the robot
static int
select_target(SL_DJstate* newtarget, int target_num) 
{
  int i;
      for (i=1; i<=n_dofs; ++i) {
        newtarget[i].thd  = 0.0;
        newtarget[i].thdd = 0.0;
        newtarget[i].uff = 0.0;
      }

      if (target_num == 1) {
        //right and up high
	newtarget[1].th = 0.340; 
	newtarget[2].th = -0.759; 
	newtarget[3].th = 0.823; 
	newtarget[4].th = 1.614; 
	newtarget[5].th = -0.015; 
	newtarget[6].th = 0.000; 
	newtarget[7].th = 0.033; 
	newtarget[8].th = 0.258; 
	newtarget[9].th = -0.186; 
	newtarget[10].th = 0.033; 

	reach_target.x[_X_] = balls[2][_X_] =  0.233;
	reach_target.x[_Y_] = balls[2][_Y_] =  0.420;
	reach_target.x[_Z_] = balls[2][_Z_] = -0.118;

	/* sendUserGraphics("ball",&(ball[1]),sizeof(float)*N_CART); */

      }

      else if (target_num == 10) {
	//TARGET for pos 1  //endeff is at: x=0.233 y=0.420 z=-0.118
      	newtarget[1].th= 0.449;
	newtarget[2].th=-0.213;
	newtarget[3].th=-0.306;
	newtarget[4].th= 0.931;
	newtarget[5].th= 0.398;
	newtarget[6].th= 0.076;
	newtarget[7].th=-0.033;
	newtarget[8].th= 0.172;
	newtarget[9].th=-0.188;
	newtarget[10].th=-0.205;
      }
     
      else if (target_num == 2) {
        //back
	newtarget[1].th=-0.277;
	newtarget[2].th=-0.325;
	newtarget[3].th=-0.413;
	newtarget[4].th= 1.868;
	newtarget[5].th= 0.154;
	newtarget[6].th= 0.262;
	newtarget[7].th=-0.001;
	newtarget[8].th= 0.134;
	newtarget[9].th=-0.005;
	newtarget[10].th= 0.112;
      }

      else if (target_num == 3) {
	//right to left
	newtarget[1].th=-0.380;
	newtarget[2].th=-0.333;
	newtarget[3].th=0.191;
	newtarget[4].th=1.727;
	newtarget[5].th=0.375;
	newtarget[6].th=0.303;
	newtarget[7].th=0.002;
	newtarget[8].th= 0.134;
	newtarget[9].th=-0.005;
	newtarget[10].th= 0.112;
      }

      else if (target_num == 4) {
	///up to down
	newtarget[1].th=0.650;
	newtarget[2].th=-0.671;
	newtarget[3].th=-0.245;
	newtarget[4].th=1.788;
	newtarget[5].th=-0.483;
	newtarget[6].th=-0.068;
	newtarget[7].th=-0.157;
	newtarget[8].th= 0.134;
	newtarget[9].th=-0.005;
	newtarget[10].th= 0.112;
      }

      /*
      else if (target_num == 5) {
	//up-right target
	newtarget[1].th=0.197;
	newtarget[2].th=-0.172;
	newtarget[3].th=-0.424;
	newtarget[4].th=1.142;
	newtarget[5].th=-0.268;
	newtarget[6].th=0.032;
	newtarget[7].th=-0.149;
	newtarget[8].th= 0.134;
	newtarget[9].th=-0.005;
	newtarget[10].th= 0.112;
      }
      */
      else if (target_num == 5) {
	//up-right target
	newtarget[1].th=0.212;
	newtarget[2].th=-0.241;
	newtarget[3].th=-0.401;
	newtarget[4].th=1.219;
	newtarget[5].th=-0.323;
	newtarget[6].th=-0.070;
	newtarget[7].th=-0.169;
	newtarget[8].th= 0.134;
	newtarget[9].th=-0.005;
	newtarget[10].th= 0.112;
      }
      /*
      else if (target_num == 6) {
	//back target
	newtarget[1].th=0.586;
	newtarget[2].th=-0.286;
	newtarget[3].th=0.073;
	newtarget[4].th=1.062;
	newtarget[5].th=0.329;
	newtarget[6].th=0.050;
	newtarget[7].th=-0.063;
	newtarget[8].th= 0.134;
	newtarget[9].th=-0.005;
	newtarget[10].th= 0.112;
      }
      */
      else if (target_num == 6) {
	//back target
	newtarget[1].th=0.730;
	newtarget[2].th=-0.108;
	newtarget[3].th=0.441;
	newtarget[4].th=1.007;
	newtarget[5].th=-0.143;
	newtarget[6].th=0.016;
	newtarget[7].th=-0.122;
	newtarget[8].th= 0.134;
	newtarget[9].th=-0.005;
	newtarget[10].th= 0.112;
      }

      else if (target_num == 7) {
	//right to left target
	newtarget[1].th=0.414;
	newtarget[2].th=-0.033;
	newtarget[3].th=-0.630;
	newtarget[4].th=1.235;
	newtarget[5].th=0.198;
	newtarget[6].th=0.279;
	newtarget[7].th=-0.033;
	newtarget[8].th= 0.134;
	newtarget[9].th=-0.005;
	newtarget[10].th= 0.112;
      }

      else if (target_num == 99) {
	//SFN07, NCM08
	newtarget[1].th=-0.187;
	newtarget[2].th=-0.277;
	newtarget[3].th=-0.202;
	newtarget[4].th=1.488;
	newtarget[5].th=0.378;
	newtarget[6].th=0.191;
	newtarget[7].th=-0.303;
	newtarget[8].th= 0.134;
	newtarget[9].th=-0.005;
	newtarget[10].th= 0.112;
      }

      

      else  {
	// go0 location
	newtarget[1].th = 0.009; 
	newtarget[2].th = -0.068; 
	newtarget[3].th = 0.017; 
	newtarget[4].th = 1.075; 
	newtarget[5].th = 0.176; 
	newtarget[6].th = -0.073; 
	newtarget[7].th = -0.166; 
	newtarget[8].th = 0.208; 
	newtarget[9].th = -0.250; 
	newtarget[10].th = 0.062; 
      }

      
      return 1;
}
  
static double 
dist_to_target(void) {
  double dist;
  int i;
  dist = 0.0;
  for (i=1;i<=3;i++) {
    dist += (cart_state[1].x[i]-reach_target.x[i])*(cart_state[1].x[i]-reach_target.x[i]);
  }
  return sqrt(dist);
}

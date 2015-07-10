/*============================================================================
==============================================================================
                      
                              dcp_task.c
 
==============================================================================
Remarks:

      task for CS545 to program a honey sphere on the robot

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

// private includes
#include "utility.h"
#include "lwpr.h"
#include "dcp.h"

// defines
#define  BASEBALL_BAT_LENGTH 0.55
#define  N_PEGASUS  50
#define  N_RAND_REP 10

// switch events
#define RUN_DCP  1
#define GO_BACK  2
static int        event = RUN_DCP;
static double     pause_duration = 1;
static double     start_time;
static int        count_repeats;
static int        max_repeats = 5;

//local variables
static int        use_invdyn = TRUE;
static int        dcps_initialized = FALSE;
static SL_DJstate target[N_DOFS+1];
static double     ball[N_CART+1] = {0.0,0.35,0.7,-0.25};
static int        servo_ticks;
static FILE      *fp;
static int        n_iter;

// DCP related variables
#define           N_INIT_RFS 10
#define           N_DCPS     (N_DOFS-N_DOFS_EST_SKIP)
static double     duration = 0.7;
static int        n_iter_per_servo_tick = 2;
static double     start_state[N_DCPS+1]= {0.0,-0.35,-0.53, 1.29,1.43,0.51,-0.03,0.61};
static double     target_state[N_DCPS+1]={0.0, 0.20,-0.06,-0.11,0.86,0.19,-0.01,0.16 };

// learning related variables
#define           MAX_BASES  20
static int        use_learning = FALSE;
static int        n_bases;
static double     bases[MAX_BASES+1];
static double     sum_bases[N_DCPS+1][MAX_BASES+1];
static double     ng[MAX_BASES+1];
static double     cost[N_DCPS+1];
static Matrix     XTX[N_DCPS+1];
static Vector     XTY[N_DCPS+1];
static double     eps[N_DCPS+1];
static double     lambda          = 0.99;
static double     std_noise       = 5.0;
static double     std_noise_min   = .5;
static double     ridge           = 1.0;
static double     n_data          = 0;
static double     alpha           = 0.1*10;
static double     factor_terminal = 10.0;

static double     bases[MAX_BASES+1];
static double     sum_bases[N_DCPS+1][MAX_BASES+1];
static int        myseed;
static int        base_seed;
static double     min_dist;


// learning related variables
double v_threshold = 0.05;

//global variables

// external variables
extern int save_data_flag;

// global functions
void add_dcp_task(void);
void saveDCPs(void);
void deleteDCPs(void);


// local functions
static int init_dcp_task(void);
static int run_dcp_task(void);
static int change_dcp_task(void);
static void display_ball(void);
static void update_RL(void);


 
/*****************************************************************************
******************************************************************************
Function Name	: add_dcp_task
Date		: Feb 1999
Remarks:

adds the task to the task menu

******************************************************************************
Paramters:  (i/o = input/output)

none

*****************************************************************************/
void
add_dcp_task( void )

{
  int i, j;
  
  addTask("Discrete Primitive", init_dcp_task, 
	  run_dcp_task, change_dcp_task);

  addToMan("saveDCPs","Saves all DCPS to binary files",saveDCPs);
  addToMan("deleteDCPs","Delete all DCPS",deleteDCPs);

}    

/*****************************************************************************
******************************************************************************
  Function Name	: init_dcp_task
  Date		: Dec. 1997

  Remarks:

  initialization for task

******************************************************************************
  Paramters:  (i/o = input/output)

       none

 *****************************************************************************/
static int 
init_dcp_task(void)
{
  int j, i, o;
  char string[100];
  double max_range=0;
  int ans;

  // check whether any other task is running
  if (strcmp(current_task_name,NO_TASK) != 0) {
    printf("New task can only be run if no other task is running!\n");
    return FALSE;
  }

  // first time?
  if (!dcps_initialized) {

    // initialize the DCPs
    for (i=1; i<=N_DCPS; ++i) {
      sprintf(string,"learn/%s_dcp",joint_names[i]);
      if (!initDCP(i, string, N_INIT_RFS, "learn/dcp.script", FALSE))
	return FALSE;
      // need this to learn from scratch
      for (j=1; j<=N_INIT_RFS; ++j)
	lwprs[dcps[i].lwpr_ID].rfs[j].trustworthy = TRUE;
    }

    dcps_initialized = TRUE;

  }

  // set the endeffector to mimic the base ball bat
  setDefaultEndeffector();
  endeff[RIGHT_HAND].x[_Y_]  = BASEBALL_BAT_LENGTH;

  // some additional variables
  get_int("Repeat movement how often?",max_repeats,&max_repeats);
  pause_duration = duration;
  get_double("Pause how long after the movement?",pause_duration,&pause_duration);
  get_int("Use learning?",use_learning,&use_learning);


  // go to the start posture
  for (i=1; i<=N_DCPS; ++i)
    target[i].th = start_state[i];

  if (!go_target_wait_ID(target))
    return FALSE;


  // use inverse dynamics servo
  get_int("Use invdyn servo?",use_idservo,&use_idservo);
  if (!use_idservo)
    get_int("Use local invdyn?",use_invdyn,&use_invdyn);

  // switch the servo mode
  if (use_idservo)
    setServoMode(INVDYNSERVO);
  else
    setServoMode(MOTORSERVO);

  // reset the DCPs
  for (i=1; i<=N_DCPS; ++i) {
    resetDCPState(i,start_state[i]); // could also be set to joint_des_state
    setDCPGoal(i,target_state[i],TRUE);
  }

  // reset RL variables
  for (i=1; i<=N_DCPS; ++i) {
    cost[i] = 0;
    min_dist=999;
    for (o=1; o<=MAX_BASES; ++o) 
      sum_bases[i][o] = 0.0;
    mat_zero(XTX[i]);
    vec_zero(XTY[i]);
  }
  n_data = 0;

  // need defined seed for RL
  base_seed = gaussian(0.0,1.0);
  base_seed = gaussian(0.0,1.0); // intentionally called twice
                                 // to reset random number generator
  // base_seed = -10; // constant seed for testing

  // do we really want to do this task?
  ans = 999;
  while (ans == 999) {
    if (!get_int("Enter 1 to start or anthing else to abort ...",ans,&ans))
      return FALSE;
  }
  
  if (ans != 1) 
    return FALSE;

  event = RUN_DCP;
  count_repeats = 0;
  servo_ticks   = 0;
  n_iter        = 0;
  start_time = task_servo_time;
  scd();

  return TRUE;

}

/*****************************************************************************
******************************************************************************
  Function Name	: run_dcp_task
  Date		: Dec. 1997

  Remarks:

  run the task from the task servo: REAL TIME requirements!

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
static int 
run_dcp_task(void)
{
  int j, i, o, r;
  double y,yd,ydd;
  double dt;
  double dur;
  double aux;

  dur = duration;
  ++servo_ticks;

  switch (event) {
    
  case GO_BACK:
    dur = duration*2.0;
    
  case RUN_DCP:

    // Pegasus repeated random variables
    if (count_repeats%N_PEGASUS == 0 || count_repeats == 0) {
      if (count_repeats == 0) // was used to make little simlation the same
	count_repeats = 1;
      myseed = base_seed;
      my_ran0(&myseed);
    }

    ++n_iter; // count how many iteration per primitive execution

    for (i=1; i<=N_DCPS; ++i) {

      // a random perturbaton for RL, only change at a certain frequency
      if (use_learning && event == RUN_DCP) {
	if (servo_ticks%N_RAND_REP==0 || servo_ticks==1)
	  eps[i] = gaussian(0.0,std_noise);
      } else {
	eps[i] = 0.0;
      }
      
      dt = 1./(double)task_servo_rate;
      n_bases = MAX_BASES;
      runDCP(i, dur, dt/(double)n_iter_per_servo_tick, 
	     n_iter_per_servo_tick, eps[i], 
	     &y,&yd,&ydd,&n_bases,bases);
      
      joint_des_state[i].th   = y;
      joint_des_state[i].thd  = yd;
      joint_des_state[i].thdd = ydd;

      // compute RL variables
      if (use_learning && event == RUN_DCP) {
	
	for (o=1; o<=n_bases; ++o) 
	  sum_bases[i][o] += bases[o]*eps[i];
	sum_bases[i][n_bases+1] += (sqr(eps[i]/std_noise)-1.)*std_noise;
	sum_bases[i][n_bases+2] += 1;
	  
	cost[i] += sqr(ydd/10.);
	if (task_servo_time - start_time >= duration)
	  cost[i] += factor_terminal*(sqr(yd) + sqr(y-target_state[i]));

      }
      
    }

    // compute the minmal distance from ball
    aux = sqrt(sqr(cart_des_state[RIGHT_HAND].x[_X_]-ball[_X_])+
	       sqr(cart_des_state[RIGHT_HAND].x[_Y_]-ball[_Y_])+
	       sqr(cart_des_state[RIGHT_HAND].x[_Z_]-ball[_Z_]));
    if (aux < min_dist)
      if (fabs(task_servo_time-start_time - 0.8*duration) < 0.01)
	min_dist = aux;

    // switch the event if needed
    if (task_servo_time - start_time >= dur + pause_duration) {
      start_time = task_servo_time;

      if (event == RUN_DCP) {

	event = GO_BACK;
	// update learning
	if (use_learning) 
	  update_RL();
	// set goal to start state
	for (i=1; i<=N_DCPS; ++i) {
	  setDCPGoal(i,start_state[i],TRUE);
	}

      } else { // even is not RUN_DCP

	event = RUN_DCP;
	n_iter = 0;
	servo_ticks=0;
	if (++count_repeats > max_repeats) {
	  freeze();
	  return TRUE;
	}

	// set goal to target
	for (i=1; i<=N_DCPS; ++i) {
	  resetDCPState(i,start_state[i]);
	  setDCPGoal(i,target_state[i],TRUE);
	}

	// reset RL variables
	min_dist=999;
	for (i=1; i<=N_DCPS; ++i) {
	  cost[i] = 0;
	  for (o=1; o<=MAX_BASES; ++o) 
	    sum_bases[i][o] = 0.0;
	}

      }

    }

    break;

  default:
    freeze();
    return FALSE;

  }


  // inverse dynanmics control
  if (use_invdyn && !use_idservo) 
    SL_InverseDynamics(joint_state,joint_des_state,endeff);

  // simulate the ball if needed
#ifndef VX
  display_ball();
#endif

  return TRUE;

}

/*****************************************************************************
******************************************************************************
  Function Name	: update_RL
  Date		: Oct. 2003

  Remarks:

  update the DCPs from policy gradient

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
static void
update_RL(void)
{

  int i,j,o;

  // add cost for hitting target (maybe not a great place to do this)
  for (i=1; i<=N_DCPS; ++i)
    //cost[i] += 10000.*min_dist;
    //cost[i] = 10000.*min_dist;
    ;

#ifndef VX
  if (count_repeats%N_PEGASUS == 0 || count_repeats == 1) {
    printf("%d: dist=%5.3f cost = ",count_repeats,min_dist);
    for (i=1; i<=N_DCPS; ++i)
      printf("%7.3f  ",cost[i]);
    printf("   std = %5.3f\n",std_noise);
  }
#endif

  // Natural Actor Critic Reinforcement Learning
  for (i=1; i<=N_DCPS; ++i) {
    mat_mult_scalar(XTX[i], lambda, XTX[i]);
    vec_mult_scalar(XTY[i], lambda, XTY[i]);
    for (j=1; j<=N_INIT_RFS+2; ++j) {
      XTY[i][j] += sum_bases[i][j]*cost[i];
      for (o=j; o<=N_INIT_RFS+2; ++o) {
	XTX[i][j][o] += sum_bases[i][j]*sum_bases[i][o];
	XTX[i][o][j]  = XTX[i][j][o];
      }
    }

    // compute the gradient and update the weights
    if (count_repeats > 2*(N_INIT_RFS+2)) {
      
      for (j=1; j<=N_INIT_RFS+2; ++j)
	XTX[i][j][j] += ridge;
      my_inv_ludcmp_solve(XTX[i], XTY[i], N_INIT_RFS+2, ng);
      for (j=1; j<=N_INIT_RFS+2; ++j)
	XTX[i][j][j] -= ridge;
      
      // update the weights
      for (j=1; j<=N_INIT_RFS; ++j) {
	lwprs[dcps[i].lwpr_ID].rfs[j].B[1][1] -= ng[j] * alpha * n_data * (1-lambda);
      }
      
	std_noise -= ng[N_INIT_RFS+1] * alpha * 0.1 * n_data * (1-lambda) / ((double) N_DCPS);
      if (std_noise < std_noise_min)
	std_noise = std_noise_min;
      
    }

  }

  // discounted number of data points
  n_data  = lambda*n_data + 1;

}
  

/*****************************************************************************
******************************************************************************
  Function Name	: change_dcp_task
  Date		: Dec. 1997

  Remarks:

  changes the task parameters

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
static int 
change_dcp_task(void)
{
  static int j, i;
  char string[100];
  double goal;
  double temp;

  i = 1;
  get_int("Which joint?",i,&i);
  if (i>=1 && i<=N_DCPS) {
    goal = dcps[i].goal;
    sprintf(string,"%s: enter new goal state",joint_names[i]);
    get_double(string,goal,&goal);
    if (goal <= joint_range[i][MAX_THETA] && goal >= joint_range[i][MIN_THETA])
        setDCPGoal(i,goal,TRUE);
  }

  get_double("Movement duration",duration,&temp);
  if (temp > 0.2)
    duration = temp;

  get_int("#Integration steps per servo step",n_iter_per_servo_tick,&i);
  if (i>=1)
    n_iter_per_servo_tick = i;

  get_double("Velocity Threshold",v_threshold,&v_threshold);

  return TRUE;

}

/*****************************************************************************
******************************************************************************
  Function Name	: saveDCPs
  Date		: Aug.2003

  Remarks:

  save all DCPs

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
void
saveDCPs(void)
{

  int i;
  
  if (strcmp(current_task_name,NO_TASK) != 0) {
    printf("Save can only be run if no other task is running!\n");
    return;
  }

  for (i=1; i<=N_DCPS; ++i)
    writeDCP(i);

}

/*****************************************************************************
******************************************************************************
  Function Name	: deleteDCPs
  Date		: Aug.2003

  Remarks:

  delete all DCPs

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
void
deleteDCPs(void)
{

  int i;

  if (strcmp(current_task_name,NO_TASK) != 0) {
    printf("Delete can only be run if no other task is running!\n");
    return;
  }
  
  for (i=1; i<=N_DCPS; ++i)
    deleteDCP(i);

  dcps_initialized = FALSE;

}

/*****************************************************************************
******************************************************************************
  Function Name	: teachDCPs
  Date		: Aug.2003

  Remarks:

  teaches the DCPs a new trajectory by moving the robot directly

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
void
teachDCPs(void)
{

  int    i,j;
  int    teach_which_dofs[N_DCPS+1];
  int    count_teach_dofs;
  int    ans=1;
  double start_time;
  double v;
  int    start_flag;
  double time_out = 5.0;
  Matrix th, thd, thdd;
  Vector t;
  int    n_rows;
  int    c;
  double last_time=0;
  char   cans[100]="a\0";
  char   string[100];
  double y,yd,ydd;
  
  // check whether any other task is running
  if (strcmp(current_task_name,NO_TASK) != 0) {
    printf("New task must be running during teaching!\n");
    return;
  }

  // first time? Initialize the DCPs
  if (!dcps_initialized) {

    // initialize the DCPs
    for (i=1; i<=N_DCPS; ++i) {
      sprintf(string,"learn/%s_dcp",joint_names[i]);
      if (!initDCP(i, string, N_INIT_RFS, "learn/dcp.script", FALSE))
	return;
    }

    dcps_initialized = TRUE;

  }


  // first check which DOFs should be taught
  get_string("Which DOFs?  All='a' OneDOF=#",
	  cans,cans);

  ans = cans[0];

  count_teach_dofs = 0;
  switch (ans) {

  case 'a': // all DOFs
    for (i=1; i<=N_DCPS; ++i)
      teach_which_dofs[++count_teach_dofs] = i;
    break;

  default: // one DOF only
    sscanf(cans,"%d",&ans);
    if (ans >= 1 && ans <=N_DCPS)
      teach_which_dofs[++count_teach_dofs] = ans;

  }

  // Second, we need to record a movement. This is done in a local
  // buffer for the speed of processing, although an mrdplot file is
  // collected as well

  printf("Start moving the robot immediately after the beep.\n");
  printf("Stop moving at the target point.\n");
  // do we really want to do this task?
  ans = 999;
  while (ans == 999) {
    if (!get_int("Enter 1 to start after 10 seconds delay or  anthing else to abort ...",ans,&ans))
      return;
  }

  // get some memory for the data
  n_rows = (int)(time_out*task_servo_rate)+10;
  th   = my_matrix(1,n_rows,1,count_teach_dofs);
  thd  = my_matrix(1,n_rows,1,count_teach_dofs);
  thdd = my_matrix(1,n_rows,1,count_teach_dofs);
  t    = my_vector(1,n_rows);
  c = 0;

  // wait for 10s, then beep
  start_time = task_servo_time;

  while (task_servo_time-start_time < 10) {

    // passively move the DOFs that are active
    for (i=1; i<=count_teach_dofs; ++i) {
      if (fabs(joint_state[teach_which_dofs[i]].th-joint_des_state[teach_which_dofs[i]].th) > 0.05){
	joint_des_state[teach_which_dofs[i]].th +=
	  (joint_state[teach_which_dofs[i]].th-joint_des_state[teach_which_dofs[i]].th)*0.01;
      }
    }

    // add gravity compensation
    for (i=1; i<=N_DOFS; ++i) {
      target[i].th   = joint_state[i].th;
      target[i].thd  = 0.0;
      target[i].thdd = 0.0;
      target[i].uff  = 0.0;
    }
    SL_InverseDynamics(NULL,target,endeff);
    for (i=1; i<=N_DOFS; ++i)
      joint_des_state[i].uff   = target[i].uff;


    // this will create two start beeps
    if (task_servo_time - start_time > 9.8) 
      beep(1);

  }

  // now we are ready to record
  taskDelay(1);
  start_time = task_servo_time;
  start_flag = FALSE;
  while (TRUE) {

    // passively move the DOFs that are active
    for (i=1; i<=count_teach_dofs; ++i) {
      if (fabs(joint_state[teach_which_dofs[i]].th-joint_des_state[teach_which_dofs[i]].th) > 0.05){
	joint_des_state[teach_which_dofs[i]].th +=
	  (joint_state[teach_which_dofs[i]].th-joint_des_state[teach_which_dofs[i]].th)*0.01;
      }
    }

    // add gravity compensation
    for (i=1; i<=N_DOFS; ++i) {
      target[i].th   = joint_state[i].th;
      target[i].thd  = 0.0;
      target[i].thdd = 0.0;
      target[i].uff  = 0.0;
    }
    SL_InverseDynamics(NULL,target,endeff);
    for (i=1; i<=N_DOFS; ++i)
      joint_des_state[i].uff   = target[i].uff;

    // compute the average velocity of all participating joints
    v = 0.0;
    for (i=1; i<=count_teach_dofs; ++i)
      v += sqr(joint_state[teach_which_dofs[i]].thd);
    v = sqrt(v)/(double)count_teach_dofs;

    // if velocity falls below threshold after at lest 200ms movement time
    if (task_servo_time - start_time > 0.4 && v < v_threshold && start_flag) {
      printf("stop: %f\n",v);
      save_data_flag = FALSE;
      break;
    } else if (!start_flag && v > v_threshold ) {  // this is the real movement start
      start_flag = TRUE;
      last_time  = task_servo_time;
      scd();
      start_time = task_servo_time;
      printf("start: %f\n",v);
    } else if (task_servo_time - start_time > time_out) { // time out
      printf("Time out!\n");
      return;
    } else if (start_flag) { // data collection
      if (task_servo_time != last_time) {
	if (++c > n_rows)
	  break;
	last_time = task_servo_time;
	for (i=1; i<=count_teach_dofs; ++i) {
	  t[c]       = last_time;
	  th[c][i]   = joint_state[teach_which_dofs[i]].th;
	  thd[c][i]  = joint_state[teach_which_dofs[i]].thd;
	  thdd[c][i] = joint_state[teach_which_dofs[i]].thdd;
	}
      }
    }

  }

  beep(1);
  duration = task_servo_time-start_time;
  printf("Duration = %f (v=%f)\n",duration,v);

  // do we really want to fit this trajectory
  ans = 999;
  while (ans == 999) {
    if (!get_int("Enter 1 to fit this trajectory or anthing else to abort ...",ans,&ans)) {
      // release memory
      my_free_matrix(th,1,n_rows,1,count_teach_dofs);
      my_free_matrix(thd,1,n_rows,1,count_teach_dofs);
      my_free_matrix(thdd,1,n_rows,1,count_teach_dofs);
      my_free_vector(t,1,n_rows);
      return;
    }
  }

  // fit the dynamic systems
  for (i=1; i<=c; ++i) {
    for (j=1; j<=count_teach_dofs; ++j) {

      if (i==1) {
	// reset DCP to start of recorded movement, set goal to end state
	resetDCPState(teach_which_dofs[j],th[i][j]);
	setDCPGoal(teach_which_dofs[j],th[c][j],FALSE);
      } else {
	// fit the trajectory
	runDCPFit(teach_which_dofs[j], 
		  duration, 
		  (t[i]-t[i-1])/(double)n_iter_per_servo_tick, 
		  n_iter_per_servo_tick, 
		  th[i][j],thd[i][j],thdd[i][j],
		  &y,&yd,&ydd);
      }
    }
  }

  // assign start and target state
  for (j=1; j<=count_teach_dofs; ++j) {
    start_state[teach_which_dofs[j]]  = th[1][j];
    target_state[teach_which_dofs[j]] = th[c][j];
  }

  printf("{0.0 ");
  for (i=1; i<=N_DCPS; ++i)
    printf(", %6.2f ",start_state[i]);
  printf("}\n");

  printf("{0.0 ");
  for (i=1; i<=N_DCPS; ++i)
    printf(", %6.2f ",target_state[i]);
  printf("}\n");

  // release memory
  my_free_matrix(th,1,n_rows,1,count_teach_dofs);
  my_free_matrix(thd,1,n_rows,1,count_teach_dofs);
  my_free_matrix(thdd,1,n_rows,1,count_teach_dofs);
  my_free_vector(t,1,n_rows);

}

#ifndef VX
/*****************************************************************************
 *****************************************************************************
 Function Name	: display_ball
 Date		: Aug. 99
 
 Remarks:

        diplays a ball for simulations

 ******************************************************************************
 Paramters:  (i/o = input/output)

     none

 ****************************************************************************/
#ifdef powerpc
#include <GLUT/glut.h>
#else
#include "GL/glut.h"
#endif
static void
display_ball(void)
{
  static int firsttime = TRUE;
  GLfloat  col[4]={(float)1.0,(float)1.0,(float)0.0,(float)1.0};

  /* the following automatically adds the display function to the 
     update routine */
  if (firsttime) {
    extern void addUserDisplayFunc(void (*fptr)(void));
    firsttime = FALSE;
    addUserDisplayFunc(display_ball);
  }

  /* here is the drawing rountines */
  glPushMatrix();
  glTranslated((GLdouble)ball[_X_],
	       (GLdouble)ball[_Y_],
	       (GLdouble)ball[_Z_]);
  
  glColor4fv(col);
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, col);
  glutSolidSphere(0.03,8,8);
  glPopMatrix();

}

#endif

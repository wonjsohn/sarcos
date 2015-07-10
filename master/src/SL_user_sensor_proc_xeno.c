/*!=============================================================================
  ==============================================================================

  \file    SL_user_sensor_proc_xeno.c

  \author 
  \date   

  ==============================================================================
  \remarks

  performs reading of sensors, translation to units, and sending out
  motor commands. This verion of the functions is for the real robot.

  ============================================================================*/

// SL general includes of system headers
#include "SL_system_headers.h"

// private includes
#include "utility.h"
#include "SL.h"
#include "SL_man.h"
#include "SL_motor_servo.h"
#include "SL_shared_memory.h"
#include "SL_common.h"
#include "SL_user.h"
#include "SL_sensor_proc.h"
#include "SL_oscilloscope.h"
#include "ajc.h"
#include "SL_collect_data.h"

#define TIME_OUT_NS      NO_WAIT          // we are just serving the graphics
#define TRANSLATION_FILE "Translation.cf"

typedef struct Translation {
  double slope;
  double offset;
} Translation;

// local variables
static AjcJoint        joint_list[N_DOFS+1];

static Translation     joint_trans_positions[N_DOFS+1];
static Translation     joint_trans_velocities[N_DOFS+1];
static Translation     joint_trans_torques[N_DOFS+1];
static Translation     joint_trans_desired_torques[N_DOFS+1];
static Translation     misc_trans_sensors[N_MISC_SENSORS+1];

static AjcValue        raw_positions[N_DOFS+1];
static AjcValue        raw_velocities[N_DOFS+1];
static AjcValue        raw_torques[N_DOFS+1];
static AjcValue        raw_desired_torques[N_DOFS+1];
static AjcValue        raw_misc_sensors[N_MISC_SENSORS+1];

static int             use_velocity_readings = FALSE;

// external variables
extern int           motor_servo_errors;

// global functions

// local functions
static int  read_translation(char *fname);
static int  send_sim_state(void);
static int  send_misc_sensors(void);
static void translate_sensor_readings(SL_Jstate *joint_raw_state);
static void translate_commands(SL_Jstate *command);
static void compute_ajc_statistics(void);
static void where_iraw(void);
static void changeAjcRegister(void);
static void read_trans(void);
static void read_sensor_offs(void);


/*!*****************************************************************************
 *******************************************************************************
\note  init_user_sensor_processing
\date  Feb. 2010
   
\remarks 

          Initializes all user specific sensory processing

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

     none

 ******************************************************************************/
int
init_user_sensor_processing(void)
{
  int i,j;
  char string[100];

  // initalizes translation to and from units
  if (!read_translation(TRANSLATION_FILE))
    return FALSE;

  // the joint list is need for reading multiple sensors at one shot
  for (i=1; i<=N_DOFS; ++i)
    joint_list[i] = i;

  addToMan("where_iraw","prints sensor readings as raw integers",where_iraw);
  addToMan("changeAjcRegisters","interactive change of AJC registers",changeAjcRegister);
  addToMan("readTranslation","re-reads the translation file",read_trans);
  addToMan("readSensorOffsets","re-reads the sensor-offsets file",read_sensor_offs);

  // add some data collection variables
  for (i=1; i<=n_dofs; ++i) {
    sprintf(string,"%s_ith",joint_names[i]);
    addVarToCollect((char *)&(raw_positions[i]),string,"int",INT,FALSE);
    sprintf(string,"%s_ithd",joint_names[i]);
    addVarToCollect((char *)&(raw_velocities[i]),string,"int",INT,FALSE);
    sprintf(string,"%s_iload",joint_names[i]);
    addVarToCollect((char *)&(raw_torques[i]),string,"int",INT,FALSE);
  }

  updateDataCollectScript();


  return TRUE;
}

/*!*****************************************************************************
 *******************************************************************************
\note  read_translation
\date  Feb 2010
   
\remarks 

the translation of raw numbers to and from units

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

   \param[in] fname: the filename to read from

 ******************************************************************************/
static void
read_trans(void)
{
  read_translation(TRANSLATION_FILE);
}

static int
read_translation(char *fname)
{
  
  int       i,j;
  int       rc;
  FILE      *in;
  int       error_flag = FALSE;
  char      string[100];


  /* Get the translation info for each joint: we just parse those
     values from the file config/Translation.cf */

  sprintf(string,"%s%s",CONFIG,fname);
  in = fopen(string,"r");
  if (in == NULL) {
    printf("ERROR: Cannot open file >%s<!\n",string);
    return FALSE;
  }

  /* parse all translation variables according to the joint variables */
  for (i=1; i<= n_dofs; ++i) {
    if (!find_keyword(in, &(joint_names[i][0]))) {
      printf("ERROR: Cannot find offset for >%s<!\n",joint_names[i]);
      fclose(in);
      return FALSE;
    }
    rc = fscanf(in,"%lf %lf %lf %lf %lf %lf %lf %lf",
		&joint_trans_positions[i].slope,
		&joint_trans_positions[i].offset,
		&joint_trans_velocities[i].slope,
		&joint_trans_velocities[i].offset,
		&joint_trans_torques[i].slope,
		&joint_trans_torques[i].offset,
		&joint_trans_desired_torques[i].slope,
		&joint_trans_desired_torques[i].offset);
  }

  for (i=1; i<= n_misc_sensors; ++i) {
    if (!find_keyword(in, &(misc_sensor_names[i][0]))) {
      printf("ERROR: Cannot find offset for >%s<!\n",misc_sensor_names[i]);
      fclose(in);
      return FALSE;
    }
    rc = fscanf(in,"%lf %lf",
		&misc_trans_sensors[i].slope,
		&misc_trans_sensors[i].offset);
  }

  fclose(in);

  return TRUE;

}

/*!*****************************************************************************
 *******************************************************************************
\note  read_user_sensors
\date  Feb 2010
   
\remarks 

    gets sensor readings from the robot and converts them into standard
    units

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[out]    raw :     the raw sensor readings
 \param[out]    misc_raw: the raw miscelleneous sensor readings

 ******************************************************************************/
int
read_user_sensors(SL_Jstate *raw,double *misc_raw)
{

  int i,j;
  static long last_motor_servo_calls = 0;

  use_velocity_readings = FALSE;

  // this initializes the velocity readings
  if (motor_servo_calls != last_motor_servo_calls+1)
    use_velocity_readings = TRUE;

  last_motor_servo_calls = motor_servo_calls;

  // read the positions
  if (!Ajc_ReadChannelFast(N_DOFS,joint_list,channelActPosStage1,raw_positions))
    return FALSE;

  // read the velocities
  if (use_velocity_readings) {

    if (!Ajc_ReadChannelFast(N_DOFS,joint_list,channelActVelocity,raw_velocities))
      return FALSE;

  }

  // read the torques
  if (!Ajc_ReadChannelFast(N_DOFS,joint_list,channelActTorque,raw_torques))
    return FALSE;


  // translate the raw values into units
  translate_sensor_readings(raw);

  // debugging whether values are read correctly -- only works with static robot
  // compute_ajc_statistics();

  // send the old sensor readings (which are processed by now) to
  // shared memory for the graphics visualization
  for (i=1; i<=N_DOFS; ++i)
    joint_sim_state[i] = joint_state[i];

  for (i=1; i<=N_MISC_SENSORS; ++i)
    misc_sim_sensor[i] = misc_sensor[i];

  send_sim_state();
  send_misc_sensors();

  return TRUE;

}

/*!*****************************************************************************
 *******************************************************************************
\note  translate_sensor_readings
\date  Dec 1997
   
\remarks 

          translate sensors to unit values

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[out]    raw : the raw state

 ******************************************************************************/
static void
translate_sensor_readings(SL_Jstate *joint_raw_state)
{

  int i,j;
  double temp=0;
  static SL_Jstate last_joint_raw_state[N_DOFS+1];


  for (i=1; i<=N_DOFS; ++i) {

    // translate the position sensors
    joint_raw_state[i].th = (joint_trans_positions[i].offset + 
			     raw_positions[i]) * 
      joint_trans_positions[i].slope;

    if (joint_lin_rot[i][SENSOR] == LINEAR) { 
      
      temp = (sqr(joint_raw_state[i].th)-sqr(joint_lin_rot[i][MOMENTARM]) - 
	      sqr(joint_lin_rot[i][MOUNTPOINT])) / 
	(2.*joint_lin_rot[i][MOMENTARM]*joint_lin_rot[i][MOUNTPOINT]);

      joint_raw_state[i].th = acos(temp);

    }

    // translate the velocity sensors
    if (use_velocity_readings) {

      joint_raw_state[i].thd = (joint_trans_velocities[i].offset + 
				raw_velocities[i]) * 
	joint_trans_velocities[i].slope;
      
      if (joint_lin_rot[i][SENSOR] == LINEAR) { 
	
	joint_raw_state[i].thd  = joint_raw_state[i].thd / 
	  (sqrt(1.-sqr(temp))*joint_lin_rot[i][MOMENTARM]*
	   joint_lin_rot[i][MOUNTPOINT]);
	
      }

    } else { // for velocity readings generated from diff position

      joint_raw_state[i].thd = 
	(joint_raw_state[i].th - last_joint_raw_state[i].th)*(double)motor_servo_rate;

    }

    last_joint_raw_state[i].th = joint_raw_state[i].th;

    // translate the force sensors
    joint_raw_state[i].load = (joint_trans_torques[i].offset + 
			       raw_torques[i]) * 
      joint_trans_torques[i].slope;

    if (joint_lin_rot[i][LOADCELL] == LINEAR) { 
      
      joint_raw_state[i].load  = joint_raw_state[i].load * 
	joint_lin_rot[i][MOMENTARM] * 
	cos(joint_raw_state[i].th - joint_lin_rot[i][THETA0]);

    }

    joint_raw_state[i].th   *= pos_polar[i];
    joint_raw_state[i].thd  *= pos_polar[i];
    joint_raw_state[i].load *= load_polar[i];

    /* take out the user offset from the position -- but not before here since
       the load cell readings need the un-offsetted information */
    
    joint_raw_state[i].th -= joint_range[i][THETA_OFFSET];


  }


}

/*!*****************************************************************************
 *******************************************************************************
\note  send_user_commands
\date  Feb 2010
   
\remarks 

    translates the commands into raw and sends them to the robot

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[in]     commands : the structure containing the commands

 ******************************************************************************/
int
send_user_commands(SL_Jstate *command)

{
  int i,j;

  // translate into raw values
  translate_commands(command);

  // read the positions
  if (!Ajc_WriteRegisterFast(N_DOFS,joint_list,registerDesiredTorqueCommand, 
			     raw_desired_torques))
    return FALSE;

  return TRUE;

}

/*!*****************************************************************************
 *******************************************************************************
\note  translate_commands
\date  Dec 1997
   
\remarks 

          translate unit commands into raw values

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[in]     commands : the structure containing the commands

 ******************************************************************************/
static void
translate_commands(SL_Jstate *command)

{

  int i,j;
  double temp=0;
  double raw;

  for (i=1; i<=N_DOFS; ++i) {

    /* translate the torque command first into a linear command, if
       necessary -- for AJC control, only needed if the torque cell
       is a linear with a linear actuator. Otherwise, the torque
       loop will take care of the ensuring the right value, no
       matter what the moment arms of the linear actuators */

    if (joint_lin_rot[i][ACTUATOR] == LINEAR && 
	joint_lin_rot[i][LOADCELL] == LINEAR ) { 

      temp = load_polar[i] * command[i].u / joint_lin_rot[i][MOMENTARM] /
	cos((command[i].th+joint_range[i][THETA_OFFSET])
	    - joint_lin_rot[i][THETA0]);
      
    } else {
      
      temp = command[i].u * load_polar[i];

    }
    
    raw = temp/joint_trans_desired_torques[i].slope -
      joint_trans_desired_torques[i].offset; 

    if (raw < 0) 
      raw = 0;
    if (raw > 4095)
      raw = 4095;

    raw_desired_torques[i] = (AjcValue) raw;

  }


}

/*!*****************************************************************************
 *******************************************************************************
\note  user_kill
\date  May 2000
   
\remarks 

        kill routine for the real robot

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

     none

 ******************************************************************************/
int
user_kill(void)

{
  Ajc_PumpKill();
  return TRUE;
}

/*!*****************************************************************************
 *******************************************************************************
\note  user_power_status
\date  May 2000
   
\remarks 

        power is on or off?

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

     none

 ******************************************************************************/
int
user_power_status(void)
{
  return Ajc_PumpStatus();
}

/*!*****************************************************************************
 *******************************************************************************
\note  userCheckForMessage
\date  Feb. 2009
   
\remarks 

          this function allows the user to intercept a message send to the
          motor servo and use this information in sensor_user_proc

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[in]     name : message identifying name
 \param[in]     k    : index of message in shared memory

 ******************************************************************************/
void
userCheckForMessage(char *name, int k)
{
  int i,j;

}

/*!*****************************************************************************
*******************************************************************************
\note  send_sim_state
\date  Nov. 2007
   
\remarks 

sends the entire joint_sim_state to shared memory


*******************************************************************************
Function Parameters: [in]=input,[out]=output

none

******************************************************************************/
static int 
send_sim_state(void)
{
  
  int i;

  // joint state
  if (semTake(sm_joint_sim_state_sem,ns2ticks(TIME_OUT_NS)) == ERROR) {
    
    ++motor_servo_errors;
    return FALSE;

  } 

  cSL_Jstate(joint_sim_state,sm_joint_sim_state_data,n_dofs,DOUBLE2FLOAT);
    
  for (i=1; i<=n_dofs; ++i)
      sm_joint_sim_state->joint_sim_state[i] = sm_joint_sim_state_data[i];
  
  semGive(sm_joint_sim_state_sem);

  // no need to send the base for a fixed-base system

  return TRUE;
}

/*!*****************************************************************************
 *******************************************************************************
\note  send_misc_sensors
\date  Feb. 2010
   
\remarks 

sends the entire misc_sim_sensor to shared memory
	

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 none
 
******************************************************************************/
static int 
send_misc_sensors(void)
{
  
  int i;
  
  if (n_misc_sensors <= 0)
    return TRUE;
  
  if (semTake(sm_misc_sim_sensor_sem,ns2ticks(TIME_OUT_NS)) == ERROR) {
    
    ++motor_servo_errors;
    return FALSE;
    
  } 
  
  for (i=1; i<=n_misc_sensors; ++i)
    sm_misc_sim_sensor->value[i] = misc_sim_sensor[i];
  
  semGive(sm_misc_sim_sensor_sem);
  
  return TRUE;
}

/*!*****************************************************************************
 *******************************************************************************
\note  user_controller
\date  Feb. 2009
   
\remarks 

          allows the user to modify the commands currently computed by 
          the active controller. Note that only u is actually used in
          the final send out of the commands to the robot, and ufb is only
          to kept as feedback to the user for data collection.

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[in,out] u     : the current total command
 \param[in,out] ufb   : the current feedback command

 ******************************************************************************/
void
user_controller(double *u, double *uf)
{
  int i,j;
}

/*!*****************************************************************************
 *******************************************************************************
\note  where_iraw
\date  Sept 2011
\remarks 

 prints sensor readings as raw integers

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 none

 ******************************************************************************/
static void
where_iraw(void)
{
  int i,j;

  if (!servo_enabled) {
    beep(1);
    printf("WARNING: motor servo is not running!!\n");
  }

  printf("Current Integer Raw Sensor States:\n");

  for (i=1; i<=N_DOFS; ++i) {

    printf("%2d: %5s: th=% 6d  thd=% 6d  load=% 6d\n",
	   i,joint_names[i],
	   raw_positions[i],
	   raw_velocities[i],
	   raw_torques[i]);

  }
  printf("\n");

}

/*!*****************************************************************************
 *******************************************************************************
\note  computer_ajc_statistics
\date  Sept 2011
\remarks 

 quick hack to look for outliers in communication, assuming the robot is not
 moving. This function is not properly maintained.

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 none

 ******************************************************************************/
static void
compute_ajc_statistics(void) 
{
  int i,j;
  static double  p[N_DOFS+1], v[N_DOFS+1], t[N_DOFS+1];
  static double  map[N_DOFS+1], mav[N_DOFS+1], mat[N_DOFS+1];
  static double  mip[N_DOFS+1], miv[N_DOFS+1], mit[N_DOFS+1];
  static double  vp[N_DOFS+1],vv[N_DOFS+1],vt[N_DOFS+1];
  static double  count=0;
  static int     count_errors=0;
  double gamma = 0.999;
  double aux;
  double thres=10.0;
  int    flag;
  extern double motor_servo_time;
#ifndef VX
  static FILE *fd=NULL;

  if (fd == NULL)
    fd = fopen("comm_errors.txt","w");

#endif

  // position statistics
  for (i=1; i<=N_DOFS; ++i) {
    if (count > .5/(1.-gamma)) {  // only if there is enough data

      if (joint_state[i].th > map[i])
	map[i] = joint_state[i].th;
      if (joint_state[i].th < mip[i])
	mip[i] = joint_state[i].th;

      aux = fabs(p[i] - joint_state[i].th);
      if ( aux > thres*sqrt(vp[i]) && aux > 0.1) {
	++count_errors;
	printf("%f-%d: p communication errors=%d (%f %f)\n",motor_servo_time,i,count_errors,
	       p[i],joint_state[i].th);
#ifndef VX
	fprintf(fd,"%f-%d: p communication errors=%d (%f %f)\n",motor_servo_time,i,
		count_errors,p[i],joint_state[i].th);
	fflush(fd);
#endif
	continue;
      }
    }
    if (count == 0) {
      p[i]  = joint_state[i].th;
      vp[i] = 0;
      map[i] = -1e10;
      mip[i] =  1e10;
    } else {
      p[i] = ((double)(joint_state[i].th+gamma*p[i]*((double)count)))/
	((double)count*gamma+1);
      vp[i] = ((double)(sqr(joint_state[i].th-p[i])+gamma*vp[i]*((double)count)))/
	((double)count*gamma+1.);
    }
  }

  for (i=1; i<=N_DOFS; ++i) {
    if (count > .5/(1.-gamma)) {

      if (joint_state[i].thd > mav[i])
	mav[i] = joint_state[i].thd;
      if (joint_state[i].thd < miv[i])
	miv[i] = joint_state[i].thd;

      aux = fabs(v[i] - joint_state[i].thd);
      if ( aux > thres*sqrt(vv[i]) && aux > 1) {
	++count_errors;
#ifndef VX
	printf("%f-%d: v communication errors=%d (%f %f)\n",motor_servo_time,i,count_errors,
	       v[i],joint_state[i].thd);
	fprintf(fd,"%f-%d: v communication errors=%d (%f %f)\n",motor_servo_time,i,
		count_errors,v[i],joint_state[i].thd);
	fflush(fd);
#endif
	continue;
      }
    }
    if (count == 0) {
      v[i] = joint_state[i].thd;
      vv[i] = 0;
      mav[i] = -1e10;
      miv[i] =  1e10;
    } else {
      v[i] = ((double)(joint_state[i].thd+gamma*v[i]*((double)count)))/
	((double)count*gamma+1);
      vv[i] = ((double)(sqr(joint_state[i].thd-v[i])+gamma*vv[i]*((double)count)))/
	((double)count*gamma+1.);
    }
  }

  if (motor_servo_calls%1000==0)
    flag = 1;
  else
    flag = 0;

  for (i=1; i<=N_DOFS; ++i) {
    if (count > 0.5/(1.-gamma)) {

      if (joint_state[i].load > mat[i])
	mat[i] = joint_state[i].load;
      if (joint_state[i].load < mit[i])
	mit[i] = joint_state[i].load;


      aux = fabs(t[i] - joint_state[i].load);
      if ( aux > thres*sqrt(vt[i]) && aux > 5) {
	++count_errors;
	printf("%f-%d: t communication errors=%d (%f %f)\n",motor_servo_time,i,count_errors,
	       t[i],joint_state[i].load);
#ifndef VX
	fprintf(fd,"%f-%d: t communication errors=%d (%f %f)\n",motor_servo_time,i,
		count_errors,t[i],joint_state[i].load);
	fflush(fd);
#endif
	continue;
      }
    }
    if (count == 0) {
      t[i] = joint_state[i].load;
      vt[i] = 0;
      mat[i] = -1e10;
      mit[i] =  1e10;
    } else {
      t[i] = ((double)(joint_state[i].load+gamma*t[i]*((double)count)))/
	((double)count*gamma+1);
      vt[i] = ((double)(sqr(joint_state[i].load-t[i])+gamma*vt[i]*((double)count)))/
	((double)count*gamma+1.);
    }
    
    if (flag) {
      printf("%ld.%2d: %5.2f (%5.3f/%5.3f)  %5.2f (%5.3f/%5.3f)  %5.2f (%5.3f/%5.3f)\n",
	     motor_servo_calls,i,
	     p[i],sqrt(vp[i]),map[i]-mip[i],
	     v[i],sqrt(vv[i]),mav[i]-miv[i],
	     t[i],sqrt(vt[i]),mat[i]-mit[i]);
      if (i ==N_DOFS)
	printf("errors=%d (%7.3f%%)\n",count_errors,100.*((double)count_errors)/((double)motor_servo_calls));
    }
  }
  count = count*gamma+1;
  
}

/*!*****************************************************************************
 *******************************************************************************
\note  changeAjcRegister
\date  Sept 2011
\remarks 

 A simple interactive program to change selected AJC registers

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 none

 ******************************************************************************/
static void
changeAjcRegister(void) 
{
  static int   jID=R_SFE;
  static int   rID=registerPositionCrossGain;
  int    iaux;
  char   string[100];
  int    i,j;
  extern void change_register(int,int);

  // get the joint to work on
  while (TRUE) {
    if (!get_int("Which joint should be modified?",jID,&iaux))
      return;
    if (iaux < 1 || iaux > N_DOFS) 
      printf("Invalid joint ID\n");
    else if ( !joints[iaux].active ) 
      printf("Joint %d is not active\n",iaux);
    else {
      jID = iaux;
      break;
    }
  }

  // choose a register to modify
  while (TRUE) {
    printf("\n\n\nPossible Registers are:\n\n");
    for (i=0; i<RegisterCount/2; ++i) {
      printf("%22s [%4d] ---> %d  ",ajcRegisterNames[i],joints[jID].registers[i+1],i);
      printf("%22s [%4d] ---> %d\n",ajcRegisterNames[i+RegisterCount/2],
	     joints[jID].registers[i+RegisterCount/2+1],i+RegisterCount/2);
    }
    printf("                                                             Quit   ---> q\n");
    if (!get_int("        ----> Input",rID,&iaux)) 
      break;
  
    if (iaux >= RegisterCount || iaux < 0) {
      printf("Invalid register ID\n");
    } else {
      rID = iaux;
      // call the interactive function for changing the register
      change_register(jID,rID);
    }
  }
   
  // print the current register settings
  printf("\n\nCurrent AjcRegister.cf entries:\n\n");

  for (i=1; i<=N_DOFS; ++i) {
    printf("%5s  ",joint_names[i]);
    for (j=1; j<=RegisterCount; ++j)
      printf("%d ",joints[i].registers[j]);
    printf("\n");
  }

}

/*!*****************************************************************************
 *******************************************************************************
\note  read_sensor_offs
\date  Oct 2011
   
\remarks 

interface to read sensor offsets configuration file

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 none

 ******************************************************************************/
static void
read_sensor_offs(void)
{
  read_sensor_offsets(config_files[SENSOROFFSETS]);
}

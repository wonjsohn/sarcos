/*!=============================================================================
  ==============================================================================

  \file    SL_user_sensor_proc_vx.c

  \author 
  \date   

  ==============================================================================
  \remarks

      performs reading of sensors, translation to units, and sending out
      motor commands. Additionally, power_status and power_kill are 
      implemented.

  ============================================================================*/

/* vxWorks includes */

#include "stdio.h"
#include "math.h"
#include "string.h"
#include "SL_vx_headers.h"

/* private includes */
#include "utility.h"
#include "SL.h"
#include "SL_user.h"
#include "SL_sensor_proc.h"
#include "DextArm/Ajc.h"

/* local variables */
static AjcJoint          joint_list[N_DOFS+1];
static AtTranslation     joint_trans_positions[N_DOFS+1];
static AtTranslation     joint_trans_velocities[N_DOFS+1];
static AtTranslation     joint_trans_torques[N_DOFS+1];
static AtTranslation     joint_trans_desired_torques[N_DOFS+1];
static AjcValue          raw_positions[N_DOFS+1];
static AjcValue          raw_velocities[N_DOFS+1];
static AjcValue          raw_torques[N_DOFS+1];
static AjcValue          raw_desired_torques[N_DOFS+1];

/* global functions */
int read_one_sensor(int i);

/* local functions */
static int    init_translation(void);
static void   translate_sensor_readings(SL_Jstate *joint_raw_state);
static void   translate_commands(SL_Jstate *commands);

/*!*****************************************************************************
 *******************************************************************************
\note  init_user_sensor_processing
\date  Dec 1997
   
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
  extern int read_register_file(char *fname_in);

  /* initialize the registers */
  read_register_file("default");

  /* initalizes translation to and from units */
  if (!init_translation())
    return FALSE;

  return TRUE;
  
}

/*!*****************************************************************************
 *******************************************************************************
\note  init_translation
\date  Dec 1997
   
\remarks 

          the translation of raw numbers to and from units

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

     none

 ******************************************************************************/
static int
init_translation(void)

{
  
  int       i,j;
  Error     error;
  FILE      *in;
  int       error_flag = FALSE;
  char      string[100];

  /* first get the joint info from sarcos programs */

  joint_list[R_SFE] = At_JointCompose(MasterRightArm,JointShoulderFlexExt);
  joint_list[R_SAA] = At_JointCompose(MasterRightArm,JointShoulderAbdAdd);
  joint_list[R_HR]  = At_JointCompose(MasterRightArm,JointHumeralRotation);
  joint_list[R_EB]  = At_JointCompose(MasterRightArm,JointElbowFlexExt);
  joint_list[R_WR]  = At_JointCompose(MasterRightArm,JointWristRotation);
  joint_list[R_WFE] = At_JointCompose(MasterRightArm,JointWristFlexExt);
  joint_list[R_WAA] = At_JointCompose(MasterRightArm,JointWristAbdAdd);

  joint_list[R_TL]  = At_JointCompose(MasterRightArm,JointThumbLateral);
  joint_list[R_TV]  = At_JointCompose(MasterRightArm,JointThumbVertical);
  joint_list[R_FAA] = At_JointCompose(MasterRightArm,JointFingerAbdAdd);

  /* second get the translation info for each joint */

  for (i=1; i<=N_DOFS; ++i) {

    error=At_GetTranslation(joint_list[i],
			    channelActPosStage1,
			    &(joint_trans_positions[i]));

    if (error) {
      printf("Error in position translation for joint %d\n",i);
      error_flag = TRUE;
    }
    
    
    error=At_GetTranslation(joint_list[i],
			    channelActVelocity,
			    &(joint_trans_velocities[i]));
    if (error) {
      printf("Error in velocity translation for joint %d\n",i);
      error_flag = TRUE;
    }
    
    error = At_GetTranslation(joint_list[i],
			      channelActTorque,
			      &(joint_trans_torques[i]));
    if (error) {
      printf("Error in torque translation for joint %d\n",i);
      error_flag = TRUE;
    }
    
    At_GetTranslation(joint_list[i],
		      registerDesiredTorqueCommand,
		      &(joint_trans_desired_torques[i]));
    if (error) {
      printf("Error in desired torque translation for joint %d\n",i);
      error_flag = TRUE;
    }
    
  }

  if (error_flag)
    return FALSE;
  
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


  for (i=1; i<=N_DOFS; ++i) {

    /* translate the position sensors */

    joint_raw_state[i].th = (joint_trans_positions[i].offset + 
			     raw_positions[i]) * 
      joint_trans_positions[i].slope;

    if (joint_lin_rot[i][SENSOR] == LINEAR) { 
      
      temp = (sqr(joint_raw_state[i].th)-sqr(joint_lin_rot[i][MOMENTARM]) - 
	      sqr(joint_lin_rot[i][MOUNTPOINT])) / 
	(2.*joint_lin_rot[i][MOMENTARM]*joint_lin_rot[i][MOUNTPOINT]);

      joint_raw_state[i].th = acos(temp);

    }

    /* translate the velocity sensors */

    joint_raw_state[i].thd = (joint_trans_velocities[i].offset + 
			      raw_velocities[i]) * 
      joint_trans_velocities[i].slope;

    if (joint_lin_rot[i][SENSOR] == LINEAR) { 
      
      joint_raw_state[i].thd  = joint_raw_state[i].thd / 
	(sqrt(1.-sqr(temp))*joint_lin_rot[i][MOMENTARM]*
	 joint_lin_rot[i][MOUNTPOINT]);

    }

    /* translate the force sensors */

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
\note  read_user_sensors
\date  Dec 1997
   
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
  Error error;

  /* read the positions */
  error = Ajc_ReadChannelFast(N_DOFS,
			      &(joint_list[1]),channelActPosStage1, 
			      False, 0, &(raw_positions[1]) );

  if ( error ) {
    return FALSE;
  }

  /* read the velocities */
  error = Ajc_ReadChannelFast(N_DOFS, 
				&(joint_list[1]),channelActVelocity, 
				False, 0, &(raw_velocities[1]) );
    
  if ( error ) {
    return FALSE;
  }

  /* read the torques */
  error = Ajc_ReadChannelFast( N_DOFS, 
			      &(joint_list[1]), channelActTorque, 
			       False, 0, &(raw_torques[1]) );

  if ( error ) {
    return FALSE;
  }


  /* translate the raw values into units */
  translate_sensor_readings(raw);

  return TRUE;

}

/*!*****************************************************************************
 *******************************************************************************
\note  send_user_commands
\date  April 1999
   
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
  Error error;

  /* translate into raw values */
  translate_commands(command);

  /* read the positions */
  error = Ajc_WriteRegisterFast (N_DOFS, 
				 PriorityHigh,
				 &(joint_list[1]), 
				 registerDesiredTorqueCommand, 
				 &(raw_desired_torques [1]));
  
  if ( error ) {
    return FALSE;
  }

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
\note  read_one_sensor
\date  Dec 1997
   
\remarks 

    reads one sensor and displays the values in raw
    This is for debugging only

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

     none

 ******************************************************************************/
int
read_one_sensor(int i)

{

  int j;
  Error error;
  double raw;
  double temp;

  if (i> N_DOFS || i < 1)
    return FALSE;

  /* read the positions */
  error = Ajc_ReadChannelFast(1,
			      &(joint_list[i]),channelActPosStage1, 
			      False, 0, &(raw_positions[i]) );

  if ( error ) {
    return FALSE;
  }

  /* read the velocities */
  error = Ajc_ReadChannelFast(1, 
				&(joint_list[i]),channelActVelocity, 
				False, 0, &(raw_velocities[i]) );
    
  if ( error ) {
    return FALSE;
  }

  /* read the torques */
  error = Ajc_ReadChannelFast( 1, 
			      &(joint_list[i]), channelActTorque, 
			       False, 0, &(raw_torques[i]) );

  if ( error ) {
    return FALSE;
  }

  /* show the raw values */

  printf("%s: pos=%d  vel=%d   load=%d\n",joint_names[i],raw_positions[i],
	 raw_velocities[i],raw_torques[i]);

  /* translate the position sensors */

  raw = (joint_trans_positions[i].offset + raw_positions[i]) * 
    joint_trans_positions[i].slope;

  if (joint_lin_rot[i][SENSOR] == LINEAR) { 
      
    temp = (sqr(raw)-sqr(joint_lin_rot[i][MOMENTARM]) - 
	    sqr(joint_lin_rot[i][MOUNTPOINT])) / 
      (2.*joint_lin_rot[i][MOMENTARM]*joint_lin_rot[i][MOUNTPOINT]);

    raw = acos(temp);

  }

  if (joint_lin_rot[i][ACTUATOR] == LINEAR) { 

    /* also print the offset if this were the 90-degree moment arm
       position */

    if (joint_lin_rot[i][SENSOR] == LINEAR) { 

      printf("Offset (90-degree) = %f (%f)   Angle for Moment Arm = %f\n",
	     -sqrt(cos(joint_lin_rot[i][THETA0])*
		  (2.*joint_lin_rot[i][MOMENTARM]*joint_lin_rot[i][MOUNTPOINT]) +
		  sqr(joint_lin_rot[i][MOUNTPOINT]) + sqr(joint_lin_rot[i][MOMENTARM]))
	     /joint_trans_positions[i].slope -  raw_positions[i],
	     sqrt(cos(joint_lin_rot[i][THETA0])*
		  (2.*joint_lin_rot[i][MOMENTARM]*joint_lin_rot[i][MOUNTPOINT]) +
		  sqr(joint_lin_rot[i][MOUNTPOINT]) + sqr(joint_lin_rot[i][MOMENTARM]))
	     /joint_trans_positions[i].slope -  raw_positions[i],
	     raw - joint_lin_rot[i][THETA0]);

    } else {
      /* off = arccos(a/h)/g - raw */
      
      printf("Offset (90-degree) = %f   Angle for Moment Arm = %f\n",
	     joint_lin_rot[i][THETA0]/joint_trans_positions[i].slope
	     - raw_positions[i],
	     raw - joint_lin_rot[i][THETA0]);
    }
  }


  return TRUE;

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

/*============================================================================
==============================================================================
                      
                              initUserTasks.c
 
==============================================================================
Remarks:

         Functions needed to initialize and link user tasks for the
         simulation

============================================================================*/
// system heaaders
#include "SL_system_headers.h"


#include "SL.h"
#include "SL_user.h"
#include "SL_man.h"
#include "SL_task_servo.h"

/* global variables */

/* local variables */
static int user_tasks_initialized = FALSE;


/*****************************************************************************
******************************************************************************
Function Name	: initUserTasks
Date		: June 1999
   
Remarks:

      initialize tasks that are not permanently linked in the simulation
      This replaces the <ltask facility in vxworks -- just that we cannot
      do on-line linking in C.

******************************************************************************
Paramters:  (i/o = input/output)

  none   

*****************************************************************************/
void
initUserTasks(void)

{

  extern void add_vision_calibration_task();
  extern void add_honey_sphere_task();
  extern void add_sample_task();
  extern void add_fpga_task();
     

  add_vision_calibration_task();
  add_honey_sphere_task();
  add_sample_task();
  add_fpga_task();
  

  // make the robot to the default posture
  if (!real_robot_flag)
    sprintf(initial_user_command,"go0");


}

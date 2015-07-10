/*!=============================================================================
  ==============================================================================

  \file    SL_user_rmotor.c

  \author  Stefan Schaal
  \date    Nov. 2009

  ==============================================================================
  \remarks
  
  Allows user specific motor servo initializations, customized for the real
  robot
  
  ============================================================================*/
  
// SL general includes of system headers
#include "SL_system_headers.h"

/* user specific headers */
#include "SL.h"
#include "SL_motor_servo.h"
#include "analogy/analogy.h"
#include "ni6259_interface.h"
#include "ajc.h"

/* global variables */

/* local variables */
  
/* local functions */

/* external functions */


/*!*****************************************************************************
 *******************************************************************************
 \note  init_user_motor
 \date  July 1998
 
 \remarks 
 
 initializes user specific motor functionality
 
 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 none 

 ******************************************************************************/
int
init_user_motor(void)

{
  
  int i,j,n;

  // intialize the NI6259 DAQ
  if (!init_NI6259(FALSE))
    exit(-1);

  // initialize the AJC boards
  Ajc_Initialize();


  return TRUE;
}



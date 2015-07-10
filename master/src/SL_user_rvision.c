/*!=============================================================================
  ==============================================================================

  \file    SL_user_vision.c

  \author  Stefan Schaal
  \date    Nov. 2009

  ==============================================================================
  \remarks
  
  Allows user specific vision servo initializations
  
  ============================================================================*/
  
// SL general includes of system headers
#include "SL_system_headers.h"

/* user specific headers */
#include "SL.h"
#include "SL_vision_servo.h"
#include "analogy/analogy.h"
#include "ni6259_interface.h"

/* global variables */

/* local variables */
  
/* local functions */

/* external functions */


/*!*****************************************************************************
 *******************************************************************************
 \note  init_user_vision
 \date  July 1998
 
 \remarks 
 
 initializes user specific vision functionality
 
 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 none 

 ******************************************************************************/
int
init_user_vision(void)

{
  
  int i,j,n;

  // initialize NI6259 DAQ
  if (!init_NI6259(TRUE))
    exit(-1);

  return TRUE;
}



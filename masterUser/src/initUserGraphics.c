/*============================================================================
==============================================================================
                      
                              initUserGraphics.c
 
==============================================================================
Remarks:

         Functions needed for user graphics
         simulation

============================================================================*/

// system headers
#include "SL_system_headers.h"

#include "SL.h"
#include "SL_user.h"
#include "SL_man.h"

// openGL includes
#ifdef powerpc
#include <GLUT/glut.h>
#else
#include "GL/glut.h"
#endif
#include "SL_openGL.h"
#include "SL_userGraphics.h"

// global variables

// local variables
static  struct {
  float    pos[N_CART+1];
  float    scale[N_CART+1];
} cube;

// local functions
static void displayCube(void *b);


/*****************************************************************************
******************************************************************************
Function Name	: initUserGraphics
Date		: June 1999
   
Remarks:

      allows adding new graphics functions to openGL interface

******************************************************************************
Paramters:  (i/o = input/output)

  none   

*****************************************************************************/
int
initUserGraphics(void)

{

  switchCometDisplay(TRUE,5000);
  addToUserGraphics("cube","Display a translucent cube",displayCube,sizeof(cube));

  return TRUE;

}

/*!*****************************************************************************
 *******************************************************************************
 \note  displayCube
 \date  Nov. 2007 
 
 \remarks 

        a simple cube in 3D

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[in]      b      : the general array of bytes

 ******************************************************************************/
static void
displayCube(void *b)
{
  GLfloat  col[4]={(float)0.5,(float)0.5,(float)0.5,(float)1.0};

  // assign the cube position from b array
  memcpy(&cube,b,sizeof(cube));

  /* here is the drawing rountines */
  glPushMatrix();
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE);
  
  glTranslated((GLdouble)cube.pos[_X_],
	       (GLdouble)cube.pos[_Y_],
	       (GLdouble)cube.pos[_Z_]);
  glColor4fv(col);
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, col);

  glScaled((double)cube.scale[_X_]*2.,(double)cube.scale[_X_]*2.,(double)cube.scale[_X_]*2);
  
  glutSolidCube(1.0);
  
  glDisable(GL_BLEND);
  glPopMatrix();

}


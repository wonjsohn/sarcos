/*!=============================================================================
  ==============================================================================

  \file    SL_user_openGL.c

  \author  Stefan Schaal
  \date    Nov. 2007

  ==============================================================================
  \remarks
  
  This program contains all graphics user functions for a particular simulation.
  
  ============================================================================*/
  
// SL general includes of system headers
#include "SL_system_headers.h"

// openGL headers
#ifdef powerpc
#include <GLUT/glut.h>
#else
#include "GL/freeglut_std.h"
#include "GL/freeglut_ext.h"
#include "GL/glu.h"
#endif
#include <X11/Xlib.h>

// user specific headers
#include "utility.h"
#include "SL.h"
#include "SL_openGL.h"
#include "SL_user.h"
#include "SL_common.h"
#include "SL_unix_common.h"
#include "SL_objects.h"
#include "SL_openGL_servo.h"
#include "SL_collect_data.h"
#include "mdefs.h"
#include "SL_kinematics.h"
#include "SL_shared_memory.h"
#include "SL_userGraphics.h"

// global variables 
int print_Hmat = FALSE;

// local variables
  
// local functions
static int createWindows(void);
static void myDrawGLElement(int num, double length, int flag);

// global functions
void display(void);
void idle(void);

// external functions


/*!*****************************************************************************
 *******************************************************************************
 \note  init_user_openGL
 \date  July 1998
 
 \remarks 
 
 initializes everything needed for the graphics for this simulation
 
 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[in]     argc : number of elements in argv
 \param[in]     argv : array of argc character strings
 

 ******************************************************************************/
int
init_user_openGL(int argc, char** argv)

{
  
  int i,j,n;
  int rc;
  int ans;

  // we need the kinematics initialized
  init_kinematics();

  // read objects
  readObjects(config_files[OBJECTS]);

  // assign contact force mappings
#include "LEKin_contact.h"

  // create simulation windows
  if (!createWindows())
    return FALSE;

  return TRUE;
}

/*!*****************************************************************************
 *******************************************************************************
 \note  createWindows
 \date  July 1998
 
 \remarks 
 
 initializes graphic windows
 
 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 none
 

 ******************************************************************************/
static int
createWindows(void)

{

  int i;
  int width=400, height=400;
  OpenGLWPtr w;

  Display *disp;
  int  screen_num;
  int  display_width;
  int  display_height;

  char string[100];
  char xstring[100];

  double eye[N_CART+1];
  
  // connect to X server using the DISPLAY environment variable
  if ( (disp=XOpenDisplay(NULL)) == NULL ) {
    printf("Cannot connect to X servo %s\n",XDisplayName(NULL));
    exit(-1);
  }
  
  // get screen size from display structure macro 
  screen_num = DefaultScreen(disp);
  display_width = DisplayWidth(disp, screen_num);
  display_height = DisplayHeight(disp, screen_num);
  
  
  /* get a window structure, initialized with default values */
  w=getOpenGLWindow();
  if (w==NULL)
    return FALSE;
  
  for (i=1; i<=N_CART; ++i)
    w->eye[i] /= 1.3;

  w->display = display;
  w->idle    = idle;
  w->width   = width;
  w->height  = height;

  // check for user parameters
  if (read_parameter_pool_string(config_files[PARAMETERPOOL], 
				 "main_window_geometry", string))
    parseWindowSpecs(string, display_width,display_height,xstring, 
		     &(w->x), 
		     &(w->y), 
		     &(w->width),
		     &(w->height));

  if (read_parameter_pool_double_array(config_files[PARAMETERPOOL], 
				       "main_window_camera_pos", N_CART, eye))
    for (i=1; i<=N_CART; ++i)
      w->eye[i] = eye[i];
  
  // finally create the window
  for (i=1; i<=N_CART; ++i)
    w->eye0[i] = w->eye[i];

  if (!createWindow(w))
    return FALSE;

  return TRUE;

}

/*!*****************************************************************************
 *******************************************************************************
\note  display
\date  August 7, 1992
   
\remarks 

        this function updates the OpenGL graphics

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output


 ******************************************************************************/
void 
display(void)

{
  int i;
  static SL_Jstate  *state = joint_sim_state;
  static SL_endeff  *eff   = endeff;
  static SL_Cstate  *basec = &base_state;
  static SL_quat    *baseo = &base_orient;
  GLfloat  objscolor[4]={(float)0.,(float)0.,(float)0.,(float)0.0};
  static double fscale = 0.01;
  static int    firsttime = TRUE;

  if (firsttime) {
    firsttime = FALSE;
    double w;
    if (read_parameter_pool_double(config_files[PARAMETERPOOL],"contact_force_scale",&w))
      fscale = w;
  }

#include "OpenGL.h"

  // the standard display functions for openGL
#include "SL_user_display_core.h"

}

/*!*****************************************************************************
 *******************************************************************************
\note  myDrawGLElement
\date  August 7, 1992
   
\remarks 

        draws a GL element of a particular length in z direction

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[in]     num   : ID number of element (just for info)
 \param[in]     length: length of element
 \param[in]     flag  : draw joint element (yes, not)


 ******************************************************************************/
static void  
myDrawGLElement(int num, double length, int flag)

{
		
  double width=0.03;
  double thumb_width = 0.02;
  double finger_width = 0.02;
  double hand_width = 0.07;
  GLfloat  gray[4]={(float)0.8,(float)0.8,(float)0.8,(float)1.0};
  GLfloat  green[4]={(float)0.1,(float)0.5,(float)0.5,(float)1.0};
  GLfloat  red[4]={(float)1.0,(float)0.25,(float)0.25,(float)1.0};
  GLfloat  blue[4]={(float)0.1,(float)0.1,(float)1.0,(float)1.0};
  GLfloat  black[4]={(float)0.,(float)0.,(float)0.0,(float)1.0};
  GLfloat  white[4]={(float)1.,(float)1.,(float)1.0,(float)1.0};
  GLfloat  yellow[4]={(float)1.0,(float)0.8,(float)0.7,(float)1.0};
  int      isphere = 10;
	
  if (flag==1) {
    glTranslated(0.0,0.0,length); 

    if (num==999) {/* the base coordinate system */
      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);
      glColor4fv(blue);
    } else if (num == 8 || num == 9 || num ==10) {
      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
      glColor4fv(white);
    } else {
      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, green);
      glColor4fv(green);
    }

    if (num == 8 || num == 9 || num == 10) {
      if (solid)
	glutSolidSphere(0.5*width,isphere,isphere);
      else
	glutWireSphere(0.5*width,isphere,isphere);
    } else {
      if (solid)
	glutSolidSphere(1.2*width,isphere,isphere);
      else
	glutWireSphere(1.2*width,isphere,isphere);
    }
    glTranslated(0.0,0.0,-length);
  }
	

  switch (num) {

  case 108: /* the hand */
	
    glScaled(hand_width,hand_width/3.,length);
    glTranslated(0.0,0.0,0.5);
    glColor4fv(yellow);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, yellow);
    if (solid)
      glutSolidSphere(0.5,isphere,isphere);
    else
      glutWireSphere(0.5,isphere,isphere);
    break;
	
  case 109: /* the thumb */
	
    glScaled(thumb_width,thumb_width,length);
    glTranslated(0.0,0.0,0.5);
    glColor4fv(yellow);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, yellow);
    if (solid)
      glutSolidSphere(0.5,isphere,isphere);
    else
      glutWireSphere(0.5,isphere,isphere);
    break;
	
  case 110: /* the finger */
	
    glScaled(finger_width,finger_width,length);
    glTranslated(0.0,0.0,0.5);
    glColor4fv(yellow);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, yellow);
    if (solid)
      glutSolidSphere(0.5,isphere,isphere);
    else
      glutWireSphere(0.5,isphere,isphere);
    break;
	
  case 8: /* the finger */
	
    glScaled(thumb_width*1.5,thumb_width*1.5,length);
    glTranslated(0.0,0.0,0.5);
    glColor4fv(gray);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
    if (solid)
      glutSolidSphere(0.5,isphere,isphere);
    else
      glutWireSphere(0.5,isphere,isphere);
    break;
	
  case 9: /* the finger */
	
    glScaled(thumb_width*1.5,thumb_width*1.5,length);
    glTranslated(0.0,0.0,0.5);
    glColor4fv(gray);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
    if (solid)
      glutSolidSphere(0.5,isphere,isphere);
    else
      glutWireSphere(0.5,isphere,isphere);
    break;
	
  case 10: /* the finger */
	
    glScaled(thumb_width*1.5,thumb_width*1.5,length);
    glTranslated(0.0,0.0,0.5);
    glColor4fv(gray);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
    if (solid)
      glutSolidSphere(0.5,isphere,isphere);
    else
      glutWireSphere(0.5,isphere,isphere);
    break;
	
  default:
	
    glScaled(width,width,length);
    glColor4fv(gray);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
    if (solid)
      glutSolidCylinder(1.0,1.0,isphere,1);
    else
      glutWireCylinder(1.0,1.0,isphere,1);
			
  }
}

/*!*****************************************************************************
 *******************************************************************************
\note  idle
\date  June 1999
   
\remarks 

      The function called by openGL whenever processing time available.

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output


 ******************************************************************************/
void
idle(void)

{
  int i;
  struct timeval t;
  static double last_draw_time = 0.0;
  double current_time;

  //-------------------------------------------------------------------------
  // the main functions are the most handy in an include file

#include "SL_user_idle_core.h"

  //-------------------------------------------------------------------------
  // refresh display

  gettimeofday(&t,NULL);
  current_time = (double) t.tv_sec + ((double)t.tv_usec)/1.e6;

  if (current_time-last_draw_time >= 1./window_update_rate) {
    glutPostRedisplayAll();
    last_draw_time = current_time; 
  }

}


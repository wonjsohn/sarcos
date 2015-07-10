/*!=============================================================================
  ==============================================================================

  \file    SL_user.h

  \author  Stefan Schaal
  \date    Feb 1999

  ==============================================================================
  \remarks
  
  robot specific definitions
  
  ============================================================================*/
  
#ifndef _SL_user_
#define _SL_user_

/*! the robot name */
#define ROBOT_NAME "master"

/*! dimensions of the robot */
#define l0  0.4
#define l1  0.0381
#define l2  0.287
#define l3  0.0025
#define l4  0.2781
#define l5  0.0081
#define l6x 0.03
#define l6y 0.1
#define l6z 0.02
#define l7z -0.05

#define l8  0.10        /*!< thumb length  */
#define l9  0.05        /*!< finger length */
#define l10 0.15        /*!< hand length   */

/* links of the robot */

enum RobotLinks {
  SHOULDER = 1,
  SHOULDER_OFF,
  ELBOW,
  ELBOW_OFF,
  WRIST,
  WRIST_OFF,
  HAND,
  FINGER_JOINT,
  FINGER,
  THUMB_JOINT,
  THUMB
};

/* endeffector information */

#define RIGHT_HAND   1

/* vision variables */

#define CAMERA_1  1
#define CAMERA_2  2

#define BLOB1 1
#define BLOB2 2
#define BLOB3 3
#define BLOB4 4
#define BLOB5 5
#define BLOB6 6


/* define the DOFs of this robot */

enum RobotDOFs {
  BASE=0,

  R_SFE,
  R_SAA,
  R_HR,
  R_EB,
  R_WR,
  R_WFE,
  R_WAA,
  R_TL,
  R_TV,
  R_FAA
};

/*! number of degrees-of-freedom of robot */
#define N_DOFS  R_FAA

/*! N_DOFS + fake DOFS, needed for parameter estimation; 
   fake DOFS come from creating endeffector information */
#define N_DOFS_EST 13

/*! N_DOFS to be excluded from parameter estimation (e.g., eye joints);
   these DOFS must be the last DOFS in the arrays */
#define N_DOFS_EST_SKIP 3

/*! number of links of the robot */
#define N_LINKS THUMB

/*! number of miscellaneous sensors */
#define N_MISC_SENSORS 0

/*! number of endeffectors */
#define N_ENDEFFS RIGHT_HAND

/*! number of cameras used */
#define N_CAMERAS 2

/*! number of blobs that can be tracked by vision system */
#define MAX_BLOBS 6

/*! vision default post processing */
#define VISION_DEFAULT_PP "vision_default.pp"

/*! the servo rate used by the I/O with robot: this limits the
   servo rates of all other servos */
#define  SERVO_BASE_RATE 1080

/*! divisor to obtain task servo rate (task servo can run slower than
   base rate, but only in integer fractions */
#define  TASK_SERVO_RATIO   R1TO2

/* settings for D/A debugging information -- see SL_oscilloscope.c */
#define  D2A_CM 1     //<! motor servo
#define  D2A_CT 2     //<! task servo
#define  D2A_CV 3     //<! vision servo
#define  D2A_CR 4     //<! ros servo

#ifdef __cplusplus
extern "C" {
#endif

  /* function prototypes */

#ifdef __cplusplus
}
#endif


#endif  /* _SL_user_ */

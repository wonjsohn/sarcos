/*============================================================================
==============================================================================

                              jacobian_comp.c

==============================================================================
============================================================================*/

/* vxWorks includes blah */
#include "SL_system_headers.h"
#ifndef VX
#endif

/* private includes */
#include "SL.h"
#include "SL_user.h"
#include "utility.h"
#include "SL_tasks.h"
#include "SL_task_servo.h"
#include "SL_kinematics.h"
#include "SL_dynamics.h"
#include "SL_collect_data.h"
#include "rfwr.h"
#include "SL_shared_memory.h"

#include "jacobian_comp.h"


/*****************************************************************************
******************************************************************************
Function Name	: init_jacobian
Date		: April 2006
Author          : Michael Mistry, CLMC Lab, USC, Los Angeles, CA

Remarks:

   initializations required for cogInvKinVel()
   call this function in the init_xxxx_task() function

******************************************************************************
Paramters:  (i/o = input/output)

none

*****************************************************************************/
int 
init_jacobian(JacobianAcc* J, int m, int n) {
  if (m <= 0 || n <= 0) {
    printf("invalid matrix size in init_jacobian()\n");
    return FALSE;
  }
  if (m >= n) {
    printf("init_jacobian() warning: m is greater or equal to n, right-pseudo-inverse does not apply\n");   
  }

  J->m = m;
  J->n = n;
  J->J       = my_matrix(1,m,1,n);
  J->Jnew    = my_matrix(1,m,1,n);
  J->JW      = my_matrix(1,m,1,n);
  J->JT      = my_matrix(1,n,1,m);
  J->JJT     = my_matrix(1,m,1,m);
  J->JJT_inv = my_matrix(1,m,1,m);
  J->J_hash  = my_matrix(1,n,1,m);
  J->JhJ     = my_matrix(1,n,1,n);
  J->JhJT    = my_matrix(1,n,1,n);
  J->N       = my_matrix(1,n,1,n);
  J->NT      = my_matrix(1,n,1,n); 
  J->Jd      = my_matrix(1,m,1,n);
  J->Jdqd    = my_vector(1,m);

  return TRUE;  
}

int
compute_inv_and_null(JacobianAcc* J) {

  int i,j;
  
  // compute J_hash using right-pseudo-inverse
  if (!mat_trans(J->J, J->JT))  
    return FALSE;
  if (!mat_mult(J->J,J->JT, J->JJT))
    return FALSE;
  if (!my_inv_ludcmp(J->JJT,J->m,J->JJT_inv)) 
    return FALSE;
  if (!mat_mult(J->JT, J->JJT_inv, J->J_hash))
    return FALSE;  
  
  // compute null space projection matrix
  if (!mat_mult(J->J_hash, J->J, J->N))
    return FALSE;  

  for (i=1;i<=J->n;i++) {  
    for (j=1;j<=J->n;j++) {  
      if (i==j) {
	J->N[i][j] =  1.0 - J->N[i][j];
      }
      else {
	J->N[i][j] = -1.0 * J->N[i][j];
      }
    }
  }

  if (!mat_trans(J->N, J->NT))  
    return FALSE;

  return TRUE;
}

int
compute_inv_and_null_W(JacobianAcc* J, Matrix W) {

  int i,j;
  
  // compute J_hash using right-pseudo-inverse
  if (!mat_trans(J->J, J->JT))  
    return FALSE;
  if (!mat_mult(J->J,W, J->JW))
    return FALSE;
  if (!mat_mult(J->JW,J->JT, J->JJT))
    return FALSE;
  if (!my_inv_ludcmp(J->JJT,J->m,J->JJT_inv)) 
    return FALSE;
  if (!mat_mult(J->JT, J->JJT_inv, J->J_hash))
    return FALSE;  
  if (!mat_mult(W, J->J_hash, J->J_hash))
    return FALSE;  
  
  // compute task and null space projection matricies
  if (!mat_mult(J->J_hash, J->J, J->JhJ))
    return FALSE;  

  
  for (i=1;i<=J->n;i++) {  
    for (j=1;j<=J->n;j++) {  
      if (i==j) {
	J->N[i][j] =  1.0 - J->JhJ[i][j];
      }
      else {
	J->N[i][j] = -1.0 * J->JhJ[i][j];
      }
    }
  }
  
  if (!mat_trans(J->JhJ, J->JhJT))  
    return FALSE;
  if (!mat_trans(J->N, J->NT))  
    return FALSE;

  return TRUE;
}


int
compute_inv_and_null_damped(JacobianAcc* J, Matrix W, double damp) {

  int i,j;
  
  // compute J_hash using right-pseudo-inverse
  if (!mat_trans(J->J, J->JT))  
    return FALSE;
  if (!mat_mult(J->J,W, J->JW))
    return FALSE;
  if (!mat_mult(J->JW,J->JT, J->JJT))
    return FALSE;

  for (i=1;i<=J->m;i++) {
    J->JJT[i][i] += damp*damp;
  }

  if (!my_inv_ludcmp(J->JJT,J->m,J->JJT_inv)) 
    return FALSE;
  if (!mat_mult(J->JT, J->JJT_inv, J->J_hash))
    return FALSE;  
  if (!mat_mult(W, J->J_hash, J->J_hash))
    return FALSE;  
  
  // compute null space projection matrix
  if (!mat_mult(J->J_hash, J->J, J->N))
    return FALSE;  

  for (i=1;i<=J->n;i++) {  
    for (j=1;j<=J->n;j++) {  
      if (i==j) {
	J->N[i][j] =  1.0 - J->N[i][j];
      }
      else {
	J->N[i][j] = -1.0 * J->N[i][j];
      }
    }
  }

  if (!mat_trans(J->N, J->NT))  
    return FALSE;

  return TRUE;
}

int
compute_Jdqd(JacobianAcc* J, Vector qd, double dt, int reset) {
  // reset flag specifies whether or not to reinitialize the numerical derivative.  

  //overwrite flag specifies whether or not to replace J->J with newJ
  //  usually this is what we want
  //  but then inv_and_null must be computed after compute_Jd is called

  if (reset == TRUE) {
    mat_zero(J->Jd);
  }
  else {
    if (!mat_sub(J->Jnew,J->J,J->Jd)) 
      return FALSE;  
    if (!mat_mult_scalar(J->Jd,1.0/dt,J->Jd))
      return FALSE; 
  }

  if (!mat_equal(J->Jnew,J->J)) 
    return FALSE;
  
  if (!mat_vec_mult(J->Jd,qd,J->Jdqd))
    return FALSE;

  return TRUE;
}


int
compute_detJWJT(JacobianAcc* J, Matrix W, double *det) {

  int i,j;
  
  if (!mat_trans(J->J, J->JT))  
    return FALSE;
  if (!mat_mult(J->J,W, J->JW))
    return FALSE;
  if (!mat_mult(J->JW,J->JT, J->JJT))
    return FALSE;  
  if (!my_ludcmp_det(J->JJT,J->m,det)) 
    return FALSE;

  return TRUE;
}

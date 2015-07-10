#ifndef _JACOBIAN_COMP_
#define _JACOBIAN_COMP_

typedef struct JacobianAcc
{
  Matrix J;      // The Jacobian
  Matrix Jnew;   // Temporary Jacobian (used to compute Jd)
  Matrix JT;     // J Transpose
  Matrix JJT;    // J*J^T
  Matrix JJT_inv;// inv(J*JT) 
  Matrix J_hash; // pseudoinverse of J = W*JT*inv(J*W*JT)
  Matrix JhJ;    // J_hash*J (task space projection)
  Matrix JhJT;   // Transpose of J_hash*J (khatib task space projection)
  Matrix N;      // null space projection of J = I-J_hash*J 
  Matrix NT;     // N transpose (used for khatib null space projection)
  Matrix Jd;     // Numerical derivative of J
  Vector Jdqd;   // Jd*qd
  Matrix JW;     // J*W (used for weighted-psuedoinverses)
  int m;         // number of rows of J        
  int n;         // number of columns of J
} JacobianAcc;


int init_jacobian(JacobianAcc* J, int m, int n);
int compute_inv_and_null(JacobianAcc* J);
int compute_inv_and_null_W(JacobianAcc* J, Matrix W);
int compute_inv_and_null_damped(JacobianAcc* J, Matrix W, double damp);
int compute_Jdqd(JacobianAcc* J, Vector qd, double dt, int reset);
int compute_detJWJT(JacobianAcc* J, Matrix W, double *det);
#endif /* _JACOBIAN_COMP_ */


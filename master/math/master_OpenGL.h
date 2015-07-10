/* this function generates simple OpenGL graphics code to draw each link */


glPushMatrix();
myDrawGLElement((int)999,(double)0.0,(int)1);
glPopMatrix();

/* JointID = 0 */

glPushMatrix();
glPushMatrix();
if (basec[0].x[1]==0 && basec[0].x[2]==0)
glRotated((GLdouble)90.*(-1. + basec[0].x[3]/Sqrt(Power(basec[0].x[1],2) + Power(basec[0].x[2],2) + Power(basec[0].x[3],2))),(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*basec[0].x[1],(GLdouble)0.5*basec[0].x[2],(GLdouble)0.5*(basec[0].x[3] + Sqrt(Power(basec[0].x[1],2) + Power(basec[0].x[2],2) + Power(basec[0].x[3],2))));
myDrawGLElement((int)0,(double)Sqrt(Power(basec[0].x[1],2) + Power(basec[0].x[2],2) + Power(basec[0].x[3],2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)basec[0].x[1],(GLdouble)basec[0].x[2],(GLdouble)basec[0].x[3]);
glRotated((GLdouble)114.59155902616465*ArcCos(baseo[0].q[1]),(GLdouble)baseo[0].q[2],(GLdouble)baseo[0].q[3],(GLdouble)baseo[0].q[4]);

/* JointID = 1 */

glPushMatrix();
glPushMatrix();
if (l0/Sqrt(2)==0 && 0==0)
glRotated((GLdouble)90.*(-1. + l0/(Sqrt(2)*Sqrt(Power(l0,2)))),(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.35355339059327373*l0,(GLdouble)0,(GLdouble)0.5*(l0/Sqrt(2) + Sqrt(Power(l0,2))));
myDrawGLElement((int)1,(double)Sqrt(Power(l0,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)l0/Sqrt(2),(GLdouble)0,(GLdouble)l0/Sqrt(2));
glRotated((GLdouble)45.,(GLdouble)0.,(GLdouble)1.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[1].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 2 */

glPushMatrix();
glPushMatrix();
myDrawGLElement((int)2,(double)0,(int)0);
glPopMatrix();
glRotated((GLdouble)-90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)45.,(GLdouble)0.,(GLdouble)0.,(GLdouble)1.);
glRotated((GLdouble)57.29577951308232*state[2].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 3 */

glPushMatrix();
glPushMatrix();
if (0==0 && -l1==0)
glRotated((GLdouble)-90.,(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0,(GLdouble)-0.5*l1,(GLdouble)0.5*Sqrt(Power(l1,2)));
myDrawGLElement((int)3,(double)Sqrt(Power(l1,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)0,(GLdouble)-l1,(GLdouble)0);
glRotated((GLdouble)90.,(GLdouble)0.,(GLdouble)1.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[3].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 4 */

glPushMatrix();
glPushMatrix();
if (0==0 && 0==0)
glRotated((GLdouble)90.*(-1. + l2/Sqrt(Power(l2,2))),(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0,(GLdouble)0,(GLdouble)0.5*(l2 + Sqrt(Power(l2,2))));
myDrawGLElement((int)4,(double)Sqrt(Power(l2,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)0,(GLdouble)0,(GLdouble)l2);
glRotated((GLdouble)90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)-90.,(GLdouble)0.,(GLdouble)0.,(GLdouble)1.);
glRotated((GLdouble)57.29577951308232*state[4].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 5 */

glPushMatrix();
glPushMatrix();
if (0==0 && 0==0)
glRotated((GLdouble)90.*(-1. - l3/Sqrt(Power(l3,2))),(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0,(GLdouble)0,(GLdouble)0.5*(-l3 + Sqrt(Power(l3,2))));
myDrawGLElement((int)5,(double)Sqrt(Power(l3,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)0,(GLdouble)0,(GLdouble)-l3);
glRotated((GLdouble)-90.,(GLdouble)0.,(GLdouble)1.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[5].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 6 */

glPushMatrix();
glPushMatrix();
if (0==0 && 0==0)
glRotated((GLdouble)90.*(-1. + l4/Sqrt(Power(l4,2))),(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0,(GLdouble)0,(GLdouble)0.5*(l4 + Sqrt(Power(l4,2))));
myDrawGLElement((int)6,(double)Sqrt(Power(l4,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)0,(GLdouble)0,(GLdouble)l4);
glRotated((GLdouble)-90.,(GLdouble)1.,(GLdouble)0.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[6].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 7 */

glPushMatrix();
glPushMatrix();
if (0==0 && 0==0)
glRotated((GLdouble)90.*(-1. + l5/Sqrt(Power(l5,2))),(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0,(GLdouble)0,(GLdouble)0.5*(l5 + Sqrt(Power(l5,2))));
myDrawGLElement((int)7,(double)Sqrt(Power(l5,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)0,(GLdouble)0,(GLdouble)l5);
glRotated((GLdouble)90.,(GLdouble)0.,(GLdouble)1.,(GLdouble)0.);
glRotated((GLdouble)180.,(GLdouble)0.,(GLdouble)0.,(GLdouble)1.);
glRotated((GLdouble)57.29577951308232*state[7].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 108 */

glPushMatrix();
glPushMatrix();
if (eff[1].x[1]==0 && eff[1].x[2]==0)
glRotated((GLdouble)90.*(-1. + eff[1].x[3]/Sqrt(Power(eff[1].x[1],2) + Power(eff[1].x[2],2) + Power(eff[1].x[3],2))),(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0.5*eff[1].x[1],(GLdouble)0.5*eff[1].x[2],(GLdouble)0.5*(eff[1].x[3] + Sqrt(Power(eff[1].x[1],2) + Power(eff[1].x[2],2) + Power(eff[1].x[3],2))));
myDrawGLElement((int)108,(double)Sqrt(Power(eff[1].x[1],2) + Power(eff[1].x[2],2) + Power(eff[1].x[3],2)),(int)0);
glPopMatrix();
glPopMatrix();

/* JointID = 8 */

glPushMatrix();
glPushMatrix();
if (-l6x==0 && 0==0)
glRotated((GLdouble)90.*(-1. + l7z/Sqrt(Power(l6x,2) + Power(l7z,2))),(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)-0.5*l6x,(GLdouble)0,(GLdouble)0.5*(l7z + Sqrt(Power(l6x,2) + Power(l7z,2))));
myDrawGLElement((int)8,(double)Sqrt(Power(l6x,2) + Power(l7z,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)-l6x,(GLdouble)0,(GLdouble)l7z);
glRotated((GLdouble)-90.,(GLdouble)0.,(GLdouble)1.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[8].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 9 */

glPushMatrix();
glPushMatrix();
myDrawGLElement((int)9,(double)0,(int)0);
glPopMatrix();
glRotated((GLdouble)90.,(GLdouble)0.,(GLdouble)1.,(GLdouble)0.);
glRotated((GLdouble)57.29577951308232*state[9].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 109 */

glPushMatrix();
glPushMatrix();
if (0==0 && l8==0)
glRotated((GLdouble)-90.,(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0,(GLdouble)0.5*l8,(GLdouble)0.5*Sqrt(Power(l8,2)));
myDrawGLElement((int)109,(double)Sqrt(Power(l8,2)),(int)0);
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();

/* JointID = 10 */

glPushMatrix();
glPushMatrix();
if (-l6x==0 && l6y==0)
glRotated((GLdouble)90.*(-1. + l6z/Sqrt(Power(l6x,2) + Power(l6y,2) + Power(l6z,2))),(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)-0.5*l6x,(GLdouble)0.5*l6y,(GLdouble)0.5*(l6z + Sqrt(Power(l6x,2) + Power(l6y,2) + Power(l6z,2))));
myDrawGLElement((int)10,(double)Sqrt(Power(l6x,2) + Power(l6y,2) + Power(l6z,2)),(int)1);
glPopMatrix();
glTranslated((GLdouble)-l6x,(GLdouble)l6y,(GLdouble)l6z);
glRotated((GLdouble)57.29577951308232*state[10].th,(GLdouble)0,(GLdouble)0,(GLdouble)1);

/* JointID = 110 */

glPushMatrix();
glPushMatrix();
if (0==0 && l9==0)
glRotated((GLdouble)-90.,(GLdouble)1.0,(GLdouble)0.0,(GLdouble)0.0);
else
glRotated((GLdouble)180.0,(GLdouble)0,(GLdouble)0.5*l9,(GLdouble)0.5*Sqrt(Power(l9,2)));
myDrawGLElement((int)110,(double)Sqrt(Power(l9,2)),(int)0);
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
/*glutSwapBuffers();*/


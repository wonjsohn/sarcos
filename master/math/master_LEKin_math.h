/* this function assumes that the array Xlink[nLinks+1][3+1]
 is passed as an argument. Only the real number of links are computed */

/* sine and cosine precomputation */
sstate1th=Sin(state[1].th);
cstate1th=Cos(state[1].th);

sstate2th=Sin(state[2].th);
cstate2th=Cos(state[2].th);

sstate3th=Sin(state[3].th);
cstate3th=Cos(state[3].th);

sstate4th=Sin(state[4].th);
cstate4th=Cos(state[4].th);

sstate5th=Sin(state[5].th);
cstate5th=Cos(state[5].th);

sstate6th=Sin(state[6].th);
cstate6th=Cos(state[6].th);

sstate7th=Sin(state[7].th);
cstate7th=Cos(state[7].th);

sstate8th=Sin(state[8].th);
cstate8th=Cos(state[8].th);

sstate9th=Sin(state[9].th);
cstate9th=Cos(state[9].th);

sstate10th=Sin(state[10].th);
cstate10th=Cos(state[10].th);


/* rotation matrix sine and cosine precomputation */







rseff1a1=Sin(eff[1].a[1]);
rceff1a1=Cos(eff[1].a[1]);

rseff1a2=Sin(eff[1].a[2]);
rceff1a2=Cos(eff[1].a[2]);

rseff1a3=Sin(eff[1].a[3]);
rceff1a3=Cos(eff[1].a[3]);








/* inverse rotation matrices */
Si00[1][1]=-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[2],2);
Si00[1][2]=2*(baseo[0].q[2]*baseo[0].q[3] - baseo[0].q[1]*baseo[0].q[4]);
Si00[1][3]=2*(baseo[0].q[1]*baseo[0].q[3] + baseo[0].q[2]*baseo[0].q[4]);

Si00[2][1]=2*(baseo[0].q[2]*baseo[0].q[3] + baseo[0].q[1]*baseo[0].q[4]);
Si00[2][2]=-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[3],2);
Si00[2][3]=2*(-(baseo[0].q[1]*baseo[0].q[2]) + baseo[0].q[3]*baseo[0].q[4]);

Si00[3][1]=2*(-(baseo[0].q[1]*baseo[0].q[3]) + baseo[0].q[2]*baseo[0].q[4]);
Si00[3][2]=2*(baseo[0].q[1]*baseo[0].q[2] + baseo[0].q[3]*baseo[0].q[4]);
Si00[3][3]=-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[4],2);


Si01[1][1]=0.7071067811865475*cstate1th;
Si01[1][2]=-0.7071067811865475*sstate1th;

Si01[2][1]=sstate1th;
Si01[2][2]=cstate1th;

Si01[3][1]=-0.7071067811865475*cstate1th;
Si01[3][2]=0.7071067811865475*sstate1th;


Si12[1][1]=0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th;
Si12[1][2]=-0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th;

Si12[3][1]=-0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th;
Si12[3][2]=-0.7071067811865475*cstate2th + 0.7071067811865475*sstate2th;


Si23[2][1]=sstate3th;
Si23[2][2]=cstate3th;

Si23[3][1]=-cstate3th;
Si23[3][2]=sstate3th;


Si34[1][1]=sstate4th;
Si34[1][2]=cstate4th;

Si34[3][1]=-cstate4th;
Si34[3][2]=sstate4th;


Si45[2][1]=sstate5th;
Si45[2][2]=cstate5th;

Si45[3][1]=cstate5th;
Si45[3][2]=-sstate5th;


Si56[1][1]=cstate6th;
Si56[1][2]=-sstate6th;

Si56[3][1]=-sstate6th;
Si56[3][2]=-cstate6th;


Si67[2][1]=-sstate7th;
Si67[2][2]=-cstate7th;

Si67[3][1]=cstate7th;
Si67[3][2]=-sstate7th;


Si78[1][1]=rceff1a2*rceff1a3;
Si78[1][2]=-(rceff1a2*rseff1a3);
Si78[1][3]=rseff1a2;

Si78[2][1]=rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3;
Si78[2][2]=rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3;
Si78[2][3]=-(rceff1a2*rseff1a1);

Si78[3][1]=-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3;
Si78[3][2]=rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3;
Si78[3][3]=rceff1a1*rceff1a2;


Si79[2][1]=sstate8th;
Si79[2][2]=cstate8th;

Si79[3][1]=cstate8th;
Si79[3][2]=-sstate8th;


Si910[2][1]=sstate9th;
Si910[2][2]=cstate9th;

Si910[3][1]=-cstate9th;
Si910[3][2]=sstate9th;



Si712[1][1]=cstate10th;
Si712[1][2]=-sstate10th;

Si712[2][1]=sstate10th;
Si712[2][2]=cstate10th;




/* calculation of link coordinates */
/* link: {basec$0$$x[[1]], basec$0$$x[[2]], basec$0$$x[[3]]} */
Xlink[0][1]=basec[0].x[1];
Xlink[0][2]=basec[0].x[2];
Xlink[0][3]=basec[0].x[3];

v[1]=basec[0].x[1] + (l0*Si00[1][1])/Sqrt(2) + (l0*Si00[1][3])/Sqrt(2);
v[2]=basec[0].x[2] + (l0*Si00[2][1])/Sqrt(2) + (l0*Si00[2][3])/Sqrt(2);
v[3]=basec[0].x[3] + (l0*Si00[3][1])/Sqrt(2) + (l0*Si00[3][3])/Sqrt(2);

/* link: {l0/Sqrt[2], 0, l0/Sqrt[2]} */
Xlink[1][1]=v[1];
Xlink[1][2]=v[2];
Xlink[1][3]=v[3];

v[1]=-(l1*Si12[1][2]);
v[3]=-(l1*Si12[3][2]);

vv[1]=l0/Sqrt(2) + 0.7071067811865475*v[3] + v[1]*Si01[1][1];
vv[2]=v[1]*Si01[2][1];
vv[3]=l0/Sqrt(2) + 0.7071067811865475*v[3] + v[1]*Si01[3][1];

v[1]=basec[0].x[1] + vv[1]*Si00[1][1] + vv[2]*Si00[1][2] + vv[3]*Si00[1][3];
v[2]=basec[0].x[2] + vv[1]*Si00[2][1] + vv[2]*Si00[2][2] + vv[3]*Si00[2][3];
v[3]=basec[0].x[3] + vv[1]*Si00[3][1] + vv[2]*Si00[3][2] + vv[3]*Si00[3][3];

/* link: {0, -l1, 0} */
Xlink[2][1]=v[1];
Xlink[2][2]=v[2];
Xlink[2][3]=v[3];

v[1]=l2;
v[2]=-l1;

vv[1]=v[1]*Si12[1][1] + v[2]*Si12[1][2];
vv[3]=v[1]*Si12[3][1] + v[2]*Si12[3][2];

v[1]=l0/Sqrt(2) + 0.7071067811865475*vv[3] + vv[1]*Si01[1][1];
v[2]=vv[1]*Si01[2][1];
v[3]=l0/Sqrt(2) + 0.7071067811865475*vv[3] + vv[1]*Si01[3][1];

vv[1]=basec[0].x[1] + v[1]*Si00[1][1] + v[2]*Si00[1][2] + v[3]*Si00[1][3];
vv[2]=basec[0].x[2] + v[1]*Si00[2][1] + v[2]*Si00[2][2] + v[3]*Si00[2][3];
vv[3]=basec[0].x[3] + v[1]*Si00[3][1] + v[2]*Si00[3][2] + v[3]*Si00[3][3];

/* link: {0, 0, l2} */
Xlink[3][1]=vv[1];
Xlink[3][2]=vv[2];
Xlink[3][3]=vv[3];

v[2]=l3;
v[3]=l2;

vv[1]=v[3];
vv[2]=-l1 + v[2]*Si23[2][2];
vv[3]=v[2]*Si23[3][2];

v[1]=vv[1]*Si12[1][1] + vv[2]*Si12[1][2];
v[2]=vv[3];
v[3]=vv[1]*Si12[3][1] + vv[2]*Si12[3][2];

vv[1]=l0/Sqrt(2) + 0.7071067811865475*v[3] + v[1]*Si01[1][1] + v[2]*Si01[1][2];
vv[2]=v[1]*Si01[2][1] + v[2]*Si01[2][2];
vv[3]=l0/Sqrt(2) + 0.7071067811865475*v[3] + v[1]*Si01[3][1] + v[2]*Si01[3][2];

v[1]=basec[0].x[1] + vv[1]*Si00[1][1] + vv[2]*Si00[1][2] + vv[3]*Si00[1][3];
v[2]=basec[0].x[2] + vv[1]*Si00[2][1] + vv[2]*Si00[2][2] + vv[3]*Si00[2][3];
v[3]=basec[0].x[3] + vv[1]*Si00[3][1] + vv[2]*Si00[3][2] + vv[3]*Si00[3][3];

/* link: {0, 0, -l3} */
Xlink[4][1]=v[1];
Xlink[4][2]=v[2];
Xlink[4][3]=v[3];

v[1]=-l4;
v[3]=-l3;

vv[1]=v[1]*Si34[1][1];
vv[2]=-v[3];
vv[3]=l2 + v[1]*Si34[3][1];

v[1]=vv[3];
v[2]=-l1 + vv[1]*Si23[2][1] + vv[2]*Si23[2][2];
v[3]=vv[1]*Si23[3][1] + vv[2]*Si23[3][2];

vv[1]=v[1]*Si12[1][1] + v[2]*Si12[1][2];
vv[2]=v[3];
vv[3]=v[1]*Si12[3][1] + v[2]*Si12[3][2];

v[1]=l0/Sqrt(2) + 0.7071067811865475*vv[3] + vv[1]*Si01[1][1] + vv[2]*Si01[1][2];
v[2]=vv[1]*Si01[2][1] + vv[2]*Si01[2][2];
v[3]=l0/Sqrt(2) + 0.7071067811865475*vv[3] + vv[1]*Si01[3][1] + vv[2]*Si01[3][2];

vv[1]=basec[0].x[1] + v[1]*Si00[1][1] + v[2]*Si00[1][2] + v[3]*Si00[1][3];
vv[2]=basec[0].x[2] + v[1]*Si00[2][1] + v[2]*Si00[2][2] + v[3]*Si00[2][3];
vv[3]=basec[0].x[3] + v[1]*Si00[3][1] + v[2]*Si00[3][2] + v[3]*Si00[3][3];

/* link: {0, 0, l4} */
Xlink[5][1]=vv[1];
Xlink[5][2]=vv[2];
Xlink[5][3]=vv[3];

v[2]=l5;
v[3]=l4;

vv[1]=-v[3];
vv[2]=v[2]*Si45[2][2];
vv[3]=-l3 + v[2]*Si45[3][2];

v[1]=vv[1]*Si34[1][1] + vv[2]*Si34[1][2];
v[2]=-vv[3];
v[3]=l2 + vv[1]*Si34[3][1] + vv[2]*Si34[3][2];

vv[1]=v[3];
vv[2]=-l1 + v[1]*Si23[2][1] + v[2]*Si23[2][2];
vv[3]=v[1]*Si23[3][1] + v[2]*Si23[3][2];

v[1]=vv[1]*Si12[1][1] + vv[2]*Si12[1][2];
v[2]=vv[3];
v[3]=vv[1]*Si12[3][1] + vv[2]*Si12[3][2];

vv[1]=l0/Sqrt(2) + 0.7071067811865475*v[3] + v[1]*Si01[1][1] + v[2]*Si01[1][2];
vv[2]=v[1]*Si01[2][1] + v[2]*Si01[2][2];
vv[3]=l0/Sqrt(2) + 0.7071067811865475*v[3] + v[1]*Si01[3][1] + v[2]*Si01[3][2];

v[1]=basec[0].x[1] + vv[1]*Si00[1][1] + vv[2]*Si00[1][2] + vv[3]*Si00[1][3];
v[2]=basec[0].x[2] + vv[1]*Si00[2][1] + vv[2]*Si00[2][2] + vv[3]*Si00[2][3];
v[3]=basec[0].x[3] + vv[1]*Si00[3][1] + vv[2]*Si00[3][2] + vv[3]*Si00[3][3];

/* link: {0, 0, l5} */
Xlink[6][1]=v[1];
Xlink[6][2]=v[2];
Xlink[6][3]=v[3];

v[1]=eff[1].x[3];
v[2]=eff[1].x[1]*Si67[2][1] + eff[1].x[2]*Si67[2][2];
v[3]=l5 + eff[1].x[1]*Si67[3][1] + eff[1].x[2]*Si67[3][2];

vv[1]=v[1]*Si56[1][1] + v[2]*Si56[1][2];
vv[2]=v[3];
vv[3]=l4 + v[1]*Si56[3][1] + v[2]*Si56[3][2];

v[1]=-vv[3];
v[2]=vv[1]*Si45[2][1] + vv[2]*Si45[2][2];
v[3]=-l3 + vv[1]*Si45[3][1] + vv[2]*Si45[3][2];

vv[1]=v[1]*Si34[1][1] + v[2]*Si34[1][2];
vv[2]=-v[3];
vv[3]=l2 + v[1]*Si34[3][1] + v[2]*Si34[3][2];

v[1]=vv[3];
v[2]=-l1 + vv[1]*Si23[2][1] + vv[2]*Si23[2][2];
v[3]=vv[1]*Si23[3][1] + vv[2]*Si23[3][2];

vv[1]=v[1]*Si12[1][1] + v[2]*Si12[1][2];
vv[2]=v[3];
vv[3]=v[1]*Si12[3][1] + v[2]*Si12[3][2];

v[1]=l0/Sqrt(2) + 0.7071067811865475*vv[3] + vv[1]*Si01[1][1] + vv[2]*Si01[1][2];
v[2]=vv[1]*Si01[2][1] + vv[2]*Si01[2][2];
v[3]=l0/Sqrt(2) + 0.7071067811865475*vv[3] + vv[1]*Si01[3][1] + vv[2]*Si01[3][2];

vv[1]=basec[0].x[1] + v[1]*Si00[1][1] + v[2]*Si00[1][2] + v[3]*Si00[1][3];
vv[2]=basec[0].x[2] + v[1]*Si00[2][1] + v[2]*Si00[2][2] + v[3]*Si00[2][3];
vv[3]=basec[0].x[3] + v[1]*Si00[3][1] + v[2]*Si00[3][2] + v[3]*Si00[3][3];

/* link: {eff$1$$x[[1]], eff$1$$x[[2]], eff$1$$x[[3]]} */
Xlink[7][1]=vv[1];
Xlink[7][2]=vv[2];
Xlink[7][3]=vv[3];

v[1]=l7z;
v[2]=-(l6x*Si67[2][1]);
v[3]=l5 - l6x*Si67[3][1];

vv[1]=v[1]*Si56[1][1] + v[2]*Si56[1][2];
vv[2]=v[3];
vv[3]=l4 + v[1]*Si56[3][1] + v[2]*Si56[3][2];

v[1]=-vv[3];
v[2]=vv[1]*Si45[2][1] + vv[2]*Si45[2][2];
v[3]=-l3 + vv[1]*Si45[3][1] + vv[2]*Si45[3][2];

vv[1]=v[1]*Si34[1][1] + v[2]*Si34[1][2];
vv[2]=-v[3];
vv[3]=l2 + v[1]*Si34[3][1] + v[2]*Si34[3][2];

v[1]=vv[3];
v[2]=-l1 + vv[1]*Si23[2][1] + vv[2]*Si23[2][2];
v[3]=vv[1]*Si23[3][1] + vv[2]*Si23[3][2];

vv[1]=v[1]*Si12[1][1] + v[2]*Si12[1][2];
vv[2]=v[3];
vv[3]=v[1]*Si12[3][1] + v[2]*Si12[3][2];

v[1]=l0/Sqrt(2) + 0.7071067811865475*vv[3] + vv[1]*Si01[1][1] + vv[2]*Si01[1][2];
v[2]=vv[1]*Si01[2][1] + vv[2]*Si01[2][2];
v[3]=l0/Sqrt(2) + 0.7071067811865475*vv[3] + vv[1]*Si01[3][1] + vv[2]*Si01[3][2];

vv[1]=basec[0].x[1] + v[1]*Si00[1][1] + v[2]*Si00[1][2] + v[3]*Si00[1][3];
vv[2]=basec[0].x[2] + v[1]*Si00[2][1] + v[2]*Si00[2][2] + v[3]*Si00[2][3];
vv[3]=basec[0].x[3] + v[1]*Si00[3][1] + v[2]*Si00[3][2] + v[3]*Si00[3][3];

/* link: {-l6x, 0, l7z} */
Xlink[8][1]=vv[1];
Xlink[8][2]=vv[2];
Xlink[8][3]=vv[3];

v[2]=l8*Si910[2][2];
v[3]=l8*Si910[3][2];

vv[1]=-l6x - v[3];
vv[2]=v[2]*Si79[2][2];
vv[3]=l7z + v[2]*Si79[3][2];

v[1]=vv[3];
v[2]=vv[1]*Si67[2][1] + vv[2]*Si67[2][2];
v[3]=l5 + vv[1]*Si67[3][1] + vv[2]*Si67[3][2];

vv[1]=v[1]*Si56[1][1] + v[2]*Si56[1][2];
vv[2]=v[3];
vv[3]=l4 + v[1]*Si56[3][1] + v[2]*Si56[3][2];

v[1]=-vv[3];
v[2]=vv[1]*Si45[2][1] + vv[2]*Si45[2][2];
v[3]=-l3 + vv[1]*Si45[3][1] + vv[2]*Si45[3][2];

vv[1]=v[1]*Si34[1][1] + v[2]*Si34[1][2];
vv[2]=-v[3];
vv[3]=l2 + v[1]*Si34[3][1] + v[2]*Si34[3][2];

v[1]=vv[3];
v[2]=-l1 + vv[1]*Si23[2][1] + vv[2]*Si23[2][2];
v[3]=vv[1]*Si23[3][1] + vv[2]*Si23[3][2];

vv[1]=v[1]*Si12[1][1] + v[2]*Si12[1][2];
vv[2]=v[3];
vv[3]=v[1]*Si12[3][1] + v[2]*Si12[3][2];

v[1]=l0/Sqrt(2) + 0.7071067811865475*vv[3] + vv[1]*Si01[1][1] + vv[2]*Si01[1][2];
v[2]=vv[1]*Si01[2][1] + vv[2]*Si01[2][2];
v[3]=l0/Sqrt(2) + 0.7071067811865475*vv[3] + vv[1]*Si01[3][1] + vv[2]*Si01[3][2];

vv[1]=basec[0].x[1] + v[1]*Si00[1][1] + v[2]*Si00[1][2] + v[3]*Si00[1][3];
vv[2]=basec[0].x[2] + v[1]*Si00[2][1] + v[2]*Si00[2][2] + v[3]*Si00[2][3];
vv[3]=basec[0].x[3] + v[1]*Si00[3][1] + v[2]*Si00[3][2] + v[3]*Si00[3][3];

/* link: {0, l8, 0} */
Xlink[9][1]=vv[1];
Xlink[9][2]=vv[2];
Xlink[9][3]=vv[3];

v[1]=l6z;
v[2]=-(l6x*Si67[2][1]) + l6y*Si67[2][2];
v[3]=l5 - l6x*Si67[3][1] + l6y*Si67[3][2];

vv[1]=v[1]*Si56[1][1] + v[2]*Si56[1][2];
vv[2]=v[3];
vv[3]=l4 + v[1]*Si56[3][1] + v[2]*Si56[3][2];

v[1]=-vv[3];
v[2]=vv[1]*Si45[2][1] + vv[2]*Si45[2][2];
v[3]=-l3 + vv[1]*Si45[3][1] + vv[2]*Si45[3][2];

vv[1]=v[1]*Si34[1][1] + v[2]*Si34[1][2];
vv[2]=-v[3];
vv[3]=l2 + v[1]*Si34[3][1] + v[2]*Si34[3][2];

v[1]=vv[3];
v[2]=-l1 + vv[1]*Si23[2][1] + vv[2]*Si23[2][2];
v[3]=vv[1]*Si23[3][1] + vv[2]*Si23[3][2];

vv[1]=v[1]*Si12[1][1] + v[2]*Si12[1][2];
vv[2]=v[3];
vv[3]=v[1]*Si12[3][1] + v[2]*Si12[3][2];

v[1]=l0/Sqrt(2) + 0.7071067811865475*vv[3] + vv[1]*Si01[1][1] + vv[2]*Si01[1][2];
v[2]=vv[1]*Si01[2][1] + vv[2]*Si01[2][2];
v[3]=l0/Sqrt(2) + 0.7071067811865475*vv[3] + vv[1]*Si01[3][1] + vv[2]*Si01[3][2];

vv[1]=basec[0].x[1] + v[1]*Si00[1][1] + v[2]*Si00[1][2] + v[3]*Si00[1][3];
vv[2]=basec[0].x[2] + v[1]*Si00[2][1] + v[2]*Si00[2][2] + v[3]*Si00[2][3];
vv[3]=basec[0].x[3] + v[1]*Si00[3][1] + v[2]*Si00[3][2] + v[3]*Si00[3][3];

/* link: {-l6x, l6y, l6z} */
Xlink[10][1]=vv[1];
Xlink[10][2]=vv[2];
Xlink[10][3]=vv[3];

v[1]=-l6x + l9*Si712[1][2];
v[2]=l6y + l9*Si712[2][2];
v[3]=l6z;

vv[1]=v[3];
vv[2]=v[1]*Si67[2][1] + v[2]*Si67[2][2];
vv[3]=l5 + v[1]*Si67[3][1] + v[2]*Si67[3][2];

v[1]=vv[1]*Si56[1][1] + vv[2]*Si56[1][2];
v[2]=vv[3];
v[3]=l4 + vv[1]*Si56[3][1] + vv[2]*Si56[3][2];

vv[1]=-v[3];
vv[2]=v[1]*Si45[2][1] + v[2]*Si45[2][2];
vv[3]=-l3 + v[1]*Si45[3][1] + v[2]*Si45[3][2];

v[1]=vv[1]*Si34[1][1] + vv[2]*Si34[1][2];
v[2]=-vv[3];
v[3]=l2 + vv[1]*Si34[3][1] + vv[2]*Si34[3][2];

vv[1]=v[3];
vv[2]=-l1 + v[1]*Si23[2][1] + v[2]*Si23[2][2];
vv[3]=v[1]*Si23[3][1] + v[2]*Si23[3][2];

v[1]=vv[1]*Si12[1][1] + vv[2]*Si12[1][2];
v[2]=vv[3];
v[3]=vv[1]*Si12[3][1] + vv[2]*Si12[3][2];

vv[1]=l0/Sqrt(2) + 0.7071067811865475*v[3] + v[1]*Si01[1][1] + v[2]*Si01[1][2];
vv[2]=v[1]*Si01[2][1] + v[2]*Si01[2][2];
vv[3]=l0/Sqrt(2) + 0.7071067811865475*v[3] + v[1]*Si01[3][1] + v[2]*Si01[3][2];

v[1]=basec[0].x[1] + vv[1]*Si00[1][1] + vv[2]*Si00[1][2] + vv[3]*Si00[1][3];
v[2]=basec[0].x[2] + vv[1]*Si00[2][1] + vv[2]*Si00[2][2] + vv[3]*Si00[2][3];
v[3]=basec[0].x[3] + vv[1]*Si00[3][1] + vv[2]*Si00[3][2] + vv[3]*Si00[3][3];

/* link: {0, l9, 0} */
Xlink[11][1]=v[1];
Xlink[11][2]=v[2];
Xlink[11][3]=v[3];


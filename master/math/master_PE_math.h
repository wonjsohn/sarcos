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








/* inverse spatial rotation matrices */
Xinv[0][1][1]=-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[2],2);
Xinv[0][1][2]=2*(baseo[0].q[2]*baseo[0].q[3] - baseo[0].q[1]*baseo[0].q[4]);
Xinv[0][1][3]=2*(baseo[0].q[1]*baseo[0].q[3] + baseo[0].q[2]*baseo[0].q[4]);
Xinv[0][1][4]=0;
Xinv[0][1][5]=0;
Xinv[0][1][6]=0;

Xinv[0][2][1]=2*(baseo[0].q[2]*baseo[0].q[3] + baseo[0].q[1]*baseo[0].q[4]);
Xinv[0][2][2]=-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[3],2);
Xinv[0][2][3]=2*(-(baseo[0].q[1]*baseo[0].q[2]) + baseo[0].q[3]*baseo[0].q[4]);
Xinv[0][2][4]=0;
Xinv[0][2][5]=0;
Xinv[0][2][6]=0;

Xinv[0][3][1]=2*(-(baseo[0].q[1]*baseo[0].q[3]) + baseo[0].q[2]*baseo[0].q[4]);
Xinv[0][3][2]=2*(baseo[0].q[1]*baseo[0].q[2] + baseo[0].q[3]*baseo[0].q[4]);
Xinv[0][3][3]=-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[4],2);
Xinv[0][3][4]=0;
Xinv[0][3][5]=0;
Xinv[0][3][6]=0;

Xinv[0][4][1]=0;
Xinv[0][4][2]=0;
Xinv[0][4][3]=0;
Xinv[0][4][4]=-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[2],2);
Xinv[0][4][5]=2*(baseo[0].q[2]*baseo[0].q[3] - baseo[0].q[1]*baseo[0].q[4]);
Xinv[0][4][6]=2*(baseo[0].q[1]*baseo[0].q[3] + baseo[0].q[2]*baseo[0].q[4]);

Xinv[0][5][1]=0;
Xinv[0][5][2]=0;
Xinv[0][5][3]=0;
Xinv[0][5][4]=2*(baseo[0].q[2]*baseo[0].q[3] + baseo[0].q[1]*baseo[0].q[4]);
Xinv[0][5][5]=-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[3],2);
Xinv[0][5][6]=2*(-(baseo[0].q[1]*baseo[0].q[2]) + baseo[0].q[3]*baseo[0].q[4]);

Xinv[0][6][1]=0;
Xinv[0][6][2]=0;
Xinv[0][6][3]=0;
Xinv[0][6][4]=2*(-(baseo[0].q[1]*baseo[0].q[3]) + baseo[0].q[2]*baseo[0].q[4]);
Xinv[0][6][5]=2*(baseo[0].q[1]*baseo[0].q[2] + baseo[0].q[3]*baseo[0].q[4]);
Xinv[0][6][6]=-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[4],2);


Xinv[1][1][1]=0.7071067811865475*cstate1th;
Xinv[1][1][2]=-0.7071067811865475*sstate1th;
Xinv[1][1][3]=0.7071067811865475;
Xinv[1][1][4]=0;
Xinv[1][1][5]=0;
Xinv[1][1][6]=0;

Xinv[1][2][1]=sstate1th;
Xinv[1][2][2]=cstate1th;
Xinv[1][2][3]=0;
Xinv[1][2][4]=0;
Xinv[1][2][5]=0;
Xinv[1][2][6]=0;

Xinv[1][3][1]=-0.7071067811865475*cstate1th;
Xinv[1][3][2]=0.7071067811865475*sstate1th;
Xinv[1][3][3]=0.7071067811865475;
Xinv[1][3][4]=0;
Xinv[1][3][5]=0;
Xinv[1][3][6]=0;

Xinv[1][4][1]=-((l0*sstate1th)/Sqrt(2));
Xinv[1][4][2]=-((cstate1th*l0)/Sqrt(2));
Xinv[1][4][3]=0;
Xinv[1][4][4]=0.7071067811865475*cstate1th;
Xinv[1][4][5]=-0.7071067811865475*sstate1th;
Xinv[1][4][6]=0.7071067811865475;

Xinv[1][5][1]=0.9999999999999998*cstate1th*l0;
Xinv[1][5][2]=-0.9999999999999998*l0*sstate1th;
Xinv[1][5][3]=0;
Xinv[1][5][4]=sstate1th;
Xinv[1][5][5]=cstate1th;
Xinv[1][5][6]=0;

Xinv[1][6][1]=(l0*sstate1th)/Sqrt(2);
Xinv[1][6][2]=(cstate1th*l0)/Sqrt(2);
Xinv[1][6][3]=0;
Xinv[1][6][4]=-0.7071067811865475*cstate1th;
Xinv[1][6][5]=0.7071067811865475*sstate1th;
Xinv[1][6][6]=0.7071067811865475;


Xinv[2][1][1]=0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th;
Xinv[2][1][2]=-0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th;
Xinv[2][1][3]=0;
Xinv[2][1][4]=0;
Xinv[2][1][5]=0;
Xinv[2][1][6]=0;

Xinv[2][2][1]=0;
Xinv[2][2][2]=0;
Xinv[2][2][3]=1;
Xinv[2][2][4]=0;
Xinv[2][2][5]=0;
Xinv[2][2][6]=0;

Xinv[2][3][1]=-0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th;
Xinv[2][3][2]=-0.7071067811865475*cstate2th + 0.7071067811865475*sstate2th;
Xinv[2][3][3]=0;
Xinv[2][3][4]=0;
Xinv[2][3][5]=0;
Xinv[2][3][6]=0;

Xinv[2][4][1]=0;
Xinv[2][4][2]=0;
Xinv[2][4][3]=0;
Xinv[2][4][4]=0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th;
Xinv[2][4][5]=-0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th;
Xinv[2][4][6]=0;

Xinv[2][5][1]=0;
Xinv[2][5][2]=0;
Xinv[2][5][3]=0;
Xinv[2][5][4]=0;
Xinv[2][5][5]=0;
Xinv[2][5][6]=1;

Xinv[2][6][1]=0;
Xinv[2][6][2]=0;
Xinv[2][6][3]=0;
Xinv[2][6][4]=-0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th;
Xinv[2][6][5]=-0.7071067811865475*cstate2th + 0.7071067811865475*sstate2th;
Xinv[2][6][6]=0;


Xinv[3][1][1]=0;
Xinv[3][1][2]=0;
Xinv[3][1][3]=1;
Xinv[3][1][4]=0;
Xinv[3][1][5]=0;
Xinv[3][1][6]=0;

Xinv[3][2][1]=sstate3th;
Xinv[3][2][2]=cstate3th;
Xinv[3][2][3]=0;
Xinv[3][2][4]=0;
Xinv[3][2][5]=0;
Xinv[3][2][6]=0;

Xinv[3][3][1]=-cstate3th;
Xinv[3][3][2]=sstate3th;
Xinv[3][3][3]=0;
Xinv[3][3][4]=0;
Xinv[3][3][5]=0;
Xinv[3][3][6]=0;

Xinv[3][4][1]=cstate3th*l1;
Xinv[3][4][2]=-(l1*sstate3th);
Xinv[3][4][3]=0;
Xinv[3][4][4]=0;
Xinv[3][4][5]=0;
Xinv[3][4][6]=1;

Xinv[3][5][1]=0;
Xinv[3][5][2]=0;
Xinv[3][5][3]=0;
Xinv[3][5][4]=sstate3th;
Xinv[3][5][5]=cstate3th;
Xinv[3][5][6]=0;

Xinv[3][6][1]=0;
Xinv[3][6][2]=0;
Xinv[3][6][3]=l1;
Xinv[3][6][4]=-cstate3th;
Xinv[3][6][5]=sstate3th;
Xinv[3][6][6]=0;


Xinv[4][1][1]=sstate4th;
Xinv[4][1][2]=cstate4th;
Xinv[4][1][3]=0;
Xinv[4][1][4]=0;
Xinv[4][1][5]=0;
Xinv[4][1][6]=0;

Xinv[4][2][1]=0;
Xinv[4][2][2]=0;
Xinv[4][2][3]=-1;
Xinv[4][2][4]=0;
Xinv[4][2][5]=0;
Xinv[4][2][6]=0;

Xinv[4][3][1]=-cstate4th;
Xinv[4][3][2]=sstate4th;
Xinv[4][3][3]=0;
Xinv[4][3][4]=0;
Xinv[4][3][5]=0;
Xinv[4][3][6]=0;

Xinv[4][4][1]=0;
Xinv[4][4][2]=0;
Xinv[4][4][3]=l2;
Xinv[4][4][4]=sstate4th;
Xinv[4][4][5]=cstate4th;
Xinv[4][4][6]=0;

Xinv[4][5][1]=l2*sstate4th;
Xinv[4][5][2]=cstate4th*l2;
Xinv[4][5][3]=0;
Xinv[4][5][4]=0;
Xinv[4][5][5]=0;
Xinv[4][5][6]=-1;

Xinv[4][6][1]=0;
Xinv[4][6][2]=0;
Xinv[4][6][3]=0;
Xinv[4][6][4]=-cstate4th;
Xinv[4][6][5]=sstate4th;
Xinv[4][6][6]=0;


Xinv[5][1][1]=0;
Xinv[5][1][2]=0;
Xinv[5][1][3]=-1;
Xinv[5][1][4]=0;
Xinv[5][1][5]=0;
Xinv[5][1][6]=0;

Xinv[5][2][1]=sstate5th;
Xinv[5][2][2]=cstate5th;
Xinv[5][2][3]=0;
Xinv[5][2][4]=0;
Xinv[5][2][5]=0;
Xinv[5][2][6]=0;

Xinv[5][3][1]=cstate5th;
Xinv[5][3][2]=-sstate5th;
Xinv[5][3][3]=0;
Xinv[5][3][4]=0;
Xinv[5][3][5]=0;
Xinv[5][3][6]=0;

Xinv[5][4][1]=l3*sstate5th;
Xinv[5][4][2]=cstate5th*l3;
Xinv[5][4][3]=0;
Xinv[5][4][4]=0;
Xinv[5][4][5]=0;
Xinv[5][4][6]=-1;

Xinv[5][5][1]=0;
Xinv[5][5][2]=0;
Xinv[5][5][3]=l3;
Xinv[5][5][4]=sstate5th;
Xinv[5][5][5]=cstate5th;
Xinv[5][5][6]=0;

Xinv[5][6][1]=0;
Xinv[5][6][2]=0;
Xinv[5][6][3]=0;
Xinv[5][6][4]=cstate5th;
Xinv[5][6][5]=-sstate5th;
Xinv[5][6][6]=0;


Xinv[6][1][1]=cstate6th;
Xinv[6][1][2]=-sstate6th;
Xinv[6][1][3]=0;
Xinv[6][1][4]=0;
Xinv[6][1][5]=0;
Xinv[6][1][6]=0;

Xinv[6][2][1]=0;
Xinv[6][2][2]=0;
Xinv[6][2][3]=1;
Xinv[6][2][4]=0;
Xinv[6][2][5]=0;
Xinv[6][2][6]=0;

Xinv[6][3][1]=-sstate6th;
Xinv[6][3][2]=-cstate6th;
Xinv[6][3][3]=0;
Xinv[6][3][4]=0;
Xinv[6][3][5]=0;
Xinv[6][3][6]=0;

Xinv[6][4][1]=0;
Xinv[6][4][2]=0;
Xinv[6][4][3]=-l4;
Xinv[6][4][4]=cstate6th;
Xinv[6][4][5]=-sstate6th;
Xinv[6][4][6]=0;

Xinv[6][5][1]=cstate6th*l4;
Xinv[6][5][2]=-(l4*sstate6th);
Xinv[6][5][3]=0;
Xinv[6][5][4]=0;
Xinv[6][5][5]=0;
Xinv[6][5][6]=1;

Xinv[6][6][1]=0;
Xinv[6][6][2]=0;
Xinv[6][6][3]=0;
Xinv[6][6][4]=-sstate6th;
Xinv[6][6][5]=-cstate6th;
Xinv[6][6][6]=0;


Xinv[7][1][1]=0;
Xinv[7][1][2]=0;
Xinv[7][1][3]=1;
Xinv[7][1][4]=0;
Xinv[7][1][5]=0;
Xinv[7][1][6]=0;

Xinv[7][2][1]=-sstate7th;
Xinv[7][2][2]=-cstate7th;
Xinv[7][2][3]=0;
Xinv[7][2][4]=0;
Xinv[7][2][5]=0;
Xinv[7][2][6]=0;

Xinv[7][3][1]=cstate7th;
Xinv[7][3][2]=-sstate7th;
Xinv[7][3][3]=0;
Xinv[7][3][4]=0;
Xinv[7][3][5]=0;
Xinv[7][3][6]=0;

Xinv[7][4][1]=l5*sstate7th;
Xinv[7][4][2]=cstate7th*l5;
Xinv[7][4][3]=0;
Xinv[7][4][4]=0;
Xinv[7][4][5]=0;
Xinv[7][4][6]=1;

Xinv[7][5][1]=0;
Xinv[7][5][2]=0;
Xinv[7][5][3]=l5;
Xinv[7][5][4]=-sstate7th;
Xinv[7][5][5]=-cstate7th;
Xinv[7][5][6]=0;

Xinv[7][6][1]=0;
Xinv[7][6][2]=0;
Xinv[7][6][3]=0;
Xinv[7][6][4]=cstate7th;
Xinv[7][6][5]=-sstate7th;
Xinv[7][6][6]=0;


Xinv[8][1][1]=rceff1a2*rceff1a3;
Xinv[8][1][2]=-(rceff1a2*rseff1a3);
Xinv[8][1][3]=rseff1a2;
Xinv[8][1][4]=0;
Xinv[8][1][5]=0;
Xinv[8][1][6]=0;

Xinv[8][2][1]=rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3;
Xinv[8][2][2]=rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3;
Xinv[8][2][3]=-(rceff1a2*rseff1a1);
Xinv[8][2][4]=0;
Xinv[8][2][5]=0;
Xinv[8][2][6]=0;

Xinv[8][3][1]=-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3;
Xinv[8][3][2]=rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3;
Xinv[8][3][3]=rceff1a1*rceff1a2;
Xinv[8][3][4]=0;
Xinv[8][3][5]=0;
Xinv[8][3][6]=0;

Xinv[8][4][1]=(-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3)*eff[1].x[2] - (rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3)*eff[1].x[3];
Xinv[8][4][2]=(rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3)*eff[1].x[2] - (rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3)*eff[1].x[3];
Xinv[8][4][3]=rceff1a1*rceff1a2*eff[1].x[2] + rceff1a2*rseff1a1*eff[1].x[3];
Xinv[8][4][4]=rceff1a2*rceff1a3;
Xinv[8][4][5]=-(rceff1a2*rseff1a3);
Xinv[8][4][6]=rseff1a2;

Xinv[8][5][1]=-((-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3)*eff[1].x[1]) + rceff1a2*rceff1a3*eff[1].x[3];
Xinv[8][5][2]=-((rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3)*eff[1].x[1]) - rceff1a2*rseff1a3*eff[1].x[3];
Xinv[8][5][3]=-(rceff1a1*rceff1a2*eff[1].x[1]) + rseff1a2*eff[1].x[3];
Xinv[8][5][4]=rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3;
Xinv[8][5][5]=rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3;
Xinv[8][5][6]=-(rceff1a2*rseff1a1);

Xinv[8][6][1]=(rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3)*eff[1].x[1] - rceff1a2*rceff1a3*eff[1].x[2];
Xinv[8][6][2]=(rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3)*eff[1].x[1] + rceff1a2*rseff1a3*eff[1].x[2];
Xinv[8][6][3]=-(rceff1a2*rseff1a1*eff[1].x[1]) - rseff1a2*eff[1].x[2];
Xinv[8][6][4]=-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3;
Xinv[8][6][5]=rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3;
Xinv[8][6][6]=rceff1a1*rceff1a2;


Xinv[9][1][1]=0;
Xinv[9][1][2]=0;
Xinv[9][1][3]=-1;
Xinv[9][1][4]=0;
Xinv[9][1][5]=0;
Xinv[9][1][6]=0;

Xinv[9][2][1]=sstate8th;
Xinv[9][2][2]=cstate8th;
Xinv[9][2][3]=0;
Xinv[9][2][4]=0;
Xinv[9][2][5]=0;
Xinv[9][2][6]=0;

Xinv[9][3][1]=cstate8th;
Xinv[9][3][2]=-sstate8th;
Xinv[9][3][3]=0;
Xinv[9][3][4]=0;
Xinv[9][3][5]=0;
Xinv[9][3][6]=0;

Xinv[9][4][1]=-(l7z*sstate8th);
Xinv[9][4][2]=-(cstate8th*l7z);
Xinv[9][4][3]=0;
Xinv[9][4][4]=0;
Xinv[9][4][5]=0;
Xinv[9][4][6]=-1;

Xinv[9][5][1]=cstate8th*l6x;
Xinv[9][5][2]=-(l6x*sstate8th);
Xinv[9][5][3]=-l7z;
Xinv[9][5][4]=sstate8th;
Xinv[9][5][5]=cstate8th;
Xinv[9][5][6]=0;

Xinv[9][6][1]=-(l6x*sstate8th);
Xinv[9][6][2]=-(cstate8th*l6x);
Xinv[9][6][3]=0;
Xinv[9][6][4]=cstate8th;
Xinv[9][6][5]=-sstate8th;
Xinv[9][6][6]=0;


Xinv[10][1][1]=0;
Xinv[10][1][2]=0;
Xinv[10][1][3]=1;
Xinv[10][1][4]=0;
Xinv[10][1][5]=0;
Xinv[10][1][6]=0;

Xinv[10][2][1]=sstate9th;
Xinv[10][2][2]=cstate9th;
Xinv[10][2][3]=0;
Xinv[10][2][4]=0;
Xinv[10][2][5]=0;
Xinv[10][2][6]=0;

Xinv[10][3][1]=-cstate9th;
Xinv[10][3][2]=sstate9th;
Xinv[10][3][3]=0;
Xinv[10][3][4]=0;
Xinv[10][3][5]=0;
Xinv[10][3][6]=0;

Xinv[10][4][1]=0;
Xinv[10][4][2]=0;
Xinv[10][4][3]=0;
Xinv[10][4][4]=0;
Xinv[10][4][5]=0;
Xinv[10][4][6]=1;

Xinv[10][5][1]=0;
Xinv[10][5][2]=0;
Xinv[10][5][3]=0;
Xinv[10][5][4]=sstate9th;
Xinv[10][5][5]=cstate9th;
Xinv[10][5][6]=0;

Xinv[10][6][1]=0;
Xinv[10][6][2]=0;
Xinv[10][6][3]=0;
Xinv[10][6][4]=-cstate9th;
Xinv[10][6][5]=sstate9th;
Xinv[10][6][6]=0;


Xinv[11][1][1]=1;
Xinv[11][1][2]=0;
Xinv[11][1][3]=0;
Xinv[11][1][4]=0;
Xinv[11][1][5]=0;
Xinv[11][1][6]=0;

Xinv[11][2][1]=0;
Xinv[11][2][2]=1;
Xinv[11][2][3]=0;
Xinv[11][2][4]=0;
Xinv[11][2][5]=0;
Xinv[11][2][6]=0;

Xinv[11][3][1]=0;
Xinv[11][3][2]=0;
Xinv[11][3][3]=1;
Xinv[11][3][4]=0;
Xinv[11][3][5]=0;
Xinv[11][3][6]=0;

Xinv[11][4][1]=0;
Xinv[11][4][2]=0;
Xinv[11][4][3]=l8;
Xinv[11][4][4]=1;
Xinv[11][4][5]=0;
Xinv[11][4][6]=0;

Xinv[11][5][1]=0;
Xinv[11][5][2]=0;
Xinv[11][5][3]=0;
Xinv[11][5][4]=0;
Xinv[11][5][5]=1;
Xinv[11][5][6]=0;

Xinv[11][6][1]=-l8;
Xinv[11][6][2]=0;
Xinv[11][6][3]=0;
Xinv[11][6][4]=0;
Xinv[11][6][5]=0;
Xinv[11][6][6]=1;


Xinv[12][1][1]=cstate10th;
Xinv[12][1][2]=-sstate10th;
Xinv[12][1][3]=0;
Xinv[12][1][4]=0;
Xinv[12][1][5]=0;
Xinv[12][1][6]=0;

Xinv[12][2][1]=sstate10th;
Xinv[12][2][2]=cstate10th;
Xinv[12][2][3]=0;
Xinv[12][2][4]=0;
Xinv[12][2][5]=0;
Xinv[12][2][6]=0;

Xinv[12][3][1]=0;
Xinv[12][3][2]=0;
Xinv[12][3][3]=1;
Xinv[12][3][4]=0;
Xinv[12][3][5]=0;
Xinv[12][3][6]=0;

Xinv[12][4][1]=-(l6z*sstate10th);
Xinv[12][4][2]=-(cstate10th*l6z);
Xinv[12][4][3]=l6y;
Xinv[12][4][4]=cstate10th;
Xinv[12][4][5]=-sstate10th;
Xinv[12][4][6]=0;

Xinv[12][5][1]=cstate10th*l6z;
Xinv[12][5][2]=-(l6z*sstate10th);
Xinv[12][5][3]=l6x;
Xinv[12][5][4]=sstate10th;
Xinv[12][5][5]=cstate10th;
Xinv[12][5][6]=0;

Xinv[12][6][1]=-(cstate10th*l6y) - l6x*sstate10th;
Xinv[12][6][2]=-(cstate10th*l6x) + l6y*sstate10th;
Xinv[12][6][3]=0;
Xinv[12][6][4]=0;
Xinv[12][6][5]=0;
Xinv[12][6][6]=1;


Xinv[13][1][1]=1;
Xinv[13][1][2]=0;
Xinv[13][1][3]=0;
Xinv[13][1][4]=0;
Xinv[13][1][5]=0;
Xinv[13][1][6]=0;

Xinv[13][2][1]=0;
Xinv[13][2][2]=1;
Xinv[13][2][3]=0;
Xinv[13][2][4]=0;
Xinv[13][2][5]=0;
Xinv[13][2][6]=0;

Xinv[13][3][1]=0;
Xinv[13][3][2]=0;
Xinv[13][3][3]=1;
Xinv[13][3][4]=0;
Xinv[13][3][5]=0;
Xinv[13][3][6]=0;

Xinv[13][4][1]=0;
Xinv[13][4][2]=0;
Xinv[13][4][3]=l9;
Xinv[13][4][4]=1;
Xinv[13][4][5]=0;
Xinv[13][4][6]=0;

Xinv[13][5][1]=0;
Xinv[13][5][2]=0;
Xinv[13][5][3]=0;
Xinv[13][5][4]=0;
Xinv[13][5][5]=1;
Xinv[13][5][6]=0;

Xinv[13][6][1]=-l9;
Xinv[13][6][2]=0;
Xinv[13][6][3]=0;
Xinv[13][6][4]=0;
Xinv[13][6][5]=0;
Xinv[13][6][6]=1;



/* spatial transpose of axis of the DOFs */
st[1][1]=0;
st[1][2]=0;
st[1][3]=0;
st[1][4]=0;
st[1][5]=0;
st[1][6]=1;

st[2][1]=0;
st[2][2]=0;
st[2][3]=0;
st[2][4]=0;
st[2][5]=0;
st[2][6]=1;

st[3][1]=0;
st[3][2]=0;
st[3][3]=0;
st[3][4]=0;
st[3][5]=0;
st[3][6]=1;

st[4][1]=0;
st[4][2]=0;
st[4][3]=0;
st[4][4]=0;
st[4][5]=0;
st[4][6]=1;

st[5][1]=0;
st[5][2]=0;
st[5][3]=0;
st[5][4]=0;
st[5][5]=0;
st[5][6]=1;

st[6][1]=0;
st[6][2]=0;
st[6][3]=0;
st[6][4]=0;
st[6][5]=0;
st[6][6]=1;

st[7][1]=0;
st[7][2]=0;
st[7][3]=0;
st[7][4]=0;
st[7][5]=0;
st[7][6]=1;

st[8][1]=0;
st[8][2]=0;
st[8][3]=0;
st[8][4]=0;
st[8][5]=0;
st[8][6]=0;

st[9][1]=0;
st[9][2]=0;
st[9][3]=0;
st[9][4]=0;
st[9][5]=0;
st[9][6]=1;

st[10][1]=0;
st[10][2]=0;
st[10][3]=0;
st[10][4]=0;
st[10][5]=0;
st[10][6]=1;

st[11][1]=0;
st[11][2]=0;
st[11][3]=0;
st[11][4]=0;
st[11][5]=0;
st[11][6]=0;

st[12][1]=0;
st[12][2]=0;
st[12][3]=0;
st[12][4]=0;
st[12][5]=0;
st[12][6]=1;

st[13][1]=0;
st[13][2]=0;
st[13][3]=0;
st[13][4]=0;
st[13][5]=0;
st[13][6]=0;


/* velocity vectors */
v0[1]=baseo[0].ad[1]*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[2],2)) + 2*baseo[0].ad[2]*(baseo[0].q[2]*baseo[0].q[3] + baseo[0].q[1]*baseo[0].q[4]) + 2*baseo[0].ad[3]*(-(baseo[0].q[1]*baseo[0].q[3]) + baseo[0].q[2]*baseo[0].q[4]);
v0[2]=baseo[0].ad[2]*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[3],2)) + 2*baseo[0].ad[1]*(baseo[0].q[2]*baseo[0].q[3] - baseo[0].q[1]*baseo[0].q[4]) + 2*baseo[0].ad[3]*(baseo[0].q[1]*baseo[0].q[2] + baseo[0].q[3]*baseo[0].q[4]);
v0[3]=2*baseo[0].ad[1]*(baseo[0].q[1]*baseo[0].q[3] + baseo[0].q[2]*baseo[0].q[4]) + 2*baseo[0].ad[2]*(-(baseo[0].q[1]*baseo[0].q[2]) + baseo[0].q[3]*baseo[0].q[4]) + baseo[0].ad[3]*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[4],2));
v0[4]=basec[0].xd[1]*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[2],2)) + 2*basec[0].xd[2]*(baseo[0].q[2]*baseo[0].q[3] + baseo[0].q[1]*baseo[0].q[4]) + 2*basec[0].xd[3]*(-(baseo[0].q[1]*baseo[0].q[3]) + baseo[0].q[2]*baseo[0].q[4]);
v0[5]=basec[0].xd[2]*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[3],2)) + 2*basec[0].xd[1]*(baseo[0].q[2]*baseo[0].q[3] - baseo[0].q[1]*baseo[0].q[4]) + 2*basec[0].xd[3]*(baseo[0].q[1]*baseo[0].q[2] + baseo[0].q[3]*baseo[0].q[4]);
v0[6]=2*basec[0].xd[1]*(baseo[0].q[1]*baseo[0].q[3] + baseo[0].q[2]*baseo[0].q[4]) + 2*basec[0].xd[2]*(-(baseo[0].q[1]*baseo[0].q[2]) + baseo[0].q[3]*baseo[0].q[4]) + basec[0].xd[3]*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[4],2));

v1[1]=0.7071067811865475*cstate1th*v0[1] + sstate1th*v0[2] - 0.7071067811865475*cstate1th*v0[3];
v1[2]=-0.7071067811865475*sstate1th*v0[1] + cstate1th*v0[2] + 0.7071067811865475*sstate1th*v0[3];
v1[3]=state[1].thd + 0.7071067811865475*v0[1] + 0.7071067811865475*v0[3];
v1[4]=-((l0*sstate1th*v0[1])/Sqrt(2)) + 0.9999999999999998*cstate1th*l0*v0[2] + (l0*sstate1th*v0[3])/Sqrt(2) + 0.7071067811865475*cstate1th*v0[4] + sstate1th*v0[5] - 0.7071067811865475*cstate1th*v0[6];
v1[5]=-((cstate1th*l0*v0[1])/Sqrt(2)) - 0.9999999999999998*l0*sstate1th*v0[2] + (cstate1th*l0*v0[3])/Sqrt(2) - 0.7071067811865475*sstate1th*v0[4] + cstate1th*v0[5] + 0.7071067811865475*sstate1th*v0[6];
v1[6]=0.7071067811865475*v0[4] + 0.7071067811865475*v0[6];

v2[1]=(0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th)*v1[1] + (-0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th)*v1[3];
v2[2]=(-0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th)*v1[1] + (-0.7071067811865475*cstate2th + 0.7071067811865475*sstate2th)*v1[3];
v2[3]=state[2].thd + v1[2];
v2[4]=(0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th)*v1[4] + (-0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th)*v1[6];
v2[5]=(-0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th)*v1[4] + (-0.7071067811865475*cstate2th + 0.7071067811865475*sstate2th)*v1[6];
v2[6]=v1[5];

v3[1]=sstate3th*v2[2] - cstate3th*v2[3];
v3[2]=cstate3th*v2[2] + sstate3th*v2[3];
v3[3]=state[3].thd + v2[1];
v3[4]=cstate3th*l1*v2[1] + sstate3th*v2[5] - cstate3th*v2[6];
v3[5]=-(l1*sstate3th*v2[1]) + cstate3th*v2[5] + sstate3th*v2[6];
v3[6]=l1*v2[3] + v2[4];

v4[1]=sstate4th*v3[1] - cstate4th*v3[3];
v4[2]=cstate4th*v3[1] + sstate4th*v3[3];
v4[3]=state[4].thd - v3[2];
v4[4]=l2*sstate4th*v3[2] + sstate4th*v3[4] - cstate4th*v3[6];
v4[5]=cstate4th*l2*v3[2] + cstate4th*v3[4] + sstate4th*v3[6];
v4[6]=l2*v3[1] - v3[5];

v5[1]=sstate5th*v4[2] + cstate5th*v4[3];
v5[2]=cstate5th*v4[2] - sstate5th*v4[3];
v5[3]=state[5].thd - v4[1];
v5[4]=l3*sstate5th*v4[1] + sstate5th*v4[5] + cstate5th*v4[6];
v5[5]=cstate5th*l3*v4[1] + cstate5th*v4[5] - sstate5th*v4[6];
v5[6]=l3*v4[2] - v4[4];

v6[1]=cstate6th*v5[1] - sstate6th*v5[3];
v6[2]=-(sstate6th*v5[1]) - cstate6th*v5[3];
v6[3]=state[6].thd + v5[2];
v6[4]=cstate6th*l4*v5[2] + cstate6th*v5[4] - sstate6th*v5[6];
v6[5]=-(l4*sstate6th*v5[2]) - sstate6th*v5[4] - cstate6th*v5[6];
v6[6]=-(l4*v5[1]) + v5[5];

v7[1]=-(sstate7th*v6[2]) + cstate7th*v6[3];
v7[2]=-(cstate7th*v6[2]) - sstate7th*v6[3];
v7[3]=state[7].thd + v6[1];
v7[4]=l5*sstate7th*v6[1] - sstate7th*v6[5] + cstate7th*v6[6];
v7[5]=cstate7th*l5*v6[1] - cstate7th*v6[5] - sstate7th*v6[6];
v7[6]=l5*v6[2] + v6[4];

v8[1]=rceff1a2*rceff1a3*v7[1] + (rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3)*v7[2] + (-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3)*v7[3];
v8[2]=-(rceff1a2*rseff1a3*v7[1]) + (rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3)*v7[2] + (rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3)*v7[3];
v8[3]=rseff1a2*v7[1] - rceff1a2*rseff1a1*v7[2] + rceff1a1*rceff1a2*v7[3];
v8[4]=((-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3)*eff[1].x[2] - (rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3)*eff[1].x[3])*v7[1] + (-((-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3)*eff[1].x[1]) + rceff1a2*rceff1a3*eff[1].x[3])*v7[2] + ((rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3)*eff[1].x[1] - rceff1a2*rceff1a3*eff[1].x[2])*v7[3] + rceff1a2*rceff1a3*v7[4] + (rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3)*v7[5] + (-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3)*v7[6];
v8[5]=((rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3)*eff[1].x[2] - (rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3)*eff[1].x[3])*v7[1] + (-((rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3)*eff[1].x[1]) - rceff1a2*rseff1a3*eff[1].x[3])*v7[2] + ((rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3)*eff[1].x[1] + rceff1a2*rseff1a3*eff[1].x[2])*v7[3] - rceff1a2*rseff1a3*v7[4] + (rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3)*v7[5] + (rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3)*v7[6];
v8[6]=(rceff1a1*rceff1a2*eff[1].x[2] + rceff1a2*rseff1a1*eff[1].x[3])*v7[1] + (-(rceff1a1*rceff1a2*eff[1].x[1]) + rseff1a2*eff[1].x[3])*v7[2] + (-(rceff1a2*rseff1a1*eff[1].x[1]) - rseff1a2*eff[1].x[2])*v7[3] + rseff1a2*v7[4] - rceff1a2*rseff1a1*v7[5] + rceff1a1*rceff1a2*v7[6];

v9[1]=sstate8th*v7[2] + cstate8th*v7[3];
v9[2]=cstate8th*v7[2] - sstate8th*v7[3];
v9[3]=state[8].thd - v7[1];
v9[4]=-(l7z*sstate8th*v7[1]) + cstate8th*l6x*v7[2] - l6x*sstate8th*v7[3] + sstate8th*v7[5] + cstate8th*v7[6];
v9[5]=-(cstate8th*l7z*v7[1]) - l6x*sstate8th*v7[2] - cstate8th*l6x*v7[3] + cstate8th*v7[5] - sstate8th*v7[6];
v9[6]=-(l7z*v7[2]) - v7[4];

v10[1]=sstate9th*v9[2] - cstate9th*v9[3];
v10[2]=cstate9th*v9[2] + sstate9th*v9[3];
v10[3]=state[9].thd + v9[1];
v10[4]=sstate9th*v9[5] - cstate9th*v9[6];
v10[5]=cstate9th*v9[5] + sstate9th*v9[6];
v10[6]=v9[4];

v11[1]=v10[1];
v11[2]=v10[2];
v11[3]=v10[3];
v11[4]=-(l8*v10[3]) + v10[4];
v11[5]=v10[5];
v11[6]=l8*v10[1] + v10[6];

v12[1]=cstate10th*v7[1] + sstate10th*v7[2];
v12[2]=-(sstate10th*v7[1]) + cstate10th*v7[2];
v12[3]=state[10].thd + v7[3];
v12[4]=-(l6z*sstate10th*v7[1]) + cstate10th*l6z*v7[2] + (-(cstate10th*l6y) - l6x*sstate10th)*v7[3] + cstate10th*v7[4] + sstate10th*v7[5];
v12[5]=-(cstate10th*l6z*v7[1]) - l6z*sstate10th*v7[2] + (-(cstate10th*l6x) + l6y*sstate10th)*v7[3] - sstate10th*v7[4] + cstate10th*v7[5];
v12[6]=l6y*v7[1] + l6x*v7[2] + v7[6];

v13[1]=v12[1];
v13[2]=v12[2];
v13[3]=v12[3];
v13[4]=-(l9*v12[3]) + v12[4];
v13[5]=v12[5];
v13[6]=l9*v12[1] + v12[6];


/* acceleration vectors */
a0[1]=baseo[0].add[1]*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[2],2)) + 2*baseo[0].add[2]*(baseo[0].q[2]*baseo[0].q[3] + baseo[0].q[1]*baseo[0].q[4]) + 2*baseo[0].add[3]*(-(baseo[0].q[1]*baseo[0].q[3]) + baseo[0].q[2]*baseo[0].q[4]);
a0[2]=baseo[0].add[2]*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[3],2)) + 2*baseo[0].add[1]*(baseo[0].q[2]*baseo[0].q[3] - baseo[0].q[1]*baseo[0].q[4]) + 2*baseo[0].add[3]*(baseo[0].q[1]*baseo[0].q[2] + baseo[0].q[3]*baseo[0].q[4]);
a0[3]=2*baseo[0].add[1]*(baseo[0].q[1]*baseo[0].q[3] + baseo[0].q[2]*baseo[0].q[4]) + 2*baseo[0].add[2]*(-(baseo[0].q[1]*baseo[0].q[2]) + baseo[0].q[3]*baseo[0].q[4]) + baseo[0].add[3]*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[4],2));
a0[4]=basec[0].xdd[1]*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[2],2)) + 2*basec[0].xdd[2]*(baseo[0].q[2]*baseo[0].q[3] + baseo[0].q[1]*baseo[0].q[4]) + 2*(gravity + basec[0].xdd[3])*(-(baseo[0].q[1]*baseo[0].q[3]) + baseo[0].q[2]*baseo[0].q[4]);
a0[5]=basec[0].xdd[2]*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[3],2)) + 2*basec[0].xdd[1]*(baseo[0].q[2]*baseo[0].q[3] - baseo[0].q[1]*baseo[0].q[4]) + 2*(gravity + basec[0].xdd[3])*(baseo[0].q[1]*baseo[0].q[2] + baseo[0].q[3]*baseo[0].q[4]);
a0[6]=2*basec[0].xdd[1]*(baseo[0].q[1]*baseo[0].q[3] + baseo[0].q[2]*baseo[0].q[4]) + 2*basec[0].xdd[2]*(-(baseo[0].q[1]*baseo[0].q[2]) + baseo[0].q[3]*baseo[0].q[4]) + (gravity + basec[0].xdd[3])*(-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[4],2));

a1[1]=0.7071067811865475*cstate1th*a0[1] + sstate1th*a0[2] - 0.7071067811865475*cstate1th*a0[3] + state[1].thd*v1[2];
a1[2]=-0.7071067811865475*sstate1th*a0[1] + cstate1th*a0[2] + 0.7071067811865475*sstate1th*a0[3] - state[1].thd*v1[1];
a1[3]=state[1].thdd + 0.7071067811865475*a0[1] + 0.7071067811865475*a0[3];
a1[4]=-((l0*sstate1th*a0[1])/Sqrt(2)) + 0.9999999999999998*cstate1th*l0*a0[2] + (l0*sstate1th*a0[3])/Sqrt(2) + 0.7071067811865475*cstate1th*a0[4] + sstate1th*a0[5] - 0.7071067811865475*cstate1th*a0[6] + state[1].thd*v1[5];
a1[5]=-((cstate1th*l0*a0[1])/Sqrt(2)) - 0.9999999999999998*l0*sstate1th*a0[2] + (cstate1th*l0*a0[3])/Sqrt(2) - 0.7071067811865475*sstate1th*a0[4] + cstate1th*a0[5] + 0.7071067811865475*sstate1th*a0[6] - state[1].thd*v1[4];
a1[6]=0.7071067811865475*a0[4] + 0.7071067811865475*a0[6];

a2[1]=(0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th)*a1[1] + (-0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th)*a1[3] + state[2].thd*v2[2];
a2[2]=(-0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th)*a1[1] + (-0.7071067811865475*cstate2th + 0.7071067811865475*sstate2th)*a1[3] - state[2].thd*v2[1];
a2[3]=state[2].thdd + a1[2];
a2[4]=(0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th)*a1[4] + (-0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th)*a1[6] + state[2].thd*v2[5];
a2[5]=(-0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th)*a1[4] + (-0.7071067811865475*cstate2th + 0.7071067811865475*sstate2th)*a1[6] - state[2].thd*v2[4];
a2[6]=a1[5];

a3[1]=sstate3th*a2[2] - cstate3th*a2[3] + state[3].thd*v3[2];
a3[2]=cstate3th*a2[2] + sstate3th*a2[3] - state[3].thd*v3[1];
a3[3]=state[3].thdd + a2[1];
a3[4]=cstate3th*l1*a2[1] + sstate3th*a2[5] - cstate3th*a2[6] + state[3].thd*v3[5];
a3[5]=-(l1*sstate3th*a2[1]) + cstate3th*a2[5] + sstate3th*a2[6] - state[3].thd*v3[4];
a3[6]=l1*a2[3] + a2[4];

a4[1]=sstate4th*a3[1] - cstate4th*a3[3] + state[4].thd*v4[2];
a4[2]=cstate4th*a3[1] + sstate4th*a3[3] - state[4].thd*v4[1];
a4[3]=state[4].thdd - a3[2];
a4[4]=l2*sstate4th*a3[2] + sstate4th*a3[4] - cstate4th*a3[6] + state[4].thd*v4[5];
a4[5]=cstate4th*l2*a3[2] + cstate4th*a3[4] + sstate4th*a3[6] - state[4].thd*v4[4];
a4[6]=l2*a3[1] - a3[5];

a5[1]=sstate5th*a4[2] + cstate5th*a4[3] + state[5].thd*v5[2];
a5[2]=cstate5th*a4[2] - sstate5th*a4[3] - state[5].thd*v5[1];
a5[3]=state[5].thdd - a4[1];
a5[4]=l3*sstate5th*a4[1] + sstate5th*a4[5] + cstate5th*a4[6] + state[5].thd*v5[5];
a5[5]=cstate5th*l3*a4[1] + cstate5th*a4[5] - sstate5th*a4[6] - state[5].thd*v5[4];
a5[6]=l3*a4[2] - a4[4];

a6[1]=cstate6th*a5[1] - sstate6th*a5[3] + state[6].thd*v6[2];
a6[2]=-(sstate6th*a5[1]) - cstate6th*a5[3] - state[6].thd*v6[1];
a6[3]=state[6].thdd + a5[2];
a6[4]=cstate6th*l4*a5[2] + cstate6th*a5[4] - sstate6th*a5[6] + state[6].thd*v6[5];
a6[5]=-(l4*sstate6th*a5[2]) - sstate6th*a5[4] - cstate6th*a5[6] - state[6].thd*v6[4];
a6[6]=-(l4*a5[1]) + a5[5];

a7[1]=-(sstate7th*a6[2]) + cstate7th*a6[3] + state[7].thd*v7[2];
a7[2]=-(cstate7th*a6[2]) - sstate7th*a6[3] - state[7].thd*v7[1];
a7[3]=state[7].thdd + a6[1];
a7[4]=l5*sstate7th*a6[1] - sstate7th*a6[5] + cstate7th*a6[6] + state[7].thd*v7[5];
a7[5]=cstate7th*l5*a6[1] - cstate7th*a6[5] - sstate7th*a6[6] - state[7].thd*v7[4];
a7[6]=l5*a6[2] + a6[4];

a8[1]=rceff1a2*rceff1a3*a7[1] + (rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3)*a7[2] + (-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3)*a7[3];
a8[2]=-(rceff1a2*rseff1a3*a7[1]) + (rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3)*a7[2] + (rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3)*a7[3];
a8[3]=rseff1a2*a7[1] - rceff1a2*rseff1a1*a7[2] + rceff1a1*rceff1a2*a7[3];
a8[4]=rceff1a2*rceff1a3*a7[4] + (rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3)*a7[5] + (-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3)*a7[6] + a7[3]*((rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3)*eff[1].x[1] - rceff1a2*rceff1a3*eff[1].x[2]) + a7[2]*(-((-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3)*eff[1].x[1]) + rceff1a2*rceff1a3*eff[1].x[3]) + a7[1]*((-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3)*eff[1].x[2] - (rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3)*eff[1].x[3]);
a8[5]=-(rceff1a2*rseff1a3*a7[4]) + (rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3)*a7[5] + (rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3)*a7[6] + a7[3]*((rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3)*eff[1].x[1] + rceff1a2*rseff1a3*eff[1].x[2]) + a7[2]*(-((rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3)*eff[1].x[1]) - rceff1a2*rseff1a3*eff[1].x[3]) + a7[1]*((rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3)*eff[1].x[2] - (rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3)*eff[1].x[3]);
a8[6]=rseff1a2*a7[4] - rceff1a2*rseff1a1*a7[5] + rceff1a1*rceff1a2*a7[6] + a7[3]*(-(rceff1a2*rseff1a1*eff[1].x[1]) - rseff1a2*eff[1].x[2]) + a7[1]*(rceff1a1*rceff1a2*eff[1].x[2] + rceff1a2*rseff1a1*eff[1].x[3]) + a7[2]*(-(rceff1a1*rceff1a2*eff[1].x[1]) + rseff1a2*eff[1].x[3]);

a9[1]=sstate8th*a7[2] + cstate8th*a7[3] + state[8].thd*v9[2];
a9[2]=cstate8th*a7[2] - sstate8th*a7[3] - state[8].thd*v9[1];
a9[3]=state[8].thdd - a7[1];
a9[4]=-(l7z*sstate8th*a7[1]) + cstate8th*l6x*a7[2] - l6x*sstate8th*a7[3] + sstate8th*a7[5] + cstate8th*a7[6] + state[8].thd*v9[5];
a9[5]=-(cstate8th*l7z*a7[1]) - l6x*sstate8th*a7[2] - cstate8th*l6x*a7[3] + cstate8th*a7[5] - sstate8th*a7[6] - state[8].thd*v9[4];
a9[6]=-(l7z*a7[2]) - a7[4];

a10[1]=sstate9th*a9[2] - cstate9th*a9[3] + state[9].thd*v10[2];
a10[2]=cstate9th*a9[2] + sstate9th*a9[3] - state[9].thd*v10[1];
a10[3]=state[9].thdd + a9[1];
a10[4]=sstate9th*a9[5] - cstate9th*a9[6] + state[9].thd*v10[5];
a10[5]=cstate9th*a9[5] + sstate9th*a9[6] - state[9].thd*v10[4];
a10[6]=a9[4];

a11[1]=a10[1];
a11[2]=a10[2];
a11[3]=a10[3];
a11[4]=-(l8*a10[3]) + a10[4];
a11[5]=a10[5];
a11[6]=l8*a10[1] + a10[6];

a12[1]=cstate10th*a7[1] + sstate10th*a7[2] + state[10].thd*v12[2];
a12[2]=-(sstate10th*a7[1]) + cstate10th*a7[2] - state[10].thd*v12[1];
a12[3]=state[10].thdd + a7[3];
a12[4]=-(l6z*sstate10th*a7[1]) + cstate10th*l6z*a7[2] + (-(cstate10th*l6y) - l6x*sstate10th)*a7[3] + cstate10th*a7[4] + sstate10th*a7[5] + state[10].thd*v12[5];
a12[5]=-(cstate10th*l6z*a7[1]) - l6z*sstate10th*a7[2] + (-(cstate10th*l6x) + l6y*sstate10th)*a7[3] - sstate10th*a7[4] + cstate10th*a7[5] - state[10].thd*v12[4];
a12[6]=l6y*a7[1] + l6x*a7[2] + a7[6];

a13[1]=a12[1];
a13[2]=a12[2];
a13[3]=a12[3];
a13[4]=-(l9*a12[3]) + a12[4];
a13[5]=a12[5];
a13[6]=l9*a12[1] + a12[6];


/* kinematic matrices */
bzero((void *)A,sizeof(double)*(13+1)*(6+1)*(N_RBD_PARMS+1));
A[0][1][1]=a0[4] - v0[3]*v0[5] + v0[2]*v0[6];
A[0][1][2]=-Power(v0[2],2) - Power(v0[3],2);
A[0][1][3]=-a0[3] + v0[1]*v0[2];
A[0][1][4]=a0[2] + v0[1]*v0[3];
A[0][1][5]=0;
A[0][1][6]=0;
A[0][1][7]=0;
A[0][1][8]=0;
A[0][1][9]=0;
A[0][1][10]=0;
A[0][1][11]=0;
A[0][1][12]=0;
A[0][1][13]=0;
A[0][1][14]=0;

A[0][2][1]=a0[5] + v0[3]*v0[4] - v0[1]*v0[6];
A[0][2][2]=a0[3] + v0[1]*v0[2];
A[0][2][3]=-Power(v0[1],2) - Power(v0[3],2);
A[0][2][4]=-a0[1] + v0[2]*v0[3];
A[0][2][5]=0;
A[0][2][6]=0;
A[0][2][7]=0;
A[0][2][8]=0;
A[0][2][9]=0;
A[0][2][10]=0;
A[0][2][11]=0;
A[0][2][12]=0;
A[0][2][13]=0;
A[0][2][14]=0;

A[0][3][1]=a0[6] - v0[2]*v0[4] + v0[1]*v0[5];
A[0][3][2]=-a0[2] + v0[1]*v0[3];
A[0][3][3]=a0[1] + v0[2]*v0[3];
A[0][3][4]=-Power(v0[1],2) - Power(v0[2],2);
A[0][3][5]=0;
A[0][3][6]=0;
A[0][3][7]=0;
A[0][3][8]=0;
A[0][3][9]=0;
A[0][3][10]=0;
A[0][3][11]=0;
A[0][3][12]=0;
A[0][3][13]=0;
A[0][3][14]=0;

A[0][4][1]=0;
A[0][4][2]=0;
A[0][4][3]=a0[6] - v0[2]*v0[4] + v0[1]*v0[5];
A[0][4][4]=-a0[5] - v0[3]*v0[4] + v0[1]*v0[6];
A[0][4][5]=a0[1];
A[0][4][6]=a0[2] - v0[1]*v0[3];
A[0][4][7]=a0[3] + v0[1]*v0[2];
A[0][4][8]=-(v0[2]*v0[3]);
A[0][4][9]=Power(v0[2],2) - Power(v0[3],2);
A[0][4][10]=v0[2]*v0[3];
A[0][4][11]=0;
A[0][4][12]=0;
A[0][4][13]=0;
A[0][4][14]=0;

A[0][5][1]=0;
A[0][5][2]=-a0[6] + v0[2]*v0[4] - v0[1]*v0[5];
A[0][5][3]=0;
A[0][5][4]=a0[4] - v0[3]*v0[5] + v0[2]*v0[6];
A[0][5][5]=v0[1]*v0[3];
A[0][5][6]=a0[1] + v0[2]*v0[3];
A[0][5][7]=-Power(v0[1],2) + Power(v0[3],2);
A[0][5][8]=a0[2];
A[0][5][9]=a0[3] - v0[1]*v0[2];
A[0][5][10]=-(v0[1]*v0[3]);
A[0][5][11]=0;
A[0][5][12]=0;
A[0][5][13]=0;
A[0][5][14]=0;

A[0][6][1]=0;
A[0][6][2]=a0[5] + v0[3]*v0[4] - v0[1]*v0[6];
A[0][6][3]=-a0[4] + v0[3]*v0[5] - v0[2]*v0[6];
A[0][6][4]=0;
A[0][6][5]=-(v0[1]*v0[2]);
A[0][6][6]=Power(v0[1],2) - Power(v0[2],2);
A[0][6][7]=a0[1] - v0[2]*v0[3];
A[0][6][8]=v0[1]*v0[2];
A[0][6][9]=a0[2] + v0[1]*v0[3];
A[0][6][10]=a0[3];
A[0][6][11]=0;
A[0][6][12]=0;
A[0][6][13]=0;
A[0][6][14]=0;


A[1][1][1]=a1[4] - v1[3]*v1[5] + v1[2]*v1[6];
A[1][1][2]=-Power(v1[2],2) - Power(v1[3],2);
A[1][1][3]=-a1[3] + v1[1]*v1[2];
A[1][1][4]=a1[2] + v1[1]*v1[3];
A[1][1][5]=0;
A[1][1][6]=0;
A[1][1][7]=0;
A[1][1][8]=0;
A[1][1][9]=0;
A[1][1][10]=0;
A[1][1][11]=0;
A[1][1][12]=0;
A[1][1][13]=0;
A[1][1][14]=0;

A[1][2][1]=a1[5] + v1[3]*v1[4] - v1[1]*v1[6];
A[1][2][2]=a1[3] + v1[1]*v1[2];
A[1][2][3]=-Power(v1[1],2) - Power(v1[3],2);
A[1][2][4]=-a1[1] + v1[2]*v1[3];
A[1][2][5]=0;
A[1][2][6]=0;
A[1][2][7]=0;
A[1][2][8]=0;
A[1][2][9]=0;
A[1][2][10]=0;
A[1][2][11]=0;
A[1][2][12]=0;
A[1][2][13]=0;
A[1][2][14]=0;

A[1][3][1]=a1[6] - v1[2]*v1[4] + v1[1]*v1[5];
A[1][3][2]=-a1[2] + v1[1]*v1[3];
A[1][3][3]=a1[1] + v1[2]*v1[3];
A[1][3][4]=-Power(v1[1],2) - Power(v1[2],2);
A[1][3][5]=0;
A[1][3][6]=0;
A[1][3][7]=0;
A[1][3][8]=0;
A[1][3][9]=0;
A[1][3][10]=0;
A[1][3][11]=0;
A[1][3][12]=0;
A[1][3][13]=0;
A[1][3][14]=0;

A[1][4][1]=0;
A[1][4][2]=0;
A[1][4][3]=a1[6] - v1[2]*v1[4] + v1[1]*v1[5];
A[1][4][4]=-a1[5] - v1[3]*v1[4] + v1[1]*v1[6];
A[1][4][5]=a1[1];
A[1][4][6]=a1[2] - v1[1]*v1[3];
A[1][4][7]=a1[3] + v1[1]*v1[2];
A[1][4][8]=-(v1[2]*v1[3]);
A[1][4][9]=Power(v1[2],2) - Power(v1[3],2);
A[1][4][10]=v1[2]*v1[3];
A[1][4][11]=0;
A[1][4][12]=0;
A[1][4][13]=0;
A[1][4][14]=0;

A[1][5][1]=0;
A[1][5][2]=-a1[6] + v1[2]*v1[4] - v1[1]*v1[5];
A[1][5][3]=0;
A[1][5][4]=a1[4] - v1[3]*v1[5] + v1[2]*v1[6];
A[1][5][5]=v1[1]*v1[3];
A[1][5][6]=a1[1] + v1[2]*v1[3];
A[1][5][7]=-Power(v1[1],2) + Power(v1[3],2);
A[1][5][8]=a1[2];
A[1][5][9]=a1[3] - v1[1]*v1[2];
A[1][5][10]=-(v1[1]*v1[3]);
A[1][5][11]=0;
A[1][5][12]=0;
A[1][5][13]=0;
A[1][5][14]=0;

A[1][6][1]=0;
A[1][6][2]=a1[5] + v1[3]*v1[4] - v1[1]*v1[6];
A[1][6][3]=-a1[4] + v1[3]*v1[5] - v1[2]*v1[6];
A[1][6][4]=0;
A[1][6][5]=-(v1[1]*v1[2]);
A[1][6][6]=Power(v1[1],2) - Power(v1[2],2);
A[1][6][7]=a1[1] - v1[2]*v1[3];
A[1][6][8]=v1[1]*v1[2];
A[1][6][9]=a1[2] + v1[1]*v1[3];
A[1][6][10]=a1[3];
A[1][6][11]=0;
A[1][6][12]=0;
A[1][6][13]=0;
A[1][6][14]=0;


A[2][1][1]=a2[4] - v2[3]*v2[5] + v2[2]*v2[6];
A[2][1][2]=-Power(v2[2],2) - Power(v2[3],2);
A[2][1][3]=-a2[3] + v2[1]*v2[2];
A[2][1][4]=a2[2] + v2[1]*v2[3];
A[2][1][5]=0;
A[2][1][6]=0;
A[2][1][7]=0;
A[2][1][8]=0;
A[2][1][9]=0;
A[2][1][10]=0;
A[2][1][11]=0;
A[2][1][12]=0;
A[2][1][13]=0;
A[2][1][14]=0;

A[2][2][1]=a2[5] + v2[3]*v2[4] - v2[1]*v2[6];
A[2][2][2]=a2[3] + v2[1]*v2[2];
A[2][2][3]=-Power(v2[1],2) - Power(v2[3],2);
A[2][2][4]=-a2[1] + v2[2]*v2[3];
A[2][2][5]=0;
A[2][2][6]=0;
A[2][2][7]=0;
A[2][2][8]=0;
A[2][2][9]=0;
A[2][2][10]=0;
A[2][2][11]=0;
A[2][2][12]=0;
A[2][2][13]=0;
A[2][2][14]=0;

A[2][3][1]=a2[6] - v2[2]*v2[4] + v2[1]*v2[5];
A[2][3][2]=-a2[2] + v2[1]*v2[3];
A[2][3][3]=a2[1] + v2[2]*v2[3];
A[2][3][4]=-Power(v2[1],2) - Power(v2[2],2);
A[2][3][5]=0;
A[2][3][6]=0;
A[2][3][7]=0;
A[2][3][8]=0;
A[2][3][9]=0;
A[2][3][10]=0;
A[2][3][11]=0;
A[2][3][12]=0;
A[2][3][13]=0;
A[2][3][14]=0;

A[2][4][1]=0;
A[2][4][2]=0;
A[2][4][3]=a2[6] - v2[2]*v2[4] + v2[1]*v2[5];
A[2][4][4]=-a2[5] - v2[3]*v2[4] + v2[1]*v2[6];
A[2][4][5]=a2[1];
A[2][4][6]=a2[2] - v2[1]*v2[3];
A[2][4][7]=a2[3] + v2[1]*v2[2];
A[2][4][8]=-(v2[2]*v2[3]);
A[2][4][9]=Power(v2[2],2) - Power(v2[3],2);
A[2][4][10]=v2[2]*v2[3];
A[2][4][11]=0;
A[2][4][12]=0;
A[2][4][13]=0;
A[2][4][14]=0;

A[2][5][1]=0;
A[2][5][2]=-a2[6] + v2[2]*v2[4] - v2[1]*v2[5];
A[2][5][3]=0;
A[2][5][4]=a2[4] - v2[3]*v2[5] + v2[2]*v2[6];
A[2][5][5]=v2[1]*v2[3];
A[2][5][6]=a2[1] + v2[2]*v2[3];
A[2][5][7]=-Power(v2[1],2) + Power(v2[3],2);
A[2][5][8]=a2[2];
A[2][5][9]=a2[3] - v2[1]*v2[2];
A[2][5][10]=-(v2[1]*v2[3]);
A[2][5][11]=0;
A[2][5][12]=0;
A[2][5][13]=0;
A[2][5][14]=0;

A[2][6][1]=0;
A[2][6][2]=a2[5] + v2[3]*v2[4] - v2[1]*v2[6];
A[2][6][3]=-a2[4] + v2[3]*v2[5] - v2[2]*v2[6];
A[2][6][4]=0;
A[2][6][5]=-(v2[1]*v2[2]);
A[2][6][6]=Power(v2[1],2) - Power(v2[2],2);
A[2][6][7]=a2[1] - v2[2]*v2[3];
A[2][6][8]=v2[1]*v2[2];
A[2][6][9]=a2[2] + v2[1]*v2[3];
A[2][6][10]=a2[3];
A[2][6][11]=0;
A[2][6][12]=0;
A[2][6][13]=0;
A[2][6][14]=0;


A[3][1][1]=a3[4] - v3[3]*v3[5] + v3[2]*v3[6];
A[3][1][2]=-Power(v3[2],2) - Power(v3[3],2);
A[3][1][3]=-a3[3] + v3[1]*v3[2];
A[3][1][4]=a3[2] + v3[1]*v3[3];
A[3][1][5]=0;
A[3][1][6]=0;
A[3][1][7]=0;
A[3][1][8]=0;
A[3][1][9]=0;
A[3][1][10]=0;
A[3][1][11]=0;
A[3][1][12]=0;
A[3][1][13]=0;
A[3][1][14]=0;

A[3][2][1]=a3[5] + v3[3]*v3[4] - v3[1]*v3[6];
A[3][2][2]=a3[3] + v3[1]*v3[2];
A[3][2][3]=-Power(v3[1],2) - Power(v3[3],2);
A[3][2][4]=-a3[1] + v3[2]*v3[3];
A[3][2][5]=0;
A[3][2][6]=0;
A[3][2][7]=0;
A[3][2][8]=0;
A[3][2][9]=0;
A[3][2][10]=0;
A[3][2][11]=0;
A[3][2][12]=0;
A[3][2][13]=0;
A[3][2][14]=0;

A[3][3][1]=a3[6] - v3[2]*v3[4] + v3[1]*v3[5];
A[3][3][2]=-a3[2] + v3[1]*v3[3];
A[3][3][3]=a3[1] + v3[2]*v3[3];
A[3][3][4]=-Power(v3[1],2) - Power(v3[2],2);
A[3][3][5]=0;
A[3][3][6]=0;
A[3][3][7]=0;
A[3][3][8]=0;
A[3][3][9]=0;
A[3][3][10]=0;
A[3][3][11]=0;
A[3][3][12]=0;
A[3][3][13]=0;
A[3][3][14]=0;

A[3][4][1]=0;
A[3][4][2]=0;
A[3][4][3]=a3[6] - v3[2]*v3[4] + v3[1]*v3[5];
A[3][4][4]=-a3[5] - v3[3]*v3[4] + v3[1]*v3[6];
A[3][4][5]=a3[1];
A[3][4][6]=a3[2] - v3[1]*v3[3];
A[3][4][7]=a3[3] + v3[1]*v3[2];
A[3][4][8]=-(v3[2]*v3[3]);
A[3][4][9]=Power(v3[2],2) - Power(v3[3],2);
A[3][4][10]=v3[2]*v3[3];
A[3][4][11]=0;
A[3][4][12]=0;
A[3][4][13]=0;
A[3][4][14]=0;

A[3][5][1]=0;
A[3][5][2]=-a3[6] + v3[2]*v3[4] - v3[1]*v3[5];
A[3][5][3]=0;
A[3][5][4]=a3[4] - v3[3]*v3[5] + v3[2]*v3[6];
A[3][5][5]=v3[1]*v3[3];
A[3][5][6]=a3[1] + v3[2]*v3[3];
A[3][5][7]=-Power(v3[1],2) + Power(v3[3],2);
A[3][5][8]=a3[2];
A[3][5][9]=a3[3] - v3[1]*v3[2];
A[3][5][10]=-(v3[1]*v3[3]);
A[3][5][11]=0;
A[3][5][12]=0;
A[3][5][13]=0;
A[3][5][14]=0;

A[3][6][1]=0;
A[3][6][2]=a3[5] + v3[3]*v3[4] - v3[1]*v3[6];
A[3][6][3]=-a3[4] + v3[3]*v3[5] - v3[2]*v3[6];
A[3][6][4]=0;
A[3][6][5]=-(v3[1]*v3[2]);
A[3][6][6]=Power(v3[1],2) - Power(v3[2],2);
A[3][6][7]=a3[1] - v3[2]*v3[3];
A[3][6][8]=v3[1]*v3[2];
A[3][6][9]=a3[2] + v3[1]*v3[3];
A[3][6][10]=a3[3];
A[3][6][11]=0;
A[3][6][12]=0;
A[3][6][13]=0;
A[3][6][14]=0;


A[4][1][1]=a4[4] - v4[3]*v4[5] + v4[2]*v4[6];
A[4][1][2]=-Power(v4[2],2) - Power(v4[3],2);
A[4][1][3]=-a4[3] + v4[1]*v4[2];
A[4][1][4]=a4[2] + v4[1]*v4[3];
A[4][1][5]=0;
A[4][1][6]=0;
A[4][1][7]=0;
A[4][1][8]=0;
A[4][1][9]=0;
A[4][1][10]=0;
A[4][1][11]=0;
A[4][1][12]=0;
A[4][1][13]=0;
A[4][1][14]=0;

A[4][2][1]=a4[5] + v4[3]*v4[4] - v4[1]*v4[6];
A[4][2][2]=a4[3] + v4[1]*v4[2];
A[4][2][3]=-Power(v4[1],2) - Power(v4[3],2);
A[4][2][4]=-a4[1] + v4[2]*v4[3];
A[4][2][5]=0;
A[4][2][6]=0;
A[4][2][7]=0;
A[4][2][8]=0;
A[4][2][9]=0;
A[4][2][10]=0;
A[4][2][11]=0;
A[4][2][12]=0;
A[4][2][13]=0;
A[4][2][14]=0;

A[4][3][1]=a4[6] - v4[2]*v4[4] + v4[1]*v4[5];
A[4][3][2]=-a4[2] + v4[1]*v4[3];
A[4][3][3]=a4[1] + v4[2]*v4[3];
A[4][3][4]=-Power(v4[1],2) - Power(v4[2],2);
A[4][3][5]=0;
A[4][3][6]=0;
A[4][3][7]=0;
A[4][3][8]=0;
A[4][3][9]=0;
A[4][3][10]=0;
A[4][3][11]=0;
A[4][3][12]=0;
A[4][3][13]=0;
A[4][3][14]=0;

A[4][4][1]=0;
A[4][4][2]=0;
A[4][4][3]=a4[6] - v4[2]*v4[4] + v4[1]*v4[5];
A[4][4][4]=-a4[5] - v4[3]*v4[4] + v4[1]*v4[6];
A[4][4][5]=a4[1];
A[4][4][6]=a4[2] - v4[1]*v4[3];
A[4][4][7]=a4[3] + v4[1]*v4[2];
A[4][4][8]=-(v4[2]*v4[3]);
A[4][4][9]=Power(v4[2],2) - Power(v4[3],2);
A[4][4][10]=v4[2]*v4[3];
A[4][4][11]=0;
A[4][4][12]=0;
A[4][4][13]=0;
A[4][4][14]=0;

A[4][5][1]=0;
A[4][5][2]=-a4[6] + v4[2]*v4[4] - v4[1]*v4[5];
A[4][5][3]=0;
A[4][5][4]=a4[4] - v4[3]*v4[5] + v4[2]*v4[6];
A[4][5][5]=v4[1]*v4[3];
A[4][5][6]=a4[1] + v4[2]*v4[3];
A[4][5][7]=-Power(v4[1],2) + Power(v4[3],2);
A[4][5][8]=a4[2];
A[4][5][9]=a4[3] - v4[1]*v4[2];
A[4][5][10]=-(v4[1]*v4[3]);
A[4][5][11]=0;
A[4][5][12]=0;
A[4][5][13]=0;
A[4][5][14]=0;

A[4][6][1]=0;
A[4][6][2]=a4[5] + v4[3]*v4[4] - v4[1]*v4[6];
A[4][6][3]=-a4[4] + v4[3]*v4[5] - v4[2]*v4[6];
A[4][6][4]=0;
A[4][6][5]=-(v4[1]*v4[2]);
A[4][6][6]=Power(v4[1],2) - Power(v4[2],2);
A[4][6][7]=a4[1] - v4[2]*v4[3];
A[4][6][8]=v4[1]*v4[2];
A[4][6][9]=a4[2] + v4[1]*v4[3];
A[4][6][10]=a4[3];
A[4][6][11]=0;
A[4][6][12]=0;
A[4][6][13]=0;
A[4][6][14]=0;


A[5][1][1]=a5[4] - v5[3]*v5[5] + v5[2]*v5[6];
A[5][1][2]=-Power(v5[2],2) - Power(v5[3],2);
A[5][1][3]=-a5[3] + v5[1]*v5[2];
A[5][1][4]=a5[2] + v5[1]*v5[3];
A[5][1][5]=0;
A[5][1][6]=0;
A[5][1][7]=0;
A[5][1][8]=0;
A[5][1][9]=0;
A[5][1][10]=0;
A[5][1][11]=0;
A[5][1][12]=0;
A[5][1][13]=0;
A[5][1][14]=0;

A[5][2][1]=a5[5] + v5[3]*v5[4] - v5[1]*v5[6];
A[5][2][2]=a5[3] + v5[1]*v5[2];
A[5][2][3]=-Power(v5[1],2) - Power(v5[3],2);
A[5][2][4]=-a5[1] + v5[2]*v5[3];
A[5][2][5]=0;
A[5][2][6]=0;
A[5][2][7]=0;
A[5][2][8]=0;
A[5][2][9]=0;
A[5][2][10]=0;
A[5][2][11]=0;
A[5][2][12]=0;
A[5][2][13]=0;
A[5][2][14]=0;

A[5][3][1]=a5[6] - v5[2]*v5[4] + v5[1]*v5[5];
A[5][3][2]=-a5[2] + v5[1]*v5[3];
A[5][3][3]=a5[1] + v5[2]*v5[3];
A[5][3][4]=-Power(v5[1],2) - Power(v5[2],2);
A[5][3][5]=0;
A[5][3][6]=0;
A[5][3][7]=0;
A[5][3][8]=0;
A[5][3][9]=0;
A[5][3][10]=0;
A[5][3][11]=0;
A[5][3][12]=0;
A[5][3][13]=0;
A[5][3][14]=0;

A[5][4][1]=0;
A[5][4][2]=0;
A[5][4][3]=a5[6] - v5[2]*v5[4] + v5[1]*v5[5];
A[5][4][4]=-a5[5] - v5[3]*v5[4] + v5[1]*v5[6];
A[5][4][5]=a5[1];
A[5][4][6]=a5[2] - v5[1]*v5[3];
A[5][4][7]=a5[3] + v5[1]*v5[2];
A[5][4][8]=-(v5[2]*v5[3]);
A[5][4][9]=Power(v5[2],2) - Power(v5[3],2);
A[5][4][10]=v5[2]*v5[3];
A[5][4][11]=0;
A[5][4][12]=0;
A[5][4][13]=0;
A[5][4][14]=0;

A[5][5][1]=0;
A[5][5][2]=-a5[6] + v5[2]*v5[4] - v5[1]*v5[5];
A[5][5][3]=0;
A[5][5][4]=a5[4] - v5[3]*v5[5] + v5[2]*v5[6];
A[5][5][5]=v5[1]*v5[3];
A[5][5][6]=a5[1] + v5[2]*v5[3];
A[5][5][7]=-Power(v5[1],2) + Power(v5[3],2);
A[5][5][8]=a5[2];
A[5][5][9]=a5[3] - v5[1]*v5[2];
A[5][5][10]=-(v5[1]*v5[3]);
A[5][5][11]=0;
A[5][5][12]=0;
A[5][5][13]=0;
A[5][5][14]=0;

A[5][6][1]=0;
A[5][6][2]=a5[5] + v5[3]*v5[4] - v5[1]*v5[6];
A[5][6][3]=-a5[4] + v5[3]*v5[5] - v5[2]*v5[6];
A[5][6][4]=0;
A[5][6][5]=-(v5[1]*v5[2]);
A[5][6][6]=Power(v5[1],2) - Power(v5[2],2);
A[5][6][7]=a5[1] - v5[2]*v5[3];
A[5][6][8]=v5[1]*v5[2];
A[5][6][9]=a5[2] + v5[1]*v5[3];
A[5][6][10]=a5[3];
A[5][6][11]=0;
A[5][6][12]=0;
A[5][6][13]=0;
A[5][6][14]=0;


A[6][1][1]=a6[4] - v6[3]*v6[5] + v6[2]*v6[6];
A[6][1][2]=-Power(v6[2],2) - Power(v6[3],2);
A[6][1][3]=-a6[3] + v6[1]*v6[2];
A[6][1][4]=a6[2] + v6[1]*v6[3];
A[6][1][5]=0;
A[6][1][6]=0;
A[6][1][7]=0;
A[6][1][8]=0;
A[6][1][9]=0;
A[6][1][10]=0;
A[6][1][11]=0;
A[6][1][12]=0;
A[6][1][13]=0;
A[6][1][14]=0;

A[6][2][1]=a6[5] + v6[3]*v6[4] - v6[1]*v6[6];
A[6][2][2]=a6[3] + v6[1]*v6[2];
A[6][2][3]=-Power(v6[1],2) - Power(v6[3],2);
A[6][2][4]=-a6[1] + v6[2]*v6[3];
A[6][2][5]=0;
A[6][2][6]=0;
A[6][2][7]=0;
A[6][2][8]=0;
A[6][2][9]=0;
A[6][2][10]=0;
A[6][2][11]=0;
A[6][2][12]=0;
A[6][2][13]=0;
A[6][2][14]=0;

A[6][3][1]=a6[6] - v6[2]*v6[4] + v6[1]*v6[5];
A[6][3][2]=-a6[2] + v6[1]*v6[3];
A[6][3][3]=a6[1] + v6[2]*v6[3];
A[6][3][4]=-Power(v6[1],2) - Power(v6[2],2);
A[6][3][5]=0;
A[6][3][6]=0;
A[6][3][7]=0;
A[6][3][8]=0;
A[6][3][9]=0;
A[6][3][10]=0;
A[6][3][11]=0;
A[6][3][12]=0;
A[6][3][13]=0;
A[6][3][14]=0;

A[6][4][1]=0;
A[6][4][2]=0;
A[6][4][3]=a6[6] - v6[2]*v6[4] + v6[1]*v6[5];
A[6][4][4]=-a6[5] - v6[3]*v6[4] + v6[1]*v6[6];
A[6][4][5]=a6[1];
A[6][4][6]=a6[2] - v6[1]*v6[3];
A[6][4][7]=a6[3] + v6[1]*v6[2];
A[6][4][8]=-(v6[2]*v6[3]);
A[6][4][9]=Power(v6[2],2) - Power(v6[3],2);
A[6][4][10]=v6[2]*v6[3];
A[6][4][11]=0;
A[6][4][12]=0;
A[6][4][13]=0;
A[6][4][14]=0;

A[6][5][1]=0;
A[6][5][2]=-a6[6] + v6[2]*v6[4] - v6[1]*v6[5];
A[6][5][3]=0;
A[6][5][4]=a6[4] - v6[3]*v6[5] + v6[2]*v6[6];
A[6][5][5]=v6[1]*v6[3];
A[6][5][6]=a6[1] + v6[2]*v6[3];
A[6][5][7]=-Power(v6[1],2) + Power(v6[3],2);
A[6][5][8]=a6[2];
A[6][5][9]=a6[3] - v6[1]*v6[2];
A[6][5][10]=-(v6[1]*v6[3]);
A[6][5][11]=0;
A[6][5][12]=0;
A[6][5][13]=0;
A[6][5][14]=0;

A[6][6][1]=0;
A[6][6][2]=a6[5] + v6[3]*v6[4] - v6[1]*v6[6];
A[6][6][3]=-a6[4] + v6[3]*v6[5] - v6[2]*v6[6];
A[6][6][4]=0;
A[6][6][5]=-(v6[1]*v6[2]);
A[6][6][6]=Power(v6[1],2) - Power(v6[2],2);
A[6][6][7]=a6[1] - v6[2]*v6[3];
A[6][6][8]=v6[1]*v6[2];
A[6][6][9]=a6[2] + v6[1]*v6[3];
A[6][6][10]=a6[3];
A[6][6][11]=0;
A[6][6][12]=0;
A[6][6][13]=0;
A[6][6][14]=0;


A[7][1][1]=a7[4] - v7[3]*v7[5] + v7[2]*v7[6];
A[7][1][2]=-Power(v7[2],2) - Power(v7[3],2);
A[7][1][3]=-a7[3] + v7[1]*v7[2];
A[7][1][4]=a7[2] + v7[1]*v7[3];
A[7][1][5]=0;
A[7][1][6]=0;
A[7][1][7]=0;
A[7][1][8]=0;
A[7][1][9]=0;
A[7][1][10]=0;
A[7][1][11]=0;
A[7][1][12]=0;
A[7][1][13]=0;
A[7][1][14]=0;

A[7][2][1]=a7[5] + v7[3]*v7[4] - v7[1]*v7[6];
A[7][2][2]=a7[3] + v7[1]*v7[2];
A[7][2][3]=-Power(v7[1],2) - Power(v7[3],2);
A[7][2][4]=-a7[1] + v7[2]*v7[3];
A[7][2][5]=0;
A[7][2][6]=0;
A[7][2][7]=0;
A[7][2][8]=0;
A[7][2][9]=0;
A[7][2][10]=0;
A[7][2][11]=0;
A[7][2][12]=0;
A[7][2][13]=0;
A[7][2][14]=0;

A[7][3][1]=a7[6] - v7[2]*v7[4] + v7[1]*v7[5];
A[7][3][2]=-a7[2] + v7[1]*v7[3];
A[7][3][3]=a7[1] + v7[2]*v7[3];
A[7][3][4]=-Power(v7[1],2) - Power(v7[2],2);
A[7][3][5]=0;
A[7][3][6]=0;
A[7][3][7]=0;
A[7][3][8]=0;
A[7][3][9]=0;
A[7][3][10]=0;
A[7][3][11]=0;
A[7][3][12]=0;
A[7][3][13]=0;
A[7][3][14]=0;

A[7][4][1]=0;
A[7][4][2]=0;
A[7][4][3]=a7[6] - v7[2]*v7[4] + v7[1]*v7[5];
A[7][4][4]=-a7[5] - v7[3]*v7[4] + v7[1]*v7[6];
A[7][4][5]=a7[1];
A[7][4][6]=a7[2] - v7[1]*v7[3];
A[7][4][7]=a7[3] + v7[1]*v7[2];
A[7][4][8]=-(v7[2]*v7[3]);
A[7][4][9]=Power(v7[2],2) - Power(v7[3],2);
A[7][4][10]=v7[2]*v7[3];
A[7][4][11]=0;
A[7][4][12]=0;
A[7][4][13]=0;
A[7][4][14]=0;

A[7][5][1]=0;
A[7][5][2]=-a7[6] + v7[2]*v7[4] - v7[1]*v7[5];
A[7][5][3]=0;
A[7][5][4]=a7[4] - v7[3]*v7[5] + v7[2]*v7[6];
A[7][5][5]=v7[1]*v7[3];
A[7][5][6]=a7[1] + v7[2]*v7[3];
A[7][5][7]=-Power(v7[1],2) + Power(v7[3],2);
A[7][5][8]=a7[2];
A[7][5][9]=a7[3] - v7[1]*v7[2];
A[7][5][10]=-(v7[1]*v7[3]);
A[7][5][11]=0;
A[7][5][12]=0;
A[7][5][13]=0;
A[7][5][14]=0;

A[7][6][1]=0;
A[7][6][2]=a7[5] + v7[3]*v7[4] - v7[1]*v7[6];
A[7][6][3]=-a7[4] + v7[3]*v7[5] - v7[2]*v7[6];
A[7][6][4]=0;
A[7][6][5]=-(v7[1]*v7[2]);
A[7][6][6]=Power(v7[1],2) - Power(v7[2],2);
A[7][6][7]=a7[1] - v7[2]*v7[3];
A[7][6][8]=v7[1]*v7[2];
A[7][6][9]=a7[2] + v7[1]*v7[3];
A[7][6][10]=a7[3];
A[7][6][11]=0;
A[7][6][12]=0;
A[7][6][13]=0;
A[7][6][14]=0;


A[8][1][1]=a8[4] - v8[3]*v8[5] + v8[2]*v8[6];
A[8][1][2]=-Power(v8[2],2) - Power(v8[3],2);
A[8][1][3]=-a8[3] + v8[1]*v8[2];
A[8][1][4]=a8[2] + v8[1]*v8[3];
A[8][1][5]=0;
A[8][1][6]=0;
A[8][1][7]=0;
A[8][1][8]=0;
A[8][1][9]=0;
A[8][1][10]=0;
A[8][1][11]=0;
A[8][1][12]=0;
A[8][1][13]=0;
A[8][1][14]=0;

A[8][2][1]=a8[5] + v8[3]*v8[4] - v8[1]*v8[6];
A[8][2][2]=a8[3] + v8[1]*v8[2];
A[8][2][3]=-Power(v8[1],2) - Power(v8[3],2);
A[8][2][4]=-a8[1] + v8[2]*v8[3];
A[8][2][5]=0;
A[8][2][6]=0;
A[8][2][7]=0;
A[8][2][8]=0;
A[8][2][9]=0;
A[8][2][10]=0;
A[8][2][11]=0;
A[8][2][12]=0;
A[8][2][13]=0;
A[8][2][14]=0;

A[8][3][1]=a8[6] - v8[2]*v8[4] + v8[1]*v8[5];
A[8][3][2]=-a8[2] + v8[1]*v8[3];
A[8][3][3]=a8[1] + v8[2]*v8[3];
A[8][3][4]=-Power(v8[1],2) - Power(v8[2],2);
A[8][3][5]=0;
A[8][3][6]=0;
A[8][3][7]=0;
A[8][3][8]=0;
A[8][3][9]=0;
A[8][3][10]=0;
A[8][3][11]=0;
A[8][3][12]=0;
A[8][3][13]=0;
A[8][3][14]=0;

A[8][4][1]=0;
A[8][4][2]=0;
A[8][4][3]=a8[6] - v8[2]*v8[4] + v8[1]*v8[5];
A[8][4][4]=-a8[5] - v8[3]*v8[4] + v8[1]*v8[6];
A[8][4][5]=a8[1];
A[8][4][6]=a8[2] - v8[1]*v8[3];
A[8][4][7]=a8[3] + v8[1]*v8[2];
A[8][4][8]=-(v8[2]*v8[3]);
A[8][4][9]=Power(v8[2],2) - Power(v8[3],2);
A[8][4][10]=v8[2]*v8[3];
A[8][4][11]=0;
A[8][4][12]=0;
A[8][4][13]=0;
A[8][4][14]=0;

A[8][5][1]=0;
A[8][5][2]=-a8[6] + v8[2]*v8[4] - v8[1]*v8[5];
A[8][5][3]=0;
A[8][5][4]=a8[4] - v8[3]*v8[5] + v8[2]*v8[6];
A[8][5][5]=v8[1]*v8[3];
A[8][5][6]=a8[1] + v8[2]*v8[3];
A[8][5][7]=-Power(v8[1],2) + Power(v8[3],2);
A[8][5][8]=a8[2];
A[8][5][9]=a8[3] - v8[1]*v8[2];
A[8][5][10]=-(v8[1]*v8[3]);
A[8][5][11]=0;
A[8][5][12]=0;
A[8][5][13]=0;
A[8][5][14]=0;

A[8][6][1]=0;
A[8][6][2]=a8[5] + v8[3]*v8[4] - v8[1]*v8[6];
A[8][6][3]=-a8[4] + v8[3]*v8[5] - v8[2]*v8[6];
A[8][6][4]=0;
A[8][6][5]=-(v8[1]*v8[2]);
A[8][6][6]=Power(v8[1],2) - Power(v8[2],2);
A[8][6][7]=a8[1] - v8[2]*v8[3];
A[8][6][8]=v8[1]*v8[2];
A[8][6][9]=a8[2] + v8[1]*v8[3];
A[8][6][10]=a8[3];
A[8][6][11]=0;
A[8][6][12]=0;
A[8][6][13]=0;
A[8][6][14]=0;


A[9][1][1]=a9[4] - v9[3]*v9[5] + v9[2]*v9[6];
A[9][1][2]=-Power(v9[2],2) - Power(v9[3],2);
A[9][1][3]=-a9[3] + v9[1]*v9[2];
A[9][1][4]=a9[2] + v9[1]*v9[3];
A[9][1][5]=0;
A[9][1][6]=0;
A[9][1][7]=0;
A[9][1][8]=0;
A[9][1][9]=0;
A[9][1][10]=0;
A[9][1][11]=0;
A[9][1][12]=0;
A[9][1][13]=0;
A[9][1][14]=0;

A[9][2][1]=a9[5] + v9[3]*v9[4] - v9[1]*v9[6];
A[9][2][2]=a9[3] + v9[1]*v9[2];
A[9][2][3]=-Power(v9[1],2) - Power(v9[3],2);
A[9][2][4]=-a9[1] + v9[2]*v9[3];
A[9][2][5]=0;
A[9][2][6]=0;
A[9][2][7]=0;
A[9][2][8]=0;
A[9][2][9]=0;
A[9][2][10]=0;
A[9][2][11]=0;
A[9][2][12]=0;
A[9][2][13]=0;
A[9][2][14]=0;

A[9][3][1]=a9[6] - v9[2]*v9[4] + v9[1]*v9[5];
A[9][3][2]=-a9[2] + v9[1]*v9[3];
A[9][3][3]=a9[1] + v9[2]*v9[3];
A[9][3][4]=-Power(v9[1],2) - Power(v9[2],2);
A[9][3][5]=0;
A[9][3][6]=0;
A[9][3][7]=0;
A[9][3][8]=0;
A[9][3][9]=0;
A[9][3][10]=0;
A[9][3][11]=0;
A[9][3][12]=0;
A[9][3][13]=0;
A[9][3][14]=0;

A[9][4][1]=0;
A[9][4][2]=0;
A[9][4][3]=a9[6] - v9[2]*v9[4] + v9[1]*v9[5];
A[9][4][4]=-a9[5] - v9[3]*v9[4] + v9[1]*v9[6];
A[9][4][5]=a9[1];
A[9][4][6]=a9[2] - v9[1]*v9[3];
A[9][4][7]=a9[3] + v9[1]*v9[2];
A[9][4][8]=-(v9[2]*v9[3]);
A[9][4][9]=Power(v9[2],2) - Power(v9[3],2);
A[9][4][10]=v9[2]*v9[3];
A[9][4][11]=0;
A[9][4][12]=0;
A[9][4][13]=0;
A[9][4][14]=0;

A[9][5][1]=0;
A[9][5][2]=-a9[6] + v9[2]*v9[4] - v9[1]*v9[5];
A[9][5][3]=0;
A[9][5][4]=a9[4] - v9[3]*v9[5] + v9[2]*v9[6];
A[9][5][5]=v9[1]*v9[3];
A[9][5][6]=a9[1] + v9[2]*v9[3];
A[9][5][7]=-Power(v9[1],2) + Power(v9[3],2);
A[9][5][8]=a9[2];
A[9][5][9]=a9[3] - v9[1]*v9[2];
A[9][5][10]=-(v9[1]*v9[3]);
A[9][5][11]=0;
A[9][5][12]=0;
A[9][5][13]=0;
A[9][5][14]=0;

A[9][6][1]=0;
A[9][6][2]=a9[5] + v9[3]*v9[4] - v9[1]*v9[6];
A[9][6][3]=-a9[4] + v9[3]*v9[5] - v9[2]*v9[6];
A[9][6][4]=0;
A[9][6][5]=-(v9[1]*v9[2]);
A[9][6][6]=Power(v9[1],2) - Power(v9[2],2);
A[9][6][7]=a9[1] - v9[2]*v9[3];
A[9][6][8]=v9[1]*v9[2];
A[9][6][9]=a9[2] + v9[1]*v9[3];
A[9][6][10]=a9[3];
A[9][6][11]=0;
A[9][6][12]=0;
A[9][6][13]=0;
A[9][6][14]=0;


A[10][1][1]=a10[4] - v10[3]*v10[5] + v10[2]*v10[6];
A[10][1][2]=-Power(v10[2],2) - Power(v10[3],2);
A[10][1][3]=-a10[3] + v10[1]*v10[2];
A[10][1][4]=a10[2] + v10[1]*v10[3];
A[10][1][5]=0;
A[10][1][6]=0;
A[10][1][7]=0;
A[10][1][8]=0;
A[10][1][9]=0;
A[10][1][10]=0;
A[10][1][11]=0;
A[10][1][12]=0;
A[10][1][13]=0;
A[10][1][14]=0;

A[10][2][1]=a10[5] + v10[3]*v10[4] - v10[1]*v10[6];
A[10][2][2]=a10[3] + v10[1]*v10[2];
A[10][2][3]=-Power(v10[1],2) - Power(v10[3],2);
A[10][2][4]=-a10[1] + v10[2]*v10[3];
A[10][2][5]=0;
A[10][2][6]=0;
A[10][2][7]=0;
A[10][2][8]=0;
A[10][2][9]=0;
A[10][2][10]=0;
A[10][2][11]=0;
A[10][2][12]=0;
A[10][2][13]=0;
A[10][2][14]=0;

A[10][3][1]=a10[6] - v10[2]*v10[4] + v10[1]*v10[5];
A[10][3][2]=-a10[2] + v10[1]*v10[3];
A[10][3][3]=a10[1] + v10[2]*v10[3];
A[10][3][4]=-Power(v10[1],2) - Power(v10[2],2);
A[10][3][5]=0;
A[10][3][6]=0;
A[10][3][7]=0;
A[10][3][8]=0;
A[10][3][9]=0;
A[10][3][10]=0;
A[10][3][11]=0;
A[10][3][12]=0;
A[10][3][13]=0;
A[10][3][14]=0;

A[10][4][1]=0;
A[10][4][2]=0;
A[10][4][3]=a10[6] - v10[2]*v10[4] + v10[1]*v10[5];
A[10][4][4]=-a10[5] - v10[3]*v10[4] + v10[1]*v10[6];
A[10][4][5]=a10[1];
A[10][4][6]=a10[2] - v10[1]*v10[3];
A[10][4][7]=a10[3] + v10[1]*v10[2];
A[10][4][8]=-(v10[2]*v10[3]);
A[10][4][9]=Power(v10[2],2) - Power(v10[3],2);
A[10][4][10]=v10[2]*v10[3];
A[10][4][11]=0;
A[10][4][12]=0;
A[10][4][13]=0;
A[10][4][14]=0;

A[10][5][1]=0;
A[10][5][2]=-a10[6] + v10[2]*v10[4] - v10[1]*v10[5];
A[10][5][3]=0;
A[10][5][4]=a10[4] - v10[3]*v10[5] + v10[2]*v10[6];
A[10][5][5]=v10[1]*v10[3];
A[10][5][6]=a10[1] + v10[2]*v10[3];
A[10][5][7]=-Power(v10[1],2) + Power(v10[3],2);
A[10][5][8]=a10[2];
A[10][5][9]=a10[3] - v10[1]*v10[2];
A[10][5][10]=-(v10[1]*v10[3]);
A[10][5][11]=0;
A[10][5][12]=0;
A[10][5][13]=0;
A[10][5][14]=0;

A[10][6][1]=0;
A[10][6][2]=a10[5] + v10[3]*v10[4] - v10[1]*v10[6];
A[10][6][3]=-a10[4] + v10[3]*v10[5] - v10[2]*v10[6];
A[10][6][4]=0;
A[10][6][5]=-(v10[1]*v10[2]);
A[10][6][6]=Power(v10[1],2) - Power(v10[2],2);
A[10][6][7]=a10[1] - v10[2]*v10[3];
A[10][6][8]=v10[1]*v10[2];
A[10][6][9]=a10[2] + v10[1]*v10[3];
A[10][6][10]=a10[3];
A[10][6][11]=0;
A[10][6][12]=0;
A[10][6][13]=0;
A[10][6][14]=0;


A[11][1][1]=a11[4] - v11[3]*v11[5] + v11[2]*v11[6];
A[11][1][2]=-Power(v11[2],2) - Power(v11[3],2);
A[11][1][3]=-a11[3] + v11[1]*v11[2];
A[11][1][4]=a11[2] + v11[1]*v11[3];
A[11][1][5]=0;
A[11][1][6]=0;
A[11][1][7]=0;
A[11][1][8]=0;
A[11][1][9]=0;
A[11][1][10]=0;
A[11][1][11]=0;
A[11][1][12]=0;
A[11][1][13]=0;
A[11][1][14]=0;

A[11][2][1]=a11[5] + v11[3]*v11[4] - v11[1]*v11[6];
A[11][2][2]=a11[3] + v11[1]*v11[2];
A[11][2][3]=-Power(v11[1],2) - Power(v11[3],2);
A[11][2][4]=-a11[1] + v11[2]*v11[3];
A[11][2][5]=0;
A[11][2][6]=0;
A[11][2][7]=0;
A[11][2][8]=0;
A[11][2][9]=0;
A[11][2][10]=0;
A[11][2][11]=0;
A[11][2][12]=0;
A[11][2][13]=0;
A[11][2][14]=0;

A[11][3][1]=a11[6] - v11[2]*v11[4] + v11[1]*v11[5];
A[11][3][2]=-a11[2] + v11[1]*v11[3];
A[11][3][3]=a11[1] + v11[2]*v11[3];
A[11][3][4]=-Power(v11[1],2) - Power(v11[2],2);
A[11][3][5]=0;
A[11][3][6]=0;
A[11][3][7]=0;
A[11][3][8]=0;
A[11][3][9]=0;
A[11][3][10]=0;
A[11][3][11]=0;
A[11][3][12]=0;
A[11][3][13]=0;
A[11][3][14]=0;

A[11][4][1]=0;
A[11][4][2]=0;
A[11][4][3]=a11[6] - v11[2]*v11[4] + v11[1]*v11[5];
A[11][4][4]=-a11[5] - v11[3]*v11[4] + v11[1]*v11[6];
A[11][4][5]=a11[1];
A[11][4][6]=a11[2] - v11[1]*v11[3];
A[11][4][7]=a11[3] + v11[1]*v11[2];
A[11][4][8]=-(v11[2]*v11[3]);
A[11][4][9]=Power(v11[2],2) - Power(v11[3],2);
A[11][4][10]=v11[2]*v11[3];
A[11][4][11]=0;
A[11][4][12]=0;
A[11][4][13]=0;
A[11][4][14]=0;

A[11][5][1]=0;
A[11][5][2]=-a11[6] + v11[2]*v11[4] - v11[1]*v11[5];
A[11][5][3]=0;
A[11][5][4]=a11[4] - v11[3]*v11[5] + v11[2]*v11[6];
A[11][5][5]=v11[1]*v11[3];
A[11][5][6]=a11[1] + v11[2]*v11[3];
A[11][5][7]=-Power(v11[1],2) + Power(v11[3],2);
A[11][5][8]=a11[2];
A[11][5][9]=a11[3] - v11[1]*v11[2];
A[11][5][10]=-(v11[1]*v11[3]);
A[11][5][11]=0;
A[11][5][12]=0;
A[11][5][13]=0;
A[11][5][14]=0;

A[11][6][1]=0;
A[11][6][2]=a11[5] + v11[3]*v11[4] - v11[1]*v11[6];
A[11][6][3]=-a11[4] + v11[3]*v11[5] - v11[2]*v11[6];
A[11][6][4]=0;
A[11][6][5]=-(v11[1]*v11[2]);
A[11][6][6]=Power(v11[1],2) - Power(v11[2],2);
A[11][6][7]=a11[1] - v11[2]*v11[3];
A[11][6][8]=v11[1]*v11[2];
A[11][6][9]=a11[2] + v11[1]*v11[3];
A[11][6][10]=a11[3];
A[11][6][11]=0;
A[11][6][12]=0;
A[11][6][13]=0;
A[11][6][14]=0;


A[12][1][1]=a12[4] - v12[3]*v12[5] + v12[2]*v12[6];
A[12][1][2]=-Power(v12[2],2) - Power(v12[3],2);
A[12][1][3]=-a12[3] + v12[1]*v12[2];
A[12][1][4]=a12[2] + v12[1]*v12[3];
A[12][1][5]=0;
A[12][1][6]=0;
A[12][1][7]=0;
A[12][1][8]=0;
A[12][1][9]=0;
A[12][1][10]=0;
A[12][1][11]=0;
A[12][1][12]=0;
A[12][1][13]=0;
A[12][1][14]=0;

A[12][2][1]=a12[5] + v12[3]*v12[4] - v12[1]*v12[6];
A[12][2][2]=a12[3] + v12[1]*v12[2];
A[12][2][3]=-Power(v12[1],2) - Power(v12[3],2);
A[12][2][4]=-a12[1] + v12[2]*v12[3];
A[12][2][5]=0;
A[12][2][6]=0;
A[12][2][7]=0;
A[12][2][8]=0;
A[12][2][9]=0;
A[12][2][10]=0;
A[12][2][11]=0;
A[12][2][12]=0;
A[12][2][13]=0;
A[12][2][14]=0;

A[12][3][1]=a12[6] - v12[2]*v12[4] + v12[1]*v12[5];
A[12][3][2]=-a12[2] + v12[1]*v12[3];
A[12][3][3]=a12[1] + v12[2]*v12[3];
A[12][3][4]=-Power(v12[1],2) - Power(v12[2],2);
A[12][3][5]=0;
A[12][3][6]=0;
A[12][3][7]=0;
A[12][3][8]=0;
A[12][3][9]=0;
A[12][3][10]=0;
A[12][3][11]=0;
A[12][3][12]=0;
A[12][3][13]=0;
A[12][3][14]=0;

A[12][4][1]=0;
A[12][4][2]=0;
A[12][4][3]=a12[6] - v12[2]*v12[4] + v12[1]*v12[5];
A[12][4][4]=-a12[5] - v12[3]*v12[4] + v12[1]*v12[6];
A[12][4][5]=a12[1];
A[12][4][6]=a12[2] - v12[1]*v12[3];
A[12][4][7]=a12[3] + v12[1]*v12[2];
A[12][4][8]=-(v12[2]*v12[3]);
A[12][4][9]=Power(v12[2],2) - Power(v12[3],2);
A[12][4][10]=v12[2]*v12[3];
A[12][4][11]=0;
A[12][4][12]=0;
A[12][4][13]=0;
A[12][4][14]=0;

A[12][5][1]=0;
A[12][5][2]=-a12[6] + v12[2]*v12[4] - v12[1]*v12[5];
A[12][5][3]=0;
A[12][5][4]=a12[4] - v12[3]*v12[5] + v12[2]*v12[6];
A[12][5][5]=v12[1]*v12[3];
A[12][5][6]=a12[1] + v12[2]*v12[3];
A[12][5][7]=-Power(v12[1],2) + Power(v12[3],2);
A[12][5][8]=a12[2];
A[12][5][9]=a12[3] - v12[1]*v12[2];
A[12][5][10]=-(v12[1]*v12[3]);
A[12][5][11]=0;
A[12][5][12]=0;
A[12][5][13]=0;
A[12][5][14]=0;

A[12][6][1]=0;
A[12][6][2]=a12[5] + v12[3]*v12[4] - v12[1]*v12[6];
A[12][6][3]=-a12[4] + v12[3]*v12[5] - v12[2]*v12[6];
A[12][6][4]=0;
A[12][6][5]=-(v12[1]*v12[2]);
A[12][6][6]=Power(v12[1],2) - Power(v12[2],2);
A[12][6][7]=a12[1] - v12[2]*v12[3];
A[12][6][8]=v12[1]*v12[2];
A[12][6][9]=a12[2] + v12[1]*v12[3];
A[12][6][10]=a12[3];
A[12][6][11]=0;
A[12][6][12]=0;
A[12][6][13]=0;
A[12][6][14]=0;


A[13][1][1]=a13[4] - v13[3]*v13[5] + v13[2]*v13[6];
A[13][1][2]=-Power(v13[2],2) - Power(v13[3],2);
A[13][1][3]=-a13[3] + v13[1]*v13[2];
A[13][1][4]=a13[2] + v13[1]*v13[3];
A[13][1][5]=0;
A[13][1][6]=0;
A[13][1][7]=0;
A[13][1][8]=0;
A[13][1][9]=0;
A[13][1][10]=0;
A[13][1][11]=0;
A[13][1][12]=0;
A[13][1][13]=0;
A[13][1][14]=0;

A[13][2][1]=a13[5] + v13[3]*v13[4] - v13[1]*v13[6];
A[13][2][2]=a13[3] + v13[1]*v13[2];
A[13][2][3]=-Power(v13[1],2) - Power(v13[3],2);
A[13][2][4]=-a13[1] + v13[2]*v13[3];
A[13][2][5]=0;
A[13][2][6]=0;
A[13][2][7]=0;
A[13][2][8]=0;
A[13][2][9]=0;
A[13][2][10]=0;
A[13][2][11]=0;
A[13][2][12]=0;
A[13][2][13]=0;
A[13][2][14]=0;

A[13][3][1]=a13[6] - v13[2]*v13[4] + v13[1]*v13[5];
A[13][3][2]=-a13[2] + v13[1]*v13[3];
A[13][3][3]=a13[1] + v13[2]*v13[3];
A[13][3][4]=-Power(v13[1],2) - Power(v13[2],2);
A[13][3][5]=0;
A[13][3][6]=0;
A[13][3][7]=0;
A[13][3][8]=0;
A[13][3][9]=0;
A[13][3][10]=0;
A[13][3][11]=0;
A[13][3][12]=0;
A[13][3][13]=0;
A[13][3][14]=0;

A[13][4][1]=0;
A[13][4][2]=0;
A[13][4][3]=a13[6] - v13[2]*v13[4] + v13[1]*v13[5];
A[13][4][4]=-a13[5] - v13[3]*v13[4] + v13[1]*v13[6];
A[13][4][5]=a13[1];
A[13][4][6]=a13[2] - v13[1]*v13[3];
A[13][4][7]=a13[3] + v13[1]*v13[2];
A[13][4][8]=-(v13[2]*v13[3]);
A[13][4][9]=Power(v13[2],2) - Power(v13[3],2);
A[13][4][10]=v13[2]*v13[3];
A[13][4][11]=0;
A[13][4][12]=0;
A[13][4][13]=0;
A[13][4][14]=0;

A[13][5][1]=0;
A[13][5][2]=-a13[6] + v13[2]*v13[4] - v13[1]*v13[5];
A[13][5][3]=0;
A[13][5][4]=a13[4] - v13[3]*v13[5] + v13[2]*v13[6];
A[13][5][5]=v13[1]*v13[3];
A[13][5][6]=a13[1] + v13[2]*v13[3];
A[13][5][7]=-Power(v13[1],2) + Power(v13[3],2);
A[13][5][8]=a13[2];
A[13][5][9]=a13[3] - v13[1]*v13[2];
A[13][5][10]=-(v13[1]*v13[3]);
A[13][5][11]=0;
A[13][5][12]=0;
A[13][5][13]=0;
A[13][5][14]=0;

A[13][6][1]=0;
A[13][6][2]=a13[5] + v13[3]*v13[4] - v13[1]*v13[6];
A[13][6][3]=-a13[4] + v13[3]*v13[5] - v13[2]*v13[6];
A[13][6][4]=0;
A[13][6][5]=-(v13[1]*v13[2]);
A[13][6][6]=Power(v13[1],2) - Power(v13[2],2);
A[13][6][7]=a13[1] - v13[2]*v13[3];
A[13][6][8]=v13[1]*v13[2];
A[13][6][9]=a13[2] + v13[1]*v13[3];
A[13][6][10]=a13[3];
A[13][6][11]=0;
A[13][6][12]=0;
A[13][6][13]=0;
A[13][6][14]=0;



/* predecessor vectors */
pred[1]=0;
pred[2]=1;
pred[3]=2;
pred[4]=3;
pred[5]=4;
pred[6]=5;
pred[7]=6;
pred[8]=7;
pred[9]=7;
pred[10]=9;
pred[11]=10;
pred[12]=7;
pred[13]=12;

/* output mapping, i.e, which joint is where */
map[0]=0;
map[1]=1;
map[2]=2;
map[3]=3;
map[4]=4;
map[5]=5;
map[6]=6;
map[7]=7;
map[108]=8;
map[8]=9;
map[9]=10;
map[109]=11;
map[10]=12;
map[110]=13;

{                                                           
  int ii;                                                   
  int jj;                                                   
  int nn;                                                   
  int mm;                                                   
  int level;                                                
  int xnj=13;                           
  int fbflag=0;                        
                                                            
  for ( ii=xnj; ii>=0; --ii) {                              
    level = ii;                                             
    while (1) {                                             
                                                            
      if (level==ii)                                        
        for (nn=1;nn<=6;++nn)                               
          for (mm=1;mm<=N_RBD_PARMS;++mm)                   
            U[nn][mm]=A[ii][nn][mm];                        
      else                                                  
        for (nn=1;nn<=6;++nn)                               
          for (mm=1;mm<=N_RBD_PARMS;++mm)                   
            U[nn][mm]=Unew[nn][mm];                         
                                                            
      if (level == 0) {                                     
        for (nn=1;nn<=6;++nn)                               
          for (mm=1;mm<=N_RBD_PARMS;++mm) {                 
            Unew[nn][mm]=0;                                 
            for (jj=1;jj<=6;++jj)                           
              Unew[nn][mm]+=Xinv[level][nn][jj]*U[jj][mm];  
          }                                                 
        for (nn=1;nn<=6;++nn)                               
          for (mm=1;mm<=N_RBD_PARMS;++mm)                   
            K[xnj+nn][ii*N_RBD_PARMS+mm]=Unew[nn][mm]*fbflag;
        break;                                              
      } else {                                              
        for (mm=1;mm<=N_RBD_PARMS;++mm) {                   
          K[level][ii*N_RBD_PARMS+mm]=0;                    
          for (nn=1;nn<=6;++nn)                             
            K[level][ii*N_RBD_PARMS+mm]+=st[level][nn]*U[nn][mm];
        }                                                   
      }                                                     
                                                            
      for (nn=1;nn<=6;++nn)                                 
        for (mm=1;mm<=N_RBD_PARMS;++mm) {                   
          Unew[nn][mm]=0;                                   
          for (jj=1;jj<=6;++jj)                             
            Unew[nn][mm]+=Xinv[level][nn][jj]*U[jj][mm];    
        }                                                   
      level=pred[level];                                    
    }                                                       
  }                                                         
}                                                           
                                                            
/* The outputs that are associate with each row of K */
Y[1]=state[1].u;
Y[2]=state[2].u;
Y[3]=state[3].u;
Y[4]=state[4].u;
Y[5]=state[5].u;
Y[6]=state[6].u;
Y[7]=state[7].u;
Y[9]=state[8].u;
Y[10]=state[9].u;
Y[12]=state[10].u;


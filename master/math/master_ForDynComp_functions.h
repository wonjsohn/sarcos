
void
master_ForDynCompfunc1(void)
     {
/* rotation matrices */
S00[1][1]=-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[2],2);
S00[1][2]=2*(baseo[0].q[2]*baseo[0].q[3] + baseo[0].q[1]*baseo[0].q[4]);
S00[1][3]=2*(-(baseo[0].q[1]*baseo[0].q[3]) + baseo[0].q[2]*baseo[0].q[4]);

S00[2][1]=2*(baseo[0].q[2]*baseo[0].q[3] - baseo[0].q[1]*baseo[0].q[4]);
S00[2][2]=-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[3],2);
S00[2][3]=2*(baseo[0].q[1]*baseo[0].q[2] + baseo[0].q[3]*baseo[0].q[4]);

S00[3][1]=2*(baseo[0].q[1]*baseo[0].q[3] + baseo[0].q[2]*baseo[0].q[4]);
S00[3][2]=2*(-(baseo[0].q[1]*baseo[0].q[2]) + baseo[0].q[3]*baseo[0].q[4]);
S00[3][3]=-1 + 2*Power(baseo[0].q[1],2) + 2*Power(baseo[0].q[4],2);


S10[1][1]=0.7071067811865475*cstate1th;
S10[1][2]=sstate1th;
S10[1][3]=-0.7071067811865475*cstate1th;

S10[2][1]=-0.7071067811865475*sstate1th;
S10[2][2]=cstate1th;
S10[2][3]=0.7071067811865475*sstate1th;


S21[1][1]=0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th;
S21[1][3]=-0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th;

S21[2][1]=-0.7071067811865475*cstate2th - 0.7071067811865475*sstate2th;
S21[2][3]=-0.7071067811865475*cstate2th + 0.7071067811865475*sstate2th;


S32[1][2]=sstate3th;
S32[1][3]=-cstate3th;

S32[2][2]=cstate3th;
S32[2][3]=sstate3th;


S43[1][1]=sstate4th;
S43[1][3]=-cstate4th;

S43[2][1]=cstate4th;
S43[2][3]=sstate4th;


S54[1][2]=sstate5th;
S54[1][3]=cstate5th;

S54[2][2]=cstate5th;
S54[2][3]=-sstate5th;


S65[1][1]=cstate6th;
S65[1][3]=-sstate6th;

S65[2][1]=-sstate6th;
S65[2][3]=-cstate6th;


S76[1][2]=-sstate7th;
S76[1][3]=cstate7th;

S76[2][2]=-cstate7th;
S76[2][3]=-sstate7th;


S87[1][1]=rceff1a2*rceff1a3;
S87[1][2]=rceff1a3*rseff1a1*rseff1a2 + rceff1a1*rseff1a3;
S87[1][3]=-(rceff1a1*rceff1a3*rseff1a2) + rseff1a1*rseff1a3;

S87[2][1]=-(rceff1a2*rseff1a3);
S87[2][2]=rceff1a1*rceff1a3 - rseff1a1*rseff1a2*rseff1a3;
S87[2][3]=rceff1a3*rseff1a1 + rceff1a1*rseff1a2*rseff1a3;

S87[3][1]=rseff1a2;
S87[3][2]=-(rceff1a2*rseff1a1);
S87[3][3]=rceff1a1*rceff1a2;


S97[1][2]=sstate8th;
S97[1][3]=cstate8th;

S97[2][2]=cstate8th;
S97[2][3]=-sstate8th;


S109[1][2]=sstate9th;
S109[1][3]=-cstate9th;

S109[2][2]=cstate9th;
S109[2][3]=sstate9th;



S127[1][1]=cstate10th;
S127[1][2]=sstate10th;

S127[2][1]=-sstate10th;
S127[2][2]=cstate10th;





}


void
master_ForDynCompfunc2(void)
     {
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





}


void
master_ForDynCompfunc3(void)
     {
/* rotation matrices from global to link coordinates */
SG10[1][1]=S00[1][1]*S10[1][1] + S00[2][1]*S10[1][2] + S00[3][1]*S10[1][3];
SG10[1][2]=S00[1][2]*S10[1][1] + S00[2][2]*S10[1][2] + S00[3][2]*S10[1][3];
SG10[1][3]=S00[1][3]*S10[1][1] + S00[2][3]*S10[1][2] + S00[3][3]*S10[1][3];

SG10[2][1]=S00[1][1]*S10[2][1] + S00[2][1]*S10[2][2] + S00[3][1]*S10[2][3];
SG10[2][2]=S00[1][2]*S10[2][1] + S00[2][2]*S10[2][2] + S00[3][2]*S10[2][3];
SG10[2][3]=S00[1][3]*S10[2][1] + S00[2][3]*S10[2][2] + S00[3][3]*S10[2][3];

SG10[3][1]=0.7071067811865475*S00[1][1] + 0.7071067811865475*S00[3][1];
SG10[3][2]=0.7071067811865475*S00[1][2] + 0.7071067811865475*S00[3][2];
SG10[3][3]=0.7071067811865475*S00[1][3] + 0.7071067811865475*S00[3][3];


SG20[1][1]=S21[1][1]*SG10[1][1] + S21[1][3]*SG10[3][1];
SG20[1][2]=S21[1][1]*SG10[1][2] + S21[1][3]*SG10[3][2];
SG20[1][3]=S21[1][1]*SG10[1][3] + S21[1][3]*SG10[3][3];

SG20[2][1]=S21[2][1]*SG10[1][1] + S21[2][3]*SG10[3][1];
SG20[2][2]=S21[2][1]*SG10[1][2] + S21[2][3]*SG10[3][2];
SG20[2][3]=S21[2][1]*SG10[1][3] + S21[2][3]*SG10[3][3];

SG20[3][1]=SG10[2][1];
SG20[3][2]=SG10[2][2];
SG20[3][3]=SG10[2][3];


SG30[1][1]=S32[1][2]*SG20[2][1] + S32[1][3]*SG20[3][1];
SG30[1][2]=S32[1][2]*SG20[2][2] + S32[1][3]*SG20[3][2];
SG30[1][3]=S32[1][2]*SG20[2][3] + S32[1][3]*SG20[3][3];

SG30[2][1]=S32[2][2]*SG20[2][1] + S32[2][3]*SG20[3][1];
SG30[2][2]=S32[2][2]*SG20[2][2] + S32[2][3]*SG20[3][2];
SG30[2][3]=S32[2][2]*SG20[2][3] + S32[2][3]*SG20[3][3];

SG30[3][1]=SG20[1][1];
SG30[3][2]=SG20[1][2];
SG30[3][3]=SG20[1][3];


SG40[1][1]=S43[1][1]*SG30[1][1] + S43[1][3]*SG30[3][1];
SG40[1][2]=S43[1][1]*SG30[1][2] + S43[1][3]*SG30[3][2];
SG40[1][3]=S43[1][1]*SG30[1][3] + S43[1][3]*SG30[3][3];

SG40[2][1]=S43[2][1]*SG30[1][1] + S43[2][3]*SG30[3][1];
SG40[2][2]=S43[2][1]*SG30[1][2] + S43[2][3]*SG30[3][2];
SG40[2][3]=S43[2][1]*SG30[1][3] + S43[2][3]*SG30[3][3];

SG40[3][1]=-SG30[2][1];
SG40[3][2]=-SG30[2][2];
SG40[3][3]=-SG30[2][3];


SG50[1][1]=S54[1][2]*SG40[2][1] + S54[1][3]*SG40[3][1];
SG50[1][2]=S54[1][2]*SG40[2][2] + S54[1][3]*SG40[3][2];
SG50[1][3]=S54[1][2]*SG40[2][3] + S54[1][3]*SG40[3][3];

SG50[2][1]=S54[2][2]*SG40[2][1] + S54[2][3]*SG40[3][1];
SG50[2][2]=S54[2][2]*SG40[2][2] + S54[2][3]*SG40[3][2];
SG50[2][3]=S54[2][2]*SG40[2][3] + S54[2][3]*SG40[3][3];

SG50[3][1]=-SG40[1][1];
SG50[3][2]=-SG40[1][2];
SG50[3][3]=-SG40[1][3];


SG60[1][1]=S65[1][1]*SG50[1][1] + S65[1][3]*SG50[3][1];
SG60[1][2]=S65[1][1]*SG50[1][2] + S65[1][3]*SG50[3][2];
SG60[1][3]=S65[1][1]*SG50[1][3] + S65[1][3]*SG50[3][3];

SG60[2][1]=S65[2][1]*SG50[1][1] + S65[2][3]*SG50[3][1];
SG60[2][2]=S65[2][1]*SG50[1][2] + S65[2][3]*SG50[3][2];
SG60[2][3]=S65[2][1]*SG50[1][3] + S65[2][3]*SG50[3][3];

SG60[3][1]=SG50[2][1];
SG60[3][2]=SG50[2][2];
SG60[3][3]=SG50[2][3];


SG70[1][1]=S76[1][2]*SG60[2][1] + S76[1][3]*SG60[3][1];
SG70[1][2]=S76[1][2]*SG60[2][2] + S76[1][3]*SG60[3][2];
SG70[1][3]=S76[1][2]*SG60[2][3] + S76[1][3]*SG60[3][3];

SG70[2][1]=S76[2][2]*SG60[2][1] + S76[2][3]*SG60[3][1];
SG70[2][2]=S76[2][2]*SG60[2][2] + S76[2][3]*SG60[3][2];
SG70[2][3]=S76[2][2]*SG60[2][3] + S76[2][3]*SG60[3][3];

SG70[3][1]=SG60[1][1];
SG70[3][2]=SG60[1][2];
SG70[3][3]=SG60[1][3];


SG80[1][1]=S87[1][1]*SG70[1][1] + S87[1][2]*SG70[2][1] + S87[1][3]*SG70[3][1];
SG80[1][2]=S87[1][1]*SG70[1][2] + S87[1][2]*SG70[2][2] + S87[1][3]*SG70[3][2];
SG80[1][3]=S87[1][1]*SG70[1][3] + S87[1][2]*SG70[2][3] + S87[1][3]*SG70[3][3];

SG80[2][1]=S87[2][1]*SG70[1][1] + S87[2][2]*SG70[2][1] + S87[2][3]*SG70[3][1];
SG80[2][2]=S87[2][1]*SG70[1][2] + S87[2][2]*SG70[2][2] + S87[2][3]*SG70[3][2];
SG80[2][3]=S87[2][1]*SG70[1][3] + S87[2][2]*SG70[2][3] + S87[2][3]*SG70[3][3];

SG80[3][1]=S87[3][1]*SG70[1][1] + S87[3][2]*SG70[2][1] + S87[3][3]*SG70[3][1];
SG80[3][2]=S87[3][1]*SG70[1][2] + S87[3][2]*SG70[2][2] + S87[3][3]*SG70[3][2];
SG80[3][3]=S87[3][1]*SG70[1][3] + S87[3][2]*SG70[2][3] + S87[3][3]*SG70[3][3];


SG90[1][1]=S97[1][2]*SG70[2][1] + S97[1][3]*SG70[3][1];
SG90[1][2]=S97[1][2]*SG70[2][2] + S97[1][3]*SG70[3][2];
SG90[1][3]=S97[1][2]*SG70[2][3] + S97[1][3]*SG70[3][3];

SG90[2][1]=S97[2][2]*SG70[2][1] + S97[2][3]*SG70[3][1];
SG90[2][2]=S97[2][2]*SG70[2][2] + S97[2][3]*SG70[3][2];
SG90[2][3]=S97[2][2]*SG70[2][3] + S97[2][3]*SG70[3][3];

SG90[3][1]=-SG70[1][1];
SG90[3][2]=-SG70[1][2];
SG90[3][3]=-SG70[1][3];


SG100[1][1]=S109[1][2]*SG90[2][1] + S109[1][3]*SG90[3][1];
SG100[1][2]=S109[1][2]*SG90[2][2] + S109[1][3]*SG90[3][2];
SG100[1][3]=S109[1][2]*SG90[2][3] + S109[1][3]*SG90[3][3];

SG100[2][1]=S109[2][2]*SG90[2][1] + S109[2][3]*SG90[3][1];
SG100[2][2]=S109[2][2]*SG90[2][2] + S109[2][3]*SG90[3][2];
SG100[2][3]=S109[2][2]*SG90[2][3] + S109[2][3]*SG90[3][3];

SG100[3][1]=SG90[1][1];
SG100[3][2]=SG90[1][2];
SG100[3][3]=SG90[1][3];


SG110[1][1]=SG100[1][1];
SG110[1][2]=SG100[1][2];
SG110[1][3]=SG100[1][3];

SG110[2][1]=SG100[2][1];
SG110[2][2]=SG100[2][2];
SG110[2][3]=SG100[2][3];

SG110[3][1]=SG100[3][1];
SG110[3][2]=SG100[3][2];
SG110[3][3]=SG100[3][3];


SG120[1][1]=S127[1][1]*SG70[1][1] + S127[1][2]*SG70[2][1];
SG120[1][2]=S127[1][1]*SG70[1][2] + S127[1][2]*SG70[2][2];
SG120[1][3]=S127[1][1]*SG70[1][3] + S127[1][2]*SG70[2][3];

SG120[2][1]=S127[2][1]*SG70[1][1] + S127[2][2]*SG70[2][1];
SG120[2][2]=S127[2][1]*SG70[1][2] + S127[2][2]*SG70[2][2];
SG120[2][3]=S127[2][1]*SG70[1][3] + S127[2][2]*SG70[2][3];

SG120[3][1]=SG70[3][1];
SG120[3][2]=SG70[3][2];
SG120[3][3]=SG70[3][3];


SG130[1][1]=SG120[1][1];
SG130[1][2]=SG120[1][2];
SG130[1][3]=SG120[1][3];

SG130[2][1]=SG120[2][1];
SG130[2][2]=SG120[2][2];
SG130[2][3]=SG120[2][3];

SG130[3][1]=SG120[3][1];
SG130[3][2]=SG120[3][2];
SG130[3][3]=SG120[3][3];




}


void
master_ForDynCompfunc4(void)
     {
/* velocity vectors */
v0[1]=baseo[0].ad[1]*S00[1][1] + baseo[0].ad[2]*S00[1][2] + baseo[0].ad[3]*S00[1][3];
v0[2]=baseo[0].ad[1]*S00[2][1] + baseo[0].ad[2]*S00[2][2] + baseo[0].ad[3]*S00[2][3];
v0[3]=baseo[0].ad[1]*S00[3][1] + baseo[0].ad[2]*S00[3][2] + baseo[0].ad[3]*S00[3][3];
v0[4]=basec[0].xd[1]*S00[1][1] + basec[0].xd[2]*S00[1][2] + basec[0].xd[3]*S00[1][3];
v0[5]=basec[0].xd[1]*S00[2][1] + basec[0].xd[2]*S00[2][2] + basec[0].xd[3]*S00[2][3];
v0[6]=basec[0].xd[1]*S00[3][1] + basec[0].xd[2]*S00[3][2] + basec[0].xd[3]*S00[3][3];

v1[1]=v0[1]*S10[1][1] + v0[2]*S10[1][2] + v0[3]*S10[1][3];
v1[2]=v0[1]*S10[2][1] + v0[2]*S10[2][2] + v0[3]*S10[2][3];
v1[3]=state[1].thd + 0.7071067811865475*v0[1] + 0.7071067811865475*v0[3];
v1[4]=v0[4]*S10[1][1] - (l0*v0[1]*S10[1][2])/Sqrt(2) + (l0*v0[3]*S10[1][2])/Sqrt(2) + v0[5]*S10[1][2] + v0[6]*S10[1][3] + v0[2]*((l0*S10[1][1])/Sqrt(2) - (l0*S10[1][3])/Sqrt(2));
v1[5]=v0[4]*S10[2][1] - (l0*v0[1]*S10[2][2])/Sqrt(2) + (l0*v0[3]*S10[2][2])/Sqrt(2) + v0[5]*S10[2][2] + v0[6]*S10[2][3] + v0[2]*((l0*S10[2][1])/Sqrt(2) - (l0*S10[2][3])/Sqrt(2));
v1[6]=0.7071067811865475*v0[4] + 0.7071067811865475*v0[6];

v2[1]=v1[1]*S21[1][1] + v1[3]*S21[1][3];
v2[2]=v1[1]*S21[2][1] + v1[3]*S21[2][3];
v2[3]=state[2].thd + v1[2];
v2[4]=v1[4]*S21[1][1] + v1[6]*S21[1][3];
v2[5]=v1[4]*S21[2][1] + v1[6]*S21[2][3];
v2[6]=v1[5];

v3[1]=v2[2]*S32[1][2] + v2[3]*S32[1][3];
v3[2]=v2[2]*S32[2][2] + v2[3]*S32[2][3];
v3[3]=state[3].thd + v2[1];
v3[4]=v2[5]*S32[1][2] - l1*v2[1]*S32[1][3] + v2[6]*S32[1][3];
v3[5]=v2[5]*S32[2][2] - l1*v2[1]*S32[2][3] + v2[6]*S32[2][3];
v3[6]=l1*v2[3] + v2[4];

v4[1]=v3[1]*S43[1][1] + v3[3]*S43[1][3];
v4[2]=v3[1]*S43[2][1] + v3[3]*S43[2][3];
v4[3]=state[4].thd - v3[2];
v4[4]=l2*v3[2]*S43[1][1] + v3[4]*S43[1][1] + v3[6]*S43[1][3];
v4[5]=l2*v3[2]*S43[2][1] + v3[4]*S43[2][1] + v3[6]*S43[2][3];
v4[6]=l2*v3[1] - v3[5];

v5[1]=v4[2]*S54[1][2] + v4[3]*S54[1][3];
v5[2]=v4[2]*S54[2][2] + v4[3]*S54[2][3];
v5[3]=state[5].thd - v4[1];
v5[4]=l3*v4[1]*S54[1][2] + v4[5]*S54[1][2] + v4[6]*S54[1][3];
v5[5]=l3*v4[1]*S54[2][2] + v4[5]*S54[2][2] + v4[6]*S54[2][3];
v5[6]=l3*v4[2] - v4[4];

v6[1]=v5[1]*S65[1][1] + v5[3]*S65[1][3];
v6[2]=v5[1]*S65[2][1] + v5[3]*S65[2][3];
v6[3]=state[6].thd + v5[2];
v6[4]=l4*v5[2]*S65[1][1] + v5[4]*S65[1][1] + v5[6]*S65[1][3];
v6[5]=l4*v5[2]*S65[2][1] + v5[4]*S65[2][1] + v5[6]*S65[2][3];
v6[6]=-(l4*v5[1]) + v5[5];

v7[1]=v6[2]*S76[1][2] + v6[3]*S76[1][3];
v7[2]=v6[2]*S76[2][2] + v6[3]*S76[2][3];
v7[3]=state[7].thd + v6[1];
v7[4]=-(l5*v6[1]*S76[1][2]) + v6[5]*S76[1][2] + v6[6]*S76[1][3];
v7[5]=-(l5*v6[1]*S76[2][2]) + v6[5]*S76[2][2] + v6[6]*S76[2][3];
v7[6]=l5*v6[2] + v6[4];

v8[1]=v7[1]*S87[1][1] + v7[2]*S87[1][2] + v7[3]*S87[1][3];
v8[2]=v7[1]*S87[2][1] + v7[2]*S87[2][2] + v7[3]*S87[2][3];
v8[3]=v7[1]*S87[3][1] + v7[2]*S87[3][2] + v7[3]*S87[3][3];
v8[4]=v7[4]*S87[1][1] + v7[5]*S87[1][2] + v7[3]*(-(eff[1].x[2]*S87[1][1]) + eff[1].x[1]*S87[1][2]) + v7[6]*S87[1][3] + v7[2]*(eff[1].x[3]*S87[1][1] - eff[1].x[1]*S87[1][3]) + v7[1]*(-(eff[1].x[3]*S87[1][2]) + eff[1].x[2]*S87[1][3]);
v8[5]=v7[4]*S87[2][1] + v7[5]*S87[2][2] + v7[3]*(-(eff[1].x[2]*S87[2][1]) + eff[1].x[1]*S87[2][2]) + v7[6]*S87[2][3] + v7[2]*(eff[1].x[3]*S87[2][1] - eff[1].x[1]*S87[2][3]) + v7[1]*(-(eff[1].x[3]*S87[2][2]) + eff[1].x[2]*S87[2][3]);
v8[6]=v7[4]*S87[3][1] + v7[5]*S87[3][2] + v7[3]*(-(eff[1].x[2]*S87[3][1]) + eff[1].x[1]*S87[3][2]) + v7[6]*S87[3][3] + v7[2]*(eff[1].x[3]*S87[3][1] - eff[1].x[1]*S87[3][3]) + v7[1]*(-(eff[1].x[3]*S87[3][2]) + eff[1].x[2]*S87[3][3]);

v9[1]=v7[2]*S97[1][2] + v7[3]*S97[1][3];
v9[2]=v7[2]*S97[2][2] + v7[3]*S97[2][3];
v9[3]=state[8].thd - v7[1];
v9[4]=-(l7z*v7[1]*S97[1][2]) - l6x*v7[3]*S97[1][2] + v7[5]*S97[1][2] + l6x*v7[2]*S97[1][3] + v7[6]*S97[1][3];
v9[5]=-(l7z*v7[1]*S97[2][2]) - l6x*v7[3]*S97[2][2] + v7[5]*S97[2][2] + l6x*v7[2]*S97[2][3] + v7[6]*S97[2][3];
v9[6]=-(l7z*v7[2]) - v7[4];

v10[1]=v9[2]*S109[1][2] + v9[3]*S109[1][3];
v10[2]=v9[2]*S109[2][2] + v9[3]*S109[2][3];
v10[3]=state[9].thd + v9[1];
v10[4]=v9[5]*S109[1][2] + v9[6]*S109[1][3];
v10[5]=v9[5]*S109[2][2] + v9[6]*S109[2][3];
v10[6]=v9[4];

v11[1]=v10[1];
v11[2]=v10[2];
v11[3]=v10[3];
v11[4]=-(l8*v10[3]) + v10[4];
v11[5]=v10[5];
v11[6]=l8*v10[1] + v10[6];

v12[1]=v7[1]*S127[1][1] + v7[2]*S127[1][2];
v12[2]=v7[1]*S127[2][1] + v7[2]*S127[2][2];
v12[3]=state[10].thd + v7[3];
v12[4]=l6z*v7[2]*S127[1][1] + v7[4]*S127[1][1] - l6z*v7[1]*S127[1][2] + v7[5]*S127[1][2] + v7[3]*(-(l6y*S127[1][1]) - l6x*S127[1][2]);
v12[5]=l6z*v7[2]*S127[2][1] + v7[4]*S127[2][1] - l6z*v7[1]*S127[2][2] + v7[5]*S127[2][2] + v7[3]*(-(l6y*S127[2][1]) - l6x*S127[2][2]);
v12[6]=l6y*v7[1] + l6x*v7[2] + v7[6];

v13[1]=v12[1];
v13[2]=v12[2];
v13[3]=v12[3];
v13[4]=-(l9*v12[3]) + v12[4];
v13[5]=v12[5];
v13[6]=l9*v12[1] + v12[6];



}


void
master_ForDynCompfunc5(void)
     {
/* acceleration vectors */
a0[4]=gravity*S00[1][3];
a0[5]=gravity*S00[2][3];
a0[6]=gravity*S00[3][3];

a1[1]=state[1].thd*v1[2];
a1[2]=-(state[1].thd*v1[1]);
a1[4]=state[1].thd*v1[5] + a0[4]*S10[1][1] + a0[5]*S10[1][2] + a0[6]*S10[1][3];
a1[5]=-(state[1].thd*v1[4]) + a0[4]*S10[2][1] + a0[5]*S10[2][2] + a0[6]*S10[2][3];
a1[6]=0.7071067811865475*a0[4] + 0.7071067811865475*a0[6];

a2[1]=state[2].thd*v2[2] + a1[1]*S21[1][1];
a2[2]=-(state[2].thd*v2[1]) + a1[1]*S21[2][1];
a2[3]=a1[2];
a2[4]=state[2].thd*v2[5] + a1[4]*S21[1][1] + a1[6]*S21[1][3];
a2[5]=-(state[2].thd*v2[4]) + a1[4]*S21[2][1] + a1[6]*S21[2][3];
a2[6]=a1[5];

a3[1]=state[3].thd*v3[2] + a2[2]*S32[1][2] + a2[3]*S32[1][3];
a3[2]=-(state[3].thd*v3[1]) + a2[2]*S32[2][2] + a2[3]*S32[2][3];
a3[3]=a2[1];
a3[4]=state[3].thd*v3[5] + a2[5]*S32[1][2] - l1*a2[1]*S32[1][3] + a2[6]*S32[1][3];
a3[5]=-(state[3].thd*v3[4]) + a2[5]*S32[2][2] - l1*a2[1]*S32[2][3] + a2[6]*S32[2][3];
a3[6]=l1*a2[3] + a2[4];

a4[1]=state[4].thd*v4[2] + a3[1]*S43[1][1] + a3[3]*S43[1][3];
a4[2]=-(state[4].thd*v4[1]) + a3[1]*S43[2][1] + a3[3]*S43[2][3];
a4[3]=-a3[2];
a4[4]=state[4].thd*v4[5] + l2*a3[2]*S43[1][1] + a3[4]*S43[1][1] + a3[6]*S43[1][3];
a4[5]=-(state[4].thd*v4[4]) + l2*a3[2]*S43[2][1] + a3[4]*S43[2][1] + a3[6]*S43[2][3];
a4[6]=l2*a3[1] - a3[5];

a5[1]=state[5].thd*v5[2] + a4[2]*S54[1][2] + a4[3]*S54[1][3];
a5[2]=-(state[5].thd*v5[1]) + a4[2]*S54[2][2] + a4[3]*S54[2][3];
a5[3]=-a4[1];
a5[4]=state[5].thd*v5[5] + l3*a4[1]*S54[1][2] + a4[5]*S54[1][2] + a4[6]*S54[1][3];
a5[5]=-(state[5].thd*v5[4]) + l3*a4[1]*S54[2][2] + a4[5]*S54[2][2] + a4[6]*S54[2][3];
a5[6]=l3*a4[2] - a4[4];

a6[1]=state[6].thd*v6[2] + a5[1]*S65[1][1] + a5[3]*S65[1][3];
a6[2]=-(state[6].thd*v6[1]) + a5[1]*S65[2][1] + a5[3]*S65[2][3];
a6[3]=a5[2];
a6[4]=state[6].thd*v6[5] + l4*a5[2]*S65[1][1] + a5[4]*S65[1][1] + a5[6]*S65[1][3];
a6[5]=-(state[6].thd*v6[4]) + l4*a5[2]*S65[2][1] + a5[4]*S65[2][1] + a5[6]*S65[2][3];
a6[6]=-(l4*a5[1]) + a5[5];

a7[1]=state[7].thd*v7[2] + a6[2]*S76[1][2] + a6[3]*S76[1][3];
a7[2]=-(state[7].thd*v7[1]) + a6[2]*S76[2][2] + a6[3]*S76[2][3];
a7[3]=a6[1];
a7[4]=state[7].thd*v7[5] - l5*a6[1]*S76[1][2] + a6[5]*S76[1][2] + a6[6]*S76[1][3];
a7[5]=-(state[7].thd*v7[4]) - l5*a6[1]*S76[2][2] + a6[5]*S76[2][2] + a6[6]*S76[2][3];
a7[6]=l5*a6[2] + a6[4];

a8[1]=a7[1]*S87[1][1] + a7[2]*S87[1][2] + a7[3]*S87[1][3];
a8[2]=a7[1]*S87[2][1] + a7[2]*S87[2][2] + a7[3]*S87[2][3];
a8[3]=a7[1]*S87[3][1] + a7[2]*S87[3][2] + a7[3]*S87[3][3];
a8[4]=a7[4]*S87[1][1] + a7[5]*S87[1][2] + a7[3]*(-(eff[1].x[2]*S87[1][1]) + eff[1].x[1]*S87[1][2]) + a7[6]*S87[1][3] + a7[2]*(eff[1].x[3]*S87[1][1] - eff[1].x[1]*S87[1][3]) + a7[1]*(-(eff[1].x[3]*S87[1][2]) + eff[1].x[2]*S87[1][3]);
a8[5]=a7[4]*S87[2][1] + a7[5]*S87[2][2] + a7[3]*(-(eff[1].x[2]*S87[2][1]) + eff[1].x[1]*S87[2][2]) + a7[6]*S87[2][3] + a7[2]*(eff[1].x[3]*S87[2][1] - eff[1].x[1]*S87[2][3]) + a7[1]*(-(eff[1].x[3]*S87[2][2]) + eff[1].x[2]*S87[2][3]);
a8[6]=a7[4]*S87[3][1] + a7[5]*S87[3][2] + a7[3]*(-(eff[1].x[2]*S87[3][1]) + eff[1].x[1]*S87[3][2]) + a7[6]*S87[3][3] + a7[2]*(eff[1].x[3]*S87[3][1] - eff[1].x[1]*S87[3][3]) + a7[1]*(-(eff[1].x[3]*S87[3][2]) + eff[1].x[2]*S87[3][3]);

a9[1]=state[8].thd*v9[2] + a7[2]*S97[1][2] + a7[3]*S97[1][3];
a9[2]=-(state[8].thd*v9[1]) + a7[2]*S97[2][2] + a7[3]*S97[2][3];
a9[3]=-a7[1];
a9[4]=state[8].thd*v9[5] - l7z*a7[1]*S97[1][2] - l6x*a7[3]*S97[1][2] + a7[5]*S97[1][2] + l6x*a7[2]*S97[1][3] + a7[6]*S97[1][3];
a9[5]=-(state[8].thd*v9[4]) - l7z*a7[1]*S97[2][2] - l6x*a7[3]*S97[2][2] + a7[5]*S97[2][2] + l6x*a7[2]*S97[2][3] + a7[6]*S97[2][3];
a9[6]=-(l7z*a7[2]) - a7[4];

a10[1]=state[9].thd*v10[2] + a9[2]*S109[1][2] + a9[3]*S109[1][3];
a10[2]=-(state[9].thd*v10[1]) + a9[2]*S109[2][2] + a9[3]*S109[2][3];
a10[3]=a9[1];
a10[4]=state[9].thd*v10[5] + a9[5]*S109[1][2] + a9[6]*S109[1][3];
a10[5]=-(state[9].thd*v10[4]) + a9[5]*S109[2][2] + a9[6]*S109[2][3];
a10[6]=a9[4];

a11[1]=a10[1];
a11[2]=a10[2];
a11[3]=a10[3];
a11[4]=-(l8*a10[3]) + a10[4];
a11[5]=a10[5];
a11[6]=l8*a10[1] + a10[6];

a12[1]=state[10].thd*v12[2] + a7[1]*S127[1][1] + a7[2]*S127[1][2];
a12[2]=-(state[10].thd*v12[1]) + a7[1]*S127[2][1] + a7[2]*S127[2][2];
a12[3]=a7[3];
a12[4]=state[10].thd*v12[5] + l6z*a7[2]*S127[1][1] + a7[4]*S127[1][1] - l6z*a7[1]*S127[1][2] + a7[5]*S127[1][2] + a7[3]*(-(l6y*S127[1][1]) - l6x*S127[1][2]);
a12[5]=-(state[10].thd*v12[4]) + l6z*a7[2]*S127[2][1] + a7[4]*S127[2][1] - l6z*a7[1]*S127[2][2] + a7[5]*S127[2][2] + a7[3]*(-(l6y*S127[2][1]) - l6x*S127[2][2]);
a12[6]=l6y*a7[1] + l6x*a7[2] + a7[6];

a13[1]=a12[1];
a13[2]=a12[2];
a13[3]=a12[3];
a13[4]=-(l9*a12[3]) + a12[4];
a13[5]=a12[5];
a13[6]=l9*a12[1] + a12[6];



}


void
master_ForDynCompfunc6(void)
     {
/* net forces and external forces for each joint */
fnet0[1]=links[0].m*a0[4] - links[0].mcm[1]*Power(v0[2],2) - links[0].mcm[1]*Power(v0[3],2) + v0[1]*(links[0].mcm[2]*v0[2] + links[0].mcm[3]*v0[3]) - links[0].m*v0[3]*v0[5] + links[0].m*v0[2]*v0[6];
fnet0[2]=links[0].m*a0[5] - links[0].mcm[2]*Power(v0[1],2) - links[0].mcm[2]*Power(v0[3],2) + v0[2]*(links[0].mcm[1]*v0[1] + links[0].mcm[3]*v0[3]) + links[0].m*v0[3]*v0[4] - links[0].m*v0[1]*v0[6];
fnet0[3]=links[0].m*a0[6] - links[0].mcm[3]*Power(v0[1],2) - links[0].mcm[3]*Power(v0[2],2) + (links[0].mcm[1]*v0[1] + links[0].mcm[2]*v0[2])*v0[3] - links[0].m*v0[2]*v0[4] + links[0].m*v0[1]*v0[5];
fnet0[4]=a0[6]*links[0].mcm[2] - a0[5]*links[0].mcm[3] + (-(links[0].mcm[2]*v0[2]) - links[0].mcm[3]*v0[3])*v0[4] + (links[0].mcm[1]*v0[3] + links[0].m*v0[5])*v0[6] + v0[5]*(links[0].mcm[1]*v0[2] - links[0].m*v0[6]) + v0[1]*(links[0].mcm[2]*v0[5] + links[0].mcm[3]*v0[6] - v0[3]*links[0].inertia[1][2] + v0[2]*links[0].inertia[1][3]) + v0[2]*(-(links[0].mcm[1]*v0[5]) - v0[3]*links[0].inertia[2][2] + v0[2]*links[0].inertia[2][3]) + v0[3]*(-(links[0].mcm[1]*v0[6]) - v0[3]*links[0].inertia[2][3] + v0[2]*links[0].inertia[3][3]);
fnet0[5]=-(a0[6]*links[0].mcm[1]) + a0[4]*links[0].mcm[3] + (-(links[0].mcm[1]*v0[1]) - links[0].mcm[3]*v0[3])*v0[5] + (links[0].mcm[2]*v0[3] - links[0].m*v0[4])*v0[6] + v0[4]*(links[0].mcm[2]*v0[1] + links[0].m*v0[6]) + v0[1]*(-(links[0].mcm[2]*v0[4]) + v0[3]*links[0].inertia[1][1] - v0[1]*links[0].inertia[1][3]) + v0[2]*(links[0].mcm[1]*v0[4] + links[0].mcm[3]*v0[6] + v0[3]*links[0].inertia[1][2] - v0[1]*links[0].inertia[2][3]) + v0[3]*(-(links[0].mcm[2]*v0[6]) + v0[3]*links[0].inertia[1][3] - v0[1]*links[0].inertia[3][3]);
fnet0[6]=a0[5]*links[0].mcm[1] - a0[4]*links[0].mcm[2] + (links[0].mcm[3]*v0[2] + links[0].m*v0[4])*v0[5] + v0[4]*(links[0].mcm[3]*v0[1] - links[0].m*v0[5]) + (-(links[0].mcm[1]*v0[1]) - links[0].mcm[2]*v0[2])*v0[6] + v0[1]*(-(links[0].mcm[3]*v0[4]) - v0[2]*links[0].inertia[1][1] + v0[1]*links[0].inertia[1][2]) + v0[2]*(-(links[0].mcm[3]*v0[5]) - v0[2]*links[0].inertia[1][2] + v0[1]*links[0].inertia[2][2]) + v0[3]*(links[0].mcm[1]*v0[4] + links[0].mcm[2]*v0[5] - v0[2]*links[0].inertia[1][3] + v0[1]*links[0].inertia[2][3]);

fnet1[1]=links[1].m*a1[4] + a1[2]*links[1].mcm[3] - links[1].mcm[1]*Power(v1[2],2) - links[1].mcm[1]*Power(v1[3],2) + v1[1]*(links[1].mcm[2]*v1[2] + links[1].mcm[3]*v1[3]) - links[1].m*v1[3]*v1[5] + links[1].m*v1[2]*v1[6];
fnet1[2]=links[1].m*a1[5] - a1[1]*links[1].mcm[3] - links[1].mcm[2]*Power(v1[1],2) - links[1].mcm[2]*Power(v1[3],2) + v1[2]*(links[1].mcm[1]*v1[1] + links[1].mcm[3]*v1[3]) + links[1].m*v1[3]*v1[4] - links[1].m*v1[1]*v1[6];
fnet1[3]=links[1].m*a1[6] - a1[2]*links[1].mcm[1] + a1[1]*links[1].mcm[2] - links[1].mcm[3]*Power(v1[1],2) - links[1].mcm[3]*Power(v1[2],2) + (links[1].mcm[1]*v1[1] + links[1].mcm[2]*v1[2])*v1[3] - links[1].m*v1[2]*v1[4] + links[1].m*v1[1]*v1[5];
fnet1[4]=a1[6]*links[1].mcm[2] - a1[5]*links[1].mcm[3] + (-(links[1].mcm[2]*v1[2]) - links[1].mcm[3]*v1[3])*v1[4] + (links[1].mcm[1]*v1[3] + links[1].m*v1[5])*v1[6] + v1[5]*(links[1].mcm[1]*v1[2] - links[1].m*v1[6]) + a1[1]*links[1].inertia[1][1] + a1[2]*links[1].inertia[1][2] + v1[1]*(links[1].mcm[2]*v1[5] + links[1].mcm[3]*v1[6] - v1[3]*links[1].inertia[1][2] + v1[2]*links[1].inertia[1][3]) + v1[2]*(-(links[1].mcm[1]*v1[5]) - v1[3]*links[1].inertia[2][2] + v1[2]*links[1].inertia[2][3]) + v1[3]*(-(links[1].mcm[1]*v1[6]) - v1[3]*links[1].inertia[2][3] + v1[2]*links[1].inertia[3][3]);
fnet1[5]=-(a1[6]*links[1].mcm[1]) + a1[4]*links[1].mcm[3] + (-(links[1].mcm[1]*v1[1]) - links[1].mcm[3]*v1[3])*v1[5] + (links[1].mcm[2]*v1[3] - links[1].m*v1[4])*v1[6] + v1[4]*(links[1].mcm[2]*v1[1] + links[1].m*v1[6]) + a1[1]*links[1].inertia[1][2] + v1[1]*(-(links[1].mcm[2]*v1[4]) + v1[3]*links[1].inertia[1][1] - v1[1]*links[1].inertia[1][3]) + a1[2]*links[1].inertia[2][2] + v1[2]*(links[1].mcm[1]*v1[4] + links[1].mcm[3]*v1[6] + v1[3]*links[1].inertia[1][2] - v1[1]*links[1].inertia[2][3]) + v1[3]*(-(links[1].mcm[2]*v1[6]) + v1[3]*links[1].inertia[1][3] - v1[1]*links[1].inertia[3][3]);
fnet1[6]=a1[5]*links[1].mcm[1] - a1[4]*links[1].mcm[2] + (links[1].mcm[3]*v1[2] + links[1].m*v1[4])*v1[5] + v1[4]*(links[1].mcm[3]*v1[1] - links[1].m*v1[5]) + (-(links[1].mcm[1]*v1[1]) - links[1].mcm[2]*v1[2])*v1[6] + v1[1]*(-(links[1].mcm[3]*v1[4]) - v1[2]*links[1].inertia[1][1] + v1[1]*links[1].inertia[1][2]) + a1[1]*links[1].inertia[1][3] + v1[2]*(-(links[1].mcm[3]*v1[5]) - v1[2]*links[1].inertia[1][2] + v1[1]*links[1].inertia[2][2]) + a1[2]*links[1].inertia[2][3] + v1[3]*(links[1].mcm[1]*v1[4] + links[1].mcm[2]*v1[5] - v1[2]*links[1].inertia[1][3] + v1[1]*links[1].inertia[2][3]);

fnet2[1]=links[2].m*a2[4] - a2[3]*links[2].mcm[2] + a2[2]*links[2].mcm[3] - links[2].mcm[1]*Power(v2[2],2) - links[2].mcm[1]*Power(v2[3],2) + v2[1]*(links[2].mcm[2]*v2[2] + links[2].mcm[3]*v2[3]) - links[2].m*v2[3]*v2[5] + links[2].m*v2[2]*v2[6];
fnet2[2]=links[2].m*a2[5] + a2[3]*links[2].mcm[1] - a2[1]*links[2].mcm[3] - links[2].mcm[2]*Power(v2[1],2) - links[2].mcm[2]*Power(v2[3],2) + v2[2]*(links[2].mcm[1]*v2[1] + links[2].mcm[3]*v2[3]) + links[2].m*v2[3]*v2[4] - links[2].m*v2[1]*v2[6];
fnet2[3]=links[2].m*a2[6] - a2[2]*links[2].mcm[1] + a2[1]*links[2].mcm[2] - links[2].mcm[3]*Power(v2[1],2) - links[2].mcm[3]*Power(v2[2],2) + (links[2].mcm[1]*v2[1] + links[2].mcm[2]*v2[2])*v2[3] - links[2].m*v2[2]*v2[4] + links[2].m*v2[1]*v2[5];
fnet2[4]=a2[6]*links[2].mcm[2] - a2[5]*links[2].mcm[3] + (-(links[2].mcm[2]*v2[2]) - links[2].mcm[3]*v2[3])*v2[4] + (links[2].mcm[1]*v2[3] + links[2].m*v2[5])*v2[6] + v2[5]*(links[2].mcm[1]*v2[2] - links[2].m*v2[6]) + a2[1]*links[2].inertia[1][1] + a2[2]*links[2].inertia[1][2] + a2[3]*links[2].inertia[1][3] + v2[1]*(links[2].mcm[2]*v2[5] + links[2].mcm[3]*v2[6] - v2[3]*links[2].inertia[1][2] + v2[2]*links[2].inertia[1][3]) + v2[2]*(-(links[2].mcm[1]*v2[5]) - v2[3]*links[2].inertia[2][2] + v2[2]*links[2].inertia[2][3]) + v2[3]*(-(links[2].mcm[1]*v2[6]) - v2[3]*links[2].inertia[2][3] + v2[2]*links[2].inertia[3][3]);
fnet2[5]=-(a2[6]*links[2].mcm[1]) + a2[4]*links[2].mcm[3] + (-(links[2].mcm[1]*v2[1]) - links[2].mcm[3]*v2[3])*v2[5] + (links[2].mcm[2]*v2[3] - links[2].m*v2[4])*v2[6] + v2[4]*(links[2].mcm[2]*v2[1] + links[2].m*v2[6]) + a2[1]*links[2].inertia[1][2] + v2[1]*(-(links[2].mcm[2]*v2[4]) + v2[3]*links[2].inertia[1][1] - v2[1]*links[2].inertia[1][3]) + a2[2]*links[2].inertia[2][2] + a2[3]*links[2].inertia[2][3] + v2[2]*(links[2].mcm[1]*v2[4] + links[2].mcm[3]*v2[6] + v2[3]*links[2].inertia[1][2] - v2[1]*links[2].inertia[2][3]) + v2[3]*(-(links[2].mcm[2]*v2[6]) + v2[3]*links[2].inertia[1][3] - v2[1]*links[2].inertia[3][3]);
fnet2[6]=a2[5]*links[2].mcm[1] - a2[4]*links[2].mcm[2] + (links[2].mcm[3]*v2[2] + links[2].m*v2[4])*v2[5] + v2[4]*(links[2].mcm[3]*v2[1] - links[2].m*v2[5]) + (-(links[2].mcm[1]*v2[1]) - links[2].mcm[2]*v2[2])*v2[6] + v2[1]*(-(links[2].mcm[3]*v2[4]) - v2[2]*links[2].inertia[1][1] + v2[1]*links[2].inertia[1][2]) + a2[1]*links[2].inertia[1][3] + v2[2]*(-(links[2].mcm[3]*v2[5]) - v2[2]*links[2].inertia[1][2] + v2[1]*links[2].inertia[2][2]) + a2[2]*links[2].inertia[2][3] + v2[3]*(links[2].mcm[1]*v2[4] + links[2].mcm[2]*v2[5] - v2[2]*links[2].inertia[1][3] + v2[1]*links[2].inertia[2][3]) + a2[3]*links[2].inertia[3][3];

fnet3[1]=links[3].m*a3[4] - a3[3]*links[3].mcm[2] + a3[2]*links[3].mcm[3] - links[3].mcm[1]*Power(v3[2],2) - links[3].mcm[1]*Power(v3[3],2) + v3[1]*(links[3].mcm[2]*v3[2] + links[3].mcm[3]*v3[3]) - links[3].m*v3[3]*v3[5] + links[3].m*v3[2]*v3[6];
fnet3[2]=links[3].m*a3[5] + a3[3]*links[3].mcm[1] - a3[1]*links[3].mcm[3] - links[3].mcm[2]*Power(v3[1],2) - links[3].mcm[2]*Power(v3[3],2) + v3[2]*(links[3].mcm[1]*v3[1] + links[3].mcm[3]*v3[3]) + links[3].m*v3[3]*v3[4] - links[3].m*v3[1]*v3[6];
fnet3[3]=links[3].m*a3[6] - a3[2]*links[3].mcm[1] + a3[1]*links[3].mcm[2] - links[3].mcm[3]*Power(v3[1],2) - links[3].mcm[3]*Power(v3[2],2) + (links[3].mcm[1]*v3[1] + links[3].mcm[2]*v3[2])*v3[3] - links[3].m*v3[2]*v3[4] + links[3].m*v3[1]*v3[5];
fnet3[4]=a3[6]*links[3].mcm[2] - a3[5]*links[3].mcm[3] + (-(links[3].mcm[2]*v3[2]) - links[3].mcm[3]*v3[3])*v3[4] + (links[3].mcm[1]*v3[3] + links[3].m*v3[5])*v3[6] + v3[5]*(links[3].mcm[1]*v3[2] - links[3].m*v3[6]) + a3[1]*links[3].inertia[1][1] + a3[2]*links[3].inertia[1][2] + a3[3]*links[3].inertia[1][3] + v3[1]*(links[3].mcm[2]*v3[5] + links[3].mcm[3]*v3[6] - v3[3]*links[3].inertia[1][2] + v3[2]*links[3].inertia[1][3]) + v3[2]*(-(links[3].mcm[1]*v3[5]) - v3[3]*links[3].inertia[2][2] + v3[2]*links[3].inertia[2][3]) + v3[3]*(-(links[3].mcm[1]*v3[6]) - v3[3]*links[3].inertia[2][3] + v3[2]*links[3].inertia[3][3]);
fnet3[5]=-(a3[6]*links[3].mcm[1]) + a3[4]*links[3].mcm[3] + (-(links[3].mcm[1]*v3[1]) - links[3].mcm[3]*v3[3])*v3[5] + (links[3].mcm[2]*v3[3] - links[3].m*v3[4])*v3[6] + v3[4]*(links[3].mcm[2]*v3[1] + links[3].m*v3[6]) + a3[1]*links[3].inertia[1][2] + v3[1]*(-(links[3].mcm[2]*v3[4]) + v3[3]*links[3].inertia[1][1] - v3[1]*links[3].inertia[1][3]) + a3[2]*links[3].inertia[2][2] + a3[3]*links[3].inertia[2][3] + v3[2]*(links[3].mcm[1]*v3[4] + links[3].mcm[3]*v3[6] + v3[3]*links[3].inertia[1][2] - v3[1]*links[3].inertia[2][3]) + v3[3]*(-(links[3].mcm[2]*v3[6]) + v3[3]*links[3].inertia[1][3] - v3[1]*links[3].inertia[3][3]);
fnet3[6]=a3[5]*links[3].mcm[1] - a3[4]*links[3].mcm[2] + (links[3].mcm[3]*v3[2] + links[3].m*v3[4])*v3[5] + v3[4]*(links[3].mcm[3]*v3[1] - links[3].m*v3[5]) + (-(links[3].mcm[1]*v3[1]) - links[3].mcm[2]*v3[2])*v3[6] + v3[1]*(-(links[3].mcm[3]*v3[4]) - v3[2]*links[3].inertia[1][1] + v3[1]*links[3].inertia[1][2]) + a3[1]*links[3].inertia[1][3] + v3[2]*(-(links[3].mcm[3]*v3[5]) - v3[2]*links[3].inertia[1][2] + v3[1]*links[3].inertia[2][2]) + a3[2]*links[3].inertia[2][3] + v3[3]*(links[3].mcm[1]*v3[4] + links[3].mcm[2]*v3[5] - v3[2]*links[3].inertia[1][3] + v3[1]*links[3].inertia[2][3]) + a3[3]*links[3].inertia[3][3];

fnet4[1]=links[4].m*a4[4] - a4[3]*links[4].mcm[2] + a4[2]*links[4].mcm[3] - links[4].mcm[1]*Power(v4[2],2) - links[4].mcm[1]*Power(v4[3],2) + v4[1]*(links[4].mcm[2]*v4[2] + links[4].mcm[3]*v4[3]) - links[4].m*v4[3]*v4[5] + links[4].m*v4[2]*v4[6];
fnet4[2]=links[4].m*a4[5] + a4[3]*links[4].mcm[1] - a4[1]*links[4].mcm[3] - links[4].mcm[2]*Power(v4[1],2) - links[4].mcm[2]*Power(v4[3],2) + v4[2]*(links[4].mcm[1]*v4[1] + links[4].mcm[3]*v4[3]) + links[4].m*v4[3]*v4[4] - links[4].m*v4[1]*v4[6];
fnet4[3]=links[4].m*a4[6] - a4[2]*links[4].mcm[1] + a4[1]*links[4].mcm[2] - links[4].mcm[3]*Power(v4[1],2) - links[4].mcm[3]*Power(v4[2],2) + (links[4].mcm[1]*v4[1] + links[4].mcm[2]*v4[2])*v4[3] - links[4].m*v4[2]*v4[4] + links[4].m*v4[1]*v4[5];
fnet4[4]=a4[6]*links[4].mcm[2] - a4[5]*links[4].mcm[3] + (-(links[4].mcm[2]*v4[2]) - links[4].mcm[3]*v4[3])*v4[4] + (links[4].mcm[1]*v4[3] + links[4].m*v4[5])*v4[6] + v4[5]*(links[4].mcm[1]*v4[2] - links[4].m*v4[6]) + a4[1]*links[4].inertia[1][1] + a4[2]*links[4].inertia[1][2] + a4[3]*links[4].inertia[1][3] + v4[1]*(links[4].mcm[2]*v4[5] + links[4].mcm[3]*v4[6] - v4[3]*links[4].inertia[1][2] + v4[2]*links[4].inertia[1][3]) + v4[2]*(-(links[4].mcm[1]*v4[5]) - v4[3]*links[4].inertia[2][2] + v4[2]*links[4].inertia[2][3]) + v4[3]*(-(links[4].mcm[1]*v4[6]) - v4[3]*links[4].inertia[2][3] + v4[2]*links[4].inertia[3][3]);
fnet4[5]=-(a4[6]*links[4].mcm[1]) + a4[4]*links[4].mcm[3] + (-(links[4].mcm[1]*v4[1]) - links[4].mcm[3]*v4[3])*v4[5] + (links[4].mcm[2]*v4[3] - links[4].m*v4[4])*v4[6] + v4[4]*(links[4].mcm[2]*v4[1] + links[4].m*v4[6]) + a4[1]*links[4].inertia[1][2] + v4[1]*(-(links[4].mcm[2]*v4[4]) + v4[3]*links[4].inertia[1][1] - v4[1]*links[4].inertia[1][3]) + a4[2]*links[4].inertia[2][2] + a4[3]*links[4].inertia[2][3] + v4[2]*(links[4].mcm[1]*v4[4] + links[4].mcm[3]*v4[6] + v4[3]*links[4].inertia[1][2] - v4[1]*links[4].inertia[2][3]) + v4[3]*(-(links[4].mcm[2]*v4[6]) + v4[3]*links[4].inertia[1][3] - v4[1]*links[4].inertia[3][3]);
fnet4[6]=a4[5]*links[4].mcm[1] - a4[4]*links[4].mcm[2] + (links[4].mcm[3]*v4[2] + links[4].m*v4[4])*v4[5] + v4[4]*(links[4].mcm[3]*v4[1] - links[4].m*v4[5]) + (-(links[4].mcm[1]*v4[1]) - links[4].mcm[2]*v4[2])*v4[6] + v4[1]*(-(links[4].mcm[3]*v4[4]) - v4[2]*links[4].inertia[1][1] + v4[1]*links[4].inertia[1][2]) + a4[1]*links[4].inertia[1][3] + v4[2]*(-(links[4].mcm[3]*v4[5]) - v4[2]*links[4].inertia[1][2] + v4[1]*links[4].inertia[2][2]) + a4[2]*links[4].inertia[2][3] + v4[3]*(links[4].mcm[1]*v4[4] + links[4].mcm[2]*v4[5] - v4[2]*links[4].inertia[1][3] + v4[1]*links[4].inertia[2][3]) + a4[3]*links[4].inertia[3][3];

fnet5[1]=links[5].m*a5[4] - a5[3]*links[5].mcm[2] + a5[2]*links[5].mcm[3] - links[5].mcm[1]*Power(v5[2],2) - links[5].mcm[1]*Power(v5[3],2) + v5[1]*(links[5].mcm[2]*v5[2] + links[5].mcm[3]*v5[3]) - links[5].m*v5[3]*v5[5] + links[5].m*v5[2]*v5[6];
fnet5[2]=links[5].m*a5[5] + a5[3]*links[5].mcm[1] - a5[1]*links[5].mcm[3] - links[5].mcm[2]*Power(v5[1],2) - links[5].mcm[2]*Power(v5[3],2) + v5[2]*(links[5].mcm[1]*v5[1] + links[5].mcm[3]*v5[3]) + links[5].m*v5[3]*v5[4] - links[5].m*v5[1]*v5[6];
fnet5[3]=links[5].m*a5[6] - a5[2]*links[5].mcm[1] + a5[1]*links[5].mcm[2] - links[5].mcm[3]*Power(v5[1],2) - links[5].mcm[3]*Power(v5[2],2) + (links[5].mcm[1]*v5[1] + links[5].mcm[2]*v5[2])*v5[3] - links[5].m*v5[2]*v5[4] + links[5].m*v5[1]*v5[5];
fnet5[4]=a5[6]*links[5].mcm[2] - a5[5]*links[5].mcm[3] + (-(links[5].mcm[2]*v5[2]) - links[5].mcm[3]*v5[3])*v5[4] + (links[5].mcm[1]*v5[3] + links[5].m*v5[5])*v5[6] + v5[5]*(links[5].mcm[1]*v5[2] - links[5].m*v5[6]) + a5[1]*links[5].inertia[1][1] + a5[2]*links[5].inertia[1][2] + a5[3]*links[5].inertia[1][3] + v5[1]*(links[5].mcm[2]*v5[5] + links[5].mcm[3]*v5[6] - v5[3]*links[5].inertia[1][2] + v5[2]*links[5].inertia[1][3]) + v5[2]*(-(links[5].mcm[1]*v5[5]) - v5[3]*links[5].inertia[2][2] + v5[2]*links[5].inertia[2][3]) + v5[3]*(-(links[5].mcm[1]*v5[6]) - v5[3]*links[5].inertia[2][3] + v5[2]*links[5].inertia[3][3]);
fnet5[5]=-(a5[6]*links[5].mcm[1]) + a5[4]*links[5].mcm[3] + (-(links[5].mcm[1]*v5[1]) - links[5].mcm[3]*v5[3])*v5[5] + (links[5].mcm[2]*v5[3] - links[5].m*v5[4])*v5[6] + v5[4]*(links[5].mcm[2]*v5[1] + links[5].m*v5[6]) + a5[1]*links[5].inertia[1][2] + v5[1]*(-(links[5].mcm[2]*v5[4]) + v5[3]*links[5].inertia[1][1] - v5[1]*links[5].inertia[1][3]) + a5[2]*links[5].inertia[2][2] + a5[3]*links[5].inertia[2][3] + v5[2]*(links[5].mcm[1]*v5[4] + links[5].mcm[3]*v5[6] + v5[3]*links[5].inertia[1][2] - v5[1]*links[5].inertia[2][3]) + v5[3]*(-(links[5].mcm[2]*v5[6]) + v5[3]*links[5].inertia[1][3] - v5[1]*links[5].inertia[3][3]);
fnet5[6]=a5[5]*links[5].mcm[1] - a5[4]*links[5].mcm[2] + (links[5].mcm[3]*v5[2] + links[5].m*v5[4])*v5[5] + v5[4]*(links[5].mcm[3]*v5[1] - links[5].m*v5[5]) + (-(links[5].mcm[1]*v5[1]) - links[5].mcm[2]*v5[2])*v5[6] + v5[1]*(-(links[5].mcm[3]*v5[4]) - v5[2]*links[5].inertia[1][1] + v5[1]*links[5].inertia[1][2]) + a5[1]*links[5].inertia[1][3] + v5[2]*(-(links[5].mcm[3]*v5[5]) - v5[2]*links[5].inertia[1][2] + v5[1]*links[5].inertia[2][2]) + a5[2]*links[5].inertia[2][3] + v5[3]*(links[5].mcm[1]*v5[4] + links[5].mcm[2]*v5[5] - v5[2]*links[5].inertia[1][3] + v5[1]*links[5].inertia[2][3]) + a5[3]*links[5].inertia[3][3];

fnet6[1]=links[6].m*a6[4] - a6[3]*links[6].mcm[2] + a6[2]*links[6].mcm[3] - links[6].mcm[1]*Power(v6[2],2) - links[6].mcm[1]*Power(v6[3],2) + v6[1]*(links[6].mcm[2]*v6[2] + links[6].mcm[3]*v6[3]) - links[6].m*v6[3]*v6[5] + links[6].m*v6[2]*v6[6];
fnet6[2]=links[6].m*a6[5] + a6[3]*links[6].mcm[1] - a6[1]*links[6].mcm[3] - links[6].mcm[2]*Power(v6[1],2) - links[6].mcm[2]*Power(v6[3],2) + v6[2]*(links[6].mcm[1]*v6[1] + links[6].mcm[3]*v6[3]) + links[6].m*v6[3]*v6[4] - links[6].m*v6[1]*v6[6];
fnet6[3]=links[6].m*a6[6] - a6[2]*links[6].mcm[1] + a6[1]*links[6].mcm[2] - links[6].mcm[3]*Power(v6[1],2) - links[6].mcm[3]*Power(v6[2],2) + (links[6].mcm[1]*v6[1] + links[6].mcm[2]*v6[2])*v6[3] - links[6].m*v6[2]*v6[4] + links[6].m*v6[1]*v6[5];
fnet6[4]=a6[6]*links[6].mcm[2] - a6[5]*links[6].mcm[3] + (-(links[6].mcm[2]*v6[2]) - links[6].mcm[3]*v6[3])*v6[4] + (links[6].mcm[1]*v6[3] + links[6].m*v6[5])*v6[6] + v6[5]*(links[6].mcm[1]*v6[2] - links[6].m*v6[6]) + a6[1]*links[6].inertia[1][1] + a6[2]*links[6].inertia[1][2] + a6[3]*links[6].inertia[1][3] + v6[1]*(links[6].mcm[2]*v6[5] + links[6].mcm[3]*v6[6] - v6[3]*links[6].inertia[1][2] + v6[2]*links[6].inertia[1][3]) + v6[2]*(-(links[6].mcm[1]*v6[5]) - v6[3]*links[6].inertia[2][2] + v6[2]*links[6].inertia[2][3]) + v6[3]*(-(links[6].mcm[1]*v6[6]) - v6[3]*links[6].inertia[2][3] + v6[2]*links[6].inertia[3][3]);
fnet6[5]=-(a6[6]*links[6].mcm[1]) + a6[4]*links[6].mcm[3] + (-(links[6].mcm[1]*v6[1]) - links[6].mcm[3]*v6[3])*v6[5] + (links[6].mcm[2]*v6[3] - links[6].m*v6[4])*v6[6] + v6[4]*(links[6].mcm[2]*v6[1] + links[6].m*v6[6]) + a6[1]*links[6].inertia[1][2] + v6[1]*(-(links[6].mcm[2]*v6[4]) + v6[3]*links[6].inertia[1][1] - v6[1]*links[6].inertia[1][3]) + a6[2]*links[6].inertia[2][2] + a6[3]*links[6].inertia[2][3] + v6[2]*(links[6].mcm[1]*v6[4] + links[6].mcm[3]*v6[6] + v6[3]*links[6].inertia[1][2] - v6[1]*links[6].inertia[2][3]) + v6[3]*(-(links[6].mcm[2]*v6[6]) + v6[3]*links[6].inertia[1][3] - v6[1]*links[6].inertia[3][3]);
fnet6[6]=a6[5]*links[6].mcm[1] - a6[4]*links[6].mcm[2] + (links[6].mcm[3]*v6[2] + links[6].m*v6[4])*v6[5] + v6[4]*(links[6].mcm[3]*v6[1] - links[6].m*v6[5]) + (-(links[6].mcm[1]*v6[1]) - links[6].mcm[2]*v6[2])*v6[6] + v6[1]*(-(links[6].mcm[3]*v6[4]) - v6[2]*links[6].inertia[1][1] + v6[1]*links[6].inertia[1][2]) + a6[1]*links[6].inertia[1][3] + v6[2]*(-(links[6].mcm[3]*v6[5]) - v6[2]*links[6].inertia[1][2] + v6[1]*links[6].inertia[2][2]) + a6[2]*links[6].inertia[2][3] + v6[3]*(links[6].mcm[1]*v6[4] + links[6].mcm[2]*v6[5] - v6[2]*links[6].inertia[1][3] + v6[1]*links[6].inertia[2][3]) + a6[3]*links[6].inertia[3][3];

fnet7[1]=links[7].m*a7[4] - a7[3]*links[7].mcm[2] + a7[2]*links[7].mcm[3] - links[7].mcm[1]*Power(v7[2],2) - links[7].mcm[1]*Power(v7[3],2) + v7[1]*(links[7].mcm[2]*v7[2] + links[7].mcm[3]*v7[3]) - links[7].m*v7[3]*v7[5] + links[7].m*v7[2]*v7[6];
fnet7[2]=links[7].m*a7[5] + a7[3]*links[7].mcm[1] - a7[1]*links[7].mcm[3] - links[7].mcm[2]*Power(v7[1],2) - links[7].mcm[2]*Power(v7[3],2) + v7[2]*(links[7].mcm[1]*v7[1] + links[7].mcm[3]*v7[3]) + links[7].m*v7[3]*v7[4] - links[7].m*v7[1]*v7[6];
fnet7[3]=links[7].m*a7[6] - a7[2]*links[7].mcm[1] + a7[1]*links[7].mcm[2] - links[7].mcm[3]*Power(v7[1],2) - links[7].mcm[3]*Power(v7[2],2) + (links[7].mcm[1]*v7[1] + links[7].mcm[2]*v7[2])*v7[3] - links[7].m*v7[2]*v7[4] + links[7].m*v7[1]*v7[5];
fnet7[4]=a7[6]*links[7].mcm[2] - a7[5]*links[7].mcm[3] + (-(links[7].mcm[2]*v7[2]) - links[7].mcm[3]*v7[3])*v7[4] + (links[7].mcm[1]*v7[3] + links[7].m*v7[5])*v7[6] + v7[5]*(links[7].mcm[1]*v7[2] - links[7].m*v7[6]) + a7[1]*links[7].inertia[1][1] + a7[2]*links[7].inertia[1][2] + a7[3]*links[7].inertia[1][3] + v7[1]*(links[7].mcm[2]*v7[5] + links[7].mcm[3]*v7[6] - v7[3]*links[7].inertia[1][2] + v7[2]*links[7].inertia[1][3]) + v7[2]*(-(links[7].mcm[1]*v7[5]) - v7[3]*links[7].inertia[2][2] + v7[2]*links[7].inertia[2][3]) + v7[3]*(-(links[7].mcm[1]*v7[6]) - v7[3]*links[7].inertia[2][3] + v7[2]*links[7].inertia[3][3]);
fnet7[5]=-(a7[6]*links[7].mcm[1]) + a7[4]*links[7].mcm[3] + (-(links[7].mcm[1]*v7[1]) - links[7].mcm[3]*v7[3])*v7[5] + (links[7].mcm[2]*v7[3] - links[7].m*v7[4])*v7[6] + v7[4]*(links[7].mcm[2]*v7[1] + links[7].m*v7[6]) + a7[1]*links[7].inertia[1][2] + v7[1]*(-(links[7].mcm[2]*v7[4]) + v7[3]*links[7].inertia[1][1] - v7[1]*links[7].inertia[1][3]) + a7[2]*links[7].inertia[2][2] + a7[3]*links[7].inertia[2][3] + v7[2]*(links[7].mcm[1]*v7[4] + links[7].mcm[3]*v7[6] + v7[3]*links[7].inertia[1][2] - v7[1]*links[7].inertia[2][3]) + v7[3]*(-(links[7].mcm[2]*v7[6]) + v7[3]*links[7].inertia[1][3] - v7[1]*links[7].inertia[3][3]);
fnet7[6]=a7[5]*links[7].mcm[1] - a7[4]*links[7].mcm[2] + (links[7].mcm[3]*v7[2] + links[7].m*v7[4])*v7[5] + v7[4]*(links[7].mcm[3]*v7[1] - links[7].m*v7[5]) + (-(links[7].mcm[1]*v7[1]) - links[7].mcm[2]*v7[2])*v7[6] + v7[1]*(-(links[7].mcm[3]*v7[4]) - v7[2]*links[7].inertia[1][1] + v7[1]*links[7].inertia[1][2]) + a7[1]*links[7].inertia[1][3] + v7[2]*(-(links[7].mcm[3]*v7[5]) - v7[2]*links[7].inertia[1][2] + v7[1]*links[7].inertia[2][2]) + a7[2]*links[7].inertia[2][3] + v7[3]*(links[7].mcm[1]*v7[4] + links[7].mcm[2]*v7[5] - v7[2]*links[7].inertia[1][3] + v7[1]*links[7].inertia[2][3]) + a7[3]*links[7].inertia[3][3];

fnet8[1]=eff[1].m*a8[4] - a8[3]*eff[1].mcm[2] + a8[2]*eff[1].mcm[3] - eff[1].mcm[1]*Power(v8[2],2) - eff[1].mcm[1]*Power(v8[3],2) + v8[1]*(eff[1].mcm[2]*v8[2] + eff[1].mcm[3]*v8[3]) - eff[1].m*v8[3]*v8[5] + eff[1].m*v8[2]*v8[6];
fnet8[2]=eff[1].m*a8[5] + a8[3]*eff[1].mcm[1] - a8[1]*eff[1].mcm[3] - eff[1].mcm[2]*Power(v8[1],2) - eff[1].mcm[2]*Power(v8[3],2) + v8[2]*(eff[1].mcm[1]*v8[1] + eff[1].mcm[3]*v8[3]) + eff[1].m*v8[3]*v8[4] - eff[1].m*v8[1]*v8[6];
fnet8[3]=eff[1].m*a8[6] - a8[2]*eff[1].mcm[1] + a8[1]*eff[1].mcm[2] - eff[1].mcm[3]*Power(v8[1],2) - eff[1].mcm[3]*Power(v8[2],2) + (eff[1].mcm[1]*v8[1] + eff[1].mcm[2]*v8[2])*v8[3] - eff[1].m*v8[2]*v8[4] + eff[1].m*v8[1]*v8[5];
fnet8[4]=a8[6]*eff[1].mcm[2] - a8[5]*eff[1].mcm[3] + (-(eff[1].mcm[2]*v8[2]) - eff[1].mcm[3]*v8[3])*v8[4] - eff[1].mcm[1]*v8[2]*v8[5] - eff[1].mcm[1]*v8[3]*v8[6] + (eff[1].mcm[1]*v8[3] + eff[1].m*v8[5])*v8[6] + v8[5]*(eff[1].mcm[1]*v8[2] - eff[1].m*v8[6]) + v8[1]*(eff[1].mcm[2]*v8[5] + eff[1].mcm[3]*v8[6]);
fnet8[5]=-(a8[6]*eff[1].mcm[1]) + a8[4]*eff[1].mcm[3] - eff[1].mcm[2]*v8[1]*v8[4] + (-(eff[1].mcm[1]*v8[1]) - eff[1].mcm[3]*v8[3])*v8[5] - eff[1].mcm[2]*v8[3]*v8[6] + (eff[1].mcm[2]*v8[3] - eff[1].m*v8[4])*v8[6] + v8[4]*(eff[1].mcm[2]*v8[1] + eff[1].m*v8[6]) + v8[2]*(eff[1].mcm[1]*v8[4] + eff[1].mcm[3]*v8[6]);
fnet8[6]=a8[5]*eff[1].mcm[1] - a8[4]*eff[1].mcm[2] - eff[1].mcm[3]*v8[1]*v8[4] - eff[1].mcm[3]*v8[2]*v8[5] + (eff[1].mcm[3]*v8[2] + eff[1].m*v8[4])*v8[5] + v8[4]*(eff[1].mcm[3]*v8[1] - eff[1].m*v8[5]) + v8[3]*(eff[1].mcm[1]*v8[4] + eff[1].mcm[2]*v8[5]) + (-(eff[1].mcm[1]*v8[1]) - eff[1].mcm[2]*v8[2])*v8[6];

fnet9[1]=links[8].m*a9[4] - a9[3]*links[8].mcm[2] + a9[2]*links[8].mcm[3] - links[8].mcm[1]*Power(v9[2],2) - links[8].mcm[1]*Power(v9[3],2) + v9[1]*(links[8].mcm[2]*v9[2] + links[8].mcm[3]*v9[3]) - links[8].m*v9[3]*v9[5] + links[8].m*v9[2]*v9[6];
fnet9[2]=links[8].m*a9[5] + a9[3]*links[8].mcm[1] - a9[1]*links[8].mcm[3] - links[8].mcm[2]*Power(v9[1],2) - links[8].mcm[2]*Power(v9[3],2) + v9[2]*(links[8].mcm[1]*v9[1] + links[8].mcm[3]*v9[3]) + links[8].m*v9[3]*v9[4] - links[8].m*v9[1]*v9[6];
fnet9[3]=links[8].m*a9[6] - a9[2]*links[8].mcm[1] + a9[1]*links[8].mcm[2] - links[8].mcm[3]*Power(v9[1],2) - links[8].mcm[3]*Power(v9[2],2) + (links[8].mcm[1]*v9[1] + links[8].mcm[2]*v9[2])*v9[3] - links[8].m*v9[2]*v9[4] + links[8].m*v9[1]*v9[5];
fnet9[4]=a9[6]*links[8].mcm[2] - a9[5]*links[8].mcm[3] + (-(links[8].mcm[2]*v9[2]) - links[8].mcm[3]*v9[3])*v9[4] + (links[8].mcm[1]*v9[3] + links[8].m*v9[5])*v9[6] + v9[5]*(links[8].mcm[1]*v9[2] - links[8].m*v9[6]) + a9[1]*links[8].inertia[1][1] + a9[2]*links[8].inertia[1][2] + a9[3]*links[8].inertia[1][3] + v9[1]*(links[8].mcm[2]*v9[5] + links[8].mcm[3]*v9[6] - v9[3]*links[8].inertia[1][2] + v9[2]*links[8].inertia[1][3]) + v9[2]*(-(links[8].mcm[1]*v9[5]) - v9[3]*links[8].inertia[2][2] + v9[2]*links[8].inertia[2][3]) + v9[3]*(-(links[8].mcm[1]*v9[6]) - v9[3]*links[8].inertia[2][3] + v9[2]*links[8].inertia[3][3]);
fnet9[5]=-(a9[6]*links[8].mcm[1]) + a9[4]*links[8].mcm[3] + (-(links[8].mcm[1]*v9[1]) - links[8].mcm[3]*v9[3])*v9[5] + (links[8].mcm[2]*v9[3] - links[8].m*v9[4])*v9[6] + v9[4]*(links[8].mcm[2]*v9[1] + links[8].m*v9[6]) + a9[1]*links[8].inertia[1][2] + v9[1]*(-(links[8].mcm[2]*v9[4]) + v9[3]*links[8].inertia[1][1] - v9[1]*links[8].inertia[1][3]) + a9[2]*links[8].inertia[2][2] + a9[3]*links[8].inertia[2][3] + v9[2]*(links[8].mcm[1]*v9[4] + links[8].mcm[3]*v9[6] + v9[3]*links[8].inertia[1][2] - v9[1]*links[8].inertia[2][3]) + v9[3]*(-(links[8].mcm[2]*v9[6]) + v9[3]*links[8].inertia[1][3] - v9[1]*links[8].inertia[3][3]);
fnet9[6]=a9[5]*links[8].mcm[1] - a9[4]*links[8].mcm[2] + (links[8].mcm[3]*v9[2] + links[8].m*v9[4])*v9[5] + v9[4]*(links[8].mcm[3]*v9[1] - links[8].m*v9[5]) + (-(links[8].mcm[1]*v9[1]) - links[8].mcm[2]*v9[2])*v9[6] + v9[1]*(-(links[8].mcm[3]*v9[4]) - v9[2]*links[8].inertia[1][1] + v9[1]*links[8].inertia[1][2]) + a9[1]*links[8].inertia[1][3] + v9[2]*(-(links[8].mcm[3]*v9[5]) - v9[2]*links[8].inertia[1][2] + v9[1]*links[8].inertia[2][2]) + a9[2]*links[8].inertia[2][3] + v9[3]*(links[8].mcm[1]*v9[4] + links[8].mcm[2]*v9[5] - v9[2]*links[8].inertia[1][3] + v9[1]*links[8].inertia[2][3]) + a9[3]*links[8].inertia[3][3];

fnet10[1]=links[9].m*a10[4] - a10[3]*links[9].mcm[2] + a10[2]*links[9].mcm[3] - links[9].mcm[1]*Power(v10[2],2) - links[9].mcm[1]*Power(v10[3],2) + v10[1]*(links[9].mcm[2]*v10[2] + links[9].mcm[3]*v10[3]) - links[9].m*v10[3]*v10[5] + links[9].m*v10[2]*v10[6];
fnet10[2]=links[9].m*a10[5] + a10[3]*links[9].mcm[1] - a10[1]*links[9].mcm[3] - links[9].mcm[2]*Power(v10[1],2) - links[9].mcm[2]*Power(v10[3],2) + v10[2]*(links[9].mcm[1]*v10[1] + links[9].mcm[3]*v10[3]) + links[9].m*v10[3]*v10[4] - links[9].m*v10[1]*v10[6];
fnet10[3]=links[9].m*a10[6] - a10[2]*links[9].mcm[1] + a10[1]*links[9].mcm[2] - links[9].mcm[3]*Power(v10[1],2) - links[9].mcm[3]*Power(v10[2],2) + (links[9].mcm[1]*v10[1] + links[9].mcm[2]*v10[2])*v10[3] - links[9].m*v10[2]*v10[4] + links[9].m*v10[1]*v10[5];
fnet10[4]=a10[6]*links[9].mcm[2] - a10[5]*links[9].mcm[3] + (-(links[9].mcm[2]*v10[2]) - links[9].mcm[3]*v10[3])*v10[4] + (links[9].mcm[1]*v10[3] + links[9].m*v10[5])*v10[6] + v10[5]*(links[9].mcm[1]*v10[2] - links[9].m*v10[6]) + a10[1]*links[9].inertia[1][1] + a10[2]*links[9].inertia[1][2] + a10[3]*links[9].inertia[1][3] + v10[1]*(links[9].mcm[2]*v10[5] + links[9].mcm[3]*v10[6] - v10[3]*links[9].inertia[1][2] + v10[2]*links[9].inertia[1][3]) + v10[2]*(-(links[9].mcm[1]*v10[5]) - v10[3]*links[9].inertia[2][2] + v10[2]*links[9].inertia[2][3]) + v10[3]*(-(links[9].mcm[1]*v10[6]) - v10[3]*links[9].inertia[2][3] + v10[2]*links[9].inertia[3][3]);
fnet10[5]=-(a10[6]*links[9].mcm[1]) + a10[4]*links[9].mcm[3] + (-(links[9].mcm[1]*v10[1]) - links[9].mcm[3]*v10[3])*v10[5] + (links[9].mcm[2]*v10[3] - links[9].m*v10[4])*v10[6] + v10[4]*(links[9].mcm[2]*v10[1] + links[9].m*v10[6]) + a10[1]*links[9].inertia[1][2] + v10[1]*(-(links[9].mcm[2]*v10[4]) + v10[3]*links[9].inertia[1][1] - v10[1]*links[9].inertia[1][3]) + a10[2]*links[9].inertia[2][2] + a10[3]*links[9].inertia[2][3] + v10[2]*(links[9].mcm[1]*v10[4] + links[9].mcm[3]*v10[6] + v10[3]*links[9].inertia[1][2] - v10[1]*links[9].inertia[2][3]) + v10[3]*(-(links[9].mcm[2]*v10[6]) + v10[3]*links[9].inertia[1][3] - v10[1]*links[9].inertia[3][3]);
fnet10[6]=a10[5]*links[9].mcm[1] - a10[4]*links[9].mcm[2] + (links[9].mcm[3]*v10[2] + links[9].m*v10[4])*v10[5] + v10[4]*(links[9].mcm[3]*v10[1] - links[9].m*v10[5]) + (-(links[9].mcm[1]*v10[1]) - links[9].mcm[2]*v10[2])*v10[6] + v10[1]*(-(links[9].mcm[3]*v10[4]) - v10[2]*links[9].inertia[1][1] + v10[1]*links[9].inertia[1][2]) + a10[1]*links[9].inertia[1][3] + v10[2]*(-(links[9].mcm[3]*v10[5]) - v10[2]*links[9].inertia[1][2] + v10[1]*links[9].inertia[2][2]) + a10[2]*links[9].inertia[2][3] + v10[3]*(links[9].mcm[1]*v10[4] + links[9].mcm[2]*v10[5] - v10[2]*links[9].inertia[1][3] + v10[1]*links[9].inertia[2][3]) + a10[3]*links[9].inertia[3][3];

fnet12[1]=links[10].m*a12[4] - a12[3]*links[10].mcm[2] + a12[2]*links[10].mcm[3] - links[10].mcm[1]*Power(v12[2],2) - links[10].mcm[1]*Power(v12[3],2) + v12[1]*(links[10].mcm[2]*v12[2] + links[10].mcm[3]*v12[3]) - links[10].m*v12[3]*v12[5] + links[10].m*v12[2]*v12[6];
fnet12[2]=links[10].m*a12[5] + a12[3]*links[10].mcm[1] - a12[1]*links[10].mcm[3] - links[10].mcm[2]*Power(v12[1],2) - links[10].mcm[2]*Power(v12[3],2) + v12[2]*(links[10].mcm[1]*v12[1] + links[10].mcm[3]*v12[3]) + links[10].m*v12[3]*v12[4] - links[10].m*v12[1]*v12[6];
fnet12[3]=links[10].m*a12[6] - a12[2]*links[10].mcm[1] + a12[1]*links[10].mcm[2] - links[10].mcm[3]*Power(v12[1],2) - links[10].mcm[3]*Power(v12[2],2) + (links[10].mcm[1]*v12[1] + links[10].mcm[2]*v12[2])*v12[3] - links[10].m*v12[2]*v12[4] + links[10].m*v12[1]*v12[5];
fnet12[4]=a12[6]*links[10].mcm[2] - a12[5]*links[10].mcm[3] + (-(links[10].mcm[2]*v12[2]) - links[10].mcm[3]*v12[3])*v12[4] + (links[10].mcm[1]*v12[3] + links[10].m*v12[5])*v12[6] + v12[5]*(links[10].mcm[1]*v12[2] - links[10].m*v12[6]) + a12[1]*links[10].inertia[1][1] + a12[2]*links[10].inertia[1][2] + a12[3]*links[10].inertia[1][3] + v12[1]*(links[10].mcm[2]*v12[5] + links[10].mcm[3]*v12[6] - v12[3]*links[10].inertia[1][2] + v12[2]*links[10].inertia[1][3]) + v12[2]*(-(links[10].mcm[1]*v12[5]) - v12[3]*links[10].inertia[2][2] + v12[2]*links[10].inertia[2][3]) + v12[3]*(-(links[10].mcm[1]*v12[6]) - v12[3]*links[10].inertia[2][3] + v12[2]*links[10].inertia[3][3]);
fnet12[5]=-(a12[6]*links[10].mcm[1]) + a12[4]*links[10].mcm[3] + (-(links[10].mcm[1]*v12[1]) - links[10].mcm[3]*v12[3])*v12[5] + (links[10].mcm[2]*v12[3] - links[10].m*v12[4])*v12[6] + v12[4]*(links[10].mcm[2]*v12[1] + links[10].m*v12[6]) + a12[1]*links[10].inertia[1][2] + v12[1]*(-(links[10].mcm[2]*v12[4]) + v12[3]*links[10].inertia[1][1] - v12[1]*links[10].inertia[1][3]) + a12[2]*links[10].inertia[2][2] + a12[3]*links[10].inertia[2][3] + v12[2]*(links[10].mcm[1]*v12[4] + links[10].mcm[3]*v12[6] + v12[3]*links[10].inertia[1][2] - v12[1]*links[10].inertia[2][3]) + v12[3]*(-(links[10].mcm[2]*v12[6]) + v12[3]*links[10].inertia[1][3] - v12[1]*links[10].inertia[3][3]);
fnet12[6]=a12[5]*links[10].mcm[1] - a12[4]*links[10].mcm[2] + (links[10].mcm[3]*v12[2] + links[10].m*v12[4])*v12[5] + v12[4]*(links[10].mcm[3]*v12[1] - links[10].m*v12[5]) + (-(links[10].mcm[1]*v12[1]) - links[10].mcm[2]*v12[2])*v12[6] + v12[1]*(-(links[10].mcm[3]*v12[4]) - v12[2]*links[10].inertia[1][1] + v12[1]*links[10].inertia[1][2]) + a12[1]*links[10].inertia[1][3] + v12[2]*(-(links[10].mcm[3]*v12[5]) - v12[2]*links[10].inertia[1][2] + v12[1]*links[10].inertia[2][2]) + a12[2]*links[10].inertia[2][3] + v12[3]*(links[10].mcm[1]*v12[4] + links[10].mcm[2]*v12[5] - v12[2]*links[10].inertia[1][3] + v12[1]*links[10].inertia[2][3]) + a12[3]*links[10].inertia[3][3];


fex1[1]=-(uex[1].f[1]*SG10[1][1]) - uex[1].f[2]*SG10[1][2] - uex[1].f[3]*SG10[1][3];
fex1[2]=-(uex[1].f[1]*SG10[2][1]) - uex[1].f[2]*SG10[2][2] - uex[1].f[3]*SG10[2][3];
fex1[3]=-(uex[1].f[1]*SG10[3][1]) - uex[1].f[2]*SG10[3][2] - uex[1].f[3]*SG10[3][3];
fex1[4]=-(uex[1].t[1]*SG10[1][1]) - uex[1].t[2]*SG10[1][2] - uex[1].t[3]*SG10[1][3];
fex1[5]=-(uex[1].t[1]*SG10[2][1]) - uex[1].t[2]*SG10[2][2] - uex[1].t[3]*SG10[2][3];
fex1[6]=-(uex[1].t[1]*SG10[3][1]) - uex[1].t[2]*SG10[3][2] - uex[1].t[3]*SG10[3][3];

fex2[1]=-(uex[2].f[1]*SG20[1][1]) - uex[2].f[2]*SG20[1][2] - uex[2].f[3]*SG20[1][3];
fex2[2]=-(uex[2].f[1]*SG20[2][1]) - uex[2].f[2]*SG20[2][2] - uex[2].f[3]*SG20[2][3];
fex2[3]=-(uex[2].f[1]*SG20[3][1]) - uex[2].f[2]*SG20[3][2] - uex[2].f[3]*SG20[3][3];
fex2[4]=-(uex[2].t[1]*SG20[1][1]) - uex[2].t[2]*SG20[1][2] - uex[2].t[3]*SG20[1][3];
fex2[5]=-(uex[2].t[1]*SG20[2][1]) - uex[2].t[2]*SG20[2][2] - uex[2].t[3]*SG20[2][3];
fex2[6]=-(uex[2].t[1]*SG20[3][1]) - uex[2].t[2]*SG20[3][2] - uex[2].t[3]*SG20[3][3];

fex3[1]=-(uex[3].f[1]*SG30[1][1]) - uex[3].f[2]*SG30[1][2] - uex[3].f[3]*SG30[1][3];
fex3[2]=-(uex[3].f[1]*SG30[2][1]) - uex[3].f[2]*SG30[2][2] - uex[3].f[3]*SG30[2][3];
fex3[3]=-(uex[3].f[1]*SG30[3][1]) - uex[3].f[2]*SG30[3][2] - uex[3].f[3]*SG30[3][3];
fex3[4]=-(uex[3].t[1]*SG30[1][1]) - uex[3].t[2]*SG30[1][2] - uex[3].t[3]*SG30[1][3];
fex3[5]=-(uex[3].t[1]*SG30[2][1]) - uex[3].t[2]*SG30[2][2] - uex[3].t[3]*SG30[2][3];
fex3[6]=-(uex[3].t[1]*SG30[3][1]) - uex[3].t[2]*SG30[3][2] - uex[3].t[3]*SG30[3][3];

fex4[1]=-(uex[4].f[1]*SG40[1][1]) - uex[4].f[2]*SG40[1][2] - uex[4].f[3]*SG40[1][3];
fex4[2]=-(uex[4].f[1]*SG40[2][1]) - uex[4].f[2]*SG40[2][2] - uex[4].f[3]*SG40[2][3];
fex4[3]=-(uex[4].f[1]*SG40[3][1]) - uex[4].f[2]*SG40[3][2] - uex[4].f[3]*SG40[3][3];
fex4[4]=-(uex[4].t[1]*SG40[1][1]) - uex[4].t[2]*SG40[1][2] - uex[4].t[3]*SG40[1][3];
fex4[5]=-(uex[4].t[1]*SG40[2][1]) - uex[4].t[2]*SG40[2][2] - uex[4].t[3]*SG40[2][3];
fex4[6]=-(uex[4].t[1]*SG40[3][1]) - uex[4].t[2]*SG40[3][2] - uex[4].t[3]*SG40[3][3];

fex5[1]=-(uex[5].f[1]*SG50[1][1]) - uex[5].f[2]*SG50[1][2] - uex[5].f[3]*SG50[1][3];
fex5[2]=-(uex[5].f[1]*SG50[2][1]) - uex[5].f[2]*SG50[2][2] - uex[5].f[3]*SG50[2][3];
fex5[3]=-(uex[5].f[1]*SG50[3][1]) - uex[5].f[2]*SG50[3][2] - uex[5].f[3]*SG50[3][3];
fex5[4]=-(uex[5].t[1]*SG50[1][1]) - uex[5].t[2]*SG50[1][2] - uex[5].t[3]*SG50[1][3];
fex5[5]=-(uex[5].t[1]*SG50[2][1]) - uex[5].t[2]*SG50[2][2] - uex[5].t[3]*SG50[2][3];
fex5[6]=-(uex[5].t[1]*SG50[3][1]) - uex[5].t[2]*SG50[3][2] - uex[5].t[3]*SG50[3][3];

fex6[1]=-(uex[6].f[1]*SG60[1][1]) - uex[6].f[2]*SG60[1][2] - uex[6].f[3]*SG60[1][3];
fex6[2]=-(uex[6].f[1]*SG60[2][1]) - uex[6].f[2]*SG60[2][2] - uex[6].f[3]*SG60[2][3];
fex6[3]=-(uex[6].f[1]*SG60[3][1]) - uex[6].f[2]*SG60[3][2] - uex[6].f[3]*SG60[3][3];
fex6[4]=-(uex[6].t[1]*SG60[1][1]) - uex[6].t[2]*SG60[1][2] - uex[6].t[3]*SG60[1][3];
fex6[5]=-(uex[6].t[1]*SG60[2][1]) - uex[6].t[2]*SG60[2][2] - uex[6].t[3]*SG60[2][3];
fex6[6]=-(uex[6].t[1]*SG60[3][1]) - uex[6].t[2]*SG60[3][2] - uex[6].t[3]*SG60[3][3];

fex7[1]=-(uex[7].f[1]*SG70[1][1]) - uex[7].f[2]*SG70[1][2] - uex[7].f[3]*SG70[1][3];
fex7[2]=-(uex[7].f[1]*SG70[2][1]) - uex[7].f[2]*SG70[2][2] - uex[7].f[3]*SG70[2][3];
fex7[3]=-(uex[7].f[1]*SG70[3][1]) - uex[7].f[2]*SG70[3][2] - uex[7].f[3]*SG70[3][3];
fex7[4]=-(uex[7].t[1]*SG70[1][1]) - uex[7].t[2]*SG70[1][2] - uex[7].t[3]*SG70[1][3];
fex7[5]=-(uex[7].t[1]*SG70[2][1]) - uex[7].t[2]*SG70[2][2] - uex[7].t[3]*SG70[2][3];
fex7[6]=-(uex[7].t[1]*SG70[3][1]) - uex[7].t[2]*SG70[3][2] - uex[7].t[3]*SG70[3][3];

fex9[1]=-(uex[8].f[1]*SG90[1][1]) - uex[8].f[2]*SG90[1][2] - uex[8].f[3]*SG90[1][3];
fex9[2]=-(uex[8].f[1]*SG90[2][1]) - uex[8].f[2]*SG90[2][2] - uex[8].f[3]*SG90[2][3];
fex9[3]=-(uex[8].f[1]*SG90[3][1]) - uex[8].f[2]*SG90[3][2] - uex[8].f[3]*SG90[3][3];
fex9[4]=-(uex[8].t[1]*SG90[1][1]) - uex[8].t[2]*SG90[1][2] - uex[8].t[3]*SG90[1][3];
fex9[5]=-(uex[8].t[1]*SG90[2][1]) - uex[8].t[2]*SG90[2][2] - uex[8].t[3]*SG90[2][3];
fex9[6]=-(uex[8].t[1]*SG90[3][1]) - uex[8].t[2]*SG90[3][2] - uex[8].t[3]*SG90[3][3];

fex10[1]=-(uex[9].f[1]*SG100[1][1]) - uex[9].f[2]*SG100[1][2] - uex[9].f[3]*SG100[1][3];
fex10[2]=-(uex[9].f[1]*SG100[2][1]) - uex[9].f[2]*SG100[2][2] - uex[9].f[3]*SG100[2][3];
fex10[3]=-(uex[9].f[1]*SG100[3][1]) - uex[9].f[2]*SG100[3][2] - uex[9].f[3]*SG100[3][3];
fex10[4]=-(uex[9].t[1]*SG100[1][1]) - uex[9].t[2]*SG100[1][2] - uex[9].t[3]*SG100[1][3];
fex10[5]=-(uex[9].t[1]*SG100[2][1]) - uex[9].t[2]*SG100[2][2] - uex[9].t[3]*SG100[2][3];
fex10[6]=-(uex[9].t[1]*SG100[3][1]) - uex[9].t[2]*SG100[3][2] - uex[9].t[3]*SG100[3][3];

fex12[1]=-(uex[10].f[1]*SG120[1][1]) - uex[10].f[2]*SG120[1][2] - uex[10].f[3]*SG120[1][3];
fex12[2]=-(uex[10].f[1]*SG120[2][1]) - uex[10].f[2]*SG120[2][2] - uex[10].f[3]*SG120[2][3];
fex12[3]=-(uex[10].f[1]*SG120[3][1]) - uex[10].f[2]*SG120[3][2] - uex[10].f[3]*SG120[3][3];
fex12[4]=-(uex[10].t[1]*SG120[1][1]) - uex[10].t[2]*SG120[1][2] - uex[10].t[3]*SG120[1][3];
fex12[5]=-(uex[10].t[1]*SG120[2][1]) - uex[10].t[2]*SG120[2][2] - uex[10].t[3]*SG120[2][3];
fex12[6]=-(uex[10].t[1]*SG120[3][1]) - uex[10].t[2]*SG120[3][2] - uex[10].t[3]*SG120[3][3];



}


void
master_ForDynCompfunc7(void)
     {
/* total forces and external forces for each joint */
f12[1]=fnet12[1];
f12[2]=fnet12[2];
f12[3]=fnet12[3];
f12[4]=fnet12[4];
f12[5]=fnet12[5];
f12[6]=fnet12[6];

f10[1]=fnet10[1];
f10[2]=fnet10[2];
f10[3]=fnet10[3];
f10[4]=fnet10[4];
f10[5]=fnet10[5];
f10[6]=fnet10[6];

f9[1]=f10[3] + fnet9[1];
f9[2]=fnet9[2] + f10[1]*Si910[2][1] + f10[2]*Si910[2][2];
f9[3]=fnet9[3] + f10[1]*Si910[3][1] + f10[2]*Si910[3][2];
f9[4]=f10[6] + fnet9[4];
f9[5]=fnet9[5] + f10[4]*Si910[2][1] + f10[5]*Si910[2][2];
f9[6]=fnet9[6] + f10[4]*Si910[3][1] + f10[5]*Si910[3][2];

f8[1]=fnet8[1];
f8[2]=fnet8[2];
f8[3]=fnet8[3];
f8[4]=fnet8[4];
f8[5]=fnet8[5];
f8[6]=fnet8[6];

f7[1]=-f9[3] + fnet7[1] + f12[1]*Si712[1][1] + f12[2]*Si712[1][2] + f8[1]*Si78[1][1] + f8[2]*Si78[1][2] + f8[3]*Si78[1][3];
f7[2]=fnet7[2] + f12[1]*Si712[2][1] + f12[2]*Si712[2][2] + f8[1]*Si78[2][1] + f8[2]*Si78[2][2] + f8[3]*Si78[2][3] + f9[1]*Si79[2][1] + f9[2]*Si79[2][2];
f7[3]=f12[3] + fnet7[3] + f8[1]*Si78[3][1] + f8[2]*Si78[3][2] + f8[3]*Si78[3][3] + f9[1]*Si79[3][1] + f9[2]*Si79[3][2];
f7[4]=l6y*f12[3] - f9[6] + fnet7[4] + f12[4]*Si712[1][1] + f12[5]*Si712[1][2] - l6z*f12[1]*Si712[2][1] - l6z*f12[2]*Si712[2][2] + f8[4]*Si78[1][1] + f8[5]*Si78[1][2] + f8[6]*Si78[1][3] + f8[1]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + f8[2]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + f8[3]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3]) - l7z*f9[1]*Si79[2][1] - l7z*f9[2]*Si79[2][2];
f7[5]=l6x*f12[3] - l7z*f9[3] + fnet7[5] + l6z*f12[1]*Si712[1][1] + l6z*f12[2]*Si712[1][2] + f12[4]*Si712[2][1] + f12[5]*Si712[2][2] + f8[4]*Si78[2][1] + f8[5]*Si78[2][2] + f8[6]*Si78[2][3] + f8[1]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + f8[2]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + f8[3]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3]) + f9[4]*Si79[2][1] + f9[5]*Si79[2][2] + l6x*f9[1]*Si79[3][1] + l6x*f9[2]*Si79[3][2];
f7[6]=f12[6] + fnet7[6] + f12[1]*(-(l6y*Si712[1][1]) - l6x*Si712[2][1]) + f12[2]*(-(l6y*Si712[1][2]) - l6x*Si712[2][2]) + f8[1]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + f8[2]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + f8[3]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + f8[4]*Si78[3][1] + f8[5]*Si78[3][2] + f8[6]*Si78[3][3] - l6x*f9[1]*Si79[2][1] - l6x*f9[2]*Si79[2][2] + f9[4]*Si79[3][1] + f9[5]*Si79[3][2];

f6[1]=f7[3] + fnet6[1];
f6[2]=fnet6[2] + f7[1]*Si67[2][1] + f7[2]*Si67[2][2];
f6[3]=fnet6[3] + f7[1]*Si67[3][1] + f7[2]*Si67[3][2];
f6[4]=f7[6] + fnet6[4] - l5*f7[1]*Si67[2][1] - l5*f7[2]*Si67[2][2];
f6[5]=l5*f7[3] + fnet6[5] + f7[4]*Si67[2][1] + f7[5]*Si67[2][2];
f6[6]=fnet6[6] + f7[4]*Si67[3][1] + f7[5]*Si67[3][2];

f5[1]=fnet5[1] + f6[1]*Si56[1][1] + f6[2]*Si56[1][2];
f5[2]=f6[3] + fnet5[2];
f5[3]=fnet5[3] + f6[1]*Si56[3][1] + f6[2]*Si56[3][2];
f5[4]=-(l4*f6[3]) + fnet5[4] + f6[4]*Si56[1][1] + f6[5]*Si56[1][2];
f5[5]=f6[6] + fnet5[5] + l4*f6[1]*Si56[1][1] + l4*f6[2]*Si56[1][2];
f5[6]=fnet5[6] + f6[4]*Si56[3][1] + f6[5]*Si56[3][2];

f4[1]=-f5[3] + fnet4[1];
f4[2]=fnet4[2] + f5[1]*Si45[2][1] + f5[2]*Si45[2][2];
f4[3]=fnet4[3] + f5[1]*Si45[3][1] + f5[2]*Si45[3][2];
f4[4]=-f5[6] + fnet4[4] + l3*f5[1]*Si45[2][1] + l3*f5[2]*Si45[2][2];
f4[5]=l3*f5[3] + fnet4[5] + f5[4]*Si45[2][1] + f5[5]*Si45[2][2];
f4[6]=fnet4[6] + f5[4]*Si45[3][1] + f5[5]*Si45[3][2];

f3[1]=fnet3[1] + f4[1]*Si34[1][1] + f4[2]*Si34[1][2];
f3[2]=-f4[3] + fnet3[2];
f3[3]=fnet3[3] + f4[1]*Si34[3][1] + f4[2]*Si34[3][2];
f3[4]=l2*f4[3] + fnet3[4] + f4[4]*Si34[1][1] + f4[5]*Si34[1][2];
f3[5]=-f4[6] + fnet3[5] + l2*f4[1]*Si34[1][1] + l2*f4[2]*Si34[1][2];
f3[6]=fnet3[6] + f4[4]*Si34[3][1] + f4[5]*Si34[3][2];

f2[1]=f3[3] + fnet2[1];
f2[2]=fnet2[2] + f3[1]*Si23[2][1] + f3[2]*Si23[2][2];
f2[3]=fnet2[3] + f3[1]*Si23[3][1] + f3[2]*Si23[3][2];
f2[4]=f3[6] + fnet2[4] - l1*f3[1]*Si23[3][1] - l1*f3[2]*Si23[3][2];
f2[5]=fnet2[5] + f3[4]*Si23[2][1] + f3[5]*Si23[2][2];
f2[6]=l1*f3[3] + fnet2[6] + f3[4]*Si23[3][1] + f3[5]*Si23[3][2];

f1[1]=fnet1[1] + f2[1]*Si12[1][1] + f2[2]*Si12[1][2];
f1[2]=f2[3] + fnet1[2];
f1[3]=fnet1[3] + f2[1]*Si12[3][1] + f2[2]*Si12[3][2];
f1[4]=fnet1[4] + f2[4]*Si12[1][1] + f2[5]*Si12[1][2];
f1[5]=f2[6] + fnet1[5];
f1[6]=fnet1[6] + f2[4]*Si12[3][1] + f2[5]*Si12[3][2];

f0[1]=0.7071067811865475*f1[3] + fnet0[1] + f1[1]*Si01[1][1] + f1[2]*Si01[1][2];
f0[2]=fnet0[2] + f1[1]*Si01[2][1] + f1[2]*Si01[2][2];
f0[3]=0.7071067811865475*f1[3] + fnet0[3] + f1[1]*Si01[3][1] + f1[2]*Si01[3][2];
f0[4]=0.7071067811865475*f1[6] + fnet0[4] + f1[4]*Si01[1][1] + f1[5]*Si01[1][2] - (l0*f1[1]*Si01[2][1])/Sqrt(2) - (l0*f1[2]*Si01[2][2])/Sqrt(2);
f0[5]=fnet0[5] + f1[4]*Si01[2][1] + f1[5]*Si01[2][2] + f1[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + f1[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2));
f0[6]=0.7071067811865475*f1[6] + fnet0[6] + (l0*f1[1]*Si01[2][1])/Sqrt(2) + (l0*f1[2]*Si01[2][2])/Sqrt(2) + f1[4]*Si01[3][1] + f1[5]*Si01[3][2];


fext12[1]=fex12[1];
fext12[2]=fex12[2];
fext12[3]=fex12[3];
fext12[4]=fex12[4];
fext12[5]=fex12[5];
fext12[6]=fex12[6];

fext10[1]=fex10[1];
fext10[2]=fex10[2];
fext10[3]=fex10[3];
fext10[4]=fex10[4];
fext10[5]=fex10[5];
fext10[6]=fex10[6];

fext9[1]=fex9[1] + fext10[3];
fext9[2]=fex9[2] + fext10[1]*Si910[2][1] + fext10[2]*Si910[2][2];
fext9[3]=fex9[3] + fext10[1]*Si910[3][1] + fext10[2]*Si910[3][2];
fext9[4]=fex9[4] + fext10[6];
fext9[5]=fex9[5] + fext10[4]*Si910[2][1] + fext10[5]*Si910[2][2];
fext9[6]=fex9[6] + fext10[4]*Si910[3][1] + fext10[5]*Si910[3][2];

fext7[1]=fex7[1] - fext9[3] + fext12[1]*Si712[1][1] + fext12[2]*Si712[1][2];
fext7[2]=fex7[2] + fext12[1]*Si712[2][1] + fext12[2]*Si712[2][2] + fext9[1]*Si79[2][1] + fext9[2]*Si79[2][2];
fext7[3]=fex7[3] + fext12[3] + fext9[1]*Si79[3][1] + fext9[2]*Si79[3][2];
fext7[4]=fex7[4] + l6y*fext12[3] - fext9[6] + fext12[4]*Si712[1][1] + fext12[5]*Si712[1][2] - l6z*fext12[1]*Si712[2][1] - l6z*fext12[2]*Si712[2][2] - l7z*fext9[1]*Si79[2][1] - l7z*fext9[2]*Si79[2][2];
fext7[5]=fex7[5] + l6x*fext12[3] - l7z*fext9[3] + l6z*fext12[1]*Si712[1][1] + l6z*fext12[2]*Si712[1][2] + fext12[4]*Si712[2][1] + fext12[5]*Si712[2][2] + fext9[4]*Si79[2][1] + fext9[5]*Si79[2][2] + l6x*fext9[1]*Si79[3][1] + l6x*fext9[2]*Si79[3][2];
fext7[6]=fex7[6] + fext12[6] + fext12[1]*(-(l6y*Si712[1][1]) - l6x*Si712[2][1]) + fext12[2]*(-(l6y*Si712[1][2]) - l6x*Si712[2][2]) - l6x*fext9[1]*Si79[2][1] - l6x*fext9[2]*Si79[2][2] + fext9[4]*Si79[3][1] + fext9[5]*Si79[3][2];

fext6[1]=fex6[1] + fext7[3];
fext6[2]=fex6[2] + fext7[1]*Si67[2][1] + fext7[2]*Si67[2][2];
fext6[3]=fex6[3] + fext7[1]*Si67[3][1] + fext7[2]*Si67[3][2];
fext6[4]=fex6[4] + fext7[6] - l5*fext7[1]*Si67[2][1] - l5*fext7[2]*Si67[2][2];
fext6[5]=fex6[5] + l5*fext7[3] + fext7[4]*Si67[2][1] + fext7[5]*Si67[2][2];
fext6[6]=fex6[6] + fext7[4]*Si67[3][1] + fext7[5]*Si67[3][2];

fext5[1]=fex5[1] + fext6[1]*Si56[1][1] + fext6[2]*Si56[1][2];
fext5[2]=fex5[2] + fext6[3];
fext5[3]=fex5[3] + fext6[1]*Si56[3][1] + fext6[2]*Si56[3][2];
fext5[4]=fex5[4] - l4*fext6[3] + fext6[4]*Si56[1][1] + fext6[5]*Si56[1][2];
fext5[5]=fex5[5] + fext6[6] + l4*fext6[1]*Si56[1][1] + l4*fext6[2]*Si56[1][2];
fext5[6]=fex5[6] + fext6[4]*Si56[3][1] + fext6[5]*Si56[3][2];

fext4[1]=fex4[1] - fext5[3];
fext4[2]=fex4[2] + fext5[1]*Si45[2][1] + fext5[2]*Si45[2][2];
fext4[3]=fex4[3] + fext5[1]*Si45[3][1] + fext5[2]*Si45[3][2];
fext4[4]=fex4[4] - fext5[6] + l3*fext5[1]*Si45[2][1] + l3*fext5[2]*Si45[2][2];
fext4[5]=fex4[5] + l3*fext5[3] + fext5[4]*Si45[2][1] + fext5[5]*Si45[2][2];
fext4[6]=fex4[6] + fext5[4]*Si45[3][1] + fext5[5]*Si45[3][2];

fext3[1]=fex3[1] + fext4[1]*Si34[1][1] + fext4[2]*Si34[1][2];
fext3[2]=fex3[2] - fext4[3];
fext3[3]=fex3[3] + fext4[1]*Si34[3][1] + fext4[2]*Si34[3][2];
fext3[4]=fex3[4] + l2*fext4[3] + fext4[4]*Si34[1][1] + fext4[5]*Si34[1][2];
fext3[5]=fex3[5] - fext4[6] + l2*fext4[1]*Si34[1][1] + l2*fext4[2]*Si34[1][2];
fext3[6]=fex3[6] + fext4[4]*Si34[3][1] + fext4[5]*Si34[3][2];

fext2[1]=fex2[1] + fext3[3];
fext2[2]=fex2[2] + fext3[1]*Si23[2][1] + fext3[2]*Si23[2][2];
fext2[3]=fex2[3] + fext3[1]*Si23[3][1] + fext3[2]*Si23[3][2];
fext2[4]=fex2[4] + fext3[6] - l1*fext3[1]*Si23[3][1] - l1*fext3[2]*Si23[3][2];
fext2[5]=fex2[5] + fext3[4]*Si23[2][1] + fext3[5]*Si23[2][2];
fext2[6]=fex2[6] + l1*fext3[3] + fext3[4]*Si23[3][1] + fext3[5]*Si23[3][2];

fext1[1]=fex1[1] + fext2[1]*Si12[1][1] + fext2[2]*Si12[1][2];
fext1[2]=fex1[2] + fext2[3];
fext1[3]=fex1[3] + fext2[1]*Si12[3][1] + fext2[2]*Si12[3][2];
fext1[4]=fex1[4] + fext2[4]*Si12[1][1] + fext2[5]*Si12[1][2];
fext1[5]=fex1[5] + fext2[6];
fext1[6]=fex1[6] + fext2[4]*Si12[3][1] + fext2[5]*Si12[3][2];

fext0[1]=0.7071067811865475*fext1[3] + fext1[1]*Si01[1][1] + fext1[2]*Si01[1][2];
fext0[2]=fext1[1]*Si01[2][1] + fext1[2]*Si01[2][2];
fext0[3]=0.7071067811865475*fext1[3] + fext1[1]*Si01[3][1] + fext1[2]*Si01[3][2];
fext0[4]=0.7071067811865475*fext1[6] + fext1[4]*Si01[1][1] + fext1[5]*Si01[1][2] - (l0*fext1[1]*Si01[2][1])/Sqrt(2) - (l0*fext1[2]*Si01[2][2])/Sqrt(2);
fext0[5]=fext1[4]*Si01[2][1] + fext1[5]*Si01[2][2] + fext1[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + fext1[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2));
fext0[6]=0.7071067811865475*fext1[6] + (l0*fext1[1]*Si01[2][1])/Sqrt(2) + (l0*fext1[2]*Si01[2][2])/Sqrt(2) + fext1[4]*Si01[3][1] + fext1[5]*Si01[3][2];



}


void
masterfunc11(void)
      {
/* composite inertia matrices */
Jc13[1][1]=0;
Jc13[1][2]=0;
Jc13[1][3]=0;
Jc13[1][4]=0;
Jc13[1][5]=0;
Jc13[1][6]=0;

Jc13[2][1]=0;
Jc13[2][2]=0;
Jc13[2][3]=0;
Jc13[2][4]=0;
Jc13[2][5]=0;
Jc13[2][6]=0;

Jc13[3][1]=0;
Jc13[3][2]=0;
Jc13[3][3]=0;
Jc13[3][4]=0;
Jc13[3][5]=0;
Jc13[3][6]=0;

Jc13[4][1]=0;
Jc13[4][2]=0;
Jc13[4][3]=0;
Jc13[4][4]=0;
Jc13[4][5]=0;
Jc13[4][6]=0;

Jc13[5][1]=0;
Jc13[5][2]=0;
Jc13[5][3]=0;
Jc13[5][4]=0;
Jc13[5][5]=0;
Jc13[5][6]=0;

Jc13[6][1]=0;
Jc13[6][2]=0;
Jc13[6][3]=0;
Jc13[6][4]=0;
Jc13[6][5]=0;
Jc13[6][6]=0;



}


void
masterfunc12(void)
      {
/* composite inertia matrices */
Jc12[1][1]=Jc13[1][1] + l9*Jc13[1][6];
Jc12[1][2]=links[10].mcm[3] + Jc13[1][2];
Jc12[1][3]=-links[10].mcm[2] + Jc13[1][3] - l9*Jc13[1][4];
Jc12[1][4]=links[10].m + Jc13[1][4];
Jc12[1][5]=Jc13[1][5];
Jc12[1][6]=Jc13[1][6];

Jc12[2][1]=-links[10].mcm[3] + Jc13[2][1] + l9*Jc13[2][6];
Jc12[2][2]=Jc13[2][2];
Jc12[2][3]=links[10].mcm[1] + Jc13[2][3] - l9*Jc13[2][4];
Jc12[2][4]=Jc13[2][4];
Jc12[2][5]=links[10].m + Jc13[2][5];
Jc12[2][6]=Jc13[2][6];

Jc12[3][1]=links[10].mcm[2] + Jc13[3][1] + l9*Jc13[3][6];
Jc12[3][2]=-links[10].mcm[1] + Jc13[3][2];
Jc12[3][3]=Jc13[3][3] - l9*Jc13[3][4];
Jc12[3][4]=Jc13[3][4];
Jc12[3][5]=Jc13[3][5];
Jc12[3][6]=links[10].m + Jc13[3][6];

Jc12[4][1]=l9*Jc13[3][1] + Jc13[4][1] + l9*(l9*Jc13[3][6] + Jc13[4][6]) + links[10].inertia[1][1];
Jc12[4][2]=l9*Jc13[3][2] + Jc13[4][2] + links[10].inertia[1][2];
Jc12[4][3]=l9*Jc13[3][3] + Jc13[4][3] - l9*(l9*Jc13[3][4] + Jc13[4][4]) + links[10].inertia[1][3];
Jc12[4][4]=l9*Jc13[3][4] + Jc13[4][4];
Jc12[4][5]=-links[10].mcm[3] + l9*Jc13[3][5] + Jc13[4][5];
Jc12[4][6]=links[10].mcm[2] + l9*Jc13[3][6] + Jc13[4][6];

Jc12[5][1]=Jc13[5][1] + l9*Jc13[5][6] + links[10].inertia[1][2];
Jc12[5][2]=Jc13[5][2] + links[10].inertia[2][2];
Jc12[5][3]=Jc13[5][3] - l9*Jc13[5][4] + links[10].inertia[2][3];
Jc12[5][4]=links[10].mcm[3] + Jc13[5][4];
Jc12[5][5]=Jc13[5][5];
Jc12[5][6]=-links[10].mcm[1] + Jc13[5][6];

Jc12[6][1]=-(l9*Jc13[1][1]) + Jc13[6][1] + l9*(-(l9*Jc13[1][6]) + Jc13[6][6]) + links[10].inertia[1][3];
Jc12[6][2]=-(l9*Jc13[1][2]) + Jc13[6][2] + links[10].inertia[2][3];
Jc12[6][3]=-(l9*Jc13[1][3]) + Jc13[6][3] - l9*(-(l9*Jc13[1][4]) + Jc13[6][4]) + links[10].inertia[3][3];
Jc12[6][4]=-links[10].mcm[2] - l9*Jc13[1][4] + Jc13[6][4];
Jc12[6][5]=links[10].mcm[1] - l9*Jc13[1][5] + Jc13[6][5];
Jc12[6][6]=-(l9*Jc13[1][6]) + Jc13[6][6];



}


void
masterfunc13(void)
      {
/* composite inertia matrices */
Jc11[1][1]=0;
Jc11[1][2]=0;
Jc11[1][3]=0;
Jc11[1][4]=0;
Jc11[1][5]=0;
Jc11[1][6]=0;

Jc11[2][1]=0;
Jc11[2][2]=0;
Jc11[2][3]=0;
Jc11[2][4]=0;
Jc11[2][5]=0;
Jc11[2][6]=0;

Jc11[3][1]=0;
Jc11[3][2]=0;
Jc11[3][3]=0;
Jc11[3][4]=0;
Jc11[3][5]=0;
Jc11[3][6]=0;

Jc11[4][1]=0;
Jc11[4][2]=0;
Jc11[4][3]=0;
Jc11[4][4]=0;
Jc11[4][5]=0;
Jc11[4][6]=0;

Jc11[5][1]=0;
Jc11[5][2]=0;
Jc11[5][3]=0;
Jc11[5][4]=0;
Jc11[5][5]=0;
Jc11[5][6]=0;

Jc11[6][1]=0;
Jc11[6][2]=0;
Jc11[6][3]=0;
Jc11[6][4]=0;
Jc11[6][5]=0;
Jc11[6][6]=0;



}


void
masterfunc14(void)
      {
/* composite inertia matrices */
Jc10[1][1]=Jc11[1][1] + l8*Jc11[1][6];
Jc10[1][2]=links[9].mcm[3] + Jc11[1][2];
Jc10[1][3]=-links[9].mcm[2] + Jc11[1][3] - l8*Jc11[1][4];
Jc10[1][4]=links[9].m + Jc11[1][4];
Jc10[1][5]=Jc11[1][5];
Jc10[1][6]=Jc11[1][6];

Jc10[2][1]=-links[9].mcm[3] + Jc11[2][1] + l8*Jc11[2][6];
Jc10[2][2]=Jc11[2][2];
Jc10[2][3]=links[9].mcm[1] + Jc11[2][3] - l8*Jc11[2][4];
Jc10[2][4]=Jc11[2][4];
Jc10[2][5]=links[9].m + Jc11[2][5];
Jc10[2][6]=Jc11[2][6];

Jc10[3][1]=links[9].mcm[2] + Jc11[3][1] + l8*Jc11[3][6];
Jc10[3][2]=-links[9].mcm[1] + Jc11[3][2];
Jc10[3][3]=Jc11[3][3] - l8*Jc11[3][4];
Jc10[3][4]=Jc11[3][4];
Jc10[3][5]=Jc11[3][5];
Jc10[3][6]=links[9].m + Jc11[3][6];

Jc10[4][1]=l8*Jc11[3][1] + Jc11[4][1] + l8*(l8*Jc11[3][6] + Jc11[4][6]) + links[9].inertia[1][1];
Jc10[4][2]=l8*Jc11[3][2] + Jc11[4][2] + links[9].inertia[1][2];
Jc10[4][3]=l8*Jc11[3][3] + Jc11[4][3] - l8*(l8*Jc11[3][4] + Jc11[4][4]) + links[9].inertia[1][3];
Jc10[4][4]=l8*Jc11[3][4] + Jc11[4][4];
Jc10[4][5]=-links[9].mcm[3] + l8*Jc11[3][5] + Jc11[4][5];
Jc10[4][6]=links[9].mcm[2] + l8*Jc11[3][6] + Jc11[4][6];

Jc10[5][1]=Jc11[5][1] + l8*Jc11[5][6] + links[9].inertia[1][2];
Jc10[5][2]=Jc11[5][2] + links[9].inertia[2][2];
Jc10[5][3]=Jc11[5][3] - l8*Jc11[5][4] + links[9].inertia[2][3];
Jc10[5][4]=links[9].mcm[3] + Jc11[5][4];
Jc10[5][5]=Jc11[5][5];
Jc10[5][6]=-links[9].mcm[1] + Jc11[5][6];

Jc10[6][1]=-(l8*Jc11[1][1]) + Jc11[6][1] + l8*(-(l8*Jc11[1][6]) + Jc11[6][6]) + links[9].inertia[1][3];
Jc10[6][2]=-(l8*Jc11[1][2]) + Jc11[6][2] + links[9].inertia[2][3];
Jc10[6][3]=-(l8*Jc11[1][3]) + Jc11[6][3] - l8*(-(l8*Jc11[1][4]) + Jc11[6][4]) + links[9].inertia[3][3];
Jc10[6][4]=-links[9].mcm[2] - l8*Jc11[1][4] + Jc11[6][4];
Jc10[6][5]=links[9].mcm[1] - l8*Jc11[1][5] + Jc11[6][5];
Jc10[6][6]=-(l8*Jc11[1][6]) + Jc11[6][6];



}


void
masterfunc15(void)
      {
/* composite inertia matrices */
Jc9[1][1]=Jc10[3][3];
Jc9[1][2]=links[8].mcm[3] + Jc10[3][1]*S109[1][2] + Jc10[3][2]*S109[2][2];
Jc9[1][3]=-links[8].mcm[2] + Jc10[3][1]*S109[1][3] + Jc10[3][2]*S109[2][3];
Jc9[1][4]=links[8].m + Jc10[3][6];
Jc9[1][5]=Jc10[3][4]*S109[1][2] + Jc10[3][5]*S109[2][2];
Jc9[1][6]=Jc10[3][4]*S109[1][3] + Jc10[3][5]*S109[2][3];

Jc9[2][1]=-links[8].mcm[3] + Jc10[1][3]*Si910[2][1] + Jc10[2][3]*Si910[2][2];
Jc9[2][2]=S109[1][2]*(Jc10[1][1]*Si910[2][1] + Jc10[2][1]*Si910[2][2]) + S109[2][2]*(Jc10[1][2]*Si910[2][1] + Jc10[2][2]*Si910[2][2]);
Jc9[2][3]=links[8].mcm[1] + S109[1][3]*(Jc10[1][1]*Si910[2][1] + Jc10[2][1]*Si910[2][2]) + S109[2][3]*(Jc10[1][2]*Si910[2][1] + Jc10[2][2]*Si910[2][2]);
Jc9[2][4]=Jc10[1][6]*Si910[2][1] + Jc10[2][6]*Si910[2][2];
Jc9[2][5]=links[8].m + S109[1][2]*(Jc10[1][4]*Si910[2][1] + Jc10[2][4]*Si910[2][2]) + S109[2][2]*(Jc10[1][5]*Si910[2][1] + Jc10[2][5]*Si910[2][2]);
Jc9[2][6]=S109[1][3]*(Jc10[1][4]*Si910[2][1] + Jc10[2][4]*Si910[2][2]) + S109[2][3]*(Jc10[1][5]*Si910[2][1] + Jc10[2][5]*Si910[2][2]);

Jc9[3][1]=links[8].mcm[2] + Jc10[1][3]*Si910[3][1] + Jc10[2][3]*Si910[3][2];
Jc9[3][2]=-links[8].mcm[1] + S109[1][2]*(Jc10[1][1]*Si910[3][1] + Jc10[2][1]*Si910[3][2]) + S109[2][2]*(Jc10[1][2]*Si910[3][1] + Jc10[2][2]*Si910[3][2]);
Jc9[3][3]=S109[1][3]*(Jc10[1][1]*Si910[3][1] + Jc10[2][1]*Si910[3][2]) + S109[2][3]*(Jc10[1][2]*Si910[3][1] + Jc10[2][2]*Si910[3][2]);
Jc9[3][4]=Jc10[1][6]*Si910[3][1] + Jc10[2][6]*Si910[3][2];
Jc9[3][5]=S109[1][2]*(Jc10[1][4]*Si910[3][1] + Jc10[2][4]*Si910[3][2]) + S109[2][2]*(Jc10[1][5]*Si910[3][1] + Jc10[2][5]*Si910[3][2]);
Jc9[3][6]=links[8].m + S109[1][3]*(Jc10[1][4]*Si910[3][1] + Jc10[2][4]*Si910[3][2]) + S109[2][3]*(Jc10[1][5]*Si910[3][1] + Jc10[2][5]*Si910[3][2]);

Jc9[4][1]=Jc10[6][3] + links[8].inertia[1][1];
Jc9[4][2]=links[8].inertia[1][2] + Jc10[6][1]*S109[1][2] + Jc10[6][2]*S109[2][2];
Jc9[4][3]=links[8].inertia[1][3] + Jc10[6][1]*S109[1][3] + Jc10[6][2]*S109[2][3];
Jc9[4][4]=Jc10[6][6];
Jc9[4][5]=-links[8].mcm[3] + Jc10[6][4]*S109[1][2] + Jc10[6][5]*S109[2][2];
Jc9[4][6]=links[8].mcm[2] + Jc10[6][4]*S109[1][3] + Jc10[6][5]*S109[2][3];

Jc9[5][1]=links[8].inertia[1][2] + Jc10[4][3]*Si910[2][1] + Jc10[5][3]*Si910[2][2];
Jc9[5][2]=links[8].inertia[2][2] + S109[1][2]*(Jc10[4][1]*Si910[2][1] + Jc10[5][1]*Si910[2][2]) + S109[2][2]*(Jc10[4][2]*Si910[2][1] + Jc10[5][2]*Si910[2][2]);
Jc9[5][3]=links[8].inertia[2][3] + S109[1][3]*(Jc10[4][1]*Si910[2][1] + Jc10[5][1]*Si910[2][2]) + S109[2][3]*(Jc10[4][2]*Si910[2][1] + Jc10[5][2]*Si910[2][2]);
Jc9[5][4]=links[8].mcm[3] + Jc10[4][6]*Si910[2][1] + Jc10[5][6]*Si910[2][2];
Jc9[5][5]=S109[1][2]*(Jc10[4][4]*Si910[2][1] + Jc10[5][4]*Si910[2][2]) + S109[2][2]*(Jc10[4][5]*Si910[2][1] + Jc10[5][5]*Si910[2][2]);
Jc9[5][6]=-links[8].mcm[1] + S109[1][3]*(Jc10[4][4]*Si910[2][1] + Jc10[5][4]*Si910[2][2]) + S109[2][3]*(Jc10[4][5]*Si910[2][1] + Jc10[5][5]*Si910[2][2]);

Jc9[6][1]=links[8].inertia[1][3] + Jc10[4][3]*Si910[3][1] + Jc10[5][3]*Si910[3][2];
Jc9[6][2]=links[8].inertia[2][3] + S109[1][2]*(Jc10[4][1]*Si910[3][1] + Jc10[5][1]*Si910[3][2]) + S109[2][2]*(Jc10[4][2]*Si910[3][1] + Jc10[5][2]*Si910[3][2]);
Jc9[6][3]=links[8].inertia[3][3] + S109[1][3]*(Jc10[4][1]*Si910[3][1] + Jc10[5][1]*Si910[3][2]) + S109[2][3]*(Jc10[4][2]*Si910[3][1] + Jc10[5][2]*Si910[3][2]);
Jc9[6][4]=-links[8].mcm[2] + Jc10[4][6]*Si910[3][1] + Jc10[5][6]*Si910[3][2];
Jc9[6][5]=links[8].mcm[1] + S109[1][2]*(Jc10[4][4]*Si910[3][1] + Jc10[5][4]*Si910[3][2]) + S109[2][2]*(Jc10[4][5]*Si910[3][1] + Jc10[5][5]*Si910[3][2]);
Jc9[6][6]=S109[1][3]*(Jc10[4][4]*Si910[3][1] + Jc10[5][4]*Si910[3][2]) + S109[2][3]*(Jc10[4][5]*Si910[3][1] + Jc10[5][5]*Si910[3][2]);



}


void
masterfunc16(void)
      {
/* composite inertia matrices */
Jc8[1][1]=0;
Jc8[1][2]=eff[1].mcm[3];
Jc8[1][3]=-eff[1].mcm[2];
Jc8[1][4]=eff[1].m;
Jc8[1][5]=0;
Jc8[1][6]=0;

Jc8[2][1]=-eff[1].mcm[3];
Jc8[2][2]=0;
Jc8[2][3]=eff[1].mcm[1];
Jc8[2][4]=0;
Jc8[2][5]=eff[1].m;
Jc8[2][6]=0;

Jc8[3][1]=eff[1].mcm[2];
Jc8[3][2]=-eff[1].mcm[1];
Jc8[3][3]=0;
Jc8[3][4]=0;
Jc8[3][5]=0;
Jc8[3][6]=eff[1].m;

Jc8[4][1]=0;
Jc8[4][2]=0;
Jc8[4][3]=0;
Jc8[4][4]=0;
Jc8[4][5]=-eff[1].mcm[3];
Jc8[4][6]=eff[1].mcm[2];

Jc8[5][1]=0;
Jc8[5][2]=0;
Jc8[5][3]=0;
Jc8[5][4]=eff[1].mcm[3];
Jc8[5][5]=0;
Jc8[5][6]=-eff[1].mcm[1];

Jc8[6][1]=0;
Jc8[6][2]=0;
Jc8[6][3]=0;
Jc8[6][4]=-eff[1].mcm[2];
Jc8[6][5]=eff[1].mcm[1];
Jc8[6][6]=0;



}


void
masterfunc17(void)
      {
/* composite inertia matrices */
Jc7[1][1]=Jc9[3][3] + l7z*Jc9[3][4]*S97[1][2] + l7z*Jc9[3][5]*S97[2][2] + S127[1][1]*(Jc12[1][1]*Si712[1][1] + Jc12[2][1]*Si712[1][2]) + S127[2][1]*(Jc12[1][2]*Si712[1][1] + Jc12[2][2]*Si712[1][2]) - l6z*S127[1][2]*(Jc12[1][4]*Si712[1][1] + Jc12[2][4]*Si712[1][2]) - l6z*S127[2][2]*(Jc12[1][5]*Si712[1][1] + Jc12[2][5]*Si712[1][2]) + l6y*(Jc12[1][6]*Si712[1][1] + Jc12[2][6]*Si712[1][2]) + S87[1][1]*(Jc8[1][1]*Si78[1][1] + Jc8[2][1]*Si78[1][2] + Jc8[3][1]*Si78[1][3]) + S87[2][1]*(Jc8[1][2]*Si78[1][1] + Jc8[2][2]*Si78[1][2] + Jc8[3][2]*Si78[1][3]) + S87[3][1]*(Jc8[1][3]*Si78[1][1] + Jc8[2][3]*Si78[1][2] + Jc8[3][3]*Si78[1][3]) + (-(eff[1].x[3]*S87[1][2]) + eff[1].x[2]*S87[1][3])*(Jc8[1][4]*Si78[1][1] + Jc8[2][4]*Si78[1][2] + Jc8[3][4]*Si78[1][3]) + (-(eff[1].x[3]*S87[2][2]) + eff[1].x[2]*S87[2][3])*(Jc8[1][5]*Si78[1][1] + Jc8[2][5]*Si78[1][2] + Jc8[3][5]*Si78[1][3]) + (-(eff[1].x[3]*S87[3][2]) + eff[1].x[2]*S87[3][3])*(Jc8[1][6]*Si78[1][1] + Jc8[2][6]*Si78[1][2] + Jc8[3][6]*Si78[1][3]);
Jc7[1][2]=links[7].mcm[3] + l7z*Jc9[3][6] - Jc9[3][1]*S97[1][2] - l6x*Jc9[3][4]*S97[1][3] - Jc9[3][2]*S97[2][2] - l6x*Jc9[3][5]*S97[2][3] + S127[1][2]*(Jc12[1][1]*Si712[1][1] + Jc12[2][1]*Si712[1][2]) + S127[2][2]*(Jc12[1][2]*Si712[1][1] + Jc12[2][2]*Si712[1][2]) + l6z*S127[1][1]*(Jc12[1][4]*Si712[1][1] + Jc12[2][4]*Si712[1][2]) + l6z*S127[2][1]*(Jc12[1][5]*Si712[1][1] + Jc12[2][5]*Si712[1][2]) + l6x*(Jc12[1][6]*Si712[1][1] + Jc12[2][6]*Si712[1][2]) + S87[1][2]*(Jc8[1][1]*Si78[1][1] + Jc8[2][1]*Si78[1][2] + Jc8[3][1]*Si78[1][3]) + S87[2][2]*(Jc8[1][2]*Si78[1][1] + Jc8[2][2]*Si78[1][2] + Jc8[3][2]*Si78[1][3]) + S87[3][2]*(Jc8[1][3]*Si78[1][1] + Jc8[2][3]*Si78[1][2] + Jc8[3][3]*Si78[1][3]) + (eff[1].x[3]*S87[1][1] - eff[1].x[1]*S87[1][3])*(Jc8[1][4]*Si78[1][1] + Jc8[2][4]*Si78[1][2] + Jc8[3][4]*Si78[1][3]) + (eff[1].x[3]*S87[2][1] - eff[1].x[1]*S87[2][3])*(Jc8[1][5]*Si78[1][1] + Jc8[2][5]*Si78[1][2] + Jc8[3][5]*Si78[1][3]) + (eff[1].x[3]*S87[3][1] - eff[1].x[1]*S87[3][3])*(Jc8[1][6]*Si78[1][1] + Jc8[2][6]*Si78[1][2] + Jc8[3][6]*Si78[1][3]);
Jc7[1][3]=-links[7].mcm[2] + l6x*Jc9[3][4]*S97[1][2] - Jc9[3][1]*S97[1][3] + l6x*Jc9[3][5]*S97[2][2] - Jc9[3][2]*S97[2][3] + Jc12[1][3]*Si712[1][1] + Jc12[2][3]*Si712[1][2] + (-(l6y*S127[1][1]) - l6x*S127[1][2])*(Jc12[1][4]*Si712[1][1] + Jc12[2][4]*Si712[1][2]) + (-(l6y*S127[2][1]) - l6x*S127[2][2])*(Jc12[1][5]*Si712[1][1] + Jc12[2][5]*Si712[1][2]) + S87[1][3]*(Jc8[1][1]*Si78[1][1] + Jc8[2][1]*Si78[1][2] + Jc8[3][1]*Si78[1][3]) + S87[2][3]*(Jc8[1][2]*Si78[1][1] + Jc8[2][2]*Si78[1][2] + Jc8[3][2]*Si78[1][3]) + S87[3][3]*(Jc8[1][3]*Si78[1][1] + Jc8[2][3]*Si78[1][2] + Jc8[3][3]*Si78[1][3]) + (-(eff[1].x[2]*S87[1][1]) + eff[1].x[1]*S87[1][2])*(Jc8[1][4]*Si78[1][1] + Jc8[2][4]*Si78[1][2] + Jc8[3][4]*Si78[1][3]) + (-(eff[1].x[2]*S87[2][1]) + eff[1].x[1]*S87[2][2])*(Jc8[1][5]*Si78[1][1] + Jc8[2][5]*Si78[1][2] + Jc8[3][5]*Si78[1][3]) + (-(eff[1].x[2]*S87[3][1]) + eff[1].x[1]*S87[3][2])*(Jc8[1][6]*Si78[1][1] + Jc8[2][6]*Si78[1][2] + Jc8[3][6]*Si78[1][3]);
Jc7[1][4]=links[7].m + Jc9[3][6] + S127[1][1]*(Jc12[1][4]*Si712[1][1] + Jc12[2][4]*Si712[1][2]) + S127[2][1]*(Jc12[1][5]*Si712[1][1] + Jc12[2][5]*Si712[1][2]) + S87[1][1]*(Jc8[1][4]*Si78[1][1] + Jc8[2][4]*Si78[1][2] + Jc8[3][4]*Si78[1][3]) + S87[2][1]*(Jc8[1][5]*Si78[1][1] + Jc8[2][5]*Si78[1][2] + Jc8[3][5]*Si78[1][3]) + S87[3][1]*(Jc8[1][6]*Si78[1][1] + Jc8[2][6]*Si78[1][2] + Jc8[3][6]*Si78[1][3]);
Jc7[1][5]=-(Jc9[3][4]*S97[1][2]) - Jc9[3][5]*S97[2][2] + S127[1][2]*(Jc12[1][4]*Si712[1][1] + Jc12[2][4]*Si712[1][2]) + S127[2][2]*(Jc12[1][5]*Si712[1][1] + Jc12[2][5]*Si712[1][2]) + S87[1][2]*(Jc8[1][4]*Si78[1][1] + Jc8[2][4]*Si78[1][2] + Jc8[3][4]*Si78[1][3]) + S87[2][2]*(Jc8[1][5]*Si78[1][1] + Jc8[2][5]*Si78[1][2] + Jc8[3][5]*Si78[1][3]) + S87[3][2]*(Jc8[1][6]*Si78[1][1] + Jc8[2][6]*Si78[1][2] + Jc8[3][6]*Si78[1][3]);
Jc7[1][6]=-(Jc9[3][4]*S97[1][3]) - Jc9[3][5]*S97[2][3] + Jc12[1][6]*Si712[1][1] + Jc12[2][6]*Si712[1][2] + S87[1][3]*(Jc8[1][4]*Si78[1][1] + Jc8[2][4]*Si78[1][2] + Jc8[3][4]*Si78[1][3]) + S87[2][3]*(Jc8[1][5]*Si78[1][1] + Jc8[2][5]*Si78[1][2] + Jc8[3][5]*Si78[1][3]) + S87[3][3]*(Jc8[1][6]*Si78[1][1] + Jc8[2][6]*Si78[1][2] + Jc8[3][6]*Si78[1][3]);

Jc7[2][1]=-links[7].mcm[3] + S127[1][1]*(Jc12[1][1]*Si712[2][1] + Jc12[2][1]*Si712[2][2]) + S127[2][1]*(Jc12[1][2]*Si712[2][1] + Jc12[2][2]*Si712[2][2]) - l6z*S127[1][2]*(Jc12[1][4]*Si712[2][1] + Jc12[2][4]*Si712[2][2]) - l6z*S127[2][2]*(Jc12[1][5]*Si712[2][1] + Jc12[2][5]*Si712[2][2]) + l6y*(Jc12[1][6]*Si712[2][1] + Jc12[2][6]*Si712[2][2]) + S87[1][1]*(Jc8[1][1]*Si78[2][1] + Jc8[2][1]*Si78[2][2] + Jc8[3][1]*Si78[2][3]) + S87[2][1]*(Jc8[1][2]*Si78[2][1] + Jc8[2][2]*Si78[2][2] + Jc8[3][2]*Si78[2][3]) + S87[3][1]*(Jc8[1][3]*Si78[2][1] + Jc8[2][3]*Si78[2][2] + Jc8[3][3]*Si78[2][3]) + (-(eff[1].x[3]*S87[1][2]) + eff[1].x[2]*S87[1][3])*(Jc8[1][4]*Si78[2][1] + Jc8[2][4]*Si78[2][2] + Jc8[3][4]*Si78[2][3]) + (-(eff[1].x[3]*S87[2][2]) + eff[1].x[2]*S87[2][3])*(Jc8[1][5]*Si78[2][1] + Jc8[2][5]*Si78[2][2] + Jc8[3][5]*Si78[2][3]) + (-(eff[1].x[3]*S87[3][2]) + eff[1].x[2]*S87[3][3])*(Jc8[1][6]*Si78[2][1] + Jc8[2][6]*Si78[2][2] + Jc8[3][6]*Si78[2][3]) - Jc9[1][3]*Si79[2][1] - Jc9[2][3]*Si79[2][2] - l7z*S97[1][2]*(Jc9[1][4]*Si79[2][1] + Jc9[2][4]*Si79[2][2]) - l7z*S97[2][2]*(Jc9[1][5]*Si79[2][1] + Jc9[2][5]*Si79[2][2]);
Jc7[2][2]=S127[1][2]*(Jc12[1][1]*Si712[2][1] + Jc12[2][1]*Si712[2][2]) + S127[2][2]*(Jc12[1][2]*Si712[2][1] + Jc12[2][2]*Si712[2][2]) + l6z*S127[1][1]*(Jc12[1][4]*Si712[2][1] + Jc12[2][4]*Si712[2][2]) + l6z*S127[2][1]*(Jc12[1][5]*Si712[2][1] + Jc12[2][5]*Si712[2][2]) + l6x*(Jc12[1][6]*Si712[2][1] + Jc12[2][6]*Si712[2][2]) + S87[1][2]*(Jc8[1][1]*Si78[2][1] + Jc8[2][1]*Si78[2][2] + Jc8[3][1]*Si78[2][3]) + S87[2][2]*(Jc8[1][2]*Si78[2][1] + Jc8[2][2]*Si78[2][2] + Jc8[3][2]*Si78[2][3]) + S87[3][2]*(Jc8[1][3]*Si78[2][1] + Jc8[2][3]*Si78[2][2] + Jc8[3][3]*Si78[2][3]) + (eff[1].x[3]*S87[1][1] - eff[1].x[1]*S87[1][3])*(Jc8[1][4]*Si78[2][1] + Jc8[2][4]*Si78[2][2] + Jc8[3][4]*Si78[2][3]) + (eff[1].x[3]*S87[2][1] - eff[1].x[1]*S87[2][3])*(Jc8[1][5]*Si78[2][1] + Jc8[2][5]*Si78[2][2] + Jc8[3][5]*Si78[2][3]) + (eff[1].x[3]*S87[3][1] - eff[1].x[1]*S87[3][3])*(Jc8[1][6]*Si78[2][1] + Jc8[2][6]*Si78[2][2] + Jc8[3][6]*Si78[2][3]) + S97[1][2]*(Jc9[1][1]*Si79[2][1] + Jc9[2][1]*Si79[2][2]) + S97[2][2]*(Jc9[1][2]*Si79[2][1] + Jc9[2][2]*Si79[2][2]) + l6x*S97[1][3]*(Jc9[1][4]*Si79[2][1] + Jc9[2][4]*Si79[2][2]) + l6x*S97[2][3]*(Jc9[1][5]*Si79[2][1] + Jc9[2][5]*Si79[2][2]) - l7z*(Jc9[1][6]*Si79[2][1] + Jc9[2][6]*Si79[2][2]);
Jc7[2][3]=links[7].mcm[1] + Jc12[1][3]*Si712[2][1] + Jc12[2][3]*Si712[2][2] + (-(l6y*S127[1][1]) - l6x*S127[1][2])*(Jc12[1][4]*Si712[2][1] + Jc12[2][4]*Si712[2][2]) + (-(l6y*S127[2][1]) - l6x*S127[2][2])*(Jc12[1][5]*Si712[2][1] + Jc12[2][5]*Si712[2][2]) + S87[1][3]*(Jc8[1][1]*Si78[2][1] + Jc8[2][1]*Si78[2][2] + Jc8[3][1]*Si78[2][3]) + S87[2][3]*(Jc8[1][2]*Si78[2][1] + Jc8[2][2]*Si78[2][2] + Jc8[3][2]*Si78[2][3]) + S87[3][3]*(Jc8[1][3]*Si78[2][1] + Jc8[2][3]*Si78[2][2] + Jc8[3][3]*Si78[2][3]) + (-(eff[1].x[2]*S87[1][1]) + eff[1].x[1]*S87[1][2])*(Jc8[1][4]*Si78[2][1] + Jc8[2][4]*Si78[2][2] + Jc8[3][4]*Si78[2][3]) + (-(eff[1].x[2]*S87[2][1]) + eff[1].x[1]*S87[2][2])*(Jc8[1][5]*Si78[2][1] + Jc8[2][5]*Si78[2][2] + Jc8[3][5]*Si78[2][3]) + (-(eff[1].x[2]*S87[3][1]) + eff[1].x[1]*S87[3][2])*(Jc8[1][6]*Si78[2][1] + Jc8[2][6]*Si78[2][2] + Jc8[3][6]*Si78[2][3]) + S97[1][3]*(Jc9[1][1]*Si79[2][1] + Jc9[2][1]*Si79[2][2]) + S97[2][3]*(Jc9[1][2]*Si79[2][1] + Jc9[2][2]*Si79[2][2]) - l6x*S97[1][2]*(Jc9[1][4]*Si79[2][1] + Jc9[2][4]*Si79[2][2]) - l6x*S97[2][2]*(Jc9[1][5]*Si79[2][1] + Jc9[2][5]*Si79[2][2]);
Jc7[2][4]=S127[1][1]*(Jc12[1][4]*Si712[2][1] + Jc12[2][4]*Si712[2][2]) + S127[2][1]*(Jc12[1][5]*Si712[2][1] + Jc12[2][5]*Si712[2][2]) + S87[1][1]*(Jc8[1][4]*Si78[2][1] + Jc8[2][4]*Si78[2][2] + Jc8[3][4]*Si78[2][3]) + S87[2][1]*(Jc8[1][5]*Si78[2][1] + Jc8[2][5]*Si78[2][2] + Jc8[3][5]*Si78[2][3]) + S87[3][1]*(Jc8[1][6]*Si78[2][1] + Jc8[2][6]*Si78[2][2] + Jc8[3][6]*Si78[2][3]) - Jc9[1][6]*Si79[2][1] - Jc9[2][6]*Si79[2][2];
Jc7[2][5]=links[7].m + S127[1][2]*(Jc12[1][4]*Si712[2][1] + Jc12[2][4]*Si712[2][2]) + S127[2][2]*(Jc12[1][5]*Si712[2][1] + Jc12[2][5]*Si712[2][2]) + S87[1][2]*(Jc8[1][4]*Si78[2][1] + Jc8[2][4]*Si78[2][2] + Jc8[3][4]*Si78[2][3]) + S87[2][2]*(Jc8[1][5]*Si78[2][1] + Jc8[2][5]*Si78[2][2] + Jc8[3][5]*Si78[2][3]) + S87[3][2]*(Jc8[1][6]*Si78[2][1] + Jc8[2][6]*Si78[2][2] + Jc8[3][6]*Si78[2][3]) + S97[1][2]*(Jc9[1][4]*Si79[2][1] + Jc9[2][4]*Si79[2][2]) + S97[2][2]*(Jc9[1][5]*Si79[2][1] + Jc9[2][5]*Si79[2][2]);
Jc7[2][6]=Jc12[1][6]*Si712[2][1] + Jc12[2][6]*Si712[2][2] + S87[1][3]*(Jc8[1][4]*Si78[2][1] + Jc8[2][4]*Si78[2][2] + Jc8[3][4]*Si78[2][3]) + S87[2][3]*(Jc8[1][5]*Si78[2][1] + Jc8[2][5]*Si78[2][2] + Jc8[3][5]*Si78[2][3]) + S87[3][3]*(Jc8[1][6]*Si78[2][1] + Jc8[2][6]*Si78[2][2] + Jc8[3][6]*Si78[2][3]) + S97[1][3]*(Jc9[1][4]*Si79[2][1] + Jc9[2][4]*Si79[2][2]) + S97[2][3]*(Jc9[1][5]*Si79[2][1] + Jc9[2][5]*Si79[2][2]);

Jc7[3][1]=links[7].mcm[2] + l6y*Jc12[3][6] + Jc12[3][1]*S127[1][1] - l6z*Jc12[3][4]*S127[1][2] + Jc12[3][2]*S127[2][1] - l6z*Jc12[3][5]*S127[2][2] + S87[1][1]*(Jc8[1][1]*Si78[3][1] + Jc8[2][1]*Si78[3][2] + Jc8[3][1]*Si78[3][3]) + S87[2][1]*(Jc8[1][2]*Si78[3][1] + Jc8[2][2]*Si78[3][2] + Jc8[3][2]*Si78[3][3]) + S87[3][1]*(Jc8[1][3]*Si78[3][1] + Jc8[2][3]*Si78[3][2] + Jc8[3][3]*Si78[3][3]) + (-(eff[1].x[3]*S87[1][2]) + eff[1].x[2]*S87[1][3])*(Jc8[1][4]*Si78[3][1] + Jc8[2][4]*Si78[3][2] + Jc8[3][4]*Si78[3][3]) + (-(eff[1].x[3]*S87[2][2]) + eff[1].x[2]*S87[2][3])*(Jc8[1][5]*Si78[3][1] + Jc8[2][5]*Si78[3][2] + Jc8[3][5]*Si78[3][3]) + (-(eff[1].x[3]*S87[3][2]) + eff[1].x[2]*S87[3][3])*(Jc8[1][6]*Si78[3][1] + Jc8[2][6]*Si78[3][2] + Jc8[3][6]*Si78[3][3]) - Jc9[1][3]*Si79[3][1] - Jc9[2][3]*Si79[3][2] - l7z*S97[1][2]*(Jc9[1][4]*Si79[3][1] + Jc9[2][4]*Si79[3][2]) - l7z*S97[2][2]*(Jc9[1][5]*Si79[3][1] + Jc9[2][5]*Si79[3][2]);
Jc7[3][2]=-links[7].mcm[1] + l6x*Jc12[3][6] + l6z*Jc12[3][4]*S127[1][1] + Jc12[3][1]*S127[1][2] + l6z*Jc12[3][5]*S127[2][1] + Jc12[3][2]*S127[2][2] + S87[1][2]*(Jc8[1][1]*Si78[3][1] + Jc8[2][1]*Si78[3][2] + Jc8[3][1]*Si78[3][3]) + S87[2][2]*(Jc8[1][2]*Si78[3][1] + Jc8[2][2]*Si78[3][2] + Jc8[3][2]*Si78[3][3]) + S87[3][2]*(Jc8[1][3]*Si78[3][1] + Jc8[2][3]*Si78[3][2] + Jc8[3][3]*Si78[3][3]) + (eff[1].x[3]*S87[1][1] - eff[1].x[1]*S87[1][3])*(Jc8[1][4]*Si78[3][1] + Jc8[2][4]*Si78[3][2] + Jc8[3][4]*Si78[3][3]) + (eff[1].x[3]*S87[2][1] - eff[1].x[1]*S87[2][3])*(Jc8[1][5]*Si78[3][1] + Jc8[2][5]*Si78[3][2] + Jc8[3][5]*Si78[3][3]) + (eff[1].x[3]*S87[3][1] - eff[1].x[1]*S87[3][3])*(Jc8[1][6]*Si78[3][1] + Jc8[2][6]*Si78[3][2] + Jc8[3][6]*Si78[3][3]) + S97[1][2]*(Jc9[1][1]*Si79[3][1] + Jc9[2][1]*Si79[3][2]) + S97[2][2]*(Jc9[1][2]*Si79[3][1] + Jc9[2][2]*Si79[3][2]) + l6x*S97[1][3]*(Jc9[1][4]*Si79[3][1] + Jc9[2][4]*Si79[3][2]) + l6x*S97[2][3]*(Jc9[1][5]*Si79[3][1] + Jc9[2][5]*Si79[3][2]) - l7z*(Jc9[1][6]*Si79[3][1] + Jc9[2][6]*Si79[3][2]);
Jc7[3][3]=Jc12[3][3] + Jc12[3][4]*(-(l6y*S127[1][1]) - l6x*S127[1][2]) + Jc12[3][5]*(-(l6y*S127[2][1]) - l6x*S127[2][2]) + S87[1][3]*(Jc8[1][1]*Si78[3][1] + Jc8[2][1]*Si78[3][2] + Jc8[3][1]*Si78[3][3]) + S87[2][3]*(Jc8[1][2]*Si78[3][1] + Jc8[2][2]*Si78[3][2] + Jc8[3][2]*Si78[3][3]) + S87[3][3]*(Jc8[1][3]*Si78[3][1] + Jc8[2][3]*Si78[3][2] + Jc8[3][3]*Si78[3][3]) + (-(eff[1].x[2]*S87[1][1]) + eff[1].x[1]*S87[1][2])*(Jc8[1][4]*Si78[3][1] + Jc8[2][4]*Si78[3][2] + Jc8[3][4]*Si78[3][3]) + (-(eff[1].x[2]*S87[2][1]) + eff[1].x[1]*S87[2][2])*(Jc8[1][5]*Si78[3][1] + Jc8[2][5]*Si78[3][2] + Jc8[3][5]*Si78[3][3]) + (-(eff[1].x[2]*S87[3][1]) + eff[1].x[1]*S87[3][2])*(Jc8[1][6]*Si78[3][1] + Jc8[2][6]*Si78[3][2] + Jc8[3][6]*Si78[3][3]) + S97[1][3]*(Jc9[1][1]*Si79[3][1] + Jc9[2][1]*Si79[3][2]) + S97[2][3]*(Jc9[1][2]*Si79[3][1] + Jc9[2][2]*Si79[3][2]) - l6x*S97[1][2]*(Jc9[1][4]*Si79[3][1] + Jc9[2][4]*Si79[3][2]) - l6x*S97[2][2]*(Jc9[1][5]*Si79[3][1] + Jc9[2][5]*Si79[3][2]);
Jc7[3][4]=Jc12[3][4]*S127[1][1] + Jc12[3][5]*S127[2][1] + S87[1][1]*(Jc8[1][4]*Si78[3][1] + Jc8[2][4]*Si78[3][2] + Jc8[3][4]*Si78[3][3]) + S87[2][1]*(Jc8[1][5]*Si78[3][1] + Jc8[2][5]*Si78[3][2] + Jc8[3][5]*Si78[3][3]) + S87[3][1]*(Jc8[1][6]*Si78[3][1] + Jc8[2][6]*Si78[3][2] + Jc8[3][6]*Si78[3][3]) - Jc9[1][6]*Si79[3][1] - Jc9[2][6]*Si79[3][2];
Jc7[3][5]=Jc12[3][4]*S127[1][2] + Jc12[3][5]*S127[2][2] + S87[1][2]*(Jc8[1][4]*Si78[3][1] + Jc8[2][4]*Si78[3][2] + Jc8[3][4]*Si78[3][3]) + S87[2][2]*(Jc8[1][5]*Si78[3][1] + Jc8[2][5]*Si78[3][2] + Jc8[3][5]*Si78[3][3]) + S87[3][2]*(Jc8[1][6]*Si78[3][1] + Jc8[2][6]*Si78[3][2] + Jc8[3][6]*Si78[3][3]) + S97[1][2]*(Jc9[1][4]*Si79[3][1] + Jc9[2][4]*Si79[3][2]) + S97[2][2]*(Jc9[1][5]*Si79[3][1] + Jc9[2][5]*Si79[3][2]);
Jc7[3][6]=links[7].m + Jc12[3][6] + S87[1][3]*(Jc8[1][4]*Si78[3][1] + Jc8[2][4]*Si78[3][2] + Jc8[3][4]*Si78[3][3]) + S87[2][3]*(Jc8[1][5]*Si78[3][1] + Jc8[2][5]*Si78[3][2] + Jc8[3][5]*Si78[3][3]) + S87[3][3]*(Jc8[1][6]*Si78[3][1] + Jc8[2][6]*Si78[3][2] + Jc8[3][6]*Si78[3][3]) + S97[1][3]*(Jc9[1][4]*Si79[3][1] + Jc9[2][4]*Si79[3][2]) + S97[2][3]*(Jc9[1][5]*Si79[3][1] + Jc9[2][5]*Si79[3][2]);

Jc7[4][1]=Jc9[6][3] + links[7].inertia[1][1] + S127[1][1]*(l6y*Jc12[3][1] + Jc12[4][1]*Si712[1][1] + Jc12[5][1]*Si712[1][2] - l6z*Jc12[1][1]*Si712[2][1] - l6z*Jc12[2][1]*Si712[2][2]) + S127[2][1]*(l6y*Jc12[3][2] + Jc12[4][2]*Si712[1][1] + Jc12[5][2]*Si712[1][2] - l6z*Jc12[1][2]*Si712[2][1] - l6z*Jc12[2][2]*Si712[2][2]) - l6z*S127[1][2]*(l6y*Jc12[3][4] + Jc12[4][4]*Si712[1][1] + Jc12[5][4]*Si712[1][2] - l6z*Jc12[1][4]*Si712[2][1] - l6z*Jc12[2][4]*Si712[2][2]) - l6z*S127[2][2]*(l6y*Jc12[3][5] + Jc12[4][5]*Si712[1][1] + Jc12[5][5]*Si712[1][2] - l6z*Jc12[1][5]*Si712[2][1] - l6z*Jc12[2][5]*Si712[2][2]) + l6y*(l6y*Jc12[3][6] + Jc12[4][6]*Si712[1][1] + Jc12[5][6]*Si712[1][2] - l6z*Jc12[1][6]*Si712[2][1] - l6z*Jc12[2][6]*Si712[2][2]) + S87[1][1]*(Jc8[4][1]*Si78[1][1] + Jc8[5][1]*Si78[1][2] + Jc8[6][1]*Si78[1][3] + Jc8[1][1]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][1]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][1]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + S87[2][1]*(Jc8[4][2]*Si78[1][1] + Jc8[5][2]*Si78[1][2] + Jc8[6][2]*Si78[1][3] + Jc8[1][2]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][2]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][2]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + S87[3][1]*(Jc8[4][3]*Si78[1][1] + Jc8[5][3]*Si78[1][2] + Jc8[6][3]*Si78[1][3] + Jc8[1][3]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][3]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][3]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + (-(eff[1].x[3]*S87[1][2]) + eff[1].x[2]*S87[1][3])*(Jc8[4][4]*Si78[1][1] + Jc8[5][4]*Si78[1][2] + Jc8[6][4]*Si78[1][3] + Jc8[1][4]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][4]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][4]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + (-(eff[1].x[3]*S87[2][2]) + eff[1].x[2]*S87[2][3])*(Jc8[4][5]*Si78[1][1] + Jc8[5][5]*Si78[1][2] + Jc8[6][5]*Si78[1][3] + Jc8[1][5]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][5]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][5]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + (-(eff[1].x[3]*S87[3][2]) + eff[1].x[2]*S87[3][3])*(Jc8[4][6]*Si78[1][1] + Jc8[5][6]*Si78[1][2] + Jc8[6][6]*Si78[1][3] + Jc8[1][6]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][6]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][6]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + l7z*Jc9[1][3]*Si79[2][1] + l7z*Jc9[2][3]*Si79[2][2] - l7z*S97[1][2]*(-Jc9[6][4] - l7z*Jc9[1][4]*Si79[2][1] - l7z*Jc9[2][4]*Si79[2][2]) - l7z*S97[2][2]*(-Jc9[6][5] - l7z*Jc9[1][5]*Si79[2][1] - l7z*Jc9[2][5]*Si79[2][2]);
Jc7[4][2]=links[7].inertia[1][2] + S127[1][2]*(l6y*Jc12[3][1] + Jc12[4][1]*Si712[1][1] + Jc12[5][1]*Si712[1][2] - l6z*Jc12[1][1]*Si712[2][1] - l6z*Jc12[2][1]*Si712[2][2]) + S127[2][2]*(l6y*Jc12[3][2] + Jc12[4][2]*Si712[1][1] + Jc12[5][2]*Si712[1][2] - l6z*Jc12[1][2]*Si712[2][1] - l6z*Jc12[2][2]*Si712[2][2]) + l6z*S127[1][1]*(l6y*Jc12[3][4] + Jc12[4][4]*Si712[1][1] + Jc12[5][4]*Si712[1][2] - l6z*Jc12[1][4]*Si712[2][1] - l6z*Jc12[2][4]*Si712[2][2]) + l6z*S127[2][1]*(l6y*Jc12[3][5] + Jc12[4][5]*Si712[1][1] + Jc12[5][5]*Si712[1][2] - l6z*Jc12[1][5]*Si712[2][1] - l6z*Jc12[2][5]*Si712[2][2]) + l6x*(l6y*Jc12[3][6] + Jc12[4][6]*Si712[1][1] + Jc12[5][6]*Si712[1][2] - l6z*Jc12[1][6]*Si712[2][1] - l6z*Jc12[2][6]*Si712[2][2]) + S87[1][2]*(Jc8[4][1]*Si78[1][1] + Jc8[5][1]*Si78[1][2] + Jc8[6][1]*Si78[1][3] + Jc8[1][1]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][1]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][1]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + S87[2][2]*(Jc8[4][2]*Si78[1][1] + Jc8[5][2]*Si78[1][2] + Jc8[6][2]*Si78[1][3] + Jc8[1][2]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][2]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][2]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + S87[3][2]*(Jc8[4][3]*Si78[1][1] + Jc8[5][3]*Si78[1][2] + Jc8[6][3]*Si78[1][3] + Jc8[1][3]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][3]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][3]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + (eff[1].x[3]*S87[1][1] - eff[1].x[1]*S87[1][3])*(Jc8[4][4]*Si78[1][1] + Jc8[5][4]*Si78[1][2] + Jc8[6][4]*Si78[1][3] + Jc8[1][4]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][4]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][4]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + (eff[1].x[3]*S87[2][1] - eff[1].x[1]*S87[2][3])*(Jc8[4][5]*Si78[1][1] + Jc8[5][5]*Si78[1][2] + Jc8[6][5]*Si78[1][3] + Jc8[1][5]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][5]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][5]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + (eff[1].x[3]*S87[3][1] - eff[1].x[1]*S87[3][3])*(Jc8[4][6]*Si78[1][1] + Jc8[5][6]*Si78[1][2] + Jc8[6][6]*Si78[1][3] + Jc8[1][6]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][6]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][6]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + S97[1][2]*(-Jc9[6][1] - l7z*Jc9[1][1]*Si79[2][1] - l7z*Jc9[2][1]*Si79[2][2]) + S97[2][2]*(-Jc9[6][2] - l7z*Jc9[1][2]*Si79[2][1] - l7z*Jc9[2][2]*Si79[2][2]) + l6x*S97[1][3]*(-Jc9[6][4] - l7z*Jc9[1][4]*Si79[2][1] - l7z*Jc9[2][4]*Si79[2][2]) + l6x*S97[2][3]*(-Jc9[6][5] - l7z*Jc9[1][5]*Si79[2][1] - l7z*Jc9[2][5]*Si79[2][2]) - l7z*(-Jc9[6][6] - l7z*Jc9[1][6]*Si79[2][1] - l7z*Jc9[2][6]*Si79[2][2]);
Jc7[4][3]=l6y*Jc12[3][3] + links[7].inertia[1][3] + Jc12[4][3]*Si712[1][1] + Jc12[5][3]*Si712[1][2] - l6z*Jc12[1][3]*Si712[2][1] - l6z*Jc12[2][3]*Si712[2][2] + (-(l6y*S127[1][1]) - l6x*S127[1][2])*(l6y*Jc12[3][4] + Jc12[4][4]*Si712[1][1] + Jc12[5][4]*Si712[1][2] - l6z*Jc12[1][4]*Si712[2][1] - l6z*Jc12[2][4]*Si712[2][2]) + (-(l6y*S127[2][1]) - l6x*S127[2][2])*(l6y*Jc12[3][5] + Jc12[4][5]*Si712[1][1] + Jc12[5][5]*Si712[1][2] - l6z*Jc12[1][5]*Si712[2][1] - l6z*Jc12[2][5]*Si712[2][2]) + S87[1][3]*(Jc8[4][1]*Si78[1][1] + Jc8[5][1]*Si78[1][2] + Jc8[6][1]*Si78[1][3] + Jc8[1][1]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][1]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][1]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + S87[2][3]*(Jc8[4][2]*Si78[1][1] + Jc8[5][2]*Si78[1][2] + Jc8[6][2]*Si78[1][3] + Jc8[1][2]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][2]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][2]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + S87[3][3]*(Jc8[4][3]*Si78[1][1] + Jc8[5][3]*Si78[1][2] + Jc8[6][3]*Si78[1][3] + Jc8[1][3]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][3]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][3]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + (-(eff[1].x[2]*S87[1][1]) + eff[1].x[1]*S87[1][2])*(Jc8[4][4]*Si78[1][1] + Jc8[5][4]*Si78[1][2] + Jc8[6][4]*Si78[1][3] + Jc8[1][4]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][4]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][4]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + (-(eff[1].x[2]*S87[2][1]) + eff[1].x[1]*S87[2][2])*(Jc8[4][5]*Si78[1][1] + Jc8[5][5]*Si78[1][2] + Jc8[6][5]*Si78[1][3] + Jc8[1][5]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][5]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][5]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + (-(eff[1].x[2]*S87[3][1]) + eff[1].x[1]*S87[3][2])*(Jc8[4][6]*Si78[1][1] + Jc8[5][6]*Si78[1][2] + Jc8[6][6]*Si78[1][3] + Jc8[1][6]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][6]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][6]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + S97[1][3]*(-Jc9[6][1] - l7z*Jc9[1][1]*Si79[2][1] - l7z*Jc9[2][1]*Si79[2][2]) + S97[2][3]*(-Jc9[6][2] - l7z*Jc9[1][2]*Si79[2][1] - l7z*Jc9[2][2]*Si79[2][2]) - l6x*S97[1][2]*(-Jc9[6][4] - l7z*Jc9[1][4]*Si79[2][1] - l7z*Jc9[2][4]*Si79[2][2]) - l6x*S97[2][2]*(-Jc9[6][5] - l7z*Jc9[1][5]*Si79[2][1] - l7z*Jc9[2][5]*Si79[2][2]);
Jc7[4][4]=Jc9[6][6] + S127[1][1]*(l6y*Jc12[3][4] + Jc12[4][4]*Si712[1][1] + Jc12[5][4]*Si712[1][2] - l6z*Jc12[1][4]*Si712[2][1] - l6z*Jc12[2][4]*Si712[2][2]) + S127[2][1]*(l6y*Jc12[3][5] + Jc12[4][5]*Si712[1][1] + Jc12[5][5]*Si712[1][2] - l6z*Jc12[1][5]*Si712[2][1] - l6z*Jc12[2][5]*Si712[2][2]) + S87[1][1]*(Jc8[4][4]*Si78[1][1] + Jc8[5][4]*Si78[1][2] + Jc8[6][4]*Si78[1][3] + Jc8[1][4]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][4]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][4]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + S87[2][1]*(Jc8[4][5]*Si78[1][1] + Jc8[5][5]*Si78[1][2] + Jc8[6][5]*Si78[1][3] + Jc8[1][5]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][5]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][5]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + S87[3][1]*(Jc8[4][6]*Si78[1][1] + Jc8[5][6]*Si78[1][2] + Jc8[6][6]*Si78[1][3] + Jc8[1][6]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][6]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][6]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + l7z*Jc9[1][6]*Si79[2][1] + l7z*Jc9[2][6]*Si79[2][2];
Jc7[4][5]=-links[7].mcm[3] + S127[1][2]*(l6y*Jc12[3][4] + Jc12[4][4]*Si712[1][1] + Jc12[5][4]*Si712[1][2] - l6z*Jc12[1][4]*Si712[2][1] - l6z*Jc12[2][4]*Si712[2][2]) + S127[2][2]*(l6y*Jc12[3][5] + Jc12[4][5]*Si712[1][1] + Jc12[5][5]*Si712[1][2] - l6z*Jc12[1][5]*Si712[2][1] - l6z*Jc12[2][5]*Si712[2][2]) + S87[1][2]*(Jc8[4][4]*Si78[1][1] + Jc8[5][4]*Si78[1][2] + Jc8[6][4]*Si78[1][3] + Jc8[1][4]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][4]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][4]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + S87[2][2]*(Jc8[4][5]*Si78[1][1] + Jc8[5][5]*Si78[1][2] + Jc8[6][5]*Si78[1][3] + Jc8[1][5]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][5]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][5]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + S87[3][2]*(Jc8[4][6]*Si78[1][1] + Jc8[5][6]*Si78[1][2] + Jc8[6][6]*Si78[1][3] + Jc8[1][6]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][6]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][6]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + S97[1][2]*(-Jc9[6][4] - l7z*Jc9[1][4]*Si79[2][1] - l7z*Jc9[2][4]*Si79[2][2]) + S97[2][2]*(-Jc9[6][5] - l7z*Jc9[1][5]*Si79[2][1] - l7z*Jc9[2][5]*Si79[2][2]);
Jc7[4][6]=links[7].mcm[2] + l6y*Jc12[3][6] + Jc12[4][6]*Si712[1][1] + Jc12[5][6]*Si712[1][2] - l6z*Jc12[1][6]*Si712[2][1] - l6z*Jc12[2][6]*Si712[2][2] + S87[1][3]*(Jc8[4][4]*Si78[1][1] + Jc8[5][4]*Si78[1][2] + Jc8[6][4]*Si78[1][3] + Jc8[1][4]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][4]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][4]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + S87[2][3]*(Jc8[4][5]*Si78[1][1] + Jc8[5][5]*Si78[1][2] + Jc8[6][5]*Si78[1][3] + Jc8[1][5]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][5]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][5]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + S87[3][3]*(Jc8[4][6]*Si78[1][1] + Jc8[5][6]*Si78[1][2] + Jc8[6][6]*Si78[1][3] + Jc8[1][6]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + Jc8[2][6]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + Jc8[3][6]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])) + S97[1][3]*(-Jc9[6][4] - l7z*Jc9[1][4]*Si79[2][1] - l7z*Jc9[2][4]*Si79[2][2]) + S97[2][3]*(-Jc9[6][5] - l7z*Jc9[1][5]*Si79[2][1] - l7z*Jc9[2][5]*Si79[2][2]);

Jc7[5][1]=l7z*Jc9[3][3] + links[7].inertia[1][2] + S127[1][1]*(l6x*Jc12[3][1] + l6z*Jc12[1][1]*Si712[1][1] + l6z*Jc12[2][1]*Si712[1][2] + Jc12[4][1]*Si712[2][1] + Jc12[5][1]*Si712[2][2]) + S127[2][1]*(l6x*Jc12[3][2] + l6z*Jc12[1][2]*Si712[1][1] + l6z*Jc12[2][2]*Si712[1][2] + Jc12[4][2]*Si712[2][1] + Jc12[5][2]*Si712[2][2]) - l6z*S127[1][2]*(l6x*Jc12[3][4] + l6z*Jc12[1][4]*Si712[1][1] + l6z*Jc12[2][4]*Si712[1][2] + Jc12[4][4]*Si712[2][1] + Jc12[5][4]*Si712[2][2]) - l6z*S127[2][2]*(l6x*Jc12[3][5] + l6z*Jc12[1][5]*Si712[1][1] + l6z*Jc12[2][5]*Si712[1][2] + Jc12[4][5]*Si712[2][1] + Jc12[5][5]*Si712[2][2]) + l6y*(l6x*Jc12[3][6] + l6z*Jc12[1][6]*Si712[1][1] + l6z*Jc12[2][6]*Si712[1][2] + Jc12[4][6]*Si712[2][1] + Jc12[5][6]*Si712[2][2]) + S87[1][1]*(Jc8[4][1]*Si78[2][1] + Jc8[5][1]*Si78[2][2] + Jc8[6][1]*Si78[2][3] + Jc8[1][1]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][1]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][1]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + S87[2][1]*(Jc8[4][2]*Si78[2][1] + Jc8[5][2]*Si78[2][2] + Jc8[6][2]*Si78[2][3] + Jc8[1][2]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][2]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][2]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + S87[3][1]*(Jc8[4][3]*Si78[2][1] + Jc8[5][3]*Si78[2][2] + Jc8[6][3]*Si78[2][3] + Jc8[1][3]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][3]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][3]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + (-(eff[1].x[3]*S87[1][2]) + eff[1].x[2]*S87[1][3])*(Jc8[4][4]*Si78[2][1] + Jc8[5][4]*Si78[2][2] + Jc8[6][4]*Si78[2][3] + Jc8[1][4]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][4]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][4]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + (-(eff[1].x[3]*S87[2][2]) + eff[1].x[2]*S87[2][3])*(Jc8[4][5]*Si78[2][1] + Jc8[5][5]*Si78[2][2] + Jc8[6][5]*Si78[2][3] + Jc8[1][5]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][5]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][5]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + (-(eff[1].x[3]*S87[3][2]) + eff[1].x[2]*S87[3][3])*(Jc8[4][6]*Si78[2][1] + Jc8[5][6]*Si78[2][2] + Jc8[6][6]*Si78[2][3] + Jc8[1][6]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][6]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][6]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) - Jc9[4][3]*Si79[2][1] - Jc9[5][3]*Si79[2][2] - l6x*Jc9[1][3]*Si79[3][1] - l6x*Jc9[2][3]*Si79[3][2] - l7z*S97[1][2]*(-(l7z*Jc9[3][4]) + Jc9[4][4]*Si79[2][1] + Jc9[5][4]*Si79[2][2] + l6x*Jc9[1][4]*Si79[3][1] + l6x*Jc9[2][4]*Si79[3][2]) - l7z*S97[2][2]*(-(l7z*Jc9[3][5]) + Jc9[4][5]*Si79[2][1] + Jc9[5][5]*Si79[2][2] + l6x*Jc9[1][5]*Si79[3][1] + l6x*Jc9[2][5]*Si79[3][2]);
Jc7[5][2]=links[7].inertia[2][2] + S127[1][2]*(l6x*Jc12[3][1] + l6z*Jc12[1][1]*Si712[1][1] + l6z*Jc12[2][1]*Si712[1][2] + Jc12[4][1]*Si712[2][1] + Jc12[5][1]*Si712[2][2]) + S127[2][2]*(l6x*Jc12[3][2] + l6z*Jc12[1][2]*Si712[1][1] + l6z*Jc12[2][2]*Si712[1][2] + Jc12[4][2]*Si712[2][1] + Jc12[5][2]*Si712[2][2]) + l6z*S127[1][1]*(l6x*Jc12[3][4] + l6z*Jc12[1][4]*Si712[1][1] + l6z*Jc12[2][4]*Si712[1][2] + Jc12[4][4]*Si712[2][1] + Jc12[5][4]*Si712[2][2]) + l6z*S127[2][1]*(l6x*Jc12[3][5] + l6z*Jc12[1][5]*Si712[1][1] + l6z*Jc12[2][5]*Si712[1][2] + Jc12[4][5]*Si712[2][1] + Jc12[5][5]*Si712[2][2]) + l6x*(l6x*Jc12[3][6] + l6z*Jc12[1][6]*Si712[1][1] + l6z*Jc12[2][6]*Si712[1][2] + Jc12[4][6]*Si712[2][1] + Jc12[5][6]*Si712[2][2]) + S87[1][2]*(Jc8[4][1]*Si78[2][1] + Jc8[5][1]*Si78[2][2] + Jc8[6][1]*Si78[2][3] + Jc8[1][1]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][1]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][1]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + S87[2][2]*(Jc8[4][2]*Si78[2][1] + Jc8[5][2]*Si78[2][2] + Jc8[6][2]*Si78[2][3] + Jc8[1][2]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][2]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][2]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + S87[3][2]*(Jc8[4][3]*Si78[2][1] + Jc8[5][3]*Si78[2][2] + Jc8[6][3]*Si78[2][3] + Jc8[1][3]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][3]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][3]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + (eff[1].x[3]*S87[1][1] - eff[1].x[1]*S87[1][3])*(Jc8[4][4]*Si78[2][1] + Jc8[5][4]*Si78[2][2] + Jc8[6][4]*Si78[2][3] + Jc8[1][4]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][4]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][4]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + (eff[1].x[3]*S87[2][1] - eff[1].x[1]*S87[2][3])*(Jc8[4][5]*Si78[2][1] + Jc8[5][5]*Si78[2][2] + Jc8[6][5]*Si78[2][3] + Jc8[1][5]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][5]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][5]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + (eff[1].x[3]*S87[3][1] - eff[1].x[1]*S87[3][3])*(Jc8[4][6]*Si78[2][1] + Jc8[5][6]*Si78[2][2] + Jc8[6][6]*Si78[2][3] + Jc8[1][6]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][6]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][6]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + S97[1][2]*(-(l7z*Jc9[3][1]) + Jc9[4][1]*Si79[2][1] + Jc9[5][1]*Si79[2][2] + l6x*Jc9[1][1]*Si79[3][1] + l6x*Jc9[2][1]*Si79[3][2]) + S97[2][2]*(-(l7z*Jc9[3][2]) + Jc9[4][2]*Si79[2][1] + Jc9[5][2]*Si79[2][2] + l6x*Jc9[1][2]*Si79[3][1] + l6x*Jc9[2][2]*Si79[3][2]) + l6x*S97[1][3]*(-(l7z*Jc9[3][4]) + Jc9[4][4]*Si79[2][1] + Jc9[5][4]*Si79[2][2] + l6x*Jc9[1][4]*Si79[3][1] + l6x*Jc9[2][4]*Si79[3][2]) + l6x*S97[2][3]*(-(l7z*Jc9[3][5]) + Jc9[4][5]*Si79[2][1] + Jc9[5][5]*Si79[2][2] + l6x*Jc9[1][5]*Si79[3][1] + l6x*Jc9[2][5]*Si79[3][2]) - l7z*(-(l7z*Jc9[3][6]) + Jc9[4][6]*Si79[2][1] + Jc9[5][6]*Si79[2][2] + l6x*Jc9[1][6]*Si79[3][1] + l6x*Jc9[2][6]*Si79[3][2]);
Jc7[5][3]=l6x*Jc12[3][3] + links[7].inertia[2][3] + l6z*Jc12[1][3]*Si712[1][1] + l6z*Jc12[2][3]*Si712[1][2] + Jc12[4][3]*Si712[2][1] + Jc12[5][3]*Si712[2][2] + (-(l6y*S127[1][1]) - l6x*S127[1][2])*(l6x*Jc12[3][4] + l6z*Jc12[1][4]*Si712[1][1] + l6z*Jc12[2][4]*Si712[1][2] + Jc12[4][4]*Si712[2][1] + Jc12[5][4]*Si712[2][2]) + (-(l6y*S127[2][1]) - l6x*S127[2][2])*(l6x*Jc12[3][5] + l6z*Jc12[1][5]*Si712[1][1] + l6z*Jc12[2][5]*Si712[1][2] + Jc12[4][5]*Si712[2][1] + Jc12[5][5]*Si712[2][2]) + S87[1][3]*(Jc8[4][1]*Si78[2][1] + Jc8[5][1]*Si78[2][2] + Jc8[6][1]*Si78[2][3] + Jc8[1][1]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][1]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][1]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + S87[2][3]*(Jc8[4][2]*Si78[2][1] + Jc8[5][2]*Si78[2][2] + Jc8[6][2]*Si78[2][3] + Jc8[1][2]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][2]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][2]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + S87[3][3]*(Jc8[4][3]*Si78[2][1] + Jc8[5][3]*Si78[2][2] + Jc8[6][3]*Si78[2][3] + Jc8[1][3]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][3]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][3]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + (-(eff[1].x[2]*S87[1][1]) + eff[1].x[1]*S87[1][2])*(Jc8[4][4]*Si78[2][1] + Jc8[5][4]*Si78[2][2] + Jc8[6][4]*Si78[2][3] + Jc8[1][4]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][4]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][4]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + (-(eff[1].x[2]*S87[2][1]) + eff[1].x[1]*S87[2][2])*(Jc8[4][5]*Si78[2][1] + Jc8[5][5]*Si78[2][2] + Jc8[6][5]*Si78[2][3] + Jc8[1][5]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][5]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][5]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + (-(eff[1].x[2]*S87[3][1]) + eff[1].x[1]*S87[3][2])*(Jc8[4][6]*Si78[2][1] + Jc8[5][6]*Si78[2][2] + Jc8[6][6]*Si78[2][3] + Jc8[1][6]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][6]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][6]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + S97[1][3]*(-(l7z*Jc9[3][1]) + Jc9[4][1]*Si79[2][1] + Jc9[5][1]*Si79[2][2] + l6x*Jc9[1][1]*Si79[3][1] + l6x*Jc9[2][1]*Si79[3][2]) + S97[2][3]*(-(l7z*Jc9[3][2]) + Jc9[4][2]*Si79[2][1] + Jc9[5][2]*Si79[2][2] + l6x*Jc9[1][2]*Si79[3][1] + l6x*Jc9[2][2]*Si79[3][2]) - l6x*S97[1][2]*(-(l7z*Jc9[3][4]) + Jc9[4][4]*Si79[2][1] + Jc9[5][4]*Si79[2][2] + l6x*Jc9[1][4]*Si79[3][1] + l6x*Jc9[2][4]*Si79[3][2]) - l6x*S97[2][2]*(-(l7z*Jc9[3][5]) + Jc9[4][5]*Si79[2][1] + Jc9[5][5]*Si79[2][2] + l6x*Jc9[1][5]*Si79[3][1] + l6x*Jc9[2][5]*Si79[3][2]);
Jc7[5][4]=links[7].mcm[3] + l7z*Jc9[3][6] + S127[1][1]*(l6x*Jc12[3][4] + l6z*Jc12[1][4]*Si712[1][1] + l6z*Jc12[2][4]*Si712[1][2] + Jc12[4][4]*Si712[2][1] + Jc12[5][4]*Si712[2][2]) + S127[2][1]*(l6x*Jc12[3][5] + l6z*Jc12[1][5]*Si712[1][1] + l6z*Jc12[2][5]*Si712[1][2] + Jc12[4][5]*Si712[2][1] + Jc12[5][5]*Si712[2][2]) + S87[1][1]*(Jc8[4][4]*Si78[2][1] + Jc8[5][4]*Si78[2][2] + Jc8[6][4]*Si78[2][3] + Jc8[1][4]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][4]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][4]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + S87[2][1]*(Jc8[4][5]*Si78[2][1] + Jc8[5][5]*Si78[2][2] + Jc8[6][5]*Si78[2][3] + Jc8[1][5]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][5]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][5]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + S87[3][1]*(Jc8[4][6]*Si78[2][1] + Jc8[5][6]*Si78[2][2] + Jc8[6][6]*Si78[2][3] + Jc8[1][6]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][6]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][6]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) - Jc9[4][6]*Si79[2][1] - Jc9[5][6]*Si79[2][2] - l6x*Jc9[1][6]*Si79[3][1] - l6x*Jc9[2][6]*Si79[3][2];
Jc7[5][5]=S127[1][2]*(l6x*Jc12[3][4] + l6z*Jc12[1][4]*Si712[1][1] + l6z*Jc12[2][4]*Si712[1][2] + Jc12[4][4]*Si712[2][1] + Jc12[5][4]*Si712[2][2]) + S127[2][2]*(l6x*Jc12[3][5] + l6z*Jc12[1][5]*Si712[1][1] + l6z*Jc12[2][5]*Si712[1][2] + Jc12[4][5]*Si712[2][1] + Jc12[5][5]*Si712[2][2]) + S87[1][2]*(Jc8[4][4]*Si78[2][1] + Jc8[5][4]*Si78[2][2] + Jc8[6][4]*Si78[2][3] + Jc8[1][4]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][4]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][4]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + S87[2][2]*(Jc8[4][5]*Si78[2][1] + Jc8[5][5]*Si78[2][2] + Jc8[6][5]*Si78[2][3] + Jc8[1][5]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][5]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][5]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + S87[3][2]*(Jc8[4][6]*Si78[2][1] + Jc8[5][6]*Si78[2][2] + Jc8[6][6]*Si78[2][3] + Jc8[1][6]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][6]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][6]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + S97[1][2]*(-(l7z*Jc9[3][4]) + Jc9[4][4]*Si79[2][1] + Jc9[5][4]*Si79[2][2] + l6x*Jc9[1][4]*Si79[3][1] + l6x*Jc9[2][4]*Si79[3][2]) + S97[2][2]*(-(l7z*Jc9[3][5]) + Jc9[4][5]*Si79[2][1] + Jc9[5][5]*Si79[2][2] + l6x*Jc9[1][5]*Si79[3][1] + l6x*Jc9[2][5]*Si79[3][2]);
Jc7[5][6]=-links[7].mcm[1] + l6x*Jc12[3][6] + l6z*Jc12[1][6]*Si712[1][1] + l6z*Jc12[2][6]*Si712[1][2] + Jc12[4][6]*Si712[2][1] + Jc12[5][6]*Si712[2][2] + S87[1][3]*(Jc8[4][4]*Si78[2][1] + Jc8[5][4]*Si78[2][2] + Jc8[6][4]*Si78[2][3] + Jc8[1][4]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][4]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][4]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + S87[2][3]*(Jc8[4][5]*Si78[2][1] + Jc8[5][5]*Si78[2][2] + Jc8[6][5]*Si78[2][3] + Jc8[1][5]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][5]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][5]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + S87[3][3]*(Jc8[4][6]*Si78[2][1] + Jc8[5][6]*Si78[2][2] + Jc8[6][6]*Si78[2][3] + Jc8[1][6]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + Jc8[2][6]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + Jc8[3][6]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])) + S97[1][3]*(-(l7z*Jc9[3][4]) + Jc9[4][4]*Si79[2][1] + Jc9[5][4]*Si79[2][2] + l6x*Jc9[1][4]*Si79[3][1] + l6x*Jc9[2][4]*Si79[3][2]) + S97[2][3]*(-(l7z*Jc9[3][5]) + Jc9[4][5]*Si79[2][1] + Jc9[5][5]*Si79[2][2] + l6x*Jc9[1][5]*Si79[3][1] + l6x*Jc9[2][5]*Si79[3][2]);

Jc7[6][1]=links[7].inertia[1][3] + S127[1][1]*(Jc12[6][1] + Jc12[1][1]*(-(l6y*Si712[1][1]) - l6x*Si712[2][1]) + Jc12[2][1]*(-(l6y*Si712[1][2]) - l6x*Si712[2][2])) + S127[2][1]*(Jc12[6][2] + Jc12[1][2]*(-(l6y*Si712[1][1]) - l6x*Si712[2][1]) + Jc12[2][2]*(-(l6y*Si712[1][2]) - l6x*Si712[2][2])) - l6z*S127[1][2]*(Jc12[6][4] + Jc12[1][4]*(-(l6y*Si712[1][1]) - l6x*Si712[2][1]) + Jc12[2][4]*(-(l6y*Si712[1][2]) - l6x*Si712[2][2])) - l6z*S127[2][2]*(Jc12[6][5] + Jc12[1][5]*(-(l6y*Si712[1][1]) - l6x*Si712[2][1]) + Jc12[2][5]*(-(l6y*Si712[1][2]) - l6x*Si712[2][2])) + l6y*(Jc12[6][6] + Jc12[1][6]*(-(l6y*Si712[1][1]) - l6x*Si712[2][1]) + Jc12[2][6]*(-(l6y*Si712[1][2]) - l6x*Si712[2][2])) + S87[1][1]*(Jc8[1][1]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][1]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][1]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][1]*Si78[3][1] + Jc8[5][1]*Si78[3][2] + Jc8[6][1]*Si78[3][3]) + S87[2][1]*(Jc8[1][2]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][2]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][2]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][2]*Si78[3][1] + Jc8[5][2]*Si78[3][2] + Jc8[6][2]*Si78[3][3]) + S87[3][1]*(Jc8[1][3]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][3]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][3]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][3]*Si78[3][1] + Jc8[5][3]*Si78[3][2] + Jc8[6][3]*Si78[3][3]) + (-(eff[1].x[3]*S87[1][2]) + eff[1].x[2]*S87[1][3])*(Jc8[1][4]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][4]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][4]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][4]*Si78[3][1] + Jc8[5][4]*Si78[3][2] + Jc8[6][4]*Si78[3][3]) + (-(eff[1].x[3]*S87[2][2]) + eff[1].x[2]*S87[2][3])*(Jc8[1][5]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][5]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][5]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][5]*Si78[3][1] + Jc8[5][5]*Si78[3][2] + Jc8[6][5]*Si78[3][3]) + (-(eff[1].x[3]*S87[3][2]) + eff[1].x[2]*S87[3][3])*(Jc8[1][6]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][6]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][6]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][6]*Si78[3][1] + Jc8[5][6]*Si78[3][2] + Jc8[6][6]*Si78[3][3]) + l6x*Jc9[1][3]*Si79[2][1] + l6x*Jc9[2][3]*Si79[2][2] - Jc9[4][3]*Si79[3][1] - Jc9[5][3]*Si79[3][2] - l7z*S97[1][2]*(-(l6x*Jc9[1][4]*Si79[2][1]) - l6x*Jc9[2][4]*Si79[2][2] + Jc9[4][4]*Si79[3][1] + Jc9[5][4]*Si79[3][2]) - l7z*S97[2][2]*(-(l6x*Jc9[1][5]*Si79[2][1]) - l6x*Jc9[2][5]*Si79[2][2] + Jc9[4][5]*Si79[3][1] + Jc9[5][5]*Si79[3][2]);
Jc7[6][2]=links[7].inertia[2][3] + S127[1][2]*(Jc12[6][1] + Jc12[1][1]*(-(l6y*Si712[1][1]) - l6x*Si712[2][1]) + Jc12[2][1]*(-(l6y*Si712[1][2]) - l6x*Si712[2][2])) + S127[2][2]*(Jc12[6][2] + Jc12[1][2]*(-(l6y*Si712[1][1]) - l6x*Si712[2][1]) + Jc12[2][2]*(-(l6y*Si712[1][2]) - l6x*Si712[2][2])) + l6z*S127[1][1]*(Jc12[6][4] + Jc12[1][4]*(-(l6y*Si712[1][1]) - l6x*Si712[2][1]) + Jc12[2][4]*(-(l6y*Si712[1][2]) - l6x*Si712[2][2])) + l6z*S127[2][1]*(Jc12[6][5] + Jc12[1][5]*(-(l6y*Si712[1][1]) - l6x*Si712[2][1]) + Jc12[2][5]*(-(l6y*Si712[1][2]) - l6x*Si712[2][2])) + l6x*(Jc12[6][6] + Jc12[1][6]*(-(l6y*Si712[1][1]) - l6x*Si712[2][1]) + Jc12[2][6]*(-(l6y*Si712[1][2]) - l6x*Si712[2][2])) + S87[1][2]*(Jc8[1][1]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][1]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][1]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][1]*Si78[3][1] + Jc8[5][1]*Si78[3][2] + Jc8[6][1]*Si78[3][3]) + S87[2][2]*(Jc8[1][2]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][2]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][2]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][2]*Si78[3][1] + Jc8[5][2]*Si78[3][2] + Jc8[6][2]*Si78[3][3]) + S87[3][2]*(Jc8[1][3]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][3]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][3]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][3]*Si78[3][1] + Jc8[5][3]*Si78[3][2] + Jc8[6][3]*Si78[3][3]) + (eff[1].x[3]*S87[1][1] - eff[1].x[1]*S87[1][3])*(Jc8[1][4]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][4]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][4]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][4]*Si78[3][1] + Jc8[5][4]*Si78[3][2] + Jc8[6][4]*Si78[3][3]) + (eff[1].x[3]*S87[2][1] - eff[1].x[1]*S87[2][3])*(Jc8[1][5]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][5]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][5]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][5]*Si78[3][1] + Jc8[5][5]*Si78[3][2] + Jc8[6][5]*Si78[3][3]) + (eff[1].x[3]*S87[3][1] - eff[1].x[1]*S87[3][3])*(Jc8[1][6]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][6]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][6]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][6]*Si78[3][1] + Jc8[5][6]*Si78[3][2] + Jc8[6][6]*Si78[3][3]) + S97[1][2]*(-(l6x*Jc9[1][1]*Si79[2][1]) - l6x*Jc9[2][1]*Si79[2][2] + Jc9[4][1]*Si79[3][1] + Jc9[5][1]*Si79[3][2]) + S97[2][2]*(-(l6x*Jc9[1][2]*Si79[2][1]) - l6x*Jc9[2][2]*Si79[2][2] + Jc9[4][2]*Si79[3][1] + Jc9[5][2]*Si79[3][2]) + l6x*S97[1][3]*(-(l6x*Jc9[1][4]*Si79[2][1]) - l6x*Jc9[2][4]*Si79[2][2] + Jc9[4][4]*Si79[3][1] + Jc9[5][4]*Si79[3][2]) + l6x*S97[2][3]*(-(l6x*Jc9[1][5]*Si79[2][1]) - l6x*Jc9[2][5]*Si79[2][2] + Jc9[4][5]*Si79[3][1] + Jc9[5][5]*Si79[3][2]) - l7z*(-(l6x*Jc9[1][6]*Si79[2][1]) - l6x*Jc9[2][6]*Si79[2][2] + Jc9[4][6]*Si79[3][1] + Jc9[5][6]*Si79[3][2]);
Jc7[6][3]=Jc12[6][3] + links[7].inertia[3][3] + Jc12[1][3]*(-(l6y*Si712[1][1]) - l6x*Si712[2][1]) + Jc12[2][3]*(-(l6y*Si712[1][2]) - l6x*Si712[2][2]) + (-(l6y*S127[1][1]) - l6x*S127[1][2])*(Jc12[6][4] + Jc12[1][4]*(-(l6y*Si712[1][1]) - l6x*Si712[2][1]) + Jc12[2][4]*(-(l6y*Si712[1][2]) - l6x*Si712[2][2])) + (-(l6y*S127[2][1]) - l6x*S127[2][2])*(Jc12[6][5] + Jc12[1][5]*(-(l6y*Si712[1][1]) - l6x*Si712[2][1]) + Jc12[2][5]*(-(l6y*Si712[1][2]) - l6x*Si712[2][2])) + S87[1][3]*(Jc8[1][1]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][1]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][1]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][1]*Si78[3][1] + Jc8[5][1]*Si78[3][2] + Jc8[6][1]*Si78[3][3]) + S87[2][3]*(Jc8[1][2]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][2]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][2]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][2]*Si78[3][1] + Jc8[5][2]*Si78[3][2] + Jc8[6][2]*Si78[3][3]) + S87[3][3]*(Jc8[1][3]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][3]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][3]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][3]*Si78[3][1] + Jc8[5][3]*Si78[3][2] + Jc8[6][3]*Si78[3][3]) + (-(eff[1].x[2]*S87[1][1]) + eff[1].x[1]*S87[1][2])*(Jc8[1][4]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][4]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][4]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][4]*Si78[3][1] + Jc8[5][4]*Si78[3][2] + Jc8[6][4]*Si78[3][3]) + (-(eff[1].x[2]*S87[2][1]) + eff[1].x[1]*S87[2][2])*(Jc8[1][5]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][5]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][5]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][5]*Si78[3][1] + Jc8[5][5]*Si78[3][2] + Jc8[6][5]*Si78[3][3]) + (-(eff[1].x[2]*S87[3][1]) + eff[1].x[1]*S87[3][2])*(Jc8[1][6]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][6]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][6]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][6]*Si78[3][1] + Jc8[5][6]*Si78[3][2] + Jc8[6][6]*Si78[3][3]) + S97[1][3]*(-(l6x*Jc9[1][1]*Si79[2][1]) - l6x*Jc9[2][1]*Si79[2][2] + Jc9[4][1]*Si79[3][1] + Jc9[5][1]*Si79[3][2]) + S97[2][3]*(-(l6x*Jc9[1][2]*Si79[2][1]) - l6x*Jc9[2][2]*Si79[2][2] + Jc9[4][2]*Si79[3][1] + Jc9[5][2]*Si79[3][2]) - l6x*S97[1][2]*(-(l6x*Jc9[1][4]*Si79[2][1]) - l6x*Jc9[2][4]*Si79[2][2] + Jc9[4][4]*Si79[3][1] + Jc9[5][4]*Si79[3][2]) - l6x*S97[2][2]*(-(l6x*Jc9[1][5]*Si79[2][1]) - l6x*Jc9[2][5]*Si79[2][2] + Jc9[4][5]*Si79[3][1] + Jc9[5][5]*Si79[3][2]);
Jc7[6][4]=-links[7].mcm[2] + S127[1][1]*(Jc12[6][4] + Jc12[1][4]*(-(l6y*Si712[1][1]) - l6x*Si712[2][1]) + Jc12[2][4]*(-(l6y*Si712[1][2]) - l6x*Si712[2][2])) + S127[2][1]*(Jc12[6][5] + Jc12[1][5]*(-(l6y*Si712[1][1]) - l6x*Si712[2][1]) + Jc12[2][5]*(-(l6y*Si712[1][2]) - l6x*Si712[2][2])) + S87[1][1]*(Jc8[1][4]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][4]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][4]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][4]*Si78[3][1] + Jc8[5][4]*Si78[3][2] + Jc8[6][4]*Si78[3][3]) + S87[2][1]*(Jc8[1][5]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][5]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][5]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][5]*Si78[3][1] + Jc8[5][5]*Si78[3][2] + Jc8[6][5]*Si78[3][3]) + S87[3][1]*(Jc8[1][6]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][6]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][6]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][6]*Si78[3][1] + Jc8[5][6]*Si78[3][2] + Jc8[6][6]*Si78[3][3]) + l6x*Jc9[1][6]*Si79[2][1] + l6x*Jc9[2][6]*Si79[2][2] - Jc9[4][6]*Si79[3][1] - Jc9[5][6]*Si79[3][2];
Jc7[6][5]=links[7].mcm[1] + S127[1][2]*(Jc12[6][4] + Jc12[1][4]*(-(l6y*Si712[1][1]) - l6x*Si712[2][1]) + Jc12[2][4]*(-(l6y*Si712[1][2]) - l6x*Si712[2][2])) + S127[2][2]*(Jc12[6][5] + Jc12[1][5]*(-(l6y*Si712[1][1]) - l6x*Si712[2][1]) + Jc12[2][5]*(-(l6y*Si712[1][2]) - l6x*Si712[2][2])) + S87[1][2]*(Jc8[1][4]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][4]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][4]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][4]*Si78[3][1] + Jc8[5][4]*Si78[3][2] + Jc8[6][4]*Si78[3][3]) + S87[2][2]*(Jc8[1][5]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][5]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][5]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][5]*Si78[3][1] + Jc8[5][5]*Si78[3][2] + Jc8[6][5]*Si78[3][3]) + S87[3][2]*(Jc8[1][6]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][6]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][6]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][6]*Si78[3][1] + Jc8[5][6]*Si78[3][2] + Jc8[6][6]*Si78[3][3]) + S97[1][2]*(-(l6x*Jc9[1][4]*Si79[2][1]) - l6x*Jc9[2][4]*Si79[2][2] + Jc9[4][4]*Si79[3][1] + Jc9[5][4]*Si79[3][2]) + S97[2][2]*(-(l6x*Jc9[1][5]*Si79[2][1]) - l6x*Jc9[2][5]*Si79[2][2] + Jc9[4][5]*Si79[3][1] + Jc9[5][5]*Si79[3][2]);
Jc7[6][6]=Jc12[6][6] + Jc12[1][6]*(-(l6y*Si712[1][1]) - l6x*Si712[2][1]) + Jc12[2][6]*(-(l6y*Si712[1][2]) - l6x*Si712[2][2]) + S87[1][3]*(Jc8[1][4]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][4]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][4]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][4]*Si78[3][1] + Jc8[5][4]*Si78[3][2] + Jc8[6][4]*Si78[3][3]) + S87[2][3]*(Jc8[1][5]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][5]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][5]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][5]*Si78[3][1] + Jc8[5][5]*Si78[3][2] + Jc8[6][5]*Si78[3][3]) + S87[3][3]*(Jc8[1][6]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + Jc8[2][6]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + Jc8[3][6]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + Jc8[4][6]*Si78[3][1] + Jc8[5][6]*Si78[3][2] + Jc8[6][6]*Si78[3][3]) + S97[1][3]*(-(l6x*Jc9[1][4]*Si79[2][1]) - l6x*Jc9[2][4]*Si79[2][2] + Jc9[4][4]*Si79[3][1] + Jc9[5][4]*Si79[3][2]) + S97[2][3]*(-(l6x*Jc9[1][5]*Si79[2][1]) - l6x*Jc9[2][5]*Si79[2][2] + Jc9[4][5]*Si79[3][1] + Jc9[5][5]*Si79[3][2]);



}


void
masterfunc18(void)
      {
/* composite inertia matrices */
Jc6[1][1]=Jc7[3][3] - l5*Jc7[3][4]*S76[1][2] - l5*Jc7[3][5]*S76[2][2];
Jc6[1][2]=links[6].mcm[3] + l5*Jc7[3][6] + Jc7[3][1]*S76[1][2] + Jc7[3][2]*S76[2][2];
Jc6[1][3]=-links[6].mcm[2] + Jc7[3][1]*S76[1][3] + Jc7[3][2]*S76[2][3];
Jc6[1][4]=links[6].m + Jc7[3][6];
Jc6[1][5]=Jc7[3][4]*S76[1][2] + Jc7[3][5]*S76[2][2];
Jc6[1][6]=Jc7[3][4]*S76[1][3] + Jc7[3][5]*S76[2][3];

Jc6[2][1]=-links[6].mcm[3] + Jc7[1][3]*Si67[2][1] + Jc7[2][3]*Si67[2][2] - l5*S76[1][2]*(Jc7[1][4]*Si67[2][1] + Jc7[2][4]*Si67[2][2]) - l5*S76[2][2]*(Jc7[1][5]*Si67[2][1] + Jc7[2][5]*Si67[2][2]);
Jc6[2][2]=S76[1][2]*(Jc7[1][1]*Si67[2][1] + Jc7[2][1]*Si67[2][2]) + S76[2][2]*(Jc7[1][2]*Si67[2][1] + Jc7[2][2]*Si67[2][2]) + l5*(Jc7[1][6]*Si67[2][1] + Jc7[2][6]*Si67[2][2]);
Jc6[2][3]=links[6].mcm[1] + S76[1][3]*(Jc7[1][1]*Si67[2][1] + Jc7[2][1]*Si67[2][2]) + S76[2][3]*(Jc7[1][2]*Si67[2][1] + Jc7[2][2]*Si67[2][2]);
Jc6[2][4]=Jc7[1][6]*Si67[2][1] + Jc7[2][6]*Si67[2][2];
Jc6[2][5]=links[6].m + S76[1][2]*(Jc7[1][4]*Si67[2][1] + Jc7[2][4]*Si67[2][2]) + S76[2][2]*(Jc7[1][5]*Si67[2][1] + Jc7[2][5]*Si67[2][2]);
Jc6[2][6]=S76[1][3]*(Jc7[1][4]*Si67[2][1] + Jc7[2][4]*Si67[2][2]) + S76[2][3]*(Jc7[1][5]*Si67[2][1] + Jc7[2][5]*Si67[2][2]);

Jc6[3][1]=links[6].mcm[2] + Jc7[1][3]*Si67[3][1] + Jc7[2][3]*Si67[3][2] - l5*S76[1][2]*(Jc7[1][4]*Si67[3][1] + Jc7[2][4]*Si67[3][2]) - l5*S76[2][2]*(Jc7[1][5]*Si67[3][1] + Jc7[2][5]*Si67[3][2]);
Jc6[3][2]=-links[6].mcm[1] + S76[1][2]*(Jc7[1][1]*Si67[3][1] + Jc7[2][1]*Si67[3][2]) + S76[2][2]*(Jc7[1][2]*Si67[3][1] + Jc7[2][2]*Si67[3][2]) + l5*(Jc7[1][6]*Si67[3][1] + Jc7[2][6]*Si67[3][2]);
Jc6[3][3]=S76[1][3]*(Jc7[1][1]*Si67[3][1] + Jc7[2][1]*Si67[3][2]) + S76[2][3]*(Jc7[1][2]*Si67[3][1] + Jc7[2][2]*Si67[3][2]);
Jc6[3][4]=Jc7[1][6]*Si67[3][1] + Jc7[2][6]*Si67[3][2];
Jc6[3][5]=S76[1][2]*(Jc7[1][4]*Si67[3][1] + Jc7[2][4]*Si67[3][2]) + S76[2][2]*(Jc7[1][5]*Si67[3][1] + Jc7[2][5]*Si67[3][2]);
Jc6[3][6]=links[6].m + S76[1][3]*(Jc7[1][4]*Si67[3][1] + Jc7[2][4]*Si67[3][2]) + S76[2][3]*(Jc7[1][5]*Si67[3][1] + Jc7[2][5]*Si67[3][2]);

Jc6[4][1]=Jc7[6][3] + links[6].inertia[1][1] - l5*Jc7[1][3]*Si67[2][1] - l5*Jc7[2][3]*Si67[2][2] - l5*S76[1][2]*(Jc7[6][4] - l5*Jc7[1][4]*Si67[2][1] - l5*Jc7[2][4]*Si67[2][2]) - l5*S76[2][2]*(Jc7[6][5] - l5*Jc7[1][5]*Si67[2][1] - l5*Jc7[2][5]*Si67[2][2]);
Jc6[4][2]=links[6].inertia[1][2] + S76[1][2]*(Jc7[6][1] - l5*Jc7[1][1]*Si67[2][1] - l5*Jc7[2][1]*Si67[2][2]) + S76[2][2]*(Jc7[6][2] - l5*Jc7[1][2]*Si67[2][1] - l5*Jc7[2][2]*Si67[2][2]) + l5*(Jc7[6][6] - l5*Jc7[1][6]*Si67[2][1] - l5*Jc7[2][6]*Si67[2][2]);
Jc6[4][3]=links[6].inertia[1][3] + S76[1][3]*(Jc7[6][1] - l5*Jc7[1][1]*Si67[2][1] - l5*Jc7[2][1]*Si67[2][2]) + S76[2][3]*(Jc7[6][2] - l5*Jc7[1][2]*Si67[2][1] - l5*Jc7[2][2]*Si67[2][2]);
Jc6[4][4]=Jc7[6][6] - l5*Jc7[1][6]*Si67[2][1] - l5*Jc7[2][6]*Si67[2][2];
Jc6[4][5]=-links[6].mcm[3] + S76[1][2]*(Jc7[6][4] - l5*Jc7[1][4]*Si67[2][1] - l5*Jc7[2][4]*Si67[2][2]) + S76[2][2]*(Jc7[6][5] - l5*Jc7[1][5]*Si67[2][1] - l5*Jc7[2][5]*Si67[2][2]);
Jc6[4][6]=links[6].mcm[2] + S76[1][3]*(Jc7[6][4] - l5*Jc7[1][4]*Si67[2][1] - l5*Jc7[2][4]*Si67[2][2]) + S76[2][3]*(Jc7[6][5] - l5*Jc7[1][5]*Si67[2][1] - l5*Jc7[2][5]*Si67[2][2]);

Jc6[5][1]=l5*Jc7[3][3] + links[6].inertia[1][2] + Jc7[4][3]*Si67[2][1] + Jc7[5][3]*Si67[2][2] - l5*S76[1][2]*(l5*Jc7[3][4] + Jc7[4][4]*Si67[2][1] + Jc7[5][4]*Si67[2][2]) - l5*S76[2][2]*(l5*Jc7[3][5] + Jc7[4][5]*Si67[2][1] + Jc7[5][5]*Si67[2][2]);
Jc6[5][2]=links[6].inertia[2][2] + S76[1][2]*(l5*Jc7[3][1] + Jc7[4][1]*Si67[2][1] + Jc7[5][1]*Si67[2][2]) + S76[2][2]*(l5*Jc7[3][2] + Jc7[4][2]*Si67[2][1] + Jc7[5][2]*Si67[2][2]) + l5*(l5*Jc7[3][6] + Jc7[4][6]*Si67[2][1] + Jc7[5][6]*Si67[2][2]);
Jc6[5][3]=links[6].inertia[2][3] + S76[1][3]*(l5*Jc7[3][1] + Jc7[4][1]*Si67[2][1] + Jc7[5][1]*Si67[2][2]) + S76[2][3]*(l5*Jc7[3][2] + Jc7[4][2]*Si67[2][1] + Jc7[5][2]*Si67[2][2]);
Jc6[5][4]=links[6].mcm[3] + l5*Jc7[3][6] + Jc7[4][6]*Si67[2][1] + Jc7[5][6]*Si67[2][2];
Jc6[5][5]=S76[1][2]*(l5*Jc7[3][4] + Jc7[4][4]*Si67[2][1] + Jc7[5][4]*Si67[2][2]) + S76[2][2]*(l5*Jc7[3][5] + Jc7[4][5]*Si67[2][1] + Jc7[5][5]*Si67[2][2]);
Jc6[5][6]=-links[6].mcm[1] + S76[1][3]*(l5*Jc7[3][4] + Jc7[4][4]*Si67[2][1] + Jc7[5][4]*Si67[2][2]) + S76[2][3]*(l5*Jc7[3][5] + Jc7[4][5]*Si67[2][1] + Jc7[5][5]*Si67[2][2]);

Jc6[6][1]=links[6].inertia[1][3] + Jc7[4][3]*Si67[3][1] + Jc7[5][3]*Si67[3][2] - l5*S76[1][2]*(Jc7[4][4]*Si67[3][1] + Jc7[5][4]*Si67[3][2]) - l5*S76[2][2]*(Jc7[4][5]*Si67[3][1] + Jc7[5][5]*Si67[3][2]);
Jc6[6][2]=links[6].inertia[2][3] + S76[1][2]*(Jc7[4][1]*Si67[3][1] + Jc7[5][1]*Si67[3][2]) + S76[2][2]*(Jc7[4][2]*Si67[3][1] + Jc7[5][2]*Si67[3][2]) + l5*(Jc7[4][6]*Si67[3][1] + Jc7[5][6]*Si67[3][2]);
Jc6[6][3]=links[6].inertia[3][3] + S76[1][3]*(Jc7[4][1]*Si67[3][1] + Jc7[5][1]*Si67[3][2]) + S76[2][3]*(Jc7[4][2]*Si67[3][1] + Jc7[5][2]*Si67[3][2]);
Jc6[6][4]=-links[6].mcm[2] + Jc7[4][6]*Si67[3][1] + Jc7[5][6]*Si67[3][2];
Jc6[6][5]=links[6].mcm[1] + S76[1][2]*(Jc7[4][4]*Si67[3][1] + Jc7[5][4]*Si67[3][2]) + S76[2][2]*(Jc7[4][5]*Si67[3][1] + Jc7[5][5]*Si67[3][2]);
Jc6[6][6]=S76[1][3]*(Jc7[4][4]*Si67[3][1] + Jc7[5][4]*Si67[3][2]) + S76[2][3]*(Jc7[4][5]*Si67[3][1] + Jc7[5][5]*Si67[3][2]);



}


void
masterfunc19(void)
      {
/* composite inertia matrices */
Jc5[1][1]=S65[1][1]*(Jc6[1][1]*Si56[1][1] + Jc6[2][1]*Si56[1][2]) + S65[2][1]*(Jc6[1][2]*Si56[1][1] + Jc6[2][2]*Si56[1][2]) - l4*(Jc6[1][6]*Si56[1][1] + Jc6[2][6]*Si56[1][2]);
Jc5[1][2]=links[5].mcm[3] + Jc6[1][3]*Si56[1][1] + Jc6[2][3]*Si56[1][2] + l4*S65[1][1]*(Jc6[1][4]*Si56[1][1] + Jc6[2][4]*Si56[1][2]) + l4*S65[2][1]*(Jc6[1][5]*Si56[1][1] + Jc6[2][5]*Si56[1][2]);
Jc5[1][3]=-links[5].mcm[2] + S65[1][3]*(Jc6[1][1]*Si56[1][1] + Jc6[2][1]*Si56[1][2]) + S65[2][3]*(Jc6[1][2]*Si56[1][1] + Jc6[2][2]*Si56[1][2]);
Jc5[1][4]=links[5].m + S65[1][1]*(Jc6[1][4]*Si56[1][1] + Jc6[2][4]*Si56[1][2]) + S65[2][1]*(Jc6[1][5]*Si56[1][1] + Jc6[2][5]*Si56[1][2]);
Jc5[1][5]=Jc6[1][6]*Si56[1][1] + Jc6[2][6]*Si56[1][2];
Jc5[1][6]=S65[1][3]*(Jc6[1][4]*Si56[1][1] + Jc6[2][4]*Si56[1][2]) + S65[2][3]*(Jc6[1][5]*Si56[1][1] + Jc6[2][5]*Si56[1][2]);

Jc5[2][1]=-links[5].mcm[3] - l4*Jc6[3][6] + Jc6[3][1]*S65[1][1] + Jc6[3][2]*S65[2][1];
Jc5[2][2]=Jc6[3][3] + l4*Jc6[3][4]*S65[1][1] + l4*Jc6[3][5]*S65[2][1];
Jc5[2][3]=links[5].mcm[1] + Jc6[3][1]*S65[1][3] + Jc6[3][2]*S65[2][3];
Jc5[2][4]=Jc6[3][4]*S65[1][1] + Jc6[3][5]*S65[2][1];
Jc5[2][5]=links[5].m + Jc6[3][6];
Jc5[2][6]=Jc6[3][4]*S65[1][3] + Jc6[3][5]*S65[2][3];

Jc5[3][1]=links[5].mcm[2] + S65[1][1]*(Jc6[1][1]*Si56[3][1] + Jc6[2][1]*Si56[3][2]) + S65[2][1]*(Jc6[1][2]*Si56[3][1] + Jc6[2][2]*Si56[3][2]) - l4*(Jc6[1][6]*Si56[3][1] + Jc6[2][6]*Si56[3][2]);
Jc5[3][2]=-links[5].mcm[1] + Jc6[1][3]*Si56[3][1] + Jc6[2][3]*Si56[3][2] + l4*S65[1][1]*(Jc6[1][4]*Si56[3][1] + Jc6[2][4]*Si56[3][2]) + l4*S65[2][1]*(Jc6[1][5]*Si56[3][1] + Jc6[2][5]*Si56[3][2]);
Jc5[3][3]=S65[1][3]*(Jc6[1][1]*Si56[3][1] + Jc6[2][1]*Si56[3][2]) + S65[2][3]*(Jc6[1][2]*Si56[3][1] + Jc6[2][2]*Si56[3][2]);
Jc5[3][4]=S65[1][1]*(Jc6[1][4]*Si56[3][1] + Jc6[2][4]*Si56[3][2]) + S65[2][1]*(Jc6[1][5]*Si56[3][1] + Jc6[2][5]*Si56[3][2]);
Jc5[3][5]=Jc6[1][6]*Si56[3][1] + Jc6[2][6]*Si56[3][2];
Jc5[3][6]=links[5].m + S65[1][3]*(Jc6[1][4]*Si56[3][1] + Jc6[2][4]*Si56[3][2]) + S65[2][3]*(Jc6[1][5]*Si56[3][1] + Jc6[2][5]*Si56[3][2]);

Jc5[4][1]=links[5].inertia[1][1] + S65[1][1]*(-(l4*Jc6[3][1]) + Jc6[4][1]*Si56[1][1] + Jc6[5][1]*Si56[1][2]) + S65[2][1]*(-(l4*Jc6[3][2]) + Jc6[4][2]*Si56[1][1] + Jc6[5][2]*Si56[1][2]) - l4*(-(l4*Jc6[3][6]) + Jc6[4][6]*Si56[1][1] + Jc6[5][6]*Si56[1][2]);
Jc5[4][2]=-(l4*Jc6[3][3]) + links[5].inertia[1][2] + Jc6[4][3]*Si56[1][1] + Jc6[5][3]*Si56[1][2] + l4*S65[1][1]*(-(l4*Jc6[3][4]) + Jc6[4][4]*Si56[1][1] + Jc6[5][4]*Si56[1][2]) + l4*S65[2][1]*(-(l4*Jc6[3][5]) + Jc6[4][5]*Si56[1][1] + Jc6[5][5]*Si56[1][2]);
Jc5[4][3]=links[5].inertia[1][3] + S65[1][3]*(-(l4*Jc6[3][1]) + Jc6[4][1]*Si56[1][1] + Jc6[5][1]*Si56[1][2]) + S65[2][3]*(-(l4*Jc6[3][2]) + Jc6[4][2]*Si56[1][1] + Jc6[5][2]*Si56[1][2]);
Jc5[4][4]=S65[1][1]*(-(l4*Jc6[3][4]) + Jc6[4][4]*Si56[1][1] + Jc6[5][4]*Si56[1][2]) + S65[2][1]*(-(l4*Jc6[3][5]) + Jc6[4][5]*Si56[1][1] + Jc6[5][5]*Si56[1][2]);
Jc5[4][5]=-links[5].mcm[3] - l4*Jc6[3][6] + Jc6[4][6]*Si56[1][1] + Jc6[5][6]*Si56[1][2];
Jc5[4][6]=links[5].mcm[2] + S65[1][3]*(-(l4*Jc6[3][4]) + Jc6[4][4]*Si56[1][1] + Jc6[5][4]*Si56[1][2]) + S65[2][3]*(-(l4*Jc6[3][5]) + Jc6[4][5]*Si56[1][1] + Jc6[5][5]*Si56[1][2]);

Jc5[5][1]=links[5].inertia[1][2] + S65[1][1]*(Jc6[6][1] + l4*Jc6[1][1]*Si56[1][1] + l4*Jc6[2][1]*Si56[1][2]) + S65[2][1]*(Jc6[6][2] + l4*Jc6[1][2]*Si56[1][1] + l4*Jc6[2][2]*Si56[1][2]) - l4*(Jc6[6][6] + l4*Jc6[1][6]*Si56[1][1] + l4*Jc6[2][6]*Si56[1][2]);
Jc5[5][2]=Jc6[6][3] + links[5].inertia[2][2] + l4*Jc6[1][3]*Si56[1][1] + l4*Jc6[2][3]*Si56[1][2] + l4*S65[1][1]*(Jc6[6][4] + l4*Jc6[1][4]*Si56[1][1] + l4*Jc6[2][4]*Si56[1][2]) + l4*S65[2][1]*(Jc6[6][5] + l4*Jc6[1][5]*Si56[1][1] + l4*Jc6[2][5]*Si56[1][2]);
Jc5[5][3]=links[5].inertia[2][3] + S65[1][3]*(Jc6[6][1] + l4*Jc6[1][1]*Si56[1][1] + l4*Jc6[2][1]*Si56[1][2]) + S65[2][3]*(Jc6[6][2] + l4*Jc6[1][2]*Si56[1][1] + l4*Jc6[2][2]*Si56[1][2]);
Jc5[5][4]=links[5].mcm[3] + S65[1][1]*(Jc6[6][4] + l4*Jc6[1][4]*Si56[1][1] + l4*Jc6[2][4]*Si56[1][2]) + S65[2][1]*(Jc6[6][5] + l4*Jc6[1][5]*Si56[1][1] + l4*Jc6[2][5]*Si56[1][2]);
Jc5[5][5]=Jc6[6][6] + l4*Jc6[1][6]*Si56[1][1] + l4*Jc6[2][6]*Si56[1][2];
Jc5[5][6]=-links[5].mcm[1] + S65[1][3]*(Jc6[6][4] + l4*Jc6[1][4]*Si56[1][1] + l4*Jc6[2][4]*Si56[1][2]) + S65[2][3]*(Jc6[6][5] + l4*Jc6[1][5]*Si56[1][1] + l4*Jc6[2][5]*Si56[1][2]);

Jc5[6][1]=links[5].inertia[1][3] + S65[1][1]*(Jc6[4][1]*Si56[3][1] + Jc6[5][1]*Si56[3][2]) + S65[2][1]*(Jc6[4][2]*Si56[3][1] + Jc6[5][2]*Si56[3][2]) - l4*(Jc6[4][6]*Si56[3][1] + Jc6[5][6]*Si56[3][2]);
Jc5[6][2]=links[5].inertia[2][3] + Jc6[4][3]*Si56[3][1] + Jc6[5][3]*Si56[3][2] + l4*S65[1][1]*(Jc6[4][4]*Si56[3][1] + Jc6[5][4]*Si56[3][2]) + l4*S65[2][1]*(Jc6[4][5]*Si56[3][1] + Jc6[5][5]*Si56[3][2]);
Jc5[6][3]=links[5].inertia[3][3] + S65[1][3]*(Jc6[4][1]*Si56[3][1] + Jc6[5][1]*Si56[3][2]) + S65[2][3]*(Jc6[4][2]*Si56[3][1] + Jc6[5][2]*Si56[3][2]);
Jc5[6][4]=-links[5].mcm[2] + S65[1][1]*(Jc6[4][4]*Si56[3][1] + Jc6[5][4]*Si56[3][2]) + S65[2][1]*(Jc6[4][5]*Si56[3][1] + Jc6[5][5]*Si56[3][2]);
Jc5[6][5]=links[5].mcm[1] + Jc6[4][6]*Si56[3][1] + Jc6[5][6]*Si56[3][2];
Jc5[6][6]=S65[1][3]*(Jc6[4][4]*Si56[3][1] + Jc6[5][4]*Si56[3][2]) + S65[2][3]*(Jc6[4][5]*Si56[3][1] + Jc6[5][5]*Si56[3][2]);



}


void
masterfunc20(void)
      {
/* composite inertia matrices */
Jc4[1][1]=Jc5[3][3] - l3*Jc5[3][4]*S54[1][2] - l3*Jc5[3][5]*S54[2][2];
Jc4[1][2]=links[4].mcm[3] - l3*Jc5[3][6] - Jc5[3][1]*S54[1][2] - Jc5[3][2]*S54[2][2];
Jc4[1][3]=-links[4].mcm[2] - Jc5[3][1]*S54[1][3] - Jc5[3][2]*S54[2][3];
Jc4[1][4]=links[4].m + Jc5[3][6];
Jc4[1][5]=-(Jc5[3][4]*S54[1][2]) - Jc5[3][5]*S54[2][2];
Jc4[1][6]=-(Jc5[3][4]*S54[1][3]) - Jc5[3][5]*S54[2][3];

Jc4[2][1]=-links[4].mcm[3] - Jc5[1][3]*Si45[2][1] - Jc5[2][3]*Si45[2][2] + l3*S54[1][2]*(Jc5[1][4]*Si45[2][1] + Jc5[2][4]*Si45[2][2]) + l3*S54[2][2]*(Jc5[1][5]*Si45[2][1] + Jc5[2][5]*Si45[2][2]);
Jc4[2][2]=S54[1][2]*(Jc5[1][1]*Si45[2][1] + Jc5[2][1]*Si45[2][2]) + S54[2][2]*(Jc5[1][2]*Si45[2][1] + Jc5[2][2]*Si45[2][2]) + l3*(Jc5[1][6]*Si45[2][1] + Jc5[2][6]*Si45[2][2]);
Jc4[2][3]=links[4].mcm[1] + S54[1][3]*(Jc5[1][1]*Si45[2][1] + Jc5[2][1]*Si45[2][2]) + S54[2][3]*(Jc5[1][2]*Si45[2][1] + Jc5[2][2]*Si45[2][2]);
Jc4[2][4]=-(Jc5[1][6]*Si45[2][1]) - Jc5[2][6]*Si45[2][2];
Jc4[2][5]=links[4].m + S54[1][2]*(Jc5[1][4]*Si45[2][1] + Jc5[2][4]*Si45[2][2]) + S54[2][2]*(Jc5[1][5]*Si45[2][1] + Jc5[2][5]*Si45[2][2]);
Jc4[2][6]=S54[1][3]*(Jc5[1][4]*Si45[2][1] + Jc5[2][4]*Si45[2][2]) + S54[2][3]*(Jc5[1][5]*Si45[2][1] + Jc5[2][5]*Si45[2][2]);

Jc4[3][1]=links[4].mcm[2] - Jc5[1][3]*Si45[3][1] - Jc5[2][3]*Si45[3][2] + l3*S54[1][2]*(Jc5[1][4]*Si45[3][1] + Jc5[2][4]*Si45[3][2]) + l3*S54[2][2]*(Jc5[1][5]*Si45[3][1] + Jc5[2][5]*Si45[3][2]);
Jc4[3][2]=-links[4].mcm[1] + S54[1][2]*(Jc5[1][1]*Si45[3][1] + Jc5[2][1]*Si45[3][2]) + S54[2][2]*(Jc5[1][2]*Si45[3][1] + Jc5[2][2]*Si45[3][2]) + l3*(Jc5[1][6]*Si45[3][1] + Jc5[2][6]*Si45[3][2]);
Jc4[3][3]=S54[1][3]*(Jc5[1][1]*Si45[3][1] + Jc5[2][1]*Si45[3][2]) + S54[2][3]*(Jc5[1][2]*Si45[3][1] + Jc5[2][2]*Si45[3][2]);
Jc4[3][4]=-(Jc5[1][6]*Si45[3][1]) - Jc5[2][6]*Si45[3][2];
Jc4[3][5]=S54[1][2]*(Jc5[1][4]*Si45[3][1] + Jc5[2][4]*Si45[3][2]) + S54[2][2]*(Jc5[1][5]*Si45[3][1] + Jc5[2][5]*Si45[3][2]);
Jc4[3][6]=links[4].m + S54[1][3]*(Jc5[1][4]*Si45[3][1] + Jc5[2][4]*Si45[3][2]) + S54[2][3]*(Jc5[1][5]*Si45[3][1] + Jc5[2][5]*Si45[3][2]);

Jc4[4][1]=Jc5[6][3] + links[4].inertia[1][1] - l3*Jc5[1][3]*Si45[2][1] - l3*Jc5[2][3]*Si45[2][2] + l3*S54[1][2]*(-Jc5[6][4] + l3*Jc5[1][4]*Si45[2][1] + l3*Jc5[2][4]*Si45[2][2]) + l3*S54[2][2]*(-Jc5[6][5] + l3*Jc5[1][5]*Si45[2][1] + l3*Jc5[2][5]*Si45[2][2]);
Jc4[4][2]=links[4].inertia[1][2] + S54[1][2]*(-Jc5[6][1] + l3*Jc5[1][1]*Si45[2][1] + l3*Jc5[2][1]*Si45[2][2]) + S54[2][2]*(-Jc5[6][2] + l3*Jc5[1][2]*Si45[2][1] + l3*Jc5[2][2]*Si45[2][2]) + l3*(-Jc5[6][6] + l3*Jc5[1][6]*Si45[2][1] + l3*Jc5[2][6]*Si45[2][2]);
Jc4[4][3]=links[4].inertia[1][3] + S54[1][3]*(-Jc5[6][1] + l3*Jc5[1][1]*Si45[2][1] + l3*Jc5[2][1]*Si45[2][2]) + S54[2][3]*(-Jc5[6][2] + l3*Jc5[1][2]*Si45[2][1] + l3*Jc5[2][2]*Si45[2][2]);
Jc4[4][4]=Jc5[6][6] - l3*Jc5[1][6]*Si45[2][1] - l3*Jc5[2][6]*Si45[2][2];
Jc4[4][5]=-links[4].mcm[3] + S54[1][2]*(-Jc5[6][4] + l3*Jc5[1][4]*Si45[2][1] + l3*Jc5[2][4]*Si45[2][2]) + S54[2][2]*(-Jc5[6][5] + l3*Jc5[1][5]*Si45[2][1] + l3*Jc5[2][5]*Si45[2][2]);
Jc4[4][6]=links[4].mcm[2] + S54[1][3]*(-Jc5[6][4] + l3*Jc5[1][4]*Si45[2][1] + l3*Jc5[2][4]*Si45[2][2]) + S54[2][3]*(-Jc5[6][5] + l3*Jc5[1][5]*Si45[2][1] + l3*Jc5[2][5]*Si45[2][2]);

Jc4[5][1]=-(l3*Jc5[3][3]) + links[4].inertia[1][2] - Jc5[4][3]*Si45[2][1] - Jc5[5][3]*Si45[2][2] + l3*S54[1][2]*(l3*Jc5[3][4] + Jc5[4][4]*Si45[2][1] + Jc5[5][4]*Si45[2][2]) + l3*S54[2][2]*(l3*Jc5[3][5] + Jc5[4][5]*Si45[2][1] + Jc5[5][5]*Si45[2][2]);
Jc4[5][2]=links[4].inertia[2][2] + S54[1][2]*(l3*Jc5[3][1] + Jc5[4][1]*Si45[2][1] + Jc5[5][1]*Si45[2][2]) + S54[2][2]*(l3*Jc5[3][2] + Jc5[4][2]*Si45[2][1] + Jc5[5][2]*Si45[2][2]) + l3*(l3*Jc5[3][6] + Jc5[4][6]*Si45[2][1] + Jc5[5][6]*Si45[2][2]);
Jc4[5][3]=links[4].inertia[2][3] + S54[1][3]*(l3*Jc5[3][1] + Jc5[4][1]*Si45[2][1] + Jc5[5][1]*Si45[2][2]) + S54[2][3]*(l3*Jc5[3][2] + Jc5[4][2]*Si45[2][1] + Jc5[5][2]*Si45[2][2]);
Jc4[5][4]=links[4].mcm[3] - l3*Jc5[3][6] - Jc5[4][6]*Si45[2][1] - Jc5[5][6]*Si45[2][2];
Jc4[5][5]=S54[1][2]*(l3*Jc5[3][4] + Jc5[4][4]*Si45[2][1] + Jc5[5][4]*Si45[2][2]) + S54[2][2]*(l3*Jc5[3][5] + Jc5[4][5]*Si45[2][1] + Jc5[5][5]*Si45[2][2]);
Jc4[5][6]=-links[4].mcm[1] + S54[1][3]*(l3*Jc5[3][4] + Jc5[4][4]*Si45[2][1] + Jc5[5][4]*Si45[2][2]) + S54[2][3]*(l3*Jc5[3][5] + Jc5[4][5]*Si45[2][1] + Jc5[5][5]*Si45[2][2]);

Jc4[6][1]=links[4].inertia[1][3] - Jc5[4][3]*Si45[3][1] - Jc5[5][3]*Si45[3][2] + l3*S54[1][2]*(Jc5[4][4]*Si45[3][1] + Jc5[5][4]*Si45[3][2]) + l3*S54[2][2]*(Jc5[4][5]*Si45[3][1] + Jc5[5][5]*Si45[3][2]);
Jc4[6][2]=links[4].inertia[2][3] + S54[1][2]*(Jc5[4][1]*Si45[3][1] + Jc5[5][1]*Si45[3][2]) + S54[2][2]*(Jc5[4][2]*Si45[3][1] + Jc5[5][2]*Si45[3][2]) + l3*(Jc5[4][6]*Si45[3][1] + Jc5[5][6]*Si45[3][2]);
Jc4[6][3]=links[4].inertia[3][3] + S54[1][3]*(Jc5[4][1]*Si45[3][1] + Jc5[5][1]*Si45[3][2]) + S54[2][3]*(Jc5[4][2]*Si45[3][1] + Jc5[5][2]*Si45[3][2]);
Jc4[6][4]=-links[4].mcm[2] - Jc5[4][6]*Si45[3][1] - Jc5[5][6]*Si45[3][2];
Jc4[6][5]=links[4].mcm[1] + S54[1][2]*(Jc5[4][4]*Si45[3][1] + Jc5[5][4]*Si45[3][2]) + S54[2][2]*(Jc5[4][5]*Si45[3][1] + Jc5[5][5]*Si45[3][2]);
Jc4[6][6]=S54[1][3]*(Jc5[4][4]*Si45[3][1] + Jc5[5][4]*Si45[3][2]) + S54[2][3]*(Jc5[4][5]*Si45[3][1] + Jc5[5][5]*Si45[3][2]);



}


void
masterfunc21(void)
      {
/* composite inertia matrices */
Jc3[1][1]=S43[1][1]*(Jc4[1][1]*Si34[1][1] + Jc4[2][1]*Si34[1][2]) + S43[2][1]*(Jc4[1][2]*Si34[1][1] + Jc4[2][2]*Si34[1][2]) + l2*(Jc4[1][6]*Si34[1][1] + Jc4[2][6]*Si34[1][2]);
Jc3[1][2]=links[3].mcm[3] - Jc4[1][3]*Si34[1][1] - Jc4[2][3]*Si34[1][2] + l2*S43[1][1]*(Jc4[1][4]*Si34[1][1] + Jc4[2][4]*Si34[1][2]) + l2*S43[2][1]*(Jc4[1][5]*Si34[1][1] + Jc4[2][5]*Si34[1][2]);
Jc3[1][3]=-links[3].mcm[2] + S43[1][3]*(Jc4[1][1]*Si34[1][1] + Jc4[2][1]*Si34[1][2]) + S43[2][3]*(Jc4[1][2]*Si34[1][1] + Jc4[2][2]*Si34[1][2]);
Jc3[1][4]=links[3].m + S43[1][1]*(Jc4[1][4]*Si34[1][1] + Jc4[2][4]*Si34[1][2]) + S43[2][1]*(Jc4[1][5]*Si34[1][1] + Jc4[2][5]*Si34[1][2]);
Jc3[1][5]=-(Jc4[1][6]*Si34[1][1]) - Jc4[2][6]*Si34[1][2];
Jc3[1][6]=S43[1][3]*(Jc4[1][4]*Si34[1][1] + Jc4[2][4]*Si34[1][2]) + S43[2][3]*(Jc4[1][5]*Si34[1][1] + Jc4[2][5]*Si34[1][2]);

Jc3[2][1]=-links[3].mcm[3] - l2*Jc4[3][6] - Jc4[3][1]*S43[1][1] - Jc4[3][2]*S43[2][1];
Jc3[2][2]=Jc4[3][3] - l2*Jc4[3][4]*S43[1][1] - l2*Jc4[3][5]*S43[2][1];
Jc3[2][3]=links[3].mcm[1] - Jc4[3][1]*S43[1][3] - Jc4[3][2]*S43[2][3];
Jc3[2][4]=-(Jc4[3][4]*S43[1][1]) - Jc4[3][5]*S43[2][1];
Jc3[2][5]=links[3].m + Jc4[3][6];
Jc3[2][6]=-(Jc4[3][4]*S43[1][3]) - Jc4[3][5]*S43[2][3];

Jc3[3][1]=links[3].mcm[2] + S43[1][1]*(Jc4[1][1]*Si34[3][1] + Jc4[2][1]*Si34[3][2]) + S43[2][1]*(Jc4[1][2]*Si34[3][1] + Jc4[2][2]*Si34[3][2]) + l2*(Jc4[1][6]*Si34[3][1] + Jc4[2][6]*Si34[3][2]);
Jc3[3][2]=-links[3].mcm[1] - Jc4[1][3]*Si34[3][1] - Jc4[2][3]*Si34[3][2] + l2*S43[1][1]*(Jc4[1][4]*Si34[3][1] + Jc4[2][4]*Si34[3][2]) + l2*S43[2][1]*(Jc4[1][5]*Si34[3][1] + Jc4[2][5]*Si34[3][2]);
Jc3[3][3]=S43[1][3]*(Jc4[1][1]*Si34[3][1] + Jc4[2][1]*Si34[3][2]) + S43[2][3]*(Jc4[1][2]*Si34[3][1] + Jc4[2][2]*Si34[3][2]);
Jc3[3][4]=S43[1][1]*(Jc4[1][4]*Si34[3][1] + Jc4[2][4]*Si34[3][2]) + S43[2][1]*(Jc4[1][5]*Si34[3][1] + Jc4[2][5]*Si34[3][2]);
Jc3[3][5]=-(Jc4[1][6]*Si34[3][1]) - Jc4[2][6]*Si34[3][2];
Jc3[3][6]=links[3].m + S43[1][3]*(Jc4[1][4]*Si34[3][1] + Jc4[2][4]*Si34[3][2]) + S43[2][3]*(Jc4[1][5]*Si34[3][1] + Jc4[2][5]*Si34[3][2]);

Jc3[4][1]=links[3].inertia[1][1] + S43[1][1]*(l2*Jc4[3][1] + Jc4[4][1]*Si34[1][1] + Jc4[5][1]*Si34[1][2]) + S43[2][1]*(l2*Jc4[3][2] + Jc4[4][2]*Si34[1][1] + Jc4[5][2]*Si34[1][2]) + l2*(l2*Jc4[3][6] + Jc4[4][6]*Si34[1][1] + Jc4[5][6]*Si34[1][2]);
Jc3[4][2]=-(l2*Jc4[3][3]) + links[3].inertia[1][2] - Jc4[4][3]*Si34[1][1] - Jc4[5][3]*Si34[1][2] + l2*S43[1][1]*(l2*Jc4[3][4] + Jc4[4][4]*Si34[1][1] + Jc4[5][4]*Si34[1][2]) + l2*S43[2][1]*(l2*Jc4[3][5] + Jc4[4][5]*Si34[1][1] + Jc4[5][5]*Si34[1][2]);
Jc3[4][3]=links[3].inertia[1][3] + S43[1][3]*(l2*Jc4[3][1] + Jc4[4][1]*Si34[1][1] + Jc4[5][1]*Si34[1][2]) + S43[2][3]*(l2*Jc4[3][2] + Jc4[4][2]*Si34[1][1] + Jc4[5][2]*Si34[1][2]);
Jc3[4][4]=S43[1][1]*(l2*Jc4[3][4] + Jc4[4][4]*Si34[1][1] + Jc4[5][4]*Si34[1][2]) + S43[2][1]*(l2*Jc4[3][5] + Jc4[4][5]*Si34[1][1] + Jc4[5][5]*Si34[1][2]);
Jc3[4][5]=-links[3].mcm[3] - l2*Jc4[3][6] - Jc4[4][6]*Si34[1][1] - Jc4[5][6]*Si34[1][2];
Jc3[4][6]=links[3].mcm[2] + S43[1][3]*(l2*Jc4[3][4] + Jc4[4][4]*Si34[1][1] + Jc4[5][4]*Si34[1][2]) + S43[2][3]*(l2*Jc4[3][5] + Jc4[4][5]*Si34[1][1] + Jc4[5][5]*Si34[1][2]);

Jc3[5][1]=links[3].inertia[1][2] + S43[1][1]*(-Jc4[6][1] + l2*Jc4[1][1]*Si34[1][1] + l2*Jc4[2][1]*Si34[1][2]) + S43[2][1]*(-Jc4[6][2] + l2*Jc4[1][2]*Si34[1][1] + l2*Jc4[2][2]*Si34[1][2]) + l2*(-Jc4[6][6] + l2*Jc4[1][6]*Si34[1][1] + l2*Jc4[2][6]*Si34[1][2]);
Jc3[5][2]=Jc4[6][3] + links[3].inertia[2][2] - l2*Jc4[1][3]*Si34[1][1] - l2*Jc4[2][3]*Si34[1][2] + l2*S43[1][1]*(-Jc4[6][4] + l2*Jc4[1][4]*Si34[1][1] + l2*Jc4[2][4]*Si34[1][2]) + l2*S43[2][1]*(-Jc4[6][5] + l2*Jc4[1][5]*Si34[1][1] + l2*Jc4[2][5]*Si34[1][2]);
Jc3[5][3]=links[3].inertia[2][3] + S43[1][3]*(-Jc4[6][1] + l2*Jc4[1][1]*Si34[1][1] + l2*Jc4[2][1]*Si34[1][2]) + S43[2][3]*(-Jc4[6][2] + l2*Jc4[1][2]*Si34[1][1] + l2*Jc4[2][2]*Si34[1][2]);
Jc3[5][4]=links[3].mcm[3] + S43[1][1]*(-Jc4[6][4] + l2*Jc4[1][4]*Si34[1][1] + l2*Jc4[2][4]*Si34[1][2]) + S43[2][1]*(-Jc4[6][5] + l2*Jc4[1][5]*Si34[1][1] + l2*Jc4[2][5]*Si34[1][2]);
Jc3[5][5]=Jc4[6][6] - l2*Jc4[1][6]*Si34[1][1] - l2*Jc4[2][6]*Si34[1][2];
Jc3[5][6]=-links[3].mcm[1] + S43[1][3]*(-Jc4[6][4] + l2*Jc4[1][4]*Si34[1][1] + l2*Jc4[2][4]*Si34[1][2]) + S43[2][3]*(-Jc4[6][5] + l2*Jc4[1][5]*Si34[1][1] + l2*Jc4[2][5]*Si34[1][2]);

Jc3[6][1]=links[3].inertia[1][3] + S43[1][1]*(Jc4[4][1]*Si34[3][1] + Jc4[5][1]*Si34[3][2]) + S43[2][1]*(Jc4[4][2]*Si34[3][1] + Jc4[5][2]*Si34[3][2]) + l2*(Jc4[4][6]*Si34[3][1] + Jc4[5][6]*Si34[3][2]);
Jc3[6][2]=links[3].inertia[2][3] - Jc4[4][3]*Si34[3][1] - Jc4[5][3]*Si34[3][2] + l2*S43[1][1]*(Jc4[4][4]*Si34[3][1] + Jc4[5][4]*Si34[3][2]) + l2*S43[2][1]*(Jc4[4][5]*Si34[3][1] + Jc4[5][5]*Si34[3][2]);
Jc3[6][3]=links[3].inertia[3][3] + S43[1][3]*(Jc4[4][1]*Si34[3][1] + Jc4[5][1]*Si34[3][2]) + S43[2][3]*(Jc4[4][2]*Si34[3][1] + Jc4[5][2]*Si34[3][2]);
Jc3[6][4]=-links[3].mcm[2] + S43[1][1]*(Jc4[4][4]*Si34[3][1] + Jc4[5][4]*Si34[3][2]) + S43[2][1]*(Jc4[4][5]*Si34[3][1] + Jc4[5][5]*Si34[3][2]);
Jc3[6][5]=links[3].mcm[1] - Jc4[4][6]*Si34[3][1] - Jc4[5][6]*Si34[3][2];
Jc3[6][6]=S43[1][3]*(Jc4[4][4]*Si34[3][1] + Jc4[5][4]*Si34[3][2]) + S43[2][3]*(Jc4[4][5]*Si34[3][1] + Jc4[5][5]*Si34[3][2]);



}


void
masterfunc22(void)
      {
/* composite inertia matrices */
Jc2[1][1]=Jc3[3][3] - l1*Jc3[3][4]*S32[1][3] - l1*Jc3[3][5]*S32[2][3];
Jc2[1][2]=links[2].mcm[3] + Jc3[3][1]*S32[1][2] + Jc3[3][2]*S32[2][2];
Jc2[1][3]=-links[2].mcm[2] + l1*Jc3[3][6] + Jc3[3][1]*S32[1][3] + Jc3[3][2]*S32[2][3];
Jc2[1][4]=links[2].m + Jc3[3][6];
Jc2[1][5]=Jc3[3][4]*S32[1][2] + Jc3[3][5]*S32[2][2];
Jc2[1][6]=Jc3[3][4]*S32[1][3] + Jc3[3][5]*S32[2][3];

Jc2[2][1]=-links[2].mcm[3] + Jc3[1][3]*Si23[2][1] + Jc3[2][3]*Si23[2][2] - l1*S32[1][3]*(Jc3[1][4]*Si23[2][1] + Jc3[2][4]*Si23[2][2]) - l1*S32[2][3]*(Jc3[1][5]*Si23[2][1] + Jc3[2][5]*Si23[2][2]);
Jc2[2][2]=S32[1][2]*(Jc3[1][1]*Si23[2][1] + Jc3[2][1]*Si23[2][2]) + S32[2][2]*(Jc3[1][2]*Si23[2][1] + Jc3[2][2]*Si23[2][2]);
Jc2[2][3]=links[2].mcm[1] + S32[1][3]*(Jc3[1][1]*Si23[2][1] + Jc3[2][1]*Si23[2][2]) + S32[2][3]*(Jc3[1][2]*Si23[2][1] + Jc3[2][2]*Si23[2][2]) + l1*(Jc3[1][6]*Si23[2][1] + Jc3[2][6]*Si23[2][2]);
Jc2[2][4]=Jc3[1][6]*Si23[2][1] + Jc3[2][6]*Si23[2][2];
Jc2[2][5]=links[2].m + S32[1][2]*(Jc3[1][4]*Si23[2][1] + Jc3[2][4]*Si23[2][2]) + S32[2][2]*(Jc3[1][5]*Si23[2][1] + Jc3[2][5]*Si23[2][2]);
Jc2[2][6]=S32[1][3]*(Jc3[1][4]*Si23[2][1] + Jc3[2][4]*Si23[2][2]) + S32[2][3]*(Jc3[1][5]*Si23[2][1] + Jc3[2][5]*Si23[2][2]);

Jc2[3][1]=links[2].mcm[2] + Jc3[1][3]*Si23[3][1] + Jc3[2][3]*Si23[3][2] - l1*S32[1][3]*(Jc3[1][4]*Si23[3][1] + Jc3[2][4]*Si23[3][2]) - l1*S32[2][3]*(Jc3[1][5]*Si23[3][1] + Jc3[2][5]*Si23[3][2]);
Jc2[3][2]=-links[2].mcm[1] + S32[1][2]*(Jc3[1][1]*Si23[3][1] + Jc3[2][1]*Si23[3][2]) + S32[2][2]*(Jc3[1][2]*Si23[3][1] + Jc3[2][2]*Si23[3][2]);
Jc2[3][3]=S32[1][3]*(Jc3[1][1]*Si23[3][1] + Jc3[2][1]*Si23[3][2]) + S32[2][3]*(Jc3[1][2]*Si23[3][1] + Jc3[2][2]*Si23[3][2]) + l1*(Jc3[1][6]*Si23[3][1] + Jc3[2][6]*Si23[3][2]);
Jc2[3][4]=Jc3[1][6]*Si23[3][1] + Jc3[2][6]*Si23[3][2];
Jc2[3][5]=S32[1][2]*(Jc3[1][4]*Si23[3][1] + Jc3[2][4]*Si23[3][2]) + S32[2][2]*(Jc3[1][5]*Si23[3][1] + Jc3[2][5]*Si23[3][2]);
Jc2[3][6]=links[2].m + S32[1][3]*(Jc3[1][4]*Si23[3][1] + Jc3[2][4]*Si23[3][2]) + S32[2][3]*(Jc3[1][5]*Si23[3][1] + Jc3[2][5]*Si23[3][2]);

Jc2[4][1]=Jc3[6][3] + links[2].inertia[1][1] - l1*Jc3[1][3]*Si23[3][1] - l1*Jc3[2][3]*Si23[3][2] - l1*S32[1][3]*(Jc3[6][4] - l1*Jc3[1][4]*Si23[3][1] - l1*Jc3[2][4]*Si23[3][2]) - l1*S32[2][3]*(Jc3[6][5] - l1*Jc3[1][5]*Si23[3][1] - l1*Jc3[2][5]*Si23[3][2]);
Jc2[4][2]=links[2].inertia[1][2] + S32[1][2]*(Jc3[6][1] - l1*Jc3[1][1]*Si23[3][1] - l1*Jc3[2][1]*Si23[3][2]) + S32[2][2]*(Jc3[6][2] - l1*Jc3[1][2]*Si23[3][1] - l1*Jc3[2][2]*Si23[3][2]);
Jc2[4][3]=links[2].inertia[1][3] + S32[1][3]*(Jc3[6][1] - l1*Jc3[1][1]*Si23[3][1] - l1*Jc3[2][1]*Si23[3][2]) + S32[2][3]*(Jc3[6][2] - l1*Jc3[1][2]*Si23[3][1] - l1*Jc3[2][2]*Si23[3][2]) + l1*(Jc3[6][6] - l1*Jc3[1][6]*Si23[3][1] - l1*Jc3[2][6]*Si23[3][2]);
Jc2[4][4]=Jc3[6][6] - l1*Jc3[1][6]*Si23[3][1] - l1*Jc3[2][6]*Si23[3][2];
Jc2[4][5]=-links[2].mcm[3] + S32[1][2]*(Jc3[6][4] - l1*Jc3[1][4]*Si23[3][1] - l1*Jc3[2][4]*Si23[3][2]) + S32[2][2]*(Jc3[6][5] - l1*Jc3[1][5]*Si23[3][1] - l1*Jc3[2][5]*Si23[3][2]);
Jc2[4][6]=links[2].mcm[2] + S32[1][3]*(Jc3[6][4] - l1*Jc3[1][4]*Si23[3][1] - l1*Jc3[2][4]*Si23[3][2]) + S32[2][3]*(Jc3[6][5] - l1*Jc3[1][5]*Si23[3][1] - l1*Jc3[2][5]*Si23[3][2]);

Jc2[5][1]=links[2].inertia[1][2] + Jc3[4][3]*Si23[2][1] + Jc3[5][3]*Si23[2][2] - l1*S32[1][3]*(Jc3[4][4]*Si23[2][1] + Jc3[5][4]*Si23[2][2]) - l1*S32[2][3]*(Jc3[4][5]*Si23[2][1] + Jc3[5][5]*Si23[2][2]);
Jc2[5][2]=links[2].inertia[2][2] + S32[1][2]*(Jc3[4][1]*Si23[2][1] + Jc3[5][1]*Si23[2][2]) + S32[2][2]*(Jc3[4][2]*Si23[2][1] + Jc3[5][2]*Si23[2][2]);
Jc2[5][3]=links[2].inertia[2][3] + S32[1][3]*(Jc3[4][1]*Si23[2][1] + Jc3[5][1]*Si23[2][2]) + S32[2][3]*(Jc3[4][2]*Si23[2][1] + Jc3[5][2]*Si23[2][2]) + l1*(Jc3[4][6]*Si23[2][1] + Jc3[5][6]*Si23[2][2]);
Jc2[5][4]=links[2].mcm[3] + Jc3[4][6]*Si23[2][1] + Jc3[5][6]*Si23[2][2];
Jc2[5][5]=S32[1][2]*(Jc3[4][4]*Si23[2][1] + Jc3[5][4]*Si23[2][2]) + S32[2][2]*(Jc3[4][5]*Si23[2][1] + Jc3[5][5]*Si23[2][2]);
Jc2[5][6]=-links[2].mcm[1] + S32[1][3]*(Jc3[4][4]*Si23[2][1] + Jc3[5][4]*Si23[2][2]) + S32[2][3]*(Jc3[4][5]*Si23[2][1] + Jc3[5][5]*Si23[2][2]);

Jc2[6][1]=l1*Jc3[3][3] + links[2].inertia[1][3] + Jc3[4][3]*Si23[3][1] + Jc3[5][3]*Si23[3][2] - l1*S32[1][3]*(l1*Jc3[3][4] + Jc3[4][4]*Si23[3][1] + Jc3[5][4]*Si23[3][2]) - l1*S32[2][3]*(l1*Jc3[3][5] + Jc3[4][5]*Si23[3][1] + Jc3[5][5]*Si23[3][2]);
Jc2[6][2]=links[2].inertia[2][3] + S32[1][2]*(l1*Jc3[3][1] + Jc3[4][1]*Si23[3][1] + Jc3[5][1]*Si23[3][2]) + S32[2][2]*(l1*Jc3[3][2] + Jc3[4][2]*Si23[3][1] + Jc3[5][2]*Si23[3][2]);
Jc2[6][3]=links[2].inertia[3][3] + S32[1][3]*(l1*Jc3[3][1] + Jc3[4][1]*Si23[3][1] + Jc3[5][1]*Si23[3][2]) + S32[2][3]*(l1*Jc3[3][2] + Jc3[4][2]*Si23[3][1] + Jc3[5][2]*Si23[3][2]) + l1*(l1*Jc3[3][6] + Jc3[4][6]*Si23[3][1] + Jc3[5][6]*Si23[3][2]);
Jc2[6][4]=-links[2].mcm[2] + l1*Jc3[3][6] + Jc3[4][6]*Si23[3][1] + Jc3[5][6]*Si23[3][2];
Jc2[6][5]=links[2].mcm[1] + S32[1][2]*(l1*Jc3[3][4] + Jc3[4][4]*Si23[3][1] + Jc3[5][4]*Si23[3][2]) + S32[2][2]*(l1*Jc3[3][5] + Jc3[4][5]*Si23[3][1] + Jc3[5][5]*Si23[3][2]);
Jc2[6][6]=S32[1][3]*(l1*Jc3[3][4] + Jc3[4][4]*Si23[3][1] + Jc3[5][4]*Si23[3][2]) + S32[2][3]*(l1*Jc3[3][5] + Jc3[4][5]*Si23[3][1] + Jc3[5][5]*Si23[3][2]);



}


void
masterfunc23(void)
      {
/* composite inertia matrices */
Jc1[1][1]=S21[1][1]*(Jc2[1][1]*Si12[1][1] + Jc2[2][1]*Si12[1][2]) + S21[2][1]*(Jc2[1][2]*Si12[1][1] + Jc2[2][2]*Si12[1][2]);
Jc1[1][2]=links[1].mcm[3] + Jc2[1][3]*Si12[1][1] + Jc2[2][3]*Si12[1][2];
Jc1[1][3]=-links[1].mcm[2] + S21[1][3]*(Jc2[1][1]*Si12[1][1] + Jc2[2][1]*Si12[1][2]) + S21[2][3]*(Jc2[1][2]*Si12[1][1] + Jc2[2][2]*Si12[1][2]);
Jc1[1][4]=links[1].m + S21[1][1]*(Jc2[1][4]*Si12[1][1] + Jc2[2][4]*Si12[1][2]) + S21[2][1]*(Jc2[1][5]*Si12[1][1] + Jc2[2][5]*Si12[1][2]);
Jc1[1][5]=Jc2[1][6]*Si12[1][1] + Jc2[2][6]*Si12[1][2];
Jc1[1][6]=S21[1][3]*(Jc2[1][4]*Si12[1][1] + Jc2[2][4]*Si12[1][2]) + S21[2][3]*(Jc2[1][5]*Si12[1][1] + Jc2[2][5]*Si12[1][2]);

Jc1[2][1]=-links[1].mcm[3] + Jc2[3][1]*S21[1][1] + Jc2[3][2]*S21[2][1];
Jc1[2][2]=Jc2[3][3];
Jc1[2][3]=links[1].mcm[1] + Jc2[3][1]*S21[1][3] + Jc2[3][2]*S21[2][3];
Jc1[2][4]=Jc2[3][4]*S21[1][1] + Jc2[3][5]*S21[2][1];
Jc1[2][5]=links[1].m + Jc2[3][6];
Jc1[2][6]=Jc2[3][4]*S21[1][3] + Jc2[3][5]*S21[2][3];

Jc1[3][1]=links[1].mcm[2] + S21[1][1]*(Jc2[1][1]*Si12[3][1] + Jc2[2][1]*Si12[3][2]) + S21[2][1]*(Jc2[1][2]*Si12[3][1] + Jc2[2][2]*Si12[3][2]);
Jc1[3][2]=-links[1].mcm[1] + Jc2[1][3]*Si12[3][1] + Jc2[2][3]*Si12[3][2];
Jc1[3][3]=S21[1][3]*(Jc2[1][1]*Si12[3][1] + Jc2[2][1]*Si12[3][2]) + S21[2][3]*(Jc2[1][2]*Si12[3][1] + Jc2[2][2]*Si12[3][2]);
Jc1[3][4]=S21[1][1]*(Jc2[1][4]*Si12[3][1] + Jc2[2][4]*Si12[3][2]) + S21[2][1]*(Jc2[1][5]*Si12[3][1] + Jc2[2][5]*Si12[3][2]);
Jc1[3][5]=Jc2[1][6]*Si12[3][1] + Jc2[2][6]*Si12[3][2];
Jc1[3][6]=links[1].m + S21[1][3]*(Jc2[1][4]*Si12[3][1] + Jc2[2][4]*Si12[3][2]) + S21[2][3]*(Jc2[1][5]*Si12[3][1] + Jc2[2][5]*Si12[3][2]);

Jc1[4][1]=links[1].inertia[1][1] + S21[1][1]*(Jc2[4][1]*Si12[1][1] + Jc2[5][1]*Si12[1][2]) + S21[2][1]*(Jc2[4][2]*Si12[1][1] + Jc2[5][2]*Si12[1][2]);
Jc1[4][2]=links[1].inertia[1][2] + Jc2[4][3]*Si12[1][1] + Jc2[5][3]*Si12[1][2];
Jc1[4][3]=links[1].inertia[1][3] + S21[1][3]*(Jc2[4][1]*Si12[1][1] + Jc2[5][1]*Si12[1][2]) + S21[2][3]*(Jc2[4][2]*Si12[1][1] + Jc2[5][2]*Si12[1][2]);
Jc1[4][4]=S21[1][1]*(Jc2[4][4]*Si12[1][1] + Jc2[5][4]*Si12[1][2]) + S21[2][1]*(Jc2[4][5]*Si12[1][1] + Jc2[5][5]*Si12[1][2]);
Jc1[4][5]=-links[1].mcm[3] + Jc2[4][6]*Si12[1][1] + Jc2[5][6]*Si12[1][2];
Jc1[4][6]=links[1].mcm[2] + S21[1][3]*(Jc2[4][4]*Si12[1][1] + Jc2[5][4]*Si12[1][2]) + S21[2][3]*(Jc2[4][5]*Si12[1][1] + Jc2[5][5]*Si12[1][2]);

Jc1[5][1]=links[1].inertia[1][2] + Jc2[6][1]*S21[1][1] + Jc2[6][2]*S21[2][1];
Jc1[5][2]=Jc2[6][3] + links[1].inertia[2][2];
Jc1[5][3]=links[1].inertia[2][3] + Jc2[6][1]*S21[1][3] + Jc2[6][2]*S21[2][3];
Jc1[5][4]=links[1].mcm[3] + Jc2[6][4]*S21[1][1] + Jc2[6][5]*S21[2][1];
Jc1[5][5]=Jc2[6][6];
Jc1[5][6]=-links[1].mcm[1] + Jc2[6][4]*S21[1][3] + Jc2[6][5]*S21[2][3];

Jc1[6][1]=links[1].inertia[1][3] + S21[1][1]*(Jc2[4][1]*Si12[3][1] + Jc2[5][1]*Si12[3][2]) + S21[2][1]*(Jc2[4][2]*Si12[3][1] + Jc2[5][2]*Si12[3][2]);
Jc1[6][2]=links[1].inertia[2][3] + Jc2[4][3]*Si12[3][1] + Jc2[5][3]*Si12[3][2];
Jc1[6][3]=links[1].inertia[3][3] + S21[1][3]*(Jc2[4][1]*Si12[3][1] + Jc2[5][1]*Si12[3][2]) + S21[2][3]*(Jc2[4][2]*Si12[3][1] + Jc2[5][2]*Si12[3][2]);
Jc1[6][4]=-links[1].mcm[2] + S21[1][1]*(Jc2[4][4]*Si12[3][1] + Jc2[5][4]*Si12[3][2]) + S21[2][1]*(Jc2[4][5]*Si12[3][1] + Jc2[5][5]*Si12[3][2]);
Jc1[6][5]=links[1].mcm[1] + Jc2[4][6]*Si12[3][1] + Jc2[5][6]*Si12[3][2];
Jc1[6][6]=S21[1][3]*(Jc2[4][4]*Si12[3][1] + Jc2[5][4]*Si12[3][2]) + S21[2][3]*(Jc2[4][5]*Si12[3][1] + Jc2[5][5]*Si12[3][2]);



}


void
masterfunc24(void)
      {
/* composite inertia matrices */
Jcc0[1][1]=S10[1][1]*(0.7071067811865475*Jc1[3][1] + Jc1[1][1]*Si01[1][1] + Jc1[2][1]*Si01[1][2]) + S10[2][1]*(0.7071067811865475*Jc1[3][2] + Jc1[1][2]*Si01[1][1] + Jc1[2][2]*Si01[1][2]) + 0.7071067811865475*(0.7071067811865475*Jc1[3][3] + Jc1[1][3]*Si01[1][1] + Jc1[2][3]*Si01[1][2]) - (l0*S10[1][2]*(0.7071067811865475*Jc1[3][4] + Jc1[1][4]*Si01[1][1] + Jc1[2][4]*Si01[1][2]))/Sqrt(2) - (l0*S10[2][2]*(0.7071067811865475*Jc1[3][5] + Jc1[1][5]*Si01[1][1] + Jc1[2][5]*Si01[1][2]))/Sqrt(2);
Jcc0[1][2]=links[0].mcm[3] + S10[1][2]*(0.7071067811865475*Jc1[3][1] + Jc1[1][1]*Si01[1][1] + Jc1[2][1]*Si01[1][2]) + S10[2][2]*(0.7071067811865475*Jc1[3][2] + Jc1[1][2]*Si01[1][1] + Jc1[2][2]*Si01[1][2]) + ((l0*S10[1][1])/Sqrt(2) - (l0*S10[1][3])/Sqrt(2))*(0.7071067811865475*Jc1[3][4] + Jc1[1][4]*Si01[1][1] + Jc1[2][4]*Si01[1][2]) + ((l0*S10[2][1])/Sqrt(2) - (l0*S10[2][3])/Sqrt(2))*(0.7071067811865475*Jc1[3][5] + Jc1[1][5]*Si01[1][1] + Jc1[2][5]*Si01[1][2]);
Jcc0[1][3]=-links[0].mcm[2] + S10[1][3]*(0.7071067811865475*Jc1[3][1] + Jc1[1][1]*Si01[1][1] + Jc1[2][1]*Si01[1][2]) + S10[2][3]*(0.7071067811865475*Jc1[3][2] + Jc1[1][2]*Si01[1][1] + Jc1[2][2]*Si01[1][2]) + 0.7071067811865475*(0.7071067811865475*Jc1[3][3] + Jc1[1][3]*Si01[1][1] + Jc1[2][3]*Si01[1][2]) + (l0*S10[1][2]*(0.7071067811865475*Jc1[3][4] + Jc1[1][4]*Si01[1][1] + Jc1[2][4]*Si01[1][2]))/Sqrt(2) + (l0*S10[2][2]*(0.7071067811865475*Jc1[3][5] + Jc1[1][5]*Si01[1][1] + Jc1[2][5]*Si01[1][2]))/Sqrt(2);
Jcc0[1][4]=links[0].m + S10[1][1]*(0.7071067811865475*Jc1[3][4] + Jc1[1][4]*Si01[1][1] + Jc1[2][4]*Si01[1][2]) + S10[2][1]*(0.7071067811865475*Jc1[3][5] + Jc1[1][5]*Si01[1][1] + Jc1[2][5]*Si01[1][2]) + 0.7071067811865475*(0.7071067811865475*Jc1[3][6] + Jc1[1][6]*Si01[1][1] + Jc1[2][6]*Si01[1][2]);
Jcc0[1][5]=S10[1][2]*(0.7071067811865475*Jc1[3][4] + Jc1[1][4]*Si01[1][1] + Jc1[2][4]*Si01[1][2]) + S10[2][2]*(0.7071067811865475*Jc1[3][5] + Jc1[1][5]*Si01[1][1] + Jc1[2][5]*Si01[1][2]);
Jcc0[1][6]=S10[1][3]*(0.7071067811865475*Jc1[3][4] + Jc1[1][4]*Si01[1][1] + Jc1[2][4]*Si01[1][2]) + S10[2][3]*(0.7071067811865475*Jc1[3][5] + Jc1[1][5]*Si01[1][1] + Jc1[2][5]*Si01[1][2]) + 0.7071067811865475*(0.7071067811865475*Jc1[3][6] + Jc1[1][6]*Si01[1][1] + Jc1[2][6]*Si01[1][2]);

Jcc0[2][1]=-links[0].mcm[3] + S10[1][1]*(Jc1[1][1]*Si01[2][1] + Jc1[2][1]*Si01[2][2]) + S10[2][1]*(Jc1[1][2]*Si01[2][1] + Jc1[2][2]*Si01[2][2]) + 0.7071067811865475*(Jc1[1][3]*Si01[2][1] + Jc1[2][3]*Si01[2][2]) - (l0*S10[1][2]*(Jc1[1][4]*Si01[2][1] + Jc1[2][4]*Si01[2][2]))/Sqrt(2) - (l0*S10[2][2]*(Jc1[1][5]*Si01[2][1] + Jc1[2][5]*Si01[2][2]))/Sqrt(2);
Jcc0[2][2]=S10[1][2]*(Jc1[1][1]*Si01[2][1] + Jc1[2][1]*Si01[2][2]) + S10[2][2]*(Jc1[1][2]*Si01[2][1] + Jc1[2][2]*Si01[2][2]) + ((l0*S10[1][1])/Sqrt(2) - (l0*S10[1][3])/Sqrt(2))*(Jc1[1][4]*Si01[2][1] + Jc1[2][4]*Si01[2][2]) + ((l0*S10[2][1])/Sqrt(2) - (l0*S10[2][3])/Sqrt(2))*(Jc1[1][5]*Si01[2][1] + Jc1[2][5]*Si01[2][2]);
Jcc0[2][3]=links[0].mcm[1] + S10[1][3]*(Jc1[1][1]*Si01[2][1] + Jc1[2][1]*Si01[2][2]) + S10[2][3]*(Jc1[1][2]*Si01[2][1] + Jc1[2][2]*Si01[2][2]) + 0.7071067811865475*(Jc1[1][3]*Si01[2][1] + Jc1[2][3]*Si01[2][2]) + (l0*S10[1][2]*(Jc1[1][4]*Si01[2][1] + Jc1[2][4]*Si01[2][2]))/Sqrt(2) + (l0*S10[2][2]*(Jc1[1][5]*Si01[2][1] + Jc1[2][5]*Si01[2][2]))/Sqrt(2);
Jcc0[2][4]=S10[1][1]*(Jc1[1][4]*Si01[2][1] + Jc1[2][4]*Si01[2][2]) + S10[2][1]*(Jc1[1][5]*Si01[2][1] + Jc1[2][5]*Si01[2][2]) + 0.7071067811865475*(Jc1[1][6]*Si01[2][1] + Jc1[2][6]*Si01[2][2]);
Jcc0[2][5]=links[0].m + S10[1][2]*(Jc1[1][4]*Si01[2][1] + Jc1[2][4]*Si01[2][2]) + S10[2][2]*(Jc1[1][5]*Si01[2][1] + Jc1[2][5]*Si01[2][2]);
Jcc0[2][6]=S10[1][3]*(Jc1[1][4]*Si01[2][1] + Jc1[2][4]*Si01[2][2]) + S10[2][3]*(Jc1[1][5]*Si01[2][1] + Jc1[2][5]*Si01[2][2]) + 0.7071067811865475*(Jc1[1][6]*Si01[2][1] + Jc1[2][6]*Si01[2][2]);

Jcc0[3][1]=links[0].mcm[2] + S10[1][1]*(0.7071067811865475*Jc1[3][1] + Jc1[1][1]*Si01[3][1] + Jc1[2][1]*Si01[3][2]) + S10[2][1]*(0.7071067811865475*Jc1[3][2] + Jc1[1][2]*Si01[3][1] + Jc1[2][2]*Si01[3][2]) + 0.7071067811865475*(0.7071067811865475*Jc1[3][3] + Jc1[1][3]*Si01[3][1] + Jc1[2][3]*Si01[3][2]) - (l0*S10[1][2]*(0.7071067811865475*Jc1[3][4] + Jc1[1][4]*Si01[3][1] + Jc1[2][4]*Si01[3][2]))/Sqrt(2) - (l0*S10[2][2]*(0.7071067811865475*Jc1[3][5] + Jc1[1][5]*Si01[3][1] + Jc1[2][5]*Si01[3][2]))/Sqrt(2);
Jcc0[3][2]=-links[0].mcm[1] + S10[1][2]*(0.7071067811865475*Jc1[3][1] + Jc1[1][1]*Si01[3][1] + Jc1[2][1]*Si01[3][2]) + S10[2][2]*(0.7071067811865475*Jc1[3][2] + Jc1[1][2]*Si01[3][1] + Jc1[2][2]*Si01[3][2]) + ((l0*S10[1][1])/Sqrt(2) - (l0*S10[1][3])/Sqrt(2))*(0.7071067811865475*Jc1[3][4] + Jc1[1][4]*Si01[3][1] + Jc1[2][4]*Si01[3][2]) + ((l0*S10[2][1])/Sqrt(2) - (l0*S10[2][3])/Sqrt(2))*(0.7071067811865475*Jc1[3][5] + Jc1[1][5]*Si01[3][1] + Jc1[2][5]*Si01[3][2]);
Jcc0[3][3]=S10[1][3]*(0.7071067811865475*Jc1[3][1] + Jc1[1][1]*Si01[3][1] + Jc1[2][1]*Si01[3][2]) + S10[2][3]*(0.7071067811865475*Jc1[3][2] + Jc1[1][2]*Si01[3][1] + Jc1[2][2]*Si01[3][2]) + 0.7071067811865475*(0.7071067811865475*Jc1[3][3] + Jc1[1][3]*Si01[3][1] + Jc1[2][3]*Si01[3][2]) + (l0*S10[1][2]*(0.7071067811865475*Jc1[3][4] + Jc1[1][4]*Si01[3][1] + Jc1[2][4]*Si01[3][2]))/Sqrt(2) + (l0*S10[2][2]*(0.7071067811865475*Jc1[3][5] + Jc1[1][5]*Si01[3][1] + Jc1[2][5]*Si01[3][2]))/Sqrt(2);
Jcc0[3][4]=S10[1][1]*(0.7071067811865475*Jc1[3][4] + Jc1[1][4]*Si01[3][1] + Jc1[2][4]*Si01[3][2]) + S10[2][1]*(0.7071067811865475*Jc1[3][5] + Jc1[1][5]*Si01[3][1] + Jc1[2][5]*Si01[3][2]) + 0.7071067811865475*(0.7071067811865475*Jc1[3][6] + Jc1[1][6]*Si01[3][1] + Jc1[2][6]*Si01[3][2]);
Jcc0[3][5]=S10[1][2]*(0.7071067811865475*Jc1[3][4] + Jc1[1][4]*Si01[3][1] + Jc1[2][4]*Si01[3][2]) + S10[2][2]*(0.7071067811865475*Jc1[3][5] + Jc1[1][5]*Si01[3][1] + Jc1[2][5]*Si01[3][2]);
Jcc0[3][6]=links[0].m + S10[1][3]*(0.7071067811865475*Jc1[3][4] + Jc1[1][4]*Si01[3][1] + Jc1[2][4]*Si01[3][2]) + S10[2][3]*(0.7071067811865475*Jc1[3][5] + Jc1[1][5]*Si01[3][1] + Jc1[2][5]*Si01[3][2]) + 0.7071067811865475*(0.7071067811865475*Jc1[3][6] + Jc1[1][6]*Si01[3][1] + Jc1[2][6]*Si01[3][2]);

Jcc0[4][1]=links[0].inertia[1][1] + S10[1][1]*(0.7071067811865475*Jc1[6][1] + Jc1[4][1]*Si01[1][1] + Jc1[5][1]*Si01[1][2] - (l0*Jc1[1][1]*Si01[2][1])/Sqrt(2) - (l0*Jc1[2][1]*Si01[2][2])/Sqrt(2)) + S10[2][1]*(0.7071067811865475*Jc1[6][2] + Jc1[4][2]*Si01[1][1] + Jc1[5][2]*Si01[1][2] - (l0*Jc1[1][2]*Si01[2][1])/Sqrt(2) - (l0*Jc1[2][2]*Si01[2][2])/Sqrt(2)) + 0.7071067811865475*(0.7071067811865475*Jc1[6][3] + Jc1[4][3]*Si01[1][1] + Jc1[5][3]*Si01[1][2] - (l0*Jc1[1][3]*Si01[2][1])/Sqrt(2) - (l0*Jc1[2][3]*Si01[2][2])/Sqrt(2)) - (l0*S10[1][2]*(0.7071067811865475*Jc1[6][4] + Jc1[4][4]*Si01[1][1] + Jc1[5][4]*Si01[1][2] - (l0*Jc1[1][4]*Si01[2][1])/Sqrt(2) - (l0*Jc1[2][4]*Si01[2][2])/Sqrt(2)))/Sqrt(2) - (l0*S10[2][2]*(0.7071067811865475*Jc1[6][5] + Jc1[4][5]*Si01[1][1] + Jc1[5][5]*Si01[1][2] - (l0*Jc1[1][5]*Si01[2][1])/Sqrt(2) - (l0*Jc1[2][5]*Si01[2][2])/Sqrt(2)))/Sqrt(2);
Jcc0[4][2]=links[0].inertia[1][2] + S10[1][2]*(0.7071067811865475*Jc1[6][1] + Jc1[4][1]*Si01[1][1] + Jc1[5][1]*Si01[1][2] - (l0*Jc1[1][1]*Si01[2][1])/Sqrt(2) - (l0*Jc1[2][1]*Si01[2][2])/Sqrt(2)) + S10[2][2]*(0.7071067811865475*Jc1[6][2] + Jc1[4][2]*Si01[1][1] + Jc1[5][2]*Si01[1][2] - (l0*Jc1[1][2]*Si01[2][1])/Sqrt(2) - (l0*Jc1[2][2]*Si01[2][2])/Sqrt(2)) + ((l0*S10[1][1])/Sqrt(2) - (l0*S10[1][3])/Sqrt(2))*(0.7071067811865475*Jc1[6][4] + Jc1[4][4]*Si01[1][1] + Jc1[5][4]*Si01[1][2] - (l0*Jc1[1][4]*Si01[2][1])/Sqrt(2) - (l0*Jc1[2][4]*Si01[2][2])/Sqrt(2)) + ((l0*S10[2][1])/Sqrt(2) - (l0*S10[2][3])/Sqrt(2))*(0.7071067811865475*Jc1[6][5] + Jc1[4][5]*Si01[1][1] + Jc1[5][5]*Si01[1][2] - (l0*Jc1[1][5]*Si01[2][1])/Sqrt(2) - (l0*Jc1[2][5]*Si01[2][2])/Sqrt(2));
Jcc0[4][3]=links[0].inertia[1][3] + S10[1][3]*(0.7071067811865475*Jc1[6][1] + Jc1[4][1]*Si01[1][1] + Jc1[5][1]*Si01[1][2] - (l0*Jc1[1][1]*Si01[2][1])/Sqrt(2) - (l0*Jc1[2][1]*Si01[2][2])/Sqrt(2)) + S10[2][3]*(0.7071067811865475*Jc1[6][2] + Jc1[4][2]*Si01[1][1] + Jc1[5][2]*Si01[1][2] - (l0*Jc1[1][2]*Si01[2][1])/Sqrt(2) - (l0*Jc1[2][2]*Si01[2][2])/Sqrt(2)) + 0.7071067811865475*(0.7071067811865475*Jc1[6][3] + Jc1[4][3]*Si01[1][1] + Jc1[5][3]*Si01[1][2] - (l0*Jc1[1][3]*Si01[2][1])/Sqrt(2) - (l0*Jc1[2][3]*Si01[2][2])/Sqrt(2)) + (l0*S10[1][2]*(0.7071067811865475*Jc1[6][4] + Jc1[4][4]*Si01[1][1] + Jc1[5][4]*Si01[1][2] - (l0*Jc1[1][4]*Si01[2][1])/Sqrt(2) - (l0*Jc1[2][4]*Si01[2][2])/Sqrt(2)))/Sqrt(2) + (l0*S10[2][2]*(0.7071067811865475*Jc1[6][5] + Jc1[4][5]*Si01[1][1] + Jc1[5][5]*Si01[1][2] - (l0*Jc1[1][5]*Si01[2][1])/Sqrt(2) - (l0*Jc1[2][5]*Si01[2][2])/Sqrt(2)))/Sqrt(2);
Jcc0[4][4]=S10[1][1]*(0.7071067811865475*Jc1[6][4] + Jc1[4][4]*Si01[1][1] + Jc1[5][4]*Si01[1][2] - (l0*Jc1[1][4]*Si01[2][1])/Sqrt(2) - (l0*Jc1[2][4]*Si01[2][2])/Sqrt(2)) + S10[2][1]*(0.7071067811865475*Jc1[6][5] + Jc1[4][5]*Si01[1][1] + Jc1[5][5]*Si01[1][2] - (l0*Jc1[1][5]*Si01[2][1])/Sqrt(2) - (l0*Jc1[2][5]*Si01[2][2])/Sqrt(2)) + 0.7071067811865475*(0.7071067811865475*Jc1[6][6] + Jc1[4][6]*Si01[1][1] + Jc1[5][6]*Si01[1][2] - (l0*Jc1[1][6]*Si01[2][1])/Sqrt(2) - (l0*Jc1[2][6]*Si01[2][2])/Sqrt(2));
Jcc0[4][5]=-links[0].mcm[3] + S10[1][2]*(0.7071067811865475*Jc1[6][4] + Jc1[4][4]*Si01[1][1] + Jc1[5][4]*Si01[1][2] - (l0*Jc1[1][4]*Si01[2][1])/Sqrt(2) - (l0*Jc1[2][4]*Si01[2][2])/Sqrt(2)) + S10[2][2]*(0.7071067811865475*Jc1[6][5] + Jc1[4][5]*Si01[1][1] + Jc1[5][5]*Si01[1][2] - (l0*Jc1[1][5]*Si01[2][1])/Sqrt(2) - (l0*Jc1[2][5]*Si01[2][2])/Sqrt(2));
Jcc0[4][6]=links[0].mcm[2] + S10[1][3]*(0.7071067811865475*Jc1[6][4] + Jc1[4][4]*Si01[1][1] + Jc1[5][4]*Si01[1][2] - (l0*Jc1[1][4]*Si01[2][1])/Sqrt(2) - (l0*Jc1[2][4]*Si01[2][2])/Sqrt(2)) + S10[2][3]*(0.7071067811865475*Jc1[6][5] + Jc1[4][5]*Si01[1][1] + Jc1[5][5]*Si01[1][2] - (l0*Jc1[1][5]*Si01[2][1])/Sqrt(2) - (l0*Jc1[2][5]*Si01[2][2])/Sqrt(2)) + 0.7071067811865475*(0.7071067811865475*Jc1[6][6] + Jc1[4][6]*Si01[1][1] + Jc1[5][6]*Si01[1][2] - (l0*Jc1[1][6]*Si01[2][1])/Sqrt(2) - (l0*Jc1[2][6]*Si01[2][2])/Sqrt(2));

Jcc0[5][1]=links[0].inertia[1][2] + S10[1][1]*(Jc1[4][1]*Si01[2][1] + Jc1[5][1]*Si01[2][2] + Jc1[1][1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Jc1[2][1]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))) + S10[2][1]*(Jc1[4][2]*Si01[2][1] + Jc1[5][2]*Si01[2][2] + Jc1[1][2]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Jc1[2][2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))) + 0.7071067811865475*(Jc1[4][3]*Si01[2][1] + Jc1[5][3]*Si01[2][2] + Jc1[1][3]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Jc1[2][3]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))) - (l0*S10[1][2]*(Jc1[4][4]*Si01[2][1] + Jc1[5][4]*Si01[2][2] + Jc1[1][4]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Jc1[2][4]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))))/Sqrt(2) - (l0*S10[2][2]*(Jc1[4][5]*Si01[2][1] + Jc1[5][5]*Si01[2][2] + Jc1[1][5]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Jc1[2][5]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))))/Sqrt(2);
Jcc0[5][2]=links[0].inertia[2][2] + S10[1][2]*(Jc1[4][1]*Si01[2][1] + Jc1[5][1]*Si01[2][2] + Jc1[1][1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Jc1[2][1]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))) + S10[2][2]*(Jc1[4][2]*Si01[2][1] + Jc1[5][2]*Si01[2][2] + Jc1[1][2]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Jc1[2][2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))) + ((l0*S10[1][1])/Sqrt(2) - (l0*S10[1][3])/Sqrt(2))*(Jc1[4][4]*Si01[2][1] + Jc1[5][4]*Si01[2][2] + Jc1[1][4]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Jc1[2][4]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))) + ((l0*S10[2][1])/Sqrt(2) - (l0*S10[2][3])/Sqrt(2))*(Jc1[4][5]*Si01[2][1] + Jc1[5][5]*Si01[2][2] + Jc1[1][5]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Jc1[2][5]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
Jcc0[5][3]=links[0].inertia[2][3] + S10[1][3]*(Jc1[4][1]*Si01[2][1] + Jc1[5][1]*Si01[2][2] + Jc1[1][1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Jc1[2][1]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))) + S10[2][3]*(Jc1[4][2]*Si01[2][1] + Jc1[5][2]*Si01[2][2] + Jc1[1][2]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Jc1[2][2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))) + 0.7071067811865475*(Jc1[4][3]*Si01[2][1] + Jc1[5][3]*Si01[2][2] + Jc1[1][3]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Jc1[2][3]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))) + (l0*S10[1][2]*(Jc1[4][4]*Si01[2][1] + Jc1[5][4]*Si01[2][2] + Jc1[1][4]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Jc1[2][4]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))))/Sqrt(2) + (l0*S10[2][2]*(Jc1[4][5]*Si01[2][1] + Jc1[5][5]*Si01[2][2] + Jc1[1][5]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Jc1[2][5]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))))/Sqrt(2);
Jcc0[5][4]=links[0].mcm[3] + S10[1][1]*(Jc1[4][4]*Si01[2][1] + Jc1[5][4]*Si01[2][2] + Jc1[1][4]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Jc1[2][4]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))) + S10[2][1]*(Jc1[4][5]*Si01[2][1] + Jc1[5][5]*Si01[2][2] + Jc1[1][5]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Jc1[2][5]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))) + 0.7071067811865475*(Jc1[4][6]*Si01[2][1] + Jc1[5][6]*Si01[2][2] + Jc1[1][6]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Jc1[2][6]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
Jcc0[5][5]=S10[1][2]*(Jc1[4][4]*Si01[2][1] + Jc1[5][4]*Si01[2][2] + Jc1[1][4]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Jc1[2][4]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))) + S10[2][2]*(Jc1[4][5]*Si01[2][1] + Jc1[5][5]*Si01[2][2] + Jc1[1][5]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Jc1[2][5]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
Jcc0[5][6]=-links[0].mcm[1] + S10[1][3]*(Jc1[4][4]*Si01[2][1] + Jc1[5][4]*Si01[2][2] + Jc1[1][4]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Jc1[2][4]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))) + S10[2][3]*(Jc1[4][5]*Si01[2][1] + Jc1[5][5]*Si01[2][2] + Jc1[1][5]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Jc1[2][5]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))) + 0.7071067811865475*(Jc1[4][6]*Si01[2][1] + Jc1[5][6]*Si01[2][2] + Jc1[1][6]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Jc1[2][6]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));

Jcc0[6][1]=links[0].inertia[1][3] + S10[1][1]*(0.7071067811865475*Jc1[6][1] + (l0*Jc1[1][1]*Si01[2][1])/Sqrt(2) + (l0*Jc1[2][1]*Si01[2][2])/Sqrt(2) + Jc1[4][1]*Si01[3][1] + Jc1[5][1]*Si01[3][2]) + S10[2][1]*(0.7071067811865475*Jc1[6][2] + (l0*Jc1[1][2]*Si01[2][1])/Sqrt(2) + (l0*Jc1[2][2]*Si01[2][2])/Sqrt(2) + Jc1[4][2]*Si01[3][1] + Jc1[5][2]*Si01[3][2]) + 0.7071067811865475*(0.7071067811865475*Jc1[6][3] + (l0*Jc1[1][3]*Si01[2][1])/Sqrt(2) + (l0*Jc1[2][3]*Si01[2][2])/Sqrt(2) + Jc1[4][3]*Si01[3][1] + Jc1[5][3]*Si01[3][2]) - (l0*S10[1][2]*(0.7071067811865475*Jc1[6][4] + (l0*Jc1[1][4]*Si01[2][1])/Sqrt(2) + (l0*Jc1[2][4]*Si01[2][2])/Sqrt(2) + Jc1[4][4]*Si01[3][1] + Jc1[5][4]*Si01[3][2]))/Sqrt(2) - (l0*S10[2][2]*(0.7071067811865475*Jc1[6][5] + (l0*Jc1[1][5]*Si01[2][1])/Sqrt(2) + (l0*Jc1[2][5]*Si01[2][2])/Sqrt(2) + Jc1[4][5]*Si01[3][1] + Jc1[5][5]*Si01[3][2]))/Sqrt(2);
Jcc0[6][2]=links[0].inertia[2][3] + S10[1][2]*(0.7071067811865475*Jc1[6][1] + (l0*Jc1[1][1]*Si01[2][1])/Sqrt(2) + (l0*Jc1[2][1]*Si01[2][2])/Sqrt(2) + Jc1[4][1]*Si01[3][1] + Jc1[5][1]*Si01[3][2]) + S10[2][2]*(0.7071067811865475*Jc1[6][2] + (l0*Jc1[1][2]*Si01[2][1])/Sqrt(2) + (l0*Jc1[2][2]*Si01[2][2])/Sqrt(2) + Jc1[4][2]*Si01[3][1] + Jc1[5][2]*Si01[3][2]) + ((l0*S10[1][1])/Sqrt(2) - (l0*S10[1][3])/Sqrt(2))*(0.7071067811865475*Jc1[6][4] + (l0*Jc1[1][4]*Si01[2][1])/Sqrt(2) + (l0*Jc1[2][4]*Si01[2][2])/Sqrt(2) + Jc1[4][4]*Si01[3][1] + Jc1[5][4]*Si01[3][2]) + ((l0*S10[2][1])/Sqrt(2) - (l0*S10[2][3])/Sqrt(2))*(0.7071067811865475*Jc1[6][5] + (l0*Jc1[1][5]*Si01[2][1])/Sqrt(2) + (l0*Jc1[2][5]*Si01[2][2])/Sqrt(2) + Jc1[4][5]*Si01[3][1] + Jc1[5][5]*Si01[3][2]);
Jcc0[6][3]=links[0].inertia[3][3] + S10[1][3]*(0.7071067811865475*Jc1[6][1] + (l0*Jc1[1][1]*Si01[2][1])/Sqrt(2) + (l0*Jc1[2][1]*Si01[2][2])/Sqrt(2) + Jc1[4][1]*Si01[3][1] + Jc1[5][1]*Si01[3][2]) + S10[2][3]*(0.7071067811865475*Jc1[6][2] + (l0*Jc1[1][2]*Si01[2][1])/Sqrt(2) + (l0*Jc1[2][2]*Si01[2][2])/Sqrt(2) + Jc1[4][2]*Si01[3][1] + Jc1[5][2]*Si01[3][2]) + 0.7071067811865475*(0.7071067811865475*Jc1[6][3] + (l0*Jc1[1][3]*Si01[2][1])/Sqrt(2) + (l0*Jc1[2][3]*Si01[2][2])/Sqrt(2) + Jc1[4][3]*Si01[3][1] + Jc1[5][3]*Si01[3][2]) + (l0*S10[1][2]*(0.7071067811865475*Jc1[6][4] + (l0*Jc1[1][4]*Si01[2][1])/Sqrt(2) + (l0*Jc1[2][4]*Si01[2][2])/Sqrt(2) + Jc1[4][4]*Si01[3][1] + Jc1[5][4]*Si01[3][2]))/Sqrt(2) + (l0*S10[2][2]*(0.7071067811865475*Jc1[6][5] + (l0*Jc1[1][5]*Si01[2][1])/Sqrt(2) + (l0*Jc1[2][5]*Si01[2][2])/Sqrt(2) + Jc1[4][5]*Si01[3][1] + Jc1[5][5]*Si01[3][2]))/Sqrt(2);
Jcc0[6][4]=-links[0].mcm[2] + S10[1][1]*(0.7071067811865475*Jc1[6][4] + (l0*Jc1[1][4]*Si01[2][1])/Sqrt(2) + (l0*Jc1[2][4]*Si01[2][2])/Sqrt(2) + Jc1[4][4]*Si01[3][1] + Jc1[5][4]*Si01[3][2]) + S10[2][1]*(0.7071067811865475*Jc1[6][5] + (l0*Jc1[1][5]*Si01[2][1])/Sqrt(2) + (l0*Jc1[2][5]*Si01[2][2])/Sqrt(2) + Jc1[4][5]*Si01[3][1] + Jc1[5][5]*Si01[3][2]) + 0.7071067811865475*(0.7071067811865475*Jc1[6][6] + (l0*Jc1[1][6]*Si01[2][1])/Sqrt(2) + (l0*Jc1[2][6]*Si01[2][2])/Sqrt(2) + Jc1[4][6]*Si01[3][1] + Jc1[5][6]*Si01[3][2]);
Jcc0[6][5]=links[0].mcm[1] + S10[1][2]*(0.7071067811865475*Jc1[6][4] + (l0*Jc1[1][4]*Si01[2][1])/Sqrt(2) + (l0*Jc1[2][4]*Si01[2][2])/Sqrt(2) + Jc1[4][4]*Si01[3][1] + Jc1[5][4]*Si01[3][2]) + S10[2][2]*(0.7071067811865475*Jc1[6][5] + (l0*Jc1[1][5]*Si01[2][1])/Sqrt(2) + (l0*Jc1[2][5]*Si01[2][2])/Sqrt(2) + Jc1[4][5]*Si01[3][1] + Jc1[5][5]*Si01[3][2]);
Jcc0[6][6]=S10[1][3]*(0.7071067811865475*Jc1[6][4] + (l0*Jc1[1][4]*Si01[2][1])/Sqrt(2) + (l0*Jc1[2][4]*Si01[2][2])/Sqrt(2) + Jc1[4][4]*Si01[3][1] + Jc1[5][4]*Si01[3][2]) + S10[2][3]*(0.7071067811865475*Jc1[6][5] + (l0*Jc1[1][5]*Si01[2][1])/Sqrt(2) + (l0*Jc1[2][5]*Si01[2][2])/Sqrt(2) + Jc1[4][5]*Si01[3][1] + Jc1[5][5]*Si01[3][2]) + 0.7071067811865475*(0.7071067811865475*Jc1[6][6] + (l0*Jc1[1][6]*Si01[2][1])/Sqrt(2) + (l0*Jc1[2][6]*Si01[2][2])/Sqrt(2) + Jc1[4][6]*Si01[3][1] + Jc1[5][6]*Si01[3][2]);



}


void
masterfunc25(void)
      {
/* composite inertia matrices */
Jc0[1][1]=S00[1][1]*(Jcc0[1][1]*Si00[1][1] + Jcc0[2][1]*Si00[1][2] + Jcc0[3][1]*Si00[1][3]) + S00[2][1]*(Jcc0[1][2]*Si00[1][1] + Jcc0[2][2]*Si00[1][2] + Jcc0[3][2]*Si00[1][3]) + S00[3][1]*(Jcc0[1][3]*Si00[1][1] + Jcc0[2][3]*Si00[1][2] + Jcc0[3][3]*Si00[1][3]);
Jc0[1][2]=S00[1][2]*(Jcc0[1][1]*Si00[1][1] + Jcc0[2][1]*Si00[1][2] + Jcc0[3][1]*Si00[1][3]) + S00[2][2]*(Jcc0[1][2]*Si00[1][1] + Jcc0[2][2]*Si00[1][2] + Jcc0[3][2]*Si00[1][3]) + S00[3][2]*(Jcc0[1][3]*Si00[1][1] + Jcc0[2][3]*Si00[1][2] + Jcc0[3][3]*Si00[1][3]);
Jc0[1][3]=S00[1][3]*(Jcc0[1][1]*Si00[1][1] + Jcc0[2][1]*Si00[1][2] + Jcc0[3][1]*Si00[1][3]) + S00[2][3]*(Jcc0[1][2]*Si00[1][1] + Jcc0[2][2]*Si00[1][2] + Jcc0[3][2]*Si00[1][3]) + S00[3][3]*(Jcc0[1][3]*Si00[1][1] + Jcc0[2][3]*Si00[1][2] + Jcc0[3][3]*Si00[1][3]);
Jc0[1][4]=S00[1][1]*(Jcc0[1][4]*Si00[1][1] + Jcc0[2][4]*Si00[1][2] + Jcc0[3][4]*Si00[1][3]) + S00[2][1]*(Jcc0[1][5]*Si00[1][1] + Jcc0[2][5]*Si00[1][2] + Jcc0[3][5]*Si00[1][3]) + S00[3][1]*(Jcc0[1][6]*Si00[1][1] + Jcc0[2][6]*Si00[1][2] + Jcc0[3][6]*Si00[1][3]);
Jc0[1][5]=S00[1][2]*(Jcc0[1][4]*Si00[1][1] + Jcc0[2][4]*Si00[1][2] + Jcc0[3][4]*Si00[1][3]) + S00[2][2]*(Jcc0[1][5]*Si00[1][1] + Jcc0[2][5]*Si00[1][2] + Jcc0[3][5]*Si00[1][3]) + S00[3][2]*(Jcc0[1][6]*Si00[1][1] + Jcc0[2][6]*Si00[1][2] + Jcc0[3][6]*Si00[1][3]);
Jc0[1][6]=S00[1][3]*(Jcc0[1][4]*Si00[1][1] + Jcc0[2][4]*Si00[1][2] + Jcc0[3][4]*Si00[1][3]) + S00[2][3]*(Jcc0[1][5]*Si00[1][1] + Jcc0[2][5]*Si00[1][2] + Jcc0[3][5]*Si00[1][3]) + S00[3][3]*(Jcc0[1][6]*Si00[1][1] + Jcc0[2][6]*Si00[1][2] + Jcc0[3][6]*Si00[1][3]);

Jc0[2][1]=S00[1][1]*(Jcc0[1][1]*Si00[2][1] + Jcc0[2][1]*Si00[2][2] + Jcc0[3][1]*Si00[2][3]) + S00[2][1]*(Jcc0[1][2]*Si00[2][1] + Jcc0[2][2]*Si00[2][2] + Jcc0[3][2]*Si00[2][3]) + S00[3][1]*(Jcc0[1][3]*Si00[2][1] + Jcc0[2][3]*Si00[2][2] + Jcc0[3][3]*Si00[2][3]);
Jc0[2][2]=S00[1][2]*(Jcc0[1][1]*Si00[2][1] + Jcc0[2][1]*Si00[2][2] + Jcc0[3][1]*Si00[2][3]) + S00[2][2]*(Jcc0[1][2]*Si00[2][1] + Jcc0[2][2]*Si00[2][2] + Jcc0[3][2]*Si00[2][3]) + S00[3][2]*(Jcc0[1][3]*Si00[2][1] + Jcc0[2][3]*Si00[2][2] + Jcc0[3][3]*Si00[2][3]);
Jc0[2][3]=S00[1][3]*(Jcc0[1][1]*Si00[2][1] + Jcc0[2][1]*Si00[2][2] + Jcc0[3][1]*Si00[2][3]) + S00[2][3]*(Jcc0[1][2]*Si00[2][1] + Jcc0[2][2]*Si00[2][2] + Jcc0[3][2]*Si00[2][3]) + S00[3][3]*(Jcc0[1][3]*Si00[2][1] + Jcc0[2][3]*Si00[2][2] + Jcc0[3][3]*Si00[2][3]);
Jc0[2][4]=S00[1][1]*(Jcc0[1][4]*Si00[2][1] + Jcc0[2][4]*Si00[2][2] + Jcc0[3][4]*Si00[2][3]) + S00[2][1]*(Jcc0[1][5]*Si00[2][1] + Jcc0[2][5]*Si00[2][2] + Jcc0[3][5]*Si00[2][3]) + S00[3][1]*(Jcc0[1][6]*Si00[2][1] + Jcc0[2][6]*Si00[2][2] + Jcc0[3][6]*Si00[2][3]);
Jc0[2][5]=S00[1][2]*(Jcc0[1][4]*Si00[2][1] + Jcc0[2][4]*Si00[2][2] + Jcc0[3][4]*Si00[2][3]) + S00[2][2]*(Jcc0[1][5]*Si00[2][1] + Jcc0[2][5]*Si00[2][2] + Jcc0[3][5]*Si00[2][3]) + S00[3][2]*(Jcc0[1][6]*Si00[2][1] + Jcc0[2][6]*Si00[2][2] + Jcc0[3][6]*Si00[2][3]);
Jc0[2][6]=S00[1][3]*(Jcc0[1][4]*Si00[2][1] + Jcc0[2][4]*Si00[2][2] + Jcc0[3][4]*Si00[2][3]) + S00[2][3]*(Jcc0[1][5]*Si00[2][1] + Jcc0[2][5]*Si00[2][2] + Jcc0[3][5]*Si00[2][3]) + S00[3][3]*(Jcc0[1][6]*Si00[2][1] + Jcc0[2][6]*Si00[2][2] + Jcc0[3][6]*Si00[2][3]);

Jc0[3][1]=S00[1][1]*(Jcc0[1][1]*Si00[3][1] + Jcc0[2][1]*Si00[3][2] + Jcc0[3][1]*Si00[3][3]) + S00[2][1]*(Jcc0[1][2]*Si00[3][1] + Jcc0[2][2]*Si00[3][2] + Jcc0[3][2]*Si00[3][3]) + S00[3][1]*(Jcc0[1][3]*Si00[3][1] + Jcc0[2][3]*Si00[3][2] + Jcc0[3][3]*Si00[3][3]);
Jc0[3][2]=S00[1][2]*(Jcc0[1][1]*Si00[3][1] + Jcc0[2][1]*Si00[3][2] + Jcc0[3][1]*Si00[3][3]) + S00[2][2]*(Jcc0[1][2]*Si00[3][1] + Jcc0[2][2]*Si00[3][2] + Jcc0[3][2]*Si00[3][3]) + S00[3][2]*(Jcc0[1][3]*Si00[3][1] + Jcc0[2][3]*Si00[3][2] + Jcc0[3][3]*Si00[3][3]);
Jc0[3][3]=S00[1][3]*(Jcc0[1][1]*Si00[3][1] + Jcc0[2][1]*Si00[3][2] + Jcc0[3][1]*Si00[3][3]) + S00[2][3]*(Jcc0[1][2]*Si00[3][1] + Jcc0[2][2]*Si00[3][2] + Jcc0[3][2]*Si00[3][3]) + S00[3][3]*(Jcc0[1][3]*Si00[3][1] + Jcc0[2][3]*Si00[3][2] + Jcc0[3][3]*Si00[3][3]);
Jc0[3][4]=S00[1][1]*(Jcc0[1][4]*Si00[3][1] + Jcc0[2][4]*Si00[3][2] + Jcc0[3][4]*Si00[3][3]) + S00[2][1]*(Jcc0[1][5]*Si00[3][1] + Jcc0[2][5]*Si00[3][2] + Jcc0[3][5]*Si00[3][3]) + S00[3][1]*(Jcc0[1][6]*Si00[3][1] + Jcc0[2][6]*Si00[3][2] + Jcc0[3][6]*Si00[3][3]);
Jc0[3][5]=S00[1][2]*(Jcc0[1][4]*Si00[3][1] + Jcc0[2][4]*Si00[3][2] + Jcc0[3][4]*Si00[3][3]) + S00[2][2]*(Jcc0[1][5]*Si00[3][1] + Jcc0[2][5]*Si00[3][2] + Jcc0[3][5]*Si00[3][3]) + S00[3][2]*(Jcc0[1][6]*Si00[3][1] + Jcc0[2][6]*Si00[3][2] + Jcc0[3][6]*Si00[3][3]);
Jc0[3][6]=S00[1][3]*(Jcc0[1][4]*Si00[3][1] + Jcc0[2][4]*Si00[3][2] + Jcc0[3][4]*Si00[3][3]) + S00[2][3]*(Jcc0[1][5]*Si00[3][1] + Jcc0[2][5]*Si00[3][2] + Jcc0[3][5]*Si00[3][3]) + S00[3][3]*(Jcc0[1][6]*Si00[3][1] + Jcc0[2][6]*Si00[3][2] + Jcc0[3][6]*Si00[3][3]);

Jc0[4][1]=S00[1][1]*(Jcc0[4][1]*Si00[1][1] + Jcc0[5][1]*Si00[1][2] + Jcc0[6][1]*Si00[1][3]) + S00[2][1]*(Jcc0[4][2]*Si00[1][1] + Jcc0[5][2]*Si00[1][2] + Jcc0[6][2]*Si00[1][3]) + S00[3][1]*(Jcc0[4][3]*Si00[1][1] + Jcc0[5][3]*Si00[1][2] + Jcc0[6][3]*Si00[1][3]);
Jc0[4][2]=S00[1][2]*(Jcc0[4][1]*Si00[1][1] + Jcc0[5][1]*Si00[1][2] + Jcc0[6][1]*Si00[1][3]) + S00[2][2]*(Jcc0[4][2]*Si00[1][1] + Jcc0[5][2]*Si00[1][2] + Jcc0[6][2]*Si00[1][3]) + S00[3][2]*(Jcc0[4][3]*Si00[1][1] + Jcc0[5][3]*Si00[1][2] + Jcc0[6][3]*Si00[1][3]);
Jc0[4][3]=S00[1][3]*(Jcc0[4][1]*Si00[1][1] + Jcc0[5][1]*Si00[1][2] + Jcc0[6][1]*Si00[1][3]) + S00[2][3]*(Jcc0[4][2]*Si00[1][1] + Jcc0[5][2]*Si00[1][2] + Jcc0[6][2]*Si00[1][3]) + S00[3][3]*(Jcc0[4][3]*Si00[1][1] + Jcc0[5][3]*Si00[1][2] + Jcc0[6][3]*Si00[1][3]);
Jc0[4][4]=S00[1][1]*(Jcc0[4][4]*Si00[1][1] + Jcc0[5][4]*Si00[1][2] + Jcc0[6][4]*Si00[1][3]) + S00[2][1]*(Jcc0[4][5]*Si00[1][1] + Jcc0[5][5]*Si00[1][2] + Jcc0[6][5]*Si00[1][3]) + S00[3][1]*(Jcc0[4][6]*Si00[1][1] + Jcc0[5][6]*Si00[1][2] + Jcc0[6][6]*Si00[1][3]);
Jc0[4][5]=S00[1][2]*(Jcc0[4][4]*Si00[1][1] + Jcc0[5][4]*Si00[1][2] + Jcc0[6][4]*Si00[1][3]) + S00[2][2]*(Jcc0[4][5]*Si00[1][1] + Jcc0[5][5]*Si00[1][2] + Jcc0[6][5]*Si00[1][3]) + S00[3][2]*(Jcc0[4][6]*Si00[1][1] + Jcc0[5][6]*Si00[1][2] + Jcc0[6][6]*Si00[1][3]);
Jc0[4][6]=S00[1][3]*(Jcc0[4][4]*Si00[1][1] + Jcc0[5][4]*Si00[1][2] + Jcc0[6][4]*Si00[1][3]) + S00[2][3]*(Jcc0[4][5]*Si00[1][1] + Jcc0[5][5]*Si00[1][2] + Jcc0[6][5]*Si00[1][3]) + S00[3][3]*(Jcc0[4][6]*Si00[1][1] + Jcc0[5][6]*Si00[1][2] + Jcc0[6][6]*Si00[1][3]);

Jc0[5][1]=S00[1][1]*(Jcc0[4][1]*Si00[2][1] + Jcc0[5][1]*Si00[2][2] + Jcc0[6][1]*Si00[2][3]) + S00[2][1]*(Jcc0[4][2]*Si00[2][1] + Jcc0[5][2]*Si00[2][2] + Jcc0[6][2]*Si00[2][3]) + S00[3][1]*(Jcc0[4][3]*Si00[2][1] + Jcc0[5][3]*Si00[2][2] + Jcc0[6][3]*Si00[2][3]);
Jc0[5][2]=S00[1][2]*(Jcc0[4][1]*Si00[2][1] + Jcc0[5][1]*Si00[2][2] + Jcc0[6][1]*Si00[2][3]) + S00[2][2]*(Jcc0[4][2]*Si00[2][1] + Jcc0[5][2]*Si00[2][2] + Jcc0[6][2]*Si00[2][3]) + S00[3][2]*(Jcc0[4][3]*Si00[2][1] + Jcc0[5][3]*Si00[2][2] + Jcc0[6][3]*Si00[2][3]);
Jc0[5][3]=S00[1][3]*(Jcc0[4][1]*Si00[2][1] + Jcc0[5][1]*Si00[2][2] + Jcc0[6][1]*Si00[2][3]) + S00[2][3]*(Jcc0[4][2]*Si00[2][1] + Jcc0[5][2]*Si00[2][2] + Jcc0[6][2]*Si00[2][3]) + S00[3][3]*(Jcc0[4][3]*Si00[2][1] + Jcc0[5][3]*Si00[2][2] + Jcc0[6][3]*Si00[2][3]);
Jc0[5][4]=S00[1][1]*(Jcc0[4][4]*Si00[2][1] + Jcc0[5][4]*Si00[2][2] + Jcc0[6][4]*Si00[2][3]) + S00[2][1]*(Jcc0[4][5]*Si00[2][1] + Jcc0[5][5]*Si00[2][2] + Jcc0[6][5]*Si00[2][3]) + S00[3][1]*(Jcc0[4][6]*Si00[2][1] + Jcc0[5][6]*Si00[2][2] + Jcc0[6][6]*Si00[2][3]);
Jc0[5][5]=S00[1][2]*(Jcc0[4][4]*Si00[2][1] + Jcc0[5][4]*Si00[2][2] + Jcc0[6][4]*Si00[2][3]) + S00[2][2]*(Jcc0[4][5]*Si00[2][1] + Jcc0[5][5]*Si00[2][2] + Jcc0[6][5]*Si00[2][3]) + S00[3][2]*(Jcc0[4][6]*Si00[2][1] + Jcc0[5][6]*Si00[2][2] + Jcc0[6][6]*Si00[2][3]);
Jc0[5][6]=S00[1][3]*(Jcc0[4][4]*Si00[2][1] + Jcc0[5][4]*Si00[2][2] + Jcc0[6][4]*Si00[2][3]) + S00[2][3]*(Jcc0[4][5]*Si00[2][1] + Jcc0[5][5]*Si00[2][2] + Jcc0[6][5]*Si00[2][3]) + S00[3][3]*(Jcc0[4][6]*Si00[2][1] + Jcc0[5][6]*Si00[2][2] + Jcc0[6][6]*Si00[2][3]);

Jc0[6][1]=S00[1][1]*(Jcc0[4][1]*Si00[3][1] + Jcc0[5][1]*Si00[3][2] + Jcc0[6][1]*Si00[3][3]) + S00[2][1]*(Jcc0[4][2]*Si00[3][1] + Jcc0[5][2]*Si00[3][2] + Jcc0[6][2]*Si00[3][3]) + S00[3][1]*(Jcc0[4][3]*Si00[3][1] + Jcc0[5][3]*Si00[3][2] + Jcc0[6][3]*Si00[3][3]);
Jc0[6][2]=S00[1][2]*(Jcc0[4][1]*Si00[3][1] + Jcc0[5][1]*Si00[3][2] + Jcc0[6][1]*Si00[3][3]) + S00[2][2]*(Jcc0[4][2]*Si00[3][1] + Jcc0[5][2]*Si00[3][2] + Jcc0[6][2]*Si00[3][3]) + S00[3][2]*(Jcc0[4][3]*Si00[3][1] + Jcc0[5][3]*Si00[3][2] + Jcc0[6][3]*Si00[3][3]);
Jc0[6][3]=S00[1][3]*(Jcc0[4][1]*Si00[3][1] + Jcc0[5][1]*Si00[3][2] + Jcc0[6][1]*Si00[3][3]) + S00[2][3]*(Jcc0[4][2]*Si00[3][1] + Jcc0[5][2]*Si00[3][2] + Jcc0[6][2]*Si00[3][3]) + S00[3][3]*(Jcc0[4][3]*Si00[3][1] + Jcc0[5][3]*Si00[3][2] + Jcc0[6][3]*Si00[3][3]);
Jc0[6][4]=S00[1][1]*(Jcc0[4][4]*Si00[3][1] + Jcc0[5][4]*Si00[3][2] + Jcc0[6][4]*Si00[3][3]) + S00[2][1]*(Jcc0[4][5]*Si00[3][1] + Jcc0[5][5]*Si00[3][2] + Jcc0[6][5]*Si00[3][3]) + S00[3][1]*(Jcc0[4][6]*Si00[3][1] + Jcc0[5][6]*Si00[3][2] + Jcc0[6][6]*Si00[3][3]);
Jc0[6][5]=S00[1][2]*(Jcc0[4][4]*Si00[3][1] + Jcc0[5][4]*Si00[3][2] + Jcc0[6][4]*Si00[3][3]) + S00[2][2]*(Jcc0[4][5]*Si00[3][1] + Jcc0[5][5]*Si00[3][2] + Jcc0[6][5]*Si00[3][3]) + S00[3][2]*(Jcc0[4][6]*Si00[3][1] + Jcc0[5][6]*Si00[3][2] + Jcc0[6][6]*Si00[3][3]);
Jc0[6][6]=S00[1][3]*(Jcc0[4][4]*Si00[3][1] + Jcc0[5][4]*Si00[3][2] + Jcc0[6][4]*Si00[3][3]) + S00[2][3]*(Jcc0[4][5]*Si00[3][1] + Jcc0[5][5]*Si00[3][2] + Jcc0[6][5]*Si00[3][3]) + S00[3][3]*(Jcc0[4][6]*Si00[3][1] + Jcc0[5][6]*Si00[3][2] + Jcc0[6][6]*Si00[3][3]);



}


void
masterfunc26(void)
      {
/* unit force elements of inertia matrix */

Fu1212[1]=Jc12[1][3];
Fu1212[2]=Jc12[2][3];
Fu1212[3]=Jc12[3][3];
Fu1212[4]=Jc12[4][3];
Fu1212[5]=Jc12[5][3];
Fu1212[6]=Jc12[6][3];

Fu127[1]=Fu1212[1]*Si712[1][1] + Fu1212[2]*Si712[1][2];
Fu127[2]=Fu1212[1]*Si712[2][1] + Fu1212[2]*Si712[2][2];
Fu127[3]=Fu1212[3];
Fu127[4]=l6y*Fu1212[3] + Fu1212[4]*Si712[1][1] + Fu1212[5]*Si712[1][2] - l6z*Fu1212[1]*Si712[2][1] - l6z*Fu1212[2]*Si712[2][2];
Fu127[5]=l6x*Fu1212[3] + l6z*Fu1212[1]*Si712[1][1] + l6z*Fu1212[2]*Si712[1][2] + Fu1212[4]*Si712[2][1] + Fu1212[5]*Si712[2][2];
Fu127[6]=Fu1212[6] + Fu1212[1]*(-(l6y*Si712[1][1]) - l6x*Si712[2][1]) + Fu1212[2]*(-(l6y*Si712[1][2]) - l6x*Si712[2][2]);

Fu126[1]=Fu127[3];
Fu126[2]=Fu127[1]*Si67[2][1] + Fu127[2]*Si67[2][2];
Fu126[3]=Fu127[1]*Si67[3][1] + Fu127[2]*Si67[3][2];
Fu126[4]=Fu127[6] - l5*Fu127[1]*Si67[2][1] - l5*Fu127[2]*Si67[2][2];
Fu126[5]=l5*Fu127[3] + Fu127[4]*Si67[2][1] + Fu127[5]*Si67[2][2];
Fu126[6]=Fu127[4]*Si67[3][1] + Fu127[5]*Si67[3][2];

Fu125[1]=Fu126[1]*Si56[1][1] + Fu126[2]*Si56[1][2];
Fu125[2]=Fu126[3];
Fu125[3]=Fu126[1]*Si56[3][1] + Fu126[2]*Si56[3][2];
Fu125[4]=-(l4*Fu126[3]) + Fu126[4]*Si56[1][1] + Fu126[5]*Si56[1][2];
Fu125[5]=Fu126[6] + l4*Fu126[1]*Si56[1][1] + l4*Fu126[2]*Si56[1][2];
Fu125[6]=Fu126[4]*Si56[3][1] + Fu126[5]*Si56[3][2];

Fu124[1]=-Fu125[3];
Fu124[2]=Fu125[1]*Si45[2][1] + Fu125[2]*Si45[2][2];
Fu124[3]=Fu125[1]*Si45[3][1] + Fu125[2]*Si45[3][2];
Fu124[4]=-Fu125[6] + l3*Fu125[1]*Si45[2][1] + l3*Fu125[2]*Si45[2][2];
Fu124[5]=l3*Fu125[3] + Fu125[4]*Si45[2][1] + Fu125[5]*Si45[2][2];
Fu124[6]=Fu125[4]*Si45[3][1] + Fu125[5]*Si45[3][2];

Fu123[1]=Fu124[1]*Si34[1][1] + Fu124[2]*Si34[1][2];
Fu123[2]=-Fu124[3];
Fu123[3]=Fu124[1]*Si34[3][1] + Fu124[2]*Si34[3][2];
Fu123[4]=l2*Fu124[3] + Fu124[4]*Si34[1][1] + Fu124[5]*Si34[1][2];
Fu123[5]=-Fu124[6] + l2*Fu124[1]*Si34[1][1] + l2*Fu124[2]*Si34[1][2];
Fu123[6]=Fu124[4]*Si34[3][1] + Fu124[5]*Si34[3][2];

Fu122[1]=Fu123[3];
Fu122[2]=Fu123[1]*Si23[2][1] + Fu123[2]*Si23[2][2];
Fu122[3]=Fu123[1]*Si23[3][1] + Fu123[2]*Si23[3][2];
Fu122[4]=Fu123[6] - l1*Fu123[1]*Si23[3][1] - l1*Fu123[2]*Si23[3][2];
Fu122[5]=Fu123[4]*Si23[2][1] + Fu123[5]*Si23[2][2];
Fu122[6]=l1*Fu123[3] + Fu123[4]*Si23[3][1] + Fu123[5]*Si23[3][2];

Fu121[1]=Fu122[1]*Si12[1][1] + Fu122[2]*Si12[1][2];
Fu121[2]=Fu122[3];
Fu121[3]=Fu122[1]*Si12[3][1] + Fu122[2]*Si12[3][2];
Fu121[4]=Fu122[4]*Si12[1][1] + Fu122[5]*Si12[1][2];
Fu121[5]=Fu122[6];
Fu121[6]=Fu122[4]*Si12[3][1] + Fu122[5]*Si12[3][2];



Fu1010[1]=Jc10[1][3];
Fu1010[2]=Jc10[2][3];
Fu1010[3]=Jc10[3][3];
Fu1010[4]=Jc10[4][3];
Fu1010[5]=Jc10[5][3];
Fu1010[6]=Jc10[6][3];

Fu109[1]=Fu1010[3];
Fu109[2]=Fu1010[1]*Si910[2][1] + Fu1010[2]*Si910[2][2];
Fu109[3]=Fu1010[1]*Si910[3][1] + Fu1010[2]*Si910[3][2];
Fu109[4]=Fu1010[6];
Fu109[5]=Fu1010[4]*Si910[2][1] + Fu1010[5]*Si910[2][2];
Fu109[6]=Fu1010[4]*Si910[3][1] + Fu1010[5]*Si910[3][2];

Fu107[1]=-Fu109[3];
Fu107[2]=Fu109[1]*Si79[2][1] + Fu109[2]*Si79[2][2];
Fu107[3]=Fu109[1]*Si79[3][1] + Fu109[2]*Si79[3][2];
Fu107[4]=-Fu109[6] - l7z*Fu109[1]*Si79[2][1] - l7z*Fu109[2]*Si79[2][2];
Fu107[5]=-(l7z*Fu109[3]) + Fu109[4]*Si79[2][1] + Fu109[5]*Si79[2][2] + l6x*Fu109[1]*Si79[3][1] + l6x*Fu109[2]*Si79[3][2];
Fu107[6]=-(l6x*Fu109[1]*Si79[2][1]) - l6x*Fu109[2]*Si79[2][2] + Fu109[4]*Si79[3][1] + Fu109[5]*Si79[3][2];

Fu106[1]=Fu107[3];
Fu106[2]=Fu107[1]*Si67[2][1] + Fu107[2]*Si67[2][2];
Fu106[3]=Fu107[1]*Si67[3][1] + Fu107[2]*Si67[3][2];
Fu106[4]=Fu107[6] - l5*Fu107[1]*Si67[2][1] - l5*Fu107[2]*Si67[2][2];
Fu106[5]=l5*Fu107[3] + Fu107[4]*Si67[2][1] + Fu107[5]*Si67[2][2];
Fu106[6]=Fu107[4]*Si67[3][1] + Fu107[5]*Si67[3][2];

Fu105[1]=Fu106[1]*Si56[1][1] + Fu106[2]*Si56[1][2];
Fu105[2]=Fu106[3];
Fu105[3]=Fu106[1]*Si56[3][1] + Fu106[2]*Si56[3][2];
Fu105[4]=-(l4*Fu106[3]) + Fu106[4]*Si56[1][1] + Fu106[5]*Si56[1][2];
Fu105[5]=Fu106[6] + l4*Fu106[1]*Si56[1][1] + l4*Fu106[2]*Si56[1][2];
Fu105[6]=Fu106[4]*Si56[3][1] + Fu106[5]*Si56[3][2];

Fu104[1]=-Fu105[3];
Fu104[2]=Fu105[1]*Si45[2][1] + Fu105[2]*Si45[2][2];
Fu104[3]=Fu105[1]*Si45[3][1] + Fu105[2]*Si45[3][2];
Fu104[4]=-Fu105[6] + l3*Fu105[1]*Si45[2][1] + l3*Fu105[2]*Si45[2][2];
Fu104[5]=l3*Fu105[3] + Fu105[4]*Si45[2][1] + Fu105[5]*Si45[2][2];
Fu104[6]=Fu105[4]*Si45[3][1] + Fu105[5]*Si45[3][2];

Fu103[1]=Fu104[1]*Si34[1][1] + Fu104[2]*Si34[1][2];
Fu103[2]=-Fu104[3];
Fu103[3]=Fu104[1]*Si34[3][1] + Fu104[2]*Si34[3][2];
Fu103[4]=l2*Fu104[3] + Fu104[4]*Si34[1][1] + Fu104[5]*Si34[1][2];
Fu103[5]=-Fu104[6] + l2*Fu104[1]*Si34[1][1] + l2*Fu104[2]*Si34[1][2];
Fu103[6]=Fu104[4]*Si34[3][1] + Fu104[5]*Si34[3][2];

Fu102[1]=Fu103[3];
Fu102[2]=Fu103[1]*Si23[2][1] + Fu103[2]*Si23[2][2];
Fu102[3]=Fu103[1]*Si23[3][1] + Fu103[2]*Si23[3][2];
Fu102[4]=Fu103[6] - l1*Fu103[1]*Si23[3][1] - l1*Fu103[2]*Si23[3][2];
Fu102[5]=Fu103[4]*Si23[2][1] + Fu103[5]*Si23[2][2];
Fu102[6]=l1*Fu103[3] + Fu103[4]*Si23[3][1] + Fu103[5]*Si23[3][2];

Fu101[1]=Fu102[1]*Si12[1][1] + Fu102[2]*Si12[1][2];
Fu101[2]=Fu102[3];
Fu101[3]=Fu102[1]*Si12[3][1] + Fu102[2]*Si12[3][2];
Fu101[4]=Fu102[4]*Si12[1][1] + Fu102[5]*Si12[1][2];
Fu101[5]=Fu102[6];
Fu101[6]=Fu102[4]*Si12[3][1] + Fu102[5]*Si12[3][2];


Fu99[1]=Jc9[1][3];
Fu99[2]=Jc9[2][3];
Fu99[3]=Jc9[3][3];
Fu99[4]=Jc9[4][3];
Fu99[5]=Jc9[5][3];
Fu99[6]=Jc9[6][3];

Fu97[1]=-Fu99[3];
Fu97[2]=Fu99[1]*Si79[2][1] + Fu99[2]*Si79[2][2];
Fu97[3]=Fu99[1]*Si79[3][1] + Fu99[2]*Si79[3][2];
Fu97[4]=-Fu99[6] - l7z*Fu99[1]*Si79[2][1] - l7z*Fu99[2]*Si79[2][2];
Fu97[5]=-(l7z*Fu99[3]) + Fu99[4]*Si79[2][1] + Fu99[5]*Si79[2][2] + l6x*Fu99[1]*Si79[3][1] + l6x*Fu99[2]*Si79[3][2];
Fu97[6]=-(l6x*Fu99[1]*Si79[2][1]) - l6x*Fu99[2]*Si79[2][2] + Fu99[4]*Si79[3][1] + Fu99[5]*Si79[3][2];

Fu96[1]=Fu97[3];
Fu96[2]=Fu97[1]*Si67[2][1] + Fu97[2]*Si67[2][2];
Fu96[3]=Fu97[1]*Si67[3][1] + Fu97[2]*Si67[3][2];
Fu96[4]=Fu97[6] - l5*Fu97[1]*Si67[2][1] - l5*Fu97[2]*Si67[2][2];
Fu96[5]=l5*Fu97[3] + Fu97[4]*Si67[2][1] + Fu97[5]*Si67[2][2];
Fu96[6]=Fu97[4]*Si67[3][1] + Fu97[5]*Si67[3][2];

Fu95[1]=Fu96[1]*Si56[1][1] + Fu96[2]*Si56[1][2];
Fu95[2]=Fu96[3];
Fu95[3]=Fu96[1]*Si56[3][1] + Fu96[2]*Si56[3][2];
Fu95[4]=-(l4*Fu96[3]) + Fu96[4]*Si56[1][1] + Fu96[5]*Si56[1][2];
Fu95[5]=Fu96[6] + l4*Fu96[1]*Si56[1][1] + l4*Fu96[2]*Si56[1][2];
Fu95[6]=Fu96[4]*Si56[3][1] + Fu96[5]*Si56[3][2];

Fu94[1]=-Fu95[3];
Fu94[2]=Fu95[1]*Si45[2][1] + Fu95[2]*Si45[2][2];
Fu94[3]=Fu95[1]*Si45[3][1] + Fu95[2]*Si45[3][2];
Fu94[4]=-Fu95[6] + l3*Fu95[1]*Si45[2][1] + l3*Fu95[2]*Si45[2][2];
Fu94[5]=l3*Fu95[3] + Fu95[4]*Si45[2][1] + Fu95[5]*Si45[2][2];
Fu94[6]=Fu95[4]*Si45[3][1] + Fu95[5]*Si45[3][2];

Fu93[1]=Fu94[1]*Si34[1][1] + Fu94[2]*Si34[1][2];
Fu93[2]=-Fu94[3];
Fu93[3]=Fu94[1]*Si34[3][1] + Fu94[2]*Si34[3][2];
Fu93[4]=l2*Fu94[3] + Fu94[4]*Si34[1][1] + Fu94[5]*Si34[1][2];
Fu93[5]=-Fu94[6] + l2*Fu94[1]*Si34[1][1] + l2*Fu94[2]*Si34[1][2];
Fu93[6]=Fu94[4]*Si34[3][1] + Fu94[5]*Si34[3][2];

Fu92[1]=Fu93[3];
Fu92[2]=Fu93[1]*Si23[2][1] + Fu93[2]*Si23[2][2];
Fu92[3]=Fu93[1]*Si23[3][1] + Fu93[2]*Si23[3][2];
Fu92[4]=Fu93[6] - l1*Fu93[1]*Si23[3][1] - l1*Fu93[2]*Si23[3][2];
Fu92[5]=Fu93[4]*Si23[2][1] + Fu93[5]*Si23[2][2];
Fu92[6]=l1*Fu93[3] + Fu93[4]*Si23[3][1] + Fu93[5]*Si23[3][2];

Fu91[1]=Fu92[1]*Si12[1][1] + Fu92[2]*Si12[1][2];
Fu91[2]=Fu92[3];
Fu91[3]=Fu92[1]*Si12[3][1] + Fu92[2]*Si12[3][2];
Fu91[4]=Fu92[4]*Si12[1][1] + Fu92[5]*Si12[1][2];
Fu91[5]=Fu92[6];
Fu91[6]=Fu92[4]*Si12[3][1] + Fu92[5]*Si12[3][2];



Fu77[1]=Jc7[1][3];
Fu77[2]=Jc7[2][3];
Fu77[3]=Jc7[3][3];
Fu77[4]=Jc7[4][3];
Fu77[5]=Jc7[5][3];
Fu77[6]=Jc7[6][3];

Fu76[1]=Fu77[3];
Fu76[2]=Fu77[1]*Si67[2][1] + Fu77[2]*Si67[2][2];
Fu76[3]=Fu77[1]*Si67[3][1] + Fu77[2]*Si67[3][2];
Fu76[4]=Fu77[6] - l5*Fu77[1]*Si67[2][1] - l5*Fu77[2]*Si67[2][2];
Fu76[5]=l5*Fu77[3] + Fu77[4]*Si67[2][1] + Fu77[5]*Si67[2][2];
Fu76[6]=Fu77[4]*Si67[3][1] + Fu77[5]*Si67[3][2];

Fu75[1]=Fu76[1]*Si56[1][1] + Fu76[2]*Si56[1][2];
Fu75[2]=Fu76[3];
Fu75[3]=Fu76[1]*Si56[3][1] + Fu76[2]*Si56[3][2];
Fu75[4]=-(l4*Fu76[3]) + Fu76[4]*Si56[1][1] + Fu76[5]*Si56[1][2];
Fu75[5]=Fu76[6] + l4*Fu76[1]*Si56[1][1] + l4*Fu76[2]*Si56[1][2];
Fu75[6]=Fu76[4]*Si56[3][1] + Fu76[5]*Si56[3][2];

Fu74[1]=-Fu75[3];
Fu74[2]=Fu75[1]*Si45[2][1] + Fu75[2]*Si45[2][2];
Fu74[3]=Fu75[1]*Si45[3][1] + Fu75[2]*Si45[3][2];
Fu74[4]=-Fu75[6] + l3*Fu75[1]*Si45[2][1] + l3*Fu75[2]*Si45[2][2];
Fu74[5]=l3*Fu75[3] + Fu75[4]*Si45[2][1] + Fu75[5]*Si45[2][2];
Fu74[6]=Fu75[4]*Si45[3][1] + Fu75[5]*Si45[3][2];

Fu73[1]=Fu74[1]*Si34[1][1] + Fu74[2]*Si34[1][2];
Fu73[2]=-Fu74[3];
Fu73[3]=Fu74[1]*Si34[3][1] + Fu74[2]*Si34[3][2];
Fu73[4]=l2*Fu74[3] + Fu74[4]*Si34[1][1] + Fu74[5]*Si34[1][2];
Fu73[5]=-Fu74[6] + l2*Fu74[1]*Si34[1][1] + l2*Fu74[2]*Si34[1][2];
Fu73[6]=Fu74[4]*Si34[3][1] + Fu74[5]*Si34[3][2];

Fu72[1]=Fu73[3];
Fu72[2]=Fu73[1]*Si23[2][1] + Fu73[2]*Si23[2][2];
Fu72[3]=Fu73[1]*Si23[3][1] + Fu73[2]*Si23[3][2];
Fu72[4]=Fu73[6] - l1*Fu73[1]*Si23[3][1] - l1*Fu73[2]*Si23[3][2];
Fu72[5]=Fu73[4]*Si23[2][1] + Fu73[5]*Si23[2][2];
Fu72[6]=l1*Fu73[3] + Fu73[4]*Si23[3][1] + Fu73[5]*Si23[3][2];

Fu71[1]=Fu72[1]*Si12[1][1] + Fu72[2]*Si12[1][2];
Fu71[2]=Fu72[3];
Fu71[3]=Fu72[1]*Si12[3][1] + Fu72[2]*Si12[3][2];
Fu71[4]=Fu72[4]*Si12[1][1] + Fu72[5]*Si12[1][2];
Fu71[5]=Fu72[6];
Fu71[6]=Fu72[4]*Si12[3][1] + Fu72[5]*Si12[3][2];


Fu66[1]=Jc6[1][3];
Fu66[2]=Jc6[2][3];
Fu66[3]=Jc6[3][3];
Fu66[4]=Jc6[4][3];
Fu66[5]=Jc6[5][3];
Fu66[6]=Jc6[6][3];

Fu65[1]=Fu66[1]*Si56[1][1] + Fu66[2]*Si56[1][2];
Fu65[2]=Fu66[3];
Fu65[3]=Fu66[1]*Si56[3][1] + Fu66[2]*Si56[3][2];
Fu65[4]=-(l4*Fu66[3]) + Fu66[4]*Si56[1][1] + Fu66[5]*Si56[1][2];
Fu65[5]=Fu66[6] + l4*Fu66[1]*Si56[1][1] + l4*Fu66[2]*Si56[1][2];
Fu65[6]=Fu66[4]*Si56[3][1] + Fu66[5]*Si56[3][2];

Fu64[1]=-Fu65[3];
Fu64[2]=Fu65[1]*Si45[2][1] + Fu65[2]*Si45[2][2];
Fu64[3]=Fu65[1]*Si45[3][1] + Fu65[2]*Si45[3][2];
Fu64[4]=-Fu65[6] + l3*Fu65[1]*Si45[2][1] + l3*Fu65[2]*Si45[2][2];
Fu64[5]=l3*Fu65[3] + Fu65[4]*Si45[2][1] + Fu65[5]*Si45[2][2];
Fu64[6]=Fu65[4]*Si45[3][1] + Fu65[5]*Si45[3][2];

Fu63[1]=Fu64[1]*Si34[1][1] + Fu64[2]*Si34[1][2];
Fu63[2]=-Fu64[3];
Fu63[3]=Fu64[1]*Si34[3][1] + Fu64[2]*Si34[3][2];
Fu63[4]=l2*Fu64[3] + Fu64[4]*Si34[1][1] + Fu64[5]*Si34[1][2];
Fu63[5]=-Fu64[6] + l2*Fu64[1]*Si34[1][1] + l2*Fu64[2]*Si34[1][2];
Fu63[6]=Fu64[4]*Si34[3][1] + Fu64[5]*Si34[3][2];

Fu62[1]=Fu63[3];
Fu62[2]=Fu63[1]*Si23[2][1] + Fu63[2]*Si23[2][2];
Fu62[3]=Fu63[1]*Si23[3][1] + Fu63[2]*Si23[3][2];
Fu62[4]=Fu63[6] - l1*Fu63[1]*Si23[3][1] - l1*Fu63[2]*Si23[3][2];
Fu62[5]=Fu63[4]*Si23[2][1] + Fu63[5]*Si23[2][2];
Fu62[6]=l1*Fu63[3] + Fu63[4]*Si23[3][1] + Fu63[5]*Si23[3][2];

Fu61[1]=Fu62[1]*Si12[1][1] + Fu62[2]*Si12[1][2];
Fu61[2]=Fu62[3];
Fu61[3]=Fu62[1]*Si12[3][1] + Fu62[2]*Si12[3][2];
Fu61[4]=Fu62[4]*Si12[1][1] + Fu62[5]*Si12[1][2];
Fu61[5]=Fu62[6];
Fu61[6]=Fu62[4]*Si12[3][1] + Fu62[5]*Si12[3][2];


Fu55[1]=Jc5[1][3];
Fu55[2]=Jc5[2][3];
Fu55[3]=Jc5[3][3];
Fu55[4]=Jc5[4][3];
Fu55[5]=Jc5[5][3];
Fu55[6]=Jc5[6][3];

Fu54[1]=-Fu55[3];
Fu54[2]=Fu55[1]*Si45[2][1] + Fu55[2]*Si45[2][2];
Fu54[3]=Fu55[1]*Si45[3][1] + Fu55[2]*Si45[3][2];
Fu54[4]=-Fu55[6] + l3*Fu55[1]*Si45[2][1] + l3*Fu55[2]*Si45[2][2];
Fu54[5]=l3*Fu55[3] + Fu55[4]*Si45[2][1] + Fu55[5]*Si45[2][2];
Fu54[6]=Fu55[4]*Si45[3][1] + Fu55[5]*Si45[3][2];

Fu53[1]=Fu54[1]*Si34[1][1] + Fu54[2]*Si34[1][2];
Fu53[2]=-Fu54[3];
Fu53[3]=Fu54[1]*Si34[3][1] + Fu54[2]*Si34[3][2];
Fu53[4]=l2*Fu54[3] + Fu54[4]*Si34[1][1] + Fu54[5]*Si34[1][2];
Fu53[5]=-Fu54[6] + l2*Fu54[1]*Si34[1][1] + l2*Fu54[2]*Si34[1][2];
Fu53[6]=Fu54[4]*Si34[3][1] + Fu54[5]*Si34[3][2];

Fu52[1]=Fu53[3];
Fu52[2]=Fu53[1]*Si23[2][1] + Fu53[2]*Si23[2][2];
Fu52[3]=Fu53[1]*Si23[3][1] + Fu53[2]*Si23[3][2];
Fu52[4]=Fu53[6] - l1*Fu53[1]*Si23[3][1] - l1*Fu53[2]*Si23[3][2];
Fu52[5]=Fu53[4]*Si23[2][1] + Fu53[5]*Si23[2][2];
Fu52[6]=l1*Fu53[3] + Fu53[4]*Si23[3][1] + Fu53[5]*Si23[3][2];

Fu51[1]=Fu52[1]*Si12[1][1] + Fu52[2]*Si12[1][2];
Fu51[2]=Fu52[3];
Fu51[3]=Fu52[1]*Si12[3][1] + Fu52[2]*Si12[3][2];
Fu51[4]=Fu52[4]*Si12[1][1] + Fu52[5]*Si12[1][2];
Fu51[5]=Fu52[6];
Fu51[6]=Fu52[4]*Si12[3][1] + Fu52[5]*Si12[3][2];


Fu44[1]=Jc4[1][3];
Fu44[2]=Jc4[2][3];
Fu44[3]=Jc4[3][3];
Fu44[4]=Jc4[4][3];
Fu44[5]=Jc4[5][3];
Fu44[6]=Jc4[6][3];

Fu43[1]=Fu44[1]*Si34[1][1] + Fu44[2]*Si34[1][2];
Fu43[2]=-Fu44[3];
Fu43[3]=Fu44[1]*Si34[3][1] + Fu44[2]*Si34[3][2];
Fu43[4]=l2*Fu44[3] + Fu44[4]*Si34[1][1] + Fu44[5]*Si34[1][2];
Fu43[5]=-Fu44[6] + l2*Fu44[1]*Si34[1][1] + l2*Fu44[2]*Si34[1][2];
Fu43[6]=Fu44[4]*Si34[3][1] + Fu44[5]*Si34[3][2];

Fu42[1]=Fu43[3];
Fu42[2]=Fu43[1]*Si23[2][1] + Fu43[2]*Si23[2][2];
Fu42[3]=Fu43[1]*Si23[3][1] + Fu43[2]*Si23[3][2];
Fu42[4]=Fu43[6] - l1*Fu43[1]*Si23[3][1] - l1*Fu43[2]*Si23[3][2];
Fu42[5]=Fu43[4]*Si23[2][1] + Fu43[5]*Si23[2][2];
Fu42[6]=l1*Fu43[3] + Fu43[4]*Si23[3][1] + Fu43[5]*Si23[3][2];

Fu41[1]=Fu42[1]*Si12[1][1] + Fu42[2]*Si12[1][2];
Fu41[2]=Fu42[3];
Fu41[3]=Fu42[1]*Si12[3][1] + Fu42[2]*Si12[3][2];
Fu41[4]=Fu42[4]*Si12[1][1] + Fu42[5]*Si12[1][2];
Fu41[5]=Fu42[6];
Fu41[6]=Fu42[4]*Si12[3][1] + Fu42[5]*Si12[3][2];


Fu33[1]=Jc3[1][3];
Fu33[2]=Jc3[2][3];
Fu33[3]=Jc3[3][3];
Fu33[4]=Jc3[4][3];
Fu33[5]=Jc3[5][3];
Fu33[6]=Jc3[6][3];

Fu32[1]=Fu33[3];
Fu32[2]=Fu33[1]*Si23[2][1] + Fu33[2]*Si23[2][2];
Fu32[3]=Fu33[1]*Si23[3][1] + Fu33[2]*Si23[3][2];
Fu32[4]=Fu33[6] - l1*Fu33[1]*Si23[3][1] - l1*Fu33[2]*Si23[3][2];
Fu32[5]=Fu33[4]*Si23[2][1] + Fu33[5]*Si23[2][2];
Fu32[6]=l1*Fu33[3] + Fu33[4]*Si23[3][1] + Fu33[5]*Si23[3][2];

Fu31[1]=Fu32[1]*Si12[1][1] + Fu32[2]*Si12[1][2];
Fu31[2]=Fu32[3];
Fu31[3]=Fu32[1]*Si12[3][1] + Fu32[2]*Si12[3][2];
Fu31[4]=Fu32[4]*Si12[1][1] + Fu32[5]*Si12[1][2];
Fu31[5]=Fu32[6];
Fu31[6]=Fu32[4]*Si12[3][1] + Fu32[5]*Si12[3][2];


Fu22[1]=Jc2[1][3];
Fu22[2]=Jc2[2][3];
Fu22[3]=Jc2[3][3];
Fu22[4]=Jc2[4][3];
Fu22[5]=Jc2[5][3];
Fu22[6]=Jc2[6][3];

Fu21[1]=Fu22[1]*Si12[1][1] + Fu22[2]*Si12[1][2];
Fu21[2]=Fu22[3];
Fu21[3]=Fu22[1]*Si12[3][1] + Fu22[2]*Si12[3][2];
Fu21[4]=Fu22[4]*Si12[1][1] + Fu22[5]*Si12[1][2];
Fu21[5]=Fu22[6];
Fu21[6]=Fu22[4]*Si12[3][1] + Fu22[5]*Si12[3][2];


Fu11[1]=Jc1[1][3];
Fu11[2]=Jc1[2][3];
Fu11[3]=Jc1[3][3];
Fu11[4]=Jc1[4][3];
Fu11[5]=Jc1[5][3];
Fu11[6]=Jc1[6][3];


/* off-diagonal elements of full inertia matrix */
K[1][1]=Si00[1][1]*(0.7071067811865475*Fu11[3] + Fu11[1]*Si01[1][1] + Fu11[2]*Si01[1][2]) + Si00[1][2]*(Fu11[1]*Si01[2][1] + Fu11[2]*Si01[2][2]) + Si00[1][3]*(0.7071067811865475*Fu11[3] + Fu11[1]*Si01[3][1] + Fu11[2]*Si01[3][2]);
K[1][2]=Si00[2][1]*(0.7071067811865475*Fu11[3] + Fu11[1]*Si01[1][1] + Fu11[2]*Si01[1][2]) + Si00[2][2]*(Fu11[1]*Si01[2][1] + Fu11[2]*Si01[2][2]) + Si00[2][3]*(0.7071067811865475*Fu11[3] + Fu11[1]*Si01[3][1] + Fu11[2]*Si01[3][2]);
K[1][3]=Si00[3][1]*(0.7071067811865475*Fu11[3] + Fu11[1]*Si01[1][1] + Fu11[2]*Si01[1][2]) + Si00[3][2]*(Fu11[1]*Si01[2][1] + Fu11[2]*Si01[2][2]) + Si00[3][3]*(0.7071067811865475*Fu11[3] + Fu11[1]*Si01[3][1] + Fu11[2]*Si01[3][2]);
K[1][4]=Si00[1][1]*(0.7071067811865475*Fu11[6] + Fu11[4]*Si01[1][1] + Fu11[5]*Si01[1][2] - (l0*Fu11[1]*Si01[2][1])/Sqrt(2) - (l0*Fu11[2]*Si01[2][2])/Sqrt(2)) + Si00[1][3]*(0.7071067811865475*Fu11[6] + (l0*Fu11[1]*Si01[2][1])/Sqrt(2) + (l0*Fu11[2]*Si01[2][2])/Sqrt(2) + Fu11[4]*Si01[3][1] + Fu11[5]*Si01[3][2]) + Si00[1][2]*(Fu11[4]*Si01[2][1] + Fu11[5]*Si01[2][2] + Fu11[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu11[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
K[1][5]=Si00[2][1]*(0.7071067811865475*Fu11[6] + Fu11[4]*Si01[1][1] + Fu11[5]*Si01[1][2] - (l0*Fu11[1]*Si01[2][1])/Sqrt(2) - (l0*Fu11[2]*Si01[2][2])/Sqrt(2)) + Si00[2][3]*(0.7071067811865475*Fu11[6] + (l0*Fu11[1]*Si01[2][1])/Sqrt(2) + (l0*Fu11[2]*Si01[2][2])/Sqrt(2) + Fu11[4]*Si01[3][1] + Fu11[5]*Si01[3][2]) + Si00[2][2]*(Fu11[4]*Si01[2][1] + Fu11[5]*Si01[2][2] + Fu11[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu11[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
K[1][6]=Si00[3][1]*(0.7071067811865475*Fu11[6] + Fu11[4]*Si01[1][1] + Fu11[5]*Si01[1][2] - (l0*Fu11[1]*Si01[2][1])/Sqrt(2) - (l0*Fu11[2]*Si01[2][2])/Sqrt(2)) + Si00[3][3]*(0.7071067811865475*Fu11[6] + (l0*Fu11[1]*Si01[2][1])/Sqrt(2) + (l0*Fu11[2]*Si01[2][2])/Sqrt(2) + Fu11[4]*Si01[3][1] + Fu11[5]*Si01[3][2]) + Si00[3][2]*(Fu11[4]*Si01[2][1] + Fu11[5]*Si01[2][2] + Fu11[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu11[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));

K[2][1]=Si00[1][1]*(0.7071067811865475*Fu21[3] + Fu21[1]*Si01[1][1] + Fu21[2]*Si01[1][2]) + Si00[1][2]*(Fu21[1]*Si01[2][1] + Fu21[2]*Si01[2][2]) + Si00[1][3]*(0.7071067811865475*Fu21[3] + Fu21[1]*Si01[3][1] + Fu21[2]*Si01[3][2]);
K[2][2]=Si00[2][1]*(0.7071067811865475*Fu21[3] + Fu21[1]*Si01[1][1] + Fu21[2]*Si01[1][2]) + Si00[2][2]*(Fu21[1]*Si01[2][1] + Fu21[2]*Si01[2][2]) + Si00[2][3]*(0.7071067811865475*Fu21[3] + Fu21[1]*Si01[3][1] + Fu21[2]*Si01[3][2]);
K[2][3]=Si00[3][1]*(0.7071067811865475*Fu21[3] + Fu21[1]*Si01[1][1] + Fu21[2]*Si01[1][2]) + Si00[3][2]*(Fu21[1]*Si01[2][1] + Fu21[2]*Si01[2][2]) + Si00[3][3]*(0.7071067811865475*Fu21[3] + Fu21[1]*Si01[3][1] + Fu21[2]*Si01[3][2]);
K[2][4]=Si00[1][1]*(0.7071067811865475*Fu21[6] + Fu21[4]*Si01[1][1] + Fu21[5]*Si01[1][2] - (l0*Fu21[1]*Si01[2][1])/Sqrt(2) - (l0*Fu21[2]*Si01[2][2])/Sqrt(2)) + Si00[1][3]*(0.7071067811865475*Fu21[6] + (l0*Fu21[1]*Si01[2][1])/Sqrt(2) + (l0*Fu21[2]*Si01[2][2])/Sqrt(2) + Fu21[4]*Si01[3][1] + Fu21[5]*Si01[3][2]) + Si00[1][2]*(Fu21[4]*Si01[2][1] + Fu21[5]*Si01[2][2] + Fu21[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu21[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
K[2][5]=Si00[2][1]*(0.7071067811865475*Fu21[6] + Fu21[4]*Si01[1][1] + Fu21[5]*Si01[1][2] - (l0*Fu21[1]*Si01[2][1])/Sqrt(2) - (l0*Fu21[2]*Si01[2][2])/Sqrt(2)) + Si00[2][3]*(0.7071067811865475*Fu21[6] + (l0*Fu21[1]*Si01[2][1])/Sqrt(2) + (l0*Fu21[2]*Si01[2][2])/Sqrt(2) + Fu21[4]*Si01[3][1] + Fu21[5]*Si01[3][2]) + Si00[2][2]*(Fu21[4]*Si01[2][1] + Fu21[5]*Si01[2][2] + Fu21[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu21[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
K[2][6]=Si00[3][1]*(0.7071067811865475*Fu21[6] + Fu21[4]*Si01[1][1] + Fu21[5]*Si01[1][2] - (l0*Fu21[1]*Si01[2][1])/Sqrt(2) - (l0*Fu21[2]*Si01[2][2])/Sqrt(2)) + Si00[3][3]*(0.7071067811865475*Fu21[6] + (l0*Fu21[1]*Si01[2][1])/Sqrt(2) + (l0*Fu21[2]*Si01[2][2])/Sqrt(2) + Fu21[4]*Si01[3][1] + Fu21[5]*Si01[3][2]) + Si00[3][2]*(Fu21[4]*Si01[2][1] + Fu21[5]*Si01[2][2] + Fu21[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu21[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));

K[3][1]=Si00[1][1]*(0.7071067811865475*Fu31[3] + Fu31[1]*Si01[1][1] + Fu31[2]*Si01[1][2]) + Si00[1][2]*(Fu31[1]*Si01[2][1] + Fu31[2]*Si01[2][2]) + Si00[1][3]*(0.7071067811865475*Fu31[3] + Fu31[1]*Si01[3][1] + Fu31[2]*Si01[3][2]);
K[3][2]=Si00[2][1]*(0.7071067811865475*Fu31[3] + Fu31[1]*Si01[1][1] + Fu31[2]*Si01[1][2]) + Si00[2][2]*(Fu31[1]*Si01[2][1] + Fu31[2]*Si01[2][2]) + Si00[2][3]*(0.7071067811865475*Fu31[3] + Fu31[1]*Si01[3][1] + Fu31[2]*Si01[3][2]);
K[3][3]=Si00[3][1]*(0.7071067811865475*Fu31[3] + Fu31[1]*Si01[1][1] + Fu31[2]*Si01[1][2]) + Si00[3][2]*(Fu31[1]*Si01[2][1] + Fu31[2]*Si01[2][2]) + Si00[3][3]*(0.7071067811865475*Fu31[3] + Fu31[1]*Si01[3][1] + Fu31[2]*Si01[3][2]);
K[3][4]=Si00[1][1]*(0.7071067811865475*Fu31[6] + Fu31[4]*Si01[1][1] + Fu31[5]*Si01[1][2] - (l0*Fu31[1]*Si01[2][1])/Sqrt(2) - (l0*Fu31[2]*Si01[2][2])/Sqrt(2)) + Si00[1][3]*(0.7071067811865475*Fu31[6] + (l0*Fu31[1]*Si01[2][1])/Sqrt(2) + (l0*Fu31[2]*Si01[2][2])/Sqrt(2) + Fu31[4]*Si01[3][1] + Fu31[5]*Si01[3][2]) + Si00[1][2]*(Fu31[4]*Si01[2][1] + Fu31[5]*Si01[2][2] + Fu31[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu31[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
K[3][5]=Si00[2][1]*(0.7071067811865475*Fu31[6] + Fu31[4]*Si01[1][1] + Fu31[5]*Si01[1][2] - (l0*Fu31[1]*Si01[2][1])/Sqrt(2) - (l0*Fu31[2]*Si01[2][2])/Sqrt(2)) + Si00[2][3]*(0.7071067811865475*Fu31[6] + (l0*Fu31[1]*Si01[2][1])/Sqrt(2) + (l0*Fu31[2]*Si01[2][2])/Sqrt(2) + Fu31[4]*Si01[3][1] + Fu31[5]*Si01[3][2]) + Si00[2][2]*(Fu31[4]*Si01[2][1] + Fu31[5]*Si01[2][2] + Fu31[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu31[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
K[3][6]=Si00[3][1]*(0.7071067811865475*Fu31[6] + Fu31[4]*Si01[1][1] + Fu31[5]*Si01[1][2] - (l0*Fu31[1]*Si01[2][1])/Sqrt(2) - (l0*Fu31[2]*Si01[2][2])/Sqrt(2)) + Si00[3][3]*(0.7071067811865475*Fu31[6] + (l0*Fu31[1]*Si01[2][1])/Sqrt(2) + (l0*Fu31[2]*Si01[2][2])/Sqrt(2) + Fu31[4]*Si01[3][1] + Fu31[5]*Si01[3][2]) + Si00[3][2]*(Fu31[4]*Si01[2][1] + Fu31[5]*Si01[2][2] + Fu31[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu31[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));

K[4][1]=Si00[1][1]*(0.7071067811865475*Fu41[3] + Fu41[1]*Si01[1][1] + Fu41[2]*Si01[1][2]) + Si00[1][2]*(Fu41[1]*Si01[2][1] + Fu41[2]*Si01[2][2]) + Si00[1][3]*(0.7071067811865475*Fu41[3] + Fu41[1]*Si01[3][1] + Fu41[2]*Si01[3][2]);
K[4][2]=Si00[2][1]*(0.7071067811865475*Fu41[3] + Fu41[1]*Si01[1][1] + Fu41[2]*Si01[1][2]) + Si00[2][2]*(Fu41[1]*Si01[2][1] + Fu41[2]*Si01[2][2]) + Si00[2][3]*(0.7071067811865475*Fu41[3] + Fu41[1]*Si01[3][1] + Fu41[2]*Si01[3][2]);
K[4][3]=Si00[3][1]*(0.7071067811865475*Fu41[3] + Fu41[1]*Si01[1][1] + Fu41[2]*Si01[1][2]) + Si00[3][2]*(Fu41[1]*Si01[2][1] + Fu41[2]*Si01[2][2]) + Si00[3][3]*(0.7071067811865475*Fu41[3] + Fu41[1]*Si01[3][1] + Fu41[2]*Si01[3][2]);
K[4][4]=Si00[1][1]*(0.7071067811865475*Fu41[6] + Fu41[4]*Si01[1][1] + Fu41[5]*Si01[1][2] - (l0*Fu41[1]*Si01[2][1])/Sqrt(2) - (l0*Fu41[2]*Si01[2][2])/Sqrt(2)) + Si00[1][3]*(0.7071067811865475*Fu41[6] + (l0*Fu41[1]*Si01[2][1])/Sqrt(2) + (l0*Fu41[2]*Si01[2][2])/Sqrt(2) + Fu41[4]*Si01[3][1] + Fu41[5]*Si01[3][2]) + Si00[1][2]*(Fu41[4]*Si01[2][1] + Fu41[5]*Si01[2][2] + Fu41[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu41[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
K[4][5]=Si00[2][1]*(0.7071067811865475*Fu41[6] + Fu41[4]*Si01[1][1] + Fu41[5]*Si01[1][2] - (l0*Fu41[1]*Si01[2][1])/Sqrt(2) - (l0*Fu41[2]*Si01[2][2])/Sqrt(2)) + Si00[2][3]*(0.7071067811865475*Fu41[6] + (l0*Fu41[1]*Si01[2][1])/Sqrt(2) + (l0*Fu41[2]*Si01[2][2])/Sqrt(2) + Fu41[4]*Si01[3][1] + Fu41[5]*Si01[3][2]) + Si00[2][2]*(Fu41[4]*Si01[2][1] + Fu41[5]*Si01[2][2] + Fu41[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu41[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
K[4][6]=Si00[3][1]*(0.7071067811865475*Fu41[6] + Fu41[4]*Si01[1][1] + Fu41[5]*Si01[1][2] - (l0*Fu41[1]*Si01[2][1])/Sqrt(2) - (l0*Fu41[2]*Si01[2][2])/Sqrt(2)) + Si00[3][3]*(0.7071067811865475*Fu41[6] + (l0*Fu41[1]*Si01[2][1])/Sqrt(2) + (l0*Fu41[2]*Si01[2][2])/Sqrt(2) + Fu41[4]*Si01[3][1] + Fu41[5]*Si01[3][2]) + Si00[3][2]*(Fu41[4]*Si01[2][1] + Fu41[5]*Si01[2][2] + Fu41[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu41[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));

K[5][1]=Si00[1][1]*(0.7071067811865475*Fu51[3] + Fu51[1]*Si01[1][1] + Fu51[2]*Si01[1][2]) + Si00[1][2]*(Fu51[1]*Si01[2][1] + Fu51[2]*Si01[2][2]) + Si00[1][3]*(0.7071067811865475*Fu51[3] + Fu51[1]*Si01[3][1] + Fu51[2]*Si01[3][2]);
K[5][2]=Si00[2][1]*(0.7071067811865475*Fu51[3] + Fu51[1]*Si01[1][1] + Fu51[2]*Si01[1][2]) + Si00[2][2]*(Fu51[1]*Si01[2][1] + Fu51[2]*Si01[2][2]) + Si00[2][3]*(0.7071067811865475*Fu51[3] + Fu51[1]*Si01[3][1] + Fu51[2]*Si01[3][2]);
K[5][3]=Si00[3][1]*(0.7071067811865475*Fu51[3] + Fu51[1]*Si01[1][1] + Fu51[2]*Si01[1][2]) + Si00[3][2]*(Fu51[1]*Si01[2][1] + Fu51[2]*Si01[2][2]) + Si00[3][3]*(0.7071067811865475*Fu51[3] + Fu51[1]*Si01[3][1] + Fu51[2]*Si01[3][2]);
K[5][4]=Si00[1][1]*(0.7071067811865475*Fu51[6] + Fu51[4]*Si01[1][1] + Fu51[5]*Si01[1][2] - (l0*Fu51[1]*Si01[2][1])/Sqrt(2) - (l0*Fu51[2]*Si01[2][2])/Sqrt(2)) + Si00[1][3]*(0.7071067811865475*Fu51[6] + (l0*Fu51[1]*Si01[2][1])/Sqrt(2) + (l0*Fu51[2]*Si01[2][2])/Sqrt(2) + Fu51[4]*Si01[3][1] + Fu51[5]*Si01[3][2]) + Si00[1][2]*(Fu51[4]*Si01[2][1] + Fu51[5]*Si01[2][2] + Fu51[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu51[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
K[5][5]=Si00[2][1]*(0.7071067811865475*Fu51[6] + Fu51[4]*Si01[1][1] + Fu51[5]*Si01[1][2] - (l0*Fu51[1]*Si01[2][1])/Sqrt(2) - (l0*Fu51[2]*Si01[2][2])/Sqrt(2)) + Si00[2][3]*(0.7071067811865475*Fu51[6] + (l0*Fu51[1]*Si01[2][1])/Sqrt(2) + (l0*Fu51[2]*Si01[2][2])/Sqrt(2) + Fu51[4]*Si01[3][1] + Fu51[5]*Si01[3][2]) + Si00[2][2]*(Fu51[4]*Si01[2][1] + Fu51[5]*Si01[2][2] + Fu51[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu51[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
K[5][6]=Si00[3][1]*(0.7071067811865475*Fu51[6] + Fu51[4]*Si01[1][1] + Fu51[5]*Si01[1][2] - (l0*Fu51[1]*Si01[2][1])/Sqrt(2) - (l0*Fu51[2]*Si01[2][2])/Sqrt(2)) + Si00[3][3]*(0.7071067811865475*Fu51[6] + (l0*Fu51[1]*Si01[2][1])/Sqrt(2) + (l0*Fu51[2]*Si01[2][2])/Sqrt(2) + Fu51[4]*Si01[3][1] + Fu51[5]*Si01[3][2]) + Si00[3][2]*(Fu51[4]*Si01[2][1] + Fu51[5]*Si01[2][2] + Fu51[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu51[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));

K[6][1]=Si00[1][1]*(0.7071067811865475*Fu61[3] + Fu61[1]*Si01[1][1] + Fu61[2]*Si01[1][2]) + Si00[1][2]*(Fu61[1]*Si01[2][1] + Fu61[2]*Si01[2][2]) + Si00[1][3]*(0.7071067811865475*Fu61[3] + Fu61[1]*Si01[3][1] + Fu61[2]*Si01[3][2]);
K[6][2]=Si00[2][1]*(0.7071067811865475*Fu61[3] + Fu61[1]*Si01[1][1] + Fu61[2]*Si01[1][2]) + Si00[2][2]*(Fu61[1]*Si01[2][1] + Fu61[2]*Si01[2][2]) + Si00[2][3]*(0.7071067811865475*Fu61[3] + Fu61[1]*Si01[3][1] + Fu61[2]*Si01[3][2]);
K[6][3]=Si00[3][1]*(0.7071067811865475*Fu61[3] + Fu61[1]*Si01[1][1] + Fu61[2]*Si01[1][2]) + Si00[3][2]*(Fu61[1]*Si01[2][1] + Fu61[2]*Si01[2][2]) + Si00[3][3]*(0.7071067811865475*Fu61[3] + Fu61[1]*Si01[3][1] + Fu61[2]*Si01[3][2]);
K[6][4]=Si00[1][1]*(0.7071067811865475*Fu61[6] + Fu61[4]*Si01[1][1] + Fu61[5]*Si01[1][2] - (l0*Fu61[1]*Si01[2][1])/Sqrt(2) - (l0*Fu61[2]*Si01[2][2])/Sqrt(2)) + Si00[1][3]*(0.7071067811865475*Fu61[6] + (l0*Fu61[1]*Si01[2][1])/Sqrt(2) + (l0*Fu61[2]*Si01[2][2])/Sqrt(2) + Fu61[4]*Si01[3][1] + Fu61[5]*Si01[3][2]) + Si00[1][2]*(Fu61[4]*Si01[2][1] + Fu61[5]*Si01[2][2] + Fu61[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu61[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
K[6][5]=Si00[2][1]*(0.7071067811865475*Fu61[6] + Fu61[4]*Si01[1][1] + Fu61[5]*Si01[1][2] - (l0*Fu61[1]*Si01[2][1])/Sqrt(2) - (l0*Fu61[2]*Si01[2][2])/Sqrt(2)) + Si00[2][3]*(0.7071067811865475*Fu61[6] + (l0*Fu61[1]*Si01[2][1])/Sqrt(2) + (l0*Fu61[2]*Si01[2][2])/Sqrt(2) + Fu61[4]*Si01[3][1] + Fu61[5]*Si01[3][2]) + Si00[2][2]*(Fu61[4]*Si01[2][1] + Fu61[5]*Si01[2][2] + Fu61[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu61[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
K[6][6]=Si00[3][1]*(0.7071067811865475*Fu61[6] + Fu61[4]*Si01[1][1] + Fu61[5]*Si01[1][2] - (l0*Fu61[1]*Si01[2][1])/Sqrt(2) - (l0*Fu61[2]*Si01[2][2])/Sqrt(2)) + Si00[3][3]*(0.7071067811865475*Fu61[6] + (l0*Fu61[1]*Si01[2][1])/Sqrt(2) + (l0*Fu61[2]*Si01[2][2])/Sqrt(2) + Fu61[4]*Si01[3][1] + Fu61[5]*Si01[3][2]) + Si00[3][2]*(Fu61[4]*Si01[2][1] + Fu61[5]*Si01[2][2] + Fu61[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu61[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));

K[7][1]=Si00[1][1]*(0.7071067811865475*Fu71[3] + Fu71[1]*Si01[1][1] + Fu71[2]*Si01[1][2]) + Si00[1][2]*(Fu71[1]*Si01[2][1] + Fu71[2]*Si01[2][2]) + Si00[1][3]*(0.7071067811865475*Fu71[3] + Fu71[1]*Si01[3][1] + Fu71[2]*Si01[3][2]);
K[7][2]=Si00[2][1]*(0.7071067811865475*Fu71[3] + Fu71[1]*Si01[1][1] + Fu71[2]*Si01[1][2]) + Si00[2][2]*(Fu71[1]*Si01[2][1] + Fu71[2]*Si01[2][2]) + Si00[2][3]*(0.7071067811865475*Fu71[3] + Fu71[1]*Si01[3][1] + Fu71[2]*Si01[3][2]);
K[7][3]=Si00[3][1]*(0.7071067811865475*Fu71[3] + Fu71[1]*Si01[1][1] + Fu71[2]*Si01[1][2]) + Si00[3][2]*(Fu71[1]*Si01[2][1] + Fu71[2]*Si01[2][2]) + Si00[3][3]*(0.7071067811865475*Fu71[3] + Fu71[1]*Si01[3][1] + Fu71[2]*Si01[3][2]);
K[7][4]=Si00[1][1]*(0.7071067811865475*Fu71[6] + Fu71[4]*Si01[1][1] + Fu71[5]*Si01[1][2] - (l0*Fu71[1]*Si01[2][1])/Sqrt(2) - (l0*Fu71[2]*Si01[2][2])/Sqrt(2)) + Si00[1][3]*(0.7071067811865475*Fu71[6] + (l0*Fu71[1]*Si01[2][1])/Sqrt(2) + (l0*Fu71[2]*Si01[2][2])/Sqrt(2) + Fu71[4]*Si01[3][1] + Fu71[5]*Si01[3][2]) + Si00[1][2]*(Fu71[4]*Si01[2][1] + Fu71[5]*Si01[2][2] + Fu71[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu71[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
K[7][5]=Si00[2][1]*(0.7071067811865475*Fu71[6] + Fu71[4]*Si01[1][1] + Fu71[5]*Si01[1][2] - (l0*Fu71[1]*Si01[2][1])/Sqrt(2) - (l0*Fu71[2]*Si01[2][2])/Sqrt(2)) + Si00[2][3]*(0.7071067811865475*Fu71[6] + (l0*Fu71[1]*Si01[2][1])/Sqrt(2) + (l0*Fu71[2]*Si01[2][2])/Sqrt(2) + Fu71[4]*Si01[3][1] + Fu71[5]*Si01[3][2]) + Si00[2][2]*(Fu71[4]*Si01[2][1] + Fu71[5]*Si01[2][2] + Fu71[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu71[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
K[7][6]=Si00[3][1]*(0.7071067811865475*Fu71[6] + Fu71[4]*Si01[1][1] + Fu71[5]*Si01[1][2] - (l0*Fu71[1]*Si01[2][1])/Sqrt(2) - (l0*Fu71[2]*Si01[2][2])/Sqrt(2)) + Si00[3][3]*(0.7071067811865475*Fu71[6] + (l0*Fu71[1]*Si01[2][1])/Sqrt(2) + (l0*Fu71[2]*Si01[2][2])/Sqrt(2) + Fu71[4]*Si01[3][1] + Fu71[5]*Si01[3][2]) + Si00[3][2]*(Fu71[4]*Si01[2][1] + Fu71[5]*Si01[2][2] + Fu71[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu71[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));

K[8][1]=0;
K[8][2]=0;
K[8][3]=0;
K[8][4]=0;
K[8][5]=0;
K[8][6]=0;

K[9][1]=Si00[1][1]*(0.7071067811865475*Fu91[3] + Fu91[1]*Si01[1][1] + Fu91[2]*Si01[1][2]) + Si00[1][2]*(Fu91[1]*Si01[2][1] + Fu91[2]*Si01[2][2]) + Si00[1][3]*(0.7071067811865475*Fu91[3] + Fu91[1]*Si01[3][1] + Fu91[2]*Si01[3][2]);
K[9][2]=Si00[2][1]*(0.7071067811865475*Fu91[3] + Fu91[1]*Si01[1][1] + Fu91[2]*Si01[1][2]) + Si00[2][2]*(Fu91[1]*Si01[2][1] + Fu91[2]*Si01[2][2]) + Si00[2][3]*(0.7071067811865475*Fu91[3] + Fu91[1]*Si01[3][1] + Fu91[2]*Si01[3][2]);
K[9][3]=Si00[3][1]*(0.7071067811865475*Fu91[3] + Fu91[1]*Si01[1][1] + Fu91[2]*Si01[1][2]) + Si00[3][2]*(Fu91[1]*Si01[2][1] + Fu91[2]*Si01[2][2]) + Si00[3][3]*(0.7071067811865475*Fu91[3] + Fu91[1]*Si01[3][1] + Fu91[2]*Si01[3][2]);
K[9][4]=Si00[1][1]*(0.7071067811865475*Fu91[6] + Fu91[4]*Si01[1][1] + Fu91[5]*Si01[1][2] - (l0*Fu91[1]*Si01[2][1])/Sqrt(2) - (l0*Fu91[2]*Si01[2][2])/Sqrt(2)) + Si00[1][3]*(0.7071067811865475*Fu91[6] + (l0*Fu91[1]*Si01[2][1])/Sqrt(2) + (l0*Fu91[2]*Si01[2][2])/Sqrt(2) + Fu91[4]*Si01[3][1] + Fu91[5]*Si01[3][2]) + Si00[1][2]*(Fu91[4]*Si01[2][1] + Fu91[5]*Si01[2][2] + Fu91[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu91[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
K[9][5]=Si00[2][1]*(0.7071067811865475*Fu91[6] + Fu91[4]*Si01[1][1] + Fu91[5]*Si01[1][2] - (l0*Fu91[1]*Si01[2][1])/Sqrt(2) - (l0*Fu91[2]*Si01[2][2])/Sqrt(2)) + Si00[2][3]*(0.7071067811865475*Fu91[6] + (l0*Fu91[1]*Si01[2][1])/Sqrt(2) + (l0*Fu91[2]*Si01[2][2])/Sqrt(2) + Fu91[4]*Si01[3][1] + Fu91[5]*Si01[3][2]) + Si00[2][2]*(Fu91[4]*Si01[2][1] + Fu91[5]*Si01[2][2] + Fu91[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu91[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
K[9][6]=Si00[3][1]*(0.7071067811865475*Fu91[6] + Fu91[4]*Si01[1][1] + Fu91[5]*Si01[1][2] - (l0*Fu91[1]*Si01[2][1])/Sqrt(2) - (l0*Fu91[2]*Si01[2][2])/Sqrt(2)) + Si00[3][3]*(0.7071067811865475*Fu91[6] + (l0*Fu91[1]*Si01[2][1])/Sqrt(2) + (l0*Fu91[2]*Si01[2][2])/Sqrt(2) + Fu91[4]*Si01[3][1] + Fu91[5]*Si01[3][2]) + Si00[3][2]*(Fu91[4]*Si01[2][1] + Fu91[5]*Si01[2][2] + Fu91[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu91[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));

K[10][1]=Si00[1][1]*(0.7071067811865475*Fu101[3] + Fu101[1]*Si01[1][1] + Fu101[2]*Si01[1][2]) + Si00[1][2]*(Fu101[1]*Si01[2][1] + Fu101[2]*Si01[2][2]) + Si00[1][3]*(0.7071067811865475*Fu101[3] + Fu101[1]*Si01[3][1] + Fu101[2]*Si01[3][2]);
K[10][2]=Si00[2][1]*(0.7071067811865475*Fu101[3] + Fu101[1]*Si01[1][1] + Fu101[2]*Si01[1][2]) + Si00[2][2]*(Fu101[1]*Si01[2][1] + Fu101[2]*Si01[2][2]) + Si00[2][3]*(0.7071067811865475*Fu101[3] + Fu101[1]*Si01[3][1] + Fu101[2]*Si01[3][2]);
K[10][3]=Si00[3][1]*(0.7071067811865475*Fu101[3] + Fu101[1]*Si01[1][1] + Fu101[2]*Si01[1][2]) + Si00[3][2]*(Fu101[1]*Si01[2][1] + Fu101[2]*Si01[2][2]) + Si00[3][3]*(0.7071067811865475*Fu101[3] + Fu101[1]*Si01[3][1] + Fu101[2]*Si01[3][2]);
K[10][4]=Si00[1][1]*(0.7071067811865475*Fu101[6] + Fu101[4]*Si01[1][1] + Fu101[5]*Si01[1][2] - (l0*Fu101[1]*Si01[2][1])/Sqrt(2) - (l0*Fu101[2]*Si01[2][2])/Sqrt(2)) + Si00[1][3]*(0.7071067811865475*Fu101[6] + (l0*Fu101[1]*Si01[2][1])/Sqrt(2) + (l0*Fu101[2]*Si01[2][2])/Sqrt(2) + Fu101[4]*Si01[3][1] + Fu101[5]*Si01[3][2]) + Si00[1][2]*(Fu101[4]*Si01[2][1] + Fu101[5]*Si01[2][2] + Fu101[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu101[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
K[10][5]=Si00[2][1]*(0.7071067811865475*Fu101[6] + Fu101[4]*Si01[1][1] + Fu101[5]*Si01[1][2] - (l0*Fu101[1]*Si01[2][1])/Sqrt(2) - (l0*Fu101[2]*Si01[2][2])/Sqrt(2)) + Si00[2][3]*(0.7071067811865475*Fu101[6] + (l0*Fu101[1]*Si01[2][1])/Sqrt(2) + (l0*Fu101[2]*Si01[2][2])/Sqrt(2) + Fu101[4]*Si01[3][1] + Fu101[5]*Si01[3][2]) + Si00[2][2]*(Fu101[4]*Si01[2][1] + Fu101[5]*Si01[2][2] + Fu101[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu101[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
K[10][6]=Si00[3][1]*(0.7071067811865475*Fu101[6] + Fu101[4]*Si01[1][1] + Fu101[5]*Si01[1][2] - (l0*Fu101[1]*Si01[2][1])/Sqrt(2) - (l0*Fu101[2]*Si01[2][2])/Sqrt(2)) + Si00[3][3]*(0.7071067811865475*Fu101[6] + (l0*Fu101[1]*Si01[2][1])/Sqrt(2) + (l0*Fu101[2]*Si01[2][2])/Sqrt(2) + Fu101[4]*Si01[3][1] + Fu101[5]*Si01[3][2]) + Si00[3][2]*(Fu101[4]*Si01[2][1] + Fu101[5]*Si01[2][2] + Fu101[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu101[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));

K[11][1]=0;
K[11][2]=0;
K[11][3]=0;
K[11][4]=0;
K[11][5]=0;
K[11][6]=0;

K[12][1]=Si00[1][1]*(0.7071067811865475*Fu121[3] + Fu121[1]*Si01[1][1] + Fu121[2]*Si01[1][2]) + Si00[1][2]*(Fu121[1]*Si01[2][1] + Fu121[2]*Si01[2][2]) + Si00[1][3]*(0.7071067811865475*Fu121[3] + Fu121[1]*Si01[3][1] + Fu121[2]*Si01[3][2]);
K[12][2]=Si00[2][1]*(0.7071067811865475*Fu121[3] + Fu121[1]*Si01[1][1] + Fu121[2]*Si01[1][2]) + Si00[2][2]*(Fu121[1]*Si01[2][1] + Fu121[2]*Si01[2][2]) + Si00[2][3]*(0.7071067811865475*Fu121[3] + Fu121[1]*Si01[3][1] + Fu121[2]*Si01[3][2]);
K[12][3]=Si00[3][1]*(0.7071067811865475*Fu121[3] + Fu121[1]*Si01[1][1] + Fu121[2]*Si01[1][2]) + Si00[3][2]*(Fu121[1]*Si01[2][1] + Fu121[2]*Si01[2][2]) + Si00[3][3]*(0.7071067811865475*Fu121[3] + Fu121[1]*Si01[3][1] + Fu121[2]*Si01[3][2]);
K[12][4]=Si00[1][1]*(0.7071067811865475*Fu121[6] + Fu121[4]*Si01[1][1] + Fu121[5]*Si01[1][2] - (l0*Fu121[1]*Si01[2][1])/Sqrt(2) - (l0*Fu121[2]*Si01[2][2])/Sqrt(2)) + Si00[1][3]*(0.7071067811865475*Fu121[6] + (l0*Fu121[1]*Si01[2][1])/Sqrt(2) + (l0*Fu121[2]*Si01[2][2])/Sqrt(2) + Fu121[4]*Si01[3][1] + Fu121[5]*Si01[3][2]) + Si00[1][2]*(Fu121[4]*Si01[2][1] + Fu121[5]*Si01[2][2] + Fu121[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu121[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
K[12][5]=Si00[2][1]*(0.7071067811865475*Fu121[6] + Fu121[4]*Si01[1][1] + Fu121[5]*Si01[1][2] - (l0*Fu121[1]*Si01[2][1])/Sqrt(2) - (l0*Fu121[2]*Si01[2][2])/Sqrt(2)) + Si00[2][3]*(0.7071067811865475*Fu121[6] + (l0*Fu121[1]*Si01[2][1])/Sqrt(2) + (l0*Fu121[2]*Si01[2][2])/Sqrt(2) + Fu121[4]*Si01[3][1] + Fu121[5]*Si01[3][2]) + Si00[2][2]*(Fu121[4]*Si01[2][1] + Fu121[5]*Si01[2][2] + Fu121[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu121[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));
K[12][6]=Si00[3][1]*(0.7071067811865475*Fu121[6] + Fu121[4]*Si01[1][1] + Fu121[5]*Si01[1][2] - (l0*Fu121[1]*Si01[2][1])/Sqrt(2) - (l0*Fu121[2]*Si01[2][2])/Sqrt(2)) + Si00[3][3]*(0.7071067811865475*Fu121[6] + (l0*Fu121[1]*Si01[2][1])/Sqrt(2) + (l0*Fu121[2]*Si01[2][2])/Sqrt(2) + Fu121[4]*Si01[3][1] + Fu121[5]*Si01[3][2]) + Si00[3][2]*(Fu121[4]*Si01[2][1] + Fu121[5]*Si01[2][2] + Fu121[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + Fu121[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2)));

K[13][1]=0;
K[13][2]=0;
K[13][3]=0;
K[13][4]=0;
K[13][5]=0;
K[13][6]=0;



}


void
masterfunc27(void)
      {
/* elements of inertia matrix */
H[1][1]=Fu11[6];
H[1][2]=0;
H[1][3]=0;
H[1][4]=0;
H[1][5]=0;
H[1][6]=0;
H[1][7]=0;
H[1][8]=0;
H[1][9]=0;
H[1][10]=0;
H[1][11]=0;
H[1][12]=0;
H[1][13]=0;

H[2][1]=Fu21[6];
H[2][2]=Fu22[6];
H[2][3]=0;
H[2][4]=0;
H[2][5]=0;
H[2][6]=0;
H[2][7]=0;
H[2][8]=0;
H[2][9]=0;
H[2][10]=0;
H[2][11]=0;
H[2][12]=0;
H[2][13]=0;

H[3][1]=Fu31[6];
H[3][2]=Fu32[6];
H[3][3]=Fu33[6];
H[3][4]=0;
H[3][5]=0;
H[3][6]=0;
H[3][7]=0;
H[3][8]=0;
H[3][9]=0;
H[3][10]=0;
H[3][11]=0;
H[3][12]=0;
H[3][13]=0;

H[4][1]=Fu41[6];
H[4][2]=Fu42[6];
H[4][3]=Fu43[6];
H[4][4]=Fu44[6];
H[4][5]=0;
H[4][6]=0;
H[4][7]=0;
H[4][8]=0;
H[4][9]=0;
H[4][10]=0;
H[4][11]=0;
H[4][12]=0;
H[4][13]=0;

H[5][1]=Fu51[6];
H[5][2]=Fu52[6];
H[5][3]=Fu53[6];
H[5][4]=Fu54[6];
H[5][5]=Fu55[6];
H[5][6]=0;
H[5][7]=0;
H[5][8]=0;
H[5][9]=0;
H[5][10]=0;
H[5][11]=0;
H[5][12]=0;
H[5][13]=0;

H[6][1]=Fu61[6];
H[6][2]=Fu62[6];
H[6][3]=Fu63[6];
H[6][4]=Fu64[6];
H[6][5]=Fu65[6];
H[6][6]=Fu66[6];
H[6][7]=0;
H[6][8]=0;
H[6][9]=0;
H[6][10]=0;
H[6][11]=0;
H[6][12]=0;
H[6][13]=0;

H[7][1]=Fu71[6];
H[7][2]=Fu72[6];
H[7][3]=Fu73[6];
H[7][4]=Fu74[6];
H[7][5]=Fu75[6];
H[7][6]=Fu76[6];
H[7][7]=Fu77[6];
H[7][8]=0;
H[7][9]=0;
H[7][10]=0;
H[7][11]=0;
H[7][12]=0;
H[7][13]=0;

H[8][1]=0;
H[8][2]=0;
H[8][3]=0;
H[8][4]=0;
H[8][5]=0;
H[8][6]=0;
H[8][7]=0;
H[8][8]=1;
H[8][9]=0;
H[8][10]=0;
H[8][11]=0;
H[8][12]=0;
H[8][13]=0;

H[9][1]=Fu91[6];
H[9][2]=Fu92[6];
H[9][3]=Fu93[6];
H[9][4]=Fu94[6];
H[9][5]=Fu95[6];
H[9][6]=Fu96[6];
H[9][7]=Fu97[6];
H[9][8]=0;
H[9][9]=Fu99[6];
H[9][10]=0;
H[9][11]=0;
H[9][12]=0;
H[9][13]=0;

H[10][1]=Fu101[6];
H[10][2]=Fu102[6];
H[10][3]=Fu103[6];
H[10][4]=Fu104[6];
H[10][5]=Fu105[6];
H[10][6]=Fu106[6];
H[10][7]=Fu107[6];
H[10][8]=0;
H[10][9]=Fu109[6];
H[10][10]=Fu1010[6];
H[10][11]=0;
H[10][12]=0;
H[10][13]=0;

H[11][1]=0;
H[11][2]=0;
H[11][3]=0;
H[11][4]=0;
H[11][5]=0;
H[11][6]=0;
H[11][7]=0;
H[11][8]=0;
H[11][9]=0;
H[11][10]=0;
H[11][11]=1;
H[11][12]=0;
H[11][13]=0;

H[12][1]=Fu121[6];
H[12][2]=Fu122[6];
H[12][3]=Fu123[6];
H[12][4]=Fu124[6];
H[12][5]=Fu125[6];
H[12][6]=Fu126[6];
H[12][7]=Fu127[6];
H[12][8]=0;
H[12][9]=0;
H[12][10]=0;
H[12][11]=0;
H[12][12]=Fu1212[6];
H[12][13]=0;

H[13][1]=0;
H[13][2]=0;
H[13][3]=0;
H[13][4]=0;
H[13][5]=0;
H[13][6]=0;
H[13][7]=0;
H[13][8]=0;
H[13][9]=0;
H[13][10]=0;
H[13][11]=0;
H[13][12]=0;
H[13][13]=1;



}


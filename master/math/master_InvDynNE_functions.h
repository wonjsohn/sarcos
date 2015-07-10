
void
master_InvDynNEfunc1(void)
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
master_InvDynNEfunc2(void)
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
master_InvDynNEfunc3(void)
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
master_InvDynNEfunc4(void)
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
master_InvDynNEfunc5(void)
     {
/* acceleration vectors */
a0[1]=baseo[0].add[1]*S00[1][1] + baseo[0].add[2]*S00[1][2] + baseo[0].add[3]*S00[1][3];
a0[2]=baseo[0].add[1]*S00[2][1] + baseo[0].add[2]*S00[2][2] + baseo[0].add[3]*S00[2][3];
a0[3]=baseo[0].add[1]*S00[3][1] + baseo[0].add[2]*S00[3][2] + baseo[0].add[3]*S00[3][3];
a0[4]=basec[0].xdd[1]*S00[1][1] + basec[0].xdd[2]*S00[1][2] + (gravity + basec[0].xdd[3])*S00[1][3];
a0[5]=basec[0].xdd[1]*S00[2][1] + basec[0].xdd[2]*S00[2][2] + (gravity + basec[0].xdd[3])*S00[2][3];
a0[6]=basec[0].xdd[1]*S00[3][1] + basec[0].xdd[2]*S00[3][2] + (gravity + basec[0].xdd[3])*S00[3][3];

a1[1]=state[1].thd*v1[2] + a0[1]*S10[1][1] + a0[2]*S10[1][2] + a0[3]*S10[1][3];
a1[2]=-(state[1].thd*v1[1]) + a0[1]*S10[2][1] + a0[2]*S10[2][2] + a0[3]*S10[2][3];
a1[3]=state[1].thdd + 0.7071067811865475*a0[1] + 0.7071067811865475*a0[3];
a1[4]=state[1].thd*v1[5] + a0[4]*S10[1][1] - (l0*a0[1]*S10[1][2])/Sqrt(2) + (l0*a0[3]*S10[1][2])/Sqrt(2) + a0[5]*S10[1][2] + a0[6]*S10[1][3] + a0[2]*((l0*S10[1][1])/Sqrt(2) - (l0*S10[1][3])/Sqrt(2));
a1[5]=-(state[1].thd*v1[4]) + a0[4]*S10[2][1] - (l0*a0[1]*S10[2][2])/Sqrt(2) + (l0*a0[3]*S10[2][2])/Sqrt(2) + a0[5]*S10[2][2] + a0[6]*S10[2][3] + a0[2]*((l0*S10[2][1])/Sqrt(2) - (l0*S10[2][3])/Sqrt(2));
a1[6]=0.7071067811865475*a0[4] + 0.7071067811865475*a0[6];

a2[1]=state[2].thd*v2[2] + a1[1]*S21[1][1] + a1[3]*S21[1][3];
a2[2]=-(state[2].thd*v2[1]) + a1[1]*S21[2][1] + a1[3]*S21[2][3];
a2[3]=state[2].thdd + a1[2];
a2[4]=state[2].thd*v2[5] + a1[4]*S21[1][1] + a1[6]*S21[1][3];
a2[5]=-(state[2].thd*v2[4]) + a1[4]*S21[2][1] + a1[6]*S21[2][3];
a2[6]=a1[5];

a3[1]=state[3].thd*v3[2] + a2[2]*S32[1][2] + a2[3]*S32[1][3];
a3[2]=-(state[3].thd*v3[1]) + a2[2]*S32[2][2] + a2[3]*S32[2][3];
a3[3]=state[3].thdd + a2[1];
a3[4]=state[3].thd*v3[5] + a2[5]*S32[1][2] - l1*a2[1]*S32[1][3] + a2[6]*S32[1][3];
a3[5]=-(state[3].thd*v3[4]) + a2[5]*S32[2][2] - l1*a2[1]*S32[2][3] + a2[6]*S32[2][3];
a3[6]=l1*a2[3] + a2[4];

a4[1]=state[4].thd*v4[2] + a3[1]*S43[1][1] + a3[3]*S43[1][3];
a4[2]=-(state[4].thd*v4[1]) + a3[1]*S43[2][1] + a3[3]*S43[2][3];
a4[3]=state[4].thdd - a3[2];
a4[4]=state[4].thd*v4[5] + l2*a3[2]*S43[1][1] + a3[4]*S43[1][1] + a3[6]*S43[1][3];
a4[5]=-(state[4].thd*v4[4]) + l2*a3[2]*S43[2][1] + a3[4]*S43[2][1] + a3[6]*S43[2][3];
a4[6]=l2*a3[1] - a3[5];

a5[1]=state[5].thd*v5[2] + a4[2]*S54[1][2] + a4[3]*S54[1][3];
a5[2]=-(state[5].thd*v5[1]) + a4[2]*S54[2][2] + a4[3]*S54[2][3];
a5[3]=state[5].thdd - a4[1];
a5[4]=state[5].thd*v5[5] + l3*a4[1]*S54[1][2] + a4[5]*S54[1][2] + a4[6]*S54[1][3];
a5[5]=-(state[5].thd*v5[4]) + l3*a4[1]*S54[2][2] + a4[5]*S54[2][2] + a4[6]*S54[2][3];
a5[6]=l3*a4[2] - a4[4];

a6[1]=state[6].thd*v6[2] + a5[1]*S65[1][1] + a5[3]*S65[1][3];
a6[2]=-(state[6].thd*v6[1]) + a5[1]*S65[2][1] + a5[3]*S65[2][3];
a6[3]=state[6].thdd + a5[2];
a6[4]=state[6].thd*v6[5] + l4*a5[2]*S65[1][1] + a5[4]*S65[1][1] + a5[6]*S65[1][3];
a6[5]=-(state[6].thd*v6[4]) + l4*a5[2]*S65[2][1] + a5[4]*S65[2][1] + a5[6]*S65[2][3];
a6[6]=-(l4*a5[1]) + a5[5];

a7[1]=state[7].thd*v7[2] + a6[2]*S76[1][2] + a6[3]*S76[1][3];
a7[2]=-(state[7].thd*v7[1]) + a6[2]*S76[2][2] + a6[3]*S76[2][3];
a7[3]=state[7].thdd + a6[1];
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
a9[3]=state[8].thdd - a7[1];
a9[4]=state[8].thd*v9[5] - l7z*a7[1]*S97[1][2] - l6x*a7[3]*S97[1][2] + a7[5]*S97[1][2] + l6x*a7[2]*S97[1][3] + a7[6]*S97[1][3];
a9[5]=-(state[8].thd*v9[4]) - l7z*a7[1]*S97[2][2] - l6x*a7[3]*S97[2][2] + a7[5]*S97[2][2] + l6x*a7[2]*S97[2][3] + a7[6]*S97[2][3];
a9[6]=-(l7z*a7[2]) - a7[4];

a10[1]=state[9].thd*v10[2] + a9[2]*S109[1][2] + a9[3]*S109[1][3];
a10[2]=-(state[9].thd*v10[1]) + a9[2]*S109[2][2] + a9[3]*S109[2][3];
a10[3]=state[9].thdd + a9[1];
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
a12[3]=state[10].thdd + a7[3];
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
master_InvDynNEfunc6(void)
     {
/* net forces and external forces for each joint */
fnet0[1]=links[0].m*a0[4] - a0[3]*links[0].mcm[2] + a0[2]*links[0].mcm[3] - links[0].mcm[1]*Power(v0[2],2) - links[0].mcm[1]*Power(v0[3],2) + v0[1]*(links[0].mcm[2]*v0[2] + links[0].mcm[3]*v0[3]) - links[0].m*v0[3]*v0[5] + links[0].m*v0[2]*v0[6];
fnet0[2]=links[0].m*a0[5] + a0[3]*links[0].mcm[1] - a0[1]*links[0].mcm[3] - links[0].mcm[2]*Power(v0[1],2) - links[0].mcm[2]*Power(v0[3],2) + v0[2]*(links[0].mcm[1]*v0[1] + links[0].mcm[3]*v0[3]) + links[0].m*v0[3]*v0[4] - links[0].m*v0[1]*v0[6];
fnet0[3]=links[0].m*a0[6] - a0[2]*links[0].mcm[1] + a0[1]*links[0].mcm[2] - links[0].mcm[3]*Power(v0[1],2) - links[0].mcm[3]*Power(v0[2],2) + (links[0].mcm[1]*v0[1] + links[0].mcm[2]*v0[2])*v0[3] - links[0].m*v0[2]*v0[4] + links[0].m*v0[1]*v0[5];
fnet0[4]=a0[6]*links[0].mcm[2] - a0[5]*links[0].mcm[3] + (-(links[0].mcm[2]*v0[2]) - links[0].mcm[3]*v0[3])*v0[4] + (links[0].mcm[1]*v0[3] + links[0].m*v0[5])*v0[6] + v0[5]*(links[0].mcm[1]*v0[2] - links[0].m*v0[6]) + a0[1]*links[0].inertia[1][1] + a0[2]*links[0].inertia[1][2] + a0[3]*links[0].inertia[1][3] + v0[1]*(links[0].mcm[2]*v0[5] + links[0].mcm[3]*v0[6] - v0[3]*links[0].inertia[1][2] + v0[2]*links[0].inertia[1][3]) + v0[2]*(-(links[0].mcm[1]*v0[5]) - v0[3]*links[0].inertia[2][2] + v0[2]*links[0].inertia[2][3]) + v0[3]*(-(links[0].mcm[1]*v0[6]) - v0[3]*links[0].inertia[2][3] + v0[2]*links[0].inertia[3][3]);
fnet0[5]=-(a0[6]*links[0].mcm[1]) + a0[4]*links[0].mcm[3] + (-(links[0].mcm[1]*v0[1]) - links[0].mcm[3]*v0[3])*v0[5] + (links[0].mcm[2]*v0[3] - links[0].m*v0[4])*v0[6] + v0[4]*(links[0].mcm[2]*v0[1] + links[0].m*v0[6]) + a0[1]*links[0].inertia[1][2] + v0[1]*(-(links[0].mcm[2]*v0[4]) + v0[3]*links[0].inertia[1][1] - v0[1]*links[0].inertia[1][3]) + a0[2]*links[0].inertia[2][2] + a0[3]*links[0].inertia[2][3] + v0[2]*(links[0].mcm[1]*v0[4] + links[0].mcm[3]*v0[6] + v0[3]*links[0].inertia[1][2] - v0[1]*links[0].inertia[2][3]) + v0[3]*(-(links[0].mcm[2]*v0[6]) + v0[3]*links[0].inertia[1][3] - v0[1]*links[0].inertia[3][3]);
fnet0[6]=a0[5]*links[0].mcm[1] - a0[4]*links[0].mcm[2] + (links[0].mcm[3]*v0[2] + links[0].m*v0[4])*v0[5] + v0[4]*(links[0].mcm[3]*v0[1] - links[0].m*v0[5]) + (-(links[0].mcm[1]*v0[1]) - links[0].mcm[2]*v0[2])*v0[6] + v0[1]*(-(links[0].mcm[3]*v0[4]) - v0[2]*links[0].inertia[1][1] + v0[1]*links[0].inertia[1][2]) + a0[1]*links[0].inertia[1][3] + v0[2]*(-(links[0].mcm[3]*v0[5]) - v0[2]*links[0].inertia[1][2] + v0[1]*links[0].inertia[2][2]) + a0[2]*links[0].inertia[2][3] + v0[3]*(links[0].mcm[1]*v0[4] + links[0].mcm[2]*v0[5] - v0[2]*links[0].inertia[1][3] + v0[1]*links[0].inertia[2][3]) + a0[3]*links[0].inertia[3][3];

fnet1[1]=links[1].m*a1[4] - a1[3]*links[1].mcm[2] + a1[2]*links[1].mcm[3] - links[1].mcm[1]*Power(v1[2],2) - links[1].mcm[1]*Power(v1[3],2) + v1[1]*(links[1].mcm[2]*v1[2] + links[1].mcm[3]*v1[3]) - links[1].m*v1[3]*v1[5] + links[1].m*v1[2]*v1[6];
fnet1[2]=links[1].m*a1[5] + a1[3]*links[1].mcm[1] - a1[1]*links[1].mcm[3] - links[1].mcm[2]*Power(v1[1],2) - links[1].mcm[2]*Power(v1[3],2) + v1[2]*(links[1].mcm[1]*v1[1] + links[1].mcm[3]*v1[3]) + links[1].m*v1[3]*v1[4] - links[1].m*v1[1]*v1[6];
fnet1[3]=links[1].m*a1[6] - a1[2]*links[1].mcm[1] + a1[1]*links[1].mcm[2] - links[1].mcm[3]*Power(v1[1],2) - links[1].mcm[3]*Power(v1[2],2) + (links[1].mcm[1]*v1[1] + links[1].mcm[2]*v1[2])*v1[3] - links[1].m*v1[2]*v1[4] + links[1].m*v1[1]*v1[5];
fnet1[4]=a1[6]*links[1].mcm[2] - a1[5]*links[1].mcm[3] + (-(links[1].mcm[2]*v1[2]) - links[1].mcm[3]*v1[3])*v1[4] + (links[1].mcm[1]*v1[3] + links[1].m*v1[5])*v1[6] + v1[5]*(links[1].mcm[1]*v1[2] - links[1].m*v1[6]) + a1[1]*links[1].inertia[1][1] + a1[2]*links[1].inertia[1][2] + a1[3]*links[1].inertia[1][3] + v1[1]*(links[1].mcm[2]*v1[5] + links[1].mcm[3]*v1[6] - v1[3]*links[1].inertia[1][2] + v1[2]*links[1].inertia[1][3]) + v1[2]*(-(links[1].mcm[1]*v1[5]) - v1[3]*links[1].inertia[2][2] + v1[2]*links[1].inertia[2][3]) + v1[3]*(-(links[1].mcm[1]*v1[6]) - v1[3]*links[1].inertia[2][3] + v1[2]*links[1].inertia[3][3]);
fnet1[5]=-(a1[6]*links[1].mcm[1]) + a1[4]*links[1].mcm[3] + (-(links[1].mcm[1]*v1[1]) - links[1].mcm[3]*v1[3])*v1[5] + (links[1].mcm[2]*v1[3] - links[1].m*v1[4])*v1[6] + v1[4]*(links[1].mcm[2]*v1[1] + links[1].m*v1[6]) + a1[1]*links[1].inertia[1][2] + v1[1]*(-(links[1].mcm[2]*v1[4]) + v1[3]*links[1].inertia[1][1] - v1[1]*links[1].inertia[1][3]) + a1[2]*links[1].inertia[2][2] + a1[3]*links[1].inertia[2][3] + v1[2]*(links[1].mcm[1]*v1[4] + links[1].mcm[3]*v1[6] + v1[3]*links[1].inertia[1][2] - v1[1]*links[1].inertia[2][3]) + v1[3]*(-(links[1].mcm[2]*v1[6]) + v1[3]*links[1].inertia[1][3] - v1[1]*links[1].inertia[3][3]);
fnet1[6]=a1[5]*links[1].mcm[1] - a1[4]*links[1].mcm[2] + (links[1].mcm[3]*v1[2] + links[1].m*v1[4])*v1[5] + v1[4]*(links[1].mcm[3]*v1[1] - links[1].m*v1[5]) + (-(links[1].mcm[1]*v1[1]) - links[1].mcm[2]*v1[2])*v1[6] + v1[1]*(-(links[1].mcm[3]*v1[4]) - v1[2]*links[1].inertia[1][1] + v1[1]*links[1].inertia[1][2]) + a1[1]*links[1].inertia[1][3] + v1[2]*(-(links[1].mcm[3]*v1[5]) - v1[2]*links[1].inertia[1][2] + v1[1]*links[1].inertia[2][2]) + a1[2]*links[1].inertia[2][3] + v1[3]*(links[1].mcm[1]*v1[4] + links[1].mcm[2]*v1[5] - v1[2]*links[1].inertia[1][3] + v1[1]*links[1].inertia[2][3]) + a1[3]*links[1].inertia[3][3];

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


fex0[1]=-(uex[0].f[1]*S00[1][1]) - uex[0].f[2]*S00[1][2] - uex[0].f[3]*S00[1][3];
fex0[2]=-(uex[0].f[1]*S00[2][1]) - uex[0].f[2]*S00[2][2] - uex[0].f[3]*S00[2][3];
fex0[3]=-(uex[0].f[1]*S00[3][1]) - uex[0].f[2]*S00[3][2] - uex[0].f[3]*S00[3][3];
fex0[4]=-(uex[0].t[1]*S00[1][1]) - uex[0].t[2]*S00[1][2] - uex[0].t[3]*S00[1][3];
fex0[5]=-(uex[0].t[1]*S00[2][1]) - uex[0].t[2]*S00[2][2] - uex[0].t[3]*S00[2][3];
fex0[6]=-(uex[0].t[1]*S00[3][1]) - uex[0].t[2]*S00[3][2] - uex[0].t[3]*S00[3][3];

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
master_InvDynNEfunc7(void)
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

fext0[1]=fex0[1] + 0.7071067811865475*fext1[3] + fext1[1]*Si01[1][1] + fext1[2]*Si01[1][2];
fext0[2]=fex0[2] + fext1[1]*Si01[2][1] + fext1[2]*Si01[2][2];
fext0[3]=fex0[3] + 0.7071067811865475*fext1[3] + fext1[1]*Si01[3][1] + fext1[2]*Si01[3][2];
fext0[4]=fex0[4] + 0.7071067811865475*fext1[6] + fext1[4]*Si01[1][1] + fext1[5]*Si01[1][2] - (l0*fext1[1]*Si01[2][1])/Sqrt(2) - (l0*fext1[2]*Si01[2][2])/Sqrt(2);
fext0[5]=fex0[5] + fext1[4]*Si01[2][1] + fext1[5]*Si01[2][2] + fext1[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + fext1[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2));
fext0[6]=fex0[6] + 0.7071067811865475*fext1[6] + (l0*fext1[1]*Si01[2][1])/Sqrt(2) + (l0*fext1[2]*Si01[2][2])/Sqrt(2) + fext1[4]*Si01[3][1] + fext1[5]*Si01[3][2];



}


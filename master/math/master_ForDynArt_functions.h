
void
master_ForDynArtfunc1(void)
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
master_ForDynArtfunc2(void)
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
master_ForDynArtfunc3(void)
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
master_ForDynArtfunc4(void)
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
master_ForDynArtfunc5(void)
     {
/* c-misc vectors */
c1[1]=state[1].thd*v1[2];
c1[2]=-(state[1].thd*v1[1]);
c1[4]=state[1].thd*v1[5];
c1[5]=-(state[1].thd*v1[4]);

c2[1]=state[2].thd*v2[2];
c2[2]=-(state[2].thd*v2[1]);
c2[4]=state[2].thd*v2[5];
c2[5]=-(state[2].thd*v2[4]);

c3[1]=state[3].thd*v3[2];
c3[2]=-(state[3].thd*v3[1]);
c3[4]=state[3].thd*v3[5];
c3[5]=-(state[3].thd*v3[4]);

c4[1]=state[4].thd*v4[2];
c4[2]=-(state[4].thd*v4[1]);
c4[4]=state[4].thd*v4[5];
c4[5]=-(state[4].thd*v4[4]);

c5[1]=state[5].thd*v5[2];
c5[2]=-(state[5].thd*v5[1]);
c5[4]=state[5].thd*v5[5];
c5[5]=-(state[5].thd*v5[4]);

c6[1]=state[6].thd*v6[2];
c6[2]=-(state[6].thd*v6[1]);
c6[4]=state[6].thd*v6[5];
c6[5]=-(state[6].thd*v6[4]);

c7[1]=state[7].thd*v7[2];
c7[2]=-(state[7].thd*v7[1]);
c7[4]=state[7].thd*v7[5];
c7[5]=-(state[7].thd*v7[4]);

c9[1]=state[8].thd*v9[2];
c9[2]=-(state[8].thd*v9[1]);
c9[4]=state[8].thd*v9[5];
c9[5]=-(state[8].thd*v9[4]);

c10[1]=state[9].thd*v10[2];
c10[2]=-(state[9].thd*v10[1]);
c10[4]=state[9].thd*v10[5];
c10[5]=-(state[9].thd*v10[4]);

c12[1]=state[10].thd*v12[2];
c12[2]=-(state[10].thd*v12[1]);
c12[4]=state[10].thd*v12[5];
c12[5]=-(state[10].thd*v12[4]);



}


void
master_ForDynArtfunc6(void)
     {
/* pv-misc vectors */
pv0[1]=-(links[0].mcm[1]*Power(v0[2],2)) - links[0].mcm[1]*Power(v0[3],2) + v0[1]*(links[0].mcm[2]*v0[2] + links[0].mcm[3]*v0[3]) - links[0].m*v0[3]*v0[5] + links[0].m*v0[2]*v0[6] - uex[0].f[1]*S00[1][1] - uex[0].f[2]*S00[1][2] + gravity*links[0].m*S00[1][3] - uex[0].f[3]*S00[1][3];
pv0[2]=-(links[0].mcm[2]*Power(v0[1],2)) - links[0].mcm[2]*Power(v0[3],2) + v0[2]*(links[0].mcm[1]*v0[1] + links[0].mcm[3]*v0[3]) + links[0].m*v0[3]*v0[4] - links[0].m*v0[1]*v0[6] - uex[0].f[1]*S00[2][1] - uex[0].f[2]*S00[2][2] + gravity*links[0].m*S00[2][3] - uex[0].f[3]*S00[2][3];
pv0[3]=-(links[0].mcm[3]*Power(v0[1],2)) - links[0].mcm[3]*Power(v0[2],2) + (links[0].mcm[1]*v0[1] + links[0].mcm[2]*v0[2])*v0[3] - links[0].m*v0[2]*v0[4] + links[0].m*v0[1]*v0[5] - uex[0].f[1]*S00[3][1] - uex[0].f[2]*S00[3][2] + gravity*links[0].m*S00[3][3] - uex[0].f[3]*S00[3][3];
pv0[4]=(-(links[0].mcm[2]*v0[2]) - links[0].mcm[3]*v0[3])*v0[4] + (links[0].mcm[1]*v0[3] + links[0].m*v0[5])*v0[6] + v0[5]*(links[0].mcm[1]*v0[2] - links[0].m*v0[6]) + v0[1]*(links[0].mcm[2]*v0[5] + links[0].mcm[3]*v0[6] - v0[3]*links[0].inertia[1][2] + v0[2]*links[0].inertia[1][3]) + v0[2]*(-(links[0].mcm[1]*v0[5]) - v0[3]*links[0].inertia[2][2] + v0[2]*links[0].inertia[2][3]) + v0[3]*(-(links[0].mcm[1]*v0[6]) - v0[3]*links[0].inertia[2][3] + v0[2]*links[0].inertia[3][3]) - uex[0].t[1]*S00[1][1] - uex[0].t[2]*S00[1][2] - uex[0].t[3]*S00[1][3] - gravity*links[0].mcm[3]*S00[2][3] + gravity*links[0].mcm[2]*S00[3][3];
pv0[5]=(-(links[0].mcm[1]*v0[1]) - links[0].mcm[3]*v0[3])*v0[5] + (links[0].mcm[2]*v0[3] - links[0].m*v0[4])*v0[6] + v0[4]*(links[0].mcm[2]*v0[1] + links[0].m*v0[6]) + v0[1]*(-(links[0].mcm[2]*v0[4]) + v0[3]*links[0].inertia[1][1] - v0[1]*links[0].inertia[1][3]) + v0[2]*(links[0].mcm[1]*v0[4] + links[0].mcm[3]*v0[6] + v0[3]*links[0].inertia[1][2] - v0[1]*links[0].inertia[2][3]) + v0[3]*(-(links[0].mcm[2]*v0[6]) + v0[3]*links[0].inertia[1][3] - v0[1]*links[0].inertia[3][3]) + gravity*links[0].mcm[3]*S00[1][3] - uex[0].t[1]*S00[2][1] - uex[0].t[2]*S00[2][2] - uex[0].t[3]*S00[2][3] - gravity*links[0].mcm[1]*S00[3][3];
pv0[6]=(links[0].mcm[3]*v0[2] + links[0].m*v0[4])*v0[5] + v0[4]*(links[0].mcm[3]*v0[1] - links[0].m*v0[5]) + (-(links[0].mcm[1]*v0[1]) - links[0].mcm[2]*v0[2])*v0[6] + v0[1]*(-(links[0].mcm[3]*v0[4]) - v0[2]*links[0].inertia[1][1] + v0[1]*links[0].inertia[1][2]) + v0[2]*(-(links[0].mcm[3]*v0[5]) - v0[2]*links[0].inertia[1][2] + v0[1]*links[0].inertia[2][2]) + v0[3]*(links[0].mcm[1]*v0[4] + links[0].mcm[2]*v0[5] - v0[2]*links[0].inertia[1][3] + v0[1]*links[0].inertia[2][3]) - gravity*links[0].mcm[2]*S00[1][3] + gravity*links[0].mcm[1]*S00[2][3] - uex[0].t[1]*S00[3][1] - uex[0].t[2]*S00[3][2] - uex[0].t[3]*S00[3][3];

pv1[1]=-(links[1].mcm[1]*Power(v1[2],2)) - links[1].mcm[1]*Power(v1[3],2) + v1[1]*(links[1].mcm[2]*v1[2] + links[1].mcm[3]*v1[3]) - links[1].m*v1[3]*v1[5] + links[1].m*v1[2]*v1[6] - uex[1].f[1]*SG10[1][1] - uex[1].f[2]*SG10[1][2] + gravity*links[1].m*SG10[1][3] - uex[1].f[3]*SG10[1][3];
pv1[2]=-(links[1].mcm[2]*Power(v1[1],2)) - links[1].mcm[2]*Power(v1[3],2) + v1[2]*(links[1].mcm[1]*v1[1] + links[1].mcm[3]*v1[3]) + links[1].m*v1[3]*v1[4] - links[1].m*v1[1]*v1[6] - uex[1].f[1]*SG10[2][1] - uex[1].f[2]*SG10[2][2] + gravity*links[1].m*SG10[2][3] - uex[1].f[3]*SG10[2][3];
pv1[3]=-(links[1].mcm[3]*Power(v1[1],2)) - links[1].mcm[3]*Power(v1[2],2) + (links[1].mcm[1]*v1[1] + links[1].mcm[2]*v1[2])*v1[3] - links[1].m*v1[2]*v1[4] + links[1].m*v1[1]*v1[5] - uex[1].f[1]*SG10[3][1] - uex[1].f[2]*SG10[3][2] + gravity*links[1].m*SG10[3][3] - uex[1].f[3]*SG10[3][3];
pv1[4]=(-(links[1].mcm[2]*v1[2]) - links[1].mcm[3]*v1[3])*v1[4] + (links[1].mcm[1]*v1[3] + links[1].m*v1[5])*v1[6] + v1[5]*(links[1].mcm[1]*v1[2] - links[1].m*v1[6]) + v1[1]*(links[1].mcm[2]*v1[5] + links[1].mcm[3]*v1[6] - v1[3]*links[1].inertia[1][2] + v1[2]*links[1].inertia[1][3]) + v1[2]*(-(links[1].mcm[1]*v1[5]) - v1[3]*links[1].inertia[2][2] + v1[2]*links[1].inertia[2][3]) + v1[3]*(-(links[1].mcm[1]*v1[6]) - v1[3]*links[1].inertia[2][3] + v1[2]*links[1].inertia[3][3]) - uex[1].t[1]*SG10[1][1] - uex[1].t[2]*SG10[1][2] - uex[1].t[3]*SG10[1][3] - gravity*links[1].mcm[3]*SG10[2][3] + gravity*links[1].mcm[2]*SG10[3][3];
pv1[5]=(-(links[1].mcm[1]*v1[1]) - links[1].mcm[3]*v1[3])*v1[5] + (links[1].mcm[2]*v1[3] - links[1].m*v1[4])*v1[6] + v1[4]*(links[1].mcm[2]*v1[1] + links[1].m*v1[6]) + v1[1]*(-(links[1].mcm[2]*v1[4]) + v1[3]*links[1].inertia[1][1] - v1[1]*links[1].inertia[1][3]) + v1[2]*(links[1].mcm[1]*v1[4] + links[1].mcm[3]*v1[6] + v1[3]*links[1].inertia[1][2] - v1[1]*links[1].inertia[2][3]) + v1[3]*(-(links[1].mcm[2]*v1[6]) + v1[3]*links[1].inertia[1][3] - v1[1]*links[1].inertia[3][3]) + gravity*links[1].mcm[3]*SG10[1][3] - uex[1].t[1]*SG10[2][1] - uex[1].t[2]*SG10[2][2] - uex[1].t[3]*SG10[2][3] - gravity*links[1].mcm[1]*SG10[3][3];
pv1[6]=(links[1].mcm[3]*v1[2] + links[1].m*v1[4])*v1[5] + v1[4]*(links[1].mcm[3]*v1[1] - links[1].m*v1[5]) + (-(links[1].mcm[1]*v1[1]) - links[1].mcm[2]*v1[2])*v1[6] + v1[1]*(-(links[1].mcm[3]*v1[4]) - v1[2]*links[1].inertia[1][1] + v1[1]*links[1].inertia[1][2]) + v1[2]*(-(links[1].mcm[3]*v1[5]) - v1[2]*links[1].inertia[1][2] + v1[1]*links[1].inertia[2][2]) + v1[3]*(links[1].mcm[1]*v1[4] + links[1].mcm[2]*v1[5] - v1[2]*links[1].inertia[1][3] + v1[1]*links[1].inertia[2][3]) - gravity*links[1].mcm[2]*SG10[1][3] + gravity*links[1].mcm[1]*SG10[2][3] - uex[1].t[1]*SG10[3][1] - uex[1].t[2]*SG10[3][2] - uex[1].t[3]*SG10[3][3];

pv2[1]=-(links[2].mcm[1]*Power(v2[2],2)) - links[2].mcm[1]*Power(v2[3],2) + v2[1]*(links[2].mcm[2]*v2[2] + links[2].mcm[3]*v2[3]) - links[2].m*v2[3]*v2[5] + links[2].m*v2[2]*v2[6] - uex[2].f[1]*SG20[1][1] - uex[2].f[2]*SG20[1][2] + gravity*links[2].m*SG20[1][3] - uex[2].f[3]*SG20[1][3];
pv2[2]=-(links[2].mcm[2]*Power(v2[1],2)) - links[2].mcm[2]*Power(v2[3],2) + v2[2]*(links[2].mcm[1]*v2[1] + links[2].mcm[3]*v2[3]) + links[2].m*v2[3]*v2[4] - links[2].m*v2[1]*v2[6] - uex[2].f[1]*SG20[2][1] - uex[2].f[2]*SG20[2][2] + gravity*links[2].m*SG20[2][3] - uex[2].f[3]*SG20[2][3];
pv2[3]=-(links[2].mcm[3]*Power(v2[1],2)) - links[2].mcm[3]*Power(v2[2],2) + (links[2].mcm[1]*v2[1] + links[2].mcm[2]*v2[2])*v2[3] - links[2].m*v2[2]*v2[4] + links[2].m*v2[1]*v2[5] - uex[2].f[1]*SG20[3][1] - uex[2].f[2]*SG20[3][2] + gravity*links[2].m*SG20[3][3] - uex[2].f[3]*SG20[3][3];
pv2[4]=(-(links[2].mcm[2]*v2[2]) - links[2].mcm[3]*v2[3])*v2[4] + (links[2].mcm[1]*v2[3] + links[2].m*v2[5])*v2[6] + v2[5]*(links[2].mcm[1]*v2[2] - links[2].m*v2[6]) + v2[1]*(links[2].mcm[2]*v2[5] + links[2].mcm[3]*v2[6] - v2[3]*links[2].inertia[1][2] + v2[2]*links[2].inertia[1][3]) + v2[2]*(-(links[2].mcm[1]*v2[5]) - v2[3]*links[2].inertia[2][2] + v2[2]*links[2].inertia[2][3]) + v2[3]*(-(links[2].mcm[1]*v2[6]) - v2[3]*links[2].inertia[2][3] + v2[2]*links[2].inertia[3][3]) - uex[2].t[1]*SG20[1][1] - uex[2].t[2]*SG20[1][2] - uex[2].t[3]*SG20[1][3] - gravity*links[2].mcm[3]*SG20[2][3] + gravity*links[2].mcm[2]*SG20[3][3];
pv2[5]=(-(links[2].mcm[1]*v2[1]) - links[2].mcm[3]*v2[3])*v2[5] + (links[2].mcm[2]*v2[3] - links[2].m*v2[4])*v2[6] + v2[4]*(links[2].mcm[2]*v2[1] + links[2].m*v2[6]) + v2[1]*(-(links[2].mcm[2]*v2[4]) + v2[3]*links[2].inertia[1][1] - v2[1]*links[2].inertia[1][3]) + v2[2]*(links[2].mcm[1]*v2[4] + links[2].mcm[3]*v2[6] + v2[3]*links[2].inertia[1][2] - v2[1]*links[2].inertia[2][3]) + v2[3]*(-(links[2].mcm[2]*v2[6]) + v2[3]*links[2].inertia[1][3] - v2[1]*links[2].inertia[3][3]) + gravity*links[2].mcm[3]*SG20[1][3] - uex[2].t[1]*SG20[2][1] - uex[2].t[2]*SG20[2][2] - uex[2].t[3]*SG20[2][3] - gravity*links[2].mcm[1]*SG20[3][3];
pv2[6]=(links[2].mcm[3]*v2[2] + links[2].m*v2[4])*v2[5] + v2[4]*(links[2].mcm[3]*v2[1] - links[2].m*v2[5]) + (-(links[2].mcm[1]*v2[1]) - links[2].mcm[2]*v2[2])*v2[6] + v2[1]*(-(links[2].mcm[3]*v2[4]) - v2[2]*links[2].inertia[1][1] + v2[1]*links[2].inertia[1][2]) + v2[2]*(-(links[2].mcm[3]*v2[5]) - v2[2]*links[2].inertia[1][2] + v2[1]*links[2].inertia[2][2]) + v2[3]*(links[2].mcm[1]*v2[4] + links[2].mcm[2]*v2[5] - v2[2]*links[2].inertia[1][3] + v2[1]*links[2].inertia[2][3]) - gravity*links[2].mcm[2]*SG20[1][3] + gravity*links[2].mcm[1]*SG20[2][3] - uex[2].t[1]*SG20[3][1] - uex[2].t[2]*SG20[3][2] - uex[2].t[3]*SG20[3][3];

pv3[1]=-(links[3].mcm[1]*Power(v3[2],2)) - links[3].mcm[1]*Power(v3[3],2) + v3[1]*(links[3].mcm[2]*v3[2] + links[3].mcm[3]*v3[3]) - links[3].m*v3[3]*v3[5] + links[3].m*v3[2]*v3[6] - uex[3].f[1]*SG30[1][1] - uex[3].f[2]*SG30[1][2] + gravity*links[3].m*SG30[1][3] - uex[3].f[3]*SG30[1][3];
pv3[2]=-(links[3].mcm[2]*Power(v3[1],2)) - links[3].mcm[2]*Power(v3[3],2) + v3[2]*(links[3].mcm[1]*v3[1] + links[3].mcm[3]*v3[3]) + links[3].m*v3[3]*v3[4] - links[3].m*v3[1]*v3[6] - uex[3].f[1]*SG30[2][1] - uex[3].f[2]*SG30[2][2] + gravity*links[3].m*SG30[2][3] - uex[3].f[3]*SG30[2][3];
pv3[3]=-(links[3].mcm[3]*Power(v3[1],2)) - links[3].mcm[3]*Power(v3[2],2) + (links[3].mcm[1]*v3[1] + links[3].mcm[2]*v3[2])*v3[3] - links[3].m*v3[2]*v3[4] + links[3].m*v3[1]*v3[5] - uex[3].f[1]*SG30[3][1] - uex[3].f[2]*SG30[3][2] + gravity*links[3].m*SG30[3][3] - uex[3].f[3]*SG30[3][3];
pv3[4]=(-(links[3].mcm[2]*v3[2]) - links[3].mcm[3]*v3[3])*v3[4] + (links[3].mcm[1]*v3[3] + links[3].m*v3[5])*v3[6] + v3[5]*(links[3].mcm[1]*v3[2] - links[3].m*v3[6]) + v3[1]*(links[3].mcm[2]*v3[5] + links[3].mcm[3]*v3[6] - v3[3]*links[3].inertia[1][2] + v3[2]*links[3].inertia[1][3]) + v3[2]*(-(links[3].mcm[1]*v3[5]) - v3[3]*links[3].inertia[2][2] + v3[2]*links[3].inertia[2][3]) + v3[3]*(-(links[3].mcm[1]*v3[6]) - v3[3]*links[3].inertia[2][3] + v3[2]*links[3].inertia[3][3]) - uex[3].t[1]*SG30[1][1] - uex[3].t[2]*SG30[1][2] - uex[3].t[3]*SG30[1][3] - gravity*links[3].mcm[3]*SG30[2][3] + gravity*links[3].mcm[2]*SG30[3][3];
pv3[5]=(-(links[3].mcm[1]*v3[1]) - links[3].mcm[3]*v3[3])*v3[5] + (links[3].mcm[2]*v3[3] - links[3].m*v3[4])*v3[6] + v3[4]*(links[3].mcm[2]*v3[1] + links[3].m*v3[6]) + v3[1]*(-(links[3].mcm[2]*v3[4]) + v3[3]*links[3].inertia[1][1] - v3[1]*links[3].inertia[1][3]) + v3[2]*(links[3].mcm[1]*v3[4] + links[3].mcm[3]*v3[6] + v3[3]*links[3].inertia[1][2] - v3[1]*links[3].inertia[2][3]) + v3[3]*(-(links[3].mcm[2]*v3[6]) + v3[3]*links[3].inertia[1][3] - v3[1]*links[3].inertia[3][3]) + gravity*links[3].mcm[3]*SG30[1][3] - uex[3].t[1]*SG30[2][1] - uex[3].t[2]*SG30[2][2] - uex[3].t[3]*SG30[2][3] - gravity*links[3].mcm[1]*SG30[3][3];
pv3[6]=(links[3].mcm[3]*v3[2] + links[3].m*v3[4])*v3[5] + v3[4]*(links[3].mcm[3]*v3[1] - links[3].m*v3[5]) + (-(links[3].mcm[1]*v3[1]) - links[3].mcm[2]*v3[2])*v3[6] + v3[1]*(-(links[3].mcm[3]*v3[4]) - v3[2]*links[3].inertia[1][1] + v3[1]*links[3].inertia[1][2]) + v3[2]*(-(links[3].mcm[3]*v3[5]) - v3[2]*links[3].inertia[1][2] + v3[1]*links[3].inertia[2][2]) + v3[3]*(links[3].mcm[1]*v3[4] + links[3].mcm[2]*v3[5] - v3[2]*links[3].inertia[1][3] + v3[1]*links[3].inertia[2][3]) - gravity*links[3].mcm[2]*SG30[1][3] + gravity*links[3].mcm[1]*SG30[2][3] - uex[3].t[1]*SG30[3][1] - uex[3].t[2]*SG30[3][2] - uex[3].t[3]*SG30[3][3];

pv4[1]=-(links[4].mcm[1]*Power(v4[2],2)) - links[4].mcm[1]*Power(v4[3],2) + v4[1]*(links[4].mcm[2]*v4[2] + links[4].mcm[3]*v4[3]) - links[4].m*v4[3]*v4[5] + links[4].m*v4[2]*v4[6] - uex[4].f[1]*SG40[1][1] - uex[4].f[2]*SG40[1][2] + gravity*links[4].m*SG40[1][3] - uex[4].f[3]*SG40[1][3];
pv4[2]=-(links[4].mcm[2]*Power(v4[1],2)) - links[4].mcm[2]*Power(v4[3],2) + v4[2]*(links[4].mcm[1]*v4[1] + links[4].mcm[3]*v4[3]) + links[4].m*v4[3]*v4[4] - links[4].m*v4[1]*v4[6] - uex[4].f[1]*SG40[2][1] - uex[4].f[2]*SG40[2][2] + gravity*links[4].m*SG40[2][3] - uex[4].f[3]*SG40[2][3];
pv4[3]=-(links[4].mcm[3]*Power(v4[1],2)) - links[4].mcm[3]*Power(v4[2],2) + (links[4].mcm[1]*v4[1] + links[4].mcm[2]*v4[2])*v4[3] - links[4].m*v4[2]*v4[4] + links[4].m*v4[1]*v4[5] - uex[4].f[1]*SG40[3][1] - uex[4].f[2]*SG40[3][2] + gravity*links[4].m*SG40[3][3] - uex[4].f[3]*SG40[3][3];
pv4[4]=(-(links[4].mcm[2]*v4[2]) - links[4].mcm[3]*v4[3])*v4[4] + (links[4].mcm[1]*v4[3] + links[4].m*v4[5])*v4[6] + v4[5]*(links[4].mcm[1]*v4[2] - links[4].m*v4[6]) + v4[1]*(links[4].mcm[2]*v4[5] + links[4].mcm[3]*v4[6] - v4[3]*links[4].inertia[1][2] + v4[2]*links[4].inertia[1][3]) + v4[2]*(-(links[4].mcm[1]*v4[5]) - v4[3]*links[4].inertia[2][2] + v4[2]*links[4].inertia[2][3]) + v4[3]*(-(links[4].mcm[1]*v4[6]) - v4[3]*links[4].inertia[2][3] + v4[2]*links[4].inertia[3][3]) - uex[4].t[1]*SG40[1][1] - uex[4].t[2]*SG40[1][2] - uex[4].t[3]*SG40[1][3] - gravity*links[4].mcm[3]*SG40[2][3] + gravity*links[4].mcm[2]*SG40[3][3];
pv4[5]=(-(links[4].mcm[1]*v4[1]) - links[4].mcm[3]*v4[3])*v4[5] + (links[4].mcm[2]*v4[3] - links[4].m*v4[4])*v4[6] + v4[4]*(links[4].mcm[2]*v4[1] + links[4].m*v4[6]) + v4[1]*(-(links[4].mcm[2]*v4[4]) + v4[3]*links[4].inertia[1][1] - v4[1]*links[4].inertia[1][3]) + v4[2]*(links[4].mcm[1]*v4[4] + links[4].mcm[3]*v4[6] + v4[3]*links[4].inertia[1][2] - v4[1]*links[4].inertia[2][3]) + v4[3]*(-(links[4].mcm[2]*v4[6]) + v4[3]*links[4].inertia[1][3] - v4[1]*links[4].inertia[3][3]) + gravity*links[4].mcm[3]*SG40[1][3] - uex[4].t[1]*SG40[2][1] - uex[4].t[2]*SG40[2][2] - uex[4].t[3]*SG40[2][3] - gravity*links[4].mcm[1]*SG40[3][3];
pv4[6]=(links[4].mcm[3]*v4[2] + links[4].m*v4[4])*v4[5] + v4[4]*(links[4].mcm[3]*v4[1] - links[4].m*v4[5]) + (-(links[4].mcm[1]*v4[1]) - links[4].mcm[2]*v4[2])*v4[6] + v4[1]*(-(links[4].mcm[3]*v4[4]) - v4[2]*links[4].inertia[1][1] + v4[1]*links[4].inertia[1][2]) + v4[2]*(-(links[4].mcm[3]*v4[5]) - v4[2]*links[4].inertia[1][2] + v4[1]*links[4].inertia[2][2]) + v4[3]*(links[4].mcm[1]*v4[4] + links[4].mcm[2]*v4[5] - v4[2]*links[4].inertia[1][3] + v4[1]*links[4].inertia[2][3]) - gravity*links[4].mcm[2]*SG40[1][3] + gravity*links[4].mcm[1]*SG40[2][3] - uex[4].t[1]*SG40[3][1] - uex[4].t[2]*SG40[3][2] - uex[4].t[3]*SG40[3][3];

pv5[1]=-(links[5].mcm[1]*Power(v5[2],2)) - links[5].mcm[1]*Power(v5[3],2) + v5[1]*(links[5].mcm[2]*v5[2] + links[5].mcm[3]*v5[3]) - links[5].m*v5[3]*v5[5] + links[5].m*v5[2]*v5[6] - uex[5].f[1]*SG50[1][1] - uex[5].f[2]*SG50[1][2] + gravity*links[5].m*SG50[1][3] - uex[5].f[3]*SG50[1][3];
pv5[2]=-(links[5].mcm[2]*Power(v5[1],2)) - links[5].mcm[2]*Power(v5[3],2) + v5[2]*(links[5].mcm[1]*v5[1] + links[5].mcm[3]*v5[3]) + links[5].m*v5[3]*v5[4] - links[5].m*v5[1]*v5[6] - uex[5].f[1]*SG50[2][1] - uex[5].f[2]*SG50[2][2] + gravity*links[5].m*SG50[2][3] - uex[5].f[3]*SG50[2][3];
pv5[3]=-(links[5].mcm[3]*Power(v5[1],2)) - links[5].mcm[3]*Power(v5[2],2) + (links[5].mcm[1]*v5[1] + links[5].mcm[2]*v5[2])*v5[3] - links[5].m*v5[2]*v5[4] + links[5].m*v5[1]*v5[5] - uex[5].f[1]*SG50[3][1] - uex[5].f[2]*SG50[3][2] + gravity*links[5].m*SG50[3][3] - uex[5].f[3]*SG50[3][3];
pv5[4]=(-(links[5].mcm[2]*v5[2]) - links[5].mcm[3]*v5[3])*v5[4] + (links[5].mcm[1]*v5[3] + links[5].m*v5[5])*v5[6] + v5[5]*(links[5].mcm[1]*v5[2] - links[5].m*v5[6]) + v5[1]*(links[5].mcm[2]*v5[5] + links[5].mcm[3]*v5[6] - v5[3]*links[5].inertia[1][2] + v5[2]*links[5].inertia[1][3]) + v5[2]*(-(links[5].mcm[1]*v5[5]) - v5[3]*links[5].inertia[2][2] + v5[2]*links[5].inertia[2][3]) + v5[3]*(-(links[5].mcm[1]*v5[6]) - v5[3]*links[5].inertia[2][3] + v5[2]*links[5].inertia[3][3]) - uex[5].t[1]*SG50[1][1] - uex[5].t[2]*SG50[1][2] - uex[5].t[3]*SG50[1][3] - gravity*links[5].mcm[3]*SG50[2][3] + gravity*links[5].mcm[2]*SG50[3][3];
pv5[5]=(-(links[5].mcm[1]*v5[1]) - links[5].mcm[3]*v5[3])*v5[5] + (links[5].mcm[2]*v5[3] - links[5].m*v5[4])*v5[6] + v5[4]*(links[5].mcm[2]*v5[1] + links[5].m*v5[6]) + v5[1]*(-(links[5].mcm[2]*v5[4]) + v5[3]*links[5].inertia[1][1] - v5[1]*links[5].inertia[1][3]) + v5[2]*(links[5].mcm[1]*v5[4] + links[5].mcm[3]*v5[6] + v5[3]*links[5].inertia[1][2] - v5[1]*links[5].inertia[2][3]) + v5[3]*(-(links[5].mcm[2]*v5[6]) + v5[3]*links[5].inertia[1][3] - v5[1]*links[5].inertia[3][3]) + gravity*links[5].mcm[3]*SG50[1][3] - uex[5].t[1]*SG50[2][1] - uex[5].t[2]*SG50[2][2] - uex[5].t[3]*SG50[2][3] - gravity*links[5].mcm[1]*SG50[3][3];
pv5[6]=(links[5].mcm[3]*v5[2] + links[5].m*v5[4])*v5[5] + v5[4]*(links[5].mcm[3]*v5[1] - links[5].m*v5[5]) + (-(links[5].mcm[1]*v5[1]) - links[5].mcm[2]*v5[2])*v5[6] + v5[1]*(-(links[5].mcm[3]*v5[4]) - v5[2]*links[5].inertia[1][1] + v5[1]*links[5].inertia[1][2]) + v5[2]*(-(links[5].mcm[3]*v5[5]) - v5[2]*links[5].inertia[1][2] + v5[1]*links[5].inertia[2][2]) + v5[3]*(links[5].mcm[1]*v5[4] + links[5].mcm[2]*v5[5] - v5[2]*links[5].inertia[1][3] + v5[1]*links[5].inertia[2][3]) - gravity*links[5].mcm[2]*SG50[1][3] + gravity*links[5].mcm[1]*SG50[2][3] - uex[5].t[1]*SG50[3][1] - uex[5].t[2]*SG50[3][2] - uex[5].t[3]*SG50[3][3];

pv6[1]=-(links[6].mcm[1]*Power(v6[2],2)) - links[6].mcm[1]*Power(v6[3],2) + v6[1]*(links[6].mcm[2]*v6[2] + links[6].mcm[3]*v6[3]) - links[6].m*v6[3]*v6[5] + links[6].m*v6[2]*v6[6] - uex[6].f[1]*SG60[1][1] - uex[6].f[2]*SG60[1][2] + gravity*links[6].m*SG60[1][3] - uex[6].f[3]*SG60[1][3];
pv6[2]=-(links[6].mcm[2]*Power(v6[1],2)) - links[6].mcm[2]*Power(v6[3],2) + v6[2]*(links[6].mcm[1]*v6[1] + links[6].mcm[3]*v6[3]) + links[6].m*v6[3]*v6[4] - links[6].m*v6[1]*v6[6] - uex[6].f[1]*SG60[2][1] - uex[6].f[2]*SG60[2][2] + gravity*links[6].m*SG60[2][3] - uex[6].f[3]*SG60[2][3];
pv6[3]=-(links[6].mcm[3]*Power(v6[1],2)) - links[6].mcm[3]*Power(v6[2],2) + (links[6].mcm[1]*v6[1] + links[6].mcm[2]*v6[2])*v6[3] - links[6].m*v6[2]*v6[4] + links[6].m*v6[1]*v6[5] - uex[6].f[1]*SG60[3][1] - uex[6].f[2]*SG60[3][2] + gravity*links[6].m*SG60[3][3] - uex[6].f[3]*SG60[3][3];
pv6[4]=(-(links[6].mcm[2]*v6[2]) - links[6].mcm[3]*v6[3])*v6[4] + (links[6].mcm[1]*v6[3] + links[6].m*v6[5])*v6[6] + v6[5]*(links[6].mcm[1]*v6[2] - links[6].m*v6[6]) + v6[1]*(links[6].mcm[2]*v6[5] + links[6].mcm[3]*v6[6] - v6[3]*links[6].inertia[1][2] + v6[2]*links[6].inertia[1][3]) + v6[2]*(-(links[6].mcm[1]*v6[5]) - v6[3]*links[6].inertia[2][2] + v6[2]*links[6].inertia[2][3]) + v6[3]*(-(links[6].mcm[1]*v6[6]) - v6[3]*links[6].inertia[2][3] + v6[2]*links[6].inertia[3][3]) - uex[6].t[1]*SG60[1][1] - uex[6].t[2]*SG60[1][2] - uex[6].t[3]*SG60[1][3] - gravity*links[6].mcm[3]*SG60[2][3] + gravity*links[6].mcm[2]*SG60[3][3];
pv6[5]=(-(links[6].mcm[1]*v6[1]) - links[6].mcm[3]*v6[3])*v6[5] + (links[6].mcm[2]*v6[3] - links[6].m*v6[4])*v6[6] + v6[4]*(links[6].mcm[2]*v6[1] + links[6].m*v6[6]) + v6[1]*(-(links[6].mcm[2]*v6[4]) + v6[3]*links[6].inertia[1][1] - v6[1]*links[6].inertia[1][3]) + v6[2]*(links[6].mcm[1]*v6[4] + links[6].mcm[3]*v6[6] + v6[3]*links[6].inertia[1][2] - v6[1]*links[6].inertia[2][3]) + v6[3]*(-(links[6].mcm[2]*v6[6]) + v6[3]*links[6].inertia[1][3] - v6[1]*links[6].inertia[3][3]) + gravity*links[6].mcm[3]*SG60[1][3] - uex[6].t[1]*SG60[2][1] - uex[6].t[2]*SG60[2][2] - uex[6].t[3]*SG60[2][3] - gravity*links[6].mcm[1]*SG60[3][3];
pv6[6]=(links[6].mcm[3]*v6[2] + links[6].m*v6[4])*v6[5] + v6[4]*(links[6].mcm[3]*v6[1] - links[6].m*v6[5]) + (-(links[6].mcm[1]*v6[1]) - links[6].mcm[2]*v6[2])*v6[6] + v6[1]*(-(links[6].mcm[3]*v6[4]) - v6[2]*links[6].inertia[1][1] + v6[1]*links[6].inertia[1][2]) + v6[2]*(-(links[6].mcm[3]*v6[5]) - v6[2]*links[6].inertia[1][2] + v6[1]*links[6].inertia[2][2]) + v6[3]*(links[6].mcm[1]*v6[4] + links[6].mcm[2]*v6[5] - v6[2]*links[6].inertia[1][3] + v6[1]*links[6].inertia[2][3]) - gravity*links[6].mcm[2]*SG60[1][3] + gravity*links[6].mcm[1]*SG60[2][3] - uex[6].t[1]*SG60[3][1] - uex[6].t[2]*SG60[3][2] - uex[6].t[3]*SG60[3][3];

pv7[1]=-(links[7].mcm[1]*Power(v7[2],2)) - links[7].mcm[1]*Power(v7[3],2) + v7[1]*(links[7].mcm[2]*v7[2] + links[7].mcm[3]*v7[3]) - links[7].m*v7[3]*v7[5] + links[7].m*v7[2]*v7[6] - uex[7].f[1]*SG70[1][1] - uex[7].f[2]*SG70[1][2] + gravity*links[7].m*SG70[1][3] - uex[7].f[3]*SG70[1][3];
pv7[2]=-(links[7].mcm[2]*Power(v7[1],2)) - links[7].mcm[2]*Power(v7[3],2) + v7[2]*(links[7].mcm[1]*v7[1] + links[7].mcm[3]*v7[3]) + links[7].m*v7[3]*v7[4] - links[7].m*v7[1]*v7[6] - uex[7].f[1]*SG70[2][1] - uex[7].f[2]*SG70[2][2] + gravity*links[7].m*SG70[2][3] - uex[7].f[3]*SG70[2][3];
pv7[3]=-(links[7].mcm[3]*Power(v7[1],2)) - links[7].mcm[3]*Power(v7[2],2) + (links[7].mcm[1]*v7[1] + links[7].mcm[2]*v7[2])*v7[3] - links[7].m*v7[2]*v7[4] + links[7].m*v7[1]*v7[5] - uex[7].f[1]*SG70[3][1] - uex[7].f[2]*SG70[3][2] + gravity*links[7].m*SG70[3][3] - uex[7].f[3]*SG70[3][3];
pv7[4]=(-(links[7].mcm[2]*v7[2]) - links[7].mcm[3]*v7[3])*v7[4] + (links[7].mcm[1]*v7[3] + links[7].m*v7[5])*v7[6] + v7[5]*(links[7].mcm[1]*v7[2] - links[7].m*v7[6]) + v7[1]*(links[7].mcm[2]*v7[5] + links[7].mcm[3]*v7[6] - v7[3]*links[7].inertia[1][2] + v7[2]*links[7].inertia[1][3]) + v7[2]*(-(links[7].mcm[1]*v7[5]) - v7[3]*links[7].inertia[2][2] + v7[2]*links[7].inertia[2][3]) + v7[3]*(-(links[7].mcm[1]*v7[6]) - v7[3]*links[7].inertia[2][3] + v7[2]*links[7].inertia[3][3]) - uex[7].t[1]*SG70[1][1] - uex[7].t[2]*SG70[1][2] - uex[7].t[3]*SG70[1][3] - gravity*links[7].mcm[3]*SG70[2][3] + gravity*links[7].mcm[2]*SG70[3][3];
pv7[5]=(-(links[7].mcm[1]*v7[1]) - links[7].mcm[3]*v7[3])*v7[5] + (links[7].mcm[2]*v7[3] - links[7].m*v7[4])*v7[6] + v7[4]*(links[7].mcm[2]*v7[1] + links[7].m*v7[6]) + v7[1]*(-(links[7].mcm[2]*v7[4]) + v7[3]*links[7].inertia[1][1] - v7[1]*links[7].inertia[1][3]) + v7[2]*(links[7].mcm[1]*v7[4] + links[7].mcm[3]*v7[6] + v7[3]*links[7].inertia[1][2] - v7[1]*links[7].inertia[2][3]) + v7[3]*(-(links[7].mcm[2]*v7[6]) + v7[3]*links[7].inertia[1][3] - v7[1]*links[7].inertia[3][3]) + gravity*links[7].mcm[3]*SG70[1][3] - uex[7].t[1]*SG70[2][1] - uex[7].t[2]*SG70[2][2] - uex[7].t[3]*SG70[2][3] - gravity*links[7].mcm[1]*SG70[3][3];
pv7[6]=(links[7].mcm[3]*v7[2] + links[7].m*v7[4])*v7[5] + v7[4]*(links[7].mcm[3]*v7[1] - links[7].m*v7[5]) + (-(links[7].mcm[1]*v7[1]) - links[7].mcm[2]*v7[2])*v7[6] + v7[1]*(-(links[7].mcm[3]*v7[4]) - v7[2]*links[7].inertia[1][1] + v7[1]*links[7].inertia[1][2]) + v7[2]*(-(links[7].mcm[3]*v7[5]) - v7[2]*links[7].inertia[1][2] + v7[1]*links[7].inertia[2][2]) + v7[3]*(links[7].mcm[1]*v7[4] + links[7].mcm[2]*v7[5] - v7[2]*links[7].inertia[1][3] + v7[1]*links[7].inertia[2][3]) - gravity*links[7].mcm[2]*SG70[1][3] + gravity*links[7].mcm[1]*SG70[2][3] - uex[7].t[1]*SG70[3][1] - uex[7].t[2]*SG70[3][2] - uex[7].t[3]*SG70[3][3];

pv8[1]=-(eff[1].mcm[1]*Power(v8[2],2)) - eff[1].mcm[1]*Power(v8[3],2) + v8[1]*(eff[1].mcm[2]*v8[2] + eff[1].mcm[3]*v8[3]) - eff[1].m*v8[3]*v8[5] + eff[1].m*v8[2]*v8[6] + eff[1].m*gravity*SG80[1][3];
pv8[2]=-(eff[1].mcm[2]*Power(v8[1],2)) - eff[1].mcm[2]*Power(v8[3],2) + v8[2]*(eff[1].mcm[1]*v8[1] + eff[1].mcm[3]*v8[3]) + eff[1].m*v8[3]*v8[4] - eff[1].m*v8[1]*v8[6] + eff[1].m*gravity*SG80[2][3];
pv8[3]=-(eff[1].mcm[3]*Power(v8[1],2)) - eff[1].mcm[3]*Power(v8[2],2) + (eff[1].mcm[1]*v8[1] + eff[1].mcm[2]*v8[2])*v8[3] - eff[1].m*v8[2]*v8[4] + eff[1].m*v8[1]*v8[5] + eff[1].m*gravity*SG80[3][3];
pv8[4]=(-(eff[1].mcm[2]*v8[2]) - eff[1].mcm[3]*v8[3])*v8[4] - eff[1].mcm[1]*v8[2]*v8[5] - eff[1].mcm[1]*v8[3]*v8[6] + (eff[1].mcm[1]*v8[3] + eff[1].m*v8[5])*v8[6] + v8[5]*(eff[1].mcm[1]*v8[2] - eff[1].m*v8[6]) + v8[1]*(eff[1].mcm[2]*v8[5] + eff[1].mcm[3]*v8[6]) - gravity*eff[1].mcm[3]*SG80[2][3] + gravity*eff[1].mcm[2]*SG80[3][3];
pv8[5]=-(eff[1].mcm[2]*v8[1]*v8[4]) + (-(eff[1].mcm[1]*v8[1]) - eff[1].mcm[3]*v8[3])*v8[5] - eff[1].mcm[2]*v8[3]*v8[6] + (eff[1].mcm[2]*v8[3] - eff[1].m*v8[4])*v8[6] + v8[4]*(eff[1].mcm[2]*v8[1] + eff[1].m*v8[6]) + v8[2]*(eff[1].mcm[1]*v8[4] + eff[1].mcm[3]*v8[6]) + gravity*eff[1].mcm[3]*SG80[1][3] - gravity*eff[1].mcm[1]*SG80[3][3];
pv8[6]=-(eff[1].mcm[3]*v8[1]*v8[4]) - eff[1].mcm[3]*v8[2]*v8[5] + (eff[1].mcm[3]*v8[2] + eff[1].m*v8[4])*v8[5] + v8[4]*(eff[1].mcm[3]*v8[1] - eff[1].m*v8[5]) + v8[3]*(eff[1].mcm[1]*v8[4] + eff[1].mcm[2]*v8[5]) + (-(eff[1].mcm[1]*v8[1]) - eff[1].mcm[2]*v8[2])*v8[6] - gravity*eff[1].mcm[2]*SG80[1][3] + gravity*eff[1].mcm[1]*SG80[2][3];

pv9[1]=-(links[8].mcm[1]*Power(v9[2],2)) - links[8].mcm[1]*Power(v9[3],2) + v9[1]*(links[8].mcm[2]*v9[2] + links[8].mcm[3]*v9[3]) - links[8].m*v9[3]*v9[5] + links[8].m*v9[2]*v9[6] - uex[8].f[1]*SG90[1][1] - uex[8].f[2]*SG90[1][2] + gravity*links[8].m*SG90[1][3] - uex[8].f[3]*SG90[1][3];
pv9[2]=-(links[8].mcm[2]*Power(v9[1],2)) - links[8].mcm[2]*Power(v9[3],2) + v9[2]*(links[8].mcm[1]*v9[1] + links[8].mcm[3]*v9[3]) + links[8].m*v9[3]*v9[4] - links[8].m*v9[1]*v9[6] - uex[8].f[1]*SG90[2][1] - uex[8].f[2]*SG90[2][2] + gravity*links[8].m*SG90[2][3] - uex[8].f[3]*SG90[2][3];
pv9[3]=-(links[8].mcm[3]*Power(v9[1],2)) - links[8].mcm[3]*Power(v9[2],2) + (links[8].mcm[1]*v9[1] + links[8].mcm[2]*v9[2])*v9[3] - links[8].m*v9[2]*v9[4] + links[8].m*v9[1]*v9[5] - uex[8].f[1]*SG90[3][1] - uex[8].f[2]*SG90[3][2] + gravity*links[8].m*SG90[3][3] - uex[8].f[3]*SG90[3][3];
pv9[4]=(-(links[8].mcm[2]*v9[2]) - links[8].mcm[3]*v9[3])*v9[4] + (links[8].mcm[1]*v9[3] + links[8].m*v9[5])*v9[6] + v9[5]*(links[8].mcm[1]*v9[2] - links[8].m*v9[6]) + v9[1]*(links[8].mcm[2]*v9[5] + links[8].mcm[3]*v9[6] - v9[3]*links[8].inertia[1][2] + v9[2]*links[8].inertia[1][3]) + v9[2]*(-(links[8].mcm[1]*v9[5]) - v9[3]*links[8].inertia[2][2] + v9[2]*links[8].inertia[2][3]) + v9[3]*(-(links[8].mcm[1]*v9[6]) - v9[3]*links[8].inertia[2][3] + v9[2]*links[8].inertia[3][3]) - uex[8].t[1]*SG90[1][1] - uex[8].t[2]*SG90[1][2] - uex[8].t[3]*SG90[1][3] - gravity*links[8].mcm[3]*SG90[2][3] + gravity*links[8].mcm[2]*SG90[3][3];
pv9[5]=(-(links[8].mcm[1]*v9[1]) - links[8].mcm[3]*v9[3])*v9[5] + (links[8].mcm[2]*v9[3] - links[8].m*v9[4])*v9[6] + v9[4]*(links[8].mcm[2]*v9[1] + links[8].m*v9[6]) + v9[1]*(-(links[8].mcm[2]*v9[4]) + v9[3]*links[8].inertia[1][1] - v9[1]*links[8].inertia[1][3]) + v9[2]*(links[8].mcm[1]*v9[4] + links[8].mcm[3]*v9[6] + v9[3]*links[8].inertia[1][2] - v9[1]*links[8].inertia[2][3]) + v9[3]*(-(links[8].mcm[2]*v9[6]) + v9[3]*links[8].inertia[1][3] - v9[1]*links[8].inertia[3][3]) + gravity*links[8].mcm[3]*SG90[1][3] - uex[8].t[1]*SG90[2][1] - uex[8].t[2]*SG90[2][2] - uex[8].t[3]*SG90[2][3] - gravity*links[8].mcm[1]*SG90[3][3];
pv9[6]=(links[8].mcm[3]*v9[2] + links[8].m*v9[4])*v9[5] + v9[4]*(links[8].mcm[3]*v9[1] - links[8].m*v9[5]) + (-(links[8].mcm[1]*v9[1]) - links[8].mcm[2]*v9[2])*v9[6] + v9[1]*(-(links[8].mcm[3]*v9[4]) - v9[2]*links[8].inertia[1][1] + v9[1]*links[8].inertia[1][2]) + v9[2]*(-(links[8].mcm[3]*v9[5]) - v9[2]*links[8].inertia[1][2] + v9[1]*links[8].inertia[2][2]) + v9[3]*(links[8].mcm[1]*v9[4] + links[8].mcm[2]*v9[5] - v9[2]*links[8].inertia[1][3] + v9[1]*links[8].inertia[2][3]) - gravity*links[8].mcm[2]*SG90[1][3] + gravity*links[8].mcm[1]*SG90[2][3] - uex[8].t[1]*SG90[3][1] - uex[8].t[2]*SG90[3][2] - uex[8].t[3]*SG90[3][3];

pv10[1]=-(links[9].mcm[1]*Power(v10[2],2)) - links[9].mcm[1]*Power(v10[3],2) + v10[1]*(links[9].mcm[2]*v10[2] + links[9].mcm[3]*v10[3]) - links[9].m*v10[3]*v10[5] + links[9].m*v10[2]*v10[6] - uex[9].f[1]*SG100[1][1] - uex[9].f[2]*SG100[1][2] + gravity*links[9].m*SG100[1][3] - uex[9].f[3]*SG100[1][3];
pv10[2]=-(links[9].mcm[2]*Power(v10[1],2)) - links[9].mcm[2]*Power(v10[3],2) + v10[2]*(links[9].mcm[1]*v10[1] + links[9].mcm[3]*v10[3]) + links[9].m*v10[3]*v10[4] - links[9].m*v10[1]*v10[6] - uex[9].f[1]*SG100[2][1] - uex[9].f[2]*SG100[2][2] + gravity*links[9].m*SG100[2][3] - uex[9].f[3]*SG100[2][3];
pv10[3]=-(links[9].mcm[3]*Power(v10[1],2)) - links[9].mcm[3]*Power(v10[2],2) + (links[9].mcm[1]*v10[1] + links[9].mcm[2]*v10[2])*v10[3] - links[9].m*v10[2]*v10[4] + links[9].m*v10[1]*v10[5] - uex[9].f[1]*SG100[3][1] - uex[9].f[2]*SG100[3][2] + gravity*links[9].m*SG100[3][3] - uex[9].f[3]*SG100[3][3];
pv10[4]=(-(links[9].mcm[2]*v10[2]) - links[9].mcm[3]*v10[3])*v10[4] + (links[9].mcm[1]*v10[3] + links[9].m*v10[5])*v10[6] + v10[5]*(links[9].mcm[1]*v10[2] - links[9].m*v10[6]) + v10[1]*(links[9].mcm[2]*v10[5] + links[9].mcm[3]*v10[6] - v10[3]*links[9].inertia[1][2] + v10[2]*links[9].inertia[1][3]) + v10[2]*(-(links[9].mcm[1]*v10[5]) - v10[3]*links[9].inertia[2][2] + v10[2]*links[9].inertia[2][3]) + v10[3]*(-(links[9].mcm[1]*v10[6]) - v10[3]*links[9].inertia[2][3] + v10[2]*links[9].inertia[3][3]) - uex[9].t[1]*SG100[1][1] - uex[9].t[2]*SG100[1][2] - uex[9].t[3]*SG100[1][3] - gravity*links[9].mcm[3]*SG100[2][3] + gravity*links[9].mcm[2]*SG100[3][3];
pv10[5]=(-(links[9].mcm[1]*v10[1]) - links[9].mcm[3]*v10[3])*v10[5] + (links[9].mcm[2]*v10[3] - links[9].m*v10[4])*v10[6] + v10[4]*(links[9].mcm[2]*v10[1] + links[9].m*v10[6]) + v10[1]*(-(links[9].mcm[2]*v10[4]) + v10[3]*links[9].inertia[1][1] - v10[1]*links[9].inertia[1][3]) + v10[2]*(links[9].mcm[1]*v10[4] + links[9].mcm[3]*v10[6] + v10[3]*links[9].inertia[1][2] - v10[1]*links[9].inertia[2][3]) + v10[3]*(-(links[9].mcm[2]*v10[6]) + v10[3]*links[9].inertia[1][3] - v10[1]*links[9].inertia[3][3]) + gravity*links[9].mcm[3]*SG100[1][3] - uex[9].t[1]*SG100[2][1] - uex[9].t[2]*SG100[2][2] - uex[9].t[3]*SG100[2][3] - gravity*links[9].mcm[1]*SG100[3][3];
pv10[6]=(links[9].mcm[3]*v10[2] + links[9].m*v10[4])*v10[5] + v10[4]*(links[9].mcm[3]*v10[1] - links[9].m*v10[5]) + (-(links[9].mcm[1]*v10[1]) - links[9].mcm[2]*v10[2])*v10[6] + v10[1]*(-(links[9].mcm[3]*v10[4]) - v10[2]*links[9].inertia[1][1] + v10[1]*links[9].inertia[1][2]) + v10[2]*(-(links[9].mcm[3]*v10[5]) - v10[2]*links[9].inertia[1][2] + v10[1]*links[9].inertia[2][2]) + v10[3]*(links[9].mcm[1]*v10[4] + links[9].mcm[2]*v10[5] - v10[2]*links[9].inertia[1][3] + v10[1]*links[9].inertia[2][3]) - gravity*links[9].mcm[2]*SG100[1][3] + gravity*links[9].mcm[1]*SG100[2][3] - uex[9].t[1]*SG100[3][1] - uex[9].t[2]*SG100[3][2] - uex[9].t[3]*SG100[3][3];

pv12[1]=-(links[10].mcm[1]*Power(v12[2],2)) - links[10].mcm[1]*Power(v12[3],2) + v12[1]*(links[10].mcm[2]*v12[2] + links[10].mcm[3]*v12[3]) - links[10].m*v12[3]*v12[5] + links[10].m*v12[2]*v12[6] - uex[10].f[1]*SG120[1][1] - uex[10].f[2]*SG120[1][2] + gravity*links[10].m*SG120[1][3] - uex[10].f[3]*SG120[1][3];
pv12[2]=-(links[10].mcm[2]*Power(v12[1],2)) - links[10].mcm[2]*Power(v12[3],2) + v12[2]*(links[10].mcm[1]*v12[1] + links[10].mcm[3]*v12[3]) + links[10].m*v12[3]*v12[4] - links[10].m*v12[1]*v12[6] - uex[10].f[1]*SG120[2][1] - uex[10].f[2]*SG120[2][2] + gravity*links[10].m*SG120[2][3] - uex[10].f[3]*SG120[2][3];
pv12[3]=-(links[10].mcm[3]*Power(v12[1],2)) - links[10].mcm[3]*Power(v12[2],2) + (links[10].mcm[1]*v12[1] + links[10].mcm[2]*v12[2])*v12[3] - links[10].m*v12[2]*v12[4] + links[10].m*v12[1]*v12[5] - uex[10].f[1]*SG120[3][1] - uex[10].f[2]*SG120[3][2] + gravity*links[10].m*SG120[3][3] - uex[10].f[3]*SG120[3][3];
pv12[4]=(-(links[10].mcm[2]*v12[2]) - links[10].mcm[3]*v12[3])*v12[4] + (links[10].mcm[1]*v12[3] + links[10].m*v12[5])*v12[6] + v12[5]*(links[10].mcm[1]*v12[2] - links[10].m*v12[6]) + v12[1]*(links[10].mcm[2]*v12[5] + links[10].mcm[3]*v12[6] - v12[3]*links[10].inertia[1][2] + v12[2]*links[10].inertia[1][3]) + v12[2]*(-(links[10].mcm[1]*v12[5]) - v12[3]*links[10].inertia[2][2] + v12[2]*links[10].inertia[2][3]) + v12[3]*(-(links[10].mcm[1]*v12[6]) - v12[3]*links[10].inertia[2][3] + v12[2]*links[10].inertia[3][3]) - uex[10].t[1]*SG120[1][1] - uex[10].t[2]*SG120[1][2] - uex[10].t[3]*SG120[1][3] - gravity*links[10].mcm[3]*SG120[2][3] + gravity*links[10].mcm[2]*SG120[3][3];
pv12[5]=(-(links[10].mcm[1]*v12[1]) - links[10].mcm[3]*v12[3])*v12[5] + (links[10].mcm[2]*v12[3] - links[10].m*v12[4])*v12[6] + v12[4]*(links[10].mcm[2]*v12[1] + links[10].m*v12[6]) + v12[1]*(-(links[10].mcm[2]*v12[4]) + v12[3]*links[10].inertia[1][1] - v12[1]*links[10].inertia[1][3]) + v12[2]*(links[10].mcm[1]*v12[4] + links[10].mcm[3]*v12[6] + v12[3]*links[10].inertia[1][2] - v12[1]*links[10].inertia[2][3]) + v12[3]*(-(links[10].mcm[2]*v12[6]) + v12[3]*links[10].inertia[1][3] - v12[1]*links[10].inertia[3][3]) + gravity*links[10].mcm[3]*SG120[1][3] - uex[10].t[1]*SG120[2][1] - uex[10].t[2]*SG120[2][2] - uex[10].t[3]*SG120[2][3] - gravity*links[10].mcm[1]*SG120[3][3];
pv12[6]=(links[10].mcm[3]*v12[2] + links[10].m*v12[4])*v12[5] + v12[4]*(links[10].mcm[3]*v12[1] - links[10].m*v12[5]) + (-(links[10].mcm[1]*v12[1]) - links[10].mcm[2]*v12[2])*v12[6] + v12[1]*(-(links[10].mcm[3]*v12[4]) - v12[2]*links[10].inertia[1][1] + v12[1]*links[10].inertia[1][2]) + v12[2]*(-(links[10].mcm[3]*v12[5]) - v12[2]*links[10].inertia[1][2] + v12[1]*links[10].inertia[2][2]) + v12[3]*(links[10].mcm[1]*v12[4] + links[10].mcm[2]*v12[5] - v12[2]*links[10].inertia[1][3] + v12[1]*links[10].inertia[2][3]) - gravity*links[10].mcm[2]*SG120[1][3] + gravity*links[10].mcm[1]*SG120[2][3] - uex[10].t[1]*SG120[3][1] - uex[10].t[2]*SG120[3][2] - uex[10].t[3]*SG120[3][3];



}

/* articulated body inertias and misc variables */

void
master_ForDynArtfunc7(void)
     {




}


void
master_ForDynArtfunc8(void)
     {
JA12[1][2]=0. + links[10].mcm[3];
JA12[1][3]=0. - links[10].mcm[2];
JA12[1][4]=0. + links[10].m;

JA12[2][1]=0. - links[10].mcm[3];
JA12[2][3]=0. + links[10].mcm[1];
JA12[2][5]=0. + links[10].m;

JA12[3][1]=0. + links[10].mcm[2];
JA12[3][2]=0. - links[10].mcm[1];
JA12[3][6]=0. + links[10].m;

JA12[4][1]=0. + links[10].inertia[1][1];
JA12[4][2]=0. + links[10].inertia[1][2];
JA12[4][3]=0. + links[10].inertia[1][3];
JA12[4][5]=0. - links[10].mcm[3];
JA12[4][6]=0. + links[10].mcm[2];

JA12[5][1]=0. + links[10].inertia[1][2];
JA12[5][2]=0. + links[10].inertia[2][2];
JA12[5][3]=0. + links[10].inertia[2][3];
JA12[5][4]=0. + links[10].mcm[3];
JA12[5][6]=0. - links[10].mcm[1];

JA12[6][1]=0. + links[10].inertia[1][3];
JA12[6][2]=0. + links[10].inertia[2][3];
JA12[6][3]=0. + links[10].inertia[3][3];
JA12[6][4]=0. - links[10].mcm[2];
JA12[6][5]=0. + links[10].mcm[1];


h12[1]=JA12[1][3];
h12[2]=JA12[2][3];
h12[4]=JA12[4][3];
h12[5]=JA12[5][3];
h12[6]=JA12[6][3];

d[12]=1.e-10 + h12[6];

T1712[1][1]=-((h12[1]*h12[4])/d[12]);
T1712[1][2]=-((h12[1]*h12[5])/d[12]) + JA12[1][2];
T1712[1][3]=-((h12[1]*h12[6])/d[12]) + JA12[1][3];
T1712[1][4]=-(Power(h12[1],2)/d[12]) + JA12[1][4];
T1712[1][5]=-((h12[1]*h12[2])/d[12]);

T1712[2][1]=-((h12[2]*h12[4])/d[12]) + JA12[2][1];
T1712[2][2]=-((h12[2]*h12[5])/d[12]);
T1712[2][3]=-((h12[2]*h12[6])/d[12]) + JA12[2][3];
T1712[2][4]=-((h12[1]*h12[2])/d[12]);
T1712[2][5]=-(Power(h12[2],2)/d[12]) + JA12[2][5];

T1712[3][1]=JA12[3][1];
T1712[3][2]=JA12[3][2];
T1712[3][6]=JA12[3][6];

T1712[4][1]=-(Power(h12[4],2)/d[12]) + JA12[4][1];
T1712[4][2]=-((h12[4]*h12[5])/d[12]) + JA12[4][2];
T1712[4][3]=-((h12[4]*h12[6])/d[12]) + JA12[4][3];
T1712[4][4]=-((h12[1]*h12[4])/d[12]);
T1712[4][5]=-((h12[2]*h12[4])/d[12]) + JA12[4][5];
T1712[4][6]=JA12[4][6];

T1712[5][1]=-((h12[4]*h12[5])/d[12]) + JA12[5][1];
T1712[5][2]=-(Power(h12[5],2)/d[12]) + JA12[5][2];
T1712[5][3]=-((h12[5]*h12[6])/d[12]) + JA12[5][3];
T1712[5][4]=-((h12[1]*h12[5])/d[12]) + JA12[5][4];
T1712[5][5]=-((h12[2]*h12[5])/d[12]);
T1712[5][6]=JA12[5][6];

T1712[6][1]=-((h12[4]*h12[6])/d[12]) + JA12[6][1];
T1712[6][2]=-((h12[5]*h12[6])/d[12]) + JA12[6][2];
T1712[6][3]=-(Power(h12[6],2)/d[12]) + JA12[6][3];
T1712[6][4]=-((h12[1]*h12[6])/d[12]) + JA12[6][4];
T1712[6][5]=-((h12[2]*h12[6])/d[12]) + JA12[6][5];


T712[1][1]=S127[1][1]*(Si712[1][1]*T1712[1][1] + Si712[1][2]*T1712[2][1]) + S127[2][1]*(Si712[1][1]*T1712[1][2] + Si712[1][2]*T1712[2][2]) - l6z*S127[1][2]*(Si712[1][1]*T1712[1][4] + Si712[1][2]*T1712[2][4]) - l6z*S127[2][2]*(Si712[1][1]*T1712[1][5] + Si712[1][2]*T1712[2][5]);
T712[1][2]=S127[1][2]*(Si712[1][1]*T1712[1][1] + Si712[1][2]*T1712[2][1]) + S127[2][2]*(Si712[1][1]*T1712[1][2] + Si712[1][2]*T1712[2][2]) + l6z*S127[1][1]*(Si712[1][1]*T1712[1][4] + Si712[1][2]*T1712[2][4]) + l6z*S127[2][1]*(Si712[1][1]*T1712[1][5] + Si712[1][2]*T1712[2][5]);
T712[1][3]=Si712[1][1]*T1712[1][3] + Si712[1][2]*T1712[2][3] + (-(l6y*S127[1][1]) - l6x*S127[1][2])*(Si712[1][1]*T1712[1][4] + Si712[1][2]*T1712[2][4]) + (-(l6y*S127[2][1]) - l6x*S127[2][2])*(Si712[1][1]*T1712[1][5] + Si712[1][2]*T1712[2][5]);
T712[1][4]=S127[1][1]*(Si712[1][1]*T1712[1][4] + Si712[1][2]*T1712[2][4]) + S127[2][1]*(Si712[1][1]*T1712[1][5] + Si712[1][2]*T1712[2][5]);
T712[1][5]=S127[1][2]*(Si712[1][1]*T1712[1][4] + Si712[1][2]*T1712[2][4]) + S127[2][2]*(Si712[1][1]*T1712[1][5] + Si712[1][2]*T1712[2][5]);

T712[2][1]=S127[1][1]*(Si712[2][1]*T1712[1][1] + Si712[2][2]*T1712[2][1]) + S127[2][1]*(Si712[2][1]*T1712[1][2] + Si712[2][2]*T1712[2][2]) - l6z*S127[1][2]*(Si712[2][1]*T1712[1][4] + Si712[2][2]*T1712[2][4]) - l6z*S127[2][2]*(Si712[2][1]*T1712[1][5] + Si712[2][2]*T1712[2][5]);
T712[2][2]=S127[1][2]*(Si712[2][1]*T1712[1][1] + Si712[2][2]*T1712[2][1]) + S127[2][2]*(Si712[2][1]*T1712[1][2] + Si712[2][2]*T1712[2][2]) + l6z*S127[1][1]*(Si712[2][1]*T1712[1][4] + Si712[2][2]*T1712[2][4]) + l6z*S127[2][1]*(Si712[2][1]*T1712[1][5] + Si712[2][2]*T1712[2][5]);
T712[2][3]=Si712[2][1]*T1712[1][3] + Si712[2][2]*T1712[2][3] + (-(l6y*S127[1][1]) - l6x*S127[1][2])*(Si712[2][1]*T1712[1][4] + Si712[2][2]*T1712[2][4]) + (-(l6y*S127[2][1]) - l6x*S127[2][2])*(Si712[2][1]*T1712[1][5] + Si712[2][2]*T1712[2][5]);
T712[2][4]=S127[1][1]*(Si712[2][1]*T1712[1][4] + Si712[2][2]*T1712[2][4]) + S127[2][1]*(Si712[2][1]*T1712[1][5] + Si712[2][2]*T1712[2][5]);
T712[2][5]=S127[1][2]*(Si712[2][1]*T1712[1][4] + Si712[2][2]*T1712[2][4]) + S127[2][2]*(Si712[2][1]*T1712[1][5] + Si712[2][2]*T1712[2][5]);

T712[3][1]=S127[1][1]*T1712[3][1] + S127[2][1]*T1712[3][2] + l6y*T1712[3][6];
T712[3][2]=S127[1][2]*T1712[3][1] + S127[2][2]*T1712[3][2] + l6x*T1712[3][6];
T712[3][6]=T1712[3][6];

T712[4][1]=S127[1][1]*(-(l6z*Si712[2][1]*T1712[1][1]) - l6z*Si712[2][2]*T1712[2][1] + l6y*T1712[3][1] + Si712[1][1]*T1712[4][1] + Si712[1][2]*T1712[5][1]) + S127[2][1]*(-(l6z*Si712[2][1]*T1712[1][2]) - l6z*Si712[2][2]*T1712[2][2] + l6y*T1712[3][2] + Si712[1][1]*T1712[4][2] + Si712[1][2]*T1712[5][2]) - l6z*S127[1][2]*(-(l6z*Si712[2][1]*T1712[1][4]) - l6z*Si712[2][2]*T1712[2][4] + Si712[1][1]*T1712[4][4] + Si712[1][2]*T1712[5][4]) - l6z*S127[2][2]*(-(l6z*Si712[2][1]*T1712[1][5]) - l6z*Si712[2][2]*T1712[2][5] + Si712[1][1]*T1712[4][5] + Si712[1][2]*T1712[5][5]) + l6y*(l6y*T1712[3][6] + Si712[1][1]*T1712[4][6] + Si712[1][2]*T1712[5][6]);
T712[4][2]=S127[1][2]*(-(l6z*Si712[2][1]*T1712[1][1]) - l6z*Si712[2][2]*T1712[2][1] + l6y*T1712[3][1] + Si712[1][1]*T1712[4][1] + Si712[1][2]*T1712[5][1]) + S127[2][2]*(-(l6z*Si712[2][1]*T1712[1][2]) - l6z*Si712[2][2]*T1712[2][2] + l6y*T1712[3][2] + Si712[1][1]*T1712[4][2] + Si712[1][2]*T1712[5][2]) + l6z*S127[1][1]*(-(l6z*Si712[2][1]*T1712[1][4]) - l6z*Si712[2][2]*T1712[2][4] + Si712[1][1]*T1712[4][4] + Si712[1][2]*T1712[5][4]) + l6z*S127[2][1]*(-(l6z*Si712[2][1]*T1712[1][5]) - l6z*Si712[2][2]*T1712[2][5] + Si712[1][1]*T1712[4][5] + Si712[1][2]*T1712[5][5]) + l6x*(l6y*T1712[3][6] + Si712[1][1]*T1712[4][6] + Si712[1][2]*T1712[5][6]);
T712[4][3]=-(l6z*Si712[2][1]*T1712[1][3]) - l6z*Si712[2][2]*T1712[2][3] + Si712[1][1]*T1712[4][3] + Si712[1][2]*T1712[5][3] + (-(l6y*S127[1][1]) - l6x*S127[1][2])*(-(l6z*Si712[2][1]*T1712[1][4]) - l6z*Si712[2][2]*T1712[2][4] + Si712[1][1]*T1712[4][4] + Si712[1][2]*T1712[5][4]) + (-(l6y*S127[2][1]) - l6x*S127[2][2])*(-(l6z*Si712[2][1]*T1712[1][5]) - l6z*Si712[2][2]*T1712[2][5] + Si712[1][1]*T1712[4][5] + Si712[1][2]*T1712[5][5]);
T712[4][4]=S127[1][1]*(-(l6z*Si712[2][1]*T1712[1][4]) - l6z*Si712[2][2]*T1712[2][4] + Si712[1][1]*T1712[4][4] + Si712[1][2]*T1712[5][4]) + S127[2][1]*(-(l6z*Si712[2][1]*T1712[1][5]) - l6z*Si712[2][2]*T1712[2][5] + Si712[1][1]*T1712[4][5] + Si712[1][2]*T1712[5][5]);
T712[4][5]=S127[1][2]*(-(l6z*Si712[2][1]*T1712[1][4]) - l6z*Si712[2][2]*T1712[2][4] + Si712[1][1]*T1712[4][4] + Si712[1][2]*T1712[5][4]) + S127[2][2]*(-(l6z*Si712[2][1]*T1712[1][5]) - l6z*Si712[2][2]*T1712[2][5] + Si712[1][1]*T1712[4][5] + Si712[1][2]*T1712[5][5]);
T712[4][6]=l6y*T1712[3][6] + Si712[1][1]*T1712[4][6] + Si712[1][2]*T1712[5][6];

T712[5][1]=S127[1][1]*(l6z*Si712[1][1]*T1712[1][1] + l6z*Si712[1][2]*T1712[2][1] + l6x*T1712[3][1] + Si712[2][1]*T1712[4][1] + Si712[2][2]*T1712[5][1]) + S127[2][1]*(l6z*Si712[1][1]*T1712[1][2] + l6z*Si712[1][2]*T1712[2][2] + l6x*T1712[3][2] + Si712[2][1]*T1712[4][2] + Si712[2][2]*T1712[5][2]) - l6z*S127[1][2]*(l6z*Si712[1][1]*T1712[1][4] + l6z*Si712[1][2]*T1712[2][4] + Si712[2][1]*T1712[4][4] + Si712[2][2]*T1712[5][4]) - l6z*S127[2][2]*(l6z*Si712[1][1]*T1712[1][5] + l6z*Si712[1][2]*T1712[2][5] + Si712[2][1]*T1712[4][5] + Si712[2][2]*T1712[5][5]) + l6y*(l6x*T1712[3][6] + Si712[2][1]*T1712[4][6] + Si712[2][2]*T1712[5][6]);
T712[5][2]=S127[1][2]*(l6z*Si712[1][1]*T1712[1][1] + l6z*Si712[1][2]*T1712[2][1] + l6x*T1712[3][1] + Si712[2][1]*T1712[4][1] + Si712[2][2]*T1712[5][1]) + S127[2][2]*(l6z*Si712[1][1]*T1712[1][2] + l6z*Si712[1][2]*T1712[2][2] + l6x*T1712[3][2] + Si712[2][1]*T1712[4][2] + Si712[2][2]*T1712[5][2]) + l6z*S127[1][1]*(l6z*Si712[1][1]*T1712[1][4] + l6z*Si712[1][2]*T1712[2][4] + Si712[2][1]*T1712[4][4] + Si712[2][2]*T1712[5][4]) + l6z*S127[2][1]*(l6z*Si712[1][1]*T1712[1][5] + l6z*Si712[1][2]*T1712[2][5] + Si712[2][1]*T1712[4][5] + Si712[2][2]*T1712[5][5]) + l6x*(l6x*T1712[3][6] + Si712[2][1]*T1712[4][6] + Si712[2][2]*T1712[5][6]);
T712[5][3]=l6z*Si712[1][1]*T1712[1][3] + l6z*Si712[1][2]*T1712[2][3] + Si712[2][1]*T1712[4][3] + Si712[2][2]*T1712[5][3] + (-(l6y*S127[1][1]) - l6x*S127[1][2])*(l6z*Si712[1][1]*T1712[1][4] + l6z*Si712[1][2]*T1712[2][4] + Si712[2][1]*T1712[4][4] + Si712[2][2]*T1712[5][4]) + (-(l6y*S127[2][1]) - l6x*S127[2][2])*(l6z*Si712[1][1]*T1712[1][5] + l6z*Si712[1][2]*T1712[2][5] + Si712[2][1]*T1712[4][5] + Si712[2][2]*T1712[5][5]);
T712[5][4]=S127[1][1]*(l6z*Si712[1][1]*T1712[1][4] + l6z*Si712[1][2]*T1712[2][4] + Si712[2][1]*T1712[4][4] + Si712[2][2]*T1712[5][4]) + S127[2][1]*(l6z*Si712[1][1]*T1712[1][5] + l6z*Si712[1][2]*T1712[2][5] + Si712[2][1]*T1712[4][5] + Si712[2][2]*T1712[5][5]);
T712[5][5]=S127[1][2]*(l6z*Si712[1][1]*T1712[1][4] + l6z*Si712[1][2]*T1712[2][4] + Si712[2][1]*T1712[4][4] + Si712[2][2]*T1712[5][4]) + S127[2][2]*(l6z*Si712[1][1]*T1712[1][5] + l6z*Si712[1][2]*T1712[2][5] + Si712[2][1]*T1712[4][5] + Si712[2][2]*T1712[5][5]);
T712[5][6]=l6x*T1712[3][6] + Si712[2][1]*T1712[4][6] + Si712[2][2]*T1712[5][6];

T712[6][1]=S127[1][1]*((-(l6y*Si712[1][1]) - l6x*Si712[2][1])*T1712[1][1] + (-(l6y*Si712[1][2]) - l6x*Si712[2][2])*T1712[2][1] + T1712[6][1]) + S127[2][1]*((-(l6y*Si712[1][1]) - l6x*Si712[2][1])*T1712[1][2] + (-(l6y*Si712[1][2]) - l6x*Si712[2][2])*T1712[2][2] + T1712[6][2]) - l6z*S127[1][2]*((-(l6y*Si712[1][1]) - l6x*Si712[2][1])*T1712[1][4] + (-(l6y*Si712[1][2]) - l6x*Si712[2][2])*T1712[2][4] + T1712[6][4]) - l6z*S127[2][2]*((-(l6y*Si712[1][1]) - l6x*Si712[2][1])*T1712[1][5] + (-(l6y*Si712[1][2]) - l6x*Si712[2][2])*T1712[2][5] + T1712[6][5]);
T712[6][2]=S127[1][2]*((-(l6y*Si712[1][1]) - l6x*Si712[2][1])*T1712[1][1] + (-(l6y*Si712[1][2]) - l6x*Si712[2][2])*T1712[2][1] + T1712[6][1]) + S127[2][2]*((-(l6y*Si712[1][1]) - l6x*Si712[2][1])*T1712[1][2] + (-(l6y*Si712[1][2]) - l6x*Si712[2][2])*T1712[2][2] + T1712[6][2]) + l6z*S127[1][1]*((-(l6y*Si712[1][1]) - l6x*Si712[2][1])*T1712[1][4] + (-(l6y*Si712[1][2]) - l6x*Si712[2][2])*T1712[2][4] + T1712[6][4]) + l6z*S127[2][1]*((-(l6y*Si712[1][1]) - l6x*Si712[2][1])*T1712[1][5] + (-(l6y*Si712[1][2]) - l6x*Si712[2][2])*T1712[2][5] + T1712[6][5]);
T712[6][3]=(-(l6y*Si712[1][1]) - l6x*Si712[2][1])*T1712[1][3] + (-(l6y*Si712[1][2]) - l6x*Si712[2][2])*T1712[2][3] + T1712[6][3] + (-(l6y*S127[1][1]) - l6x*S127[1][2])*((-(l6y*Si712[1][1]) - l6x*Si712[2][1])*T1712[1][4] + (-(l6y*Si712[1][2]) - l6x*Si712[2][2])*T1712[2][4] + T1712[6][4]) + (-(l6y*S127[2][1]) - l6x*S127[2][2])*((-(l6y*Si712[1][1]) - l6x*Si712[2][1])*T1712[1][5] + (-(l6y*Si712[1][2]) - l6x*Si712[2][2])*T1712[2][5] + T1712[6][5]);
T712[6][4]=S127[1][1]*((-(l6y*Si712[1][1]) - l6x*Si712[2][1])*T1712[1][4] + (-(l6y*Si712[1][2]) - l6x*Si712[2][2])*T1712[2][4] + T1712[6][4]) + S127[2][1]*((-(l6y*Si712[1][1]) - l6x*Si712[2][1])*T1712[1][5] + (-(l6y*Si712[1][2]) - l6x*Si712[2][2])*T1712[2][5] + T1712[6][5]);
T712[6][5]=S127[1][2]*((-(l6y*Si712[1][1]) - l6x*Si712[2][1])*T1712[1][4] + (-(l6y*Si712[1][2]) - l6x*Si712[2][2])*T1712[2][4] + T1712[6][4]) + S127[2][2]*((-(l6y*Si712[1][1]) - l6x*Si712[2][1])*T1712[1][5] + (-(l6y*Si712[1][2]) - l6x*Si712[2][2])*T1712[2][5] + T1712[6][5]);



}


void
master_ForDynArtfunc9(void)
     {




}


void
master_ForDynArtfunc10(void)
      {
JA10[1][2]=0. + links[9].mcm[3];
JA10[1][3]=0. - links[9].mcm[2];
JA10[1][4]=0. + links[9].m;

JA10[2][1]=0. - links[9].mcm[3];
JA10[2][3]=0. + links[9].mcm[1];
JA10[2][5]=0. + links[9].m;

JA10[3][1]=0. + links[9].mcm[2];
JA10[3][2]=0. - links[9].mcm[1];
JA10[3][6]=0. + links[9].m;

JA10[4][1]=0. + links[9].inertia[1][1];
JA10[4][2]=0. + links[9].inertia[1][2];
JA10[4][3]=0. + links[9].inertia[1][3];
JA10[4][5]=0. - links[9].mcm[3];
JA10[4][6]=0. + links[9].mcm[2];

JA10[5][1]=0. + links[9].inertia[1][2];
JA10[5][2]=0. + links[9].inertia[2][2];
JA10[5][3]=0. + links[9].inertia[2][3];
JA10[5][4]=0. + links[9].mcm[3];
JA10[5][6]=0. - links[9].mcm[1];

JA10[6][1]=0. + links[9].inertia[1][3];
JA10[6][2]=0. + links[9].inertia[2][3];
JA10[6][3]=0. + links[9].inertia[3][3];
JA10[6][4]=0. - links[9].mcm[2];
JA10[6][5]=0. + links[9].mcm[1];


h10[1]=JA10[1][3];
h10[2]=JA10[2][3];
h10[4]=JA10[4][3];
h10[5]=JA10[5][3];
h10[6]=JA10[6][3];

d[10]=1.e-10 + h10[6];

T1910[1][1]=-((h10[1]*h10[4])/d[10]);
T1910[1][2]=-((h10[1]*h10[5])/d[10]) + JA10[1][2];
T1910[1][3]=-((h10[1]*h10[6])/d[10]) + JA10[1][3];
T1910[1][4]=-(Power(h10[1],2)/d[10]) + JA10[1][4];
T1910[1][5]=-((h10[1]*h10[2])/d[10]);

T1910[2][1]=-((h10[2]*h10[4])/d[10]) + JA10[2][1];
T1910[2][2]=-((h10[2]*h10[5])/d[10]);
T1910[2][3]=-((h10[2]*h10[6])/d[10]) + JA10[2][3];
T1910[2][4]=-((h10[1]*h10[2])/d[10]);
T1910[2][5]=-(Power(h10[2],2)/d[10]) + JA10[2][5];

T1910[3][1]=JA10[3][1];
T1910[3][2]=JA10[3][2];
T1910[3][6]=JA10[3][6];

T1910[4][1]=-(Power(h10[4],2)/d[10]) + JA10[4][1];
T1910[4][2]=-((h10[4]*h10[5])/d[10]) + JA10[4][2];
T1910[4][3]=-((h10[4]*h10[6])/d[10]) + JA10[4][3];
T1910[4][4]=-((h10[1]*h10[4])/d[10]);
T1910[4][5]=-((h10[2]*h10[4])/d[10]) + JA10[4][5];
T1910[4][6]=JA10[4][6];

T1910[5][1]=-((h10[4]*h10[5])/d[10]) + JA10[5][1];
T1910[5][2]=-(Power(h10[5],2)/d[10]) + JA10[5][2];
T1910[5][3]=-((h10[5]*h10[6])/d[10]) + JA10[5][3];
T1910[5][4]=-((h10[1]*h10[5])/d[10]) + JA10[5][4];
T1910[5][5]=-((h10[2]*h10[5])/d[10]);
T1910[5][6]=JA10[5][6];

T1910[6][1]=-((h10[4]*h10[6])/d[10]) + JA10[6][1];
T1910[6][2]=-((h10[5]*h10[6])/d[10]) + JA10[6][2];
T1910[6][3]=-(Power(h10[6],2)/d[10]) + JA10[6][3];
T1910[6][4]=-((h10[1]*h10[6])/d[10]) + JA10[6][4];
T1910[6][5]=-((h10[2]*h10[6])/d[10]) + JA10[6][5];


T910[1][2]=S109[1][2]*T1910[3][1] + S109[2][2]*T1910[3][2];
T910[1][3]=S109[1][3]*T1910[3][1] + S109[2][3]*T1910[3][2];
T910[1][4]=T1910[3][6];

T910[2][1]=Si910[2][1]*T1910[1][3] + Si910[2][2]*T1910[2][3];
T910[2][2]=S109[1][2]*(Si910[2][1]*T1910[1][1] + Si910[2][2]*T1910[2][1]) + S109[2][2]*(Si910[2][1]*T1910[1][2] + Si910[2][2]*T1910[2][2]);
T910[2][3]=S109[1][3]*(Si910[2][1]*T1910[1][1] + Si910[2][2]*T1910[2][1]) + S109[2][3]*(Si910[2][1]*T1910[1][2] + Si910[2][2]*T1910[2][2]);
T910[2][5]=S109[1][2]*(Si910[2][1]*T1910[1][4] + Si910[2][2]*T1910[2][4]) + S109[2][2]*(Si910[2][1]*T1910[1][5] + Si910[2][2]*T1910[2][5]);
T910[2][6]=S109[1][3]*(Si910[2][1]*T1910[1][4] + Si910[2][2]*T1910[2][4]) + S109[2][3]*(Si910[2][1]*T1910[1][5] + Si910[2][2]*T1910[2][5]);

T910[3][1]=Si910[3][1]*T1910[1][3] + Si910[3][2]*T1910[2][3];
T910[3][2]=S109[1][2]*(Si910[3][1]*T1910[1][1] + Si910[3][2]*T1910[2][1]) + S109[2][2]*(Si910[3][1]*T1910[1][2] + Si910[3][2]*T1910[2][2]);
T910[3][3]=S109[1][3]*(Si910[3][1]*T1910[1][1] + Si910[3][2]*T1910[2][1]) + S109[2][3]*(Si910[3][1]*T1910[1][2] + Si910[3][2]*T1910[2][2]);
T910[3][5]=S109[1][2]*(Si910[3][1]*T1910[1][4] + Si910[3][2]*T1910[2][4]) + S109[2][2]*(Si910[3][1]*T1910[1][5] + Si910[3][2]*T1910[2][5]);
T910[3][6]=S109[1][3]*(Si910[3][1]*T1910[1][4] + Si910[3][2]*T1910[2][4]) + S109[2][3]*(Si910[3][1]*T1910[1][5] + Si910[3][2]*T1910[2][5]);

T910[4][1]=T1910[6][3];
T910[4][2]=S109[1][2]*T1910[6][1] + S109[2][2]*T1910[6][2];
T910[4][3]=S109[1][3]*T1910[6][1] + S109[2][3]*T1910[6][2];
T910[4][5]=S109[1][2]*T1910[6][4] + S109[2][2]*T1910[6][5];
T910[4][6]=S109[1][3]*T1910[6][4] + S109[2][3]*T1910[6][5];

T910[5][1]=Si910[2][1]*T1910[4][3] + Si910[2][2]*T1910[5][3];
T910[5][2]=S109[1][2]*(Si910[2][1]*T1910[4][1] + Si910[2][2]*T1910[5][1]) + S109[2][2]*(Si910[2][1]*T1910[4][2] + Si910[2][2]*T1910[5][2]);
T910[5][3]=S109[1][3]*(Si910[2][1]*T1910[4][1] + Si910[2][2]*T1910[5][1]) + S109[2][3]*(Si910[2][1]*T1910[4][2] + Si910[2][2]*T1910[5][2]);
T910[5][4]=Si910[2][1]*T1910[4][6] + Si910[2][2]*T1910[5][6];
T910[5][5]=S109[1][2]*(Si910[2][1]*T1910[4][4] + Si910[2][2]*T1910[5][4]) + S109[2][2]*(Si910[2][1]*T1910[4][5] + Si910[2][2]*T1910[5][5]);
T910[5][6]=S109[1][3]*(Si910[2][1]*T1910[4][4] + Si910[2][2]*T1910[5][4]) + S109[2][3]*(Si910[2][1]*T1910[4][5] + Si910[2][2]*T1910[5][5]);

T910[6][1]=Si910[3][1]*T1910[4][3] + Si910[3][2]*T1910[5][3];
T910[6][2]=S109[1][2]*(Si910[3][1]*T1910[4][1] + Si910[3][2]*T1910[5][1]) + S109[2][2]*(Si910[3][1]*T1910[4][2] + Si910[3][2]*T1910[5][2]);
T910[6][3]=S109[1][3]*(Si910[3][1]*T1910[4][1] + Si910[3][2]*T1910[5][1]) + S109[2][3]*(Si910[3][1]*T1910[4][2] + Si910[3][2]*T1910[5][2]);
T910[6][4]=Si910[3][1]*T1910[4][6] + Si910[3][2]*T1910[5][6];
T910[6][5]=S109[1][2]*(Si910[3][1]*T1910[4][4] + Si910[3][2]*T1910[5][4]) + S109[2][2]*(Si910[3][1]*T1910[4][5] + Si910[3][2]*T1910[5][5]);
T910[6][6]=S109[1][3]*(Si910[3][1]*T1910[4][4] + Si910[3][2]*T1910[5][4]) + S109[2][3]*(Si910[3][1]*T1910[4][5] + Si910[3][2]*T1910[5][5]);



}


void
master_ForDynArtfunc11(void)
      {
JA9[1][2]=links[8].mcm[3] + T910[1][2];
JA9[1][3]=-links[8].mcm[2] + T910[1][3];
JA9[1][4]=links[8].m + T910[1][4];

JA9[2][1]=-links[8].mcm[3] + T910[2][1];
JA9[2][2]=T910[2][2];
JA9[2][3]=links[8].mcm[1] + T910[2][3];
JA9[2][5]=links[8].m + T910[2][5];
JA9[2][6]=T910[2][6];

JA9[3][1]=links[8].mcm[2] + T910[3][1];
JA9[3][2]=-links[8].mcm[1] + T910[3][2];
JA9[3][3]=T910[3][3];
JA9[3][5]=T910[3][5];
JA9[3][6]=links[8].m + T910[3][6];

JA9[4][1]=links[8].inertia[1][1] + T910[4][1];
JA9[4][2]=links[8].inertia[1][2] + T910[4][2];
JA9[4][3]=links[8].inertia[1][3] + T910[4][3];
JA9[4][5]=-links[8].mcm[3] + T910[4][5];
JA9[4][6]=links[8].mcm[2] + T910[4][6];

JA9[5][1]=links[8].inertia[1][2] + T910[5][1];
JA9[5][2]=links[8].inertia[2][2] + T910[5][2];
JA9[5][3]=links[8].inertia[2][3] + T910[5][3];
JA9[5][4]=links[8].mcm[3] + T910[5][4];
JA9[5][5]=T910[5][5];
JA9[5][6]=-links[8].mcm[1] + T910[5][6];

JA9[6][1]=links[8].inertia[1][3] + T910[6][1];
JA9[6][2]=links[8].inertia[2][3] + T910[6][2];
JA9[6][3]=links[8].inertia[3][3] + T910[6][3];
JA9[6][4]=-links[8].mcm[2] + T910[6][4];
JA9[6][5]=links[8].mcm[1] + T910[6][5];
JA9[6][6]=T910[6][6];


h9[1]=JA9[1][3];
h9[2]=JA9[2][3];
h9[3]=JA9[3][3];
h9[4]=JA9[4][3];
h9[5]=JA9[5][3];
h9[6]=JA9[6][3];

d[9]=1.e-10 + h9[6];

T179[1][1]=-((h9[1]*h9[4])/d[9]);
T179[1][2]=-((h9[1]*h9[5])/d[9]) + JA9[1][2];
T179[1][3]=-((h9[1]*h9[6])/d[9]) + JA9[1][3];
T179[1][4]=-(Power(h9[1],2)/d[9]) + JA9[1][4];
T179[1][5]=-((h9[1]*h9[2])/d[9]);
T179[1][6]=-((h9[1]*h9[3])/d[9]);

T179[2][1]=-((h9[2]*h9[4])/d[9]) + JA9[2][1];
T179[2][2]=-((h9[2]*h9[5])/d[9]) + JA9[2][2];
T179[2][3]=-((h9[2]*h9[6])/d[9]) + JA9[2][3];
T179[2][4]=-((h9[1]*h9[2])/d[9]);
T179[2][5]=-(Power(h9[2],2)/d[9]) + JA9[2][5];
T179[2][6]=-((h9[2]*h9[3])/d[9]) + JA9[2][6];

T179[3][1]=-((h9[3]*h9[4])/d[9]) + JA9[3][1];
T179[3][2]=-((h9[3]*h9[5])/d[9]) + JA9[3][2];
T179[3][3]=-((h9[3]*h9[6])/d[9]) + JA9[3][3];
T179[3][4]=-((h9[1]*h9[3])/d[9]);
T179[3][5]=-((h9[2]*h9[3])/d[9]) + JA9[3][5];
T179[3][6]=-(Power(h9[3],2)/d[9]) + JA9[3][6];

T179[4][1]=-(Power(h9[4],2)/d[9]) + JA9[4][1];
T179[4][2]=-((h9[4]*h9[5])/d[9]) + JA9[4][2];
T179[4][3]=-((h9[4]*h9[6])/d[9]) + JA9[4][3];
T179[4][4]=-((h9[1]*h9[4])/d[9]);
T179[4][5]=-((h9[2]*h9[4])/d[9]) + JA9[4][5];
T179[4][6]=-((h9[3]*h9[4])/d[9]) + JA9[4][6];

T179[5][1]=-((h9[4]*h9[5])/d[9]) + JA9[5][1];
T179[5][2]=-(Power(h9[5],2)/d[9]) + JA9[5][2];
T179[5][3]=-((h9[5]*h9[6])/d[9]) + JA9[5][3];
T179[5][4]=-((h9[1]*h9[5])/d[9]) + JA9[5][4];
T179[5][5]=-((h9[2]*h9[5])/d[9]) + JA9[5][5];
T179[5][6]=-((h9[3]*h9[5])/d[9]) + JA9[5][6];

T179[6][1]=-((h9[4]*h9[6])/d[9]) + JA9[6][1];
T179[6][2]=-((h9[5]*h9[6])/d[9]) + JA9[6][2];
T179[6][3]=-(Power(h9[6],2)/d[9]) + JA9[6][3];
T179[6][4]=-((h9[1]*h9[6])/d[9]) + JA9[6][4];
T179[6][5]=-((h9[2]*h9[6])/d[9]) + JA9[6][5];
T179[6][6]=-((h9[3]*h9[6])/d[9]) + JA9[6][6];


T79[1][1]=T179[3][3] + l7z*S97[1][2]*T179[3][4] + l7z*S97[2][2]*T179[3][5];
T79[1][2]=-(S97[1][2]*T179[3][1]) - S97[2][2]*T179[3][2] - l6x*S97[1][3]*T179[3][4] - l6x*S97[2][3]*T179[3][5] + l7z*T179[3][6];
T79[1][3]=-(S97[1][3]*T179[3][1]) - S97[2][3]*T179[3][2] + l6x*S97[1][2]*T179[3][4] + l6x*S97[2][2]*T179[3][5];
T79[1][4]=T179[3][6];
T79[1][5]=-(S97[1][2]*T179[3][4]) - S97[2][2]*T179[3][5];
T79[1][6]=-(S97[1][3]*T179[3][4]) - S97[2][3]*T179[3][5];

T79[2][1]=-(Si79[2][1]*T179[1][3]) - Si79[2][2]*T179[2][3] - l7z*S97[1][2]*(Si79[2][1]*T179[1][4] + Si79[2][2]*T179[2][4]) - l7z*S97[2][2]*(Si79[2][1]*T179[1][5] + Si79[2][2]*T179[2][5]);
T79[2][2]=S97[1][2]*(Si79[2][1]*T179[1][1] + Si79[2][2]*T179[2][1]) + S97[2][2]*(Si79[2][1]*T179[1][2] + Si79[2][2]*T179[2][2]) + l6x*S97[1][3]*(Si79[2][1]*T179[1][4] + Si79[2][2]*T179[2][4]) + l6x*S97[2][3]*(Si79[2][1]*T179[1][5] + Si79[2][2]*T179[2][5]) - l7z*(Si79[2][1]*T179[1][6] + Si79[2][2]*T179[2][6]);
T79[2][3]=S97[1][3]*(Si79[2][1]*T179[1][1] + Si79[2][2]*T179[2][1]) + S97[2][3]*(Si79[2][1]*T179[1][2] + Si79[2][2]*T179[2][2]) - l6x*S97[1][2]*(Si79[2][1]*T179[1][4] + Si79[2][2]*T179[2][4]) - l6x*S97[2][2]*(Si79[2][1]*T179[1][5] + Si79[2][2]*T179[2][5]);
T79[2][4]=-(Si79[2][1]*T179[1][6]) - Si79[2][2]*T179[2][6];
T79[2][5]=S97[1][2]*(Si79[2][1]*T179[1][4] + Si79[2][2]*T179[2][4]) + S97[2][2]*(Si79[2][1]*T179[1][5] + Si79[2][2]*T179[2][5]);
T79[2][6]=S97[1][3]*(Si79[2][1]*T179[1][4] + Si79[2][2]*T179[2][4]) + S97[2][3]*(Si79[2][1]*T179[1][5] + Si79[2][2]*T179[2][5]);

T79[3][1]=-(Si79[3][1]*T179[1][3]) - Si79[3][2]*T179[2][3] - l7z*S97[1][2]*(Si79[3][1]*T179[1][4] + Si79[3][2]*T179[2][4]) - l7z*S97[2][2]*(Si79[3][1]*T179[1][5] + Si79[3][2]*T179[2][5]);
T79[3][2]=S97[1][2]*(Si79[3][1]*T179[1][1] + Si79[3][2]*T179[2][1]) + S97[2][2]*(Si79[3][1]*T179[1][2] + Si79[3][2]*T179[2][2]) + l6x*S97[1][3]*(Si79[3][1]*T179[1][4] + Si79[3][2]*T179[2][4]) + l6x*S97[2][3]*(Si79[3][1]*T179[1][5] + Si79[3][2]*T179[2][5]) - l7z*(Si79[3][1]*T179[1][6] + Si79[3][2]*T179[2][6]);
T79[3][3]=S97[1][3]*(Si79[3][1]*T179[1][1] + Si79[3][2]*T179[2][1]) + S97[2][3]*(Si79[3][1]*T179[1][2] + Si79[3][2]*T179[2][2]) - l6x*S97[1][2]*(Si79[3][1]*T179[1][4] + Si79[3][2]*T179[2][4]) - l6x*S97[2][2]*(Si79[3][1]*T179[1][5] + Si79[3][2]*T179[2][5]);
T79[3][4]=-(Si79[3][1]*T179[1][6]) - Si79[3][2]*T179[2][6];
T79[3][5]=S97[1][2]*(Si79[3][1]*T179[1][4] + Si79[3][2]*T179[2][4]) + S97[2][2]*(Si79[3][1]*T179[1][5] + Si79[3][2]*T179[2][5]);
T79[3][6]=S97[1][3]*(Si79[3][1]*T179[1][4] + Si79[3][2]*T179[2][4]) + S97[2][3]*(Si79[3][1]*T179[1][5] + Si79[3][2]*T179[2][5]);

T79[4][1]=l7z*Si79[2][1]*T179[1][3] + l7z*Si79[2][2]*T179[2][3] + T179[6][3] - l7z*S97[1][2]*(-(l7z*Si79[2][1]*T179[1][4]) - l7z*Si79[2][2]*T179[2][4] - T179[6][4]) - l7z*S97[2][2]*(-(l7z*Si79[2][1]*T179[1][5]) - l7z*Si79[2][2]*T179[2][5] - T179[6][5]);
T79[4][2]=S97[1][2]*(-(l7z*Si79[2][1]*T179[1][1]) - l7z*Si79[2][2]*T179[2][1] - T179[6][1]) + S97[2][2]*(-(l7z*Si79[2][1]*T179[1][2]) - l7z*Si79[2][2]*T179[2][2] - T179[6][2]) + l6x*S97[1][3]*(-(l7z*Si79[2][1]*T179[1][4]) - l7z*Si79[2][2]*T179[2][4] - T179[6][4]) + l6x*S97[2][3]*(-(l7z*Si79[2][1]*T179[1][5]) - l7z*Si79[2][2]*T179[2][5] - T179[6][5]) - l7z*(-(l7z*Si79[2][1]*T179[1][6]) - l7z*Si79[2][2]*T179[2][6] - T179[6][6]);
T79[4][3]=S97[1][3]*(-(l7z*Si79[2][1]*T179[1][1]) - l7z*Si79[2][2]*T179[2][1] - T179[6][1]) + S97[2][3]*(-(l7z*Si79[2][1]*T179[1][2]) - l7z*Si79[2][2]*T179[2][2] - T179[6][2]) - l6x*S97[1][2]*(-(l7z*Si79[2][1]*T179[1][4]) - l7z*Si79[2][2]*T179[2][4] - T179[6][4]) - l6x*S97[2][2]*(-(l7z*Si79[2][1]*T179[1][5]) - l7z*Si79[2][2]*T179[2][5] - T179[6][5]);
T79[4][4]=l7z*Si79[2][1]*T179[1][6] + l7z*Si79[2][2]*T179[2][6] + T179[6][6];
T79[4][5]=S97[1][2]*(-(l7z*Si79[2][1]*T179[1][4]) - l7z*Si79[2][2]*T179[2][4] - T179[6][4]) + S97[2][2]*(-(l7z*Si79[2][1]*T179[1][5]) - l7z*Si79[2][2]*T179[2][5] - T179[6][5]);
T79[4][6]=S97[1][3]*(-(l7z*Si79[2][1]*T179[1][4]) - l7z*Si79[2][2]*T179[2][4] - T179[6][4]) + S97[2][3]*(-(l7z*Si79[2][1]*T179[1][5]) - l7z*Si79[2][2]*T179[2][5] - T179[6][5]);

T79[5][1]=-(l6x*Si79[3][1]*T179[1][3]) - l6x*Si79[3][2]*T179[2][3] + l7z*T179[3][3] - Si79[2][1]*T179[4][3] - Si79[2][2]*T179[5][3] - l7z*S97[1][2]*(l6x*Si79[3][1]*T179[1][4] + l6x*Si79[3][2]*T179[2][4] - l7z*T179[3][4] + Si79[2][1]*T179[4][4] + Si79[2][2]*T179[5][4]) - l7z*S97[2][2]*(l6x*Si79[3][1]*T179[1][5] + l6x*Si79[3][2]*T179[2][5] - l7z*T179[3][5] + Si79[2][1]*T179[4][5] + Si79[2][2]*T179[5][5]);
T79[5][2]=S97[1][2]*(l6x*Si79[3][1]*T179[1][1] + l6x*Si79[3][2]*T179[2][1] - l7z*T179[3][1] + Si79[2][1]*T179[4][1] + Si79[2][2]*T179[5][1]) + S97[2][2]*(l6x*Si79[3][1]*T179[1][2] + l6x*Si79[3][2]*T179[2][2] - l7z*T179[3][2] + Si79[2][1]*T179[4][2] + Si79[2][2]*T179[5][2]) + l6x*S97[1][3]*(l6x*Si79[3][1]*T179[1][4] + l6x*Si79[3][2]*T179[2][4] - l7z*T179[3][4] + Si79[2][1]*T179[4][4] + Si79[2][2]*T179[5][4]) + l6x*S97[2][3]*(l6x*Si79[3][1]*T179[1][5] + l6x*Si79[3][2]*T179[2][5] - l7z*T179[3][5] + Si79[2][1]*T179[4][5] + Si79[2][2]*T179[5][5]) - l7z*(l6x*Si79[3][1]*T179[1][6] + l6x*Si79[3][2]*T179[2][6] - l7z*T179[3][6] + Si79[2][1]*T179[4][6] + Si79[2][2]*T179[5][6]);
T79[5][3]=S97[1][3]*(l6x*Si79[3][1]*T179[1][1] + l6x*Si79[3][2]*T179[2][1] - l7z*T179[3][1] + Si79[2][1]*T179[4][1] + Si79[2][2]*T179[5][1]) + S97[2][3]*(l6x*Si79[3][1]*T179[1][2] + l6x*Si79[3][2]*T179[2][2] - l7z*T179[3][2] + Si79[2][1]*T179[4][2] + Si79[2][2]*T179[5][2]) - l6x*S97[1][2]*(l6x*Si79[3][1]*T179[1][4] + l6x*Si79[3][2]*T179[2][4] - l7z*T179[3][4] + Si79[2][1]*T179[4][4] + Si79[2][2]*T179[5][4]) - l6x*S97[2][2]*(l6x*Si79[3][1]*T179[1][5] + l6x*Si79[3][2]*T179[2][5] - l7z*T179[3][5] + Si79[2][1]*T179[4][5] + Si79[2][2]*T179[5][5]);
T79[5][4]=-(l6x*Si79[3][1]*T179[1][6]) - l6x*Si79[3][2]*T179[2][6] + l7z*T179[3][6] - Si79[2][1]*T179[4][6] - Si79[2][2]*T179[5][6];
T79[5][5]=S97[1][2]*(l6x*Si79[3][1]*T179[1][4] + l6x*Si79[3][2]*T179[2][4] - l7z*T179[3][4] + Si79[2][1]*T179[4][4] + Si79[2][2]*T179[5][4]) + S97[2][2]*(l6x*Si79[3][1]*T179[1][5] + l6x*Si79[3][2]*T179[2][5] - l7z*T179[3][5] + Si79[2][1]*T179[4][5] + Si79[2][2]*T179[5][5]);
T79[5][6]=S97[1][3]*(l6x*Si79[3][1]*T179[1][4] + l6x*Si79[3][2]*T179[2][4] - l7z*T179[3][4] + Si79[2][1]*T179[4][4] + Si79[2][2]*T179[5][4]) + S97[2][3]*(l6x*Si79[3][1]*T179[1][5] + l6x*Si79[3][2]*T179[2][5] - l7z*T179[3][5] + Si79[2][1]*T179[4][5] + Si79[2][2]*T179[5][5]);

T79[6][1]=l6x*Si79[2][1]*T179[1][3] + l6x*Si79[2][2]*T179[2][3] - Si79[3][1]*T179[4][3] - Si79[3][2]*T179[5][3] - l7z*S97[1][2]*(-(l6x*Si79[2][1]*T179[1][4]) - l6x*Si79[2][2]*T179[2][4] + Si79[3][1]*T179[4][4] + Si79[3][2]*T179[5][4]) - l7z*S97[2][2]*(-(l6x*Si79[2][1]*T179[1][5]) - l6x*Si79[2][2]*T179[2][5] + Si79[3][1]*T179[4][5] + Si79[3][2]*T179[5][5]);
T79[6][2]=S97[1][2]*(-(l6x*Si79[2][1]*T179[1][1]) - l6x*Si79[2][2]*T179[2][1] + Si79[3][1]*T179[4][1] + Si79[3][2]*T179[5][1]) + S97[2][2]*(-(l6x*Si79[2][1]*T179[1][2]) - l6x*Si79[2][2]*T179[2][2] + Si79[3][1]*T179[4][2] + Si79[3][2]*T179[5][2]) + l6x*S97[1][3]*(-(l6x*Si79[2][1]*T179[1][4]) - l6x*Si79[2][2]*T179[2][4] + Si79[3][1]*T179[4][4] + Si79[3][2]*T179[5][4]) + l6x*S97[2][3]*(-(l6x*Si79[2][1]*T179[1][5]) - l6x*Si79[2][2]*T179[2][5] + Si79[3][1]*T179[4][5] + Si79[3][2]*T179[5][5]) - l7z*(-(l6x*Si79[2][1]*T179[1][6]) - l6x*Si79[2][2]*T179[2][6] + Si79[3][1]*T179[4][6] + Si79[3][2]*T179[5][6]);
T79[6][3]=S97[1][3]*(-(l6x*Si79[2][1]*T179[1][1]) - l6x*Si79[2][2]*T179[2][1] + Si79[3][1]*T179[4][1] + Si79[3][2]*T179[5][1]) + S97[2][3]*(-(l6x*Si79[2][1]*T179[1][2]) - l6x*Si79[2][2]*T179[2][2] + Si79[3][1]*T179[4][2] + Si79[3][2]*T179[5][2]) - l6x*S97[1][2]*(-(l6x*Si79[2][1]*T179[1][4]) - l6x*Si79[2][2]*T179[2][4] + Si79[3][1]*T179[4][4] + Si79[3][2]*T179[5][4]) - l6x*S97[2][2]*(-(l6x*Si79[2][1]*T179[1][5]) - l6x*Si79[2][2]*T179[2][5] + Si79[3][1]*T179[4][5] + Si79[3][2]*T179[5][5]);
T79[6][4]=l6x*Si79[2][1]*T179[1][6] + l6x*Si79[2][2]*T179[2][6] - Si79[3][1]*T179[4][6] - Si79[3][2]*T179[5][6];
T79[6][5]=S97[1][2]*(-(l6x*Si79[2][1]*T179[1][4]) - l6x*Si79[2][2]*T179[2][4] + Si79[3][1]*T179[4][4] + Si79[3][2]*T179[5][4]) + S97[2][2]*(-(l6x*Si79[2][1]*T179[1][5]) - l6x*Si79[2][2]*T179[2][5] + Si79[3][1]*T179[4][5] + Si79[3][2]*T179[5][5]);
T79[6][6]=S97[1][3]*(-(l6x*Si79[2][1]*T179[1][4]) - l6x*Si79[2][2]*T179[2][4] + Si79[3][1]*T179[4][4] + Si79[3][2]*T179[5][4]) + S97[2][3]*(-(l6x*Si79[2][1]*T179[1][5]) - l6x*Si79[2][2]*T179[2][5] + Si79[3][1]*T179[4][5] + Si79[3][2]*T179[5][5]);



}


void
master_ForDynArtfunc12(void)
      {
JA8[1][2]=eff[1].mcm[3];
JA8[1][3]=-eff[1].mcm[2];
JA8[1][4]=eff[1].m;

JA8[2][1]=-eff[1].mcm[3];
JA8[2][3]=eff[1].mcm[1];
JA8[2][5]=eff[1].m;

JA8[3][1]=eff[1].mcm[2];
JA8[3][2]=-eff[1].mcm[1];
JA8[3][6]=eff[1].m;

JA8[4][5]=-eff[1].mcm[3];
JA8[4][6]=eff[1].mcm[2];

JA8[5][4]=eff[1].mcm[3];
JA8[5][6]=-eff[1].mcm[1];

JA8[6][4]=-eff[1].mcm[2];
JA8[6][5]=eff[1].mcm[1];


T178[1][2]=JA8[1][2];
T178[1][3]=JA8[1][3];
T178[1][4]=JA8[1][4];

T178[2][1]=JA8[2][1];
T178[2][3]=JA8[2][3];
T178[2][5]=JA8[2][5];

T178[3][1]=JA8[3][1];
T178[3][2]=JA8[3][2];
T178[3][6]=JA8[3][6];

T178[4][5]=JA8[4][5];
T178[4][6]=JA8[4][6];

T178[5][4]=JA8[5][4];
T178[5][6]=JA8[5][6];

T178[6][4]=JA8[6][4];
T178[6][5]=JA8[6][5];


T78[1][1]=(-(eff[1].x[3]*S87[1][2]) + eff[1].x[2]*S87[1][3])*Si78[1][1]*T178[1][4] + S87[3][1]*(Si78[1][1]*T178[1][3] + Si78[1][2]*T178[2][3]) + (-(eff[1].x[3]*S87[2][2]) + eff[1].x[2]*S87[2][3])*Si78[1][2]*T178[2][5] + S87[1][1]*(Si78[1][2]*T178[2][1] + Si78[1][3]*T178[3][1]) + S87[2][1]*(Si78[1][1]*T178[1][2] + Si78[1][3]*T178[3][2]) + (-(eff[1].x[3]*S87[3][2]) + eff[1].x[2]*S87[3][3])*Si78[1][3]*T178[3][6];
T78[1][2]=(eff[1].x[3]*S87[1][1] - eff[1].x[1]*S87[1][3])*Si78[1][1]*T178[1][4] + S87[3][2]*(Si78[1][1]*T178[1][3] + Si78[1][2]*T178[2][3]) + (eff[1].x[3]*S87[2][1] - eff[1].x[1]*S87[2][3])*Si78[1][2]*T178[2][5] + S87[1][2]*(Si78[1][2]*T178[2][1] + Si78[1][3]*T178[3][1]) + S87[2][2]*(Si78[1][1]*T178[1][2] + Si78[1][3]*T178[3][2]) + (eff[1].x[3]*S87[3][1] - eff[1].x[1]*S87[3][3])*Si78[1][3]*T178[3][6];
T78[1][3]=(-(eff[1].x[2]*S87[1][1]) + eff[1].x[1]*S87[1][2])*Si78[1][1]*T178[1][4] + S87[3][3]*(Si78[1][1]*T178[1][3] + Si78[1][2]*T178[2][3]) + (-(eff[1].x[2]*S87[2][1]) + eff[1].x[1]*S87[2][2])*Si78[1][2]*T178[2][5] + S87[1][3]*(Si78[1][2]*T178[2][1] + Si78[1][3]*T178[3][1]) + S87[2][3]*(Si78[1][1]*T178[1][2] + Si78[1][3]*T178[3][2]) + (-(eff[1].x[2]*S87[3][1]) + eff[1].x[1]*S87[3][2])*Si78[1][3]*T178[3][6];
T78[1][4]=S87[1][1]*Si78[1][1]*T178[1][4] + S87[2][1]*Si78[1][2]*T178[2][5] + S87[3][1]*Si78[1][3]*T178[3][6];
T78[1][5]=S87[1][2]*Si78[1][1]*T178[1][4] + S87[2][2]*Si78[1][2]*T178[2][5] + S87[3][2]*Si78[1][3]*T178[3][6];
T78[1][6]=S87[1][3]*Si78[1][1]*T178[1][4] + S87[2][3]*Si78[1][2]*T178[2][5] + S87[3][3]*Si78[1][3]*T178[3][6];

T78[2][1]=(-(eff[1].x[3]*S87[1][2]) + eff[1].x[2]*S87[1][3])*Si78[2][1]*T178[1][4] + S87[3][1]*(Si78[2][1]*T178[1][3] + Si78[2][2]*T178[2][3]) + (-(eff[1].x[3]*S87[2][2]) + eff[1].x[2]*S87[2][3])*Si78[2][2]*T178[2][5] + S87[1][1]*(Si78[2][2]*T178[2][1] + Si78[2][3]*T178[3][1]) + S87[2][1]*(Si78[2][1]*T178[1][2] + Si78[2][3]*T178[3][2]) + (-(eff[1].x[3]*S87[3][2]) + eff[1].x[2]*S87[3][3])*Si78[2][3]*T178[3][6];
T78[2][2]=(eff[1].x[3]*S87[1][1] - eff[1].x[1]*S87[1][3])*Si78[2][1]*T178[1][4] + S87[3][2]*(Si78[2][1]*T178[1][3] + Si78[2][2]*T178[2][3]) + (eff[1].x[3]*S87[2][1] - eff[1].x[1]*S87[2][3])*Si78[2][2]*T178[2][5] + S87[1][2]*(Si78[2][2]*T178[2][1] + Si78[2][3]*T178[3][1]) + S87[2][2]*(Si78[2][1]*T178[1][2] + Si78[2][3]*T178[3][2]) + (eff[1].x[3]*S87[3][1] - eff[1].x[1]*S87[3][3])*Si78[2][3]*T178[3][6];
T78[2][3]=(-(eff[1].x[2]*S87[1][1]) + eff[1].x[1]*S87[1][2])*Si78[2][1]*T178[1][4] + S87[3][3]*(Si78[2][1]*T178[1][3] + Si78[2][2]*T178[2][3]) + (-(eff[1].x[2]*S87[2][1]) + eff[1].x[1]*S87[2][2])*Si78[2][2]*T178[2][5] + S87[1][3]*(Si78[2][2]*T178[2][1] + Si78[2][3]*T178[3][1]) + S87[2][3]*(Si78[2][1]*T178[1][2] + Si78[2][3]*T178[3][2]) + (-(eff[1].x[2]*S87[3][1]) + eff[1].x[1]*S87[3][2])*Si78[2][3]*T178[3][6];
T78[2][4]=S87[1][1]*Si78[2][1]*T178[1][4] + S87[2][1]*Si78[2][2]*T178[2][5] + S87[3][1]*Si78[2][3]*T178[3][6];
T78[2][5]=S87[1][2]*Si78[2][1]*T178[1][4] + S87[2][2]*Si78[2][2]*T178[2][5] + S87[3][2]*Si78[2][3]*T178[3][6];
T78[2][6]=S87[1][3]*Si78[2][1]*T178[1][4] + S87[2][3]*Si78[2][2]*T178[2][5] + S87[3][3]*Si78[2][3]*T178[3][6];

T78[3][1]=(-(eff[1].x[3]*S87[1][2]) + eff[1].x[2]*S87[1][3])*Si78[3][1]*T178[1][4] + S87[3][1]*(Si78[3][1]*T178[1][3] + Si78[3][2]*T178[2][3]) + (-(eff[1].x[3]*S87[2][2]) + eff[1].x[2]*S87[2][3])*Si78[3][2]*T178[2][5] + S87[1][1]*(Si78[3][2]*T178[2][1] + Si78[3][3]*T178[3][1]) + S87[2][1]*(Si78[3][1]*T178[1][2] + Si78[3][3]*T178[3][2]) + (-(eff[1].x[3]*S87[3][2]) + eff[1].x[2]*S87[3][3])*Si78[3][3]*T178[3][6];
T78[3][2]=(eff[1].x[3]*S87[1][1] - eff[1].x[1]*S87[1][3])*Si78[3][1]*T178[1][4] + S87[3][2]*(Si78[3][1]*T178[1][3] + Si78[3][2]*T178[2][3]) + (eff[1].x[3]*S87[2][1] - eff[1].x[1]*S87[2][3])*Si78[3][2]*T178[2][5] + S87[1][2]*(Si78[3][2]*T178[2][1] + Si78[3][3]*T178[3][1]) + S87[2][2]*(Si78[3][1]*T178[1][2] + Si78[3][3]*T178[3][2]) + (eff[1].x[3]*S87[3][1] - eff[1].x[1]*S87[3][3])*Si78[3][3]*T178[3][6];
T78[3][3]=(-(eff[1].x[2]*S87[1][1]) + eff[1].x[1]*S87[1][2])*Si78[3][1]*T178[1][4] + S87[3][3]*(Si78[3][1]*T178[1][3] + Si78[3][2]*T178[2][3]) + (-(eff[1].x[2]*S87[2][1]) + eff[1].x[1]*S87[2][2])*Si78[3][2]*T178[2][5] + S87[1][3]*(Si78[3][2]*T178[2][1] + Si78[3][3]*T178[3][1]) + S87[2][3]*(Si78[3][1]*T178[1][2] + Si78[3][3]*T178[3][2]) + (-(eff[1].x[2]*S87[3][1]) + eff[1].x[1]*S87[3][2])*Si78[3][3]*T178[3][6];
T78[3][4]=S87[1][1]*Si78[3][1]*T178[1][4] + S87[2][1]*Si78[3][2]*T178[2][5] + S87[3][1]*Si78[3][3]*T178[3][6];
T78[3][5]=S87[1][2]*Si78[3][1]*T178[1][4] + S87[2][2]*Si78[3][2]*T178[2][5] + S87[3][2]*Si78[3][3]*T178[3][6];
T78[3][6]=S87[1][3]*Si78[3][1]*T178[1][4] + S87[2][3]*Si78[3][2]*T178[2][5] + S87[3][3]*Si78[3][3]*T178[3][6];

T78[4][1]=S87[3][1]*((-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1])*T178[1][3] + (-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2])*T178[2][3]) + S87[1][1]*((-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2])*T178[2][1] + (-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])*T178[3][1]) + S87[2][1]*((-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1])*T178[1][2] + (-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])*T178[3][2]) + (-(eff[1].x[3]*S87[3][2]) + eff[1].x[2]*S87[3][3])*((-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])*T178[3][6] + Si78[1][1]*T178[4][6] + Si78[1][2]*T178[5][6]) + (-(eff[1].x[3]*S87[1][2]) + eff[1].x[2]*S87[1][3])*((-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1])*T178[1][4] + Si78[1][2]*T178[5][4] + Si78[1][3]*T178[6][4]) + (-(eff[1].x[3]*S87[2][2]) + eff[1].x[2]*S87[2][3])*((-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2])*T178[2][5] + Si78[1][1]*T178[4][5] + Si78[1][3]*T178[6][5]);
T78[4][2]=S87[3][2]*((-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1])*T178[1][3] + (-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2])*T178[2][3]) + S87[1][2]*((-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2])*T178[2][1] + (-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])*T178[3][1]) + S87[2][2]*((-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1])*T178[1][2] + (-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])*T178[3][2]) + (eff[1].x[3]*S87[3][1] - eff[1].x[1]*S87[3][3])*((-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])*T178[3][6] + Si78[1][1]*T178[4][6] + Si78[1][2]*T178[5][6]) + (eff[1].x[3]*S87[1][1] - eff[1].x[1]*S87[1][3])*((-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1])*T178[1][4] + Si78[1][2]*T178[5][4] + Si78[1][3]*T178[6][4]) + (eff[1].x[3]*S87[2][1] - eff[1].x[1]*S87[2][3])*((-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2])*T178[2][5] + Si78[1][1]*T178[4][5] + Si78[1][3]*T178[6][5]);
T78[4][3]=S87[3][3]*((-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1])*T178[1][3] + (-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2])*T178[2][3]) + S87[1][3]*((-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2])*T178[2][1] + (-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])*T178[3][1]) + S87[2][3]*((-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1])*T178[1][2] + (-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])*T178[3][2]) + (-(eff[1].x[2]*S87[3][1]) + eff[1].x[1]*S87[3][2])*((-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])*T178[3][6] + Si78[1][1]*T178[4][6] + Si78[1][2]*T178[5][6]) + (-(eff[1].x[2]*S87[1][1]) + eff[1].x[1]*S87[1][2])*((-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1])*T178[1][4] + Si78[1][2]*T178[5][4] + Si78[1][3]*T178[6][4]) + (-(eff[1].x[2]*S87[2][1]) + eff[1].x[1]*S87[2][2])*((-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2])*T178[2][5] + Si78[1][1]*T178[4][5] + Si78[1][3]*T178[6][5]);
T78[4][4]=S87[3][1]*((-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])*T178[3][6] + Si78[1][1]*T178[4][6] + Si78[1][2]*T178[5][6]) + S87[1][1]*((-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1])*T178[1][4] + Si78[1][2]*T178[5][4] + Si78[1][3]*T178[6][4]) + S87[2][1]*((-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2])*T178[2][5] + Si78[1][1]*T178[4][5] + Si78[1][3]*T178[6][5]);
T78[4][5]=S87[3][2]*((-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])*T178[3][6] + Si78[1][1]*T178[4][6] + Si78[1][2]*T178[5][6]) + S87[1][2]*((-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1])*T178[1][4] + Si78[1][2]*T178[5][4] + Si78[1][3]*T178[6][4]) + S87[2][2]*((-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2])*T178[2][5] + Si78[1][1]*T178[4][5] + Si78[1][3]*T178[6][5]);
T78[4][6]=S87[3][3]*((-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3])*T178[3][6] + Si78[1][1]*T178[4][6] + Si78[1][2]*T178[5][6]) + S87[1][3]*((-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1])*T178[1][4] + Si78[1][2]*T178[5][4] + Si78[1][3]*T178[6][4]) + S87[2][3]*((-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2])*T178[2][5] + Si78[1][1]*T178[4][5] + Si78[1][3]*T178[6][5]);

T78[5][1]=S87[3][1]*((eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1])*T178[1][3] + (eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2])*T178[2][3]) + S87[1][1]*((eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2])*T178[2][1] + (eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])*T178[3][1]) + S87[2][1]*((eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1])*T178[1][2] + (eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])*T178[3][2]) + (-(eff[1].x[3]*S87[3][2]) + eff[1].x[2]*S87[3][3])*((eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])*T178[3][6] + Si78[2][1]*T178[4][6] + Si78[2][2]*T178[5][6]) + (-(eff[1].x[3]*S87[1][2]) + eff[1].x[2]*S87[1][3])*((eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1])*T178[1][4] + Si78[2][2]*T178[5][4] + Si78[2][3]*T178[6][4]) + (-(eff[1].x[3]*S87[2][2]) + eff[1].x[2]*S87[2][3])*((eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2])*T178[2][5] + Si78[2][1]*T178[4][5] + Si78[2][3]*T178[6][5]);
T78[5][2]=S87[3][2]*((eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1])*T178[1][3] + (eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2])*T178[2][3]) + S87[1][2]*((eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2])*T178[2][1] + (eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])*T178[3][1]) + S87[2][2]*((eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1])*T178[1][2] + (eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])*T178[3][2]) + (eff[1].x[3]*S87[3][1] - eff[1].x[1]*S87[3][3])*((eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])*T178[3][6] + Si78[2][1]*T178[4][6] + Si78[2][2]*T178[5][6]) + (eff[1].x[3]*S87[1][1] - eff[1].x[1]*S87[1][3])*((eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1])*T178[1][4] + Si78[2][2]*T178[5][4] + Si78[2][3]*T178[6][4]) + (eff[1].x[3]*S87[2][1] - eff[1].x[1]*S87[2][3])*((eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2])*T178[2][5] + Si78[2][1]*T178[4][5] + Si78[2][3]*T178[6][5]);
T78[5][3]=S87[3][3]*((eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1])*T178[1][3] + (eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2])*T178[2][3]) + S87[1][3]*((eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2])*T178[2][1] + (eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])*T178[3][1]) + S87[2][3]*((eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1])*T178[1][2] + (eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])*T178[3][2]) + (-(eff[1].x[2]*S87[3][1]) + eff[1].x[1]*S87[3][2])*((eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])*T178[3][6] + Si78[2][1]*T178[4][6] + Si78[2][2]*T178[5][6]) + (-(eff[1].x[2]*S87[1][1]) + eff[1].x[1]*S87[1][2])*((eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1])*T178[1][4] + Si78[2][2]*T178[5][4] + Si78[2][3]*T178[6][4]) + (-(eff[1].x[2]*S87[2][1]) + eff[1].x[1]*S87[2][2])*((eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2])*T178[2][5] + Si78[2][1]*T178[4][5] + Si78[2][3]*T178[6][5]);
T78[5][4]=S87[3][1]*((eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])*T178[3][6] + Si78[2][1]*T178[4][6] + Si78[2][2]*T178[5][6]) + S87[1][1]*((eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1])*T178[1][4] + Si78[2][2]*T178[5][4] + Si78[2][3]*T178[6][4]) + S87[2][1]*((eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2])*T178[2][5] + Si78[2][1]*T178[4][5] + Si78[2][3]*T178[6][5]);
T78[5][5]=S87[3][2]*((eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])*T178[3][6] + Si78[2][1]*T178[4][6] + Si78[2][2]*T178[5][6]) + S87[1][2]*((eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1])*T178[1][4] + Si78[2][2]*T178[5][4] + Si78[2][3]*T178[6][4]) + S87[2][2]*((eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2])*T178[2][5] + Si78[2][1]*T178[4][5] + Si78[2][3]*T178[6][5]);
T78[5][6]=S87[3][3]*((eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3])*T178[3][6] + Si78[2][1]*T178[4][6] + Si78[2][2]*T178[5][6]) + S87[1][3]*((eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1])*T178[1][4] + Si78[2][2]*T178[5][4] + Si78[2][3]*T178[6][4]) + S87[2][3]*((eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2])*T178[2][5] + Si78[2][1]*T178[4][5] + Si78[2][3]*T178[6][5]);

T78[6][1]=S87[3][1]*((-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1])*T178[1][3] + (-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2])*T178[2][3]) + S87[1][1]*((-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2])*T178[2][1] + (-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3])*T178[3][1]) + S87[2][1]*((-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1])*T178[1][2] + (-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3])*T178[3][2]) + (-(eff[1].x[3]*S87[3][2]) + eff[1].x[2]*S87[3][3])*((-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3])*T178[3][6] + Si78[3][1]*T178[4][6] + Si78[3][2]*T178[5][6]) + (-(eff[1].x[3]*S87[1][2]) + eff[1].x[2]*S87[1][3])*((-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1])*T178[1][4] + Si78[3][2]*T178[5][4] + Si78[3][3]*T178[6][4]) + (-(eff[1].x[3]*S87[2][2]) + eff[1].x[2]*S87[2][3])*((-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2])*T178[2][5] + Si78[3][1]*T178[4][5] + Si78[3][3]*T178[6][5]);
T78[6][2]=S87[3][2]*((-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1])*T178[1][3] + (-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2])*T178[2][3]) + S87[1][2]*((-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2])*T178[2][1] + (-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3])*T178[3][1]) + S87[2][2]*((-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1])*T178[1][2] + (-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3])*T178[3][2]) + (eff[1].x[3]*S87[3][1] - eff[1].x[1]*S87[3][3])*((-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3])*T178[3][6] + Si78[3][1]*T178[4][6] + Si78[3][2]*T178[5][6]) + (eff[1].x[3]*S87[1][1] - eff[1].x[1]*S87[1][3])*((-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1])*T178[1][4] + Si78[3][2]*T178[5][4] + Si78[3][3]*T178[6][4]) + (eff[1].x[3]*S87[2][1] - eff[1].x[1]*S87[2][3])*((-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2])*T178[2][5] + Si78[3][1]*T178[4][5] + Si78[3][3]*T178[6][5]);
T78[6][3]=S87[3][3]*((-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1])*T178[1][3] + (-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2])*T178[2][3]) + S87[1][3]*((-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2])*T178[2][1] + (-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3])*T178[3][1]) + S87[2][3]*((-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1])*T178[1][2] + (-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3])*T178[3][2]) + (-(eff[1].x[2]*S87[3][1]) + eff[1].x[1]*S87[3][2])*((-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3])*T178[3][6] + Si78[3][1]*T178[4][6] + Si78[3][2]*T178[5][6]) + (-(eff[1].x[2]*S87[1][1]) + eff[1].x[1]*S87[1][2])*((-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1])*T178[1][4] + Si78[3][2]*T178[5][4] + Si78[3][3]*T178[6][4]) + (-(eff[1].x[2]*S87[2][1]) + eff[1].x[1]*S87[2][2])*((-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2])*T178[2][5] + Si78[3][1]*T178[4][5] + Si78[3][3]*T178[6][5]);
T78[6][4]=S87[3][1]*((-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3])*T178[3][6] + Si78[3][1]*T178[4][6] + Si78[3][2]*T178[5][6]) + S87[1][1]*((-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1])*T178[1][4] + Si78[3][2]*T178[5][4] + Si78[3][3]*T178[6][4]) + S87[2][1]*((-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2])*T178[2][5] + Si78[3][1]*T178[4][5] + Si78[3][3]*T178[6][5]);
T78[6][5]=S87[3][2]*((-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3])*T178[3][6] + Si78[3][1]*T178[4][6] + Si78[3][2]*T178[5][6]) + S87[1][2]*((-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1])*T178[1][4] + Si78[3][2]*T178[5][4] + Si78[3][3]*T178[6][4]) + S87[2][2]*((-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2])*T178[2][5] + Si78[3][1]*T178[4][5] + Si78[3][3]*T178[6][5]);
T78[6][6]=S87[3][3]*((-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3])*T178[3][6] + Si78[3][1]*T178[4][6] + Si78[3][2]*T178[5][6]) + S87[1][3]*((-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1])*T178[1][4] + Si78[3][2]*T178[5][4] + Si78[3][3]*T178[6][4]) + S87[2][3]*((-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2])*T178[2][5] + Si78[3][1]*T178[4][5] + Si78[3][3]*T178[6][5]);



}


void
master_ForDynArtfunc13(void)
      {
JA7[1][1]=T712[1][1] + T78[1][1] + T79[1][1];
JA7[1][2]=links[7].mcm[3] + T712[1][2] + T78[1][2] + T79[1][2];
JA7[1][3]=-links[7].mcm[2] + T712[1][3] + T78[1][3] + T79[1][3];
JA7[1][4]=links[7].m + T712[1][4] + T78[1][4] + T79[1][4];
JA7[1][5]=T712[1][5] + T78[1][5] + T79[1][5];
JA7[1][6]=0. + T78[1][6] + T79[1][6];

JA7[2][1]=-links[7].mcm[3] + T712[2][1] + T78[2][1] + T79[2][1];
JA7[2][2]=T712[2][2] + T78[2][2] + T79[2][2];
JA7[2][3]=links[7].mcm[1] + T712[2][3] + T78[2][3] + T79[2][3];
JA7[2][4]=T712[2][4] + T78[2][4] + T79[2][4];
JA7[2][5]=links[7].m + T712[2][5] + T78[2][5] + T79[2][5];
JA7[2][6]=0. + T78[2][6] + T79[2][6];

JA7[3][1]=links[7].mcm[2] + T712[3][1] + T78[3][1] + T79[3][1];
JA7[3][2]=-links[7].mcm[1] + T712[3][2] + T78[3][2] + T79[3][2];
JA7[3][3]=0. + T78[3][3] + T79[3][3];
JA7[3][4]=0. + T78[3][4] + T79[3][4];
JA7[3][5]=0. + T78[3][5] + T79[3][5];
JA7[3][6]=links[7].m + T712[3][6] + T78[3][6] + T79[3][6];

JA7[4][1]=links[7].inertia[1][1] + T712[4][1] + T78[4][1] + T79[4][1];
JA7[4][2]=links[7].inertia[1][2] + T712[4][2] + T78[4][2] + T79[4][2];
JA7[4][3]=links[7].inertia[1][3] + T712[4][3] + T78[4][3] + T79[4][3];
JA7[4][4]=T712[4][4] + T78[4][4] + T79[4][4];
JA7[4][5]=-links[7].mcm[3] + T712[4][5] + T78[4][5] + T79[4][5];
JA7[4][6]=links[7].mcm[2] + T712[4][6] + T78[4][6] + T79[4][6];

JA7[5][1]=links[7].inertia[1][2] + T712[5][1] + T78[5][1] + T79[5][1];
JA7[5][2]=links[7].inertia[2][2] + T712[5][2] + T78[5][2] + T79[5][2];
JA7[5][3]=links[7].inertia[2][3] + T712[5][3] + T78[5][3] + T79[5][3];
JA7[5][4]=links[7].mcm[3] + T712[5][4] + T78[5][4] + T79[5][4];
JA7[5][5]=T712[5][5] + T78[5][5] + T79[5][5];
JA7[5][6]=-links[7].mcm[1] + T712[5][6] + T78[5][6] + T79[5][6];

JA7[6][1]=links[7].inertia[1][3] + T712[6][1] + T78[6][1] + T79[6][1];
JA7[6][2]=links[7].inertia[2][3] + T712[6][2] + T78[6][2] + T79[6][2];
JA7[6][3]=links[7].inertia[3][3] + T712[6][3] + T78[6][3] + T79[6][3];
JA7[6][4]=-links[7].mcm[2] + T712[6][4] + T78[6][4] + T79[6][4];
JA7[6][5]=links[7].mcm[1] + T712[6][5] + T78[6][5] + T79[6][5];
JA7[6][6]=0. + T78[6][6] + T79[6][6];


h7[1]=JA7[1][3];
h7[2]=JA7[2][3];
h7[3]=JA7[3][3];
h7[4]=JA7[4][3];
h7[5]=JA7[5][3];
h7[6]=JA7[6][3];

d[7]=1.e-10 + h7[6];

T167[1][1]=-((h7[1]*h7[4])/d[7]) + JA7[1][1];
T167[1][2]=-((h7[1]*h7[5])/d[7]) + JA7[1][2];
T167[1][3]=-((h7[1]*h7[6])/d[7]) + JA7[1][3];
T167[1][4]=-(Power(h7[1],2)/d[7]) + JA7[1][4];
T167[1][5]=-((h7[1]*h7[2])/d[7]) + JA7[1][5];
T167[1][6]=-((h7[1]*h7[3])/d[7]) + JA7[1][6];

T167[2][1]=-((h7[2]*h7[4])/d[7]) + JA7[2][1];
T167[2][2]=-((h7[2]*h7[5])/d[7]) + JA7[2][2];
T167[2][3]=-((h7[2]*h7[6])/d[7]) + JA7[2][3];
T167[2][4]=-((h7[1]*h7[2])/d[7]) + JA7[2][4];
T167[2][5]=-(Power(h7[2],2)/d[7]) + JA7[2][5];
T167[2][6]=-((h7[2]*h7[3])/d[7]) + JA7[2][6];

T167[3][1]=-((h7[3]*h7[4])/d[7]) + JA7[3][1];
T167[3][2]=-((h7[3]*h7[5])/d[7]) + JA7[3][2];
T167[3][3]=-((h7[3]*h7[6])/d[7]) + JA7[3][3];
T167[3][4]=-((h7[1]*h7[3])/d[7]) + JA7[3][4];
T167[3][5]=-((h7[2]*h7[3])/d[7]) + JA7[3][5];
T167[3][6]=-(Power(h7[3],2)/d[7]) + JA7[3][6];

T167[4][1]=-(Power(h7[4],2)/d[7]) + JA7[4][1];
T167[4][2]=-((h7[4]*h7[5])/d[7]) + JA7[4][2];
T167[4][3]=-((h7[4]*h7[6])/d[7]) + JA7[4][3];
T167[4][4]=-((h7[1]*h7[4])/d[7]) + JA7[4][4];
T167[4][5]=-((h7[2]*h7[4])/d[7]) + JA7[4][5];
T167[4][6]=-((h7[3]*h7[4])/d[7]) + JA7[4][6];

T167[5][1]=-((h7[4]*h7[5])/d[7]) + JA7[5][1];
T167[5][2]=-(Power(h7[5],2)/d[7]) + JA7[5][2];
T167[5][3]=-((h7[5]*h7[6])/d[7]) + JA7[5][3];
T167[5][4]=-((h7[1]*h7[5])/d[7]) + JA7[5][4];
T167[5][5]=-((h7[2]*h7[5])/d[7]) + JA7[5][5];
T167[5][6]=-((h7[3]*h7[5])/d[7]) + JA7[5][6];

T167[6][1]=-((h7[4]*h7[6])/d[7]) + JA7[6][1];
T167[6][2]=-((h7[5]*h7[6])/d[7]) + JA7[6][2];
T167[6][3]=-(Power(h7[6],2)/d[7]) + JA7[6][3];
T167[6][4]=-((h7[1]*h7[6])/d[7]) + JA7[6][4];
T167[6][5]=-((h7[2]*h7[6])/d[7]) + JA7[6][5];
T167[6][6]=-((h7[3]*h7[6])/d[7]) + JA7[6][6];


T67[1][1]=T167[3][3] - l5*S76[1][2]*T167[3][4] - l5*S76[2][2]*T167[3][5];
T67[1][2]=S76[1][2]*T167[3][1] + S76[2][2]*T167[3][2] + l5*T167[3][6];
T67[1][3]=S76[1][3]*T167[3][1] + S76[2][3]*T167[3][2];
T67[1][4]=T167[3][6];
T67[1][5]=S76[1][2]*T167[3][4] + S76[2][2]*T167[3][5];
T67[1][6]=S76[1][3]*T167[3][4] + S76[2][3]*T167[3][5];

T67[2][1]=Si67[2][1]*T167[1][3] + Si67[2][2]*T167[2][3] - l5*S76[1][2]*(Si67[2][1]*T167[1][4] + Si67[2][2]*T167[2][4]) - l5*S76[2][2]*(Si67[2][1]*T167[1][5] + Si67[2][2]*T167[2][5]);
T67[2][2]=S76[1][2]*(Si67[2][1]*T167[1][1] + Si67[2][2]*T167[2][1]) + S76[2][2]*(Si67[2][1]*T167[1][2] + Si67[2][2]*T167[2][2]) + l5*(Si67[2][1]*T167[1][6] + Si67[2][2]*T167[2][6]);
T67[2][3]=S76[1][3]*(Si67[2][1]*T167[1][1] + Si67[2][2]*T167[2][1]) + S76[2][3]*(Si67[2][1]*T167[1][2] + Si67[2][2]*T167[2][2]);
T67[2][4]=Si67[2][1]*T167[1][6] + Si67[2][2]*T167[2][6];
T67[2][5]=S76[1][2]*(Si67[2][1]*T167[1][4] + Si67[2][2]*T167[2][4]) + S76[2][2]*(Si67[2][1]*T167[1][5] + Si67[2][2]*T167[2][5]);
T67[2][6]=S76[1][3]*(Si67[2][1]*T167[1][4] + Si67[2][2]*T167[2][4]) + S76[2][3]*(Si67[2][1]*T167[1][5] + Si67[2][2]*T167[2][5]);

T67[3][1]=Si67[3][1]*T167[1][3] + Si67[3][2]*T167[2][3] - l5*S76[1][2]*(Si67[3][1]*T167[1][4] + Si67[3][2]*T167[2][4]) - l5*S76[2][2]*(Si67[3][1]*T167[1][5] + Si67[3][2]*T167[2][5]);
T67[3][2]=S76[1][2]*(Si67[3][1]*T167[1][1] + Si67[3][2]*T167[2][1]) + S76[2][2]*(Si67[3][1]*T167[1][2] + Si67[3][2]*T167[2][2]) + l5*(Si67[3][1]*T167[1][6] + Si67[3][2]*T167[2][6]);
T67[3][3]=S76[1][3]*(Si67[3][1]*T167[1][1] + Si67[3][2]*T167[2][1]) + S76[2][3]*(Si67[3][1]*T167[1][2] + Si67[3][2]*T167[2][2]);
T67[3][4]=Si67[3][1]*T167[1][6] + Si67[3][2]*T167[2][6];
T67[3][5]=S76[1][2]*(Si67[3][1]*T167[1][4] + Si67[3][2]*T167[2][4]) + S76[2][2]*(Si67[3][1]*T167[1][5] + Si67[3][2]*T167[2][5]);
T67[3][6]=S76[1][3]*(Si67[3][1]*T167[1][4] + Si67[3][2]*T167[2][4]) + S76[2][3]*(Si67[3][1]*T167[1][5] + Si67[3][2]*T167[2][5]);

T67[4][1]=-(l5*Si67[2][1]*T167[1][3]) - l5*Si67[2][2]*T167[2][3] + T167[6][3] - l5*S76[1][2]*(-(l5*Si67[2][1]*T167[1][4]) - l5*Si67[2][2]*T167[2][4] + T167[6][4]) - l5*S76[2][2]*(-(l5*Si67[2][1]*T167[1][5]) - l5*Si67[2][2]*T167[2][5] + T167[6][5]);
T67[4][2]=S76[1][2]*(-(l5*Si67[2][1]*T167[1][1]) - l5*Si67[2][2]*T167[2][1] + T167[6][1]) + S76[2][2]*(-(l5*Si67[2][1]*T167[1][2]) - l5*Si67[2][2]*T167[2][2] + T167[6][2]) + l5*(-(l5*Si67[2][1]*T167[1][6]) - l5*Si67[2][2]*T167[2][6] + T167[6][6]);
T67[4][3]=S76[1][3]*(-(l5*Si67[2][1]*T167[1][1]) - l5*Si67[2][2]*T167[2][1] + T167[6][1]) + S76[2][3]*(-(l5*Si67[2][1]*T167[1][2]) - l5*Si67[2][2]*T167[2][2] + T167[6][2]);
T67[4][4]=-(l5*Si67[2][1]*T167[1][6]) - l5*Si67[2][2]*T167[2][6] + T167[6][6];
T67[4][5]=S76[1][2]*(-(l5*Si67[2][1]*T167[1][4]) - l5*Si67[2][2]*T167[2][4] + T167[6][4]) + S76[2][2]*(-(l5*Si67[2][1]*T167[1][5]) - l5*Si67[2][2]*T167[2][5] + T167[6][5]);
T67[4][6]=S76[1][3]*(-(l5*Si67[2][1]*T167[1][4]) - l5*Si67[2][2]*T167[2][4] + T167[6][4]) + S76[2][3]*(-(l5*Si67[2][1]*T167[1][5]) - l5*Si67[2][2]*T167[2][5] + T167[6][5]);

T67[5][1]=l5*T167[3][3] + Si67[2][1]*T167[4][3] + Si67[2][2]*T167[5][3] - l5*S76[1][2]*(l5*T167[3][4] + Si67[2][1]*T167[4][4] + Si67[2][2]*T167[5][4]) - l5*S76[2][2]*(l5*T167[3][5] + Si67[2][1]*T167[4][5] + Si67[2][2]*T167[5][5]);
T67[5][2]=S76[1][2]*(l5*T167[3][1] + Si67[2][1]*T167[4][1] + Si67[2][2]*T167[5][1]) + S76[2][2]*(l5*T167[3][2] + Si67[2][1]*T167[4][2] + Si67[2][2]*T167[5][2]) + l5*(l5*T167[3][6] + Si67[2][1]*T167[4][6] + Si67[2][2]*T167[5][6]);
T67[5][3]=S76[1][3]*(l5*T167[3][1] + Si67[2][1]*T167[4][1] + Si67[2][2]*T167[5][1]) + S76[2][3]*(l5*T167[3][2] + Si67[2][1]*T167[4][2] + Si67[2][2]*T167[5][2]);
T67[5][4]=l5*T167[3][6] + Si67[2][1]*T167[4][6] + Si67[2][2]*T167[5][6];
T67[5][5]=S76[1][2]*(l5*T167[3][4] + Si67[2][1]*T167[4][4] + Si67[2][2]*T167[5][4]) + S76[2][2]*(l5*T167[3][5] + Si67[2][1]*T167[4][5] + Si67[2][2]*T167[5][5]);
T67[5][6]=S76[1][3]*(l5*T167[3][4] + Si67[2][1]*T167[4][4] + Si67[2][2]*T167[5][4]) + S76[2][3]*(l5*T167[3][5] + Si67[2][1]*T167[4][5] + Si67[2][2]*T167[5][5]);

T67[6][1]=Si67[3][1]*T167[4][3] + Si67[3][2]*T167[5][3] - l5*S76[1][2]*(Si67[3][1]*T167[4][4] + Si67[3][2]*T167[5][4]) - l5*S76[2][2]*(Si67[3][1]*T167[4][5] + Si67[3][2]*T167[5][5]);
T67[6][2]=S76[1][2]*(Si67[3][1]*T167[4][1] + Si67[3][2]*T167[5][1]) + S76[2][2]*(Si67[3][1]*T167[4][2] + Si67[3][2]*T167[5][2]) + l5*(Si67[3][1]*T167[4][6] + Si67[3][2]*T167[5][6]);
T67[6][3]=S76[1][3]*(Si67[3][1]*T167[4][1] + Si67[3][2]*T167[5][1]) + S76[2][3]*(Si67[3][1]*T167[4][2] + Si67[3][2]*T167[5][2]);
T67[6][4]=Si67[3][1]*T167[4][6] + Si67[3][2]*T167[5][6];
T67[6][5]=S76[1][2]*(Si67[3][1]*T167[4][4] + Si67[3][2]*T167[5][4]) + S76[2][2]*(Si67[3][1]*T167[4][5] + Si67[3][2]*T167[5][5]);
T67[6][6]=S76[1][3]*(Si67[3][1]*T167[4][4] + Si67[3][2]*T167[5][4]) + S76[2][3]*(Si67[3][1]*T167[4][5] + Si67[3][2]*T167[5][5]);



}


void
master_ForDynArtfunc14(void)
      {
JA6[1][1]=T67[1][1];
JA6[1][2]=links[6].mcm[3] + T67[1][2];
JA6[1][3]=-links[6].mcm[2] + T67[1][3];
JA6[1][4]=links[6].m + T67[1][4];
JA6[1][5]=T67[1][5];
JA6[1][6]=T67[1][6];

JA6[2][1]=-links[6].mcm[3] + T67[2][1];
JA6[2][2]=T67[2][2];
JA6[2][3]=links[6].mcm[1] + T67[2][3];
JA6[2][4]=T67[2][4];
JA6[2][5]=links[6].m + T67[2][5];
JA6[2][6]=T67[2][6];

JA6[3][1]=links[6].mcm[2] + T67[3][1];
JA6[3][2]=-links[6].mcm[1] + T67[3][2];
JA6[3][3]=T67[3][3];
JA6[3][4]=T67[3][4];
JA6[3][5]=T67[3][5];
JA6[3][6]=links[6].m + T67[3][6];

JA6[4][1]=links[6].inertia[1][1] + T67[4][1];
JA6[4][2]=links[6].inertia[1][2] + T67[4][2];
JA6[4][3]=links[6].inertia[1][3] + T67[4][3];
JA6[4][4]=T67[4][4];
JA6[4][5]=-links[6].mcm[3] + T67[4][5];
JA6[4][6]=links[6].mcm[2] + T67[4][6];

JA6[5][1]=links[6].inertia[1][2] + T67[5][1];
JA6[5][2]=links[6].inertia[2][2] + T67[5][2];
JA6[5][3]=links[6].inertia[2][3] + T67[5][3];
JA6[5][4]=links[6].mcm[3] + T67[5][4];
JA6[5][5]=T67[5][5];
JA6[5][6]=-links[6].mcm[1] + T67[5][6];

JA6[6][1]=links[6].inertia[1][3] + T67[6][1];
JA6[6][2]=links[6].inertia[2][3] + T67[6][2];
JA6[6][3]=links[6].inertia[3][3] + T67[6][3];
JA6[6][4]=-links[6].mcm[2] + T67[6][4];
JA6[6][5]=links[6].mcm[1] + T67[6][5];
JA6[6][6]=T67[6][6];


h6[1]=JA6[1][3];
h6[2]=JA6[2][3];
h6[3]=JA6[3][3];
h6[4]=JA6[4][3];
h6[5]=JA6[5][3];
h6[6]=JA6[6][3];

d[6]=1.e-10 + h6[6];

T156[1][1]=-((h6[1]*h6[4])/d[6]) + JA6[1][1];
T156[1][2]=-((h6[1]*h6[5])/d[6]) + JA6[1][2];
T156[1][3]=-((h6[1]*h6[6])/d[6]) + JA6[1][3];
T156[1][4]=-(Power(h6[1],2)/d[6]) + JA6[1][4];
T156[1][5]=-((h6[1]*h6[2])/d[6]) + JA6[1][5];
T156[1][6]=-((h6[1]*h6[3])/d[6]) + JA6[1][6];

T156[2][1]=-((h6[2]*h6[4])/d[6]) + JA6[2][1];
T156[2][2]=-((h6[2]*h6[5])/d[6]) + JA6[2][2];
T156[2][3]=-((h6[2]*h6[6])/d[6]) + JA6[2][3];
T156[2][4]=-((h6[1]*h6[2])/d[6]) + JA6[2][4];
T156[2][5]=-(Power(h6[2],2)/d[6]) + JA6[2][5];
T156[2][6]=-((h6[2]*h6[3])/d[6]) + JA6[2][6];

T156[3][1]=-((h6[3]*h6[4])/d[6]) + JA6[3][1];
T156[3][2]=-((h6[3]*h6[5])/d[6]) + JA6[3][2];
T156[3][3]=-((h6[3]*h6[6])/d[6]) + JA6[3][3];
T156[3][4]=-((h6[1]*h6[3])/d[6]) + JA6[3][4];
T156[3][5]=-((h6[2]*h6[3])/d[6]) + JA6[3][5];
T156[3][6]=-(Power(h6[3],2)/d[6]) + JA6[3][6];

T156[4][1]=-(Power(h6[4],2)/d[6]) + JA6[4][1];
T156[4][2]=-((h6[4]*h6[5])/d[6]) + JA6[4][2];
T156[4][3]=-((h6[4]*h6[6])/d[6]) + JA6[4][3];
T156[4][4]=-((h6[1]*h6[4])/d[6]) + JA6[4][4];
T156[4][5]=-((h6[2]*h6[4])/d[6]) + JA6[4][5];
T156[4][6]=-((h6[3]*h6[4])/d[6]) + JA6[4][6];

T156[5][1]=-((h6[4]*h6[5])/d[6]) + JA6[5][1];
T156[5][2]=-(Power(h6[5],2)/d[6]) + JA6[5][2];
T156[5][3]=-((h6[5]*h6[6])/d[6]) + JA6[5][3];
T156[5][4]=-((h6[1]*h6[5])/d[6]) + JA6[5][4];
T156[5][5]=-((h6[2]*h6[5])/d[6]) + JA6[5][5];
T156[5][6]=-((h6[3]*h6[5])/d[6]) + JA6[5][6];

T156[6][1]=-((h6[4]*h6[6])/d[6]) + JA6[6][1];
T156[6][2]=-((h6[5]*h6[6])/d[6]) + JA6[6][2];
T156[6][3]=-(Power(h6[6],2)/d[6]) + JA6[6][3];
T156[6][4]=-((h6[1]*h6[6])/d[6]) + JA6[6][4];
T156[6][5]=-((h6[2]*h6[6])/d[6]) + JA6[6][5];
T156[6][6]=-((h6[3]*h6[6])/d[6]) + JA6[6][6];


T56[1][1]=S65[1][1]*(Si56[1][1]*T156[1][1] + Si56[1][2]*T156[2][1]) + S65[2][1]*(Si56[1][1]*T156[1][2] + Si56[1][2]*T156[2][2]) - l4*(Si56[1][1]*T156[1][6] + Si56[1][2]*T156[2][6]);
T56[1][2]=Si56[1][1]*T156[1][3] + Si56[1][2]*T156[2][3] + l4*S65[1][1]*(Si56[1][1]*T156[1][4] + Si56[1][2]*T156[2][4]) + l4*S65[2][1]*(Si56[1][1]*T156[1][5] + Si56[1][2]*T156[2][5]);
T56[1][3]=S65[1][3]*(Si56[1][1]*T156[1][1] + Si56[1][2]*T156[2][1]) + S65[2][3]*(Si56[1][1]*T156[1][2] + Si56[1][2]*T156[2][2]);
T56[1][4]=S65[1][1]*(Si56[1][1]*T156[1][4] + Si56[1][2]*T156[2][4]) + S65[2][1]*(Si56[1][1]*T156[1][5] + Si56[1][2]*T156[2][5]);
T56[1][5]=Si56[1][1]*T156[1][6] + Si56[1][2]*T156[2][6];
T56[1][6]=S65[1][3]*(Si56[1][1]*T156[1][4] + Si56[1][2]*T156[2][4]) + S65[2][3]*(Si56[1][1]*T156[1][5] + Si56[1][2]*T156[2][5]);

T56[2][1]=S65[1][1]*T156[3][1] + S65[2][1]*T156[3][2] - l4*T156[3][6];
T56[2][2]=T156[3][3] + l4*S65[1][1]*T156[3][4] + l4*S65[2][1]*T156[3][5];
T56[2][3]=S65[1][3]*T156[3][1] + S65[2][3]*T156[3][2];
T56[2][4]=S65[1][1]*T156[3][4] + S65[2][1]*T156[3][5];
T56[2][5]=T156[3][6];
T56[2][6]=S65[1][3]*T156[3][4] + S65[2][3]*T156[3][5];

T56[3][1]=S65[1][1]*(Si56[3][1]*T156[1][1] + Si56[3][2]*T156[2][1]) + S65[2][1]*(Si56[3][1]*T156[1][2] + Si56[3][2]*T156[2][2]) - l4*(Si56[3][1]*T156[1][6] + Si56[3][2]*T156[2][6]);
T56[3][2]=Si56[3][1]*T156[1][3] + Si56[3][2]*T156[2][3] + l4*S65[1][1]*(Si56[3][1]*T156[1][4] + Si56[3][2]*T156[2][4]) + l4*S65[2][1]*(Si56[3][1]*T156[1][5] + Si56[3][2]*T156[2][5]);
T56[3][3]=S65[1][3]*(Si56[3][1]*T156[1][1] + Si56[3][2]*T156[2][1]) + S65[2][3]*(Si56[3][1]*T156[1][2] + Si56[3][2]*T156[2][2]);
T56[3][4]=S65[1][1]*(Si56[3][1]*T156[1][4] + Si56[3][2]*T156[2][4]) + S65[2][1]*(Si56[3][1]*T156[1][5] + Si56[3][2]*T156[2][5]);
T56[3][5]=Si56[3][1]*T156[1][6] + Si56[3][2]*T156[2][6];
T56[3][6]=S65[1][3]*(Si56[3][1]*T156[1][4] + Si56[3][2]*T156[2][4]) + S65[2][3]*(Si56[3][1]*T156[1][5] + Si56[3][2]*T156[2][5]);

T56[4][1]=S65[1][1]*(-(l4*T156[3][1]) + Si56[1][1]*T156[4][1] + Si56[1][2]*T156[5][1]) + S65[2][1]*(-(l4*T156[3][2]) + Si56[1][1]*T156[4][2] + Si56[1][2]*T156[5][2]) - l4*(-(l4*T156[3][6]) + Si56[1][1]*T156[4][6] + Si56[1][2]*T156[5][6]);
T56[4][2]=-(l4*T156[3][3]) + Si56[1][1]*T156[4][3] + Si56[1][2]*T156[5][3] + l4*S65[1][1]*(-(l4*T156[3][4]) + Si56[1][1]*T156[4][4] + Si56[1][2]*T156[5][4]) + l4*S65[2][1]*(-(l4*T156[3][5]) + Si56[1][1]*T156[4][5] + Si56[1][2]*T156[5][5]);
T56[4][3]=S65[1][3]*(-(l4*T156[3][1]) + Si56[1][1]*T156[4][1] + Si56[1][2]*T156[5][1]) + S65[2][3]*(-(l4*T156[3][2]) + Si56[1][1]*T156[4][2] + Si56[1][2]*T156[5][2]);
T56[4][4]=S65[1][1]*(-(l4*T156[3][4]) + Si56[1][1]*T156[4][4] + Si56[1][2]*T156[5][4]) + S65[2][1]*(-(l4*T156[3][5]) + Si56[1][1]*T156[4][5] + Si56[1][2]*T156[5][5]);
T56[4][5]=-(l4*T156[3][6]) + Si56[1][1]*T156[4][6] + Si56[1][2]*T156[5][6];
T56[4][6]=S65[1][3]*(-(l4*T156[3][4]) + Si56[1][1]*T156[4][4] + Si56[1][2]*T156[5][4]) + S65[2][3]*(-(l4*T156[3][5]) + Si56[1][1]*T156[4][5] + Si56[1][2]*T156[5][5]);

T56[5][1]=S65[1][1]*(l4*Si56[1][1]*T156[1][1] + l4*Si56[1][2]*T156[2][1] + T156[6][1]) + S65[2][1]*(l4*Si56[1][1]*T156[1][2] + l4*Si56[1][2]*T156[2][2] + T156[6][2]) - l4*(l4*Si56[1][1]*T156[1][6] + l4*Si56[1][2]*T156[2][6] + T156[6][6]);
T56[5][2]=l4*Si56[1][1]*T156[1][3] + l4*Si56[1][2]*T156[2][3] + T156[6][3] + l4*S65[1][1]*(l4*Si56[1][1]*T156[1][4] + l4*Si56[1][2]*T156[2][4] + T156[6][4]) + l4*S65[2][1]*(l4*Si56[1][1]*T156[1][5] + l4*Si56[1][2]*T156[2][5] + T156[6][5]);
T56[5][3]=S65[1][3]*(l4*Si56[1][1]*T156[1][1] + l4*Si56[1][2]*T156[2][1] + T156[6][1]) + S65[2][3]*(l4*Si56[1][1]*T156[1][2] + l4*Si56[1][2]*T156[2][2] + T156[6][2]);
T56[5][4]=S65[1][1]*(l4*Si56[1][1]*T156[1][4] + l4*Si56[1][2]*T156[2][4] + T156[6][4]) + S65[2][1]*(l4*Si56[1][1]*T156[1][5] + l4*Si56[1][2]*T156[2][5] + T156[6][5]);
T56[5][5]=l4*Si56[1][1]*T156[1][6] + l4*Si56[1][2]*T156[2][6] + T156[6][6];
T56[5][6]=S65[1][3]*(l4*Si56[1][1]*T156[1][4] + l4*Si56[1][2]*T156[2][4] + T156[6][4]) + S65[2][3]*(l4*Si56[1][1]*T156[1][5] + l4*Si56[1][2]*T156[2][5] + T156[6][5]);

T56[6][1]=S65[1][1]*(Si56[3][1]*T156[4][1] + Si56[3][2]*T156[5][1]) + S65[2][1]*(Si56[3][1]*T156[4][2] + Si56[3][2]*T156[5][2]) - l4*(Si56[3][1]*T156[4][6] + Si56[3][2]*T156[5][6]);
T56[6][2]=Si56[3][1]*T156[4][3] + Si56[3][2]*T156[5][3] + l4*S65[1][1]*(Si56[3][1]*T156[4][4] + Si56[3][2]*T156[5][4]) + l4*S65[2][1]*(Si56[3][1]*T156[4][5] + Si56[3][2]*T156[5][5]);
T56[6][3]=S65[1][3]*(Si56[3][1]*T156[4][1] + Si56[3][2]*T156[5][1]) + S65[2][3]*(Si56[3][1]*T156[4][2] + Si56[3][2]*T156[5][2]);
T56[6][4]=S65[1][1]*(Si56[3][1]*T156[4][4] + Si56[3][2]*T156[5][4]) + S65[2][1]*(Si56[3][1]*T156[4][5] + Si56[3][2]*T156[5][5]);
T56[6][5]=Si56[3][1]*T156[4][6] + Si56[3][2]*T156[5][6];
T56[6][6]=S65[1][3]*(Si56[3][1]*T156[4][4] + Si56[3][2]*T156[5][4]) + S65[2][3]*(Si56[3][1]*T156[4][5] + Si56[3][2]*T156[5][5]);



}


void
master_ForDynArtfunc15(void)
      {
JA5[1][1]=T56[1][1];
JA5[1][2]=links[5].mcm[3] + T56[1][2];
JA5[1][3]=-links[5].mcm[2] + T56[1][3];
JA5[1][4]=links[5].m + T56[1][4];
JA5[1][5]=T56[1][5];
JA5[1][6]=T56[1][6];

JA5[2][1]=-links[5].mcm[3] + T56[2][1];
JA5[2][2]=T56[2][2];
JA5[2][3]=links[5].mcm[1] + T56[2][3];
JA5[2][4]=T56[2][4];
JA5[2][5]=links[5].m + T56[2][5];
JA5[2][6]=T56[2][6];

JA5[3][1]=links[5].mcm[2] + T56[3][1];
JA5[3][2]=-links[5].mcm[1] + T56[3][2];
JA5[3][3]=T56[3][3];
JA5[3][4]=T56[3][4];
JA5[3][5]=T56[3][5];
JA5[3][6]=links[5].m + T56[3][6];

JA5[4][1]=links[5].inertia[1][1] + T56[4][1];
JA5[4][2]=links[5].inertia[1][2] + T56[4][2];
JA5[4][3]=links[5].inertia[1][3] + T56[4][3];
JA5[4][4]=T56[4][4];
JA5[4][5]=-links[5].mcm[3] + T56[4][5];
JA5[4][6]=links[5].mcm[2] + T56[4][6];

JA5[5][1]=links[5].inertia[1][2] + T56[5][1];
JA5[5][2]=links[5].inertia[2][2] + T56[5][2];
JA5[5][3]=links[5].inertia[2][3] + T56[5][3];
JA5[5][4]=links[5].mcm[3] + T56[5][4];
JA5[5][5]=T56[5][5];
JA5[5][6]=-links[5].mcm[1] + T56[5][6];

JA5[6][1]=links[5].inertia[1][3] + T56[6][1];
JA5[6][2]=links[5].inertia[2][3] + T56[6][2];
JA5[6][3]=links[5].inertia[3][3] + T56[6][3];
JA5[6][4]=-links[5].mcm[2] + T56[6][4];
JA5[6][5]=links[5].mcm[1] + T56[6][5];
JA5[6][6]=T56[6][6];


h5[1]=JA5[1][3];
h5[2]=JA5[2][3];
h5[3]=JA5[3][3];
h5[4]=JA5[4][3];
h5[5]=JA5[5][3];
h5[6]=JA5[6][3];

d[5]=1.e-10 + h5[6];

T145[1][1]=-((h5[1]*h5[4])/d[5]) + JA5[1][1];
T145[1][2]=-((h5[1]*h5[5])/d[5]) + JA5[1][2];
T145[1][3]=-((h5[1]*h5[6])/d[5]) + JA5[1][3];
T145[1][4]=-(Power(h5[1],2)/d[5]) + JA5[1][4];
T145[1][5]=-((h5[1]*h5[2])/d[5]) + JA5[1][5];
T145[1][6]=-((h5[1]*h5[3])/d[5]) + JA5[1][6];

T145[2][1]=-((h5[2]*h5[4])/d[5]) + JA5[2][1];
T145[2][2]=-((h5[2]*h5[5])/d[5]) + JA5[2][2];
T145[2][3]=-((h5[2]*h5[6])/d[5]) + JA5[2][3];
T145[2][4]=-((h5[1]*h5[2])/d[5]) + JA5[2][4];
T145[2][5]=-(Power(h5[2],2)/d[5]) + JA5[2][5];
T145[2][6]=-((h5[2]*h5[3])/d[5]) + JA5[2][6];

T145[3][1]=-((h5[3]*h5[4])/d[5]) + JA5[3][1];
T145[3][2]=-((h5[3]*h5[5])/d[5]) + JA5[3][2];
T145[3][3]=-((h5[3]*h5[6])/d[5]) + JA5[3][3];
T145[3][4]=-((h5[1]*h5[3])/d[5]) + JA5[3][4];
T145[3][5]=-((h5[2]*h5[3])/d[5]) + JA5[3][5];
T145[3][6]=-(Power(h5[3],2)/d[5]) + JA5[3][6];

T145[4][1]=-(Power(h5[4],2)/d[5]) + JA5[4][1];
T145[4][2]=-((h5[4]*h5[5])/d[5]) + JA5[4][2];
T145[4][3]=-((h5[4]*h5[6])/d[5]) + JA5[4][3];
T145[4][4]=-((h5[1]*h5[4])/d[5]) + JA5[4][4];
T145[4][5]=-((h5[2]*h5[4])/d[5]) + JA5[4][5];
T145[4][6]=-((h5[3]*h5[4])/d[5]) + JA5[4][6];

T145[5][1]=-((h5[4]*h5[5])/d[5]) + JA5[5][1];
T145[5][2]=-(Power(h5[5],2)/d[5]) + JA5[5][2];
T145[5][3]=-((h5[5]*h5[6])/d[5]) + JA5[5][3];
T145[5][4]=-((h5[1]*h5[5])/d[5]) + JA5[5][4];
T145[5][5]=-((h5[2]*h5[5])/d[5]) + JA5[5][5];
T145[5][6]=-((h5[3]*h5[5])/d[5]) + JA5[5][6];

T145[6][1]=-((h5[4]*h5[6])/d[5]) + JA5[6][1];
T145[6][2]=-((h5[5]*h5[6])/d[5]) + JA5[6][2];
T145[6][3]=-(Power(h5[6],2)/d[5]) + JA5[6][3];
T145[6][4]=-((h5[1]*h5[6])/d[5]) + JA5[6][4];
T145[6][5]=-((h5[2]*h5[6])/d[5]) + JA5[6][5];
T145[6][6]=-((h5[3]*h5[6])/d[5]) + JA5[6][6];


T45[1][1]=T145[3][3] - l3*S54[1][2]*T145[3][4] - l3*S54[2][2]*T145[3][5];
T45[1][2]=-(S54[1][2]*T145[3][1]) - S54[2][2]*T145[3][2] - l3*T145[3][6];
T45[1][3]=-(S54[1][3]*T145[3][1]) - S54[2][3]*T145[3][2];
T45[1][4]=T145[3][6];
T45[1][5]=-(S54[1][2]*T145[3][4]) - S54[2][2]*T145[3][5];
T45[1][6]=-(S54[1][3]*T145[3][4]) - S54[2][3]*T145[3][5];

T45[2][1]=-(Si45[2][1]*T145[1][3]) - Si45[2][2]*T145[2][3] + l3*S54[1][2]*(Si45[2][1]*T145[1][4] + Si45[2][2]*T145[2][4]) + l3*S54[2][2]*(Si45[2][1]*T145[1][5] + Si45[2][2]*T145[2][5]);
T45[2][2]=S54[1][2]*(Si45[2][1]*T145[1][1] + Si45[2][2]*T145[2][1]) + S54[2][2]*(Si45[2][1]*T145[1][2] + Si45[2][2]*T145[2][2]) + l3*(Si45[2][1]*T145[1][6] + Si45[2][2]*T145[2][6]);
T45[2][3]=S54[1][3]*(Si45[2][1]*T145[1][1] + Si45[2][2]*T145[2][1]) + S54[2][3]*(Si45[2][1]*T145[1][2] + Si45[2][2]*T145[2][2]);
T45[2][4]=-(Si45[2][1]*T145[1][6]) - Si45[2][2]*T145[2][6];
T45[2][5]=S54[1][2]*(Si45[2][1]*T145[1][4] + Si45[2][2]*T145[2][4]) + S54[2][2]*(Si45[2][1]*T145[1][5] + Si45[2][2]*T145[2][5]);
T45[2][6]=S54[1][3]*(Si45[2][1]*T145[1][4] + Si45[2][2]*T145[2][4]) + S54[2][3]*(Si45[2][1]*T145[1][5] + Si45[2][2]*T145[2][5]);

T45[3][1]=-(Si45[3][1]*T145[1][3]) - Si45[3][2]*T145[2][3] + l3*S54[1][2]*(Si45[3][1]*T145[1][4] + Si45[3][2]*T145[2][4]) + l3*S54[2][2]*(Si45[3][1]*T145[1][5] + Si45[3][2]*T145[2][5]);
T45[3][2]=S54[1][2]*(Si45[3][1]*T145[1][1] + Si45[3][2]*T145[2][1]) + S54[2][2]*(Si45[3][1]*T145[1][2] + Si45[3][2]*T145[2][2]) + l3*(Si45[3][1]*T145[1][6] + Si45[3][2]*T145[2][6]);
T45[3][3]=S54[1][3]*(Si45[3][1]*T145[1][1] + Si45[3][2]*T145[2][1]) + S54[2][3]*(Si45[3][1]*T145[1][2] + Si45[3][2]*T145[2][2]);
T45[3][4]=-(Si45[3][1]*T145[1][6]) - Si45[3][2]*T145[2][6];
T45[3][5]=S54[1][2]*(Si45[3][1]*T145[1][4] + Si45[3][2]*T145[2][4]) + S54[2][2]*(Si45[3][1]*T145[1][5] + Si45[3][2]*T145[2][5]);
T45[3][6]=S54[1][3]*(Si45[3][1]*T145[1][4] + Si45[3][2]*T145[2][4]) + S54[2][3]*(Si45[3][1]*T145[1][5] + Si45[3][2]*T145[2][5]);

T45[4][1]=-(l3*Si45[2][1]*T145[1][3]) - l3*Si45[2][2]*T145[2][3] + T145[6][3] + l3*S54[1][2]*(l3*Si45[2][1]*T145[1][4] + l3*Si45[2][2]*T145[2][4] - T145[6][4]) + l3*S54[2][2]*(l3*Si45[2][1]*T145[1][5] + l3*Si45[2][2]*T145[2][5] - T145[6][5]);
T45[4][2]=S54[1][2]*(l3*Si45[2][1]*T145[1][1] + l3*Si45[2][2]*T145[2][1] - T145[6][1]) + S54[2][2]*(l3*Si45[2][1]*T145[1][2] + l3*Si45[2][2]*T145[2][2] - T145[6][2]) + l3*(l3*Si45[2][1]*T145[1][6] + l3*Si45[2][2]*T145[2][6] - T145[6][6]);
T45[4][3]=S54[1][3]*(l3*Si45[2][1]*T145[1][1] + l3*Si45[2][2]*T145[2][1] - T145[6][1]) + S54[2][3]*(l3*Si45[2][1]*T145[1][2] + l3*Si45[2][2]*T145[2][2] - T145[6][2]);
T45[4][4]=-(l3*Si45[2][1]*T145[1][6]) - l3*Si45[2][2]*T145[2][6] + T145[6][6];
T45[4][5]=S54[1][2]*(l3*Si45[2][1]*T145[1][4] + l3*Si45[2][2]*T145[2][4] - T145[6][4]) + S54[2][2]*(l3*Si45[2][1]*T145[1][5] + l3*Si45[2][2]*T145[2][5] - T145[6][5]);
T45[4][6]=S54[1][3]*(l3*Si45[2][1]*T145[1][4] + l3*Si45[2][2]*T145[2][4] - T145[6][4]) + S54[2][3]*(l3*Si45[2][1]*T145[1][5] + l3*Si45[2][2]*T145[2][5] - T145[6][5]);

T45[5][1]=-(l3*T145[3][3]) - Si45[2][1]*T145[4][3] - Si45[2][2]*T145[5][3] + l3*S54[1][2]*(l3*T145[3][4] + Si45[2][1]*T145[4][4] + Si45[2][2]*T145[5][4]) + l3*S54[2][2]*(l3*T145[3][5] + Si45[2][1]*T145[4][5] + Si45[2][2]*T145[5][5]);
T45[5][2]=S54[1][2]*(l3*T145[3][1] + Si45[2][1]*T145[4][1] + Si45[2][2]*T145[5][1]) + S54[2][2]*(l3*T145[3][2] + Si45[2][1]*T145[4][2] + Si45[2][2]*T145[5][2]) + l3*(l3*T145[3][6] + Si45[2][1]*T145[4][6] + Si45[2][2]*T145[5][6]);
T45[5][3]=S54[1][3]*(l3*T145[3][1] + Si45[2][1]*T145[4][1] + Si45[2][2]*T145[5][1]) + S54[2][3]*(l3*T145[3][2] + Si45[2][1]*T145[4][2] + Si45[2][2]*T145[5][2]);
T45[5][4]=-(l3*T145[3][6]) - Si45[2][1]*T145[4][6] - Si45[2][2]*T145[5][6];
T45[5][5]=S54[1][2]*(l3*T145[3][4] + Si45[2][1]*T145[4][4] + Si45[2][2]*T145[5][4]) + S54[2][2]*(l3*T145[3][5] + Si45[2][1]*T145[4][5] + Si45[2][2]*T145[5][5]);
T45[5][6]=S54[1][3]*(l3*T145[3][4] + Si45[2][1]*T145[4][4] + Si45[2][2]*T145[5][4]) + S54[2][3]*(l3*T145[3][5] + Si45[2][1]*T145[4][5] + Si45[2][2]*T145[5][5]);

T45[6][1]=-(Si45[3][1]*T145[4][3]) - Si45[3][2]*T145[5][3] + l3*S54[1][2]*(Si45[3][1]*T145[4][4] + Si45[3][2]*T145[5][4]) + l3*S54[2][2]*(Si45[3][1]*T145[4][5] + Si45[3][2]*T145[5][5]);
T45[6][2]=S54[1][2]*(Si45[3][1]*T145[4][1] + Si45[3][2]*T145[5][1]) + S54[2][2]*(Si45[3][1]*T145[4][2] + Si45[3][2]*T145[5][2]) + l3*(Si45[3][1]*T145[4][6] + Si45[3][2]*T145[5][6]);
T45[6][3]=S54[1][3]*(Si45[3][1]*T145[4][1] + Si45[3][2]*T145[5][1]) + S54[2][3]*(Si45[3][1]*T145[4][2] + Si45[3][2]*T145[5][2]);
T45[6][4]=-(Si45[3][1]*T145[4][6]) - Si45[3][2]*T145[5][6];
T45[6][5]=S54[1][2]*(Si45[3][1]*T145[4][4] + Si45[3][2]*T145[5][4]) + S54[2][2]*(Si45[3][1]*T145[4][5] + Si45[3][2]*T145[5][5]);
T45[6][6]=S54[1][3]*(Si45[3][1]*T145[4][4] + Si45[3][2]*T145[5][4]) + S54[2][3]*(Si45[3][1]*T145[4][5] + Si45[3][2]*T145[5][5]);



}


void
master_ForDynArtfunc16(void)
      {
JA4[1][1]=T45[1][1];
JA4[1][2]=links[4].mcm[3] + T45[1][2];
JA4[1][3]=-links[4].mcm[2] + T45[1][3];
JA4[1][4]=links[4].m + T45[1][4];
JA4[1][5]=T45[1][5];
JA4[1][6]=T45[1][6];

JA4[2][1]=-links[4].mcm[3] + T45[2][1];
JA4[2][2]=T45[2][2];
JA4[2][3]=links[4].mcm[1] + T45[2][3];
JA4[2][4]=T45[2][4];
JA4[2][5]=links[4].m + T45[2][5];
JA4[2][6]=T45[2][6];

JA4[3][1]=links[4].mcm[2] + T45[3][1];
JA4[3][2]=-links[4].mcm[1] + T45[3][2];
JA4[3][3]=T45[3][3];
JA4[3][4]=T45[3][4];
JA4[3][5]=T45[3][5];
JA4[3][6]=links[4].m + T45[3][6];

JA4[4][1]=links[4].inertia[1][1] + T45[4][1];
JA4[4][2]=links[4].inertia[1][2] + T45[4][2];
JA4[4][3]=links[4].inertia[1][3] + T45[4][3];
JA4[4][4]=T45[4][4];
JA4[4][5]=-links[4].mcm[3] + T45[4][5];
JA4[4][6]=links[4].mcm[2] + T45[4][6];

JA4[5][1]=links[4].inertia[1][2] + T45[5][1];
JA4[5][2]=links[4].inertia[2][2] + T45[5][2];
JA4[5][3]=links[4].inertia[2][3] + T45[5][3];
JA4[5][4]=links[4].mcm[3] + T45[5][4];
JA4[5][5]=T45[5][5];
JA4[5][6]=-links[4].mcm[1] + T45[5][6];

JA4[6][1]=links[4].inertia[1][3] + T45[6][1];
JA4[6][2]=links[4].inertia[2][3] + T45[6][2];
JA4[6][3]=links[4].inertia[3][3] + T45[6][3];
JA4[6][4]=-links[4].mcm[2] + T45[6][4];
JA4[6][5]=links[4].mcm[1] + T45[6][5];
JA4[6][6]=T45[6][6];


h4[1]=JA4[1][3];
h4[2]=JA4[2][3];
h4[3]=JA4[3][3];
h4[4]=JA4[4][3];
h4[5]=JA4[5][3];
h4[6]=JA4[6][3];

d[4]=1.e-10 + h4[6];

T134[1][1]=-((h4[1]*h4[4])/d[4]) + JA4[1][1];
T134[1][2]=-((h4[1]*h4[5])/d[4]) + JA4[1][2];
T134[1][3]=-((h4[1]*h4[6])/d[4]) + JA4[1][3];
T134[1][4]=-(Power(h4[1],2)/d[4]) + JA4[1][4];
T134[1][5]=-((h4[1]*h4[2])/d[4]) + JA4[1][5];
T134[1][6]=-((h4[1]*h4[3])/d[4]) + JA4[1][6];

T134[2][1]=-((h4[2]*h4[4])/d[4]) + JA4[2][1];
T134[2][2]=-((h4[2]*h4[5])/d[4]) + JA4[2][2];
T134[2][3]=-((h4[2]*h4[6])/d[4]) + JA4[2][3];
T134[2][4]=-((h4[1]*h4[2])/d[4]) + JA4[2][4];
T134[2][5]=-(Power(h4[2],2)/d[4]) + JA4[2][5];
T134[2][6]=-((h4[2]*h4[3])/d[4]) + JA4[2][6];

T134[3][1]=-((h4[3]*h4[4])/d[4]) + JA4[3][1];
T134[3][2]=-((h4[3]*h4[5])/d[4]) + JA4[3][2];
T134[3][3]=-((h4[3]*h4[6])/d[4]) + JA4[3][3];
T134[3][4]=-((h4[1]*h4[3])/d[4]) + JA4[3][4];
T134[3][5]=-((h4[2]*h4[3])/d[4]) + JA4[3][5];
T134[3][6]=-(Power(h4[3],2)/d[4]) + JA4[3][6];

T134[4][1]=-(Power(h4[4],2)/d[4]) + JA4[4][1];
T134[4][2]=-((h4[4]*h4[5])/d[4]) + JA4[4][2];
T134[4][3]=-((h4[4]*h4[6])/d[4]) + JA4[4][3];
T134[4][4]=-((h4[1]*h4[4])/d[4]) + JA4[4][4];
T134[4][5]=-((h4[2]*h4[4])/d[4]) + JA4[4][5];
T134[4][6]=-((h4[3]*h4[4])/d[4]) + JA4[4][6];

T134[5][1]=-((h4[4]*h4[5])/d[4]) + JA4[5][1];
T134[5][2]=-(Power(h4[5],2)/d[4]) + JA4[5][2];
T134[5][3]=-((h4[5]*h4[6])/d[4]) + JA4[5][3];
T134[5][4]=-((h4[1]*h4[5])/d[4]) + JA4[5][4];
T134[5][5]=-((h4[2]*h4[5])/d[4]) + JA4[5][5];
T134[5][6]=-((h4[3]*h4[5])/d[4]) + JA4[5][6];

T134[6][1]=-((h4[4]*h4[6])/d[4]) + JA4[6][1];
T134[6][2]=-((h4[5]*h4[6])/d[4]) + JA4[6][2];
T134[6][3]=-(Power(h4[6],2)/d[4]) + JA4[6][3];
T134[6][4]=-((h4[1]*h4[6])/d[4]) + JA4[6][4];
T134[6][5]=-((h4[2]*h4[6])/d[4]) + JA4[6][5];
T134[6][6]=-((h4[3]*h4[6])/d[4]) + JA4[6][6];


T34[1][1]=S43[1][1]*(Si34[1][1]*T134[1][1] + Si34[1][2]*T134[2][1]) + S43[2][1]*(Si34[1][1]*T134[1][2] + Si34[1][2]*T134[2][2]) + l2*(Si34[1][1]*T134[1][6] + Si34[1][2]*T134[2][6]);
T34[1][2]=-(Si34[1][1]*T134[1][3]) - Si34[1][2]*T134[2][3] + l2*S43[1][1]*(Si34[1][1]*T134[1][4] + Si34[1][2]*T134[2][4]) + l2*S43[2][1]*(Si34[1][1]*T134[1][5] + Si34[1][2]*T134[2][5]);
T34[1][3]=S43[1][3]*(Si34[1][1]*T134[1][1] + Si34[1][2]*T134[2][1]) + S43[2][3]*(Si34[1][1]*T134[1][2] + Si34[1][2]*T134[2][2]);
T34[1][4]=S43[1][1]*(Si34[1][1]*T134[1][4] + Si34[1][2]*T134[2][4]) + S43[2][1]*(Si34[1][1]*T134[1][5] + Si34[1][2]*T134[2][5]);
T34[1][5]=-(Si34[1][1]*T134[1][6]) - Si34[1][2]*T134[2][6];
T34[1][6]=S43[1][3]*(Si34[1][1]*T134[1][4] + Si34[1][2]*T134[2][4]) + S43[2][3]*(Si34[1][1]*T134[1][5] + Si34[1][2]*T134[2][5]);

T34[2][1]=-(S43[1][1]*T134[3][1]) - S43[2][1]*T134[3][2] - l2*T134[3][6];
T34[2][2]=T134[3][3] - l2*S43[1][1]*T134[3][4] - l2*S43[2][1]*T134[3][5];
T34[2][3]=-(S43[1][3]*T134[3][1]) - S43[2][3]*T134[3][2];
T34[2][4]=-(S43[1][1]*T134[3][4]) - S43[2][1]*T134[3][5];
T34[2][5]=T134[3][6];
T34[2][6]=-(S43[1][3]*T134[3][4]) - S43[2][3]*T134[3][5];

T34[3][1]=S43[1][1]*(Si34[3][1]*T134[1][1] + Si34[3][2]*T134[2][1]) + S43[2][1]*(Si34[3][1]*T134[1][2] + Si34[3][2]*T134[2][2]) + l2*(Si34[3][1]*T134[1][6] + Si34[3][2]*T134[2][6]);
T34[3][2]=-(Si34[3][1]*T134[1][3]) - Si34[3][2]*T134[2][3] + l2*S43[1][1]*(Si34[3][1]*T134[1][4] + Si34[3][2]*T134[2][4]) + l2*S43[2][1]*(Si34[3][1]*T134[1][5] + Si34[3][2]*T134[2][5]);
T34[3][3]=S43[1][3]*(Si34[3][1]*T134[1][1] + Si34[3][2]*T134[2][1]) + S43[2][3]*(Si34[3][1]*T134[1][2] + Si34[3][2]*T134[2][2]);
T34[3][4]=S43[1][1]*(Si34[3][1]*T134[1][4] + Si34[3][2]*T134[2][4]) + S43[2][1]*(Si34[3][1]*T134[1][5] + Si34[3][2]*T134[2][5]);
T34[3][5]=-(Si34[3][1]*T134[1][6]) - Si34[3][2]*T134[2][6];
T34[3][6]=S43[1][3]*(Si34[3][1]*T134[1][4] + Si34[3][2]*T134[2][4]) + S43[2][3]*(Si34[3][1]*T134[1][5] + Si34[3][2]*T134[2][5]);

T34[4][1]=S43[1][1]*(l2*T134[3][1] + Si34[1][1]*T134[4][1] + Si34[1][2]*T134[5][1]) + S43[2][1]*(l2*T134[3][2] + Si34[1][1]*T134[4][2] + Si34[1][2]*T134[5][2]) + l2*(l2*T134[3][6] + Si34[1][1]*T134[4][6] + Si34[1][2]*T134[5][6]);
T34[4][2]=-(l2*T134[3][3]) - Si34[1][1]*T134[4][3] - Si34[1][2]*T134[5][3] + l2*S43[1][1]*(l2*T134[3][4] + Si34[1][1]*T134[4][4] + Si34[1][2]*T134[5][4]) + l2*S43[2][1]*(l2*T134[3][5] + Si34[1][1]*T134[4][5] + Si34[1][2]*T134[5][5]);
T34[4][3]=S43[1][3]*(l2*T134[3][1] + Si34[1][1]*T134[4][1] + Si34[1][2]*T134[5][1]) + S43[2][3]*(l2*T134[3][2] + Si34[1][1]*T134[4][2] + Si34[1][2]*T134[5][2]);
T34[4][4]=S43[1][1]*(l2*T134[3][4] + Si34[1][1]*T134[4][4] + Si34[1][2]*T134[5][4]) + S43[2][1]*(l2*T134[3][5] + Si34[1][1]*T134[4][5] + Si34[1][2]*T134[5][5]);
T34[4][5]=-(l2*T134[3][6]) - Si34[1][1]*T134[4][6] - Si34[1][2]*T134[5][6];
T34[4][6]=S43[1][3]*(l2*T134[3][4] + Si34[1][1]*T134[4][4] + Si34[1][2]*T134[5][4]) + S43[2][3]*(l2*T134[3][5] + Si34[1][1]*T134[4][5] + Si34[1][2]*T134[5][5]);

T34[5][1]=S43[1][1]*(l2*Si34[1][1]*T134[1][1] + l2*Si34[1][2]*T134[2][1] - T134[6][1]) + S43[2][1]*(l2*Si34[1][1]*T134[1][2] + l2*Si34[1][2]*T134[2][2] - T134[6][2]) + l2*(l2*Si34[1][1]*T134[1][6] + l2*Si34[1][2]*T134[2][6] - T134[6][6]);
T34[5][2]=-(l2*Si34[1][1]*T134[1][3]) - l2*Si34[1][2]*T134[2][3] + T134[6][3] + l2*S43[1][1]*(l2*Si34[1][1]*T134[1][4] + l2*Si34[1][2]*T134[2][4] - T134[6][4]) + l2*S43[2][1]*(l2*Si34[1][1]*T134[1][5] + l2*Si34[1][2]*T134[2][5] - T134[6][5]);
T34[5][3]=S43[1][3]*(l2*Si34[1][1]*T134[1][1] + l2*Si34[1][2]*T134[2][1] - T134[6][1]) + S43[2][3]*(l2*Si34[1][1]*T134[1][2] + l2*Si34[1][2]*T134[2][2] - T134[6][2]);
T34[5][4]=S43[1][1]*(l2*Si34[1][1]*T134[1][4] + l2*Si34[1][2]*T134[2][4] - T134[6][4]) + S43[2][1]*(l2*Si34[1][1]*T134[1][5] + l2*Si34[1][2]*T134[2][5] - T134[6][5]);
T34[5][5]=-(l2*Si34[1][1]*T134[1][6]) - l2*Si34[1][2]*T134[2][6] + T134[6][6];
T34[5][6]=S43[1][3]*(l2*Si34[1][1]*T134[1][4] + l2*Si34[1][2]*T134[2][4] - T134[6][4]) + S43[2][3]*(l2*Si34[1][1]*T134[1][5] + l2*Si34[1][2]*T134[2][5] - T134[6][5]);

T34[6][1]=S43[1][1]*(Si34[3][1]*T134[4][1] + Si34[3][2]*T134[5][1]) + S43[2][1]*(Si34[3][1]*T134[4][2] + Si34[3][2]*T134[5][2]) + l2*(Si34[3][1]*T134[4][6] + Si34[3][2]*T134[5][6]);
T34[6][2]=-(Si34[3][1]*T134[4][3]) - Si34[3][2]*T134[5][3] + l2*S43[1][1]*(Si34[3][1]*T134[4][4] + Si34[3][2]*T134[5][4]) + l2*S43[2][1]*(Si34[3][1]*T134[4][5] + Si34[3][2]*T134[5][5]);
T34[6][3]=S43[1][3]*(Si34[3][1]*T134[4][1] + Si34[3][2]*T134[5][1]) + S43[2][3]*(Si34[3][1]*T134[4][2] + Si34[3][2]*T134[5][2]);
T34[6][4]=S43[1][1]*(Si34[3][1]*T134[4][4] + Si34[3][2]*T134[5][4]) + S43[2][1]*(Si34[3][1]*T134[4][5] + Si34[3][2]*T134[5][5]);
T34[6][5]=-(Si34[3][1]*T134[4][6]) - Si34[3][2]*T134[5][6];
T34[6][6]=S43[1][3]*(Si34[3][1]*T134[4][4] + Si34[3][2]*T134[5][4]) + S43[2][3]*(Si34[3][1]*T134[4][5] + Si34[3][2]*T134[5][5]);



}


void
master_ForDynArtfunc17(void)
      {
JA3[1][1]=T34[1][1];
JA3[1][2]=links[3].mcm[3] + T34[1][2];
JA3[1][3]=-links[3].mcm[2] + T34[1][3];
JA3[1][4]=links[3].m + T34[1][4];
JA3[1][5]=T34[1][5];
JA3[1][6]=T34[1][6];

JA3[2][1]=-links[3].mcm[3] + T34[2][1];
JA3[2][2]=T34[2][2];
JA3[2][3]=links[3].mcm[1] + T34[2][3];
JA3[2][4]=T34[2][4];
JA3[2][5]=links[3].m + T34[2][5];
JA3[2][6]=T34[2][6];

JA3[3][1]=links[3].mcm[2] + T34[3][1];
JA3[3][2]=-links[3].mcm[1] + T34[3][2];
JA3[3][3]=T34[3][3];
JA3[3][4]=T34[3][4];
JA3[3][5]=T34[3][5];
JA3[3][6]=links[3].m + T34[3][6];

JA3[4][1]=links[3].inertia[1][1] + T34[4][1];
JA3[4][2]=links[3].inertia[1][2] + T34[4][2];
JA3[4][3]=links[3].inertia[1][3] + T34[4][3];
JA3[4][4]=T34[4][4];
JA3[4][5]=-links[3].mcm[3] + T34[4][5];
JA3[4][6]=links[3].mcm[2] + T34[4][6];

JA3[5][1]=links[3].inertia[1][2] + T34[5][1];
JA3[5][2]=links[3].inertia[2][2] + T34[5][2];
JA3[5][3]=links[3].inertia[2][3] + T34[5][3];
JA3[5][4]=links[3].mcm[3] + T34[5][4];
JA3[5][5]=T34[5][5];
JA3[5][6]=-links[3].mcm[1] + T34[5][6];

JA3[6][1]=links[3].inertia[1][3] + T34[6][1];
JA3[6][2]=links[3].inertia[2][3] + T34[6][2];
JA3[6][3]=links[3].inertia[3][3] + T34[6][3];
JA3[6][4]=-links[3].mcm[2] + T34[6][4];
JA3[6][5]=links[3].mcm[1] + T34[6][5];
JA3[6][6]=T34[6][6];


h3[1]=JA3[1][3];
h3[2]=JA3[2][3];
h3[3]=JA3[3][3];
h3[4]=JA3[4][3];
h3[5]=JA3[5][3];
h3[6]=JA3[6][3];

d[3]=1.e-10 + h3[6];

T123[1][1]=-((h3[1]*h3[4])/d[3]) + JA3[1][1];
T123[1][2]=-((h3[1]*h3[5])/d[3]) + JA3[1][2];
T123[1][3]=-((h3[1]*h3[6])/d[3]) + JA3[1][3];
T123[1][4]=-(Power(h3[1],2)/d[3]) + JA3[1][4];
T123[1][5]=-((h3[1]*h3[2])/d[3]) + JA3[1][5];
T123[1][6]=-((h3[1]*h3[3])/d[3]) + JA3[1][6];

T123[2][1]=-((h3[2]*h3[4])/d[3]) + JA3[2][1];
T123[2][2]=-((h3[2]*h3[5])/d[3]) + JA3[2][2];
T123[2][3]=-((h3[2]*h3[6])/d[3]) + JA3[2][3];
T123[2][4]=-((h3[1]*h3[2])/d[3]) + JA3[2][4];
T123[2][5]=-(Power(h3[2],2)/d[3]) + JA3[2][5];
T123[2][6]=-((h3[2]*h3[3])/d[3]) + JA3[2][6];

T123[3][1]=-((h3[3]*h3[4])/d[3]) + JA3[3][1];
T123[3][2]=-((h3[3]*h3[5])/d[3]) + JA3[3][2];
T123[3][3]=-((h3[3]*h3[6])/d[3]) + JA3[3][3];
T123[3][4]=-((h3[1]*h3[3])/d[3]) + JA3[3][4];
T123[3][5]=-((h3[2]*h3[3])/d[3]) + JA3[3][5];
T123[3][6]=-(Power(h3[3],2)/d[3]) + JA3[3][6];

T123[4][1]=-(Power(h3[4],2)/d[3]) + JA3[4][1];
T123[4][2]=-((h3[4]*h3[5])/d[3]) + JA3[4][2];
T123[4][3]=-((h3[4]*h3[6])/d[3]) + JA3[4][3];
T123[4][4]=-((h3[1]*h3[4])/d[3]) + JA3[4][4];
T123[4][5]=-((h3[2]*h3[4])/d[3]) + JA3[4][5];
T123[4][6]=-((h3[3]*h3[4])/d[3]) + JA3[4][6];

T123[5][1]=-((h3[4]*h3[5])/d[3]) + JA3[5][1];
T123[5][2]=-(Power(h3[5],2)/d[3]) + JA3[5][2];
T123[5][3]=-((h3[5]*h3[6])/d[3]) + JA3[5][3];
T123[5][4]=-((h3[1]*h3[5])/d[3]) + JA3[5][4];
T123[5][5]=-((h3[2]*h3[5])/d[3]) + JA3[5][5];
T123[5][6]=-((h3[3]*h3[5])/d[3]) + JA3[5][6];

T123[6][1]=-((h3[4]*h3[6])/d[3]) + JA3[6][1];
T123[6][2]=-((h3[5]*h3[6])/d[3]) + JA3[6][2];
T123[6][3]=-(Power(h3[6],2)/d[3]) + JA3[6][3];
T123[6][4]=-((h3[1]*h3[6])/d[3]) + JA3[6][4];
T123[6][5]=-((h3[2]*h3[6])/d[3]) + JA3[6][5];
T123[6][6]=-((h3[3]*h3[6])/d[3]) + JA3[6][6];


T23[1][1]=T123[3][3] - l1*S32[1][3]*T123[3][4] - l1*S32[2][3]*T123[3][5];
T23[1][2]=S32[1][2]*T123[3][1] + S32[2][2]*T123[3][2];
T23[1][3]=S32[1][3]*T123[3][1] + S32[2][3]*T123[3][2] + l1*T123[3][6];
T23[1][4]=T123[3][6];
T23[1][5]=S32[1][2]*T123[3][4] + S32[2][2]*T123[3][5];
T23[1][6]=S32[1][3]*T123[3][4] + S32[2][3]*T123[3][5];

T23[2][1]=Si23[2][1]*T123[1][3] + Si23[2][2]*T123[2][3] - l1*S32[1][3]*(Si23[2][1]*T123[1][4] + Si23[2][2]*T123[2][4]) - l1*S32[2][3]*(Si23[2][1]*T123[1][5] + Si23[2][2]*T123[2][5]);
T23[2][2]=S32[1][2]*(Si23[2][1]*T123[1][1] + Si23[2][2]*T123[2][1]) + S32[2][2]*(Si23[2][1]*T123[1][2] + Si23[2][2]*T123[2][2]);
T23[2][3]=S32[1][3]*(Si23[2][1]*T123[1][1] + Si23[2][2]*T123[2][1]) + S32[2][3]*(Si23[2][1]*T123[1][2] + Si23[2][2]*T123[2][2]) + l1*(Si23[2][1]*T123[1][6] + Si23[2][2]*T123[2][6]);
T23[2][4]=Si23[2][1]*T123[1][6] + Si23[2][2]*T123[2][6];
T23[2][5]=S32[1][2]*(Si23[2][1]*T123[1][4] + Si23[2][2]*T123[2][4]) + S32[2][2]*(Si23[2][1]*T123[1][5] + Si23[2][2]*T123[2][5]);
T23[2][6]=S32[1][3]*(Si23[2][1]*T123[1][4] + Si23[2][2]*T123[2][4]) + S32[2][3]*(Si23[2][1]*T123[1][5] + Si23[2][2]*T123[2][5]);

T23[3][1]=Si23[3][1]*T123[1][3] + Si23[3][2]*T123[2][3] - l1*S32[1][3]*(Si23[3][1]*T123[1][4] + Si23[3][2]*T123[2][4]) - l1*S32[2][3]*(Si23[3][1]*T123[1][5] + Si23[3][2]*T123[2][5]);
T23[3][2]=S32[1][2]*(Si23[3][1]*T123[1][1] + Si23[3][2]*T123[2][1]) + S32[2][2]*(Si23[3][1]*T123[1][2] + Si23[3][2]*T123[2][2]);
T23[3][3]=S32[1][3]*(Si23[3][1]*T123[1][1] + Si23[3][2]*T123[2][1]) + S32[2][3]*(Si23[3][1]*T123[1][2] + Si23[3][2]*T123[2][2]) + l1*(Si23[3][1]*T123[1][6] + Si23[3][2]*T123[2][6]);
T23[3][4]=Si23[3][1]*T123[1][6] + Si23[3][2]*T123[2][6];
T23[3][5]=S32[1][2]*(Si23[3][1]*T123[1][4] + Si23[3][2]*T123[2][4]) + S32[2][2]*(Si23[3][1]*T123[1][5] + Si23[3][2]*T123[2][5]);
T23[3][6]=S32[1][3]*(Si23[3][1]*T123[1][4] + Si23[3][2]*T123[2][4]) + S32[2][3]*(Si23[3][1]*T123[1][5] + Si23[3][2]*T123[2][5]);

T23[4][1]=-(l1*Si23[3][1]*T123[1][3]) - l1*Si23[3][2]*T123[2][3] + T123[6][3] - l1*S32[1][3]*(-(l1*Si23[3][1]*T123[1][4]) - l1*Si23[3][2]*T123[2][4] + T123[6][4]) - l1*S32[2][3]*(-(l1*Si23[3][1]*T123[1][5]) - l1*Si23[3][2]*T123[2][5] + T123[6][5]);
T23[4][2]=S32[1][2]*(-(l1*Si23[3][1]*T123[1][1]) - l1*Si23[3][2]*T123[2][1] + T123[6][1]) + S32[2][2]*(-(l1*Si23[3][1]*T123[1][2]) - l1*Si23[3][2]*T123[2][2] + T123[6][2]);
T23[4][3]=S32[1][3]*(-(l1*Si23[3][1]*T123[1][1]) - l1*Si23[3][2]*T123[2][1] + T123[6][1]) + S32[2][3]*(-(l1*Si23[3][1]*T123[1][2]) - l1*Si23[3][2]*T123[2][2] + T123[6][2]) + l1*(-(l1*Si23[3][1]*T123[1][6]) - l1*Si23[3][2]*T123[2][6] + T123[6][6]);
T23[4][4]=-(l1*Si23[3][1]*T123[1][6]) - l1*Si23[3][2]*T123[2][6] + T123[6][6];
T23[4][5]=S32[1][2]*(-(l1*Si23[3][1]*T123[1][4]) - l1*Si23[3][2]*T123[2][4] + T123[6][4]) + S32[2][2]*(-(l1*Si23[3][1]*T123[1][5]) - l1*Si23[3][2]*T123[2][5] + T123[6][5]);
T23[4][6]=S32[1][3]*(-(l1*Si23[3][1]*T123[1][4]) - l1*Si23[3][2]*T123[2][4] + T123[6][4]) + S32[2][3]*(-(l1*Si23[3][1]*T123[1][5]) - l1*Si23[3][2]*T123[2][5] + T123[6][5]);

T23[5][1]=Si23[2][1]*T123[4][3] + Si23[2][2]*T123[5][3] - l1*S32[1][3]*(Si23[2][1]*T123[4][4] + Si23[2][2]*T123[5][4]) - l1*S32[2][3]*(Si23[2][1]*T123[4][5] + Si23[2][2]*T123[5][5]);
T23[5][2]=S32[1][2]*(Si23[2][1]*T123[4][1] + Si23[2][2]*T123[5][1]) + S32[2][2]*(Si23[2][1]*T123[4][2] + Si23[2][2]*T123[5][2]);
T23[5][3]=S32[1][3]*(Si23[2][1]*T123[4][1] + Si23[2][2]*T123[5][1]) + S32[2][3]*(Si23[2][1]*T123[4][2] + Si23[2][2]*T123[5][2]) + l1*(Si23[2][1]*T123[4][6] + Si23[2][2]*T123[5][6]);
T23[5][4]=Si23[2][1]*T123[4][6] + Si23[2][2]*T123[5][6];
T23[5][5]=S32[1][2]*(Si23[2][1]*T123[4][4] + Si23[2][2]*T123[5][4]) + S32[2][2]*(Si23[2][1]*T123[4][5] + Si23[2][2]*T123[5][5]);
T23[5][6]=S32[1][3]*(Si23[2][1]*T123[4][4] + Si23[2][2]*T123[5][4]) + S32[2][3]*(Si23[2][1]*T123[4][5] + Si23[2][2]*T123[5][5]);

T23[6][1]=l1*T123[3][3] + Si23[3][1]*T123[4][3] + Si23[3][2]*T123[5][3] - l1*S32[1][3]*(l1*T123[3][4] + Si23[3][1]*T123[4][4] + Si23[3][2]*T123[5][4]) - l1*S32[2][3]*(l1*T123[3][5] + Si23[3][1]*T123[4][5] + Si23[3][2]*T123[5][5]);
T23[6][2]=S32[1][2]*(l1*T123[3][1] + Si23[3][1]*T123[4][1] + Si23[3][2]*T123[5][1]) + S32[2][2]*(l1*T123[3][2] + Si23[3][1]*T123[4][2] + Si23[3][2]*T123[5][2]);
T23[6][3]=S32[1][3]*(l1*T123[3][1] + Si23[3][1]*T123[4][1] + Si23[3][2]*T123[5][1]) + S32[2][3]*(l1*T123[3][2] + Si23[3][1]*T123[4][2] + Si23[3][2]*T123[5][2]) + l1*(l1*T123[3][6] + Si23[3][1]*T123[4][6] + Si23[3][2]*T123[5][6]);
T23[6][4]=l1*T123[3][6] + Si23[3][1]*T123[4][6] + Si23[3][2]*T123[5][6];
T23[6][5]=S32[1][2]*(l1*T123[3][4] + Si23[3][1]*T123[4][4] + Si23[3][2]*T123[5][4]) + S32[2][2]*(l1*T123[3][5] + Si23[3][1]*T123[4][5] + Si23[3][2]*T123[5][5]);
T23[6][6]=S32[1][3]*(l1*T123[3][4] + Si23[3][1]*T123[4][4] + Si23[3][2]*T123[5][4]) + S32[2][3]*(l1*T123[3][5] + Si23[3][1]*T123[4][5] + Si23[3][2]*T123[5][5]);



}


void
master_ForDynArtfunc18(void)
      {
JA2[1][1]=T23[1][1];
JA2[1][2]=links[2].mcm[3] + T23[1][2];
JA2[1][3]=-links[2].mcm[2] + T23[1][3];
JA2[1][4]=links[2].m + T23[1][4];
JA2[1][5]=T23[1][5];
JA2[1][6]=T23[1][6];

JA2[2][1]=-links[2].mcm[3] + T23[2][1];
JA2[2][2]=T23[2][2];
JA2[2][3]=links[2].mcm[1] + T23[2][3];
JA2[2][4]=T23[2][4];
JA2[2][5]=links[2].m + T23[2][5];
JA2[2][6]=T23[2][6];

JA2[3][1]=links[2].mcm[2] + T23[3][1];
JA2[3][2]=-links[2].mcm[1] + T23[3][2];
JA2[3][3]=T23[3][3];
JA2[3][4]=T23[3][4];
JA2[3][5]=T23[3][5];
JA2[3][6]=links[2].m + T23[3][6];

JA2[4][1]=links[2].inertia[1][1] + T23[4][1];
JA2[4][2]=links[2].inertia[1][2] + T23[4][2];
JA2[4][3]=links[2].inertia[1][3] + T23[4][3];
JA2[4][4]=T23[4][4];
JA2[4][5]=-links[2].mcm[3] + T23[4][5];
JA2[4][6]=links[2].mcm[2] + T23[4][6];

JA2[5][1]=links[2].inertia[1][2] + T23[5][1];
JA2[5][2]=links[2].inertia[2][2] + T23[5][2];
JA2[5][3]=links[2].inertia[2][3] + T23[5][3];
JA2[5][4]=links[2].mcm[3] + T23[5][4];
JA2[5][5]=T23[5][5];
JA2[5][6]=-links[2].mcm[1] + T23[5][6];

JA2[6][1]=links[2].inertia[1][3] + T23[6][1];
JA2[6][2]=links[2].inertia[2][3] + T23[6][2];
JA2[6][3]=links[2].inertia[3][3] + T23[6][3];
JA2[6][4]=-links[2].mcm[2] + T23[6][4];
JA2[6][5]=links[2].mcm[1] + T23[6][5];
JA2[6][6]=T23[6][6];


h2[1]=JA2[1][3];
h2[2]=JA2[2][3];
h2[3]=JA2[3][3];
h2[4]=JA2[4][3];
h2[5]=JA2[5][3];
h2[6]=JA2[6][3];

d[2]=1.e-10 + h2[6];

T112[1][1]=-((h2[1]*h2[4])/d[2]) + JA2[1][1];
T112[1][2]=-((h2[1]*h2[5])/d[2]) + JA2[1][2];
T112[1][3]=-((h2[1]*h2[6])/d[2]) + JA2[1][3];
T112[1][4]=-(Power(h2[1],2)/d[2]) + JA2[1][4];
T112[1][5]=-((h2[1]*h2[2])/d[2]) + JA2[1][5];
T112[1][6]=-((h2[1]*h2[3])/d[2]) + JA2[1][6];

T112[2][1]=-((h2[2]*h2[4])/d[2]) + JA2[2][1];
T112[2][2]=-((h2[2]*h2[5])/d[2]) + JA2[2][2];
T112[2][3]=-((h2[2]*h2[6])/d[2]) + JA2[2][3];
T112[2][4]=-((h2[1]*h2[2])/d[2]) + JA2[2][4];
T112[2][5]=-(Power(h2[2],2)/d[2]) + JA2[2][5];
T112[2][6]=-((h2[2]*h2[3])/d[2]) + JA2[2][6];

T112[3][1]=-((h2[3]*h2[4])/d[2]) + JA2[3][1];
T112[3][2]=-((h2[3]*h2[5])/d[2]) + JA2[3][2];
T112[3][3]=-((h2[3]*h2[6])/d[2]) + JA2[3][3];
T112[3][4]=-((h2[1]*h2[3])/d[2]) + JA2[3][4];
T112[3][5]=-((h2[2]*h2[3])/d[2]) + JA2[3][5];
T112[3][6]=-(Power(h2[3],2)/d[2]) + JA2[3][6];

T112[4][1]=-(Power(h2[4],2)/d[2]) + JA2[4][1];
T112[4][2]=-((h2[4]*h2[5])/d[2]) + JA2[4][2];
T112[4][3]=-((h2[4]*h2[6])/d[2]) + JA2[4][3];
T112[4][4]=-((h2[1]*h2[4])/d[2]) + JA2[4][4];
T112[4][5]=-((h2[2]*h2[4])/d[2]) + JA2[4][5];
T112[4][6]=-((h2[3]*h2[4])/d[2]) + JA2[4][6];

T112[5][1]=-((h2[4]*h2[5])/d[2]) + JA2[5][1];
T112[5][2]=-(Power(h2[5],2)/d[2]) + JA2[5][2];
T112[5][3]=-((h2[5]*h2[6])/d[2]) + JA2[5][3];
T112[5][4]=-((h2[1]*h2[5])/d[2]) + JA2[5][4];
T112[5][5]=-((h2[2]*h2[5])/d[2]) + JA2[5][5];
T112[5][6]=-((h2[3]*h2[5])/d[2]) + JA2[5][6];

T112[6][1]=-((h2[4]*h2[6])/d[2]) + JA2[6][1];
T112[6][2]=-((h2[5]*h2[6])/d[2]) + JA2[6][2];
T112[6][3]=-(Power(h2[6],2)/d[2]) + JA2[6][3];
T112[6][4]=-((h2[1]*h2[6])/d[2]) + JA2[6][4];
T112[6][5]=-((h2[2]*h2[6])/d[2]) + JA2[6][5];
T112[6][6]=-((h2[3]*h2[6])/d[2]) + JA2[6][6];


T12[1][1]=S21[1][1]*(Si12[1][1]*T112[1][1] + Si12[1][2]*T112[2][1]) + S21[2][1]*(Si12[1][1]*T112[1][2] + Si12[1][2]*T112[2][2]);
T12[1][2]=Si12[1][1]*T112[1][3] + Si12[1][2]*T112[2][3];
T12[1][3]=S21[1][3]*(Si12[1][1]*T112[1][1] + Si12[1][2]*T112[2][1]) + S21[2][3]*(Si12[1][1]*T112[1][2] + Si12[1][2]*T112[2][2]);
T12[1][4]=S21[1][1]*(Si12[1][1]*T112[1][4] + Si12[1][2]*T112[2][4]) + S21[2][1]*(Si12[1][1]*T112[1][5] + Si12[1][2]*T112[2][5]);
T12[1][5]=Si12[1][1]*T112[1][6] + Si12[1][2]*T112[2][6];
T12[1][6]=S21[1][3]*(Si12[1][1]*T112[1][4] + Si12[1][2]*T112[2][4]) + S21[2][3]*(Si12[1][1]*T112[1][5] + Si12[1][2]*T112[2][5]);

T12[2][1]=S21[1][1]*T112[3][1] + S21[2][1]*T112[3][2];
T12[2][2]=T112[3][3];
T12[2][3]=S21[1][3]*T112[3][1] + S21[2][3]*T112[3][2];
T12[2][4]=S21[1][1]*T112[3][4] + S21[2][1]*T112[3][5];
T12[2][5]=T112[3][6];
T12[2][6]=S21[1][3]*T112[3][4] + S21[2][3]*T112[3][5];

T12[3][1]=S21[1][1]*(Si12[3][1]*T112[1][1] + Si12[3][2]*T112[2][1]) + S21[2][1]*(Si12[3][1]*T112[1][2] + Si12[3][2]*T112[2][2]);
T12[3][2]=Si12[3][1]*T112[1][3] + Si12[3][2]*T112[2][3];
T12[3][3]=S21[1][3]*(Si12[3][1]*T112[1][1] + Si12[3][2]*T112[2][1]) + S21[2][3]*(Si12[3][1]*T112[1][2] + Si12[3][2]*T112[2][2]);
T12[3][4]=S21[1][1]*(Si12[3][1]*T112[1][4] + Si12[3][2]*T112[2][4]) + S21[2][1]*(Si12[3][1]*T112[1][5] + Si12[3][2]*T112[2][5]);
T12[3][5]=Si12[3][1]*T112[1][6] + Si12[3][2]*T112[2][6];
T12[3][6]=S21[1][3]*(Si12[3][1]*T112[1][4] + Si12[3][2]*T112[2][4]) + S21[2][3]*(Si12[3][1]*T112[1][5] + Si12[3][2]*T112[2][5]);

T12[4][1]=S21[1][1]*(Si12[1][1]*T112[4][1] + Si12[1][2]*T112[5][1]) + S21[2][1]*(Si12[1][1]*T112[4][2] + Si12[1][2]*T112[5][2]);
T12[4][2]=Si12[1][1]*T112[4][3] + Si12[1][2]*T112[5][3];
T12[4][3]=S21[1][3]*(Si12[1][1]*T112[4][1] + Si12[1][2]*T112[5][1]) + S21[2][3]*(Si12[1][1]*T112[4][2] + Si12[1][2]*T112[5][2]);
T12[4][4]=S21[1][1]*(Si12[1][1]*T112[4][4] + Si12[1][2]*T112[5][4]) + S21[2][1]*(Si12[1][1]*T112[4][5] + Si12[1][2]*T112[5][5]);
T12[4][5]=Si12[1][1]*T112[4][6] + Si12[1][2]*T112[5][6];
T12[4][6]=S21[1][3]*(Si12[1][1]*T112[4][4] + Si12[1][2]*T112[5][4]) + S21[2][3]*(Si12[1][1]*T112[4][5] + Si12[1][2]*T112[5][5]);

T12[5][1]=S21[1][1]*T112[6][1] + S21[2][1]*T112[6][2];
T12[5][2]=T112[6][3];
T12[5][3]=S21[1][3]*T112[6][1] + S21[2][3]*T112[6][2];
T12[5][4]=S21[1][1]*T112[6][4] + S21[2][1]*T112[6][5];
T12[5][5]=T112[6][6];
T12[5][6]=S21[1][3]*T112[6][4] + S21[2][3]*T112[6][5];

T12[6][1]=S21[1][1]*(Si12[3][1]*T112[4][1] + Si12[3][2]*T112[5][1]) + S21[2][1]*(Si12[3][1]*T112[4][2] + Si12[3][2]*T112[5][2]);
T12[6][2]=Si12[3][1]*T112[4][3] + Si12[3][2]*T112[5][3];
T12[6][3]=S21[1][3]*(Si12[3][1]*T112[4][1] + Si12[3][2]*T112[5][1]) + S21[2][3]*(Si12[3][1]*T112[4][2] + Si12[3][2]*T112[5][2]);
T12[6][4]=S21[1][1]*(Si12[3][1]*T112[4][4] + Si12[3][2]*T112[5][4]) + S21[2][1]*(Si12[3][1]*T112[4][5] + Si12[3][2]*T112[5][5]);
T12[6][5]=Si12[3][1]*T112[4][6] + Si12[3][2]*T112[5][6];
T12[6][6]=S21[1][3]*(Si12[3][1]*T112[4][4] + Si12[3][2]*T112[5][4]) + S21[2][3]*(Si12[3][1]*T112[4][5] + Si12[3][2]*T112[5][5]);



}


void
master_ForDynArtfunc19(void)
      {
JA1[1][1]=T12[1][1];
JA1[1][2]=links[1].mcm[3] + T12[1][2];
JA1[1][3]=-links[1].mcm[2] + T12[1][3];
JA1[1][4]=links[1].m + T12[1][4];
JA1[1][5]=T12[1][5];
JA1[1][6]=T12[1][6];

JA1[2][1]=-links[1].mcm[3] + T12[2][1];
JA1[2][2]=T12[2][2];
JA1[2][3]=links[1].mcm[1] + T12[2][3];
JA1[2][4]=T12[2][4];
JA1[2][5]=links[1].m + T12[2][5];
JA1[2][6]=T12[2][6];

JA1[3][1]=links[1].mcm[2] + T12[3][1];
JA1[3][2]=-links[1].mcm[1] + T12[3][2];
JA1[3][3]=T12[3][3];
JA1[3][4]=T12[3][4];
JA1[3][5]=T12[3][5];
JA1[3][6]=links[1].m + T12[3][6];

JA1[4][1]=links[1].inertia[1][1] + T12[4][1];
JA1[4][2]=links[1].inertia[1][2] + T12[4][2];
JA1[4][3]=links[1].inertia[1][3] + T12[4][3];
JA1[4][4]=T12[4][4];
JA1[4][5]=-links[1].mcm[3] + T12[4][5];
JA1[4][6]=links[1].mcm[2] + T12[4][6];

JA1[5][1]=links[1].inertia[1][2] + T12[5][1];
JA1[5][2]=links[1].inertia[2][2] + T12[5][2];
JA1[5][3]=links[1].inertia[2][3] + T12[5][3];
JA1[5][4]=links[1].mcm[3] + T12[5][4];
JA1[5][5]=T12[5][5];
JA1[5][6]=-links[1].mcm[1] + T12[5][6];

JA1[6][1]=links[1].inertia[1][3] + T12[6][1];
JA1[6][2]=links[1].inertia[2][3] + T12[6][2];
JA1[6][3]=links[1].inertia[3][3] + T12[6][3];
JA1[6][4]=-links[1].mcm[2] + T12[6][4];
JA1[6][5]=links[1].mcm[1] + T12[6][5];
JA1[6][6]=T12[6][6];


h1[1]=JA1[1][3];
h1[2]=JA1[2][3];
h1[3]=JA1[3][3];
h1[4]=JA1[4][3];
h1[5]=JA1[5][3];
h1[6]=JA1[6][3];

d[1]=1.e-10 + h1[6];

T101[1][1]=-((h1[1]*h1[4])/d[1]) + JA1[1][1];
T101[1][2]=-((h1[1]*h1[5])/d[1]) + JA1[1][2];
T101[1][3]=-((h1[1]*h1[6])/d[1]) + JA1[1][3];
T101[1][4]=-(Power(h1[1],2)/d[1]) + JA1[1][4];
T101[1][5]=-((h1[1]*h1[2])/d[1]) + JA1[1][5];
T101[1][6]=-((h1[1]*h1[3])/d[1]) + JA1[1][6];

T101[2][1]=-((h1[2]*h1[4])/d[1]) + JA1[2][1];
T101[2][2]=-((h1[2]*h1[5])/d[1]) + JA1[2][2];
T101[2][3]=-((h1[2]*h1[6])/d[1]) + JA1[2][3];
T101[2][4]=-((h1[1]*h1[2])/d[1]) + JA1[2][4];
T101[2][5]=-(Power(h1[2],2)/d[1]) + JA1[2][5];
T101[2][6]=-((h1[2]*h1[3])/d[1]) + JA1[2][6];

T101[3][1]=-((h1[3]*h1[4])/d[1]) + JA1[3][1];
T101[3][2]=-((h1[3]*h1[5])/d[1]) + JA1[3][2];
T101[3][3]=-((h1[3]*h1[6])/d[1]) + JA1[3][3];
T101[3][4]=-((h1[1]*h1[3])/d[1]) + JA1[3][4];
T101[3][5]=-((h1[2]*h1[3])/d[1]) + JA1[3][5];
T101[3][6]=-(Power(h1[3],2)/d[1]) + JA1[3][6];

T101[4][1]=-(Power(h1[4],2)/d[1]) + JA1[4][1];
T101[4][2]=-((h1[4]*h1[5])/d[1]) + JA1[4][2];
T101[4][3]=-((h1[4]*h1[6])/d[1]) + JA1[4][3];
T101[4][4]=-((h1[1]*h1[4])/d[1]) + JA1[4][4];
T101[4][5]=-((h1[2]*h1[4])/d[1]) + JA1[4][5];
T101[4][6]=-((h1[3]*h1[4])/d[1]) + JA1[4][6];

T101[5][1]=-((h1[4]*h1[5])/d[1]) + JA1[5][1];
T101[5][2]=-(Power(h1[5],2)/d[1]) + JA1[5][2];
T101[5][3]=-((h1[5]*h1[6])/d[1]) + JA1[5][3];
T101[5][4]=-((h1[1]*h1[5])/d[1]) + JA1[5][4];
T101[5][5]=-((h1[2]*h1[5])/d[1]) + JA1[5][5];
T101[5][6]=-((h1[3]*h1[5])/d[1]) + JA1[5][6];

T101[6][1]=-((h1[4]*h1[6])/d[1]) + JA1[6][1];
T101[6][2]=-((h1[5]*h1[6])/d[1]) + JA1[6][2];
T101[6][3]=-(Power(h1[6],2)/d[1]) + JA1[6][3];
T101[6][4]=-((h1[1]*h1[6])/d[1]) + JA1[6][4];
T101[6][5]=-((h1[2]*h1[6])/d[1]) + JA1[6][5];
T101[6][6]=-((h1[3]*h1[6])/d[1]) + JA1[6][6];


T01[1][1]=S10[1][1]*(Si01[1][1]*T101[1][1] + Si01[1][2]*T101[2][1] + 0.7071067811865475*T101[3][1]) + S10[2][1]*(Si01[1][1]*T101[1][2] + Si01[1][2]*T101[2][2] + 0.7071067811865475*T101[3][2]) + 0.7071067811865475*(Si01[1][1]*T101[1][3] + Si01[1][2]*T101[2][3] + 0.7071067811865475*T101[3][3]) - (l0*S10[1][2]*(Si01[1][1]*T101[1][4] + Si01[1][2]*T101[2][4] + 0.7071067811865475*T101[3][4]))/Sqrt(2) - (l0*S10[2][2]*(Si01[1][1]*T101[1][5] + Si01[1][2]*T101[2][5] + 0.7071067811865475*T101[3][5]))/Sqrt(2);
T01[1][2]=S10[1][2]*(Si01[1][1]*T101[1][1] + Si01[1][2]*T101[2][1] + 0.7071067811865475*T101[3][1]) + S10[2][2]*(Si01[1][1]*T101[1][2] + Si01[1][2]*T101[2][2] + 0.7071067811865475*T101[3][2]) + ((l0*S10[1][1])/Sqrt(2) - (l0*S10[1][3])/Sqrt(2))*(Si01[1][1]*T101[1][4] + Si01[1][2]*T101[2][4] + 0.7071067811865475*T101[3][4]) + ((l0*S10[2][1])/Sqrt(2) - (l0*S10[2][3])/Sqrt(2))*(Si01[1][1]*T101[1][5] + Si01[1][2]*T101[2][5] + 0.7071067811865475*T101[3][5]);
T01[1][3]=S10[1][3]*(Si01[1][1]*T101[1][1] + Si01[1][2]*T101[2][1] + 0.7071067811865475*T101[3][1]) + S10[2][3]*(Si01[1][1]*T101[1][2] + Si01[1][2]*T101[2][2] + 0.7071067811865475*T101[3][2]) + 0.7071067811865475*(Si01[1][1]*T101[1][3] + Si01[1][2]*T101[2][3] + 0.7071067811865475*T101[3][3]) + (l0*S10[1][2]*(Si01[1][1]*T101[1][4] + Si01[1][2]*T101[2][4] + 0.7071067811865475*T101[3][4]))/Sqrt(2) + (l0*S10[2][2]*(Si01[1][1]*T101[1][5] + Si01[1][2]*T101[2][5] + 0.7071067811865475*T101[3][5]))/Sqrt(2);
T01[1][4]=S10[1][1]*(Si01[1][1]*T101[1][4] + Si01[1][2]*T101[2][4] + 0.7071067811865475*T101[3][4]) + S10[2][1]*(Si01[1][1]*T101[1][5] + Si01[1][2]*T101[2][5] + 0.7071067811865475*T101[3][5]) + 0.7071067811865475*(Si01[1][1]*T101[1][6] + Si01[1][2]*T101[2][6] + 0.7071067811865475*T101[3][6]);
T01[1][5]=S10[1][2]*(Si01[1][1]*T101[1][4] + Si01[1][2]*T101[2][4] + 0.7071067811865475*T101[3][4]) + S10[2][2]*(Si01[1][1]*T101[1][5] + Si01[1][2]*T101[2][5] + 0.7071067811865475*T101[3][5]);
T01[1][6]=S10[1][3]*(Si01[1][1]*T101[1][4] + Si01[1][2]*T101[2][4] + 0.7071067811865475*T101[3][4]) + S10[2][3]*(Si01[1][1]*T101[1][5] + Si01[1][2]*T101[2][5] + 0.7071067811865475*T101[3][5]) + 0.7071067811865475*(Si01[1][1]*T101[1][6] + Si01[1][2]*T101[2][6] + 0.7071067811865475*T101[3][6]);

T01[2][1]=S10[1][1]*(Si01[2][1]*T101[1][1] + Si01[2][2]*T101[2][1]) + S10[2][1]*(Si01[2][1]*T101[1][2] + Si01[2][2]*T101[2][2]) + 0.7071067811865475*(Si01[2][1]*T101[1][3] + Si01[2][2]*T101[2][3]) - (l0*S10[1][2]*(Si01[2][1]*T101[1][4] + Si01[2][2]*T101[2][4]))/Sqrt(2) - (l0*S10[2][2]*(Si01[2][1]*T101[1][5] + Si01[2][2]*T101[2][5]))/Sqrt(2);
T01[2][2]=S10[1][2]*(Si01[2][1]*T101[1][1] + Si01[2][2]*T101[2][1]) + S10[2][2]*(Si01[2][1]*T101[1][2] + Si01[2][2]*T101[2][2]) + ((l0*S10[1][1])/Sqrt(2) - (l0*S10[1][3])/Sqrt(2))*(Si01[2][1]*T101[1][4] + Si01[2][2]*T101[2][4]) + ((l0*S10[2][1])/Sqrt(2) - (l0*S10[2][3])/Sqrt(2))*(Si01[2][1]*T101[1][5] + Si01[2][2]*T101[2][5]);
T01[2][3]=S10[1][3]*(Si01[2][1]*T101[1][1] + Si01[2][2]*T101[2][1]) + S10[2][3]*(Si01[2][1]*T101[1][2] + Si01[2][2]*T101[2][2]) + 0.7071067811865475*(Si01[2][1]*T101[1][3] + Si01[2][2]*T101[2][3]) + (l0*S10[1][2]*(Si01[2][1]*T101[1][4] + Si01[2][2]*T101[2][4]))/Sqrt(2) + (l0*S10[2][2]*(Si01[2][1]*T101[1][5] + Si01[2][2]*T101[2][5]))/Sqrt(2);
T01[2][4]=S10[1][1]*(Si01[2][1]*T101[1][4] + Si01[2][2]*T101[2][4]) + S10[2][1]*(Si01[2][1]*T101[1][5] + Si01[2][2]*T101[2][5]) + 0.7071067811865475*(Si01[2][1]*T101[1][6] + Si01[2][2]*T101[2][6]);
T01[2][5]=S10[1][2]*(Si01[2][1]*T101[1][4] + Si01[2][2]*T101[2][4]) + S10[2][2]*(Si01[2][1]*T101[1][5] + Si01[2][2]*T101[2][5]);
T01[2][6]=S10[1][3]*(Si01[2][1]*T101[1][4] + Si01[2][2]*T101[2][4]) + S10[2][3]*(Si01[2][1]*T101[1][5] + Si01[2][2]*T101[2][5]) + 0.7071067811865475*(Si01[2][1]*T101[1][6] + Si01[2][2]*T101[2][6]);

T01[3][1]=S10[1][1]*(Si01[3][1]*T101[1][1] + Si01[3][2]*T101[2][1] + 0.7071067811865475*T101[3][1]) + S10[2][1]*(Si01[3][1]*T101[1][2] + Si01[3][2]*T101[2][2] + 0.7071067811865475*T101[3][2]) + 0.7071067811865475*(Si01[3][1]*T101[1][3] + Si01[3][2]*T101[2][3] + 0.7071067811865475*T101[3][3]) - (l0*S10[1][2]*(Si01[3][1]*T101[1][4] + Si01[3][2]*T101[2][4] + 0.7071067811865475*T101[3][4]))/Sqrt(2) - (l0*S10[2][2]*(Si01[3][1]*T101[1][5] + Si01[3][2]*T101[2][5] + 0.7071067811865475*T101[3][5]))/Sqrt(2);
T01[3][2]=S10[1][2]*(Si01[3][1]*T101[1][1] + Si01[3][2]*T101[2][1] + 0.7071067811865475*T101[3][1]) + S10[2][2]*(Si01[3][1]*T101[1][2] + Si01[3][2]*T101[2][2] + 0.7071067811865475*T101[3][2]) + ((l0*S10[1][1])/Sqrt(2) - (l0*S10[1][3])/Sqrt(2))*(Si01[3][1]*T101[1][4] + Si01[3][2]*T101[2][4] + 0.7071067811865475*T101[3][4]) + ((l0*S10[2][1])/Sqrt(2) - (l0*S10[2][3])/Sqrt(2))*(Si01[3][1]*T101[1][5] + Si01[3][2]*T101[2][5] + 0.7071067811865475*T101[3][5]);
T01[3][3]=S10[1][3]*(Si01[3][1]*T101[1][1] + Si01[3][2]*T101[2][1] + 0.7071067811865475*T101[3][1]) + S10[2][3]*(Si01[3][1]*T101[1][2] + Si01[3][2]*T101[2][2] + 0.7071067811865475*T101[3][2]) + 0.7071067811865475*(Si01[3][1]*T101[1][3] + Si01[3][2]*T101[2][3] + 0.7071067811865475*T101[3][3]) + (l0*S10[1][2]*(Si01[3][1]*T101[1][4] + Si01[3][2]*T101[2][4] + 0.7071067811865475*T101[3][4]))/Sqrt(2) + (l0*S10[2][2]*(Si01[3][1]*T101[1][5] + Si01[3][2]*T101[2][5] + 0.7071067811865475*T101[3][5]))/Sqrt(2);
T01[3][4]=S10[1][1]*(Si01[3][1]*T101[1][4] + Si01[3][2]*T101[2][4] + 0.7071067811865475*T101[3][4]) + S10[2][1]*(Si01[3][1]*T101[1][5] + Si01[3][2]*T101[2][5] + 0.7071067811865475*T101[3][5]) + 0.7071067811865475*(Si01[3][1]*T101[1][6] + Si01[3][2]*T101[2][6] + 0.7071067811865475*T101[3][6]);
T01[3][5]=S10[1][2]*(Si01[3][1]*T101[1][4] + Si01[3][2]*T101[2][4] + 0.7071067811865475*T101[3][4]) + S10[2][2]*(Si01[3][1]*T101[1][5] + Si01[3][2]*T101[2][5] + 0.7071067811865475*T101[3][5]);
T01[3][6]=S10[1][3]*(Si01[3][1]*T101[1][4] + Si01[3][2]*T101[2][4] + 0.7071067811865475*T101[3][4]) + S10[2][3]*(Si01[3][1]*T101[1][5] + Si01[3][2]*T101[2][5] + 0.7071067811865475*T101[3][5]) + 0.7071067811865475*(Si01[3][1]*T101[1][6] + Si01[3][2]*T101[2][6] + 0.7071067811865475*T101[3][6]);

T01[4][1]=S10[1][1]*(-((l0*Si01[2][1]*T101[1][1])/Sqrt(2)) - (l0*Si01[2][2]*T101[2][1])/Sqrt(2) + Si01[1][1]*T101[4][1] + Si01[1][2]*T101[5][1] + 0.7071067811865475*T101[6][1]) + S10[2][1]*(-((l0*Si01[2][1]*T101[1][2])/Sqrt(2)) - (l0*Si01[2][2]*T101[2][2])/Sqrt(2) + Si01[1][1]*T101[4][2] + Si01[1][2]*T101[5][2] + 0.7071067811865475*T101[6][2]) + 0.7071067811865475*(-((l0*Si01[2][1]*T101[1][3])/Sqrt(2)) - (l0*Si01[2][2]*T101[2][3])/Sqrt(2) + Si01[1][1]*T101[4][3] + Si01[1][2]*T101[5][3] + 0.7071067811865475*T101[6][3]) - (l0*S10[1][2]*(-((l0*Si01[2][1]*T101[1][4])/Sqrt(2)) - (l0*Si01[2][2]*T101[2][4])/Sqrt(2) + Si01[1][1]*T101[4][4] + Si01[1][2]*T101[5][4] + 0.7071067811865475*T101[6][4]))/Sqrt(2) - (l0*S10[2][2]*(-((l0*Si01[2][1]*T101[1][5])/Sqrt(2)) - (l0*Si01[2][2]*T101[2][5])/Sqrt(2) + Si01[1][1]*T101[4][5] + Si01[1][2]*T101[5][5] + 0.7071067811865475*T101[6][5]))/Sqrt(2);
T01[4][2]=S10[1][2]*(-((l0*Si01[2][1]*T101[1][1])/Sqrt(2)) - (l0*Si01[2][2]*T101[2][1])/Sqrt(2) + Si01[1][1]*T101[4][1] + Si01[1][2]*T101[5][1] + 0.7071067811865475*T101[6][1]) + S10[2][2]*(-((l0*Si01[2][1]*T101[1][2])/Sqrt(2)) - (l0*Si01[2][2]*T101[2][2])/Sqrt(2) + Si01[1][1]*T101[4][2] + Si01[1][2]*T101[5][2] + 0.7071067811865475*T101[6][2]) + ((l0*S10[1][1])/Sqrt(2) - (l0*S10[1][3])/Sqrt(2))*(-((l0*Si01[2][1]*T101[1][4])/Sqrt(2)) - (l0*Si01[2][2]*T101[2][4])/Sqrt(2) + Si01[1][1]*T101[4][4] + Si01[1][2]*T101[5][4] + 0.7071067811865475*T101[6][4]) + ((l0*S10[2][1])/Sqrt(2) - (l0*S10[2][3])/Sqrt(2))*(-((l0*Si01[2][1]*T101[1][5])/Sqrt(2)) - (l0*Si01[2][2]*T101[2][5])/Sqrt(2) + Si01[1][1]*T101[4][5] + Si01[1][2]*T101[5][5] + 0.7071067811865475*T101[6][5]);
T01[4][3]=S10[1][3]*(-((l0*Si01[2][1]*T101[1][1])/Sqrt(2)) - (l0*Si01[2][2]*T101[2][1])/Sqrt(2) + Si01[1][1]*T101[4][1] + Si01[1][2]*T101[5][1] + 0.7071067811865475*T101[6][1]) + S10[2][3]*(-((l0*Si01[2][1]*T101[1][2])/Sqrt(2)) - (l0*Si01[2][2]*T101[2][2])/Sqrt(2) + Si01[1][1]*T101[4][2] + Si01[1][2]*T101[5][2] + 0.7071067811865475*T101[6][2]) + 0.7071067811865475*(-((l0*Si01[2][1]*T101[1][3])/Sqrt(2)) - (l0*Si01[2][2]*T101[2][3])/Sqrt(2) + Si01[1][1]*T101[4][3] + Si01[1][2]*T101[5][3] + 0.7071067811865475*T101[6][3]) + (l0*S10[1][2]*(-((l0*Si01[2][1]*T101[1][4])/Sqrt(2)) - (l0*Si01[2][2]*T101[2][4])/Sqrt(2) + Si01[1][1]*T101[4][4] + Si01[1][2]*T101[5][4] + 0.7071067811865475*T101[6][4]))/Sqrt(2) + (l0*S10[2][2]*(-((l0*Si01[2][1]*T101[1][5])/Sqrt(2)) - (l0*Si01[2][2]*T101[2][5])/Sqrt(2) + Si01[1][1]*T101[4][5] + Si01[1][2]*T101[5][5] + 0.7071067811865475*T101[6][5]))/Sqrt(2);
T01[4][4]=S10[1][1]*(-((l0*Si01[2][1]*T101[1][4])/Sqrt(2)) - (l0*Si01[2][2]*T101[2][4])/Sqrt(2) + Si01[1][1]*T101[4][4] + Si01[1][2]*T101[5][4] + 0.7071067811865475*T101[6][4]) + S10[2][1]*(-((l0*Si01[2][1]*T101[1][5])/Sqrt(2)) - (l0*Si01[2][2]*T101[2][5])/Sqrt(2) + Si01[1][1]*T101[4][5] + Si01[1][2]*T101[5][5] + 0.7071067811865475*T101[6][5]) + 0.7071067811865475*(-((l0*Si01[2][1]*T101[1][6])/Sqrt(2)) - (l0*Si01[2][2]*T101[2][6])/Sqrt(2) + Si01[1][1]*T101[4][6] + Si01[1][2]*T101[5][6] + 0.7071067811865475*T101[6][6]);
T01[4][5]=S10[1][2]*(-((l0*Si01[2][1]*T101[1][4])/Sqrt(2)) - (l0*Si01[2][2]*T101[2][4])/Sqrt(2) + Si01[1][1]*T101[4][4] + Si01[1][2]*T101[5][4] + 0.7071067811865475*T101[6][4]) + S10[2][2]*(-((l0*Si01[2][1]*T101[1][5])/Sqrt(2)) - (l0*Si01[2][2]*T101[2][5])/Sqrt(2) + Si01[1][1]*T101[4][5] + Si01[1][2]*T101[5][5] + 0.7071067811865475*T101[6][5]);
T01[4][6]=S10[1][3]*(-((l0*Si01[2][1]*T101[1][4])/Sqrt(2)) - (l0*Si01[2][2]*T101[2][4])/Sqrt(2) + Si01[1][1]*T101[4][4] + Si01[1][2]*T101[5][4] + 0.7071067811865475*T101[6][4]) + S10[2][3]*(-((l0*Si01[2][1]*T101[1][5])/Sqrt(2)) - (l0*Si01[2][2]*T101[2][5])/Sqrt(2) + Si01[1][1]*T101[4][5] + Si01[1][2]*T101[5][5] + 0.7071067811865475*T101[6][5]) + 0.7071067811865475*(-((l0*Si01[2][1]*T101[1][6])/Sqrt(2)) - (l0*Si01[2][2]*T101[2][6])/Sqrt(2) + Si01[1][1]*T101[4][6] + Si01[1][2]*T101[5][6] + 0.7071067811865475*T101[6][6]);

T01[5][1]=S10[1][1]*(((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2))*T101[1][1] + ((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))*T101[2][1] + Si01[2][1]*T101[4][1] + Si01[2][2]*T101[5][1]) + S10[2][1]*(((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2))*T101[1][2] + ((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))*T101[2][2] + Si01[2][1]*T101[4][2] + Si01[2][2]*T101[5][2]) + 0.7071067811865475*(((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2))*T101[1][3] + ((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))*T101[2][3] + Si01[2][1]*T101[4][3] + Si01[2][2]*T101[5][3]) - (l0*S10[1][2]*(((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2))*T101[1][4] + ((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))*T101[2][4] + Si01[2][1]*T101[4][4] + Si01[2][2]*T101[5][4]))/Sqrt(2) - (l0*S10[2][2]*(((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2))*T101[1][5] + ((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))*T101[2][5] + Si01[2][1]*T101[4][5] + Si01[2][2]*T101[5][5]))/Sqrt(2);
T01[5][2]=S10[1][2]*(((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2))*T101[1][1] + ((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))*T101[2][1] + Si01[2][1]*T101[4][1] + Si01[2][2]*T101[5][1]) + S10[2][2]*(((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2))*T101[1][2] + ((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))*T101[2][2] + Si01[2][1]*T101[4][2] + Si01[2][2]*T101[5][2]) + ((l0*S10[1][1])/Sqrt(2) - (l0*S10[1][3])/Sqrt(2))*(((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2))*T101[1][4] + ((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))*T101[2][4] + Si01[2][1]*T101[4][4] + Si01[2][2]*T101[5][4]) + ((l0*S10[2][1])/Sqrt(2) - (l0*S10[2][3])/Sqrt(2))*(((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2))*T101[1][5] + ((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))*T101[2][5] + Si01[2][1]*T101[4][5] + Si01[2][2]*T101[5][5]);
T01[5][3]=S10[1][3]*(((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2))*T101[1][1] + ((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))*T101[2][1] + Si01[2][1]*T101[4][1] + Si01[2][2]*T101[5][1]) + S10[2][3]*(((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2))*T101[1][2] + ((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))*T101[2][2] + Si01[2][1]*T101[4][2] + Si01[2][2]*T101[5][2]) + 0.7071067811865475*(((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2))*T101[1][3] + ((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))*T101[2][3] + Si01[2][1]*T101[4][3] + Si01[2][2]*T101[5][3]) + (l0*S10[1][2]*(((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2))*T101[1][4] + ((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))*T101[2][4] + Si01[2][1]*T101[4][4] + Si01[2][2]*T101[5][4]))/Sqrt(2) + (l0*S10[2][2]*(((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2))*T101[1][5] + ((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))*T101[2][5] + Si01[2][1]*T101[4][5] + Si01[2][2]*T101[5][5]))/Sqrt(2);
T01[5][4]=S10[1][1]*(((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2))*T101[1][4] + ((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))*T101[2][4] + Si01[2][1]*T101[4][4] + Si01[2][2]*T101[5][4]) + S10[2][1]*(((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2))*T101[1][5] + ((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))*T101[2][5] + Si01[2][1]*T101[4][5] + Si01[2][2]*T101[5][5]) + 0.7071067811865475*(((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2))*T101[1][6] + ((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))*T101[2][6] + Si01[2][1]*T101[4][6] + Si01[2][2]*T101[5][6]);
T01[5][5]=S10[1][2]*(((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2))*T101[1][4] + ((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))*T101[2][4] + Si01[2][1]*T101[4][4] + Si01[2][2]*T101[5][4]) + S10[2][2]*(((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2))*T101[1][5] + ((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))*T101[2][5] + Si01[2][1]*T101[4][5] + Si01[2][2]*T101[5][5]);
T01[5][6]=S10[1][3]*(((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2))*T101[1][4] + ((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))*T101[2][4] + Si01[2][1]*T101[4][4] + Si01[2][2]*T101[5][4]) + S10[2][3]*(((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2))*T101[1][5] + ((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))*T101[2][5] + Si01[2][1]*T101[4][5] + Si01[2][2]*T101[5][5]) + 0.7071067811865475*(((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2))*T101[1][6] + ((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2))*T101[2][6] + Si01[2][1]*T101[4][6] + Si01[2][2]*T101[5][6]);

T01[6][1]=S10[1][1]*((l0*Si01[2][1]*T101[1][1])/Sqrt(2) + (l0*Si01[2][2]*T101[2][1])/Sqrt(2) + Si01[3][1]*T101[4][1] + Si01[3][2]*T101[5][1] + 0.7071067811865475*T101[6][1]) + S10[2][1]*((l0*Si01[2][1]*T101[1][2])/Sqrt(2) + (l0*Si01[2][2]*T101[2][2])/Sqrt(2) + Si01[3][1]*T101[4][2] + Si01[3][2]*T101[5][2] + 0.7071067811865475*T101[6][2]) + 0.7071067811865475*((l0*Si01[2][1]*T101[1][3])/Sqrt(2) + (l0*Si01[2][2]*T101[2][3])/Sqrt(2) + Si01[3][1]*T101[4][3] + Si01[3][2]*T101[5][3] + 0.7071067811865475*T101[6][3]) - (l0*S10[1][2]*((l0*Si01[2][1]*T101[1][4])/Sqrt(2) + (l0*Si01[2][2]*T101[2][4])/Sqrt(2) + Si01[3][1]*T101[4][4] + Si01[3][2]*T101[5][4] + 0.7071067811865475*T101[6][4]))/Sqrt(2) - (l0*S10[2][2]*((l0*Si01[2][1]*T101[1][5])/Sqrt(2) + (l0*Si01[2][2]*T101[2][5])/Sqrt(2) + Si01[3][1]*T101[4][5] + Si01[3][2]*T101[5][5] + 0.7071067811865475*T101[6][5]))/Sqrt(2);
T01[6][2]=S10[1][2]*((l0*Si01[2][1]*T101[1][1])/Sqrt(2) + (l0*Si01[2][2]*T101[2][1])/Sqrt(2) + Si01[3][1]*T101[4][1] + Si01[3][2]*T101[5][1] + 0.7071067811865475*T101[6][1]) + S10[2][2]*((l0*Si01[2][1]*T101[1][2])/Sqrt(2) + (l0*Si01[2][2]*T101[2][2])/Sqrt(2) + Si01[3][1]*T101[4][2] + Si01[3][2]*T101[5][2] + 0.7071067811865475*T101[6][2]) + ((l0*S10[1][1])/Sqrt(2) - (l0*S10[1][3])/Sqrt(2))*((l0*Si01[2][1]*T101[1][4])/Sqrt(2) + (l0*Si01[2][2]*T101[2][4])/Sqrt(2) + Si01[3][1]*T101[4][4] + Si01[3][2]*T101[5][4] + 0.7071067811865475*T101[6][4]) + ((l0*S10[2][1])/Sqrt(2) - (l0*S10[2][3])/Sqrt(2))*((l0*Si01[2][1]*T101[1][5])/Sqrt(2) + (l0*Si01[2][2]*T101[2][5])/Sqrt(2) + Si01[3][1]*T101[4][5] + Si01[3][2]*T101[5][5] + 0.7071067811865475*T101[6][5]);
T01[6][3]=S10[1][3]*((l0*Si01[2][1]*T101[1][1])/Sqrt(2) + (l0*Si01[2][2]*T101[2][1])/Sqrt(2) + Si01[3][1]*T101[4][1] + Si01[3][2]*T101[5][1] + 0.7071067811865475*T101[6][1]) + S10[2][3]*((l0*Si01[2][1]*T101[1][2])/Sqrt(2) + (l0*Si01[2][2]*T101[2][2])/Sqrt(2) + Si01[3][1]*T101[4][2] + Si01[3][2]*T101[5][2] + 0.7071067811865475*T101[6][2]) + 0.7071067811865475*((l0*Si01[2][1]*T101[1][3])/Sqrt(2) + (l0*Si01[2][2]*T101[2][3])/Sqrt(2) + Si01[3][1]*T101[4][3] + Si01[3][2]*T101[5][3] + 0.7071067811865475*T101[6][3]) + (l0*S10[1][2]*((l0*Si01[2][1]*T101[1][4])/Sqrt(2) + (l0*Si01[2][2]*T101[2][4])/Sqrt(2) + Si01[3][1]*T101[4][4] + Si01[3][2]*T101[5][4] + 0.7071067811865475*T101[6][4]))/Sqrt(2) + (l0*S10[2][2]*((l0*Si01[2][1]*T101[1][5])/Sqrt(2) + (l0*Si01[2][2]*T101[2][5])/Sqrt(2) + Si01[3][1]*T101[4][5] + Si01[3][2]*T101[5][5] + 0.7071067811865475*T101[6][5]))/Sqrt(2);
T01[6][4]=S10[1][1]*((l0*Si01[2][1]*T101[1][4])/Sqrt(2) + (l0*Si01[2][2]*T101[2][4])/Sqrt(2) + Si01[3][1]*T101[4][4] + Si01[3][2]*T101[5][4] + 0.7071067811865475*T101[6][4]) + S10[2][1]*((l0*Si01[2][1]*T101[1][5])/Sqrt(2) + (l0*Si01[2][2]*T101[2][5])/Sqrt(2) + Si01[3][1]*T101[4][5] + Si01[3][2]*T101[5][5] + 0.7071067811865475*T101[6][5]) + 0.7071067811865475*((l0*Si01[2][1]*T101[1][6])/Sqrt(2) + (l0*Si01[2][2]*T101[2][6])/Sqrt(2) + Si01[3][1]*T101[4][6] + Si01[3][2]*T101[5][6] + 0.7071067811865475*T101[6][6]);
T01[6][5]=S10[1][2]*((l0*Si01[2][1]*T101[1][4])/Sqrt(2) + (l0*Si01[2][2]*T101[2][4])/Sqrt(2) + Si01[3][1]*T101[4][4] + Si01[3][2]*T101[5][4] + 0.7071067811865475*T101[6][4]) + S10[2][2]*((l0*Si01[2][1]*T101[1][5])/Sqrt(2) + (l0*Si01[2][2]*T101[2][5])/Sqrt(2) + Si01[3][1]*T101[4][5] + Si01[3][2]*T101[5][5] + 0.7071067811865475*T101[6][5]);
T01[6][6]=S10[1][3]*((l0*Si01[2][1]*T101[1][4])/Sqrt(2) + (l0*Si01[2][2]*T101[2][4])/Sqrt(2) + Si01[3][1]*T101[4][4] + Si01[3][2]*T101[5][4] + 0.7071067811865475*T101[6][4]) + S10[2][3]*((l0*Si01[2][1]*T101[1][5])/Sqrt(2) + (l0*Si01[2][2]*T101[2][5])/Sqrt(2) + Si01[3][1]*T101[4][5] + Si01[3][2]*T101[5][5] + 0.7071067811865475*T101[6][5]) + 0.7071067811865475*((l0*Si01[2][1]*T101[1][6])/Sqrt(2) + (l0*Si01[2][2]*T101[2][6])/Sqrt(2) + Si01[3][1]*T101[4][6] + Si01[3][2]*T101[5][6] + 0.7071067811865475*T101[6][6]);



}


void
master_ForDynArtfunc20(void)
      {
JA0[1][1]=T01[1][1];
JA0[1][2]=links[0].mcm[3] + T01[1][2];
JA0[1][3]=-links[0].mcm[2] + T01[1][3];
JA0[1][4]=links[0].m + T01[1][4];
JA0[1][5]=T01[1][5];
JA0[1][6]=T01[1][6];

JA0[2][1]=-links[0].mcm[3] + T01[2][1];
JA0[2][2]=T01[2][2];
JA0[2][3]=links[0].mcm[1] + T01[2][3];
JA0[2][4]=T01[2][4];
JA0[2][5]=links[0].m + T01[2][5];
JA0[2][6]=T01[2][6];

JA0[3][1]=links[0].mcm[2] + T01[3][1];
JA0[3][2]=-links[0].mcm[1] + T01[3][2];
JA0[3][3]=T01[3][3];
JA0[3][4]=T01[3][4];
JA0[3][5]=T01[3][5];
JA0[3][6]=links[0].m + T01[3][6];

JA0[4][1]=links[0].inertia[1][1] + T01[4][1];
JA0[4][2]=links[0].inertia[1][2] + T01[4][2];
JA0[4][3]=links[0].inertia[1][3] + T01[4][3];
JA0[4][4]=T01[4][4];
JA0[4][5]=-links[0].mcm[3] + T01[4][5];
JA0[4][6]=links[0].mcm[2] + T01[4][6];

JA0[5][1]=links[0].inertia[1][2] + T01[5][1];
JA0[5][2]=links[0].inertia[2][2] + T01[5][2];
JA0[5][3]=links[0].inertia[2][3] + T01[5][3];
JA0[5][4]=links[0].mcm[3] + T01[5][4];
JA0[5][5]=T01[5][5];
JA0[5][6]=-links[0].mcm[1] + T01[5][6];

JA0[6][1]=links[0].inertia[1][3] + T01[6][1];
JA0[6][2]=links[0].inertia[2][3] + T01[6][2];
JA0[6][3]=links[0].inertia[3][3] + T01[6][3];
JA0[6][4]=-links[0].mcm[2] + T01[6][4];
JA0[6][5]=links[0].mcm[1] + T01[6][5];
JA0[6][6]=T01[6][6];



}


void
master_ForDynArtfunc21(void)
      {
/* bias forces */
p12[1]=0. + pv12[1];
p12[2]=0. + pv12[2];
p12[3]=0. + pv12[3];
p12[4]=0. + pv12[4];
p12[5]=0. + pv12[5];
p12[6]=0. + pv12[6];

u[12]=0. + state[10].u - c12[4]*h12[1] - c12[5]*h12[2] - c12[1]*h12[4] - c12[2]*h12[5] + 0.*h12[6] - p12[6];

pmm12[1]=p12[1] + (h12[1]*u[12])/d[12] + c12[2]*JA12[1][2] + c12[4]*JA12[1][4];
pmm12[2]=p12[2] + (h12[2]*u[12])/d[12] + c12[1]*JA12[2][1] + c12[5]*JA12[2][5];
pmm12[3]=p12[3] + c12[1]*JA12[3][1] + c12[2]*JA12[3][2];
pmm12[4]=p12[4] + (h12[4]*u[12])/d[12] + c12[1]*JA12[4][1] + c12[2]*JA12[4][2] + c12[5]*JA12[4][5];
pmm12[5]=p12[5] + (h12[5]*u[12])/d[12] + c12[1]*JA12[5][1] + c12[2]*JA12[5][2] + c12[4]*JA12[5][4];
pmm12[6]=p12[6] + (h12[6]*u[12])/d[12] + c12[1]*JA12[6][1] + c12[2]*JA12[6][2] + c12[4]*JA12[6][4] + c12[5]*JA12[6][5];

pm12[1]=pmm12[1]*Si712[1][1] + pmm12[2]*Si712[1][2];
pm12[2]=pmm12[1]*Si712[2][1] + pmm12[2]*Si712[2][2];
pm12[3]=pmm12[3];
pm12[4]=l6y*pmm12[3] + pmm12[4]*Si712[1][1] + pmm12[5]*Si712[1][2] - l6z*pmm12[1]*Si712[2][1] - l6z*pmm12[2]*Si712[2][2];
pm12[5]=l6x*pmm12[3] + l6z*pmm12[1]*Si712[1][1] + l6z*pmm12[2]*Si712[1][2] + pmm12[4]*Si712[2][1] + pmm12[5]*Si712[2][2];
pm12[6]=pmm12[6] + pmm12[1]*(-(l6y*Si712[1][1]) - l6x*Si712[2][1]) + pmm12[2]*(-(l6y*Si712[1][2]) - l6x*Si712[2][2]);

p10[1]=0. + pv10[1];
p10[2]=0. + pv10[2];
p10[3]=0. + pv10[3];
p10[4]=0. + pv10[4];
p10[5]=0. + pv10[5];
p10[6]=0. + pv10[6];

u[10]=0. + state[9].u - c10[4]*h10[1] - c10[5]*h10[2] - c10[1]*h10[4] - c10[2]*h10[5] + 0.*h10[6] - p10[6];

pmm10[1]=p10[1] + (h10[1]*u[10])/d[10] + c10[2]*JA10[1][2] + c10[4]*JA10[1][4];
pmm10[2]=p10[2] + (h10[2]*u[10])/d[10] + c10[1]*JA10[2][1] + c10[5]*JA10[2][5];
pmm10[3]=p10[3] + c10[1]*JA10[3][1] + c10[2]*JA10[3][2];
pmm10[4]=p10[4] + (h10[4]*u[10])/d[10] + c10[1]*JA10[4][1] + c10[2]*JA10[4][2] + c10[5]*JA10[4][5];
pmm10[5]=p10[5] + (h10[5]*u[10])/d[10] + c10[1]*JA10[5][1] + c10[2]*JA10[5][2] + c10[4]*JA10[5][4];
pmm10[6]=p10[6] + (h10[6]*u[10])/d[10] + c10[1]*JA10[6][1] + c10[2]*JA10[6][2] + c10[4]*JA10[6][4] + c10[5]*JA10[6][5];

pm10[1]=pmm10[3];
pm10[2]=pmm10[1]*Si910[2][1] + pmm10[2]*Si910[2][2];
pm10[3]=pmm10[1]*Si910[3][1] + pmm10[2]*Si910[3][2];
pm10[4]=pmm10[6];
pm10[5]=pmm10[4]*Si910[2][1] + pmm10[5]*Si910[2][2];
pm10[6]=pmm10[4]*Si910[3][1] + pmm10[5]*Si910[3][2];

p9[1]=pm10[1] + pv9[1];
p9[2]=pm10[2] + pv9[2];
p9[3]=pm10[3] + pv9[3];
p9[4]=pm10[4] + pv9[4];
p9[5]=pm10[5] + pv9[5];
p9[6]=pm10[6] + pv9[6];

u[9]=state[8].u - c9[4]*h9[1] - c9[5]*h9[2] + 0.*h9[3] - c9[1]*h9[4] - c9[2]*h9[5] + 0.*h9[6] - p9[6];

pmm9[1]=p9[1] + (h9[1]*u[9])/d[9] + c9[2]*JA9[1][2] + c9[4]*JA9[1][4];
pmm9[2]=p9[2] + (h9[2]*u[9])/d[9] + c9[1]*JA9[2][1] + c9[2]*JA9[2][2] + c9[5]*JA9[2][5];
pmm9[3]=p9[3] + (h9[3]*u[9])/d[9] + c9[1]*JA9[3][1] + c9[2]*JA9[3][2] + c9[5]*JA9[3][5];
pmm9[4]=p9[4] + (h9[4]*u[9])/d[9] + c9[1]*JA9[4][1] + c9[2]*JA9[4][2] + c9[5]*JA9[4][5];
pmm9[5]=p9[5] + (h9[5]*u[9])/d[9] + c9[1]*JA9[5][1] + c9[2]*JA9[5][2] + c9[4]*JA9[5][4] + c9[5]*JA9[5][5];
pmm9[6]=p9[6] + (h9[6]*u[9])/d[9] + c9[1]*JA9[6][1] + c9[2]*JA9[6][2] + c9[4]*JA9[6][4] + c9[5]*JA9[6][5];

pm9[1]=-pmm9[3];
pm9[2]=pmm9[1]*Si79[2][1] + pmm9[2]*Si79[2][2];
pm9[3]=pmm9[1]*Si79[3][1] + pmm9[2]*Si79[3][2];
pm9[4]=-pmm9[6] - l7z*pmm9[1]*Si79[2][1] - l7z*pmm9[2]*Si79[2][2];
pm9[5]=-(l7z*pmm9[3]) + pmm9[4]*Si79[2][1] + pmm9[5]*Si79[2][2] + l6x*pmm9[1]*Si79[3][1] + l6x*pmm9[2]*Si79[3][2];
pm9[6]=-(l6x*pmm9[1]*Si79[2][1]) - l6x*pmm9[2]*Si79[2][2] + pmm9[4]*Si79[3][1] + pmm9[5]*Si79[3][2];

p8[1]=pv8[1];
p8[2]=pv8[2];
p8[3]=pv8[3];
p8[4]=pv8[4];
p8[5]=pv8[5];
p8[6]=pv8[6];

pmm8[1]=p8[1];
pmm8[2]=p8[2];
pmm8[3]=p8[3];
pmm8[4]=p8[4];
pmm8[5]=p8[5];
pmm8[6]=p8[6];

pm8[1]=pmm8[1]*Si78[1][1] + pmm8[2]*Si78[1][2] + pmm8[3]*Si78[1][3];
pm8[2]=pmm8[1]*Si78[2][1] + pmm8[2]*Si78[2][2] + pmm8[3]*Si78[2][3];
pm8[3]=pmm8[1]*Si78[3][1] + pmm8[2]*Si78[3][2] + pmm8[3]*Si78[3][3];
pm8[4]=pmm8[4]*Si78[1][1] + pmm8[5]*Si78[1][2] + pmm8[6]*Si78[1][3] + pmm8[1]*(-(eff[1].x[3]*Si78[2][1]) + eff[1].x[2]*Si78[3][1]) + pmm8[2]*(-(eff[1].x[3]*Si78[2][2]) + eff[1].x[2]*Si78[3][2]) + pmm8[3]*(-(eff[1].x[3]*Si78[2][3]) + eff[1].x[2]*Si78[3][3]);
pm8[5]=pmm8[4]*Si78[2][1] + pmm8[5]*Si78[2][2] + pmm8[6]*Si78[2][3] + pmm8[1]*(eff[1].x[3]*Si78[1][1] - eff[1].x[1]*Si78[3][1]) + pmm8[2]*(eff[1].x[3]*Si78[1][2] - eff[1].x[1]*Si78[3][2]) + pmm8[3]*(eff[1].x[3]*Si78[1][3] - eff[1].x[1]*Si78[3][3]);
pm8[6]=pmm8[1]*(-(eff[1].x[2]*Si78[1][1]) + eff[1].x[1]*Si78[2][1]) + pmm8[2]*(-(eff[1].x[2]*Si78[1][2]) + eff[1].x[1]*Si78[2][2]) + pmm8[3]*(-(eff[1].x[2]*Si78[1][3]) + eff[1].x[1]*Si78[2][3]) + pmm8[4]*Si78[3][1] + pmm8[5]*Si78[3][2] + pmm8[6]*Si78[3][3];

p7[1]=pm12[1] + pm8[1] + pm9[1] + pv7[1];
p7[2]=pm12[2] + pm8[2] + pm9[2] + pv7[2];
p7[3]=pm12[3] + pm8[3] + pm9[3] + pv7[3];
p7[4]=pm12[4] + pm8[4] + pm9[4] + pv7[4];
p7[5]=pm12[5] + pm8[5] + pm9[5] + pv7[5];
p7[6]=pm12[6] + pm8[6] + pm9[6] + pv7[6];

u[7]=state[7].u - c7[4]*h7[1] - c7[5]*h7[2] + 0.*h7[3] - c7[1]*h7[4] - c7[2]*h7[5] + 0.*h7[6] - p7[6];

pmm7[1]=p7[1] + (h7[1]*u[7])/d[7] + c7[1]*JA7[1][1] + c7[2]*JA7[1][2] + c7[4]*JA7[1][4] + c7[5]*JA7[1][5];
pmm7[2]=p7[2] + (h7[2]*u[7])/d[7] + c7[1]*JA7[2][1] + c7[2]*JA7[2][2] + c7[4]*JA7[2][4] + c7[5]*JA7[2][5];
pmm7[3]=p7[3] + (h7[3]*u[7])/d[7] + c7[1]*JA7[3][1] + c7[2]*JA7[3][2] + c7[4]*JA7[3][4] + c7[5]*JA7[3][5];
pmm7[4]=p7[4] + (h7[4]*u[7])/d[7] + c7[1]*JA7[4][1] + c7[2]*JA7[4][2] + c7[4]*JA7[4][4] + c7[5]*JA7[4][5];
pmm7[5]=p7[5] + (h7[5]*u[7])/d[7] + c7[1]*JA7[5][1] + c7[2]*JA7[5][2] + c7[4]*JA7[5][4] + c7[5]*JA7[5][5];
pmm7[6]=p7[6] + (h7[6]*u[7])/d[7] + c7[1]*JA7[6][1] + c7[2]*JA7[6][2] + c7[4]*JA7[6][4] + c7[5]*JA7[6][5];

pm7[1]=pmm7[3];
pm7[2]=pmm7[1]*Si67[2][1] + pmm7[2]*Si67[2][2];
pm7[3]=pmm7[1]*Si67[3][1] + pmm7[2]*Si67[3][2];
pm7[4]=pmm7[6] - l5*pmm7[1]*Si67[2][1] - l5*pmm7[2]*Si67[2][2];
pm7[5]=l5*pmm7[3] + pmm7[4]*Si67[2][1] + pmm7[5]*Si67[2][2];
pm7[6]=pmm7[4]*Si67[3][1] + pmm7[5]*Si67[3][2];

p6[1]=pm7[1] + pv6[1];
p6[2]=pm7[2] + pv6[2];
p6[3]=pm7[3] + pv6[3];
p6[4]=pm7[4] + pv6[4];
p6[5]=pm7[5] + pv6[5];
p6[6]=pm7[6] + pv6[6];

u[6]=state[6].u - c6[4]*h6[1] - c6[5]*h6[2] + 0.*h6[3] - c6[1]*h6[4] - c6[2]*h6[5] + 0.*h6[6] - p6[6];

pmm6[1]=p6[1] + (h6[1]*u[6])/d[6] + c6[1]*JA6[1][1] + c6[2]*JA6[1][2] + c6[4]*JA6[1][4] + c6[5]*JA6[1][5];
pmm6[2]=p6[2] + (h6[2]*u[6])/d[6] + c6[1]*JA6[2][1] + c6[2]*JA6[2][2] + c6[4]*JA6[2][4] + c6[5]*JA6[2][5];
pmm6[3]=p6[3] + (h6[3]*u[6])/d[6] + c6[1]*JA6[3][1] + c6[2]*JA6[3][2] + c6[4]*JA6[3][4] + c6[5]*JA6[3][5];
pmm6[4]=p6[4] + (h6[4]*u[6])/d[6] + c6[1]*JA6[4][1] + c6[2]*JA6[4][2] + c6[4]*JA6[4][4] + c6[5]*JA6[4][5];
pmm6[5]=p6[5] + (h6[5]*u[6])/d[6] + c6[1]*JA6[5][1] + c6[2]*JA6[5][2] + c6[4]*JA6[5][4] + c6[5]*JA6[5][5];
pmm6[6]=p6[6] + (h6[6]*u[6])/d[6] + c6[1]*JA6[6][1] + c6[2]*JA6[6][2] + c6[4]*JA6[6][4] + c6[5]*JA6[6][5];

pm6[1]=pmm6[1]*Si56[1][1] + pmm6[2]*Si56[1][2];
pm6[2]=pmm6[3];
pm6[3]=pmm6[1]*Si56[3][1] + pmm6[2]*Si56[3][2];
pm6[4]=-(l4*pmm6[3]) + pmm6[4]*Si56[1][1] + pmm6[5]*Si56[1][2];
pm6[5]=pmm6[6] + l4*pmm6[1]*Si56[1][1] + l4*pmm6[2]*Si56[1][2];
pm6[6]=pmm6[4]*Si56[3][1] + pmm6[5]*Si56[3][2];

p5[1]=pm6[1] + pv5[1];
p5[2]=pm6[2] + pv5[2];
p5[3]=pm6[3] + pv5[3];
p5[4]=pm6[4] + pv5[4];
p5[5]=pm6[5] + pv5[5];
p5[6]=pm6[6] + pv5[6];

u[5]=state[5].u - c5[4]*h5[1] - c5[5]*h5[2] + 0.*h5[3] - c5[1]*h5[4] - c5[2]*h5[5] + 0.*h5[6] - p5[6];

pmm5[1]=p5[1] + (h5[1]*u[5])/d[5] + c5[1]*JA5[1][1] + c5[2]*JA5[1][2] + c5[4]*JA5[1][4] + c5[5]*JA5[1][5];
pmm5[2]=p5[2] + (h5[2]*u[5])/d[5] + c5[1]*JA5[2][1] + c5[2]*JA5[2][2] + c5[4]*JA5[2][4] + c5[5]*JA5[2][5];
pmm5[3]=p5[3] + (h5[3]*u[5])/d[5] + c5[1]*JA5[3][1] + c5[2]*JA5[3][2] + c5[4]*JA5[3][4] + c5[5]*JA5[3][5];
pmm5[4]=p5[4] + (h5[4]*u[5])/d[5] + c5[1]*JA5[4][1] + c5[2]*JA5[4][2] + c5[4]*JA5[4][4] + c5[5]*JA5[4][5];
pmm5[5]=p5[5] + (h5[5]*u[5])/d[5] + c5[1]*JA5[5][1] + c5[2]*JA5[5][2] + c5[4]*JA5[5][4] + c5[5]*JA5[5][5];
pmm5[6]=p5[6] + (h5[6]*u[5])/d[5] + c5[1]*JA5[6][1] + c5[2]*JA5[6][2] + c5[4]*JA5[6][4] + c5[5]*JA5[6][5];

pm5[1]=-pmm5[3];
pm5[2]=pmm5[1]*Si45[2][1] + pmm5[2]*Si45[2][2];
pm5[3]=pmm5[1]*Si45[3][1] + pmm5[2]*Si45[3][2];
pm5[4]=-pmm5[6] + l3*pmm5[1]*Si45[2][1] + l3*pmm5[2]*Si45[2][2];
pm5[5]=l3*pmm5[3] + pmm5[4]*Si45[2][1] + pmm5[5]*Si45[2][2];
pm5[6]=pmm5[4]*Si45[3][1] + pmm5[5]*Si45[3][2];

p4[1]=pm5[1] + pv4[1];
p4[2]=pm5[2] + pv4[2];
p4[3]=pm5[3] + pv4[3];
p4[4]=pm5[4] + pv4[4];
p4[5]=pm5[5] + pv4[5];
p4[6]=pm5[6] + pv4[6];

u[4]=state[4].u - c4[4]*h4[1] - c4[5]*h4[2] + 0.*h4[3] - c4[1]*h4[4] - c4[2]*h4[5] + 0.*h4[6] - p4[6];

pmm4[1]=p4[1] + (h4[1]*u[4])/d[4] + c4[1]*JA4[1][1] + c4[2]*JA4[1][2] + c4[4]*JA4[1][4] + c4[5]*JA4[1][5];
pmm4[2]=p4[2] + (h4[2]*u[4])/d[4] + c4[1]*JA4[2][1] + c4[2]*JA4[2][2] + c4[4]*JA4[2][4] + c4[5]*JA4[2][5];
pmm4[3]=p4[3] + (h4[3]*u[4])/d[4] + c4[1]*JA4[3][1] + c4[2]*JA4[3][2] + c4[4]*JA4[3][4] + c4[5]*JA4[3][5];
pmm4[4]=p4[4] + (h4[4]*u[4])/d[4] + c4[1]*JA4[4][1] + c4[2]*JA4[4][2] + c4[4]*JA4[4][4] + c4[5]*JA4[4][5];
pmm4[5]=p4[5] + (h4[5]*u[4])/d[4] + c4[1]*JA4[5][1] + c4[2]*JA4[5][2] + c4[4]*JA4[5][4] + c4[5]*JA4[5][5];
pmm4[6]=p4[6] + (h4[6]*u[4])/d[4] + c4[1]*JA4[6][1] + c4[2]*JA4[6][2] + c4[4]*JA4[6][4] + c4[5]*JA4[6][5];

pm4[1]=pmm4[1]*Si34[1][1] + pmm4[2]*Si34[1][2];
pm4[2]=-pmm4[3];
pm4[3]=pmm4[1]*Si34[3][1] + pmm4[2]*Si34[3][2];
pm4[4]=l2*pmm4[3] + pmm4[4]*Si34[1][1] + pmm4[5]*Si34[1][2];
pm4[5]=-pmm4[6] + l2*pmm4[1]*Si34[1][1] + l2*pmm4[2]*Si34[1][2];
pm4[6]=pmm4[4]*Si34[3][1] + pmm4[5]*Si34[3][2];

p3[1]=pm4[1] + pv3[1];
p3[2]=pm4[2] + pv3[2];
p3[3]=pm4[3] + pv3[3];
p3[4]=pm4[4] + pv3[4];
p3[5]=pm4[5] + pv3[5];
p3[6]=pm4[6] + pv3[6];

u[3]=state[3].u - c3[4]*h3[1] - c3[5]*h3[2] + 0.*h3[3] - c3[1]*h3[4] - c3[2]*h3[5] + 0.*h3[6] - p3[6];

pmm3[1]=p3[1] + (h3[1]*u[3])/d[3] + c3[1]*JA3[1][1] + c3[2]*JA3[1][2] + c3[4]*JA3[1][4] + c3[5]*JA3[1][5];
pmm3[2]=p3[2] + (h3[2]*u[3])/d[3] + c3[1]*JA3[2][1] + c3[2]*JA3[2][2] + c3[4]*JA3[2][4] + c3[5]*JA3[2][5];
pmm3[3]=p3[3] + (h3[3]*u[3])/d[3] + c3[1]*JA3[3][1] + c3[2]*JA3[3][2] + c3[4]*JA3[3][4] + c3[5]*JA3[3][5];
pmm3[4]=p3[4] + (h3[4]*u[3])/d[3] + c3[1]*JA3[4][1] + c3[2]*JA3[4][2] + c3[4]*JA3[4][4] + c3[5]*JA3[4][5];
pmm3[5]=p3[5] + (h3[5]*u[3])/d[3] + c3[1]*JA3[5][1] + c3[2]*JA3[5][2] + c3[4]*JA3[5][4] + c3[5]*JA3[5][5];
pmm3[6]=p3[6] + (h3[6]*u[3])/d[3] + c3[1]*JA3[6][1] + c3[2]*JA3[6][2] + c3[4]*JA3[6][4] + c3[5]*JA3[6][5];

pm3[1]=pmm3[3];
pm3[2]=pmm3[1]*Si23[2][1] + pmm3[2]*Si23[2][2];
pm3[3]=pmm3[1]*Si23[3][1] + pmm3[2]*Si23[3][2];
pm3[4]=pmm3[6] - l1*pmm3[1]*Si23[3][1] - l1*pmm3[2]*Si23[3][2];
pm3[5]=pmm3[4]*Si23[2][1] + pmm3[5]*Si23[2][2];
pm3[6]=l1*pmm3[3] + pmm3[4]*Si23[3][1] + pmm3[5]*Si23[3][2];

p2[1]=pm3[1] + pv2[1];
p2[2]=pm3[2] + pv2[2];
p2[3]=pm3[3] + pv2[3];
p2[4]=pm3[4] + pv2[4];
p2[5]=pm3[5] + pv2[5];
p2[6]=pm3[6] + pv2[6];

u[2]=state[2].u - c2[4]*h2[1] - c2[5]*h2[2] + 0.*h2[3] - c2[1]*h2[4] - c2[2]*h2[5] + 0.*h2[6] - p2[6];

pmm2[1]=p2[1] + (h2[1]*u[2])/d[2] + c2[1]*JA2[1][1] + c2[2]*JA2[1][2] + c2[4]*JA2[1][4] + c2[5]*JA2[1][5];
pmm2[2]=p2[2] + (h2[2]*u[2])/d[2] + c2[1]*JA2[2][1] + c2[2]*JA2[2][2] + c2[4]*JA2[2][4] + c2[5]*JA2[2][5];
pmm2[3]=p2[3] + (h2[3]*u[2])/d[2] + c2[1]*JA2[3][1] + c2[2]*JA2[3][2] + c2[4]*JA2[3][4] + c2[5]*JA2[3][5];
pmm2[4]=p2[4] + (h2[4]*u[2])/d[2] + c2[1]*JA2[4][1] + c2[2]*JA2[4][2] + c2[4]*JA2[4][4] + c2[5]*JA2[4][5];
pmm2[5]=p2[5] + (h2[5]*u[2])/d[2] + c2[1]*JA2[5][1] + c2[2]*JA2[5][2] + c2[4]*JA2[5][4] + c2[5]*JA2[5][5];
pmm2[6]=p2[6] + (h2[6]*u[2])/d[2] + c2[1]*JA2[6][1] + c2[2]*JA2[6][2] + c2[4]*JA2[6][4] + c2[5]*JA2[6][5];

pm2[1]=pmm2[1]*Si12[1][1] + pmm2[2]*Si12[1][2];
pm2[2]=pmm2[3];
pm2[3]=pmm2[1]*Si12[3][1] + pmm2[2]*Si12[3][2];
pm2[4]=pmm2[4]*Si12[1][1] + pmm2[5]*Si12[1][2];
pm2[5]=pmm2[6];
pm2[6]=pmm2[4]*Si12[3][1] + pmm2[5]*Si12[3][2];

p1[1]=pm2[1] + pv1[1];
p1[2]=pm2[2] + pv1[2];
p1[3]=pm2[3] + pv1[3];
p1[4]=pm2[4] + pv1[4];
p1[5]=pm2[5] + pv1[5];
p1[6]=pm2[6] + pv1[6];

u[1]=state[1].u - c1[4]*h1[1] - c1[5]*h1[2] + 0.*h1[3] - c1[1]*h1[4] - c1[2]*h1[5] + 0.*h1[6] - p1[6];

pmm1[1]=p1[1] + (h1[1]*u[1])/d[1] + c1[1]*JA1[1][1] + c1[2]*JA1[1][2] + c1[4]*JA1[1][4] + c1[5]*JA1[1][5];
pmm1[2]=p1[2] + (h1[2]*u[1])/d[1] + c1[1]*JA1[2][1] + c1[2]*JA1[2][2] + c1[4]*JA1[2][4] + c1[5]*JA1[2][5];
pmm1[3]=p1[3] + (h1[3]*u[1])/d[1] + c1[1]*JA1[3][1] + c1[2]*JA1[3][2] + c1[4]*JA1[3][4] + c1[5]*JA1[3][5];
pmm1[4]=p1[4] + (h1[4]*u[1])/d[1] + c1[1]*JA1[4][1] + c1[2]*JA1[4][2] + c1[4]*JA1[4][4] + c1[5]*JA1[4][5];
pmm1[5]=p1[5] + (h1[5]*u[1])/d[1] + c1[1]*JA1[5][1] + c1[2]*JA1[5][2] + c1[4]*JA1[5][4] + c1[5]*JA1[5][5];
pmm1[6]=p1[6] + (h1[6]*u[1])/d[1] + c1[1]*JA1[6][1] + c1[2]*JA1[6][2] + c1[4]*JA1[6][4] + c1[5]*JA1[6][5];

pm1[1]=0.7071067811865475*pmm1[3] + pmm1[1]*Si01[1][1] + pmm1[2]*Si01[1][2];
pm1[2]=pmm1[1]*Si01[2][1] + pmm1[2]*Si01[2][2];
pm1[3]=0.7071067811865475*pmm1[3] + pmm1[1]*Si01[3][1] + pmm1[2]*Si01[3][2];
pm1[4]=0.7071067811865475*pmm1[6] + pmm1[4]*Si01[1][1] + pmm1[5]*Si01[1][2] - (l0*pmm1[1]*Si01[2][1])/Sqrt(2) - (l0*pmm1[2]*Si01[2][2])/Sqrt(2);
pm1[5]=pmm1[4]*Si01[2][1] + pmm1[5]*Si01[2][2] + pmm1[1]*((l0*Si01[1][1])/Sqrt(2) - (l0*Si01[3][1])/Sqrt(2)) + pmm1[2]*((l0*Si01[1][2])/Sqrt(2) - (l0*Si01[3][2])/Sqrt(2));
pm1[6]=0.7071067811865475*pmm1[6] + (l0*pmm1[1]*Si01[2][1])/Sqrt(2) + (l0*pmm1[2]*Si01[2][2])/Sqrt(2) + pmm1[4]*Si01[3][1] + pmm1[5]*Si01[3][2];

p0[1]=pm1[1] + pv0[1];
p0[2]=pm1[2] + pv0[2];
p0[3]=pm1[3] + pv0[3];
p0[4]=pm1[4] + pv0[4];
p0[5]=pm1[5] + pv0[5];
p0[6]=pm1[6] + pv0[6];


}


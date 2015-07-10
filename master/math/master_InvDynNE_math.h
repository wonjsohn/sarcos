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








master_InvDynNEfunc1();

master_InvDynNEfunc2();

master_InvDynNEfunc3();

master_InvDynNEfunc4();

master_InvDynNEfunc5();

master_InvDynNEfunc6();

master_InvDynNEfunc7();

/* force/torque of base in world coordinates */
fbase[1]=f0[1]*Si00[1][1] + f0[2]*Si00[1][2] + f0[3]*Si00[1][3];
fbase[2]=f0[1]*Si00[2][1] + f0[2]*Si00[2][2] + f0[3]*Si00[2][3];
fbase[3]=f0[1]*Si00[3][1] + f0[2]*Si00[3][2] + f0[3]*Si00[3][3];
fbase[4]=f0[4]*Si00[1][1] + f0[5]*Si00[1][2] + f0[6]*Si00[1][3];
fbase[5]=f0[4]*Si00[2][1] + f0[5]*Si00[2][2] + f0[6]*Si00[2][3];
fbase[6]=f0[4]*Si00[3][1] + f0[5]*Si00[3][2] + f0[6]*Si00[3][3];

/* inverse dynamics torques */
state[1].uff=-state[1].uex + f1[6] + fext1[6];
state[2].uff=-state[2].uex + f2[6] + fext2[6];
state[3].uff=-state[3].uex + f3[6] + fext3[6];
state[4].uff=-state[4].uex + f4[6] + fext4[6];
state[5].uff=-state[5].uex + f5[6] + fext5[6];
state[6].uff=-state[6].uex + f6[6] + fext6[6];
state[7].uff=-state[7].uex + f7[6] + fext7[6];
state[8].uff=-state[8].uex + f9[6] + fext9[6];
state[9].uff=-state[9].uex + f10[6] + fext10[6];
state[10].uff=-state[10].uex + f12[6] + fext12[6];

/* torques due to external forces */
qext[1]=-state[1].uex + fext1[6];
qext[2]=-state[2].uex + fext2[6];
qext[3]=-state[3].uex + fext3[6];
qext[4]=-state[4].uex + fext4[6];
qext[5]=-state[5].uex + fext5[6];
qext[6]=-state[6].uex + fext6[6];
qext[7]=-state[7].uex + fext7[6];
qext[8]=0.;
qext[9]=-state[8].uex + fext9[6];
qext[10]=-state[9].uex + fext10[6];
qext[11]=0.;
qext[12]=-state[10].uex + fext12[6];
qext[13]=0.;


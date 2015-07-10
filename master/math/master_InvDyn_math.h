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








master_InvDynfunc1();

master_InvDynfunc2();

master_InvDynfunc3();

master_InvDynfunc4();

master_InvDynfunc5();

master_InvDynfunc6();

master_InvDynfunc7();

/* inverse dynamics torques */
state[1].uff=0. - state[1].uex + f1[6];
state[2].uff=0. - state[2].uex + f2[6];
state[3].uff=0. - state[3].uex + f3[6];
state[4].uff=0. - state[4].uex + f4[6];
state[5].uff=0. - state[5].uex + f5[6];
state[6].uff=0. - state[6].uex + f6[6];
state[7].uff=0. - state[7].uex + f7[6];
state[8].uff=0. - state[8].uex + f9[6];
state[9].uff=0. - state[9].uex + f10[6];
state[10].uff=0. - state[10].uex + f12[6];

/* torques due to external forces */
qext[1]=0. - state[1].uex;
qext[2]=0. - state[2].uex;
qext[3]=0. - state[3].uex;
qext[4]=0. - state[4].uex;
qext[5]=0. - state[5].uex;
qext[6]=0. - state[6].uex;
qext[7]=0. - state[7].uex;
qext[9]=0. - state[8].uex;
qext[10]=0. - state[9].uex;
qext[12]=0. - state[10].uex;


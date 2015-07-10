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








master_ForDynfunc1();

master_ForDynfunc2();

master_ForDynfunc3();

master_ForDynfunc4();

master_ForDynfunc5();

master_ForDynfunc6();

master_ForDynfunc7();

/* inverse dynamics torques */
c[1]=f1[6] + fext1[6];
c[2]=f2[6] + fext2[6];
c[3]=f3[6] + fext3[6];
c[4]=f4[6] + fext4[6];
c[5]=f5[6] + fext5[6];
c[6]=f6[6] + fext6[6];
c[7]=f7[6] + fext7[6];
c[8]=0;
c[9]=f9[6] + fext9[6];
c[10]=f10[6] + fext10[6];
c[11]=0.;
c[12]=f12[6] + fext12[6];
c[13]=0.;

/* torques due to external forces */
qext[1]=fext1[6];
qext[2]=fext2[6];
qext[3]=fext3[6];
qext[4]=fext4[6];
qext[5]=fext5[6];
qext[6]=fext6[6];
qext[7]=fext7[6];
qext[9]=fext9[6];
qext[10]=fext10[6];
qext[12]=fext12[6];

masterfunc11();

masterfunc12();

masterfunc13();

masterfunc14();

masterfunc15();

masterfunc16();

masterfunc17();

masterfunc18();

masterfunc19();

masterfunc20();

masterfunc21();

masterfunc22();

masterfunc23();

masterfunc24();

masterfunc25();

masterfunc26();

masterfunc27();

c[1]=c[1] - qext[1];
c[2]=c[2] - qext[2];
c[3]=c[3] - qext[3];
c[4]=c[4] - qext[4];
c[5]=c[5] - qext[5];
c[6]=c[6] - qext[6];
c[7]=c[7] - qext[7];
c[8]=c[8];
c[9]=c[9] - qext[9];
c[10]=c[10] - qext[10];
c[11]=c[11];
c[12]=c[12] - qext[12];
c[13]=c[13];
c[14]=f0[1];
c[15]=f0[2];
c[16]=f0[3];
c[17]=f0[4];
c[18]=f0[5];
c[19]=f0[6];

uc[1]=state[1].u - c[1] - qext[1];
uc[2]=state[2].u - c[2] - qext[2];
uc[3]=state[3].u - c[3] - qext[3];
uc[4]=state[4].u - c[4] - qext[4];
uc[5]=state[5].u - c[5] - qext[5];
uc[6]=state[6].u - c[6] - qext[6];
uc[7]=state[7].u - c[7] - qext[7];
uc[8]=-c[8];
uc[9]=state[8].u - c[9] - qext[9];
uc[10]=state[9].u - c[10] - qext[10];
uc[11]=-c[11];
uc[12]=state[10].u - c[12] - qext[12];
uc[13]=-c[13];
uc[14]=-c[14] - fext0[1];
uc[15]=-c[15] - fext0[2];
uc[16]=-c[16] - fext0[3];
uc[17]=-c[17] - fext0[4];
uc[18]=-c[18] - fext0[5];
uc[19]=-c[19] - fext0[6];

/* now solve for accelerations: uc = H * thdd           */
/* Note: uc and H are calculated above */
Hmat[1][1] = Hmat[1][1] = H[1][1];
Hmat[1][2] = Hmat[2][1] = H[2][1];
Hmat[1][3] = Hmat[3][1] = H[3][1];
Hmat[1][4] = Hmat[4][1] = H[4][1];
Hmat[1][5] = Hmat[5][1] = H[5][1];
Hmat[1][6] = Hmat[6][1] = H[6][1];
Hmat[1][7] = Hmat[7][1] = H[7][1];
Hmat[1][8] = Hmat[8][1] = H[9][1];
Hmat[1][9] = Hmat[9][1] = H[10][1];
Hmat[1][10] = Hmat[10][1] = H[12][1];
Hmat[2][2] = Hmat[2][2] = H[2][2];
Hmat[2][3] = Hmat[3][2] = H[3][2];
Hmat[2][4] = Hmat[4][2] = H[4][2];
Hmat[2][5] = Hmat[5][2] = H[5][2];
Hmat[2][6] = Hmat[6][2] = H[6][2];
Hmat[2][7] = Hmat[7][2] = H[7][2];
Hmat[2][8] = Hmat[8][2] = H[9][2];
Hmat[2][9] = Hmat[9][2] = H[10][2];
Hmat[2][10] = Hmat[10][2] = H[12][2];
Hmat[3][3] = Hmat[3][3] = H[3][3];
Hmat[3][4] = Hmat[4][3] = H[4][3];
Hmat[3][5] = Hmat[5][3] = H[5][3];
Hmat[3][6] = Hmat[6][3] = H[6][3];
Hmat[3][7] = Hmat[7][3] = H[7][3];
Hmat[3][8] = Hmat[8][3] = H[9][3];
Hmat[3][9] = Hmat[9][3] = H[10][3];
Hmat[3][10] = Hmat[10][3] = H[12][3];
Hmat[4][4] = Hmat[4][4] = H[4][4];
Hmat[4][5] = Hmat[5][4] = H[5][4];
Hmat[4][6] = Hmat[6][4] = H[6][4];
Hmat[4][7] = Hmat[7][4] = H[7][4];
Hmat[4][8] = Hmat[8][4] = H[9][4];
Hmat[4][9] = Hmat[9][4] = H[10][4];
Hmat[4][10] = Hmat[10][4] = H[12][4];
Hmat[5][5] = Hmat[5][5] = H[5][5];
Hmat[5][6] = Hmat[6][5] = H[6][5];
Hmat[5][7] = Hmat[7][5] = H[7][5];
Hmat[5][8] = Hmat[8][5] = H[9][5];
Hmat[5][9] = Hmat[9][5] = H[10][5];
Hmat[5][10] = Hmat[10][5] = H[12][5];
Hmat[6][6] = Hmat[6][6] = H[6][6];
Hmat[6][7] = Hmat[7][6] = H[7][6];
Hmat[6][8] = Hmat[8][6] = H[9][6];
Hmat[6][9] = Hmat[9][6] = H[10][6];
Hmat[6][10] = Hmat[10][6] = H[12][6];
Hmat[7][7] = Hmat[7][7] = H[7][7];
Hmat[7][8] = Hmat[8][7] = H[9][7];
Hmat[7][9] = Hmat[9][7] = H[10][7];
Hmat[7][10] = Hmat[10][7] = H[12][7];
Hmat[8][8] = Hmat[8][8] = H[9][9];
Hmat[8][9] = Hmat[9][8] = H[10][9];
Hmat[8][10] = Hmat[10][8] = H[12][9];
Hmat[9][9] = Hmat[9][9] = H[10][10];
Hmat[9][10] = Hmat[10][9] = H[12][10];
Hmat[10][10] = Hmat[10][10] = H[12][12];
cvec[1]  = c[1];
ucvec[1] = uc[1];
cvec[2]  = c[2];
ucvec[2] = uc[2];
cvec[3]  = c[3];
ucvec[3] = uc[3];
cvec[4]  = c[4];
ucvec[4] = uc[4];
cvec[5]  = c[5];
ucvec[5] = uc[5];
cvec[6]  = c[6];
ucvec[6] = uc[6];
cvec[7]  = c[7];
ucvec[7] = uc[7];
cvec[8]  = c[9];
ucvec[8] = uc[9];
cvec[9]  = c[10];
ucvec[9] = uc[10];
cvec[10]  = c[12];
ucvec[10] = uc[12];
 for (i=1; i<=6; ++i) 
      cvec[10+i]=c[13+i];
 for (i=1; i<=6; ++i) 
      ucvec[10+i]=uc[13+i];
my_inv_ldlt(Hmat,ucvec,10,thdd);

state[1].thdd=thdd[1];
state[2].thdd=thdd[2];
state[3].thdd=thdd[3];
state[4].thdd=thdd[4];
state[5].thdd=thdd[5];
state[6].thdd=thdd[6];
state[7].thdd=thdd[7];
state[8].thdd=thdd[8];
state[9].thdd=thdd[9];
state[10].thdd=thdd[10];


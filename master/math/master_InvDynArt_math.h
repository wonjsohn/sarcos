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








master_InvDynArtfunc1();

master_InvDynArtfunc2();

master_InvDynArtfunc3();

master_InvDynArtfunc4();

master_InvDynArtfunc5();

master_InvDynArtfunc6();

master_InvDynArtfunc7();

master_InvDynArtfunc8();

master_InvDynArtfunc9();

master_InvDynArtfunc10();

master_InvDynArtfunc11();

master_InvDynArtfunc12();

master_InvDynArtfunc13();

master_InvDynArtfunc14();

master_InvDynArtfunc15();

master_InvDynArtfunc16();

master_InvDynArtfunc17();

master_InvDynArtfunc18();

master_InvDynArtfunc19();

master_InvDynArtfunc20();

master_InvDynArtfunc21();

/* acceleration vectors, base acceleration, and joint torques */
a1[1]=c1[1];
a1[2]=c1[2];
a1[3]=state[1].thdd;
a1[4]=c1[4];
a1[5]=c1[5];

a2[1]=c2[1] + a1[1]*S21[1][1] + a1[3]*S21[1][3];
a2[2]=c2[2] + a1[1]*S21[2][1] + a1[3]*S21[2][3];
a2[3]=state[2].thdd + a1[2];
a2[4]=c2[4] + a1[4]*S21[1][1];
a2[5]=c2[5] + a1[4]*S21[2][1];
a2[6]=a1[5];

a3[1]=c3[1] + a2[2]*S32[1][2] + a2[3]*S32[1][3];
a3[2]=c3[2] + a2[2]*S32[2][2] + a2[3]*S32[2][3];
a3[3]=state[3].thdd + a2[1];
a3[4]=c3[4] + a2[5]*S32[1][2] - l1*a2[1]*S32[1][3] + a2[6]*S32[1][3];
a3[5]=c3[5] + a2[5]*S32[2][2] - l1*a2[1]*S32[2][3] + a2[6]*S32[2][3];
a3[6]=l1*a2[3] + a2[4];

a4[1]=c4[1] + a3[1]*S43[1][1] + a3[3]*S43[1][3];
a4[2]=c4[2] + a3[1]*S43[2][1] + a3[3]*S43[2][3];
a4[3]=state[4].thdd - a3[2];
a4[4]=c4[4] + l2*a3[2]*S43[1][1] + a3[4]*S43[1][1] + a3[6]*S43[1][3];
a4[5]=c4[5] + l2*a3[2]*S43[2][1] + a3[4]*S43[2][1] + a3[6]*S43[2][3];
a4[6]=l2*a3[1] - a3[5];

a5[1]=c5[1] + a4[2]*S54[1][2] + a4[3]*S54[1][3];
a5[2]=c5[2] + a4[2]*S54[2][2] + a4[3]*S54[2][3];
a5[3]=state[5].thdd - a4[1];
a5[4]=c5[4] + l3*a4[1]*S54[1][2] + a4[5]*S54[1][2] + a4[6]*S54[1][3];
a5[5]=c5[5] + l3*a4[1]*S54[2][2] + a4[5]*S54[2][2] + a4[6]*S54[2][3];
a5[6]=l3*a4[2] - a4[4];

a6[1]=c6[1] + a5[1]*S65[1][1] + a5[3]*S65[1][3];
a6[2]=c6[2] + a5[1]*S65[2][1] + a5[3]*S65[2][3];
a6[3]=state[6].thdd + a5[2];
a6[4]=c6[4] + l4*a5[2]*S65[1][1] + a5[4]*S65[1][1] + a5[6]*S65[1][3];
a6[5]=c6[5] + l4*a5[2]*S65[2][1] + a5[4]*S65[2][1] + a5[6]*S65[2][3];
a6[6]=-(l4*a5[1]) + a5[5];

a7[1]=c7[1] + a6[2]*S76[1][2] + a6[3]*S76[1][3];
a7[2]=c7[2] + a6[2]*S76[2][2] + a6[3]*S76[2][3];
a7[3]=state[7].thdd + a6[1];
a7[4]=c7[4] - l5*a6[1]*S76[1][2] + a6[5]*S76[1][2] + a6[6]*S76[1][3];
a7[5]=c7[5] - l5*a6[1]*S76[2][2] + a6[5]*S76[2][2] + a6[6]*S76[2][3];
a7[6]=l5*a6[2] + a6[4];

a8[1]=a7[1]*S87[1][1] + a7[2]*S87[1][2] + a7[3]*S87[1][3];
a8[2]=a7[1]*S87[2][1] + a7[2]*S87[2][2] + a7[3]*S87[2][3];
a8[3]=a7[1]*S87[3][1] + a7[2]*S87[3][2] + a7[3]*S87[3][3];
a8[4]=a7[4]*S87[1][1] + a7[5]*S87[1][2] + a7[3]*(-(eff[1].x[2]*S87[1][1]) + eff[1].x[1]*S87[1][2]) + a7[6]*S87[1][3] + a7[2]*(eff[1].x[3]*S87[1][1] - eff[1].x[1]*S87[1][3]) + a7[1]*(-(eff[1].x[3]*S87[1][2]) + eff[1].x[2]*S87[1][3]);
a8[5]=a7[4]*S87[2][1] + a7[5]*S87[2][2] + a7[3]*(-(eff[1].x[2]*S87[2][1]) + eff[1].x[1]*S87[2][2]) + a7[6]*S87[2][3] + a7[2]*(eff[1].x[3]*S87[2][1] - eff[1].x[1]*S87[2][3]) + a7[1]*(-(eff[1].x[3]*S87[2][2]) + eff[1].x[2]*S87[2][3]);
a8[6]=a7[4]*S87[3][1] + a7[5]*S87[3][2] + a7[3]*(-(eff[1].x[2]*S87[3][1]) + eff[1].x[1]*S87[3][2]) + a7[6]*S87[3][3] + a7[2]*(eff[1].x[3]*S87[3][1] - eff[1].x[1]*S87[3][3]) + a7[1]*(-(eff[1].x[3]*S87[3][2]) + eff[1].x[2]*S87[3][3]);

a9[1]=c9[1] + a7[2]*S97[1][2] + a7[3]*S97[1][3];
a9[2]=c9[2] + a7[2]*S97[2][2] + a7[3]*S97[2][3];
a9[3]=state[8].thdd - a7[1];
a9[4]=c9[4] - l7z*a7[1]*S97[1][2] - l6x*a7[3]*S97[1][2] + a7[5]*S97[1][2] + l6x*a7[2]*S97[1][3] + a7[6]*S97[1][3];
a9[5]=c9[5] - l7z*a7[1]*S97[2][2] - l6x*a7[3]*S97[2][2] + a7[5]*S97[2][2] + l6x*a7[2]*S97[2][3] + a7[6]*S97[2][3];
a9[6]=-(l7z*a7[2]) - a7[4];

a10[1]=c10[1] + a9[2]*S109[1][2] + a9[3]*S109[1][3];
a10[2]=c10[2] + a9[2]*S109[2][2] + a9[3]*S109[2][3];
a10[3]=state[9].thdd + a9[1];
a10[4]=c10[4] + a9[5]*S109[1][2] + a9[6]*S109[1][3];
a10[5]=c10[5] + a9[5]*S109[2][2] + a9[6]*S109[2][3];
a10[6]=a9[4];

a11[1]=a10[1];
a11[2]=a10[2];
a11[3]=a10[3];
a11[4]=-(l8*a10[3]) + a10[4];
a11[5]=a10[5];
a11[6]=l8*a10[1] + a10[6];

a12[1]=c12[1] + a7[1]*S127[1][1] + a7[2]*S127[1][2];
a12[2]=c12[2] + a7[1]*S127[2][1] + a7[2]*S127[2][2];
a12[3]=state[10].thdd + a7[3];
a12[4]=c12[4] + l6z*a7[2]*S127[1][1] + a7[4]*S127[1][1] - l6z*a7[1]*S127[1][2] + a7[5]*S127[1][2] + a7[3]*(-(l6y*S127[1][1]) - l6x*S127[1][2]);
a12[5]=c12[5] + l6z*a7[2]*S127[2][1] + a7[4]*S127[2][1] - l6z*a7[1]*S127[2][2] + a7[5]*S127[2][2] + a7[3]*(-(l6y*S127[2][1]) - l6x*S127[2][2]);
a12[6]=l6y*a7[1] + l6x*a7[2] + a7[6];

a13[1]=a12[1];
a13[2]=a12[2];
a13[3]=a12[3];
a13[4]=-(l9*a12[3]) + a12[4];
a13[5]=a12[5];
a13[6]=l9*a12[1] + a12[6];

/* inverse dynamics torques */
state[1].uff=p1[6] + a1[1]*JA1[6][1] + a1[2]*JA1[6][2] + a1[3]*JA1[6][3] + a1[4]*JA1[6][4] + a1[5]*JA1[6][5];
state[2].uff=p2[6] + a2[1]*JA2[6][1] + a2[2]*JA2[6][2] + a2[3]*JA2[6][3] + a2[4]*JA2[6][4] + a2[5]*JA2[6][5] + a2[6]*JA2[6][6];
state[3].uff=p3[6] + a3[1]*JA3[6][1] + a3[2]*JA3[6][2] + a3[3]*JA3[6][3] + a3[4]*JA3[6][4] + a3[5]*JA3[6][5] + a3[6]*JA3[6][6];
state[4].uff=p4[6] + a4[1]*JA4[6][1] + a4[2]*JA4[6][2] + a4[3]*JA4[6][3] + a4[4]*JA4[6][4] + a4[5]*JA4[6][5] + a4[6]*JA4[6][6];
state[5].uff=p5[6] + a5[1]*JA5[6][1] + a5[2]*JA5[6][2] + a5[3]*JA5[6][3] + a5[4]*JA5[6][4] + a5[5]*JA5[6][5] + a5[6]*JA5[6][6];
state[6].uff=p6[6] + a6[1]*JA6[6][1] + a6[2]*JA6[6][2] + a6[3]*JA6[6][3] + a6[4]*JA6[6][4] + a6[5]*JA6[6][5] + a6[6]*JA6[6][6];
state[7].uff=p7[6] + a7[1]*JA7[6][1] + a7[2]*JA7[6][2] + a7[3]*JA7[6][3] + a7[4]*JA7[6][4] + a7[5]*JA7[6][5] + a7[6]*JA7[6][6];
state[8].uff=p9[6] + a9[1]*JA9[6][1] + a9[2]*JA9[6][2] + a9[3]*JA9[6][3] + a9[4]*JA9[6][4] + a9[5]*JA9[6][5] + a9[6]*JA9[6][6];
state[9].uff=p10[6] + a10[1]*JA10[6][1] + a10[2]*JA10[6][2] + a10[3]*JA10[6][3] + a10[4]*JA10[6][4] + a10[5]*JA10[6][5];
state[10].uff=p12[6] + a12[1]*JA12[6][1] + a12[2]*JA12[6][2] + a12[3]*JA12[6][3] + a12[4]*JA12[6][4] + a12[5]*JA12[6][5];


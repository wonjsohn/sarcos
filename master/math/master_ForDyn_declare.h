static double  sstate1th;
static double  cstate1th;
static double  sstate2th;
static double  cstate2th;
static double  sstate3th;
static double  cstate3th;
static double  sstate4th;
static double  cstate4th;
static double  sstate5th;
static double  cstate5th;
static double  sstate6th;
static double  cstate6th;
static double  sstate7th;
static double  cstate7th;
static double  sstate8th;
static double  cstate8th;
static double  sstate9th;
static double  cstate9th;
static double  sstate10th;
static double  cstate10th;

static double  rseff1a1;
static double  rceff1a1;
static double  rseff1a2;
static double  rceff1a2;
static double  rseff1a3;
static double  rceff1a3;

static double  S10[3+1][3+1];
static double  S21[3+1][3+1];
static double  S32[3+1][3+1];
static double  S43[3+1][3+1];
static double  S54[3+1][3+1];
static double  S65[3+1][3+1];
static double  S76[3+1][3+1];
static double  S87[3+1][3+1];
static double  S97[3+1][3+1];
static double  S109[3+1][3+1];
static double  S127[3+1][3+1];

static void master_ForDynfunc1(void);

static double  Si01[3+1][3+1];
static double  Si12[3+1][3+1];
static double  Si23[3+1][3+1];
static double  Si34[3+1][3+1];
static double  Si45[3+1][3+1];
static double  Si56[3+1][3+1];
static double  Si67[3+1][3+1];
static double  Si78[3+1][3+1];
static double  Si79[3+1][3+1];
static double  Si910[3+1][3+1];
static double  Si712[3+1][3+1];

static void master_ForDynfunc2(void);

static double  SG10[3+1][3+1];
static double  SG20[3+1][3+1];
static double  SG30[3+1][3+1];
static double  SG40[3+1][3+1];
static double  SG50[3+1][3+1];
static double  SG60[3+1][3+1];
static double  SG70[3+1][3+1];
static double  SG80[3+1][3+1];
static double  SG90[3+1][3+1];
static double  SG100[3+1][3+1];
static double  SG110[3+1][3+1];
static double  SG120[3+1][3+1];
static double  SG130[3+1][3+1];

static void master_ForDynfunc3(void);

static double  v1[6+1];
static double  v2[6+1];
static double  v3[6+1];
static double  v4[6+1];
static double  v5[6+1];
static double  v6[6+1];
static double  v7[6+1];
static double  v8[6+1];
static double  v9[6+1];
static double  v10[6+1];
static double  v11[6+1];
static double  v12[6+1];
static double  v13[6+1];

static void master_ForDynfunc4(void);

static double  a0[6+1];
static double  a1[6+1];
static double  a2[6+1];
static double  a3[6+1];
static double  a4[6+1];
static double  a5[6+1];
static double  a6[6+1];
static double  a7[6+1];
static double  a8[6+1];
static double  a9[6+1];
static double  a10[6+1];
static double  a11[6+1];
static double  a12[6+1];
static double  a13[6+1];

static void master_ForDynfunc5(void);

static double  fnet1[6+1];
static double  fnet2[6+1];
static double  fnet3[6+1];
static double  fnet4[6+1];
static double  fnet5[6+1];
static double  fnet6[6+1];
static double  fnet7[6+1];
static double  fnet8[6+1];
static double  fnet9[6+1];
static double  fnet10[6+1];
static double  fnet12[6+1];

static double  fex1[6+1];
static double  fex2[6+1];
static double  fex3[6+1];
static double  fex4[6+1];
static double  fex5[6+1];
static double  fex6[6+1];
static double  fex7[6+1];
static double  fex9[6+1];
static double  fex10[6+1];
static double  fex12[6+1];

static void master_ForDynfunc6(void);

static double  f0[6+1];
static double  f1[6+1];
static double  f2[6+1];
static double  f3[6+1];
static double  f4[6+1];
static double  f5[6+1];
static double  f6[6+1];
static double  f7[6+1];
static double  f8[6+1];
static double  f9[6+1];
static double  f10[6+1];
static double  f12[6+1];

static double  fext0[6+1];
static double  fext1[6+1];
static double  fext2[6+1];
static double  fext3[6+1];
static double  fext4[6+1];
static double  fext5[6+1];
static double  fext6[6+1];
static double  fext7[6+1];
static double  fext9[6+1];
static double  fext10[6+1];
static double  fext12[6+1];

static void master_ForDynfunc7(void);

static double  qext[13+1];

static double  c[19+1];

static void masterfunc11(void);

static void masterfunc12(void);

static void masterfunc13(void);

static void masterfunc14(void);

static void masterfunc15(void);

static void masterfunc16(void);

static void masterfunc17(void);

static void masterfunc18(void);

static void masterfunc19(void);

static void masterfunc20(void);

static void masterfunc21(void);

static void masterfunc22(void);

static void masterfunc23(void);

static void masterfunc24(void);

static double  Jcc0[6+1][6+1];

static void masterfunc25(void);

static double  Jc0[6+1][6+1];
static double  Jc1[6+1][6+1];
static double  Jc2[6+1][6+1];
static double  Jc3[6+1][6+1];
static double  Jc4[6+1][6+1];
static double  Jc5[6+1][6+1];
static double  Jc6[6+1][6+1];
static double  Jc7[6+1][6+1];
static double  Jc8[6+1][6+1];
static double  Jc9[6+1][6+1];
static double  Jc10[6+1][6+1];
static double  Jc12[6+1][6+1];

static double  Fu11[6+1];
static double  Fu21[6+1];
static double  Fu22[6+1];
static double  Fu31[6+1];
static double  Fu32[6+1];
static double  Fu33[6+1];
static double  Fu41[6+1];
static double  Fu42[6+1];
static double  Fu43[6+1];
static double  Fu44[6+1];
static double  Fu51[6+1];
static double  Fu52[6+1];
static double  Fu53[6+1];
static double  Fu54[6+1];
static double  Fu55[6+1];
static double  Fu61[6+1];
static double  Fu62[6+1];
static double  Fu63[6+1];
static double  Fu64[6+1];
static double  Fu65[6+1];
static double  Fu66[6+1];
static double  Fu71[6+1];
static double  Fu72[6+1];
static double  Fu73[6+1];
static double  Fu74[6+1];
static double  Fu75[6+1];
static double  Fu76[6+1];
static double  Fu77[6+1];
static double  Fu91[6+1];
static double  Fu92[6+1];
static double  Fu93[6+1];
static double  Fu94[6+1];
static double  Fu95[6+1];
static double  Fu96[6+1];
static double  Fu97[6+1];
static double  Fu99[6+1];
static double  Fu101[6+1];
static double  Fu102[6+1];
static double  Fu103[6+1];
static double  Fu104[6+1];
static double  Fu105[6+1];
static double  Fu106[6+1];
static double  Fu107[6+1];
static double  Fu109[6+1];
static double  Fu1010[6+1];
static double  Fu121[6+1];
static double  Fu122[6+1];
static double  Fu123[6+1];
static double  Fu124[6+1];
static double  Fu125[6+1];
static double  Fu126[6+1];
static double  Fu127[6+1];
static double  Fu1212[6+1];

static double  K[13+1][6+1];

static void masterfunc26(void);

static double  H[13+1][13+1];

static void masterfunc27(void);

static double  vcross[3+1];

static double  uc[19+1];

static double  thdd[19+1];


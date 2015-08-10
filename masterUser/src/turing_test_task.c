/*============================================================================
==============================================================================
                      
                              turing_test_task.c
 
==============================================================================
Remarks:

      sekeleton to create the sample task

============================================================================*/

// system headers
#include "SL_system_headers.h"

/* SL includes */
#include "SL.h"
#include "SL_user.h"
#include "SL_tasks.h"
#include "SL_task_servo.h"
#include "SL_kinematics.h"
#include "SL_dynamics.h"
#include "SL_collect_data.h"
#include "SL_shared_memory.h"
#include "SL_filters.h"
#include "SL_man.h"
#include "time.h"

// file input output
#include <stdlib.h>
#include <stdio.h>
#include <time.h>



#ifdef WIN32	// Windows includes
#include <Windows.h>
#include <process.h>
#define sleep(x) Sleep(1000*x)
HANDLE hFile, handle, map;
#else			// POSIX includes
//#include <pthread.h>
#include <sys/mman.h>

#endif


/* defines */
#define  ARRAYLEN 	 10000
#define  LUTLEN 	 200

/* local variables */
static double start_time = 0.0;
static double freq0, freq1, freq2;
static double amp0, amp1, amp2;
static SL_DJstate  target[N_DOFS+1];
static int        use_invdyn     = TRUE;
static double		inertia_gain 				= 0.01; //0.425;
static double gainControl = 0.01;

static int k = 0; //index for Array read from txt. 
static double pos2DArray[3]; // (coeff0, coeff1, coeff2) : offset, poscoeff, velcoeff
static double reflexLut[200][200];   //reflex force lookup table



/* variables for filtering */
static Filter ff[N_CART+1];

#define NZEROS 4
#define NPOLES 4
#define GAIN   1.112983215e+06
static float xv[N_DOFS+1][NZEROS+1], yv[N_DOFS+1][NPOLES+1];
static float xa[N_DOFS+1][NZEROS+1], ya[N_DOFS+1][NPOLES+1];
static SL_DJstate  joint_filt_state[N_DOFS+1];


/* global functions */



/* local functions */
static int  init_turing_test_task(void);
static int  run_turing_test_task(void);
static int  change_turing_test_task(void);
static SL_DJstate	extra_joint_state_filter(int);

/*****************************************************************************
******************************************************************************
Function Name	: add_turing_test_task
Date		: Feb 1999
Remarks:

adds the task to the task menu

******************************************************************************
Paramters:  (i/o = input/output)

none

*****************************************************************************/
void
add_turing_test_task( void )

{
  int i, j;
  
  addTask("turing_test_task", init_turing_test_task, 
	  run_turing_test_task, change_turing_test_task);

}    

/*****************************************************************************
******************************************************************************
  Function Name	: init_turing_test_task
  Date		: Dec. 1997

  Remarks:

  initialization for task

******************************************************************************
  Paramters:  (i/o = input/output)

       none

 *****************************************************************************/

/* error statement 
void err_sys(const char* x) 
{ 
    perror(x); 
    exit(1); 
}
*/

static int 
init_turing_test_task(void)
{
  int j, i;
  int ans;
  static int firsttime = TRUE;

  // prepare going to the default posture
  bzero((char *)&(target[1]),N_DOFS*sizeof(target[1]));
  for (i=1; i<=N_DOFS; i++)
	target[i] = joint_default_state[i];

  // go to the target using inverse dynamics (ID)
  if (!go_target_wait_ID(target))
	return FALSE;


  
  if (firsttime){
    firsttime = FALSE;
    freq0 = 0.5; // frequency
    freq1 = 0.9; 
    freq2 = 1.4; 
    amp0  = 1.0/2; // amplitude
    amp1  = 3.0/2;
    amp2  = 6.0/2;
  }

  // prepare going to the default posture

/*
  bzero((char *)&(target[1]),N_DOFS*sizeof(target[1]));
  for (i=1; i<=N_DOFS; i++)
    target[i] = joint_default_state[i];
*/

 // read coefficient array from txt. (pos / vel / force)
  FILE *fp = fopen("regressionData/regressionCoeff.txt", "r"); 
  if (!fp) {
    fprintf(stderr, "Can't open file.\n");
    //exit(EXIT_FAILURE);
  }

  double temp;
  int p = 0;
 
    //read lines 
    const char s[2] = ",";
    char *token;
    int m;
    if(fp != NULL)
    {
        char line[100]; //10 is enough per line
        fgets(line, sizeof line, fp);
        
            token = strtok(line, s);
            for(m=0;m<3;m++)  // m: number of coeff
            {	
		
		printf("%f\t",atof(token));
		pos2DArray[m] = atof(token);
		token = strtok(NULL,s);	

/*
                if(m==0)
                {   
		    //printf("%i\t", m);
                   
		    pos2DArray[0] = atof(token);
                } else {
	            token = strtok(NULL,s);
		    //printf("%i\t", m);
                    printf("%f\n",atof(token));
		    pos2DArray[1] = atof(token);

                }       
*/
            }
	
        
        fclose(fp);
    }

/*
  int l;
  for (l = 0; l < ARRAYLEN ; l++) {
      printf("pos2dArray %i,  %f\n", l, pos2DArray[l][0]);
  }
*/
printf("a0:%f, a1:%f, a2:%f\n", pos2DArray[0], pos2DArray[1],pos2DArray[2]);  //this is for linear regression.





 /* ======= loading loop table ========== */
 // input file option to ask
  // list files in directory

    DIR *d;
    struct dirent *dir;
    d = opendir(“lut_table/.”);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }

  // get user input 
   char file_selected_vars[80];

   printf ("Enter a file name to open: ");
   scanf ("%s", file_selected_vars);
   
   
  // read position array from txt.
  char path[100] = "lut_table/";
  strcat (path, file_lut_table);
  FILE *fp = fopen(path, "r"); 
  if (!fp) {
    fprintf(stderr, "Can't open file.\n");
    //exit(EXIT_FAILURE);
  }


  double temp;
  int p = 0;
 

//******* write a new code for line reading, delimeter ‘,’ and 200 per line. 
    //reflexLut

    //read lines 
    const char s[2] = ",";
    char *token;
    int m;
    if(fp != NULL)
    {
        char line[1600]; // per line
        while(fgets(line, sizeof line, fp) != NULL)
        {
            token = strtok(line, s);
            for(m=0;m<200;m++)
            {
                if(m==0)
                {   
                    printf("%s\t",token);
                    token = strtok(NULL,s);
		    pos2DArray[p][0] = atof(token);
                } else {
                    printf("%f\n",atof(token));
		    pos2DArray[p][1] = atof(token);
                }       
            }
	p++;
        }
        fclose(fp);
    }



 /* ========end of look up table loading =============*/


  // go to the target using inverse dynamics (ID)
  if (!go_target_wait_ID(target)) 
    return FALSE;

  
  	// zero the filters
	for (i=1; i<=N_CART; ++i)
	{
		ff[i].cutoff = 40;
		for (j=0; j<=FILTER_ORDER; ++j)
		{
			ff[i].raw[j] = ff[i].filt[j] = 0;
		}
	}

	// initialize filter variables
	for(i=1; i<=N_DOFS; i++)
	{
		for(j=1; j<=NZEROS; j++)
		{
			xv[i][j]=0.0;
			xa[i][j]=0.0;
		}
		for(j=1; j<=NPOLES; j++)
		{
			yv[i][j]=0.0;
			ya[i][j]=0.0;
		}
	}
  
  
  
  // ready to go
  ans = 999;
  while (ans == 999) {
    if (!get_int("Enter 1 to start or anthing else to abort ...",ans,&ans))
      return FALSE;
  }
  
  // only go when user really types the right thing
  if (ans != 1) 
    return FALSE;

  

  start_time = task_servo_time;
  printf("start time = %.3f, task_servo_time = %.3f\n", 
	 start_time, task_servo_time);


  // start data collection
  scd();
  printf("Data collection started\n");

  return TRUE;
}

/*****************************************************************************
******************************************************************************
  Function Name	: run_turing_test_task
  Date		: Dec. 1997

  Remarks:

  run the task from the task servo: REAL TIME requirements!

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
static int 
run_turing_test_task(void)
{
  int j, i;

  double task_time;
  double omega0, omega1, omega2, torque;
  double posCoef, velCoef, loadCoef, gravity;
 //double gainControl;

 

/*
posCoef = -3.734;
velCoef = 0.713;
loadCoef = 0.921;
*/
/*
posCoef = -1.4703;
velCoef = -0.1102;
loadCoef = 1.1288;
*/
gravity = 8.0;
loadCoef = 0.921;

task_time = task_servo_time - start_time;
  
  // some extra filtering for better inertial compensation (inherited from Michael Mistry's program)
	for (i=1; i<=N_DOFS; ++i)
	{
		joint_filt_state[i]					= extra_joint_state_filter(i);
	}

//
//joint_des_state[R_EB].th   = joint_state[R_EB].th;
//joint_des_state[R_EB].thd  = joint_state[R_EB].thd;
//joint_des_state[R_EB].thdd = joint_state[R_EB].thdd;
//
//
//omega0 = joint_state[R_EB].th;  
//omega1 = joint_state[R_EB].thd;
//torque = joint_state[R_EB].load;

for (i=1; i<=N_DOFS; ++i)
		{
           // gainControl = 0.1;
			// The one that is very noisy is the joint acceleration sensing, that's why we are using the filtered version of it
			// (joint_filt_state[i].thdd), instead of the unfiltered one (joint_state[i].thdd). Joint position (joint_state[i].th) and joint velocity (joint_state[i].thd)
			// on the other hand are not so noisy, so we are using the original (unfiltered) one.
			if (i == R_EB)
			{
				joint_des_state[i].th   = joint_state[i].th;
				joint_des_state[i].thd  = joint_state[i].thd;
                // joint_des_state[i].thdd  = joint_state[i].thdd; // use filter
                 joint_des_state[i].thdd = joint_filt_state[i].thdd * inertia_gain;	// multiplication by inertia gain here is maybe for reducing the risk of the system becoming unstable???
        
                omega0=joint_state[i].th;
                omega1=joint_state[i].thd;
				//joint_des_state[i].thdd = joint_filt_state[i].thdd * inertia_gain;	// multiplication by inertia gain here is maybe for reducing the risk of the system becoming unstable???
				//joint_des_state[i].uff  = 0.0;
                //joint_des_state[i].uff = (pos2DArray[0]+ pos2DArray[1]*omega0 + pos2DArray[2]*omega1)*gainControl ; // + (loadCoef*torque)*1.0; //+ gravity;   // no gravity since it should have been taken care in playback - record stage. 

			}
			else
			{
				joint_des_state[i].th   = joint_des_state[i].th;	// don't change the joint_des_state;
				joint_des_state[i].thd  = 0.0;
				joint_des_state[i].thdd = 0.0;
				joint_des_state[i].uff  = 0.0;
			}
		}


//goal: find a coefficients posCoef, velCoef, loadCoef really fast!!
// regress on ufb and *add gravity* 


//joint_des_state[R_EB].uff =(pos2DArray[0]+ pos2DArray[1]*omega0 + pos2DArray[2]*omega1)*0.1 + gravity ; // + (loadCoef*torque)*1.0; //+ gravity; 
//joint_des_state[R_EB].uff = (pos2DArray[0]+ pos2DArray[1]*omega0 + pos2DArray[2]*omega1)*gainControl ; // + (loadCoef*torque)*1.0; //+ gravity;   // no gravity since it should have been taken care in playback - record stage. 

//joint_des_state[R_EB].uff = tmpdata; // torque
//joint_des_state[R_EB].uff = gravity;//(posCoef*omega0 + velCoef*omega1 + loadCoef*torque)*(0.1) + gravity;
//joint_des_state[R_EB].uff = (posCoef*omega0 + velCoef*omega1 + loadCoef*torque)*0.1;

  // compute inverse dynamics torques
  //SL_InverseDynamics(joint_state, joint_des_state, endeff);
  SL_InvDynNE(joint_state,joint_des_state,endeff,&base_state,&base_orient);
 // uff += may not be correct way (too slow?) But we need that += to make the arm not drop. 
 // joint_des_state[R_EB].uff +=  (pos2DArray[0]+ pos2DArray[1]*omega0 + pos2DArray[2]*omega1)*gainControl *(-1); // + (loadCoef*torque)*1.0; //+ gravity;   // no gravity since it should have been taken care in playback - record stage. 

   joint_des_state[R_EB].uff +=  lut_mapping(omega0, omega1)*gainControl *(-1); // (pos and vel)

  return TRUE;
}


/*****************************************************************************
******************************************************************************
  Function Name	: extra_joint_state_filter
  Date			: Jan 2012

  Remarks:

  does some extra polynomial filtering on the velocities and 
  accelerations

******************************************************************************
  Parameters:  (i/o = input/output)

  \param[in]   i: DOF to be filtered

 *****************************************************************************/
static SL_DJstate 
extra_joint_state_filter(int i)
{
	SL_DJstate  filtered_output[N_DOFS+1];

    /* position is not filtered */
    filtered_output[i].th = joint_state[i].th;
  
    /* velocity filtering */
    xv[i][0] = xv[i][1]; xv[i][1] = xv[i][2]; xv[i][2] = xv[i][3]; xv[i][3] = xv[i][4]; 
    xv[i][4] = joint_state[i].thd / GAIN;
    yv[i][0] = yv[i][1]; yv[i][1] = yv[i][2]; yv[i][2] = yv[i][3]; yv[i][3] = yv[i][4]; 
    yv[i][4] =   (xv[i][0] + xv[i][4]) + 4 * (xv[i][1] + xv[i][3]) + 6 * xv[i][2]
               + ( -0.8485559993 * yv[i][0]) + (  3.5335352195 * yv[i][1])
               + ( -5.5208191366 * yv[i][2]) + (  3.8358255406 * yv[i][3]);
    filtered_output[i].thd = yv[i][4];

    /* acceleration filtering */
    xa[i][0] = xa[i][1]; xa[i][1] = xa[i][2]; xa[i][2] = xa[i][3]; xa[i][3] = xa[i][4]; 
    xa[i][4] = joint_state[i].thdd / GAIN;
    ya[i][0] = ya[i][1]; ya[i][1] = ya[i][2]; ya[i][2] = ya[i][3]; ya[i][3] = ya[i][4]; 
    ya[i][4] =   (xa[i][0] + xa[i][4]) + 4 * (xa[i][1] + xa[i][3]) + 6 * xa[i][2]
               + ( -0.8485559993 * ya[i][0]) + (  3.5335352195 * ya[i][1])
               + ( -5.5208191366 * ya[i][2]) + (  3.8358255406 * ya[i][3]);
    filtered_output[i].thdd = ya[i][4];
    
    return filtered_output[i];
}


/*****************************************************************************
******************************************************************************
  Function Name	: change_turing_test_task
  Date		: Dec. 1997

  Remarks:

  changes the task parameters

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
//static int 
//change_turing_test_task(void)
//{
//  int    ivar;
//  double dvar;
//
//  get_int("This is how to enter an integer variable",ivar,&ivar);
//  get_double("This is how to enter a double variable",dvar,&dvar);
//
//  return TRUE;
//
//}


/*****************************************************************************
******************************************************************************
  Function Name	: look up table mapping 
  Date			: Aug 2015

  Remarks: Eric Won Joon Sohn, wonjsohn@gmail.com

  does continuous data of pos and vel mapping to discrete lookup table of reflex

******************************************************************************
  Parameters:  (i: pos, vel, o: reflex force)

 *****************************************************************************/
static double 
lut_mapping(double pos, double vel)
{

    int n;
    int m;
    n=floor(pos*100-30);  //0.3 to 2.3 -> 1 to 200
    m=floor(vel*20+100);  //-5 to 5   -> 1 to 200
    
    //safe guard
    if (n<1 || n >200) { 
	n = 100; 
	printf(“Index n out of range %i\t”, n);
    }  // pick 
    if (m<1 || m >200) {
	m = 100;
	printf(“Index m out of range %i\t”, m);
    }
    return reflexLut[n][m];
}




static int 
change_turing_test_task(void)
{
  int    ivar;
  double dvar;
      
        get_double("Gain Control",gainControl,&dvar);
        if ((dvar >= 0.0) && (dvar <= 2.0))
        {
                gainControl                                          = dvar;
        }

  return TRUE;

}



/*============================================================================
==============================================================================
                 	 
                          	turing_playback_task.c
 
==============================================================================
Remarks:

  	Generates an analoge pulse out of the physical oscilloscope for
  	sincronization purposes

============================================================================*/

// system headers
#include "SL_system_headers.h"

// SL includes
#include "SL.h"
#include "SL_user.h"
#include "SL_tasks.h"
#include "SL_task_servo.h"
#include "SL_kinematics.h"
#include "SL_dynamics.h"
#include "SL_collect_data.h"
#include "SL_shared_memory.h"
#include "SL_man.h"
#include "SL_oscilloscope.h" //Oscilloscope library (physical and virtual)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <dirent.h>  // to list files in dir


// defines

#define  ARRAYLEN 	 40000

// local variables
static double start_time = 0.0;
static double emgTrig = 0.0;
static int dataFlag;
static SL_DJstate  target[N_DOFS+1];
static double this_time = 0.00, last_time = 0.00, mov_time = 0.00, some_time = 0.00;
static double start_elbow_angle = 1.571; //1.571rad = 90deg
static int direction = 0, udFlag = 0;
static int ivar = 0;


static int k = 0; //index for posArray read from txt. 

static double posArray[ARRAYLEN] ={ 0.0, 0.05, 0.1, 0.15, 0.2, 0.25, 0.30, 0.35, 0.4, 0.45 };// for test only
static double pos2DArray[ARRAYLEN][2]; // (time, pos) 


// global functions

// local functions
static int  init_turing_playback_task(void);
static int  run_turing_playback_task(void);
static int  change_turing_playback_task(void);


/*****************************************************************************
******************************************************************************
Function Name    : add_turing_playback_task
Date   	 : June 2014
Remarks:

adds the task to the task menu

******************************************************************************
Paramters:  (i/o = input/output)

none

*****************************************************************************/
void
add_turing_playback_task( void )

{
  int i, j;
 
  addTask("Turing_playback_task", init_turing_playback_task,
	   run_turing_playback_task, change_turing_playback_task);

}    

/*****************************************************************************
******************************************************************************
  Function Name    : init_turing_playback_task
  Date   	 : June 2014

  Remarks:

  initialization for task

******************************************************************************
  Paramters:  (i/o = input/output)

   	none

 *****************************************************************************/
static int
init_turing_playback_task(void)
{
  int j, i;
  int ans;
  char string[100];
  static int firsttime = TRUE;
  dataFlag = 0;

  if (firsttime){
    firsttime = FALSE;
    //freq = 0.1; // frequency
    //amp  = 0.5; // amplitude
  }


  // prepare going to the default posture
  bzero((char *)&(target[1]),N_DOFS*sizeof(target[1]));
  for (i=1; i<=N_DOFS; i++)
	target[i] = joint_default_state[i];

  // go to the target using inverse dynamics (ID)
  if (!go_target_wait_ID(target))
	return FALSE;

  // add trigger to data collection
  sprintf(string,"emgTrig");
  addVarToCollect((char *)&(emgTrig),string,"V", DOUBLE,TRUE);

  /* add trigger signal to virtual oscilloscope:	 
  add the variable name to prog/masterUser/prefs/task_default.osc*/
  updateOscVars();
 
  // clear start data collection flag
 //dataFlag = 0;



 // input file option to ask
  // list files in directory

    DIR *d;
    struct dirent *dir;
    d = opendir("selected_vars/.");
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
  char path[100] = "selected_vars/";
  strcat (path, file_selected_vars);
  FILE *fp = fopen(path, "r"); 
  if (!fp) {
    fprintf(stderr, "Can't open file.\n");
    //exit(EXIT_FAILURE);
  }
 /*
  int *a,temp,count=0;
  a=(int *)malloc(10*sizeof(int));
  temp=fgetc(fp);
  while(!feof(fp))
  {
    if(temp!=44&&temp!=10&&temp!=32)
    {
      count++;
      a[count]=temp;
      printf("%c\n", a[count]);
    }
    temp=fgetc(fp);
  }
    fclose(fp);
 */


 // read the number of lines in the text file. 
/*
  char line[1024];
  int NumberOfLines = 0;
  while( fgets(line,sizeof(line),fp) != NULL)
     NumberOfLines++;
  printf("the number of lines : %i\n", NumberOfLines);
*/

  double temp;
  int p = 0;
 
    //read lines 
    const char s[2] = ",";
    char *token;
    int m;
    if(fp != NULL)
    {
        char line[100]; //10 is enough per line
        while(fgets(line, sizeof line, fp) != NULL)
        {
            token = strtok(line, s);
            for(m=0;m<2;m++)
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

/*
  while (!feof(fp)){ //repeat until end of file
         if (p>ARRAYLEN) { p = ARRAYLEN; break;}
		
         fscanf(fp,"%f",&temp);
   	 pos2DArray[p][1] = temp;  // time
	 fscanf(fp,"%f",&temp);
         pos2DArray[p][2] = temp;  // pos
	p++;	 
        printf("p is...%i\n", p); 
  }
  fclose(fp);
  */
  
  // print the trajectory
  int l;
  for (l = 0; l < ARRAYLEN ; l++) {
  //    printf("pos2dArray %i,  %f\n", l, pos2DArray[l][0]);
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

  printf("Input var = %i\n",ivar);

  // start data collection
  //scd();
  //printf("Data collection started\n");
  return TRUE;
}

/*****************************************************************************
******************************************************************************
  Function Name    : run_turing_playback_task
  Date   	 : June 2014

  Remarks:

  run the task from the task servo: REAL TIME requirements!

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
static int
run_turing_playback_task(void)
{

  static int firsttime = TRUE;
  int j, i, dof;
  double task_time;
  double wait_time = 5;
  double trigg_start, trigg_dur;
  //double start_elbow_angle;
  double def_elbow_angle = 1.571; //1.571rad = 90deg
  double shift = 0.2; //time shift for position
  double perturbAmp = 0.3491; //0.3491rad = 20deg | 0.5236 = 30deg
  double b = 43.8; // 31.9 for perturbAmp = 30deg;
 
  /////////////////////////////////////////////////////////////////////////////////////////////
  // RANDOMIZATION
  //srand(time(NULL)); //initialize random number generator
  // for random perturbation: perturb_satart_time = rand() %10 + 5;
  /////////////////////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////////////////////
  // trigger parameters
  trigg_start = 0.001; //trigger start time (s)
  //trigg_dur = 0.5;  // duration of the pulse (s)
  /////////////////////////////////////////////////////////////////////////////////////////////

  // Task parameters
  task_time = task_servo_time - start_time;

 // Tirgger event for starting EMG recording ///////////////////////////////////////////////
  if ((task_time >= trigg_start) && (dataFlag == 0 ))
  {
	setOsc(d2a_cr,75.00);
	emgTrig = 5.0;
	dataFlag = 1;
	printf("EMG Data collection started\n");
	scd(); // start data collection; manually input stopcd and then saveData from console
  }
  else
  {
	if (task_time >= trigg_start+trigg_dur)
	{
	setOsc(d2a_cr,50.00);
	emgTrig = 0.0;
	}
   }////////////////////////////////////////////////////////////////////////////////////////

  // osciallates one DOF
  //dof = 4; // degree of freedom to rotate
  //for (i=dof; i<=dof; ++i) 
  //{
/*
        //move to desired_pos_f
	if(joint_state[i].th <= def_elbow_angle && udFlag == 0)
	{
		this_time = task_time - last_time;
		some_time = task_time;
		//direction = 0;

		if (this_time >= wait_time)
		{
        		direction = 1;
			start_elbow_angle = def_elbow_angle;
			setOsc(d2a_cr,75.00);
			emgTrig = 5.0;
			udFlag = 1;
			last_time = task_time;
		}
	}
	//move to desired_pos_i
	if(joint_state[i].th >= def_elbow_angle+perturbAmp && udFlag == 1)
	{
		setOsc(d2a_cr,50.00);
		emgTrig = 0.0;
		this_time = task_time - last_time;
		some_time = task_time;
		//direction = 0;

		if (this_time >= wait_time)
		{
        		direction = -1;
			start_elbow_angle = def_elbow_angle + perturbAmp;
			last_time = task_time;
			udFlag = 0;
		}
	}

	mov_time = task_time - some_time;

	target[i].th = start_elbow_angle + direction*perturbAmp/(1 + exp(-b*(mov_time-shift)));
	target[i].thd = direction*perturbAmp*b*exp(-b*(mov_time-shift))/pow(1+exp(-b*(mov_time-shift)), 2);
	target[i].thdd = direction*perturbAmp*(pow(b,2)*exp(-b*(mov_time-shift))/pow(1+exp(-b*(mov_time-shift)),2))*(2*exp(-b*(mov_time-shift))/(1+exp(-b*(mov_time-shift)))-1);
*/

	if (ivar == 1)
	{
		if (firsttime == TRUE)
		{
			direction = -1;
			firsttime = FALSE;
		}
	/*
        	if (this_time >= wait_time)
		{
			direction = -direction;
			start_elbow_angle = joint_state[i].th;
			last_time = task_time;
			some_time = task_time;
			if (direction > 0) //if it's returning to defaul position
			{
				setOsc(d2a_cr,75.00);
				//emgTrig = 5.0;
			}
			else
			{
				setOsc(d2a_cr,50.00);
				//emgTrig = 0.0;
  				ivar = 0;
			}
		}
	*/
	}

		this_time = task_time - last_time;
		mov_time = task_time - some_time;

		/*
		target[i].th = start_elbow_angle + direction*perturbAmp/(1 + exp(-b*(mov_time-shift)));
		target[i].thd = direction*perturbAmp*b*exp(-b*(mov_time-shift))/pow(1+exp(-b*(mov_time-shift)), 2);
		target[i].thdd = direction*perturbAmp*(pow(b,2)*exp(-b*(mov_time-shift))/pow(1+exp(-b*(mov_time-shift)),2))*(2*exp(-b*(mov_time-shift))/(1+exp(-b*(mov_time-shift)))-1);
*/



   // position-servo  
   /* Frequency of playback:
     if 1point/s =>  k = (int)(task_time); 
     if 10 points/s => k = (int)(task_time*10);
     if 420 points /s => k = (int)(task_time*420);
   */
   k = (int)(420*task_time);  //420 Hz sampling
  
    
   if (k > ARRAYLEN-1){
 	k = ARRAYLEN-1;  // to prevent index out of Array 
   }
  // printf("task_time = %i, %f\n",k, posArray[k]);
   //printf("task_time = %i, %f\n",k, pos2DArray[k][1]);
   target[R_EB].th = pos2DArray[k][1];
   

 // }

  // the following variables need to be assigned
  for (i=1; i<=N_DOFS; ++i) 
  {
	joint_des_state[i].th   = target[i].th;
	joint_des_state[i].thd  = target[i].thd;
	joint_des_state[i].thdd = target[i].thdd;
	//joint_des_state[i].uff  = 0.0;
  }



  // compute inverse dynamics torques
  SL_InvDynNE(joint_state,joint_des_state,endeff,&base_state,&base_orient);
  return TRUE;
}

/*****************************************************************************
******************************************************************************
  Function Name    : change_turing_playback_task
  Date   	 : June 2014

  Remarks:

  changes the task parameters

******************************************************************************
  Paramters:  (i/o = input/output)

  none

 *****************************************************************************/
static int
change_turing_playback_task(void)
{

  //int	ivar;
  //double dvar;


  get_int("This is how to enter an integer variable",ivar,&ivar);
  printf("Input var = %i\n",ivar);
  
  //get_double("This is how to enter a double variable",dvar,&dvar);

  return TRUE;

}



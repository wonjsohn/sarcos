/*!=============================================================================
  ==============================================================================

  \file    ajc_change_register.c

  \author  Stefan Schaal
  \date    Sept. 2011

  ==============================================================================
  \remarks

  A quick interface to change ajc registers on-line. I put this into  different
  files as curses.h clashes with utilities.h

  ============================================================================*/

// header files
#include "analogy/analogy.h"
#include "ajc.h"
#include "ni6259_interface.h"
#include "curses.h"
#include "SL_unix_common.h"
#include "SL_rt_mutex.h"


/*!*****************************************************************************
*******************************************************************************
\note  change_register
\date  Sept. 2011

\remarks 

a curses implementation of a register change

*******************************************************************************
Function Parameters: [in]=input,[out]=output

\param[in]  jID: joint ID
\param[in]  rID: register ID

******************************************************************************/
void
change_register(int jID, int rID) {

  int i;
  unsigned int ival;
  char string[100],istring[10];;
  int n_istring = 0;
  extern char joint_names[][20];
  FILE *in, *out;

  // initialized the curses library
  in  = fopen("/dev/tty","r");
  out = fopen("/dev/tty","w");
  newterm(NULL,out,in);  // need newterm to avoid that xterm is messed up afterwards

  // enable keyboard mapping
  keypad(stdscr, TRUE);

  // tell curses not to do NL->CR/NL on output 
  nonl();

  // enable echo
  echo();

  // some comments
  addstr("Interactive changing of register -- be careful! Use >q< to abort\n");
  sprintf(string,"You are change joint %s\n",joint_names[jID]);
  addstr(string);
  sprintf(string,"You are change register %s\n\n",ajcRegisterNames[rID]);
  addstr(string);
    
  ival = joints[jID].registers[rID+1];
  sprintf(string,"%d",ival);
  addstr(string);
  move(4,0);

  // interactive loop
  while (TRUE) {

    int c = getch();     // get next keystroke

    // process the keystroke
    if (c=='q')
      break;

    if (c == KEY_UP) {

      if (ival < 4095)
	++ival;

      sprintf(string,"%d",ival);
      move(4,0);
      addstr(string);
      move(4,0);

    } else if (c==KEY_DOWN) {

      if (ival > 0)
	--ival;

      sprintf(string,"%d",ival);
      move(4,0);
      addstr(string);
      move(4,0);

    } else if (c == 13) { // return key

      istring[n_istring] = '\0';
      sscanf(istring,"%d",&ival);
      sprintf(string,"%d              ",ival);
      move(4,0);
      addstr(string);
      move(4,0);
      n_istring = 0;

    } else if (n_istring < 4)
      istring[n_istring++] = c;

    // update the register
    sl_rt_mutex_lock(&mutex1);

    if (!Ajc_WriteRegister ( 1, (&jID)-1, rID-REGISTERSTART, (&ival)-1 )) {
      printf("Error in Joint_Initialize: joint=%d, reg=%d, value=%d\n",jID,rID-REGISTERSTART,ival);
      sl_rt_mutex_unlock(&mutex1);
      break;
    } else {
      joints[jID].registers[rID+1] = ival;
    }

    sl_rt_mutex_unlock(&mutex1);

    
  }

  nl();
  endwin();
  fclose(in);
  fclose(out);

}



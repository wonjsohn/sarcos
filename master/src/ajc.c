/*!=============================================================================
  ==============================================================================

  \file    ajc.c

  \author  Stefan Schaal
  \date    Feb. 2010

  ==============================================================================
  \remarks

  APIs for communicating with the Sarocs AJC cards, based on Xenomai Analogy
  using a NI6259 DAQ board. All communication is done through the digitial I/O
  port of the NI6259. We use subdevice #02 on the NI6259, which is 32 bit wide.
  The pin assignment is:

  |  00 | data
  |  01 | data
  |  02 | data
  |  03 | data
  |  04 | data
  |  05 | data
  |  06 | data
  |  07 | data
  |  08 | data
  |  09 | data
  |  10 | data
  |  11 | data
  |  12 | data
  |  13 | data
  |  14 | data
  |  15 | data
  |  16 | not used  (not used as the pin requires a BNC conncector for access)
  |  17 | data strobe
  |  18 | read/write
  |  19 | address strobe
  |  20 | not used
  |  21 | not used
  |  22 | not used
  |  23 | not used
  |  24 | not used
  |  25 | not used
  |  26 | not used
  |  27 | not used
  |  28 | not used
  |  29 | not used
  |  30 | not used
  |  31 | not used

  ============================================================================*/

// header files
#include "SL_system_headers.h"
#include "SL.h"
#include "SL_user.h"
#include "SL_man.h"
#include "utility.h"
#include "ajc.h"
#include "analogy/analogy.h"
#include "ni6259_interface.h"
#include "SL_unix_common.h"
#include "SL_rt_mutex.h"

#define  DEBUG FALSE  // enable massive debugging


// Local Definitions
#define AJC_CONFIG_FILE   "Ajc.cf"
#define AJC_REGISTER_FILE "AjcRegisters.cf"

// card status values
#define CardStatusEOC     1
#define CardStatusSwitch  2
#define CardStatusRelay   4
#define CardStatusError   8

// Pump information register. This register is found at slot 0, address 1
#define PumpResetBit         0
#define PumpPressureBit      1
#define PumpMotorBit         2
#define PumpPressureHighBit  3
#define PumpOnBit            4
#define PumpRelaysEnabledBit 5
#define PumpConnectedBit     6

// delays during AJC interaction
#define DELAY_NS 10000

// Local Type Declarations.

// This enumeration is to define the Card Addresses of certain functions.
typedef enum  {  
  ajcCARDID = 0,          // Address for the card ID.
  ajcADBUSY,              // A/D status register.
  ajcLOCALCONVERT,        // Cause a local (one card) data conversion cycle.
  ajcMUXSELECT,           // Select the input channel.
  ajcENCODERLSB = 32,     // Low 4 bits of encoder data.
  ajcENCODERMSB = 33,     // High 16 bits of encoder data.
  ajcWORLDMUXSELECT = 60, // Global select of input channel.
  ajcWORLDCONVERT = 61    // Global conversion cycle.

} CardAddress;

// This structure defines information about a register.
typedef struct  {
  unsigned short  address;       // The card address for the register.
  AjcValue        initial;       // The initial value written (on all cards).
  Boolean         reconfigured;  // True if the value from memory is sent upon
  // system reconfiguration or False if the initial value should
  // be resent.
} RegisterInfo;

// This structure allows translations from AjcChannel ID to the actual port used.
typedef int  ChannelInfo;


// Local Function Prototypes


// Local Variable Declarations.
static int   bus_controller_slot = 0;

// Global Variable Declaration
Joint joints[N_DOFS+1];

//  This data structure maps the AjcRegister enumeration to the actual
//  addresses used on the cards.
static RegisterInfo registerInfo [ RegisterCount ] =
  {
    { 6,  412,  TRUE },
    { 5,  0,    TRUE },
    { 14, 0,    TRUE },
    { 13, 0,    TRUE },
    { 15, 0,    TRUE },
    { 7,  0,    TRUE },
    { 10, 0,    TRUE },
    { 23, 0,    TRUE },
    { 24, 0,    TRUE },
    { 31, 0,    TRUE },
    { 30, 0,    TRUE },
    { 25, 0,    TRUE },
    { 29, 2047, TRUE },
    { 11, 0,    TRUE },
    { 9,  0,    TRUE },
    { 12, 0,    TRUE },
    { 8,  2047, TRUE },
    { 26, 2047, TRUE },
    { 27, 2047, TRUE },
    { 28, 2047, TRUE }
  };


// This data structure maps the AjcChannel enumeration to the actual
// addresses used on the cards.
static ChannelInfo channelInfo [ ChannelCount ] =
  {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 14, 15, 255, 255
  };

// names of registers
char ajcRegisterNames[][40]= {
  {"PositionCrossGain"},
  {"TorqueCrossGain"},
  {"PositionErrorGain"},
  {"VelocityErrorGain"},                 
  {"TorqueErrorGain"},                   
  {"PlusVelocityGain"},                  
  {"ActPosGainStage1"},                  
  {"ActPosBiasStage1"},                  
  {"ActPosGainStage2"},                  
  {"ActPosBiasStage2"},                  
  {"ActTorqueGain"},                     
  {"ActTorqueBiasFine"},                 
  {"ActTorqueBiasCourse"},               
  {"TapGain"},                           
  {"TapThreshold"},                      
  {"ValveGain"},                         
  {"ValveCommand"},                      
  {"GravityCompensation"},               
  {"DesiredPositionCommand"},            
  {"DesiredTorqueCommand"}
};

static int ajc_initialized = FALSE;

// local functions
static int  Interface_Read ( AjcSlot s, AjcAddress a, AjcValue *v );
static void Interface_StartConvert ( AjcChannel channel );
static int  Interface_WaitConvert(void);
static int  Interface_Probe ( AjcSlot s );
static void Interface_Write( AjcSlot s, AjcAddress a, AjcValue v );
static int  Joint_Initialize (int j );
static int  Joints_Validate ( void );
static int  read_ajc_config(char *fname, Joint *jts);
static int  read_ajc_registers(char *fname, Joint *jts);
static void Ajc_DebugWrite (void);
static void Ajc_DebugRead (void);
static int  update_bit_string(int value, int mask, int bits);
static int  Joint_Defaults (void);
static void dither_me (void);


// global functions
int  Ajc_WriteRegister(int count, int *js, AjcRegister reg, AjcValue *vl );


/*!*****************************************************************************
*******************************************************************************
\note  Ajc_Initialize
\date  Feb. 2010

\remarks 

initialize all necessary information for the AJC communication

*******************************************************************************
Function Parameters: [in]=input,[out]=output

none

******************************************************************************/
int
Ajc_Initialize (void)  {

  int                     i, j, k;
  AjcInterfaceStatus      status;

  if (ajc_initialized)
    return TRUE;

  // initialize DAQ board
  printf("Initialize NI6259 ... ");
  if (!init_NI6259(FALSE))
    return FALSE;
  printf("done.\n");

  // initialize each joint
  bzero((void *)joints,sizeof(Joint)*(N_DOFS+1));
  read_ajc_config(AJC_CONFIG_FILE,joints);

  // read configuration files
  printf("Reading register file %s ... ",AJC_REGISTER_FILE);
  if (!read_ajc_registers(AJC_REGISTER_FILE,joints)) {
    printf("Error reading %s\n",AJC_REGISTER_FILE);
    return FALSE;
  }
  printf("done.\n");

  // get the status of the communication interface
  printf("Checking the pump status ... ");
  if (!Ajc_InterfaceStatus ( &status )) {
    printf("Cannot obtain AJC Interface status.\n");
    return FALSE;
  }

#if PRESSURECHECK
  if ( status.pumpPressureHigh ) {
    printf("Error retrieving interface status.\n");
    return FALSE;
  }

  if ( status.overrideBits & AjcOverrideCommand ) {
    printf("Cannot initialize with computer pump override.\n");
    return FALSE;
  }
#endif
  printf("done.\n");

  // validate each joint
  printf("Validating joints ... ");
  if (!Joints_Validate ())
    return FALSE;
  printf("done.\n");

  // Do a conversion on each interface to fix "first conversion" problem.
  if (!Interface_ConvertAndWait ()) {
    printf("Cannot initialize AJC cards\n");
    getchar();
    return FALSE;
  }

  // set default values to the cards.
  printf("Initializing joints ... ");
  Joint_Defaults();
  for (j=1; j<=N_DOFS; ++j) {
    if ( joints[ j ].active )	{
      if (!Joint_Initialize(j)) {
	printf("Failed initializatin joint %s.\n", joints[j].name );
      }
    }
  }
  printf("done.\n");

  // add to man
  addToMan("ajc_read","Reads value form Ajc card",Ajc_DebugRead);
  addToMan("ajc_write","Writes value to Ajc card",Ajc_DebugWrite);
  addToMan("dither","Dithers a valve",dither_me);

  // all done
  ajc_initialized = TRUE;


  return TRUE;
}


/*!*****************************************************************************
*******************************************************************************
\note  Ajc_InterfaceRead
\date  Feb 2010
\remarks 

reads the data (low 16 bits) from DIO


*******************************************************************************
Function Parameters: [in]=input,[out]=output

\param[out]     value: 16 bit value to read

******************************************************************************/
int
Ajc_InterfaceRead ( AjcValue *value ) {

  if (!ajc_initialized)
    return FALSE;

  dio16_NI6259_read(ajcDATAMASK, (int *) value) ;

  return TRUE;

} 

/*!*****************************************************************************
*******************************************************************************
\note  Interface_Read
\date  Feb 2010
\remarks 

- Assert the control lines to read the value.
- Write the combined address/slot to the output port. Set the
Read / Write line low (write).
- Strobe the Address Latch Enable. Write all logical
``ones'' to the I/O port, which sets all lines to input. Set the
- Read / Write line high (read). Set Data Strobe low (enable data).
- Read the contents of the I/O port and store the data into the location
given. Set Data Strobe high (inhibit data).

Note that the I/O direction
is left all logic `ones' and the card is left in a `read' situation to
protect the cards from logic spikes on data enable lines.

reads the data (low 16 bits) from DIO

*******************************************************************************
Function Parameters: [in]=input,[out]=output

\param[in]     s: Ajc Slot to read from
\param[in]     a: address to read from
\param[out]    v: value of data

******************************************************************************/
static int
Interface_Read ( AjcSlot s, AjcAddress a, AjcValue *v ) {

  AjcValue   vt;
  int        ii;


  // Set the READ/WRITE line LOW (write)
  dio32_NI6259_write(ajcCTRLMASK, ajcADDRESSLATCHENABLE | ajcDATASTROBE);
  if (DEBUG) {
    printf("RW=0 ADDR=1 STROBE=1: write mode ");getchar();
  }

  // Write the address out to the backplane
  dio32_NI6259_write(ajcDATAMASK,(a << 8) | s);
  if (DEBUG) {
    printf("wrote address=%d and slot=%d ",a,s);getchar();
  }

  // Clear and set the ADDRESSLATCHENABLE
  dio32_NI6259_write(ajcCTRLMASK, ajcDATASTROBE);
  if (DEBUG) {
    printf("RW=0 ADDR=0 STROBE=1: strobes the address an latches info ");getchar();
  }

  dio32_NI6259_write(ajcCTRLMASK, ajcADDRESSLATCHENABLE | ajcDATASTROBE);
  if (DEBUG) {
    printf("RW=0 ADDR=1 STROBE=1: write mode ");getchar();
  }

  // Set the port to input mode by writing all ones.
  //dio32_NI6259_write(ajcDATAMASK,0x0);
  //dio32_NI6259_config(ajcDATAMASK,DIO_READ);
  if (DEBUG) {
    printf("DATA bits in read mode ");getchar();
  }

  // Set the READ/WRITE bit back to HIGH (read).
  dio32_NI6259_write(ajcCTRLMASK, ajcREADWRITE | ajcADDRESSLATCHENABLE | ajcDATASTROBE);
  if (DEBUG) {
    printf("RW=1 ADDR=1 STROBE=1: bus in send mode ");getchar();
  }


  // Set the DATA STROBE to LOW, putting data on the bus. Read the data.
  dio32_NI6259_write(ajcCTRLMASK, ajcREADWRITE | ajcADDRESSLATCHENABLE);
  if (DEBUG) {
    printf("RW=1 ADDR=1 STROBE=0: latches the data into read register ");getchar();
  }

  dio16_NI6259_read(ajcDATAMASK,(int *)&vt);
  if (DEBUG) {
    printf("now the data got read");getchar();
  }

  // Reset the control lines. The data port is left in input mode. 
  dio32_NI6259_write(ajcCTRLMASK,ajcREADWRITE | ajcADDRESSLATCHENABLE | ajcDATASTROBE);
  if (DEBUG) {
    printf("RW=1 ADDR=1 STROBE=1: reset control lines ");getchar();
  }

  *v = vt;

  return TRUE;

} 

/*!*****************************************************************************
*******************************************************************************
\note  Ajc_InterfaceWrite
\date  Feb 2010
\remarks 

writes the data (low 16 bits) to DIO


*******************************************************************************
Function Parameters: [in]=input,[out]=output

\param[in]     value: 16 bit value to write

******************************************************************************/
int
Ajc_InterfaceWrite ( AjcValue value ) {

  if (!ajc_initialized)
    return FALSE;

  dio32_NI6259_write(ajcDATAMASK, value) ;

  return TRUE;

}

/*!*****************************************************************************
*******************************************************************************
\note  read_ajc_config
\date  Feb 2010
\remarks 

parses the AJC card information, i.e., which DOF to associate with which 
card in the AJC bus, and what cardID to expect.


*******************************************************************************
Function Parameters: [in]=input,[out]=output

\param[in]     fname : file name of file where config info is stored
\param[out]      jts : array to receive the information

******************************************************************************/
static int
read_ajc_config(char *fname, Joint *jts) {

  int j,i,rc,s;
  unsigned int c;
  char   string[100];
  FILE  *in;

  // open the file
  sprintf(string,"%s%s",CONFIG,fname);
  in = fopen(string,"r");
  if (in == NULL) {
    printf("ERROR: Cannot open file >%s<!\n",string);
    return FALSE;
  }

  /* find all joint variables and read the appropriate AJC info */
  for (i=1; i<= N_DOFS; ++i) {
    if (!find_keyword(in, &(joint_names[i][0]))) {
      printf("ERROR: Cannot find offset for >%s<!\n",joint_names[i]);
      fclose(in);
      return FALSE;
    }
    rc=fscanf(in,"%d %x",&s,&c);
    jts[i].slot = s;
    jts[i].cardid = c;
    strcpy(jts[i].name,joint_names[i]);
  }

  fclose(in);

  return TRUE;

}

/*!*****************************************************************************
*******************************************************************************
\note  read_ajc_registers
\date  Feb 2010
\remarks 

parses the AJC register information, i.e., all registers that need to be
downloaded to the AJC cards.

*******************************************************************************
Function Parameters: [in]=input,[out]=output

\param[in]     fname : file name of file where config info is stored
\param[out]      jts : array to receive the information

******************************************************************************/
static int
read_ajc_registers(char *fname, Joint *jts) {

  int j,i,rc;
  char   string[100];
  FILE  *in;

  // open the file
  sprintf(string,"%s%s",CONFIG,fname);
  in = fopen(string,"r");
  if (in == NULL) {
    printf("ERROR: Cannot open file >%s<!\n",string);
    return FALSE;
  }

  /* find all joint variables and read the appropriate AJC info */
  for (i=1; i<= N_DOFS; ++i) {
    if (!find_keyword(in, &(joint_names[i][0]))) {
      printf("ERROR: Cannot find offset for >%s<!\n",joint_names[i]);
      fclose(in);
      return FALSE;
    }
    for (j=1; j<=RegisterCount; ++j)
      rc=fscanf(in,"%d",&(jts[i].registers[j]));
    strcpy(jts[i].name,joint_names[i]);
  }

  fclose(in);

  return TRUE;

}

/*!*****************************************************************************
*******************************************************************************
\note  Interface_StartConvert
\date  Feb 2010
\remarks 

Start a conversion on a given interface (globally). This routine is
only callable from within the Ajc module itself.
Side-effects::
Begins a convertion on all cards on a given backplane.

*******************************************************************************
Function Parameters: [in]=input,[out]=output

\param[in]     channel : the channel to be converted

******************************************************************************/
static void
Interface_StartConvert ( AjcChannel channel )   
{
  unsigned    c;

  // subtract offset
  c = channel - CHANNELSTART;

  // Translate to a physical card address.
  c = channelInfo [ c ];

  // Write out to the interface and update the data structures.
  Interface_Write ( 1, ajcWORLDMUXSELECT, (AjcValue) c );
  Interface_Write ( 1, ajcWORLDCONVERT, 0 );

} 

/*!*****************************************************************************
*******************************************************************************
\note  Interface_WaitConvert
\date  Feb 2010
\remarks 

Continually read the card status to determine if the conversion
is complete. Note that the address information is written and
latched ONCE and that multiple data strobes are done with that
address. When the result is obtained, check the high bit of the
result to determine if the power has been lost or a cable unplugged.
Note that in these cases, the high bit (which is pulled low by
the card) will go high because of either pull-ups on the backplane
or the Digital I/O board.

A conversion must be
in progress. This routine only checks a single slot on a single
interface to determine if the conversion is complete. An unplugged
cable or power loss on a DIFFERENT interface will not be sensed.

Something should be said for the magic number 100, found in the
ending condition for the do loop. It has been determined that with
all present sections each time through that loop is about 1us. The
convertion should only take 10us. The 100us limit allows for finding
hardware problems which would otherwise lock the system in an
infinite loop. I decided not to use a watchdog here, because this
routine can be called from many tasks at the same time and keeping
a watchdog timer for each seemed inappropriate.

*******************************************************************************
Function Parameters: [in]=input,[out]=output

none

******************************************************************************/
static int
Interface_WaitConvert(void)
{
  AjcValue      v;
  int           count;
  int           max_count = 100;
  static int    count_good = 0;

  // Set the READ/WRITE line LOW (write).
  dio32_NI6259_write(ajcCTRLMASK,ajcADDRESSLATCHENABLE | ajcDATASTROBE);

  // Write the address out to the backplane -- only the slot of the first DOF is checked
  dio32_NI6259_write(ajcDATAMASK,(ajcADBUSY << 8) | joints[1].slot);

  // Clear and set the ADDRESSLATCHENABLE.
  dio32_NI6259_write(ajcCTRLMASK,ajcDATASTROBE);
  dio32_NI6259_write(ajcCTRLMASK,ajcADDRESSLATCHENABLE | ajcDATASTROBE);

  // Set the READ/WRITE bit back to HIGH (read).
  dio32_NI6259_write(ajcCTRLMASK,
		     ajcREADWRITE | ajcADDRESSLATCHENABLE | ajcDATASTROBE);

  // While the conversion is not complete...
  count = 0;   // Initialize our "failure" counter.
  do {

    // Set the DATA STROBE to LOW, putting data on the bus. Read the data.
    dio32_NI6259_write(ajcCTRLMASK,ajcREADWRITE | ajcADDRESSLATCHENABLE);

    //  Extract the low bit (End of Conversion) and a bit that is currently
    //  not assigned. This bit will go high on error. (See Algorithm, above.)

    // Binary pattern 10001.
    dio16_NI6259_read(ajcDATAMASK,(int *)&v);
    v = v & 0x11;

    // Reset the control lines. The data port is left in input mode.
    dio32_NI6259_write(ajcCTRLMASK,ajcREADWRITE | ajcADDRESSLATCHENABLE | ajcDATASTROBE);

    // Up the failure counter.
    count += 1;

  } while ( ! v && count < max_count );   /* See dependencies, above. */


  // Check for errors and return.
  if ( count == max_count ) {
    printf("Communication error 1 (count good = %d)\n",count_good);
    sleep(2);
    return FALSE;
  }  else if ( v == 1 ) {
    ++count_good;
    return TRUE;
  } else {
    printf("Communication error 2 (v=%d) (count good = %d)\n",v,count_good);
    sleep(2);
    return FALSE;
  }

} 

/*!*****************************************************************************
*******************************************************************************
\note  Interface_Probe
\date  Feb 2010
\remarks 

Perform an Interface_Read of the card id register. This number
is bounded 0-255, so a number greater than 255 indicates that
the slot is empty. This is because of pullup resistors on the
backplane and the I/O card.

*******************************************************************************
Function Parameters: [in]=input,[out]=output

\param[in]   s: slot of AJC card

******************************************************************************/
static int
Interface_Probe ( AjcSlot s )
{
  AjcValue    vt;

  // Perform the read and check the result.
  if (!Interface_Read ( s, 0, &vt )) {
    printf("Couldn't read from AJC slot %c\n",s);
    return FALSE;
  }

  // Check that the value, it cannot be greater than 255.
  if ( vt > 255 ) {
    printf("Invalid value read from slot=%d vt=%d\n",s,vt);
    return FALSE;
  }

  return TRUE;

}

/*!*****************************************************************************
*******************************************************************************
\note  Interface_Write
\date  Feb 2010
\remarks 

Write the combined address (16 bits) to the the I/O port.
Set the Read / Write line low (write).
the I/O port which (for the Green Springs card) also sets the port
to output mode. Strobe the Address Latch Enable. Write the data
(16 bits) to the I/O port. Strobe the Data Strobe line. Set the
Read / Write line high (read). Note that the I/O direction
is left in an unknown state and the card is left in a `read' situation to
protect the cards from logic spikes on data enable lines.

Cause a conversion on all slots of the interface

*******************************************************************************
Function Parameters: [in]=input,[out]=output

\param[in]   s: slot of AJC card
\param[in]   a: address of AJC card
\param[in]   v: value to be written

******************************************************************************/
static void
Interface_Write( AjcSlot s, AjcAddress a, AjcValue v )  
{
  
  // Set the READ/WRITE line LOW (write).
  dio32_NI6259_write(ajcCTRLMASK,ajcADDRESSLATCHENABLE | ajcDATASTROBE);
  
  // Write the address out to the backplane.
  dio32_NI6259_write(ajcDATAMASK,(a << 8) | s);
  
  // Clear and set the ADDRESSLATCHENABLE.
  dio32_NI6259_write(ajcCTRLMASK,ajcDATASTROBE);
  dio32_NI6259_write(ajcCTRLMASK,ajcADDRESSLATCHENABLE | ajcDATASTROBE);
  
  // Write the data out to the card.
  dio32_NI6259_write(ajcDATAMASK,v);
  
  // Set the DATA STROBE to LOW, causing the card to latch the data.
  dio32_NI6259_write(ajcCTRLMASK,ajcADDRESSLATCHENABLE);
  dio32_NI6259_write(ajcCTRLMASK,ajcDATASTROBE | ajcADDRESSLATCHENABLE);
  
  // Reset the control lines. The data port is left in input mode.
  dio32_NI6259_write(ajcCTRLMASK,ajcREADWRITE | ajcADDRESSLATCHENABLE | ajcDATASTROBE);
  
}

	    
/*!****************************************************************************
*******************************************************************************
\note  Interface_ConvertAndWait
\date  Feb 2010
\remarks 

Cause a conversion on all slots of the interface

*******************************************************************************
Function Parameters: [in]=input,[out]=output

none

******************************************************************************/
int
Interface_ConvertAndWait (void)  
{
  int    i;
  
  //Interface_StartConvert(channelManualPosition);
  //Interface_StartConvert(channelActPosStage1);
  //Interface_StartConvert(channelActVelocity);
  Interface_StartConvert(channelActTorque);
  if (!Interface_WaitConvert())
    return FALSE;

  return TRUE;
} 

/*!*****************************************************************************
*******************************************************************************
\note  Joint_Initialize
\date  Feb 2010
\remarks 

Initializes a joint, i.e., write default registers and make the joint active

*******************************************************************************
Function Parameters: [in]=input,[out]=output

\param[in]   j: joint ID

******************************************************************************/
static int
Joint_Initialize (int j )

{
  AjcValue value[N_DOFS+1];
  int      r, i;
  int      js[N_DOFS+1];

  // check that the joint is active - assumes valid `joint' parameter.
  if ( ! joints[j].active ) {
    printf("Joint %d is not active\n",j);
    return FALSE;
  }

  // write default registers
  for ( r = 0; r < RegisterCount; r++ ) {
    AjcRegister  reg;

    reg = r + REGISTERSTART;

    value[1] = joints[j].registers[ r+1 ];
    js[1] = j;
    if (!Ajc_WriteRegister ( 1, js, reg, value )) {
      printf("Error in Joint_Initialize: joint=%d, reg=%d, value=%d\n",j,reg,value[1]);
      return FALSE;
    }
  }

  // Set all the ``safe'' values for gains
  for ( r = 1; r <= RegisterCount; r++ )
    joints [j].saferegisters[r] = joints[j].registers[r];


  // Set the card as initialized.
  joints[j].initialized = TRUE;

  return TRUE;

}

/*!*****************************************************************************
*******************************************************************************
\note  Joints_Validate
\date  Feb. 2010

\remarks 

identify each card found in the system and update data structures

*******************************************************************************
Function Parameters: [in]=input,[out]=output

none

******************************************************************************/
static int
Joints_Validate ( void ) 
{
  AjcCardID   cardid;
  AjcValue    v;
  int         s, j;
  static char message [ 256 ];

  for (j=1; j<=N_DOFS; ++j) {

    if (!Ajc_ReadCardID (joints[j].slot, &cardid )) {
      printf ("Joint %s is not installed.",joints[j].name);
      continue;
    }

    if ( cardid != joints [j].cardid ) {
      if ( cardid == CardInvalid ) {
	printf("Joint %s is using a debugging card (0x%x).\n",joints [j].name,cardid) ;
      } else  {
	printf("WARNING>>> Joint %s is using a suspect card (0x%x ~= 0x%x)!\n",
	       joints [j].name,cardid,joints[j].cardid);
      }
    }

    /*
     *  Determine the version of card that is installed. This is
     *  done by knowing that the pump pressure is currently low,
     *  and checking the relay status of the card. Version 1 cards
     *  did not have relay monitors on them, so they will (erroneously)
     *  say that the pressure is HIGH. Version 2 cards will read
     *  correctly that the pump pressure is low.
     */

    if (!Interface_Read ( joints [j].slot, ajcADBUSY, &v )) {
      printf("Joint %s appears to have problems.\n",joints [j].name);
      continue;
    }

    if ( (v & CardStatusRelay) == 0 )
      joints[j].version = 1;
    else
      joints[j].version = 2;

    // Mark the joint as active.
    joints [j].active = TRUE;

  }

  return TRUE;

} 

/*!*****************************************************************************
*******************************************************************************
\note  Ajc_WriteRegister
\date  Feb. 2010

\remarks 

writes register values to multiple AJC boards

*******************************************************************************
Function Parameters: [in]=input,[out]=output

\param[in]   count : number of element in array
\param[in]      js : array of joint IDs
\param[in]     reg : which register to write
\param[in]      vl : array of values to write

******************************************************************************/
int
Ajc_WriteRegister(int count, int *js, AjcRegister reg, AjcValue *vl )
{
  int         k;
  unsigned    r;
  AjcAddress  a;

  // adjust register number
  r = reg - REGISTERSTART;

  // Determine which address to write.
  a = registerInfo [ r ].address;

  // For each item in the joint list, check whether active
  for (k=1; k<=count; ++k) {
    if ( ! joints[ js[k] ].active ) {
      printf("Joint %d is not active\n",js[k]);
      return FALSE;
    }
  }

  // For each item in the joint list, probe slot for existance
  for ( k = 1; k <= count; ++k ) {
    if (!Interface_Probe(joints[js[k]].slot)) {
      printf("I died in interface_probe for joint %d using slot %d\n",js[k],joints[js[k]].slot);
      return FALSE;
    }
  }

  // For each item in the joint list, write out the value to the card.
  for ( k = 1; k <= count; ++k ) {
    Interface_Write(joints[js[k]].slot, a, vl[k]);
  }

  return TRUE;

}

/*!*****************************************************************************
*******************************************************************************
\note  Ajc_ReadRegister
\date  Feb. 2010

\remarks 

reads register values from multiple AJC boards

*******************************************************************************
Function Parameters: [in]=input,[out]=output

\param[in]   count : number of element in array
\param[in]      js : array of joint IDs
\param[in]     reg : which register to read
\param[out]     vl : array for read values

******************************************************************************/
int
Ajc_ReadRegister ( int count, int *js, AjcRegister reg, AjcValue *vl )
{
  int         k;
  unsigned    r;
  AjcAddress  a;

  // adjust register number
  r = reg - REGISTERSTART;

  // Determine which address to read
  a = registerInfo [ r ].address;

  // For each item in the joint list, check whether active
  for (k=1; k<=count; ++k) {
    if ( ! joints[ js[k] ].active ) {
      printf("Joint %d is not active\n",js[k]);
      return FALSE;
    }
  }

  // For each item in the joint list, probe slot for existance
  for ( k = 1; k <= count; ++k ) {
    if (!Interface_Probe(joints[js[k]].slot)) {
      printf("I died in interface_probe for slot %d\n",joints[js[k]].slot);
      return FALSE;
    }
  }

  // For each item in the joint list, write out the value to the card.
  for ( k = 1; k <= count; ++k ) {
    Interface_Read(joints[js[k]].slot, a, &(vl[k]));
  }


  return TRUE;

} 

/*!*****************************************************************************
*******************************************************************************
\note  Ajc_ReadChannel
\date  Feb. 2010

\remarks 

reads channel values from multiple AJC boards

*******************************************************************************
Function Parameters: [in]=input,[out]=output

\param[in]   count : number of element in array
\param[in]      js : array of joint IDs
\param[in]     reg : which register to read
\param[out]     vl : array for read values

******************************************************************************/
int
Ajc_ReadChannel(int count, AjcJoint *js, AjcChannel channel, AjcValue *vl )
{
  int      k;
  unsigned c;
  Boolean  useConverter;

  // determine the channel's ordinal value.
  c = channel - CHANNELSTART;

  // Determine if the converter will be used.
  switch ( channel )  {

  case channelEncoderLong:
  case channelEncoderShort:
    useConverter = FALSE;
    break;

  default:
    useConverter = TRUE;
    break;

  }

  // For each item in the joint list, check whether active
  for (k=1; k<=count; ++k) {
    if ( ! joints[ js[k] ].active ) {
      printf("Joint %d is not active\n",js[k]);
      return FALSE;
    }
  }

  // For each item in the joint list, probe slot for existance
  for ( k = 1; k <= count; ++k ) {
    if (!Interface_Probe(joints[js[k]].slot)) {
      printf("I died in interface_probe for slot %d\n",joints[js[k]].slot);
      return FALSE;
    }
  }

  // Zero out the return array.
  for ( k = 1; k <= count; k++ )
    vl[k] = ValueInvalid;

  // Start and complete conversions
  if ( useConverter ) {
    Interface_StartConvert(channel);
    Interface_WaitConvert();
  }

  // Read in all the values that have been requested.
  for (k = 1; k <= count; ++k ) {
    AjcValue  value;

    if ( vl [k] != ValueInvalid )
      continue;

    if (useConverter) {

      if (!Interface_Read(joints[js[k] ].slot,ajcLOCALCONVERT,&value)) {
	printf("Error in Interface_Read for slot %d\n",joints[js[k]].slot);
	return FALSE;
      }
      vl [ k ] = value;

    } else  {

      AjcValue	temp;

      switch (channel) {

      case channelEncoderLong:

	if (!Interface_Read(joints [js[k]].slot,ajcENCODERLSB,&temp)) {
	  printf("Error in Interface_Read for slot %d (ajcENCODERLSB)\n",joints[js[k]].slot);
	  return FALSE;
	}

	if (!Interface_Read(joints[js[k]].slot,ajcENCODERMSB, &value )) {
	  printf("Error in Interface_Read for slot %d (ajcENCODERMSB)\n",joints[js[k]].slot);
	  return FALSE;
	}

	vl[k] = (value << 4) + (temp & 0xF );
	break;


      case channelEncoderShort:

	if (!Interface_Read(joints[js[k]].slot,ajcENCODERMSB, &value )) {
	  printf("Error in Interface_Read for slot %d (ajcENCODERMSB - short)\n",joints[js[k]].slot);
	  return FALSE;
	}

	vl[k] = value;
	break;

      default:
	printf("This should never happen\n");
	return FALSE;

      }

    }

  }

  return TRUE;
}

/*!*****************************************************************************
*******************************************************************************
\note  Ajc_ReadCardID
\date  Feb. 2010

\remarks 

reads the card ID for a given slot in the AJC bus

*******************************************************************************
Function Parameters: [in]=input,[out]=output

\param[in]    s: slot number
\param[out]  id: card id

******************************************************************************/
int
Ajc_ReadCardID(AjcSlot s, AjcCardID *id ) {

  AjcValue    v=0;

  // read from the card
  if (!Interface_Read ( s, 0, &v )) {
    printf("Cannot read from AJC slot %d\n",s);
    return FALSE;
  }

  if ( v > 0xFF )  {
    *id = 0;
    printf("AJC card in slot %d has weird card ID 0x%x\n",s,v);
    return FALSE;
  }

  *id = v & 0xFF;

  return TRUE;

}

/*!*****************************************************************************
*******************************************************************************
\note  Ajc_InterfaceStatus
\date  Feb. 2010

\remarks 

reads the status information for the AJC bus

*******************************************************************************
Function Parameters: [in]=input,[out]=output

\param[out]  status: status information structure

******************************************************************************/
int
Ajc_InterfaceStatus ( AjcInterfaceStatus *status ) {

  AjcValue controllerBits, pumpBits;
  int      rc;

  // read controller bits
  if (!Interface_Read (bus_controller_slot, 0, &controllerBits )) {
    printf("Cannot read controllerBits\n");
    return FALSE;
  }

  // read pump bits
  if (!Interface_Read ( bus_controller_slot, 1, &pumpBits )) {
    printf("Cannot read pumpBits\n");
    return FALSE;
  }

  // Determine the status information contained in the registers
  status->reset = (pumpBits & (1 << PumpResetBit)) == 0;
  status->pumpPressure = (pumpBits & (1 << PumpPressureBit)) == 0;
  status->pumpMotor = (pumpBits & (1 << PumpMotorBit)) != 0;
  status->pumpPressureHigh = (pumpBits & (1 << PumpPressureHighBit)) == 0;
  status->pumpOn = (pumpBits & (1 << PumpOnBit)) == 0;
  status->relaysEnabled = (pumpBits & (1 << PumpRelaysEnabledBit)) != 0;
  status->pumpConnected = (pumpBits & (1 << PumpConnectedBit)) != 0;

  status->errorBits = (~ controllerBits) & 0xFF;
  status->overrideBits = ((~ controllerBits) & 0xFF00) >> 8;


  return TRUE;

} 

/*!*****************************************************************************
*******************************************************************************
\note  Ajc_ReadChannelFast
\date  Feb. 2010

\remarks 

reads channel values from multiple AJC boards, a verion optimized for speed

*******************************************************************************
Function Parameters: [in]=input,[out]=output

\param[in]   count : number of element in array
\param[in]      js : array of joint IDs
\param[in]     reg : which register to read
\param[out]     vl : array for read values

******************************************************************************/
int
Ajc_ReadChannelFast ( int count, AjcJoint *js, AjcChannel channel, AjcValue *vl )
{
  int      i, ii, k;
  Boolean  useConverter;
  AjcValue vt;

  // Determine if the converter will be used.
  switch ( channel ) {
    
  case channelEncoderLong:
  case channelEncoderShort:
    useConverter = FALSE;
    break;
    
  default:
    useConverter = TRUE;
    break;
    
  }

  // Zero out the return array.
  for ( k = 1; k <= count; ++k )
    vl[k] = ValueInvalid;

  // Start and complete conversions on each interface that needs it.
  if ( useConverter ) {
    Interface_StartConvert (channel);
    if (!Interface_WaitConvert())
      return FALSE;
  }

  /* Read in all the values that have been requested. */
  for ( k = 1; k <= count; k++ ) {
    AjcValue value;
    int buf[20];

    if ( vl[k] != ValueInvalid )
      continue;

    if ( useConverter ) {

      // Set the READ/WRITE line LOW (write).
      dio32_NI6259_write(ajcCTRLMASK,ajcADDRESSLATCHENABLE | ajcDATASTROBE);
      
      // Write the address out to the backplane.
      dio32_NI6259_write(ajcDATAMASK,(ajcLOCALCONVERT << 8) | (joints[js[k]].slot));
      
      // Clear and set the ADDRESSLATCHENABLE.
      dio32_NI6259_write(ajcCTRLMASK,ajcDATASTROBE);
      dio32_NI6259_write(ajcCTRLMASK,ajcADDRESSLATCHENABLE | ajcDATASTROBE);
      
      // Set the READ/WRITE bit back to HIGH (read)
      dio32_NI6259_write(ajcCTRLMASK,
			 ajcREADWRITE | ajcADDRESSLATCHENABLE | ajcDATASTROBE);

      // Set the DATA STROBE to LOW, putting data on the bus. Read the data.
      dio32_NI6259_write(ajcCTRLMASK,ajcREADWRITE | ajcADDRESSLATCHENABLE);
      dio16_NI6259_read(ajcDATAMASK,(int *)&vt);

      vl [ k ] = vt;

    } else {
      AjcValue temp;

      switch ( channel ) {

      case channelEncoderLong:

	// Set the READ/WRITE line LOW (write).
	dio32_NI6259_write(ajcCTRLMASK,ajcADDRESSLATCHENABLE | ajcDATASTROBE);

	// Write the address out to the backplane.
	dio32_NI6259_write(ajcDATAMASK,(ajcENCODERLSB << 8) | (joints[js[k]].slot));

	// Clear and set the ADDRESSLATCHENABLE.
	dio32_NI6259_write(ajcCTRLMASK,ajcDATASTROBE);
	dio32_NI6259_write(ajcCTRLMASK,ajcADDRESSLATCHENABLE | ajcDATASTROBE);

	// Set the READ/WRITE bit back to HIGH (read).
	dio32_NI6259_write(ajcCTRLMASK,
			   ajcREADWRITE|ajcADDRESSLATCHENABLE|ajcDATASTROBE);

	// Set the DATA STROBE to LOW, putting data on the bus. Read the data.
	dio32_NI6259_write(ajcCTRLMASK,ajcREADWRITE | ajcADDRESSLATCHENABLE);
	dio16_NI6259_read(ajcDATAMASK,(int *)&vt);

	temp = vt;

	// the second part for long channel reading

	// Set the READ/WRITE line LOW (write).
	dio32_NI6259_write(ajcCTRLMASK,ajcADDRESSLATCHENABLE | ajcDATASTROBE);

	// Write the address out to the backplane.
	dio32_NI6259_write(ajcDATAMASK,(ajcENCODERMSB << 8) | (joints[js[k]].slot));

	// Clear and set the ADDRESSLATCHENABLE.
	dio32_NI6259_write(ajcCTRLMASK,ajcDATASTROBE);
	dio32_NI6259_write(ajcCTRLMASK,ajcADDRESSLATCHENABLE | ajcDATASTROBE);

	// Set the READ/WRITE bit back to HIGH (read).
	dio32_NI6259_write(ajcCTRLMASK,
			   ajcREADWRITE|ajcADDRESSLATCHENABLE|ajcDATASTROBE);

	// Set the DATA STROBE to LOW, putting data on the bus. Read the data.
	dio32_NI6259_write(ajcCTRLMASK,ajcREADWRITE | ajcADDRESSLATCHENABLE);
	dio16_NI6259_read(ajcDATAMASK,(int *)&vt);

	value = vt;

	vl[k] = (value << 4) + (temp & 0xF );
	break;


      case channelEncoderShort:

	// Set the READ/WRITE line LOW (write).
	dio32_NI6259_write(ajcCTRLMASK,ajcADDRESSLATCHENABLE | ajcDATASTROBE);

	// Write the address out to the backplane.
	dio32_NI6259_write(ajcDATAMASK, (ajcENCODERMSB << 8) | (joints[js[k]].slot));

	// Clear and set the ADDRESSLATCHENABLE.
	dio32_NI6259_write(ajcCTRLMASK,ajcDATASTROBE);
	dio32_NI6259_write(ajcCTRLMASK,ajcADDRESSLATCHENABLE | ajcDATASTROBE);

	// Set the READ/WRITE bit back to HIGH (read).
	dio32_NI6259_write(ajcCTRLMASK,
			   ajcREADWRITE|ajcADDRESSLATCHENABLE|ajcDATASTROBE);

	// Set the DATA STROBE to LOW, putting data on the bus. Read the data.
	dio32_NI6259_write(ajcCTRLMASK,ajcREADWRITE | ajcADDRESSLATCHENABLE);
	dio16_NI6259_read(ajcDATAMASK,(int *)&vt);

	vl [ k ] = vt;

	break;

      default:
	printf("This should never happen\n");
	return FALSE;

      } /* end switch */

    } /* end else */

  } /* end for */

  // Reset the control lines. The data port is left in input mode.
  dio32_NI6259_write(ajcCTRLMASK,
		     ajcREADWRITE|ajcADDRESSLATCHENABLE|ajcDATASTROBE);

  return TRUE;

}

/*!*****************************************************************************
*******************************************************************************
\note  Ajc_WriteRegisterFast
\date  Feb. 2010

\remarks 

writes register values to multiple AJC boards, optimized for speed

*******************************************************************************
Function Parameters: [in]=input,[out]=output

\param[in]   count : number of element in array
\param[in]      js : array of joint IDs
\param[in]     reg : which register to write
\param[in]      vl : array of values to write

******************************************************************************/
int
Ajc_WriteRegisterFast(int count, AjcJoint *js, AjcRegister reg, AjcValue *vl )
{
  int         i, k;
  unsigned    r;
  AjcAddress  a;

  // Determine which address to write.
  r = reg - REGISTERSTART;
  a = registerInfo [ r ].address;


  // For each item in the joint list, write out the value to the card.
  for ( k = 1; k <= count; ++k ) {

    // Set the READ/WRITE line LOW (write).
    dio32_NI6259_write(ajcCTRLMASK,ajcADDRESSLATCHENABLE | ajcDATASTROBE);

    // Write the address out to the backplane.
    dio32_NI6259_write(ajcDATAMASK, (a << 8) | (joints [js[k]].slot));

    // Clear and set the ADDRESSLATCHENABLE.
    dio32_NI6259_write(ajcCTRLMASK,ajcDATASTROBE);
    dio32_NI6259_write(ajcCTRLMASK,ajcADDRESSLATCHENABLE | ajcDATASTROBE);

    // Write the data out to the card.
    dio32_NI6259_write(ajcDATAMASK,vl [ k ]);

    // Set the DATA STROBE to LOW, causing the card to latch the data.
    dio32_NI6259_write(ajcCTRLMASK,ajcADDRESSLATCHENABLE);
    dio32_NI6259_write(ajcCTRLMASK,ajcDATASTROBE | ajcADDRESSLATCHENABLE);

  }

  // Reset the control lines. The data port is left in input mode.
  dio32_NI6259_write(ajcCTRLMASK,ajcREADWRITE | ajcADDRESSLATCHENABLE | ajcDATASTROBE);

  return TRUE;

} 

/*!*****************************************************************************
*******************************************************************************
\note  Ajc_PumpLow
\date  Feb. 2010

\remarks 

puts the pump into low pressure mode

*******************************************************************************
Function Parameters: [in]=input,[out]=output

none

******************************************************************************/
void
Ajc_PumpLow(void) 
{

  AjcValue v;

  Interface_Read ( bus_controller_slot, 3, &v );

}

/*!*****************************************************************************
*******************************************************************************
\note  Ajc_PumpKill
\date  Feb. 2010

\remarks 

shuts down the hydraulic pump

*******************************************************************************
Function Parameters: [in]=input,[out]=output

none

******************************************************************************/
void
Ajc_PumpKill(void) 
{

  AjcValue v;

  Interface_Read ( bus_controller_slot, 2, &v );

}

/*!*****************************************************************************
*******************************************************************************
\note  Ajc_PumpStatus
\date  Feb. 2010

\remarks 

shuts down the hydraulic pump

*******************************************************************************
Function Parameters: [in]=input,[out]=output

returns whether the pump is running or not

******************************************************************************/
int
Ajc_PumpStatus(void)
{
  AjcInterfaceStatus status;

  if (!Ajc_InterfaceStatus ( &status ))
    return -1;

  /* NOTE: this actully only gives me information whether the pump is
     running or not; the pressure information does not seem to be
     available */
  return (!status.pumpMotor);
}

/*!*****************************************************************************
*******************************************************************************
\note  Ajc_DebugWrite
\date  Feb. 2010

\remarks 

An interactive and verbose function to write a register or channel

*******************************************************************************
Function Parameters: [in]=input,[out]=output

none

******************************************************************************/
static void
Ajc_DebugWrite (void)  
{
  static int slot=0;
  static int address=0;
  static int value=0;

  if (!get_int("Which slot to write?",slot,&slot))
    return;
  if (!get_int("Which address to write?",address,&address))
    return;
  if (!get_int("Which value to write?",value,&value))
    return;

  Interface_Write( (AjcSlot) slot, (AjcAddress) address, (AjcValue) value );

}

/*!*****************************************************************************
*******************************************************************************
\note  Ajc_DebugRead
\date  Feb. 2010

\remarks 

An interactive and verbose function to read a register or channel

*******************************************************************************
Function Parameters: [in]=input,[out]=output

none

******************************************************************************/
static void
Ajc_DebugRead (void)  
{
  static int slot=0;
  static int address=0;
  static int value=0;

  if (!get_int("Which slot to read?",slot,&slot))
    return;
  if (!get_int("Which address to read?",address,&address))
    return;

  Interface_Write( (AjcSlot) slot, (AjcAddress) address, (AjcValue) &value );

  printf("Value = %d (0x%x)\n",value,value);

}

/*!*****************************************************************************
*******************************************************************************
\note  update_bit_string
\date  Jan. 2011

\remarks

Changes a 32 bit string according to a mask and the desired values

*******************************************************************************
Function Parameters: [in]=input,[out]=output

\param[in]    value: old value of bit string
\param[in]     mask: make for the bits to be changed
\param[in]     bits: value of bits to be changed in mask


******************************************************************************/
static int
update_bit_string(int value, int mask, int bits)
{
  return ((!mask) & value) | (mask & bits);
}

/*!*****************************************************************************
*******************************************************************************
\note  Joint_Defaults
\date  Feb 2010
\remarks 

Initializes all cards in the AJC bus to default value for the registers

*******************************************************************************
Function Parameters: [in]=input,[out]=output

none

******************************************************************************/
static int
Joint_Defaults (void)

{
  int      r, i;

  // write default registers
  for (i=1; i<=20; ++i) { // 20 slots hardcoded as our AJC bus won't change

    // probe slot for existance
    if (!Interface_Probe(i)) {
      printf("Ajc slot %d does not exist\n",i);
      continue;
    }
      
    for ( r = 0; r < RegisterCount; r++ ) {
      AjcRegister  reg;
      
      reg = r + REGISTERSTART;

      // write default value
      Interface_Write(i, registerInfo[r].address, registerInfo[r].initial);

    }
  }


  return TRUE;

}




/*!*****************************************************************************
 *******************************************************************************
\note  osc_valve
\date  Oct 2011
   
\remarks 

 a routine to clear up valves by oscillating them at high frequence

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 \param[in]   dof: which dof?
 \param[in]  freq: which frequency for oscillation
 \param[in] times: how often to repeat the procedure

 ******************************************************************************/
static int
osc_valve(int dof, int freq, int times)

{
  AjcJoint joint_list[1+1];
  AjcValue val[1+1];
  int      i,j;

  // first we set the valve gain to zer
  val[1]         = 0;
  joint_list[1]  = dof;
  sl_rt_mutex_lock(&mutex1);
  if (!Ajc_WriteRegisterFast(1,joint_list,registerValveGain,val)) {
    sl_rt_mutex_unlock(&mutex1);
    return FALSE;
  }
  sl_rt_mutex_unlock(&mutex1);

  // now dither the valve with the valve bias

  for (i=1; i<=times; ++i) {

    // oscillate value
    if (val[1] == 0) 
      val[1] = 4095;
    else 
      val[1] = 0;

    sl_rt_mutex_lock(&mutex1);
    if (!Ajc_WriteRegisterFast(1,joint_list,registerValveCommand,val)) {
      sl_rt_mutex_unlock(&mutex1);
      return FALSE;
    }
    sl_rt_mutex_unlock(&mutex1);

    for (j=1; j<=freq*i; ++j);
  }


  // reset the valve bias
  sl_rt_mutex_lock(&mutex1);
  val[1] = joints[dof].registers[registerValveCommand+1];
  if (!Ajc_WriteRegisterFast(1,joint_list,registerValveCommand,val)) {
    sl_rt_mutex_unlock(&mutex1);
    return FALSE;
  }

  // reset the valve gain
  val[1] = 4095;
  if (!Ajc_WriteRegisterFast(1,joint_list,registerValveGain,val)) {
    sl_rt_mutex_unlock(&mutex1);
    return FALSE;
  }
  sl_rt_mutex_unlock(&mutex1);

  return TRUE;

}


/*!*****************************************************************************
 *******************************************************************************
\note  dither_me
\date  Oct 2011
   
\remarks 

 command line routine to start dither

 *******************************************************************************
 Function Parameters: [in]=input,[out]=output

 none

 ******************************************************************************/
static void
dither_me(void)
{
  int i;
  static int num = 1;
  static int dof = 1;

  get_int("Which DOF?",dof,&dof);
  if (dof < 1 || dof > N_DOFS) {
    printf("Invalid DOF number\n");
    dof = 1;
    return;
  }

  get_int("How often should this be repeated?",num,&num);

  for (i=1; i<=num; ++i) {
    if (!osc_valve(dof,1,3000))
      return;
    taskDelay(120);
  }

}

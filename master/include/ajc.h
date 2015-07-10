/*!=============================================================================
  ==============================================================================

  \file    ajc.h

  \author  Stefan Schaal
  \date    Feb. 2010

  ==============================================================================
  \remarks
  
  header file for ajc.c
  
  ============================================================================*/
  
#ifndef _ajc_
#define _ajc_

// defines
#define CardInvalid  255
#define SlotInvalid  255
#define ValueInvalid 0x10000

// control pin access of DIO
#define ajcADDRESSLATCHENABLE         0x80000  /* bit 20 */
#define ajcREADWRITE                  0x40000  /* bit 19 */
#define ajcDATASTROBE                 0x20000  /* bit 18 */

// bit masks
#define ajcDATAMASK                   (0x0000ffff)
#define ajcCTRLMASK                   (ajcDATASTROBE | ajcREADWRITE | ajcADDRESSLATCHENABLE)

// several handy typedefs
typedef int Boolean;      // Valid values are TRUE and FALSE
typedef unsigned char AjcCardID;
typedef unsigned int AjcJoint;
typedef int AjcFunction;
typedef unsigned char AjcSlot;
typedef unsigned char AjcAddress;
typedef unsigned long AjcTime;
typedef unsigned int AjcValue;



//   This enumeration is meant only to define names and assign
//   values for the possible things that can cause the pump
//   to shut down. These values are really bit values, and they
//   can be found in the `errorBits' field of the `AjcInterfaceStatus'
//   structure.
typedef enum {
   AjcKilledLowPressure = 1,  // Pressure too low.
   AjcKilledAux = 2,          // Auxiliary input on interface card.
   AjcKilledRF = 4,           // Remote shutdown circuite.
   AjcKilledError = 8,        // Position or Torque error limit
   AjcKilledManual = 16,      // Front panel button
   AjcKilledDeadman = 32,     // Remote switch on robot
   AjcKilledCommand = 64,     // Computer command
   AjcKilledStrobe = 128      // Lost contact with computer
} AjcPumpKillers;

//    This enumeration is meant only to define names and assign
//    values for the possible overrides on the pump shutdown
//    circuitry. These values are really bit values, and they
//    can be found in the `overrideBits' field of the `AjcInterfaceStatus'
//    structure.
typedef enum {
   AjcOverrideLowPressure = 1, // Override the low pressure sense
   AjcOverrideAux = 2,         // Override the auxiliary sense
   AjcOverrideRF = 4,          // Override the remote sense
   AjcOverrideError = 8,       // Override error circuit sense
   AjcOverrideManual = 16,     // Override manual sense
   AjcOverrideDeadman = 32,    // Override deadman sense
   AjcOverrideCommand = 64,    // Override computer command sense
   AjcOverrideStrobe = 128     // Override computer connection sense
 } AjcPumpOverrides;

//    This structure is set by the routine Ajc_JointStatus(). The
//    fields can be checked to determine that current status of any joint
//    in the system.
typedef struct AjcJointStatus  {
  Boolean      active;      // Set to True if the card is active, False otherwise.
  Boolean      configured;  // True if the joint should be in the system.
  int          cardVersion; // The version number of the card.
  AjcSlot      slot;        // The slot on the interface that the joint is on.
  AjcCardID    cardid;      // The card ID of the joint.
  Boolean      local;       // True if the Local/Remote switch is local.
  Boolean      relay;       // True if the relay is enabled.
                            // This is valid only cards greater than version 1.
  Boolean      error;       // True if this card is in error (position/force).
                            // This is valid only cards greater than version 1.
} AjcJointStatus;

//    This structure contains status information for a given Interface.
typedef struct AjcInterfaceStatus  {
  Boolean        reset;            // True if the reset button is pressed.
  Boolean        pumpPressure;     // True if pump pressure is on.
  Boolean        pumpMotor;        // True if the pump motor is on.
  Boolean        pumpPressureHigh; // True if the pump is at high pressure
  Boolean        pumpOn;           // True if the pump is on.
  Boolean        relaysEnabled;    // True if the relays are enabled.
  Boolean        pumpConnected;    // True if the pump is connected.
  unsigned short errorBits;        // The bits to determine what killed the pump.
  unsigned short overrideBits;     // The bits that are overriden by jumpers.
} AjcInterfaceStatus;


#define REGISTERSTART  0
#define CHANNELSTART   32

//    This enumeration contains the identifiers for all channels that can
//    be read from the controller cards. Channels are read only. Please
//    see the documentation for the Advanced Joint Controllers for
//    more information on each channel.
typedef enum AjcChannel  {
   // These first elements MUST coorespond to the MUX assignment order! 
   channelManualPosition = CHANNELSTART,   // Front panel knob.
   channelActPosStage1,                    // Stage 1 joint angle.
   channelActPosStage2,                    // Stage 2 joint angle.
   channelActTorque,                       // Actual joint torque.
   channelTorqueOut,                       // ???
   channelActVelocity,                     // Actual joint velocity.
   channelValvePlus,                       // ???
   channelValveMinus,                      // ???
   channelValveDrive,                      // ???
   channelPositionErrorSet,                // ???
   channelTorqueErrorSet,                  // ???
   channelPositionBias,                    // Position bias for joint.
   channelActPositionBias2,                // Stage 2 position bias.
   
   // These are handled specially. 
   channelEncoderShort,                    // encoders require 4 bytes
   channelEncoderLong,                     // thus, short and long
    
   ChannelMAX
} AjcChannel;

#define ChannelCount (ChannelMAX - CHANNELSTART)

//    This enumeration contains the identifiers used for registers on the
//    controller cards. Registers are read/write. Please
//    see the documentation for the Advanced Joint Controllers for
//    more information on each channel.
typedef enum AjcRegister {
   registerPositionCrossGain = REGISTERSTART, // Gain for position cross.
   registerTorqueCrossGain,                   // Gain for torque cross.
   registerPositionErrorGain,                 // Position error gain.
   registerVelocityErrorGain,                 // Velocity error gain.
   registerTorqueErrorGain,                   // Torque error gain.
   registerPlusVelocityGain,                  // ???
   registerActPosGainStage1,                  // Stage 1 position gain.
   registerActPosBiasStage1,                  // Stage 1 position bias.
   registerActPosGainStage2,                  // Stage 2 position gain.
   registerActPosBiasStage2,                  // Stage 2 position bias.
   registerActTorqueGain,                     // Load sensor gain.
   registerActTorqueBiasFine,                 // Fine load sensor bias.
   registerActTorqueBiasCourse,               // Course load sensor bias.
   registerTapGain,                           // Tap gain.
   registerTapThreshold,                      // Tap threshold.
   registerValveGain,                         // Valve gain.
   registerValveCommand,                      // Valve command.
   registerGravityCompensation,               // Gravity compensation bias.
   registerDesiredPositionCommand,            // Desired position.
   registerDesiredTorqueCommand,              // Desired torque.
   
   RegisterMAX
} AjcRegister;


#define RegisterCount (RegisterMAX - REGISTERSTART)
#define FunctionCountMax  (RegisterCount + ChannelCount)

// An array of these is associated with each joint. It is used to store
// the current value and time of collection for Channel information.
typedef struct {
  AjcTime time;    // The time of the last read.
  AjcValue value;  // The value of the channel at that time.
} ChannelStore;


// This structure defines a Joint for the system. The joint consists of
// a name, slot, cardid, and also the data structures to keep track of
// registers and channels.
typedef struct {
  char          name[100];    // The name of the joint (initialized from the JointInfo structure).
  Boolean       active;       // Set to True only if the card is available for use.
  Boolean       initialized;  // Set True if card has been initialized before.
  Boolean       configured;   // Set True if joint should be there.
  int           version;      // The version number of the card.
  AjcCardID     cardid;       // The cardid that the joint SHOULD have.
  AjcSlot       slot;         // The type of card assignment for the joint.
  AjcValue      registers[ RegisterCount+1 ];       // The registers currently on the card.
  AjcValue      saferegisters [ RegisterCount+1 ];  // Registers used to restore ``safe'' state.
  ChannelStore  channel [ ChannelCount+1 ];         // The channel information for the card.
} Joint;


int  Ajc_Initialize (void);
int  Ajc_InterfaceRead ( AjcValue *value );
int  Ajc_InterfaceWrite ( AjcValue value );
int  Interface_ConvertAndWait(void);
int  Ajc_ReadRegister ( int count, int *js, AjcRegister reg, AjcValue *vl );
int  Ajc_ReadChannel(int count, AjcJoint *js, AjcChannel channel, AjcValue *vl );
int  Ajc_ReadCardID(AjcSlot s, AjcCardID *id );
int  Ajc_InterfaceStatus ( AjcInterfaceStatus *status );
int  Ajc_ReadChannelFast ( int count, AjcJoint *js, AjcChannel channel, AjcValue *vl );
int  Ajc_WriteRegisterFast(int count, AjcJoint *js, AjcRegister reg, AjcValue *vl );
void Ajc_PumpLow(void);
void Ajc_PumpKill(void);
int  Ajc_PumpStatus(void);
int  Ajc_WriteRegister(int count, int *js, AjcRegister reg, AjcValue *vl );

/* Exported Definitions (for function-like macros). */

/* Exported Variable Declarations. */

extern char ajcRegisterNames[][40];
extern Joint joints[];

#endif /* __Ajc_h */

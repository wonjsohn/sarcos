/*!=============================================================================
  ==============================================================================

  \file    ni6259_interface.h

  \author  Stefan Schaal
  \date    Feb. 2010

  ==============================================================================
  \remarks
  
  header file for ni6259_interface.c
  
  ============================================================================*/
  
#ifndef _ni6259_interface_
#define _ni6259_interface_

// channel read or write status
#define   DIO_READ    0
#define   DIO_WRITE   1

#ifdef __cplusplus
extern "C" {
#endif

  // function prototypes
  int  init_NI6259(int flag);
  int  d2a_NI6259(int,double);
  inline int  dio32_NI6259_read(int mask, int *val);
  inline int  dio32_NI6259_write(int mask, int val);
  int  dio32_NI6259_config(int mask, int rw);
  int  dio32_NI6259_write_cmd_buffer(int *buf, int n_buf);
  void printDeviceInfo(a4l_desc_t *dsc);
  inline int  dio16_NI6259_read(int mask, int *val);
  inline int  dio16_NI6259_write(int mask, int val);
  int  dio16_NI6259_config(int mask, int rw);



#ifdef __cplusplus
}
#endif


#endif  // _ni6259_interface_ 

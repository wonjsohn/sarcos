#!/usr/bin/env python

"""
C. Minos Niu (minos.niu AT sangerlab.net)
License: this code is in the public domain
"""
import os
import sys
from scipy.io import savemat, loadmat
##from wx.lib.pubsub import Publisher as pub
import platform
arch = platform.architecture()[0]
if arch == "32bit":
    from opalkelly_32bit import ok
elif arch == "64bit":
    from opalkelly_64bit import ok

import numpy as np
from Utilities import *

class FpgaDevice:
    """ The FPGA class
    """
    def __init__(self, serX = "",  bitfile=""):
        self.myMoney = 0
        self.ConfigureXEM(bitfile)
        
   
        #Open the first XEM - try all board types.
        self.xem = ok.FrontPanel()
        if (self.xem.NoError != self.xem.OpenBySerial(serX)):         
            print "Device could not be opened.  Is one connected?\n"

     
        print "Found a device: %s\n" % self.xem.GetBoardModelString(self.xem.GetBoardModel())
            
        
        self.xem.LoadDefaultPLLConfiguration()
            
        ## Get some general information about the XEM.
        #std::string str;
        #printf("Device firmware version: %d.%d\n", dev->GetDeviceMajorVersion(), dev->GetDeviceMinorVersion());
        str = self.xem.GetSerialNumber()
        print ("Device serial number: %s\n" % str)
        str = self.xem.GetDeviceID()
        print ("Device device ID: %s\n" % str)
            
#        # Download the configuration file.
        if (self.xem.NoError != self.xem.ConfigureFPGA(bitfile)):
            print ("FPGA configuration failed.\n")
                            
        # Check for FrontPanel support in the FPGA configuration.
        if (self.xem.IsFrontPanelEnabled()):
            print ("FrontPanel support is enabled.\n");
        else:
            print ("FrontPanel support is not enabled.\n");


    def ConfigureXEM(self,  bitfile=""):
        #bitfile = BIT_FILE
        #print os.getcwd()
        #assert os.path.exists(bitfile.encode('utf-8')), ".bit file NOT found!"
            
        #self.xem = ok.FrontPanel()
##        self.xem.OpenBySerial("")
##        assert self.xem.IsOpen(), "OpalKelly board NOT found!"
        self.xem = ok.FrontPanel()
#        print "count = ",  self.xem.GetDeviceCount()
#        serX = self.xem.GetDeviceListSerial(0)
        #print "serial = ",  serX
#        self.xem.OpenBySerial(serX)
#        assert self.xem.IsOpen(), "OpalKelly board NOT found!"

        #self.xem.LoadDefaultPLLConfiguration()

        self.pll = ok.PLL22393()
        self.pll.SetReference(48)        #base clock frequency
        self.baseRate = 100 #in MHz
        self.pll.SetPLLParameters(0, self.baseRate, 48,  True)            #multiply up to baseRate 
        self.pll.SetOutputSource(0, ok.PLL22393.ClkSrc_PLL0_0)  #clk1 
        self.clkRate = 100                                #mhz; 200 is fastest
        self.pll.SetOutputDivider(0, int(self.baseRate / self.clkRate)) 
        self.pll.SetOutputEnable(0, True)
        ## self.pll.SetOutputSource(1, ok.PLL22393.ClkSrc_PLL0_0)  #clk2
        ## self.pll.SetOutputDivider(1, int(self.baseRate / self.clkRate))       #div4 = 100 mhz
        ## self.pll.SetOutputEnable(1, True)
        self.xem.SetPLL22393Configuration(self.pll)

    def onClkRate(self, value):   
        """ value = how many times of 1/10 real-time
        """
        # F_fpga = C * NUM_NEURON * V * F_emu ,  (C : cycles_per_neuron = 2,  V = 365)
        # if F_fpga = 200Mhz,  F_emu = 1khz)
        # halfcnt = F_fpga / F_neuron / 2 = F_fpga / (C * NUM_NEURON * V * F_emu) / 2
        NUM_CYCLE = 2
        newHalfCnt = 100 * (10 **6) / (NUM_CYCLE * NUM_NEURON * value * SAMPLING_RATE/10 ) /2 
        print 'halfcnt=%d' %newHalfCnt
        print 'value=%d' %value
        DATA_EVT_CLKRATE = 0
        
        self.SendPara(bitVal = newHalfCnt, trigEvent = DATA_EVT_CLKRATE)         
        
        
    def ReadFPGA(self,  getAddr, type):

        """ getAddr = 0x20 -- 0x3F (maximal in OkHost)
        """
        self.xem.UpdateWireOuts()
        ## Read 18-bit integer from FPGA
        if type == "int18" :
            intValLo = self.xem.GetWireOutValue(getAddr) & 0xffff # length = 16-bit
            intValHi = self.xem.GetWireOutValue(getAddr + 0x01) & 0x0003 # length = 2-bit
            intVal = ((intValHi << 16) + intValLo) & 0xFFFFFFFF
#            intVal = ConvertType(intVal, 'I', 'i')
            if intVal > 0x1FFFF:
                intVal = -(0x3FFFF - intVal + 0x1)
            outVal = float(intVal) # in mV De-Scaling factor = 0xFFFF

        ## Read 32-bit float
        elif type == "float32" :
            outValLo = self.xem.GetWireOutValue(getAddr) & 0xffff # length = 16-bit
            outValHi = self.xem.GetWireOutValue(getAddr + 0x01) & 0xffff
            outVal = ((outValHi << 16) + outValLo) & 0xFFFFFFFF
            outVal = ConvertType(outVal, 'I', 'f')
            #print outVal
        ## Read 32-bit signed integer from FPGA
        elif type == "int32" :
            intValLo = self.xem.GetWireOutValue(getAddr) & 0xffff # length = 16-bit
            intValHi = self.xem.GetWireOutValue(getAddr + 0x01) & 0xffff # length = 16-bit
            intVal = ((intValHi << 16) + intValLo) & 0xFFFFFFFF
            outVal = ConvertType(intVal, 'I',  'i')  # in mV De-Scaling factor = 128  #????

        ## if getAddr == DATA_OUT_ADDR[0]:
        ## print "%2.4f" % outVal, 
        ## print "%d" % (outValLo), 
        
        return outVal
     
    """ minimize the frequency of  update wireout to get higher sampling rate """      
    def ReadMultiFPGA(self,  getAddr1, type1,  getAddr2, type2):

        """ getAddr = 0x20 -- 0x3F (maximal in OkHost)
        """
        self.xem.UpdateWireOuts()
        ## Read 18-bit integer from FPGA
        if type1 == "int18" :
            intValLo1 = self.xem.GetWireOutValue(getAddr1) & 0xffff # length = 16-bit
            intValHi1 = self.xem.GetWireOutValue(getAddr1 + 0x01) & 0x0003 # length = 2-bit
            intVal1 = ((intValHi1<< 16) + intValLo1) & 0xFFFFFFFF
#            intVal = ConvertType(intVal, 'I', 'i')
            if intVal1 > 0x1FFFF:
                intVal1 = -(0x3FFFF - intVal1 + 0x1)
            outVal1 = float(intVal1) # in mV De-Scaling factor = 0xFFFF

        ## Read 32-bit float
        elif type1 == "float32" :
            outValLo1 = self.xem.GetWireOutValue(getAddr1) & 0xffff # length = 16-bit
            outValHi1 = self.xem.GetWireOutValue(getAddr1 + 0x01) & 0xffff
            outVal1 = ((outValHi1 << 16) + outValLo1) & 0xFFFFFFFF
            outVal1 = ConvertType(outVal1, 'I', 'f')
            #print outVal
        ## Read 32-bit signed integer from FPGA
        elif type1 == "int32" :
            intValLo1 = self.xem.GetWireOutValue(getAddr1) & 0xffff # length = 16-bit
            intValHi1 = self.xem.GetWireOutValue(getAddr1 + 0x01) & 0xffff # length = 16-bit
            intVal1 = ((intValHi1 << 16) + intValLo1) & 0xFFFFFFFF
            outVal1 = ConvertType(intVal1, 'I',  'i')  # in mV De-Scaling factor = 128  #????


        if type2 == "int18" :
            intValLo2 = self.xem.GetWireOutValue(getAddr2) & 0xffff # length = 16-bit
            intValHi2 = self.xem.GetWireOutValue(getAddr2 + 0x01) & 0x0003 # length = 2-bit
            intVal2 = ((intValHi2<< 16) + intValLo2) & 0xFFFFFFFF
#            intVal = ConvertType(intVal, 'I', 'i')
            if intVal2 > 0x1FFFF:
                intVal2 = -(0x3FFFF - intVal2 + 0x1)
            outVal2 = float(intVal2) # in mV De-Scaling factor = 0xFFFF

        ## Read 32-bit float
        elif type2 == "float32" :
            outValLo2 = self.xem.GetWireOutValue(getAddr2) & 0xffff # length = 16-bit
            outValHi2 = self.xem.GetWireOutValue(getAddr2 + 0x01) & 0xffff
            outVal2 = ((outValHi2 << 16) + outValLo2) & 0xFFFFFFFF
            outVal2 = ConvertType(outVal2, 'I', 'f')
            #print outVal
        ## Read 32-bit signed integer from FPGA
        elif type2 == "int32" :
            intValLo2 = self.xem.GetWireOutValue(getAddr2) & 0xffff # length = 16-bit
            intValHi2 = self.xem.GetWireOutValue(getAddr2 + 0x01) & 0xffff # length = 16-bit
            intVal2 = ((intValHi2 << 16) + intValLo2) & 0xFFFFFFFF
            outVal2 = ConvertType(intVal2, 'I',  'i')  # in mV De-Scaling factor = 128  #????

        return (outVal1,  outVal2)
        
        

    def SendButton(self, buttonValue, evt = None):
        if evt == BUTTON_RESET:
            if (buttonValue) :
                self.xem.SetWireInValue(0x00, 0x01, 0xff)
            else :
                self.xem.SetWireInValue(0x00, 0x00, 0x01)
            self.xem.UpdateWireIns()
        elif evt == BUTTON_RESET_SIM:
            if (buttonValue) :
                self.xem.SetWireInValue(0x00, 0x02, 0xff)
            else :
                self.xem.SetWireInValue(0x00, 0x00, 0x02)
            self.xem.UpdateWireIns()
        elif evt == BUTTON_ENABLE_SIM:
            if (buttonValue) :
                self.xem.SetWireInValue(0x00, 0x04, 0xff)
            else :
                self.xem.SetWireInValue(0x00, 0x00, 0x04)
            self.xem.UpdateWireIns()
            

    def SendPipe(self, pipeInData):
        """ Send byte stream to OpalKelly board
        """
        # print pipeInData

        buf = "" 
        for x in pipeInData:
            ##print x
            buf += pack('<f', x) # convert float_x to a byte string, '<' = little endian

        byteSent = self.xem.WriteToBlockPipeIn(PIPE_IN_ADDR, 4, buf)

        if byteSent == len(buf):
            print "%d bytes sent via PipeIn!" % byteSent 
        else:
            print "Send pipe filed! %d bytes sent" % byteSent
            
    def SendPipeInt(self, pipeInData):
        """ Send byte stream to OpalKelly board
        """
        # print pipeInData

        buf = "" 
        for x in pipeInData:
            ##print x
            buf += pack('<I', x) # convert float_x to a byte string, '<' = little endian

        byteSent = self.xem.WriteToBlockPipeIn(PIPE_IN_ADDR, 4, buf)

        if byteSent == len(buf):
            print "%d bytes sent via PipeIn!" % byteSent 
        else:
            print "Send pipe filed! %d bytes sent" % byteSent

    def SendPara(self, bitVal, trigEvent):
        bitValLo = bitVal & 0xffff
        bitValHi = (bitVal >> 16) & 0xffff
        self.xem.SetWireInValue(0x01, bitValLo, 0xffff)
        self.xem.SetWireInValue(0x02, bitValHi, 0xffff)
        self.xem.UpdateWireIns()            
        self.xem.ActivateTriggerIn(0x50, trigEvent)   
     
    """ minimize the frequency of  update wireout to get higher sampling rate """       
    def SendMultiPara(self, bitVal1, bitVal2, bitVal3, bitVal4, trigEvent):
        #1
        bitValLo1 = bitVal1 & 0xffff
        bitValHi1 = (bitVal1 >> 16) & 0xffff
        self.xem.SetWireInValue(0x01, bitValLo1, 0xffff)
        self.xem.SetWireInValue(0x02, bitValHi1, 0xffff)
        #2
        bitValLo2 = bitVal2 & 0xffff
        bitValHi2 = (bitVal2 >> 16) & 0xffff
        self.xem.SetWireInValue(0x03, bitValLo2, 0xffff)
        self.xem.SetWireInValue(0x04, bitValHi2, 0xffff)
        
        #3
        bitValLo3 = bitVal3 & 0xffff
        bitValHi3 = (bitVal3 >> 16) & 0xffff
        self.xem.SetWireInValue(0x05, bitValLo3, 0xffff)
        self.xem.SetWireInValue(0x06, bitValHi3, 0xffff)
            
        #4
        bitValLo4 = bitVal4 & 0xffff
        bitValHi4 = (bitVal4 >> 16) & 0xffff
        self.xem.SetWireInValue(0x07, bitValLo4, 0xffff)
        self.xem.SetWireInValue(0x08, bitValHi4, 0xffff)
        
    
        self.xem.UpdateWireIns()            
        self.xem.ActivateTriggerIn(0x50, trigEvent)   

    def ReadPipe(self, addr, len = 1000):
        buf = "\x00" * len
        self.xem.ReadFromPipeOut(addr, buf)
        ## 'buf' becomes a string buffer which is used to contain the
        ## data read from the pipeout. In both the Write and Read
        ## cases, the length of the buffer passed is the length
        ## transferred.
        return buf

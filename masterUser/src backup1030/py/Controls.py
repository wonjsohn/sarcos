# -*- coding: utf-8 -*-

"""
Module implementing Control.
"""

from PyQt4.QtGui import QDialog
from PyQt4.QtCore import pyqtSignature
from PyQt4.QtCore import QTimer,  SIGNAL, SLOT, Qt,  QRect
from PyQt4 import QtCore, QtGui

from Utilities import *
from generate_sin import gen as gen_sin
from generate_tri import gen as gen_tri
from generate_spikes import spike_train
from generate_sequence import gen as gen_ramp
from math import floor

from Fpga import FpgaDevice
import platform
arch = platform.architecture()[0]
if arch == "32bit":
    from opalkelly_32bit import ok
elif arch == "64bit":
    from opalkelly_64bit import ok
    
from Display import View

class CtrlChannel:
    def __init__(self, hostDialog, name, id, type, value = 0.0):
        exec interp('self.id = #{id}')
        exec interp('self.currVal = #{value}')
        exec interp('self.type = type')

        exec interp('self.doubleSpinBox = QtGui.QDoubleSpinBox(hostDialog)')
        exec interp('self.doubleSpinBox.setGeometry(QtCore.QRect(230, #{id} * 35, 105, 30))')
        exec interp('self.doubleSpinBox.setProperty("value", value)')
        exec interp('self.doubleSpinBox.setObjectName("param_#{name}")')
        exec interp('self.doubleSpinBox.setSingleStep(0.1)')
        
        exec interp('self.label = QtGui.QLabel(hostDialog)')
        exec interp('self.label.setObjectName("label_#{name}")')
        exec interp('self.label.setText("#{name}")')        
        exec interp('self.label.setGeometry(QtCore.QRect(350, #{id} * 35, 105, 30))')
             
             
from Ui_Controls import Ui_Dialog
class User(QDialog, Ui_Dialog):
    """
    Class documentation goes here.
    """
    def __init__(self, parent = None):
        """
        Constructor
        """
#        QDialog.__init__(self, parent, Qt.FramelessWindowHint)
        QDialog.__init__(self, parent)
        self.setupUi(self)
        
        rawxem = ok.FrontPanel()
        #count = 2
        count = rawxem.GetDeviceCount()
        print count
    
        self.xemList = []
          
        BIT_FILE_LIST = [BIT_FILE,  BIT_FILE2]
        #BIT_FILE_LIST = [BIT_FILE]
        for i in xrange(count):
            
            serX = rawxem.GetDeviceListSerial(i)
            print "serial = ",  serX    
            self.nerfModel = FpgaDevice(serX,  BIT_FILE_LIST[i])
            self.xemList.append(self.nerfModel)
      
            
        # SEND SINEWAVE ALWAYS 
        pipeInData = gen_sin(F = 1.0, AMP = 100.0,  T = 2.0)
        self.xemList[1].SendPipe(pipeInData)
        
    
        
        self.dispView = View(None, VIEWER_REFRESH_RATE, CHIN_PARAM)

        self.dispView.show()
        self.data = []
        self.isLogData = False
        
        # Create float_spin for each input channel
        self.ctrl_all = []
        for (trig_id, name, type, value) in CHOUT_PARAM:
            exec interp('self.ctrl_#{name} = CtrlChannel(hostDialog=self, name=name, id=trig_id, type=type, value=value)')
            exec interp('self.connect(self.ctrl_#{name}.doubleSpinBox, SIGNAL("editingFinished()"), self.onNewWireIn)')
            exec interp('self.connect(self.ctrl_#{name}.doubleSpinBox, SIGNAL("valueChanged(double)"), self.onNewWireIn)')
            exec interp('self.ctrl_all.append(self.ctrl_#{name})')        
        
        # Timer for pulling data, separated from timer_display
        self.timer = QTimer(self)
        self.connect(self.timer, SIGNAL("timeout()"), self.onSyncData)       
        self.timer.start(VIEWER_REFRESH_RATE )
        
        
        self.on_horizontalSlider_valueChanged(5)
        


    def onSyncData(self):
        """
        Core function of Controller, which polls data from Model(fpga) and sends them to Viewer.
        """
        newData1 = []
        newData2 = []
        
        for xaddr, xtype in zip(DATA_OUT_ADDR, CH_TYPE):
            #newData[i] = self.nerfModel.ReadFPGA(DATA_OUT_ADDR[i], CH_TYPE[i])
#            if i == 3: 
#                newData[i] = newData[i] / 100
            #newData.append(max(-16777216, min(16777216, self.nerfModel.ReadFPGA(xaddr, xtype))))
            newData1.append(max(-16777216, min(16777216, self.xemList[0].ReadFPGA(xaddr, xtype))))

            #print newData1[0::6]   # printing 
            
        newData2.append(max(-16777216, min(16777216, self.xemList[1].ReadFPGA(0x20, 'float32'))))  # sine wave
        #print self.xemList[1]
        print newData1
        print newData2#[0::1]   # printing 
            #        newSpike1 = self.nerfModel.ReadPipe(0xA0, 5000) # read ## bytes
#        newSpike2 = self.nerfModel.ReadPipe(0xA1, 5000) # read ## bytes
#        newSpike3 = self.nerfModel.ReadPipe(0xA2, 5000) # read ## bytes
#        newSpike4 = self.nerfModel.ReadPipe(0xA3, 5000) # read ## bytes
#        newSpike5 = self.nerfModel.ReadPipe(0xA4, 5000) # read ## bytes
        newSpike1 = ""
        newSpike2 = ""
        newSpike3 = ""
        newSpike4 = ""
        newSpike5 = ""
        

        #newSpike = "" # read ## bytes
        
        self.dispView.newDataIO(newData1, [newSpike1, newSpike2, newSpike3, newSpike4, newSpike5])
        #self.dispView.newDataIO(newData, [])
        if (self.isLogData):
            self.data.append(newData1)
        
    def onClkRate(self, value):   
        """ value = how many times of 1/10 real-time
        """
        # F_fpga = C * NUM_NEURON * V * F_emu ,  (C : cycles_per_neuron = 2,  V = 365)
        # if F_fpga = 200Mhz,  F_emu = 1khz)
        # halfcnt = F_fpga / F_neuron / 2 = F_fpga / (C * NUM_NEURON * V * F_emu) / 2
        NUM_CYCLE = 2
        newHalfCnt = 200 * (10 **6) / (NUM_CYCLE * NUM_NEURON * value * SAMPLING_RATE/10 ) /2 
        print 'halfcnt=%d' %newHalfCnt
        print 'value=%d' %value

        #self.nerfModel.SendPara(bitVal = newHalfCnt, trigEvent = DATA_EVT_CLKRATE)
        self.xemList[0].SendPara(bitVal = newHalfCnt, trigEvent = DATA_EVT_CLKRATE)
        
    def onNewWireIn(self):
        for ctrl in self.ctrl_all:
            newWireIn = ctrl.doubleSpinBox.value()
            if newWireIn != ctrl.currVal:
                ctrl.currValue = newWireIn
                if (ctrl.type == 'int32'):
                    bitVal = ConvertType(floor(newWireIn),  fromType = 'i',  toType = 'I')
#                    print bitVal
                elif (ctrl.type == 'float32'):
                    bitVal = ConvertType(newWireIn, fromType = 'f', toType = 'I')
                self.xemList[0].SendPara(bitVal = bitVal, trigEvent = ctrl.id)
                


    def plotData(self, data):
        from pylab import plot, show, subplot
        from scipy.io import savemat, loadmat
        import numpy as np
        
        if (data != []):
            forplot = np.array(data)
            for i in xrange(NUM_CHANNEL):
                subplot(NUM_CHANNEL, 1, i+1)
                plot(forplot[:, i])
            show()
            savemat("./matlab_cmn.mat", {"lce": forplot[:, 0], "Ia": forplot[:, 1], \
                                         "II": forplot[:, 2], "force": forplot[:, 3], \
                                         "emg": forplot[:, 4]})
   
    @pyqtSignature("QString")
    def on_comboBox_activated(self, p0):
        """
        Slot documentation goes here.
        """
        choice = p0
        if choice == "Spike Train 1Hz":
#            pipeInData = spike_train(firing_rate = 1) 
            pipeInData = gen_sin(F = 1.0, AMP = 100.0,  T = 2.0)
        elif choice == "Spike Train 10Hz":
#            pipeInData = spike_train(firing_rate = 10)      
#            pipeInData = gen_sin(F = 4.0, AMP = 0.3)
            pipeInData = gen_tri(T = 2.0) 
            
        elif choice == "Spike Train 20Hz":
#            pipeInData = gen_tri() 
            pipeInData = gen_ramp(T = [0.0, 0.1, 0.2, 0.8, 0.9, 2.0], L = [1.0, 1.0, 1.3, 1.3, 1.0, 1.0], FILT = False)
#            pipeInData = gen_ramp(T = [0.0, 0.4, 1.5, 1.55,  1.6,  2.0], L = [0,  0,  15000, 15000, 0, 0], FILT = False)
#                pipeInData = gen_ramp(T = [0.0, 0.2, 0.25, 1.75,  1.8,  2.0], L = [1.0,  1.0,  5000.0, 5000.0, 1.0, 1.0], FILT = False)  # abrupt rise / fall
#            pipeInData = spike_train(firing_rate = 1000) 
        
        self.xemList[0].SendPipe(pipeInData)

    
    @pyqtSignature("int")
    def on_horizontalSlider_sliderMoved(self, position):
        """
        Slot documentation goes here.
        """
        self.onClkRate(position)
            
    @pyqtSignature("bool")
    def on_pushButton_2_clicked(self, checked):
        """
        Slot documentation goes here.
        """
        self.dispView.close()
        self.plotData(self.data)

    
    @pyqtSignature("int")
    def on_horizontalSlider_valueChanged(self, value):
        """
        Slot documentation goes here.
        """
        self.onClkRate(value)
    
    @pyqtSignature("bool")
    def on_pushButton_5_clicked(self, checked):
        """
        Slot documentation goes here.
        """
        newResetSim = checked
        self.xemList[0].SendButton(newResetSim, BUTTON_RESET_SIM)
    
    @pyqtSignature("bool")
    def on_pushButton_4_clicked(self, checked):
        """
        Slot documentation goes here.
        """
        newResetGlobal = checked
        self.xemList[0].SendButton(newResetGlobal, BUTTON_RESET)
    
    @pyqtSignature("bool")
    def on_pushButtonData_clicked(self, checked):
        """
        Slot documentation goes here.
        """
        self.isLogData = checked


#    @pyqtSignature("bool")
#    def on_checkbox_checked(self, state):
#        """
#        Slot documentation goes here.
#        """
#        if state == QtCore.Qt.Checked:
#            self.nerfModel.SendCheck()
        



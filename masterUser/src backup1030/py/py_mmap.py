#!/usr/bin/python
'''Python source designed to demonstrate the use of python embedding'''

import sys
import os
import time
import mmap
import threading

HOMEPATH = "/Network/Servers/duerer/guest/"
print 'homepath = ' + HOMEPATH


FPGA2ROBOT_FILENAME = HOMEPATH +"prog/masterUser/src/fpga2robot.dat"

print 'file path = %s' % FPGA2ROBOT_FILENAME
#FPGA2ROBOT_FILENAME = '/Network/Servers/duerer/guest/prog/masterUser/src/fpga2robot.dat'
ROBOT2FPGA_FILENAME = '%s/prog/masterUser/src/robot2fpga.dat' % HOMEPATH

LENGTHDATAMAP = 1024
        
class Robot:
    def __init__(self):
        self.fpga2robot_DataFile = open(FPGA2ROBOT_FILENAME, 'r+')
        print 'fpga2robot_DataFile size: ', os.path.getsize(FPGA2ROBOT_FILENAME), 'MMAP size: ', LENGTHDATAMAP
        self.fpga2robot_No = self.fpga2robot_DataFile.fileno()
        print 'fpga2robot_No=%d' %(self.fpga2robot_No)  #  why is fileno 3. 
        
        self.fpga2robot_map = mmap.mmap(self.fpga2robot_No, LENGTHDATAMAP, access=mmap.ACCESS_WRITE)
        self.fpga2robot_map.seek(0)    # simple test of validity
    
    
        self.robot2fpga_DataFile = open(ROBOT2FPGA_FILENAME, 'r+')  
        print 'robot2fpga_DataFile size: ', os.path.getsize(ROBOT2FPGA_FILENAME), 'MMAP size: ', LENGTHDATAMAP
        self.robot2fpga_No = self.robot2fpga_DataFile.fileno()
        
        self.robot2fpga_map = mmap.mmap(self.robot2fpga_No, LENGTHDATAMAP, access=mmap.ACCESS_READ)
        self.robot2fpga_map.seek(0)    # simple test of validity
    
    #def run(self):
        #x = 567
        #fpga2robot_map.write('%d' %x + '\n')

        #for i in range(10000):
            ## read out from the file to verify
            #fpga2robot_map.seek(0)
            #y = fpga2robot_map.readline()
            ##print 'Python thread read from MMAP:', y
            #fpga2robot_map.seek(0)
            #fpga2robot_map.write('%d' %i + '\n')
            ##print 'Python thread write back to MMAP:', 100 - i 
            #time.sleep(0.1)

        #fpga2robot_DataFile.close()
        
    def write(self, num):    # write to robot
        self.fpga2robot_map.seek(0)    # simple test of vUsalidityCONFIG_XENO_OPT_WATCHDOG_TIMEOUT=4
        #print str(format(num))
        if num > 0:
            safeNum = min(num, 10.0)   # safeGuard to the robot
        else:
            safeNum = max(num, -10.0)
        #print "safe torque: %f" %safeNum
        self.fpga2robot_map.write('%s' %num + '\n')   # write as string 
        #print 'num: %f' %num 
        #print type(num)
        #print "write to robot %d" % num
           
          
    def read(self):  # read from robot
        # TODO: read from Shaal robot
        self.robot2fpga_map.seek(0)    # simple test of validity
        dataLine = self.robot2fpga_map.readline()
        dataList = dataLine.split('\t')
        return float(dataList[0]), float(dataList[1])
        #print 'read from robot: %s' %dataOut
        
        #dataOut = 1.0
        #print "Read from robot %d" % num
        
    def format(value):
        return "%.1f" % value
    
    
    def angle2length(self, angle):
        length = 1.8 + (0.2-1.8) / (3.14)* angle     # angle in rad 
        return length
        
    def timeStamped(self, data):
        #return str(datetime.datetime.now()) +' '+str(data)+  '\n'
        return strftime("%Y-%m-%d %H:%M:%S", gmtime())
        

if __name__ == "__main__":
    import sys
    import WaveGen
    import datetime
    from time import gmtime, strftime
    from Utilities import *
    
    #from generate_sin import gen as gen_sin
    #sys.path.append('/home/eric/nerf_verilog_eric/source/py')
    
    import platform
    arch = platform.architecture()[0]
    if arch == "32bit":
        from opalkelly_32bit import ok
    elif arch == "64bit":
        from opalkelly_64bit import ok
    
    BIT_FILE = '%s/prog/masterUser/src/one_joint_robot_xem6010.bit' % HOMEPATH
    BIT_FILE2 = '%s/prog/masterUser/src/one_joint_robot_xem6010.bit' % HOMEPATH
    #BIT_FILE2 = "/home/eric/robot_simulator/prog/masterUser/src/sinewave_sender_xem6010.bit"
    
    from Fpga import FpgaDevice
    BIT_FILE_LIST = [BIT_FILE,  BIT_FILE2]
    #BIT_FILE_LIST = [BIT_FILE]
    
    ## 
    rawxem = ok.FrontPanel()
    #count = 2
    count = rawxem.GetDeviceCount()
    print "Found %d devices" % count
    assert count == 2, "Missing enough FPGA boards!"
    
    xemList = []

    #BIT_FILE_LIST = [BIT_FILE]
    for i in xrange(count):
        
        serX = rawxem.GetDeviceListSerial(i)
        print "serial = ",  serX    
        nerfModel = FpgaDevice(serX,  BIT_FILE_LIST[i])
        nerfModel.onClkRate(10) # 1x realtime
        xemList.append(nerfModel)
        
        
    # test WaveGen
    import os
    from WaveGen.utils import importPluginModulesIn, findPluginCreator
    plugin_path = os.path.dirname(WaveGen.__file__) + '/plugins'
    plugin_name = "Sine"
    
    available_plugins = importPluginModulesIn(plugin_path)
    plugin_creator = findPluginCreator(plugin_name, available_plugins)
    
    #sampling rate 1024
    param = {'SAMPLING_RATE' : 128, \
    'BIAS' : 0.0, \
    'F': 1.0, \
    'AMP': 20.0}
    T=2.0
    #param = {'SAMPLING_RATE' : 100, \
    #'TIME' :  [0.0, 0.2, 0.4, 1.0], \
    #'VALUE' : [0.0, 30.0, 30.0, 0.0]}
    #T = 1.0
    
    #T = 2.0  # length of data in s
    selected_plugin = plugin_creator(**param)
    waveform = WaveGen.SomeWave()
    waveform.bind(selected_plugin)
    
    square_wave = waveform.getAll(T = T)

    
    #xemList[0].SendPipe(sin_wave)
    
    
    # TODO: instantiate a FPGA object
    #xem0 = FpgaDevice()
    #xem0.onClkRate(10) # 1x real-time   
    
    shaal = Robot()
    desiredLen = 1.0;
    coeff = -10.0;
    currentLen = 1.3;
    TRIG_EVENT_GAIN = 1;
    TRIG_EVENT_LCE = 8;
    TRIG_EVENT_VEL = 9;
    TRIG_EVENT_GAIN_SYN = 6;
    deltaLen=0.0;
    moment_arm = 0.01;
    BUTTON_RESET_SIM = 1;
    
    ## SEND SINEWAVE ALWAYS 
    #pipeInData = gen_sin(F = 2.0, BIAS = 105.0, AMP = 75.0,  T = 2.0)  #1 Hz realtime. , T matters. T=2 is default. 
    #pipeInData = gen_sin(F = 1.0, BIAS = 50.0, AMP = 50.0, T=2.0) 
    #xem0.SendPipe(pipeInData)e
        
    
    
    # RESET FPGAs
    xemList[0].SendButton(True, BUTTON_RESET_SIM)
    xemList[1].SendButton(True, BUTTON_RESET_SIM)
    xemList[0].SendButton(False, BUTTON_RESET_SIM)
    xemList[1].SendButton(False, BUTTON_RESET_SIM)
    


    GAIN = ConvertType(30.0, fromType = 'f', toType = 'I')
    GAIN_SYN = ConvertType(1.0, fromType = 'f', toType = 'I')
    xemList[0].SendPara(GAIN_SYN, trigEvent = TRIG_EVENT_GAIN_SYN)   # send to FPGA (biceps)
    xemList[1].SendPara(GAIN_SYN, trigEvent = TRIG_EVENT_GAIN_SYN)   # send to FPGA (triceps)

    xemList[0].SendPara(GAIN, trigEvent = TRIG_EVENT_GAIN)   # send to FPGA (biceps)
    xemList[1].SendPara(GAIN, trigEvent = TRIG_EVENT_GAIN)   # send to FPGA (triceps)
    
    xemList[0].SendButton(True, BUTTON_RESET_SIM)
    xemList[1].SendButton(True, BUTTON_RESET_SIM)
    xemList[0].SendButton(False, BUTTON_RESET_SIM)
    xemList[1].SendButton(False, BUTTON_RESET_SIM)
    
    bitVal_bic = ConvertType(1.0, fromType = 'f', toType = 'I')
    bitVal_tri = ConvertType(1.0, fromType = 'f', toType = 'I')
    xemList[0].SendPara(bitVal_bic, trigEvent = TRIG_EVENT_LCE)   # send to FPGA (biceps)
    xemList[1].SendPara(bitVal_tri, trigEvent = TRIG_EVENT_LCE)   # send to FPGA (triceps)
    
    writeFilePath='../logfile'
    f = open(writeFilePath, 'w')
    
    basetime = round(time.time()*1000)    # current time in milisecond
      
    i = 0
    while (1):     

        biceps_force = xemList[1].ReadFPGA(0x30, 'float32') # 0x30: force
        biceps_emg = xemList[1].ReadFPGA(0x26, 'int32') # 0x26: i_emg
        triceps_force = xemList[0].ReadFPGA(0x30, 'float32') # 0x30: force 
        
        # TODO Data logging from FPGA (e.g. emg data)
        
        
    
        # WRITE TIME LOG TO FILE 
        currentTime = round(time.time()*1000)    # current time in milisecond
        elapsedTime = currentTime - basetime
        #print biceps_force
        f.write(str(elapsedTime)+'\t'+str(triceps_force)+'\n')
 
        
        
        # TODO: force to torque        
        biceps_torque = biceps_force * moment_arm
        triceps_torque = triceps_force * moment_arm
        
        #print '**biceps_force = %f,  triceps_force = %f' %(biceps_force, triceps_force)
        
        ext_torque = waveform.getNext() 
        net_torque = -(biceps_torque - triceps_torque) #  + ext_torque;
        #net_torque = triceps_torque;  # for now   
        
        #ext_torque = square_wave[i]
        #i = (i+1) % 1024
        #print 'ext torq: %f' % ext_torque

        
        #err = desiredLen - currentLen;
        #muscleForce = err * coeff;
        #print 'muscleForce: %f' %muscleForce
        
        shaal.write(net_torque*1.5)  # write to robot
        currentAngle, currentAngularVel = shaal.read()    # read from robot

        #print "python reporting Angle: %f    %f" % (currentAngle, currentAngularVel)
        # currentLen = desiredLen + deltaLen;
        #print 'currentAngle = %f' % currentAngle
        
        # TODO convert angle to length, moment arm missing.       
        currentLen_bic = shaal.angle2length(currentAngle);
        currentLen_tri = 2.0 - currentLen_bic; 
        currentVel_bic = - shaal.angle2length(currentAngularVel);
        currentVel_tri = -currentVel_bic;
        #print "python reporting currentAngle: %f, bic_len: %f,   tri_len: %f, net_torque: %f " % (currentAngle, currentLen_bic, currentLen_tri, net_torque)
        #currentLen_bic = currentAngle; 
        
        #print 'currentLen_bic = %f,  currentLen_tri = %f' % (currentLen_bic, currentLen_tri)
        
        
        bitVal_bic = ConvertType(currentLen_bic, fromType = 'f', toType = 'I')
        bitVal_tri = ConvertType(currentLen_tri, fromType = 'f', toType = 'I')
        bitVal_vel_bic = ConvertType(currentVel_bic, fromType = 'f', toType = 'I')
        bitVal_vel_tri = ConvertType(currentVel_tri, fromType = 'f', toType = 'I')

        xemList[0].SendPara(bitVal_bic, trigEvent = TRIG_EVENT_LCE)   # send to FPGA (biceps)
        xemList[1].SendPara(bitVal_tri, trigEvent = TRIG_EVENT_LCE)   # send to FPGA (triceps)
        xemList[0].SendPara(bitVal_vel_bic, trigEvent = TRIG_EVENT_VEL)   # send to FPGA (biceps)
        xemList[1].SendPara(bitVal_vel_tri, trigEvent = TRIG_EVENT_VEL)   # send to FPGA (triceps)
        

        
        #time.sleep(0.01)
            

    


    

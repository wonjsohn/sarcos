#!/usr/bin/python
'''Python source designed to demonstrate the use of python embedding'''

import sys
import os
import time
import mmap
import threading

HOMEPATH = "/Network/Servers/duerer/guest/"
#HOMEPATH = "/home/eric/"
print 'homepath = ' + HOMEPATH


FPGA2ROBOT_FILENAME = HOMEPATH +"prog/masterUser/src/fpga2robot.dat"

print 'file path = %s' % FPGA2ROBOT_FILENAME
#FPGA2ROBOT_FILENAME = '/Network/Servers/duerer/guest/prog/masterUser/src/fpga2robot.dat'
ROBOT2FPGA_FILENAME = HOMEPATH + "prog/masterUser/src/robot2fpga.dat"

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
        max_length = 1.8
        length = max_length + ((2.0-max_length)-max_length) / (3.14)* angle     # angle in rad 
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
    
    #BIT_FILE = HOMEPATH + "prog/masterUser/src/one_joint_robot_xem6010.bit" 
    #BIT_FILE2 = HOMEPATH + "prog/masterUser/src/one_joint_robot2_xem6010.bit"
    
    BIT_FILE = HOMEPATH + "prog/masterUser/src/one_joint_robot_all_in1_xem6010.bit"
    
    
    print BIT_FILE + " is here"
    print BIT_FILE2
    #assert os.path.exists(BIT_FILE.encode('utf-8')), ".bit file NOT found!"
    
    #assert os.path.exists(BIT_FILE2.encode('utf-8')), ".bit file NOT found!"
    
    #BIT_FILE2 = "/home/eric/robot_simulator/prog/masterUser/src/sinewave_sender_xem6010.bit"
    
    from Fpga import FpgaDevice
    BIT_FILE_LIST = [BIT_FILE,  BIT_FILE]
    #BIT_FILE_LIST = [BIT_FILE]
    
    ## 
    #rawxem = ok.FrontPanel()
    #count = 2
    #count = rawxem.GetDeviceCount()
    #print "Found %d devices" % count
    #assert count == 2, "Missing enough FPGA boards!"
    
    xemList = []
    
    """ simulation speed  """
    sim_speed = 10   # 10 is 1x realtime 

    """ Device registration """
    #for i in xrange(count):    
        #serX = rawxem.GetDeviceListSerial(i)
        #print "serial = ",  serX    
        #nerfModel = FpgaDevice(serX,  BIT_FILE_LIST[i])
        #nerfModel.onClkRate(10) # 1x realtime
        #xemList.append(nerfModel)
    
    """ Typing in the series numbers directly for each boards"""  
    """ working board choices: 1137000222  /  1201000216/  12320003RM / 12320003RN """    
    
    #nerfModel = FpgaDevice("1201000216",  BIT_FILE_LIST[0])
    #print "serial = 1201000216  \n"
    #nerfModel.onClkRate(sim_speed) # 1x realtime
    #xemList.append(nerfModel)
    #nerfModel = FpgaDevice("12320003RM",  BIT_FILE_LIST[1])  # transcortical part
    #print "serial = 12320003RM :  \n"
    #nerfModel.onClkRate(sim_speed) # 1x realtime
    #xemList.append(nerfModel)
    
    #nerfModel = FpgaDevice("1137000222",  BIT_FILE_LIST[0])
    #print "serial = 1137000222  \n"
    #nerfModel.onClkRate(sim_speed) # 1x realtime
    #xemList.append(nerfModel)
     

    #nerfModel = FpgaDevice("12320003RN",  BIT_FILE_LIST[1])  # transcortical part
    #print "serial = 12320003RN   \n"
    #nerfModel.onClkRate(sim_speed) # 1x realtime
    #xemList.append(nerfModel)
    



    
    
    """ test WaveGen """
    import os
    import csv
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
    
    shaal = Robot()
    desiredLen = 1.0;
    coeff = -10.0;
    currentLen = 1.3;
    TRIG_EVENT_PPS_COEFF = 1;
    TRIG_EVENT_GAIN_CN_to_MN = 3;
    TRIG_EVENT_GAIN_SN_to_MN = 6;
    TRIG_EVENT_GAIN_CN2_to_MN = 9;
    #TRIG_EVENT_LCE = 8;
    #TRIG_EVENT_VEL = 9;
    TRIG_EVENT_LCE_VEL_CNDRIVE = 10;
    #TRIG_EVENT_GAIN_SYN = 6;
    #TRIG_EVENT_SPINDLE_BIAS = 11;
    TRIG_EVENT_GAIN_SN_to_CN = 12;
    deltaLen=0.0;
    moment_arm = 0.01;
    BUTTON_RESET_SIM = 1;
    
    
    """ SEND SINEWAVE ALWAYS  """
    #pipeInData = gen_sin(F = 2.0, BIAS = 105.0, AMP = 75.0,  T = 2.0)  #1 Hz realtime. , T matters. T=2 is default. 
    #pipeInData = gen_sin(F = 1.0, BIAS = 50.0, AMP = 50.0, T=2.0) 
    #xem0.SendPipe(pipeInData)e
        
    
    
    """ RESET FPGAs  """
    # current convention = board '0': biceps /  board '1': triceps (two board setting) 
    #xemList[0].SendButton(True, BUTTON_RESET_SIM)   # send to FPGA (biceps)
    #xemList[1].SendButton(True, BUTTON_RESET_SIM)   # send to FPGA (triceps)
    #xemList[0].SendButton(False, BUTTON_RESET_SIM)
    #xemList[1].SendButton(False, BUTTON_RESET_SIM)
    #xemList[2].SendButton(True, BUTTON_RESET_SIM)  
    #xemList[3].SendButton(True, BUTTON_RESET_SIM)
    #xemList[2].SendButton(False, BUTTON_RESET_SIM)
    #xemList[3].SendButton(False, BUTTON_RESET_SIM)
       
   
    
    #xemList[0].SendButton(True, BUTTON_RESET_SIM)
    #xemList[1].SendButton(True, BUTTON_RESET_SIM)
    #xemList[0].SendButton(False, BUTTON_RESET_SIM)
    #xemList[1].SendButton(False, BUTTON_RESET_SIM)
    #xemList[2].SendButton(True, BUTTON_RESET_SIM)
    #xemList[3].SendButton(True, BUTTON_RESET_SIM)
    #xemList[2].SendButton(False, BUTTON_RESET_SIM)
    #xemList[3].SendButton(False, BUTTON_RESET_SIM)
    
    """ Set spindle gamma drives """

    TRIG_EVENT_GAMMA_DYN = 4
    TRIG_EVENT_GAMMA_STA = 5

    gamma_dynamic = ConvertType(80.0, fromType = 'f', toType = 'I')
    gamma_static = ConvertType( 80.0, fromType = 'f', toType = 'I')

    #xemList[0].SendPara( gamma_dynamic, trigEvent = TRIG_EVENT_GAMMA_DYN)
    #xemList[0].SendPara( gamma_static, trigEvent = TRIG_EVENT_GAMMA_STA)

    #xemList[1].SendPara( gamma_dynamic, trigEvent = TRIG_EVENT_GAMMA_DYN)
    #xemList[1].SendPara( gamma_static, trigEvent = TRIG_EVENT_GAMMA_STA)


    """ Set initial length """
    bitVal_bic = ConvertType(1.0, fromType = 'f', toType = 'I')
    bitVal_tri = ConvertType(1.0, fromType = 'f', toType = 'I')
    bitVal_vel_bic = ConvertType(1.0, fromType = 'f', toType = 'I')
    bitVal_vel_tri = ConvertType(1.0, fromType = 'f', toType = 'I')
    i_zero = ConvertType(0.0, fromType = 'f', toType = 'I')
    #xemList[0].SendMultiPara(bitVal_bic, bitVal_vel_bic, 0, 0, trigEvent = TRIG_EVENT_LCE_VEL_CNDRIVE)   # send to FPGA (biceps)
    #xemList[1].SendMultiPara(bitVal_tri, bitVal_vel_tri, 0, 0, trigEvent = TRIG_EVENT_LCE_VEL_CNDRIVE)   # send to FPGA (triceps)
    
    
    GAIN = ConvertType(20.0, fromType = 'f', toType = 'I')  #  
    
    #xemList[0].SendPara(GAIN, trigEvent = TRIG_EVENT_PPS_COEFF)   # send to FPGA (biceps)
    #xemList[1].SendPara(GAIN, trigEvent = TRIG_EVENT_GAIN)   # 
    #xemList[1].SendPara(GAIN, trigEvent = TRIG_EVENT_PPS_COEFF)   # send to FPGA (triceps)
    #xemList[3].SendPara(GAIN, trigEvent = TRIG_EVENT_GAIN)   # 
    
    
    """ setting synapse gain """
    #DON'T DO THIS =>>>  GAIN_SYN_BIC = ConvertType(10.0, fromType = 'f', toType = 'I')
    #DON'T DO THIS =>>>  GAIN_SYN_TRI = ConvertType(10.0, fromType = 'f', toType = 'I')

    synapseGain = 0
    #xemList[0].SendPara(synapseGain, trigEvent = TRIG_EVENT_GAIN_CN_to_MN)   # send to FPGA (biceps)
    #xemList[0].SendPara(10, trigEvent = TRIG_EVENT_GAIN_SN_to_MN) 
    #xemList[0].SendPara(0, trigEvent = TRIG_EVENT_GAIN_CN2_to_MN) 
    #xemList[0].SendPara(synapseGain, trigEvent = TRIG_EVENT_GAIN_SN_to_CN) 
    #xemList[1].SendPara(10, trigEvent = TRIG_EVENT_GAIN_SYN)   # 
    #xemList[1].SendPara(synapseGain,  trigEvent = TRIG_EVENT_GAIN_CN_to_MN)   # send to FPGA (triceps)
    #xemList[1].SendPara(10,  trigEvent = TRIG_EVENT_GAIN_SN_to_MN) 
    #xemList[1].SendPara(0,  trigEvent = TRIG_EVENT_GAIN_CN2_to_MN) 
    #xemList[1].SendPara(synapseGain,  trigEvent = TRIG_EVENT_GAIN_SN_to_CN) 
    #xemList[3].SendPara(10, trigEvent = TRIG_EVENT_GAIN_SYN)   # 
    
    
    """ set trigger data """
    #xemList[0].SendPara(GAIN_SYN_BIC, trigEvent = TRIG_EVENT_GAIN_SYN)   # send to FPGA (biceps)

    
    
    """ log data writing etc """ 
    writeFilePath= HOMEPATH + "prog/masterUser/src/logfile_pre"
    f = open(writeFilePath, 'w')  
    basetime = round(time.time()*1000)    # current time in milisecond
      
    """ running loop """   
    i = 0
    
    storage = []
    input_torque = []
    """ reading csv"""
    cr = csv.reader(open("outfile.csv","rb"))
    for row in cr:   
        input_torque.append(float(row[29]))
    
    #print input_torque
    
    while (1):     
    #for i in xrange(1, 10):
        time.sleep(1.0/540)
        i = i + 1
        if i == len(input_torque):
            i = 0
        
        

        #biceps_force = xemList[0].ReadFPGA(0x30, 'float32') # 0x30: force
        #biceps_emg = xemList[0].ReadFPGA(0x32, 'int32') # 0x32: i_emg
        #(biceps_force,  biceps_emg) = xemList[0].ReadMultiFPGA(0x30, 'float32',  0x26, 'int32') # 0x30: force
        #biceps_spindleFR = xemList[0].ReadFPGA(0x22, 'float32') # 0x30: force
        #biceps_SN_spkcnt = xemList[0].ReadFPGA(0x24, 'int32') # 0x30: force
        #biceps_MN_spkcnt = xemList[0].ReadFPGA(0x26, 'int32') # 0x30: force
        
        #biceps_force = xemList[0].ReadFPGA(0x30, 'float32') # 0x30: force
        #biceps_emg = xemList[0].ReadFPGA(0x32, 'int32') # 0x30: force
    
        
        
        
        #biceps_I_synapse_CN1 = xemList[1].ReadFPGA(0x20, 'int32') # 0x20 
        #biceps_I_synapse_CN2 = xemList[1].ReadFPGA(0x22, 'int32') # 0x20 
        #biceps_I_synapse_CN3 = xemList[1].ReadFPGA(0x24, 'int32') # 0x20 
        #bicepsi_gain_syn = xemList[1].ReadFPGA(0x26, 'int32') # 0x20 
        
       #triceps_force = xemList[2].ReadFPGA(0x30, 'float32') # 0x30: force 
        #triceps_emg = xemList[2].ReadFPGA(0x32, 'int32') # 0x32: i_emg
        #(triceps_force,  triceps_emg) = xemList[1].ReadMultiFPGA(0x30, 'float32',  0x26, 'int32') # 0x30: force
       # triceps_spindleFR = xemList[1].ReadFPGA(0x22, 'float32') # 0x30: force
        #triceps_SN_spkcnt = xemList[1].ReadFPGA(0x24, 'int32') # 0x30: force
        #triceps_MN_spkcnt = xemList[1].ReadFPGA(0x26, 'int32') # 0x30: force
        #triceps_force=xemList[2].ReadFPGA(0x30, 'float32')
        #triceps_emg=xemList[2].ReadFPGA(0x32, 'int32')
        
        
        
        """Data logging from FPGA (e.g. emg data) """
        """ WRITE TIME LOG TO FILE """
        currentTime = round(time.time()*1000)    # current time in milisecond
        elapsedTime = currentTime - basetime
        #print biceps_force
        #print str(elapsedTime) + " <--- time  "  + str(triceps_force) + "<--- triceps force \n"
        

        """ force to torque """
        #biceps_torque = biceps_force * moment_arm
        #triceps_torque = triceps_force * moment_arm
        
        
        #print '**biceps_force = %f,  triceps_force = %f' %(biceps_force, triceps_force)
        
        #ext_torque = waveform.getNext() 
        currentAngle, currentAngularVel = shaal.read()    # read from robot
        #b = 1.4*0
        #net_torque = 1.2*(1.00*biceps_torque - 0.6*triceps_torque) - currentAngularVel*b
        
        #net_torque = triceps_torque;  # for now   

        #shaal.write(net_torque)  # write to robot
        
        shaal.write(input_torque[i])  # write to robot
        
        #print '**net_torque = %f\n' %   net_torque
        

        #print "python reporting Angle: %f    %f" % (currentAngle, currentAngularVel)
        # currentLen = desiredLen + deltaLen;
        #print 'currentAngle = %f' % currentAngle
        
        # TODO convert angle to length, moment arm missing.       
        #currentLen_bic = shaal.angle2length(currentAngle) + 0.02;
        #currentLen_tri = 2.04 - currentLen_bic; # - 0.1;
        #max_length =1.8;
        #currentVel_bic =  ((2.0-max_length)-max_length) / (3.14)* currentAngularVel;
        #currentVel_tri = -currentVel_bic;
        #print "CurrentAngle: %f, bic_len: %f,   tri_len: %f, net_torque: %f " % (currentAngle, currentLen_bic, currentLen_tri, net_torque)
        #currentLen_bic = currentAngle; 
        
        #print 'currentLen_bic = %f,  currentLen_tri = %f' % (currentLen_bic, currentLen_tri)
        #dampFactor = 1.0;
        #if (currentVel_bic < 0.0):
        #    currentVel_bic = 0.0;
        #if (currentVel_tri < 0.0):
        #    currentVel_tri = 0.0;
        
        #currentVel_bic_adjusted = dampFactor* currentVel_bic;
        #currentVel_tri_adjusted = dampFactor* currentVel_tri;
        
        #bitVal_bic = ConvertType(currentLen_bic, fromType = 'f', toType = 'I')
        #bitVal_tri = ConvertType(currentLen_tri, fromType = 'f', toType = 'I')
        #bitVal_vel_bic = ConvertType(currentVel_bic_adjusted, fromType = 'f', toType = 'I')
        #bitVal_vel_tri = ConvertType(currentVel_tri_adjusted, fromType = 'f', toType = 'I')
        
        #print 'print len: ' + str(bitVal_bic) + ' and ' +   str(bitVal_tri)



#        xemList[0].SendPara(bitVal_bic, trigEvent = TRIG_EVENT_LCE)   # send to FPGA (biceps)
#        xemList[2].SendPara(bitVal_tri, trigEvent = TRIG_EVENT_LCE)   # send to FPGA (triceps)
#        xemList[0].SendPara(bitVal_vel_bic, trigEvent = TRIG_EVENT_VEL)   # send to FPGA (biceps)
#        xemList[2].SendPara(bitVal_vel_tri, trigEvent = TRIG_EVENT_VEL)   # send to FPGA (triceps)
            
        #xemList[0].SendMultiPara(bitVal_bic, bitVal_vel_bic, 0, 0,  trigEvent = TRIG_EVENT_LCE_VEL_CNDRIVE)   # send to FPGA (biceps)
        #xemList[1].SendMultiPara(bitVal_tri, bitVal_vel_tri, 0, 0, trigEvent = TRIG_EVENT_LCE_VEL_CNDRIVE)   # send to FPGA (triceps)  TRIG_EVENT_SPINDLE_BIAS
        
        
        
        #f.write(str(elapsedTime)+'\t'+str(currentLen_bic)+'\t'+str(currentLen_tri)+'\t'+str(biceps_force)+'\t'+str(triceps_force)+ '\t'+str(biceps_emg)+'\t'+str(triceps_emg)+'\n'); #+str(biceps_spindleFR)+'\t'+str(triceps_spindleFR)+'\t'+str(biceps_SN_spkcnt)+'\t'+str(biceps_MN_spkcnt)+'\t'+str(triceps_SN_spkcnt)+'\t'+str(triceps_MN_spkcnt)+'\n'); 
                #+str(biceps_I_synapse_CN1)+'\t'+str(biceps_I_synapse_CN2)+'\t'+str(biceps_I_synapse_CN3)+'\t'+str(bicepsi_gain_syn)+'\n');
        #storage.append(elapsedTime)
        
        #i = i + 1
        #time.sleep(0.01)
            
    
    #print storage


    

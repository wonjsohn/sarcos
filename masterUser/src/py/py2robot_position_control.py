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


FPGA2ROBOT_FILENAME = HOMEPATH +"prog/masterUser/src/py2robot.dat"

print 'file path = %s' % FPGA2ROBOT_FILENAME
#FPGA2ROBOT_FILENAME = '/Network/Servers/duerer/guest/prog/masterUser/src/fpga2robot.dat'
ROBOT2FPGA_FILENAME = HOMEPATH + "prog/masterUser/src/robot2py.dat"

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
    

    def write(self, num):    # write to robot
        self.fpga2robot_map.seek(0)    # simple test of vUsalidityCONFIG_XENO_OPT_WATCHDOG_TIMEOUT=4
        #print str(format(num))
        if num > 0:
            safeNum = min(num, 10.0)   # safeGuard to the robot
        else:
            safeNum = max(num, -10.0)
        #print "safe torque: %f" %safeNum
        self.fpga2robot_map.write('%s' %num + '\n')   # write as string 

           
          
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
    

    
    """ simulation speed  """
    sim_speed = 10   # 10 is 1x realtime 

    



    
    
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

    
    shaal = Robot()

    

    
    """ log data writing etc """ 
    writeFilePath= HOMEPATH + "prog/masterUser/src/logfile_pre"
    f = open(writeFilePath, 'w')  
    basetime = round(time.time()*1000)    # current time in milisecond
      
    """ running loop """   
    i = 0
    
    storage = []
    input_torque = []
    input_angle = []
    input_angular_velocity = []
    """ reading csv"""
    #cr = csv.reader(open("outfile2.csv","rb"))
    cr = csv.reader(open("d00011.csv","rb"))
    for row in cr:   
        #input_torque.append(float(row[28]))
	#input_angle.append(float(row[24]))
	#input_angular_velocity.append( float(row[2]) )
    	if row[0] == "time (s)":	# TAG ROW 0        
		print row
	else:
		#time.append( float(row[0] ) )
		#load.append( float(row[5] ) )			
		#uff.append( float(row[8] ) )
		input_angle.append( float(row[1] ) )
		input_angular_velocity.append( float(row[2] ))
    #print input_torque
    
    while (1):     
        time.sleep(1.0/540)
        i = i + 1
        if i == len(input_angle):
            i = 0
        
        


        
        """Data logging from FPGA (e.g. emg data) """
        """ WRITE TIME LOG TO FILE """
        currentTime = round(time.time()*1000)    # current time in milisecond
        elapsedTime = currentTime - basetime
  
   
        currentAngle, currentAngularVel = shaal.read()    # read from robot

        shaal.write(input_angle[i])  # write to robot
   


    

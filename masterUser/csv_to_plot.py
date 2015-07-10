#! /usr/bin/python
# Open .csv log file, plot elbow feed forward force and elbow load

import sys
import numpy as np
from pylab import *
from struct import pack, unpack


import csv


def plot_csv(filein):
	time = []
	load = []
	uff = []
	joint_angle = []
	angular_velocity = []
	filename = filein	
	
	#with open('d00007.csv', 'rb') as f:
	with open(filename, 'rb') as f:	
		reader = csv.reader(f)
		for row in reader:
			if row[0] == "time (s)":	# TAG ROW 0        
				print row
			else:
				time.append( float(row[0] ) )
				load.append( float(row[5] ) )			
				uff.append( float(row[8] ) )
				joint_angle.append( float(row[1] ) )
				angular_velocity.append( float(row[2] ))

	subplots_adjust(hspace=0.5)

	subplot(4,1,1)
	plot(time, load)
	title("Right elbow load (Nm)")
	xlabel("time (s)")
	ylabel("Force (Nm)")
	grid()
	subplot(4,1,2)
	plot(time, uff)
	title("Right elbow feed forward force (Nm)")
	xlabel("time (s)")
	ylabel("Force (Nm)")
	grid()
	subplot(4,1,3)
	plot(time, joint_angle)
	title("Right elbow joint angle (rad)")
	xlabel("time (s)")
	ylabel("joint angle (rad)")
	grid()
	subplot(4,1,4)
	plot(time, angular_velocity)
	title("Right elbow joint angular velocity (rad/s)")
	xlabel("time (s)")
	ylabel("joint angular velocity (rad/s)")
	grid()
	show()


if __name__ == '__main__':
	
	filename = sys.argv[1]
	print filename
	plot_csv(filename)


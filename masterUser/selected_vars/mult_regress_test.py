#### This program generates regression coefficient for the selected variables
#### pre-ordered in the 'file2open'
#### First 4th = a0 + a1*2nd + a2*3rd  (e.g. 2nd: var in second column.
#### You only need to run this program once per each file2open.
#### output txt file with relavant name is generated in the /regressionData/
####
#### How to run: python mult_regress_test.py file2open
#### (with selected vars)
#### 
#### Author: Won Joon Eric Sohn (wonjoons@usc.edu)
####

from sys import argv
from scipy import stats
import matplotlib.pyplot as plt
import os
import numpy as np
from sklearn import  linear_model
import shutil  

def format(value):
    return "%.2f" % value
    
# Build X, Y from 2nd file
#file2open = 'd00104_patient_selected_vars'
#file2open = 'd00103_nohuman_selected_vars'
first, second = argv
second = os.path.splitext(second)[0]
file2open = second  # second argument is file to open


f = open(file2open +'.txt') # READ PLAYBACK DATA FOR EACH PERSON
lines = f.readlines()
x1 = []
x2 = []
y = []
for line in lines:
    line = line.replace("\n", "")
    vals = line.split(",")
    x1.append(float(vals[1])) # pos
    x2.append(float(vals[2])) # vel 
#    y.append(float(vals[3]))  # ufb (update)
    y.append(float(vals[5]))  # diff load (update)
x1 = np.array(x1)
x2 = np.array(x2)
y = np.array(y)

x1min = x1.min()
x1max = x1.max()
x2min = x2.min()
x2max = x2.max()
ymin = y.min()
ymax = y.max()

# linregress doesn't do multi regression, so we use sklearn
ones = np.ones(x1.shape)
x = np.vstack([x1, x2]).T # don't need ones for 
regr = linear_model.LinearRegression()
regr.fit( x, y )
#regr.predict([3000, 3]) 
print regr.intercept_, regr.coef_[0], regr.coef_[1]  #coefficients


# write coeff to txt file
filepath = '../regressionData/' +file2open +'_regressionCoeff.txt'
f = open(filepath, 'w')
f.write("%s" %format(regr.intercept_))
f.write(",%s" %format(regr.coef_[0]))
f.write(",%s" %format(regr.coef_[1]))



# make a copy of the current file named regressionCoeff.txt in the same directory
filepath_copy = '../regressionData/'+'regressionCoeff.txt'
f = open(filepath_copy, 'w')
f.write("%s" %format(regr.intercept_))
f.write(",%s" %format(regr.coef_[0]))
f.write(",%s" %format(regr.coef_[1]))



print("Residual sum of squares: %.2f"
      % np.mean((regr.predict(x) - y) ** 2))
# Explained variance score: 1 is perfect prediction
print('Variance score: %.2f' % regr.score(x, y))

# Plot outputs
plt.scatter(x1, x2, s=80, c=y, color='black')
plt.title("x, xdot to force mapping")
plt.axis([x1min, x1max, x2min, x2max])
cb = plt.colorbar()
cb.set_label('Force')

#plt.plot(x, regr.predict(x), color='blue',
  #       linewidth=3)

#plt.xticks(())
#plt.yticks(())

plt.show()






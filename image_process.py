

from PIL import Image
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import math

# preprocessing
# down convert image to 64 x smaller size
# convert image from cartesian to polar
# build table for every degree based on # of leds (angle + 3*ledsCount)

# display
# figure out wheel rotation rate
# sync display loop with ratation rate
# use time elapsed since last cycle to choose index of which colors to display


im = Image.open("/Users/haochen/Desktop/Haos/ledWheel/test_images/test_image.bmp")
#im = Image.open("/Users/haochen/Desktop/Haos/ledWheel/test_images/lena.bmp")

p = np.array(im)



# test case
#p = np.zeros([9,9]);
#p[4,:] = np.ones([1,9]);
#p[:,4] = np.ones([1,9]);

img_dim = p.shape;
origin = [math.ceil(img_dim[0]/2.0)-1, math.ceil(img_dim[1]/2.0)-1];

# take each index and calculate the corresponding polar values
# this assumes polar max radius = center to image corner
polar_table =  np.zeros([img_dim[0]*img_dim[1],5]);
index = 0;
for row in range(img_dim[0]):
	dy = row - origin[0];
	for col in range(img_dim[1]):
		dx = col - origin[1];
		r = math.sqrt(math.pow(dx, 2)+math.pow(dy, 2));
		# right axis = zero radian, clockwise positive in radian
		#theta = math.degrees((math.atan2(dy,dx)));
		theta = math.atan2(dy,dx);
		
		# for testing
		#polar_table[index] = [theta, r, p[row][col]]; 

		# for actual image
		#  [theta, radius, r, g, b];
		polar_table[index] = [theta, r, p[row][col][0], p[row][col][1], p[row][col][2]]; 
		
		# put a dot down when there is color for testing
		if p[row][col][0]>0 | p[row][col][1]>0 | p[row][col][2]>0:
			polar_table[index,2] = 1; 
		index = index+1;

ax = plt.subplot(111, projection='polar')
ax.set_theta_direction(-1);
ax.scatter(polar_table[:,0], polar_table[:,1], s=polar_table[:,2])
#ax.grid(True)
plt.show()

		
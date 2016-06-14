

from PIL import Image
import numpy as np
import matplotlib.pyplot as plt
import math


img = Image.open("/Users/haochen/Desktop/Haos/ledWheel/test_images/not_happy.png")
#img = Image.open("/Users/haochen/Desktop/Haos/ledWheel/test_images/img_test.bmp")
img = img.convert('RGB')
DOWN_IMG_SIZE = 128, 128
img.thumbnail(DOWN_IMG_SIZE, Image.ANTIALIAS)
img.show()
# convert image from cartesian to polar
# build table for every degree based on # of leds (angle + 3*ledsCount)

# display
# figure out wheel rotation rate
# sync display loop with ratation rate
# use time elapsed since last cycle to choose index of which colors to display

img_matrix = np.array(img)
img_dim = img_matrix.shape
origin = [math.ceil(img_dim[0]/2.0)-1, math.ceil(img_dim[1]/2.0)-1]

# take each index and calculate the corresponding polar values
# this assumes polar max radius = center to image corner
polar_table =  np.zeros([img_dim[0]*img_dim[1],5])

index = 0

for row in range(img_dim[0]):
    dy = row - origin[0]
    for col in range(img_dim[1]):
        dx = col - origin[1]
        r = math.sqrt(math.pow(dx, 2)+math.pow(dy, 2))
        # right axis = zero radian, clockwise positive in radian
        theta = math.degrees((math.atan2(dy,dx)))
        if theta < 0.0: # 0 to 360
            theta += 360
        # [theta, radius, r, g, b];
        polar_table[index] = [theta, r, img_matrix[row][col][0], img_matrix[row][col][1], img_matrix[row][col][2]]

        # put a dot down when there is color for testing
        #if img_matrix[row][col][0]<>0 | img_matrix[row][col][1]<>0 | img_matrix[row][col][2]<>0:
        #    polar_table[index,2] = 1
        index = index+1


# find nearest rgb value for each of the 16 leds 1 degree
polar_table_resampled = np.zeros([360,48])
for angle in range(0,360):
    for led_index in range(0,16):
        test_radius = led_index*(128/16.0)
        idx = (np.abs(angle-polar_table[:,0])+np.abs(test_radius-polar_table[:,1])).argmin()
        polar_table_resampled[angle][(led_index*3):(led_index*3+3)] = polar_table[idx,2:5]


# find nearest rgb value for each of the 16 leds 10 degree
polar_table_resampled = np.zeros([36,48])
for angle in range(0,36):
    for led_index in range(0,16):
        test_radius = led_index*(128/16.0)
        idx = (np.abs(angle*10-polar_table[:,0])+np.abs(test_radius-polar_table[:,1])).argmin()
        polar_table_resampled[angle][(led_index*3):(led_index*3+3)] = polar_table[idx,2:5]


polar_table_resampled.astype(int)
np.savetxt("/Users/haochen/Desktop/Haos/ledWheel/test_images/test.csv",polar_table_resampled, delimiter=',')
#
ax = plt.subplot(111, projection='polar')
ax.set_theta_direction(-1)
ax.scatter(polar_table[:,0]*(3.14/180), polar_table[:,1], s=polar_table[:,2])
#ax.grid(True)
plt.show()


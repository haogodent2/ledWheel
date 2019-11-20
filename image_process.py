from PIL import Image
import numpy as np
import matplotlib.pyplot as plt
import math


#defs
DEGREE_TO_RAD = math.pi/180

#params
TOTAL_DEGREES = 360
scan_divisons = int(360/2)
NUM_LEDS = 32
SAMPLING_RATIO = 10
CROP_RATIO = .4
Y_offset = 9 # positive up
X_offset = -2 # positive to the right
angle_offset = 0  # positive clock-wise

#flags
CONVERT_TO_POLAR = False   # convert to polar first or sample from cart. directly
show_preview = False


img_original = Image.open("/Users/haochen/Desktop/Haos/ledWheel/test_images/happy_face.jpg")
img_rgb = img_original.convert('RGB')

DESIRED_DIM = list(img_rgb.size)
if img_rgb.size[0] > img_rgb.size[1]:
	DESIRED_DIM[0] = NUM_LEDS * SAMPLING_RATIO
	DESIRED_DIM[1] = int(math.floor((img_rgb.size[1] / float(img_rgb.size[0])) * DESIRED_DIM[0]))
else:
	DESIRED_DIM[1] = NUM_LEDS * SAMPLING_RATIO
	DESIRED_DIM[0] = int(math.floor((img_rgb.size[0] / float(img_rgb.size[1])) * DESIRED_DIM[1]))

img = img_rgb.resize(DESIRED_DIM, Image.ANTIALIAS)

if show_preview:
	img.show()

MAX_RESAMPLE_RADIUS = DESIRED_DIM[0] * CROP_RATIO
img_matrix = np.array(img)
img_dim = img_matrix.shape
center = [math.ceil(img_dim[0] / 2.0)+Y_offset, math.ceil(img_dim[1] / 2.0)-X_offset]


angle = np.arange(0, TOTAL_DEGREES, TOTAL_DEGREES / float(scan_divisons))
test_radii = np.arange(0, NUM_LEDS) * (float)(MAX_RESAMPLE_RADIUS / NUM_LEDS)
polar_table_resampled = np.zeros([scan_divisons, NUM_LEDS * 3])
resampled_plot = np.zeros([scan_divisons * NUM_LEDS, 5])

increment = 0
for angle_index in range(0, scan_divisons):
	for led_index in range(0, NUM_LEDS):
		# theta clock-wise positive with 0 at right axis
		r = test_radii[led_index]
		theta = angle[angle_index]
		dx = int(r * math.cos(theta * DEGREE_TO_RAD))  # col
		dy = int(r * math.sin(theta * DEGREE_TO_RAD))  # row
		col_num = int(center[1]) + dx
		row_num = int(center[0]) + dy

		if col_num < 0:
			col_num = 0
		if col_num >= img_dim[1]:
			col_num = img_dim[1]-1
		if row_num < 0:
			row_num = 0
		if row_num >= img_dim[0]:
			row_num = img_dim[0]-1

		resampled_plot[increment][0] = angle[angle_index]+angle_offset
		resampled_plot[increment][1] = test_radii[led_index]
		resampled_plot[increment][2:5] = img_matrix[row_num][col_num][0:3]
		polar_table_resampled[angle_index][(led_index * 3):(led_index * 3 + 3)] = img_matrix[row_num][col_num][0:3]
		increment = increment + 1

np.savetxt("/Users/haochen/Desktop/Haos/ledWheel/test_images/led_img.csv", polar_table_resampled, fmt='%i',
				   delimiter=',')
prefix = '{'
suffix = '},'
with open("/Users/haochen/Desktop/Haos/ledWheel/test_images/led_img.csv", 'r') as src:
	with open("/Users/haochen/Desktop/Haos/ledWheel/test_images/led_img_cpp.csv", 'w') as dest:
		for line in src:
			dest.write('%s%s%s\n' % (prefix, line.rstrip('\n'), suffix))

ax = plt.subplot(111, projection='polar')
ax.set_theta_direction(-1)
ax.scatter(resampled_plot[:, 0] * (math.pi / 180), resampled_plot[:, 1], color=(resampled_plot[:, 2:5] / 255),s=5)
plt.show()

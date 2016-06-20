from PIL import Image
import numpy as np
import matplotlib.pyplot as plt
import math
import csv

TOTAL_DEGREES = 360
scan_divisons = 360*1
NUM_LEDS = 36
SAMPLING_RATIO = 10
CROP_RATIO = .5

Y_offset = 9 # positive up
X_offset = -2 # positive to the right
angle_offset = 0  # positive clock-wise

CONVERT_TO_POLAR = False   # convert to polar first or sample from cart. directly



img_original = Image.open("/Users/haochen/Desktop/Haos/ledWheel/test_images/lena.bmp")
img_rgb = img_original.convert('RGB')

DESIRED_DIM = list(img_rgb.size)
if img_rgb.size[0] > img_rgb.size[1]:
	DESIRED_DIM[0] = NUM_LEDS * SAMPLING_RATIO
	DESIRED_DIM[1] = int(math.floor((img_rgb.size[1] / float(img_rgb.size[0])) * DESIRED_DIM[0]))
else:
	DESIRED_DIM[1] = NUM_LEDS * SAMPLING_RATIO
	DESIRED_DIM[0] = int(math.floor((img_rgb.size[0] / float(img_rgb.size[1])) * DESIRED_DIM[1]))

# DESIRED_DIM = NUM_LEDS*SAMPLING_RATIO, NUM_LEDS*SAMPLING_RATIO
# img.thumbnail(DESIRED_DIM, Image.ANTIALIAS)
img = img_rgb.resize(DESIRED_DIM, Image.ANTIALIAS)

MAX_RESAMPLE_RADIUS = DESIRED_DIM[0] * CROP_RATIO
img_matrix = np.array(img)
img_dim = img_matrix.shape
center = [math.ceil(img_dim[0] / 2.0)+Y_offset, math.ceil(img_dim[1] / 2.0)-X_offset]

if CONVERT_TO_POLAR:
	print("converting to polar coordinate")
	# take each index and calculate the corresponding polar values
	# this assumes polar max radius = center to image corner
	polar_table = np.zeros([img_dim[0] * img_dim[1], 5])

	index = 0
	for row in range(img_dim[0]):
		dy = row - center[0]
		for col in range(img_dim[1]):
			dx = col - center[1]
			r = math.sqrt(math.pow(dx, 2) + math.pow(dy, 2))
			# right axis = zero radian, clockwise positive in radian
			theta = math.degrees((math.atan2(dy, dx)))
			if theta < 0.0:  # 0 to 360
				theta += 360
			# [theta, radius, r, g, b];
			polar_table[index] = [theta, r, img_matrix[row][col][0], img_matrix[row][col][1], img_matrix[row][col][2]]

			# put a dot down when there is color for testing
			# if img_matrix[row][col][0]<>0 | img_matrix[row][col][1]<>0 | img_matrix[row][col][2]<>0:
			# polar_table[index,2] = 1
			index = index + 1
	np.savetxt("/Users/haochen/Desktop/Haos/ledWheel/test_images/polar_table.csv", polar_table, fmt='%i',
			   delimiter=',')
	print("polar conversion completed")
	# ax = plt.subplot(111, projection='polar')
	# ax.set_theta_direction(-1)
	# ax.scatter(polar_table[:,0]*(3.14/180), polar_table[:,1], color=(polar_table[:,2:5]/255))
	# ax.grid(True)
	# plt.show()

	print("resampling for LED grid")
	# find nearest rgb value for each of the leds by scan division arc
	angle = np.arange(0, TOTAL_DEGREES, TOTAL_DEGREES / scan_divisons)
	test_radii = np.arange(0, NUM_LEDS) * (float)(MAX_RESAMPLE_RADIUS / NUM_LEDS)
	polar_table_resampled = np.zeros([scan_divisons, NUM_LEDS * 3])
	resampled_plot = np.zeros([scan_divisons * NUM_LEDS, 5])

	increment = 0
	for angle_index in range(0, scan_divisons):
		for led_index in range(0, NUM_LEDS):
			angle_diff = np.abs(polar_table[:, 0] - angle[angle_index])
			radii_diff = np.abs(polar_table[:, 1] - test_radii[led_index])
			diff_sum = angle_diff + radii_diff
			idx = diff_sum.argmin()
			polar_table_resampled[angle_index][(led_index * 3):(led_index * 3 + 3)] = polar_table[idx, 2:5]
			resampled_plot[increment][0:5] = np.concatenate(
				([angle[angle_index]], [test_radii[led_index]], polar_table[idx, 2:5]))
			increment = increment + 1

	polar_table_resampled.astype(int)
	print("resampling completed")

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
	ax.scatter(resampled_plot[:, 0] * (math.pi / 180), resampled_plot[:, 1], color=(resampled_plot[:, 2:5] / 255), s=7)
	plt.show()



# try resampling nearest neighbor directly from cartesian
else:
	angle = np.arange(0, TOTAL_DEGREES, TOTAL_DEGREES / float(scan_divisons))
	test_radii = np.arange(0, NUM_LEDS) * (float)(MAX_RESAMPLE_RADIUS / NUM_LEDS)
	polar_table_resampled = np.zeros([scan_divisons, NUM_LEDS * 3])
	resampled_plot = np.zeros([scan_divisons * NUM_LEDS, 5])
	print(resampled_plot.shape)
	increment = 0
	for angle_index in range(0, scan_divisons):
		for led_index in range(0, NUM_LEDS):
			# theta clock-wise positive with 0 at right axis
			r = test_radii[led_index]
			theta = angle[angle_index]
			dx = int(r * math.cos(theta * (math.pi / 180)))  # col
			dy = int(r * math.sin(theta * (math.pi / 180)))  # row
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
			increment = increment + 1

	print("resampling completed")

			# np.savetxt("/Users/haochen/Desktop/Haos/ledWheel/test_images/led_img.csv", polar_table_resampled, fmt='%i',
			#		   delimiter=',')
			# prefix = '{'
			# suffix = '},'
			# with open("/Users/haochen/Desktop/Haos/ledWheel/test_images/led_img.csv", 'r') as src:
			#	with open("/Users/haochen/Desktop/Haos/ledWheel/test_images/led_img_cpp.csv", 'w') as dest:
			#		for line in src:
			#			dest.write('%s%s%s\n' % (prefix, line.rstrip('\n'), suffix))

	ax = plt.subplot(111, projection='polar')
	ax.set_theta_direction(-1)
	ax.scatter(resampled_plot[:, 0] * (math.pi / 180), resampled_plot[:, 1], color=(resampled_plot[:, 2:5] / 255),s=4)
	plt.show()

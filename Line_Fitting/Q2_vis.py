import matplotlib.pyplot as plt

# define the points
x = [0, 1, 2, 3, 4, 5, 6]
y = [0, 1, 2, 3, 2, 1, 0]

# define the equations
eq1 = lambda x_val: 1.00*x_val + 0.00
eq2 = lambda x_val: -1.00*x_val + 6.00

# create the plot
fig, ax = plt.subplots()

# plot the points
ax.plot(x, y, 'bo')

# plot the lines
ax.plot(x, [eq1(x_val) for x_val in x], 'r-', label='y = 1.00x + 0.00')
ax.plot(x, [eq2(x_val) for x_val in x], 'g-', label='y = -1.00x + 6.00')

# set the labels and legend
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_title('Plot of Points and Lines')
ax.legend()

# display the plot
plt.show()

# import csv
# import matplotlib.pyplot as plt

# # read equations from CSV file
# equations = []
# with open('equations.csv') as csvfile:
#     reader = csv.reader(csvfile)
#     for row in reader:
#         equations.append(lambda x_val, a=float(row[0]), b=float(row[1]): a*x_val + b)

# # read points from CSV file
# points = []
# with open('points.csv') as csvfile:
#     reader = csv.reader(csvfile)
#     for row in reader:
#         points.append((float(row[0]), float(row[1])))

# # create the plot
# fig, ax = plt.subplots()

# # plot the points
# ax.scatter([p[0] for p in points], [p[1] for p in points], c='blue', marker='o')

# # plot the lines
# colors = ['red', 'green', 'orange', 'purple']  # add more colors if needed
# for i, eq in enumerate(equations):
#     ax.plot([p[0] for p in points], [eq(p[0]) for p in points], '-', label=f'y = {round(eq(0), 2)}x + {round(eq(1), 2)}', c=colors[i % len(colors)])

# # set the labels and legend
# ax.set_xlabel('X')
# ax.set_ylabel('Y')
# ax.set_title('Plot of Points and Lines')
# ax.legend()

# # display the plot
# plt.show()

# x,y
# 0,0
# 1,1
# 2,2
# 3,3
# 4,2
# 5,1
# 6,0

# equation,color,label
# 0.5*x+1.5,red,Line 1
# -0.25*x+2,green,Line 2
# 0.75*x-1,yellow,Line 3

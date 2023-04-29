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

# display the plot
plt.show()
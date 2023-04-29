import csv
import matplotlib.pyplot as plt

equations = []
with open('equations.csv') as csvfile:
    reader = csv.reader(csvfile)
    for row in reader:
        equations.append(lambda x_val, a=float(row[0]), b=float(row[1]): a*x_val + b)

points = []
with open('points.csv') as csvfile:
    reader = csv.reader(csvfile)
    for row in reader:
        points.append((float(row[0]), float(row[1])))

fig, ax = plt.subplots()

ax.scatter([p[0] for p in points], [p[1] for p in points], c='blue', marker='o')

colors = ['red', 'green', 'orange', 'purple']  # add more colors if needed
for i, eq in enumerate(equations):
    ax.plot([p[0] for p in points], [eq(p[0]) for p in points], '-', label=f'y = {round(eq(0), 2)}x + {round(eq(1), 2)}', c=colors[i % len(colors)])

ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_title('Plot of Points and Lines')
ax.legend()

plt.show()

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

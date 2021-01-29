import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.tri import Triangulation

import numpy as np

fig = plt.figure()
ax = Axes3D(fig)
x = int(input("eola name"))
x = np.linspace(-10, 10, 30)
y = np.linspace(-10, 10, 30)
#X, Y = np.meshgrid(x, y);

#tri = Triangulation(np.ravel(X), np.ravel(Y))

def f1(x, y):
    return x**2+5

ax.plot(x,y)

plt.show()
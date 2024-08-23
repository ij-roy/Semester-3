import numpy as np
import matplotlib.pyplot as plt

np.random.seed(10)

data1 = np.random.normal(100,10,200)
data2 = np.random.normal(200,10,400)
data3 = np.random.normal(150,20,200)
data4 = np.random.normal(100,20,200)
data = [data1,data2,data3,data4]

print(data)

fig = plt.figure(figsize=(10,7))
ax = fig.add_axes([0,0,1,1])
bp = ax.boxplot(data1)

plt.show()
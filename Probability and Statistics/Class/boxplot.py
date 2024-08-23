import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

data1 = [10,20,30,40]
labels = ['A', 'B', 'C', 'D']


plt.bar(labels,data1,color = 'blue',edgecolor = 'black')
# plt.boxplot(data1)

plt.ylabel("Number of People : ")
plt.xlabel("Something")

plt.show()

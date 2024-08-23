import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

data1 = [10,20,30,40]
data2 = [28,30,44,50]
data3 = [34,55,21,14]
data4 = [10,20,30,40]
t1 = ["A","B","C","D"]
d1 = np.array([data1,data2,data3,data4])
plt.ylabel("Number of People")
plt.xlabel("Something")
plt.bar(t1,data1)
plt.show()

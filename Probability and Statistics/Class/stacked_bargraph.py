import numpy as np
import matplotlib.pyplot as plt

data1 = [10, 20, 30, 40]
data2 = [28, 30, 44, 50]
data3 = [34, 55, 21, 14]
data4 = [10, 20, 30, 40]
t1 = ["A", "B", "C", "D"]

# Convert data to a numpy array (optional, just for convenience)
d1 = np.array(data1)
d2 = np.array(data2)
d3 = np.array(data3)
d4 = np.array(data4)

# Create a stacked bar chart
plt.bar(t1, d1, label='Data1')
plt.bar(t1, d2, bottom=d1, label='Data2')
plt.bar(t1, d3, bottom=d1 + d2, label='Data3')
plt.bar(t1, d4, bottom=d1 + d2 + d3, label='Data4')

# Add labels and legend
plt.ylabel("Number of People")
plt.xlabel("Something")
plt.legend()

# Display the plot
plt.show()

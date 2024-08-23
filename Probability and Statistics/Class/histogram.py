import matplotlib.pyplot as plt

# Data
marks = ['0-10', '10-20', '20-30', '30-40', '40-50', '50-60', '60-70', '70-80']
frequency = [2, 5, 8, 11, 10, 9, 4, 1]

# Create bar plot
plt.bar(marks, frequency)

# Add labels and title
plt.xlabel('Marks')
plt.ylabel('Frequency')
plt.title('Histogram (Equal Intervals)')

# Show the plot
plt.show()

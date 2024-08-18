# box_plot.py
import matplotlib.pyplot as plt
import seaborn as sns

# Data
mismanaged_waste = [5, 3, 50, 70, 40]  # in percentage

# Plot
plt.figure(figsize=(8, 6))
sns.boxplot(data=mismanaged_waste, orient='h')
plt.title('Mismanaged Plastic Waste Percentages')
plt.xlabel('Percentage')
plt.savefig('box_plot.png')
plt.show()

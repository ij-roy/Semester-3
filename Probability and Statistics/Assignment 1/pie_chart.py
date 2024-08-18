# pie_chart.py
import matplotlib.pyplot as plt

# Data
sources = ['Fishing Gear', 'Single-Use Plastics', 'Microplastics', 'Industrial Discharge', 'Other Sources']
percentages = [20, 40, 15, 10, 15]

# Plot
plt.figure(figsize=(8, 8))
plt.pie(percentages, labels=sources, autopct='%1.1f%%', startangle=140)
plt.title('Sources of Oceanic Plastic Pollution')
plt.savefig('pie_chart.png')
plt.show()

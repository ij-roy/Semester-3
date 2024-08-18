# bar_graph.py
import matplotlib.pyplot as plt

# Data
regions = ['North America', 'Europe', 'Asia', 'Africa', 'South America']
annual_waste = [42, 58, 142, 17, 23]  # in million metric tons

# Plot
plt.figure(figsize=(10, 6))
plt.bar(regions, annual_waste, color='teal')
plt.title('Annual Plastic Waste Generation by Region')
plt.xlabel('Region')
plt.ylabel('Annual Waste (Million Metric Tons)')
plt.savefig('bar_graph.png')
plt.show()

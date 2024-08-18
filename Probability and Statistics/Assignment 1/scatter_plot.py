# scatter_plot.py
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd

# Data
regions = ['North America', 'Europe', 'Asia', 'Africa', 'South America']
annual_waste = [42, 58, 142, 17, 23]  # in million metric tons
mismanaged_waste = [5, 3, 50, 70, 40]  # in percentage

# DataFrame for plotting
scatter_data = pd.DataFrame({
    'Region': regions,
    'Annual Waste (Million Metric Tons)': annual_waste,
    'Mismanaged Waste (%)': mismanaged_waste
})

# Plot
plt.figure(figsize=(10, 6))
sns.scatterplot(data=scatter_data, x='Annual Waste (Million Metric Tons)', y='Mismanaged Waste (%)', hue='Region')
plt.title('Scatter Plot of Annual Plastic Waste vs Mismanaged Waste')
plt.legend(loc='best')
plt.xlabel('Annual Waste (Million Metric Tons)')
plt.ylabel('Mismanaged Waste (%)')
plt.savefig('scatter_plot.png')
plt.show()

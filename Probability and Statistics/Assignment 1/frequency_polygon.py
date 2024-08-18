# frequency_polygon.py
import matplotlib.pyplot as plt

# Data
debris_density_regions = ['North Pacific Ocean', 'North Atlantic Ocean', 'Indian Ocean', 'Mediterranean Sea']
debris_density = [334271, 102245, 84426, 64854]  # pieces per square kilometer

# Plot
plt.figure(figsize=(10, 6))
plt.plot(debris_density_regions, debris_density, marker='o', linestyle='-', color='b')
plt.fill_between(debris_density_regions, debris_density, alpha=0.2, color='b')
plt.title('Plastic Debris Density in Ocean Regions')
plt.xlabel('Ocean Region')
plt.ylabel('Debris Density (pieces per km²)')
plt.savefig('frequency_polygon.png')
plt.show()

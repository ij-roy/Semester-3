'''
Question 5. Suppose a surface initially contained 2.19x10**14 bacterial cells. 
After some time, the surface contained 4.68x10**14 bacterial cells. 
Calculate the percentage of bacterial growth. Display the answer rounded to 
the nearest whole number.
'''
initial_value = 2.19 * (10**14)
final_value = 4.68 * (10**14)
percentage = ((final_value - initial_value)/initial_value) * 100
print(f"Percentage of bacterial growth is : {round(percentage)}%")
'''
Question 7. Print the following table to display the sin value and cos value of degrees from 0 to 
360 with increments of 10 degrees. Round the value to keep four digits after the decimal point
'''
import math

print(f"{'Degrees':<10}{'Sin':<15}{'Cos':<15}")

for degree in range(0, 361, 10):
    radians = math.radians(degree)
    
    sin_value = math.sin(radians)
    cos_value = math.cos(radians)
    
    print(f"{degree:<10}{sin_value:<15.4f}{cos_value:<15.4f}")

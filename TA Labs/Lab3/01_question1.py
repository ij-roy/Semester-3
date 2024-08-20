'''
Question 1. Write a program that prompts the user to enter the three points (x1, y1), 
(x2, y2) , and (x3 , y3) of a triangle and displays its area. 
The formula for computing the area of a triangle is
s = (side1 + side2 + side3) / 2
area = √[s(s - side1)(s - side2)(s - side3)]
'''
#importing a library 
import math

x1 = int(input("Enter Value of x1 : "))
y1 = int(input("Enter Value of y1 : "))
x2 = int(input("Enter Value of x2 : "))
y2 = int(input("Enter Value of y2 : "))
x3 = int(input("Enter Value of x3 : "))
y3 = int(input("Enter Value of y3 : "))

# Calculate the lengths of the sides of the triangle
side1 = math.sqrt((x2 - x1)**2 + (y2 - y1)**2)
side2 = math.sqrt((x3 - x2)**2 + (y3 - y2)**2)
side3 = math.sqrt((x1 - x3)**2 + (y1 - y3)**2)

# Compute the semi-perimeter of the triangle
s = (side1 + side2 + side3) / 2

# Compute the area of the triangle using Heron's formula
area = math.sqrt(s * (s - side1) * (s - side2) * (s - side3))

# Display the area
print(f"The area of the triangle is: {area:.2f}")
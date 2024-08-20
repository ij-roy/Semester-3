'''
Question 2. Write a program that prompts the user to enter the side of a hexagon 
and displays its area. The formula for computing the area of a hexagon is 
Area = (3√3 / 2) * s2 , where s is the length of a 
side
'''
import math
side = int(input("Enter The Length of Side of a Hexagon : "))
area = (3 * math.sqrt(3) / 2) * side ** 2
print(f"The area of the hexagon is: {area:.2f}")
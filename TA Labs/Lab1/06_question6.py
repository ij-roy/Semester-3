'''
Question 6. Find the area of a Circle of radius r. 
Only radius between 1 and 100 should be accepted.
'''

radius = int(input("Enter the radius of the circle : "))
while radius>100 or radius<1:
    print("Only radius between 1 and 100 is accepted")
    radius = int(input("Enter the radius of the circle : "))

print(f"The area of the circle with radius {radius} is {3.14*radius*radius:.2f}")

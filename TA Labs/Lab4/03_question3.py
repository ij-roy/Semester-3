'''
Question 3.  Write a program that reads input data from the console  - the measures 
of a geometric shape and calculates  its  area.  There  are  four  types  of 
shapes: square, rectangle, circle and triangle. 
The first line of input is the type of shape (square, rectangle, circle, triangle): 
    If the shape is a square, the next argument will be one number - the length of 
    its side. 
    If the shape is a rectangle, the next argument will be two numbers - the lengths 
    of its sides. 
    If the shape is a circle, the next argument will be one number - the radius of 
    the circle. 
    If the shape is a triangle, the next argument will be two numbers - its base and 
    the corresponding altitude. 
The result should be rounded up to the third decimal point.
'''
type = input("Enter type of shape (square, rectangle, circle, triangle): ").lower()

# Check if the input is not one of the valid shapes
while type not in ["square", "rectangle", "circle", "triangle"]:
    print("Invalid Input! Please enter a valid shape.")
    type = input("Enter type of shape (square, rectangle, circle, triangle): ").lower()
if type == "square":
        side = float(input("Enter length of side: "))
        area = side ** 2
elif type == "rectangle":
    length = float(input("Enter length of rectangle: "))
    width = float(input("Enter width of rectangle: "))
    area = length * width
elif type == "circle":
    radius = float(input("Enter radius of circle: "))
    area = 3.14 * (radius ** 2)
elif type == "triangle":
    base = float(input("Enter base of triangle: "))
    height = float(input("Enter height of triangle: "))
    area = 0.5 * base * height
print(f"The area of the {type} is: {area:.3f}")
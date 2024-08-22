'''
Question 9. Enter the coefficients of a quadratic equation and display its solutions. 
Handle all the cases for invalid input and display the solutions till exactly 2 
decimal places. You need not calculate the complex solutions.
'''
import math
a = float(input("Enter the coefficient a: "))
b = float(input("Enter the coefficient b: "))
c = float(input("Enter the coefficient c: "))
if a == 0:
        print("Coefficient 'a' cannot be zero in a quadratic equation.")
else:
    # Calculate the discriminant
    discriminant = b**2 - 4*a*c

    # Handle different cases based on the discriminant
    if discriminant > 0:
        # Two real and distinct roots
        root1 = (-b + math.sqrt(discriminant)) / (2 * a)
        root2 = (-b - math.sqrt(discriminant)) / (2 * a)
        print(f"The solutions are {root1:.2f} and {root2:.2f}")
    elif discriminant == 0:
        # One real and repeated root
        root = -b / (2 * a)
        print(f"The solution is {root:.2f}")
    else:
        # No real solutions (discriminant < 0)
        print("There are no real solutions for this quadratic equation.")
'''
Question 3. Take 3 numbers as input, and find whether they form the sides of a
triangle or not. Consider invalid cases also.
'''
a = float(input("Enter the first side: "))
b = float(input("Enter the second side: "))
c = float(input("Enter the third side: "))
if a <= 0 or b <= 0 or c <= 0:
    print("The numbers cannot form the sides of a triangle.")
if a + b > c and a + c > b and b + c > a:
    print("The numbers can form the sides of a triangle.")
else:
    print("The numbers cannot form the sides of a triangle.")
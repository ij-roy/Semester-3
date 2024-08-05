'''
Question 1. Take 2 numbers as input from the user and find the result of five basic 
arithmetic operations, addition, subtraction, multiplication, division and modulus.
'''

a = int(input("Enter 1st number: "))
b = int(input("Enter 2nd number: "))

print(f"The sum of {a} + {b} is {a+b}")
print(f"The difference of {a} - {b} is {a-b}")
print(f"The multiplication of {a} * {b} is {a*b}")
print(f"The division of {a} / {b} is {a/b:.2f}")
print(f"The modulus of {a} % {b} is {a%b}")
'''
Question 6. Swap the values of two integer variables without using a third 
variable or multiple assignment operation.
'''
a = int(input("Enter the first number (a): "))
b = int(input("Enter the second number (b): "))
a = a + b  
b = a - b  
a = a - b  
# a,b = b,a       multiple assignment
print(f"After swapping, value of a: {a}")
print(f"After swapping, value of b: {b}")
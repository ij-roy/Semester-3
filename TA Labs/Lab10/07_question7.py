'''
Write recursive functions for the following:
i. Find the factorial of an input positive integer.
ii. Find the sum of first N positive integers.
iii. Display the Fibonacci series till N terms
'''

def factorial(n):
    if n == 1 or n == 0: 
        return 1
    else:
        return n * factorial(n - 1) 
    
def sum_of_n(n):
    if n == 1: 
        return 1
    else:
        return n + sum_of_n(n - 1) 

def fibonacci(n, a=0, b=1):
    if n <= 0:  
        return
    print(a, end=" ")  
    fibonacci(n - 1, b, a + b)  



num = int(input("Enter a positive integer N to calculate its factorial,sum of the first N integers, View N terms in fibonacci Series: "))
if num < 0:
    print("Factorial is not defined for negative integers.")
else:
    print(f"Factorial of {num} is: {factorial(num)}")

if num < 1:
    print("Please enter a positive integer.")
else:
    print(f"The sum of the first {num} positive integers is: {sum_of_n(num)}")
if num <= 0:
    print("Please enter a positive integer.")
else:
    print(f"The Fibonacci series up to {num} terms is:")
    fibonacci(num)
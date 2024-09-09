'''
Question 4. Take a positive integer N as input and find its Factorial using a while loop. Handle invalid 
cases as well
'''
try:    
    N = int(input("Enter a positive integer N: "))
    if N < 0:
        print("Invalid input! Please enter a non-negative integer.")
    else:
        fact = 1
        i = 1
        while i <= N:
            fact *= i
            i += 1
        print(f"The factorial of {N} is: {fact}")
except ValueError:
    print("Invalid input! Please enter a valid integer.")
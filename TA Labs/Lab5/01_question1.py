'''
Question 1. Take 2 numbers as input (X and Y) and a third number N. Display all the numbers between 
X and Y (X < i <= Y) that are divisible by N.
'''

X = int(input("Enter the value of X: "))
Y = int(input("Enter the value of Y: "))
N = int(input("Enter the value of N: "))

i = X + 1

print(f"Numbers between {X} and {Y} divisible by {N}:")
while i <= Y:
    if i % N == 0:
        print(i)
    i += 1
'''
Question 6. Display the first N terms of the Fibonacci sequence starting from 1.
    1, 1, 2, 3, 5, ….. till N terms
'''
N = int(input("Enter the number of terms (N): "))

a, b = 1, 1

print("Fibonacci sequence:")
if N >= 1:
    print(a, end=' ')
if N >= 2:
    print(b, end=' ')

count = 2
while count < N:
    next_term = a + b
    print(next_term, end=' ')
    a = b
    b = next_term
    count += 1

print()  
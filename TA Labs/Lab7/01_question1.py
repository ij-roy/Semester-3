'''
1. Find the sum of the following series for N terms, where N is taken as input from 
the user and display the result till exactly 9 decimal places.

(a) 1 + 1/2 + 1/3 + 1/4 + 1/5 + 1/6 + ….. N terms.
(b) 1/1! + 1/2! + 1/3! + 1/4! + … + 1/N!
(c) 1 - 1/(2^2) + 1/(3^2) - 1/(4^2) ... + N terms.
(d) 1 + x/1! + (x^2)/2! + (x^3)/3!  + (x^4)/4! + ... + (x^n)/n! (Take x as input from user)
(e) F(x) = 1 + x/1! + (x^2)/2 + (x^3)/3  + (x^4)/4 + ... + N terms (Take x also as input)

'''
'''
fact = 1
        i = 1
        while i <= N:
            fact *= i
            i += 1
            '''

n = int(input("Enter The Value of N : "))
x = int(input("Enter The Value of x : "))
a = 0
for i in range(1,n+1):
    a += 1/i

b = 0
for i in range(1,n+1):
    # Calculating factorial
    fact = 1
    j = 1
    while j <= i:
        fact *= j
        j += 1

    b += 1/fact
c = 0
for i in range(1,n+1):
    if i%2 == 0:
        c -= 1/(i*i)
    else:
        c+= 1/(i*i)
d = 1
for i in range(1,n+1):
    # Calculating factorial
    fact = 1
    j = 1
    while j <= i:
        fact *= j
        j += 1

    d += (x**i)/fact
e = 1
for i in range(1,n):
    e += (x**i)/i

print("Printing the Results Till Exactly 9 decimal Points")
print(f"A = {a:.9f}")
print(f"B = {b:.9f}")
print(f"C = {c:.9f}")
print(f"D = {d:.9f}")
print(f"E = {e:.9f}")
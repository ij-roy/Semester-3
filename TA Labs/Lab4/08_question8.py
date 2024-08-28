'''
Question 8. Write a program that finds all numbers in the range [1 ... 1000], 
    that end in 6.
'''
for number in range(1, 1001):
    if number % 10 == 6:
        print(number)
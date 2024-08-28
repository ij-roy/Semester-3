'''
Question 9. Write a program that reads n integers and finds their sum. 
'''
n = int(input("Enter the number of integers: "))
total_sum = 0
for _ in range(n):
    number = int(input("Enter an integer: "))
    total_sum += number

print(f"The sum of the {n} integers is: {total_sum}")
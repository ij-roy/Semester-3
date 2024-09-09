'''
Question 2. Take a positive integer as input and display the sum of its digits. 
The number can be of any length
'''

num = int(input("Enter a positive integer: "))

sum_of_digits = 0

while num > 0:
    digit = num % 10  # Get the last digit
    sum_of_digits += digit  # Add the digit to the sum
    num = num // 10  # Remove the last digit

print(f"The sum of the digits is: {sum_of_digits}")

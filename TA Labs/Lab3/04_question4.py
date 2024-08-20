'''
Question 4. Take a 3 digit number as input and find the sum of its digits. 
Also, check if the sum is divisible by 3 or not
'''
number = int(input("Enter a three-digit number: "))
while(100 >= number or number >= 999):
    print("Enter a valid Integer !")
    number = int(input("Enter a three-digit number: "))
hundreds = number // 100
tens = (number // 10) % 10
units = number % 10
sum = hundreds+tens+units
print(f"The sum of the digits is: {sum}")
if sum % 3 == 0:
    print("The sum of the digits is divisible by 3.")
else:
    print("The sum of the digits is not divisible by 3.")
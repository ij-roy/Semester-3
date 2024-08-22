'''
Question 7. Take a 3 digit number as input. Check if it is an Armstrong number or 
not. E.g. 1**3 + 5**3 + 3**3 = 153
'''
num = int(input("Enter a 3 digit number : "))
while(100>num or num>999):
    print("Invalid Input | Try Again :(")
    num = int(input("Enter a 3 digit number : "))
number = num
sum = 0
while num>0:
    temp = num%10
    sum = sum + (temp**3)
    num = num//10
if number == sum:
    print("The Number is an Armstrong")
else:
    print("The Number is not a palindrome")
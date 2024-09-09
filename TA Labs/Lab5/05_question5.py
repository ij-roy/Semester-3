'''
Question 5. Take a positive integer as input. It may be of any length. Check if it is palindrome or not. 
Do not use any inbuilt reverse functions
'''
num = int(input("Enter a positive integer: "))

original_num = num

reversed_num = 0

while num > 0:
    digit = num % 10  
    reversed_num = reversed_num * 10 + digit  
    num = num // 10  

if original_num == reversed_num:
    print(f"{original_num} is a palindrome.")
else:
    print(f"{original_num} is not a palindrome.")
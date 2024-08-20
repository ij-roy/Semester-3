'''
Question 5. Take a 5 digit number as input and print the reverse of the number. 
Do not use any in-built functions for reversing. 
Check whether the input number and the reversed number are the same. 
If so, print “Number is Palindrome”, else print “Number is not Palindrome”.
'''
number = int(input("Enter a five-digit number: "))
while 10000 >= number or number >= 99999:
    print("Please enter a valid five-digit number.")
    number = int(input("Enter a five-digit number: "))
reversed = 0
while number > 0:
    digit = number % 10  # Extract the last digit
    reversed = reversed * 10 + digit  # Build the reversed number
    number = number // 10  # Remove the last digit from the original number
print(f"The reversed number is: {reversed}")
if number == reversed:
    print("Number is Palindrome")
else:
    print("Number is not Palindrome")
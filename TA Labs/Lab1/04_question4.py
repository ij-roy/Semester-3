'''
Question 4. Take 2 integers x and y as input and find whether y is divisible by x 
or not. For negative integers, display the message “Invalid input”.
'''

x = int(input("Enter the value of x : "))
while x<=0:
    print("Invalid Input")
    x = int(input("Enter the value of x : "))

y = int(input("Enter the value of y : "))
while y<=0:
    print("Invalid Input")
    y = int(input("Enter the value of y : "))

if y%x == 0:
    print(f"{y} is divisible by {x}")
else:
    print(f"{y} is not divisible by {x}")
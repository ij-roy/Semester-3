'''
Question 11. Find the largest of 3 numbers using nested if else condition.
'''
num1 = int(input("Enter 1st number : "))
num2 = int(input("Enter 2nd number : "))
num3 = int(input("Enter 3rd number : "))
print("Largest Number is : ",end="")
if num1<num2:
    if num3<num2:
        print(num2)
    else:
        print(num3)
else:
    if num3<num1:
        print(num1)
    else:
        print(num3)
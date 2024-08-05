'''
Question 2. Input the length and width (in metres) of a plot and calculate its area. 
Check for valid and invalid
cases.
'''
length = int(input("Enter the length in metres : "))

while length<=0:
    print("Length Cannot be zero or negative")
    print("Try Again :(")
    length = int(input("Enter the length in metres : "))
width = int(input("Enter the width in metres : "))

while width<=0:
    print("Width Cannot be zero or negative")
    print("Try Again :(")
    width = int(input("Enter the width in metres : "))

print(f"The Area of required plot with length : {length} and width : {width} is {length*width} metres")
'''
Question 3. Modify the above question to take input in feet and calculate the area 
in square metres. 
'''

length = int(input("Enter the length in feet : "))

while length<=0:
    print("Length Cannot be zero or negative")
    print("Try Again :(")
    length = int(input("Enter the length in feet : "))
width = int(input("Enter the width in feet : "))

while width<=0:
    print("Width Cannot be zero or negative")
    print("Try Again :(")
    width = int(input("Enter the width in feet : "))

# meters = feet × 0.3048
print(f"The Area of required plot with length : {length} and width : {width} is {(length*width)*0.3048:.2f} metres")
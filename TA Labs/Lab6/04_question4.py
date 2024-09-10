'''
Question 4. Take an positive integer as input from the user and display its binary equivalent via 
the long division method. (without using any inbuilt function or format specifier). 
The final result should be displayed as a string. Check if the result matches the output of 
inbuilt bin() function. 
'''
number = int(input("Enter a positive integer: "))

binary_str = ""

original_number = number

while number > 0:
    remainder = number % 2
    binary_str = str(remainder) + binary_str  
    number = number // 2  

if binary_str == "":
    binary_str = "0"

print(f"Binary equivalent (Long Division Method): {binary_str}")

binary_builtin = bin(original_number)[2:]

print(f"Binary equivalent (Built-in bin() function): {binary_builtin}")

if binary_str == binary_builtin:
    print("The results match!")
else:
    print("The results do not match.")

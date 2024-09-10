'''
Question 4. Take an positive integer as input from the user and display its binary equivalent via 
the long division method. (without using any inbuilt function or format specifier). 
The final result should be displayed as a string. Check if the result matches the output of 
inbuilt bin() function. 
'''
# Taking input from the user
number = int(input("Enter a positive integer: "))

# Initialize an empty string to store the binary equivalent
binary_str = ""

# Store the original number for comparison
original_number = number

# Perform long division to calculate the binary equivalent
while number > 0:
    remainder = number % 2
    binary_str = str(remainder) + binary_str  # Prepend the remainder to the binary string
    number = number // 2  # Update the number by dividing it by 2

# Handle the case when the number is 0
if binary_str == "":
    binary_str = "0"

# Print the binary result using long division method
print(f"Binary equivalent (Long Division Method): {binary_str}")

# Convert using built-in bin() function for comparison (ignoring '0b' prefix)
binary_builtin = bin(original_number)[2:]

# Print the binary result using the built-in function
print(f"Binary equivalent (Built-in bin() function): {binary_builtin}")

# Check if both methods give the same result
if binary_str == binary_builtin:
    print("The results match!")
else:
    print("The results do not match.")

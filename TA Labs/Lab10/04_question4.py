'''
You’ve decided to program a simple calculator. Your calculator can perform the following
operations:
(a) It can add two numbers.
(b) It can subtract one number from another.
(c) It can multiply two numbers.
(d) It can divide one number by another.
Write a function that asks the user for two numbers, and the operation they wish to perform on 
these two integers, and return the result. Note: Choices should be entered as strings
'''
def calculator(num1, num2, operation):
    if operation == "+":
        result = num1 + num2
    elif operation == "-":
        result = num1 - num2
    elif operation == "*":
        result = num1 * num2
    elif operation == "/":
        if num2 != 0:  # Check to avoid division by zero
            result = num1 / num2
        else:
            return "Error: Division by zero is not allowed."
    else:
        return "Error: Invalid operation."
    
    return f"The result of {num1} {operation} {num2} is: {result}"


num1 = float(input("Enter the first number: "))
num2 = float(input("Enter the second number: "))
operation = input("Enter the operation (+, -, *, /): ").strip()

print(calculator(num1, num2, operation))
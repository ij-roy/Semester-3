'''
Write a program to check if a string is palindrome or not without using any inbuilt 
function except len().
'''

input_string = input("Enter a string: ")

is_palindrome = True
length = len(input_string)

for i in range(length // 2):
    if input_string[i] != input_string[length - 1 - i]:
        is_palindrome = False
        break

if is_palindrome:
    print(f'"{input_string}" is a palindrome.')
else:
    print(f'"{input_string}" is not a palindrome.')
'''
Take a paragraph as input and find the count of digits, alphabets, and special characters 
present in the paragraph. For alphabets, also check how many of them are upper case and how 
many are lower case alphabets. Use inbuilt string functions to check.
'''

paragraph = input("Enter a paragraph: ")

digit_count = 0
lowercase_count = 0
uppercase_count = 0
special_char_count = 0
space_count = 0

for char in paragraph:
    if char.isdigit():
        digit_count += 1
    elif char.isalpha():
        if char.islower():
            lowercase_count += 1
        elif char.isupper():
            uppercase_count += 1
    elif char == " ":
        space_count +=1
    else:
        special_char_count += 1

print("Count of digits:", digit_count)
print("Count of lowercase alphabets:", lowercase_count)
print("Count of uppercase alphabets:", uppercase_count)
print("Count of special characters:", special_char_count)
print("Count of spacses :",space_count)
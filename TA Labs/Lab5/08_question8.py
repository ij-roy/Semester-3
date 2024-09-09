'''
Question 8. Take a sentence as input and using while loop count the number of capital letters, 
small letters, digits, and special characters in the sentence. Do not use any inbuilt function.
'''

sentence = input("Enter a sentence: ")

capital_count = 0
small_count = 0
digit_count = 0
special_count = 0

index = 0

length = 0

#Alternate for len()
while True:
    try:
        _ = sentence[length]
        length += 1
    except IndexError:
        break

while index < length:
    char = sentence[index]
    
    if 'A' <= char <= 'Z':
        capital_count += 1
    elif 'a' <= char <= 'z':
        small_count += 1
    elif '0' <= char <= '9':
        digit_count += 1
    else:
        special_count += 1
    
    index += 1

print(f"Number of capital letters: {capital_count}")
print(f"Number of small letters: {small_count}")
print(f"Number of digits: {digit_count}")
print(f"Number of special characters: {special_count}")

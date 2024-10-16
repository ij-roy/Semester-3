'''
Take a sentence as input and remove all the duplicate characters from the string
'''

sentence = input("Enter a sentence: ")
unique_chars = ""
for char in sentence:
    if char not in unique_chars:
        unique_chars += char

print("Sentence after removing duplicate characters:", unique_chars)
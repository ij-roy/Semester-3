'''
Question 4. Write a Python program to check whether an alphabet is a
vowel or consonant.
'''
char = input("Enter a character : ")
if char.lower() in 'aeiou':
    print("It is a vowel")
else:
    print("It is a consonant")
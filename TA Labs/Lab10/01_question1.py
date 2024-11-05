'''
An anagram of a word or phrase is another word or phrase that uses the same letters with the 
same frequency. Punctuation marks, case, and spaces are ignored. Some examples of anagram 
pairs are “angered”/“enraged” and “A gentleman”/“Elegant man”. Write a program that requests 
two words or phrases as input and determines if they are anagrams of each other. The program 
should use a Boolean-valued function with header
def areAnagrams(string1, string2):
that returns True when the two strings are anagrams, and otherwise returns False.
'''

def areAnagrams(string1, string2):
    clean_string1 = ''.join(char.lower() for char in string1 if char.isalnum())
    clean_string2 = ''.join(char.lower() for char in string2 if char.isalnum())
    
    return sorted(clean_string1) == sorted(clean_string2)

string1 = input("Enter the first word or phrase: ")
string2 = input("Enter the second word or phrase: ")

if areAnagrams(string1, string2):
    print("The given words or phrases are anagrams.")
else:
    print("The given words or phrases are not anagrams.")

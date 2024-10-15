'''
Question 4. A program that takes a string as input and checks where the string is a pangram 
or not. 
Note : Pangrams are words or sentences containing every letter of the alphabet at least once. 
For example : "The quick brown fox jumps over the lazy dog"
'''

alphabet = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]

input_sentence = input("Enter the Sentence : ")
for i in range(len(input_sentence)):
    if input_sentence[i].lower() in alphabet:
        alphabet.remove(input_sentence[i])
    
if alphabet == []:
    print("It is a pangram")
else:
    print("It is not a pangram")
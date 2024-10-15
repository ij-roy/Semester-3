'''
Question 5. The Caesar cipher is a simple encryption technique that was used by Julius 
Caesar to send secret messages to his allies. It works by shifting the letters in the 
plaintext message by a certain number of positions, known as the “shift” or “key”. Take a 
string as input from user which contains English alphabets only in lower or upper case. Also, take the shift (an integer) as input from the user. Write 
a program to convert the string into its corresponding Ceaser Cipher which also contains English 
alphabets only.
'''

input_sentence = input("Enter the Sentence : ")
key = int(input("Enter the Key : "))
result = ""

for i in range(len(input_sentence)):
    if input_sentence[i].islower():
        result += chr((ord(input_sentence[i]) - ord('a') + key) % 26 + ord('a'))
    elif input_sentence[i].isupper():
        result += chr((ord(input_sentence[i]) - ord('A')+key) % 26 + ord('A'))
    else:
        result += (input_sentence[i])

print("Result is :",result)
'''
Question 2. Write a program to find the length of the last word in a sentence.
'''

input_sentence = input("Enter the Sentence : ")
length = 0
word = ""

for i in range(0, len(input_sentence)):
    if input_sentence[i] == " ":
        length = 0
        word = ""
    else:
        length+=1
        word += input_sentence[i]

print("The word is :",word)
print("Length is :",length)
'''
Question 3. Take a sentence and a word as input and check if the string contains the word 
in it. Also, count the number of times that word occurs in the string. Do this by using 
inbuilt string functions and then without using inbuilt string functions
'''

input_sentence = input("Enter the sentence : ")
input_word = input("Enter the word : ")


#With Inbuilt Functions
if input_word in input_sentence:
    print("Word is present",input_sentence.count(input_word),"times")

count = 0

#Without Inbuilt Functions
for i in range(len(input_sentence)):
    if input_sentence[i:i+len(input_word)] == input_word:
        count+=1
if count == 0:
    print("Word is not present")
else:
    print("Word is present",count,"times")
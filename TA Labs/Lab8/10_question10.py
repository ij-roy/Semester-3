'''
Write a Python program that accepts a hyphen-separated sequence of words as input and prints 
the words in a hyphen-separated sequence after sorting them alphabetically. Do not use any 
inbuilt sorting function. 

Sample String : green-red-yellow-black-white 
Expected Result : black-green-red-white-yellow 
'''
input_string = input("Enter the hyphen-separated string: ")
words = input_string.split("-")
n = len(words)

for i in range(n):
    for j in range(0, n-i-1):
        if words[j] > words[j+1]:  
            words[j], words[j+1] = words[j+1], words[j]

for i in range(n-1):
    print(words[i],end="")
    print("-",end="")
print(words[n-1])
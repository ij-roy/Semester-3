'''
Question 1. Write a program to reverse a string without using inbuilt function
'''

input_string = input("Enter  the input string : ")
reversed_sring = ""

for i in range(len(input_string)-1 , -1 ,-1):
    reversed_sring += input_string[i]

print("Revesed String is :", reversed_sring)
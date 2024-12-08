'''
Question 1. Take a list of positive integers as input in a list and perform the following 
operations:
    1. Remove duplicate elements. Do not use sets or any other in-built functions except 
    len().
    2. Remove duplicate elements by typecasting into sets and displaying resulting elements 
    in the same order as they appear in the input list.
'''
input_list = [int(x) for x in input("Enter positive integers separated by space: ").split()]

#A part
unique_list = []
for item in input_list:
    if item not in unique_list:
        unique_list.append(item)

print("Without using sets:", unique_list)

#B part
unique_set = set(input_list)
result = []
for num in input_list:
    if num in unique_set:
        result.append(num)
        unique_set.remove(num)
print("List after removing duplicates:", result)
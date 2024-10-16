'''
Write programs for the following by taking list of integers of arbitrary length as user input. Do not 
use any inbuilt list functions other than len(). 
    i. Find the sum of the elements in the list. 
    ii. Find the product of the elements in the list. 
    iii. Find the smallest element in the list of integers.
'''

lst = list(map(int, input("Enter the list of integers separated by space: ").split()))

total_sum = 0
total_product = 1
smallest = lst[0]

for num in lst:
    total_sum += num
    total_product *= num
    if num < smallest:
        smallest = num

print("Sum of the elements:", total_sum)
print("Product of the elements:", total_product)
print("Smallest element in the list:", smallest)
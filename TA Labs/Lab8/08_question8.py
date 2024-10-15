'''
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
'''
Sort the elements of the list in descending order without using any inbuilt function. 
'''

arr = list(map(int, input("Enter the elements separated by spaces: ").split()))

n = len(arr)
for i in range(n):
    for j in range(0, n-i-1):
        if arr[j] < arr[j+1]:  
            arr[j], arr[j+1] = arr[j+1], arr[j]
            
print("Sorted list in descending order:", arr)
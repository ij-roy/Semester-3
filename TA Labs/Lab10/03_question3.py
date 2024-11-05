'''
Given a list of N numbers, write a function to shift the numbers circularly by some integer k (where 
k < N). The function should take a list and k as arguments and return the shifted list.
1. Write a function that assumes shifting is to the left.
2. Write a function that takes a third argument that specifies shifting left or right.
Hint:
original list: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
shifted by 4, to the left: [4, 5, 6, 7, 8, 9, 0, 1, 2, 3]
shifted by 4, to the right: [6, 7, 8, 9, 0, 1, 2, 3, 4, 5]
'''

def shift_list(lst, k, direction="left"):
    k = k % len(lst)
    
    if direction == "left":
        return lst[k:] + lst[:k]
    elif direction == "right":
        return lst[-k:] + lst[:-k]
    else:
        # If an invalid direction is provided, return the list as is
        return lst

original_list = list(map(int, input("Enter the list of numbers separated by spaces: ").split()))

# Get the shift amount
k = int(input("Enter the number of positions to shift: "))

# Get the direction
direction = input("Enter the direction (left or right): ").strip().lower()

# Shift the list based on the direction
shifted_list = shift_list(original_list, k, direction)
print("Shifted list:", shifted_list)
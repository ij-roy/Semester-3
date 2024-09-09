'''
Question 3. 
'''

N = int(input("Enter a positive integer N: "))

divisible_count = 0
not_divisible_count = 0

while True:
    num = int(input("Enter a number (or -999 to stop): "))
    
    if num == -999:
        break
    
    if num % N == 0:
        divisible_count += 1
    else:
        not_divisible_count += 1

print(f"Count of numbers divisible by {N}: {divisible_count}")
print(f"Count of numbers not divisible by {N}: {not_divisible_count}")

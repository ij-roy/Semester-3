'''
Question 6. Find the GCD of N positive numbers, where value of N is taken as input from the user. 
'''
N = int(input("Enter the number of positive numbers: "))

a = int(input("Enter number 1: "))

gcd = a

for i in range(2, N + 1):
    num = int(input(f"Enter number {i}: "))
    
    while num != 0:
        temp = gcd % num
        gcd = num
        num = temp

print("The GCD of the given numbers is:", gcd)

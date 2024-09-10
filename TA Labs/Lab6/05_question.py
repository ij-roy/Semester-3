'''
Question 5. Find the LCM of N positive numbers, where value of N is taken as input from the user. 
'''
N = int(input("Enter the number of positive integers: "))

numbers = []
for i in range(N):
    num = int(input(f"Enter number {i+1}: "))
    numbers.append(num)

result_lcm = numbers[0]

for i in range(1, N):
    a = result_lcm
    b = numbers[i]
    
    while b != 0:
        a, b = b, a % b
    
    result_lcm = (result_lcm * numbers[i]) // a

print(f"The LCM of the given {N} numbers is: {result_lcm}")

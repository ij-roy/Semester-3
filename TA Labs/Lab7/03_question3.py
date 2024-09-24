'''
3. Write a program to find the sum of prime numbers between x and y where x and y are 
given as input by the user
'''

'''
divisor = 2
        is_prime = True
        
        while divisor <= num // 2:
            if num % divisor == 0:
                is_prime = False
                break
            divisor += 1

        if is_prime:
            print(f"{num} is a prime number.")
        else:
            print(f"{num} is not a prime number.")
'''
sum = 0
x = int(input("Enter Value of X : "))
y = int(input("Enter Value of Y : "))

for i in range(x,y+1):
    # Checking Prime
    divisor = 2
    is_prime = True
    while divisor <= i // 2:
        if i % divisor == 0:
            is_prime = False
            break
        divisor += 1

    if is_prime:
        sum += i
print(f"Sum of Prime Numbers between {x} and {y} is {sum}")
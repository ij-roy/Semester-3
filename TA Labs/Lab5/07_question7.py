'''
Question 7. Take an integer as input and check if it is prime or not. Handle invalid conditions 
and make your code efficient by minimizing the number of loop iterations
'''
try:
    num = int(input("Enter an integer: "))

    if num <= 1:
        print(f"{num} is not a prime number.")
    else:
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

except ValueError:
    print("Invalid input! Please enter a valid integer.")

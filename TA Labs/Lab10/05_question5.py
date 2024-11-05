'''
Write a function that takes in the lower and upper limits of a range, and prints all the prime 
numbers in that range. The function returns the sum of all primes in that range
'''
def is_prime(n):
    """Check if a number is prime."""
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def sum_of_primes(lower, upper):
    """Print all prime numbers in the range and return their sum."""
    prime_sum = 0
    print(f"Prime numbers between {lower} and {upper}:")
    for num in range(lower, upper + 1):
        if is_prime(num):
            print(num, end=' ')
            prime_sum += num
    print() 
    return prime_sum


lower_limit = int(input("Enter the lower limit of the range: "))
upper_limit = int(input("Enter the upper limit of the range: "))
total_sum = sum_of_primes(lower_limit, upper_limit)
print(f"The sum of all prime numbers in the range is: {total_sum}")

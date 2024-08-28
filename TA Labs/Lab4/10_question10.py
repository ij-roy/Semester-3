'''
Take a positive integer N as input and print its table as follows: 
    N x 1 = N 
    N x 2 = 2N 
    ...... 
    N x 20 = 20N
'''
N = int(input("Enter a positive integer: "))

for i in range(1, 21):
    print(f"{N:02d} x {i:02d} = {N * i:02d}")
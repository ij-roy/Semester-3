'''
Question 3. Display the following patterns for N lines (value of N taken from the user) 
            using while loop:

            a. *                b.      *          c.       *
               **                      **                  ***
               ***                    ***                 *****
               ****                  ****                *******
'''
N = int(input("Enter the number of lines: "))

# a part
i = 1
while i <= N:
    print("*" * i)
    i += 1

# b part
i = 1
while i <= N:
    print(' ' * (N - i) + '*' * i)
    i += 1

# c part
i = 1
while i <= N:
    print(' ' * (N - i) + '*' * (2 * i - 1))
    i += 1
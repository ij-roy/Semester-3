'''
Print the following patterns (take number of lines as input from user):
(a) A
    AB
    ABC
    ABCD

(b) A
    AB
    A B
    A  B
    A   B
    ABCDE

(c) A
    ABC
    ABCDE
    ABCDEFG

(d) * * * * *
    * *     *
    *   *   *
    *     * *
    * * * * *
'''

n = int(input("Enter the value of n : "))

for i in range(1,n+1):
    for j in range(65,65+i):
        print(chr(j),end="")
    print()

print()

for i in range(1,n+2):
    if i == 1:
        print("A")
    elif i ==2:
        print("AB")
    elif i == n+1:
        for j in range(65,65+i-1):
            print(chr(j),end="")
        print()
    else:
        print("A",end="")
        print(" "*(i-2),end="")
        print("B")
print()

for i in range(1,n+1):
    for j in range(65,65+((2*i)-1)):
        print(chr(j),end="")
    print()
print()

for i in range(n):
    if i == 0 or i ==n-1:
        print("* "*n)
    else:
        for j in range(n):
            if j == 0 or j == n-1 or j == i:
                print("*",end=" ")
            else:
                print(" ",end=" ")
        print()
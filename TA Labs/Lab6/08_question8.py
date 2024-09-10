'''
Question 8. Display the pattern using nested loops:
    *
   * *
  * * *
 * * * * 
till n lines
'''
n = int(input("Enter the number of lines: "))

for i in range(1, n + 1):
    for j in range(n - i):
        print(" ", end="")
    
    for k in range(i):
        print("*", end=" ")
    
    print()
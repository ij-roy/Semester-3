'''
You are given a binary string 𝐴 of length 𝑁. 
You can perform the following type of operation on the string 𝐴.

Choose two different indices 𝑖 and 𝑗 (1≤i,j≤N)
Change Ai and Aj to Ai ⊕Aj. Here ⊕ represents the bitwise XOR operation
Find the minimum number of operations required to convert the given string into a palindrome.

Input Format

First line of the input contains T, the number of test cases. Then the test cases follow.
First line of each test case contains an integer N denoting the size of the string.
Second line of each test case contains a binary string A of length N containing 0s and 1s only.
Constraints

1 ≤ T ≤ 1000
1 ≤ N ≤ 2*100000
Output Format

For each test case, print the minimum number of operations required to make the string a palindrome.
Sample Input 0

3
5
11011
7
0111010
1
1
Sample Output 0

0
1
0

Difficulty: Medium

'''

def minimum_operations(str_length,string):
    i = 0
    j = str_length-1
    operations = 0

    while i < j :
        if string[i] != string[j]:
            operations += 1

        i += 1
        j -= 1

    return operations

if __name__ == '__main__':
    fptr = open('Coding Hour\\Week1\\01_testcases.txt','r')
    ij = int(fptr.readline().strip())
    for i in range(ij):
        number_of_digits = int(fptr.readline().strip())
        string = fptr.readline().strip()
        answer = minimum_operations(number_of_digits,string)
        print(answer)

    fptr.close()

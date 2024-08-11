'''
Given a sorted array arr[] of distinct integers. 
Sort the array into a wave-like array (In Place). 
In other words, arrange the elements into a sequence such that 
arr[l] >= arr[2] <= arr(3] => arr[4] <= arr[5].....
If there are multiple solutions, find the lexicographically smallest one.

Note: The given array is sorted in ascending order.

Input Format
• First line contains an integer N denoting the size of the array.
• Second line contains N size array.

Output Format
• Output the wave like sorted array.

Testcases:
Sample Input O
5
1 2 3 4 5
Sample Output O
2 1 4 3 5

Sample Input 1
6
2 4 7 8 9 10
Sample Output 1
4 2 8 7 10 9

Sample Input 2
7
10 12 14 16 18 20 22
Sample Output 2
12 10 16 14 20 18 22

'''

def wave_sort(arr):
    n = len(arr)
    for i in range(0,n-2,2):
        arr[i],arr[i+1] = arr[i+1],arr[i]
    return arr
    

if __name__ == '__main__':
    fptr = open('Coding Hour\\Week1\\04_testcases.txt','r')
    ij = int(fptr.readline().strip()) #number of test cases
    for i in range(ij):
        n = int(fptr.readline().strip()) #size of array
        arr = list(map(int,fptr.readline().strip().split())) #making the array
        arr = wave_sort(arr)
        for i in arr:
            print(i, end=" ")
        print()
    fptr.close()

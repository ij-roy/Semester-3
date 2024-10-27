/*
Given a sorted array arr[] of size n without duplicates, and given a value x. Floor of x is defined as the largest element k in arr[] such that k is smaller than or equal to x. Find the index of k(0-based indexing).

Examples
Input: n = 7, x = 5 arr[] = {1,2,8,10,11,12,19}
Output: 1
Explanation: Largest Number less than 5 is 2 (i.e k = 2), whose index is 1(0-based indexing).

Input Format

First line contains an integer N denoting the size of the array.
Second line contains X element whose floor is to find.
Third line contains N size array.
Constraints

1 ≤ n ≤ 100000
1 ≤ arr[i] ≤ 100000
0 ≤ x ≤ arr[N-1]
Output Format

You do not need to print anything your task is to just complete the function findFloor() which returns an integer denoting the index value of K or return -1 if there isn't any such number.
Sample Input 0
7
5
1 2 8 10 11 12 19
Sample Output 0
1
*/

#include <stdio.h>
#include <stdlib.h>

int findFloor(int, int* , int );

int main()
{
    FILE* fptr = fopen("01_testcases.txt","r");

    if(fptr ==NULL){
        printf("Error Opening File.\n");
        return 1;
    }

    int n ;
    fscanf(fptr, "%d", &n);
    int x;
    fscanf(fptr, "%d", &x);

    int arr[100000];

    for (int i = 0; i < n; i++)
    {
        fscanf(fptr, "%d", &arr[i]);
    }

    printf("%d",findFloor(n, arr,x));

    fclose(fptr);

    return 0;
}

int findFloor(int n , int* arr , int x){
    int index,largest_number = -1;
    for (int i = 0; i < n; i++)
    {
        if (largest_number<arr[i] && arr[i]<x)
        {
            largest_number = arr[i];
            index = i;
        }
        
    }
    return index;
}
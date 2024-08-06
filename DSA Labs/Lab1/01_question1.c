/*
Question 1. Create an array of integers.  Using pointer arithmetic, 
find the sum of all elements in the array without using array indexing
*/

#include <stdio.h>
int main(){
    int N , sum = 0;
    printf("Enter Number of Integers : ");
    scanf("%d",&N);
    int *ptr = (int*)malloc(N*sizeof(int));
    for (int i = 0; i < N; i++)
    {
        printf("Enter Number %d : ",i+1);
        scanf("%d",&ptr[i]);
        sum += ptr[i];
    }
    printf("The Sum of Given %d numbers is %d",N,sum);
}
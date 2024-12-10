/*
Once upon a time, there was a row of warriors, each with a different strength (represented by an array of numbers). Each warrior was curious about the first stronger warrior standing to their right. If no such warrior existed, they were left wondering, with a value of -1.

Their mission was simple: find the first stronger warrior to their right or be left with no one stronger!

For example, if the array of strengths was [4, 5, 2, 10, 8], the next greater element (NGE) for each warrior would be:

For 4 → 5 (stronger warrior on the right)
For 5 → 10
For 2 → 10
For 10 → -1 (no one stronger)
For 8 → -1
And so, they figured out their NGEs and fought bravely onward!

Input Format
First line: Contains an integer N, the size of the array.
Second line: Contains N space-separated integers, representing the strengths of the warriors (the array).

Constraints
1<=N<=1000

Output Format
Output a single line containing N space-separated integers. Each integer represents the Next Greater Element (NGE) for the corresponding element in the input array. If no greater element exists, output -1 for that element.

Sample Input 0
4
1 3 2 4
Sample Output 0
3 4 4 -1
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fptr = fopen("01_testcases.txt","r");

    if(fptr ==NULL){
        printf("Error Opening File.\n");
        return 1;
    }

    int n;  
    fscanf(fptr,"%d",&n);
    int arr[1000];
    for(int i=0;i<n;i++){
        fscanf(fptr,"%d",&arr[i]);
    }
    fclose(fptr);
    for(int j=0;j<n-1;j++){
        int min = -1;
        int flag = 0;
        for(int k = j+1;k<n;k++){
            if(arr[k]>arr[j]){
                printf("%d ",arr[k]);
                flag +=1;
                break;
            }
        }
        if(flag == 0){
            printf("%d ",min);
        }
    }
    printf("%d",-1);
    return 0; 

}
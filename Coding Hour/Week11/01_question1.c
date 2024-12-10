/*
You have a collection of marbles in a jar, each marble colored either red, white, or blue. The marbles are currently mixed together, and your task is to sort them so that all marbles of the same color are grouped together in the following order: red, white, and blue.

To simplify the sorting process, each color is represented by a specific character: 'R' for red, 'W' for white, and 'B' for blue. For instance, if the marbles in the jar are represented as ['B', 'R', 'B', 'W', 'W', 'R'], your goal is to rearrange them to look like this: ['R', 'R', 'W', 'W', 'B', 'B'].

You are restricted to sorting the marbles directly within the jar, meaning no additional space can be utilized for sorting. How can you achieve this efficiently without removing all the marbles from the jar?

Input Format

The first line contains a single integer n, representing the number of marbles in the jar.
The second line contains an array of characters of size n, where each character represents a colored marble:
'R' for red
'W' for white
'B' for blue
Constraints

1 ≤ n ≤ 400
Output Format

The output should be a single line containing the sorted array of characters representing the colored marbles in the jar.
The colors should be arranged in the following order: first all 'R' (red), then all 'W' (white), followed by all 'B' (blue).
Sample Input 0

6
B R B W W R
Sample Output 0

R R W W B B
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fptr = fopen("01_testcases.txt","r");

    if(fptr ==NULL){
        printf("Error Opening File.\n");
        return 1;
    }

    int n ;
    fscanf(fptr,"%d\n",&n);
    char * arr = (char *)malloc(n*sizeof(char));
    int a =0;
    int b = 0;
    int c = 0;
    for(int i = 0;i<n;i++){
        fscanf(fptr,"%c ",&arr[i]);
    }
    fclose(fptr);
    for(int i = 0;i<n;i++){
        if (arr[i] == 'R'){
            a++;
        }else if(arr[i] == 'W'){
            b++;
        }else{
            c++;
        }
    }
    // printf("%d%d%d",a,b,c);
    int ij = 0;
    for(int i = 0;i<a;i++){
        arr[ij] = 'R';
        ij++;
    }
    for(int i = 0;i<b;i++){
        arr[ij] = 'W';
        ij++;
    }
    for(int i = 0;i<c;i++){
        arr[ij] = 'B';
        ij++;
    }
    for(int i = 0;i<n;i++){
        printf("%c ",arr[i]);
    }

}
/*
In the kingdom of Numerica, Queen Matilda has assigned you, the royal mathematician, a crucial mission. She wants you to convert all the numbers from 1 to a given number N into their binary forms and display them in a single line, separated by spaces. Your task is to print the binary representations of all the numbers from 1 to N, space-separated, in one line.

Example: 
Input: N = 3
Output: 1 10 11
    
Explanation:
The binary representation of 1 is "1"
The binary representation of 2 is "10"
The binary representation of 3 is "11"
Your Task: You need to complete the function generate() which takes an integer N and prints the binary numbers from 1 to N, separated by spaces. There's no need to return anything.

Input Format
A single integer N on one line, representing the number up to which you need to generate binary numbers.

Constraints
1 ≤ N ≤ 1000

Output Format
You need to prints the binary numbers from 1 to N, separated by spaces. There's no need to return anything.

Sample Input 0
3
Sample Output 0
1 10 11
*/

#include <stdio.h>
#include <stdlib.h>

void generate(int N) {
    for(int n = 1;n<=N;n++){
        int bin[100];
        int i = 0;
        int temp = n;
        while(temp>0){
            bin[i] = temp%2;
            temp = temp/2;
            i++;
        }
        for(int j = i-1;j>=0;j--){
            printf("%d",bin[j]);
        }  
        printf(" ");
    }
    
}

int main() {
    FILE* fptr = fopen("01_testcases.txt","r");

    if(fptr ==NULL){
        printf("Error Opening File.\n");
        return 1;
    }

    int N;  

    fscanf(fptr,"%d",&N);
    generate(N);

    fclose(fptr);

    return 0; 

}
/*
Imagine you're a linguist studying the "energy" of words. The energy of a word is calculated by measuring how "different" each letter is from the next, based on their ASCII values. The more distinct two consecutive letters are, the higher the energy between them. For example, in the word "hello," the differences between the letters create a certain "score," or total energy.

Each character in a string has an ASCII value, which is a unique number assigned to each letter. For each pair of adjacent letters in the string, you calculate the absolute difference in their ASCII values. The sum of these absolute differences gives the score (or energy) of the word.

For example, if you're given the word "hello," the score is calculated like this:

The ASCII values are: 'h' = 104, 'e' = 101, 'l' = 108, 'o' = 111.
Now, calculate the differences between adjacent letters:

|104 - 101| = 3
|101 - 108| = 7
|108 - 108| = 0
|108 - 111| = 3

The total score (or energy) of "hello" is 3 + 7 + 0 + 3 = 13. 
This is the total energy that defines the string.

Input Format
The first line contains an integer n, the size of the string s.
The second line contains the string s.

Constraints
2 <= s.length <= 100
s consists only of lowercase English letters.

Output Format
Print a single integer representing the score of the string s, which is the sum of the absolute differences between the ASCII values of adjacent characters.

Sample Input 0
3
zaz
Sample Output 0
50
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fptr = fopen("02_testcases.txt","r");

    if(fptr ==NULL){
        printf("Error Opening File.\n");
        return 1;
    }
    int n;
    fscanf(fptr,"%d\n",&n);
    char * arr = (char *)malloc(n*sizeof(char));
    for(int i =0;i<n;i++){
        fscanf(fptr,"%c",&arr[i]);
    }
    int sum = 0;
    int temp = 0;
    for(int i = 0;i<n-1;i++){
        temp = (int)(arr[i+1]) - (int)(arr[i]);
        if(temp<0){
            temp = -temp;
        }
        sum = sum + temp;
    }
    printf("%d",sum);
    fclose(fptr);
    return 0;
}
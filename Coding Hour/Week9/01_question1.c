/*
Arya, a young coder, visits a wizard who challenges her with a task. "To pass," the wizard says, "you must write a spell (a program) that reverses any word you give me—but you can only use the power of pointers!"

Help Arya write this spell to reverse a string using pointers so she can complete the wizard’s challenge.

Input Format
First and the only line that takes word as a string.

Constraints
1<=str.length<=100000

Output Format
Output the reversed word.

Sample Input 0
hello world
Sample Output 0
dlrow olleh
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fptr = fopen("01_testcases.txt","r");

    if(fptr ==NULL){
        printf("Error Opening File.\n");
        return 1;
    }
    char s[100000];
    fscanf(fptr,"%[^\n]", s);

    char *start = s;
    char *end = s;

    while (*end != '\0') {
        end++;
    }
    end--;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    printf("%s\n", s);
    
    fclose(fptr);
    return 0; 

}

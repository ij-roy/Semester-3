/*
Arya, continuing her quest, finds an ancient scroll written in a strange language. The scroll holds a secret message, but it’s hidden among lowercase letters, and only the first capital letter will reveal the key to decode the message.

The wizard gives her a clue: "The secret can be unlocked through a recursive spell. Search through the letters one by one using recursion until you find the first capital letter."

Help Arya write this recursive spell to find the first capital letter in the string, so she can uncover the hidden message and complete her journey.

Input Format
First and the only line that takes word in the form of string.

Constraints
1<=str.length<=100000

Output Format
Return the capital character.

Sample Input 0
helloWorld
Sample Output 0
W
*/

#include <stdio.h>
#include <stdlib.h>

char findFirstCapital(char* s, int index) {
    if (s[index] == '\0') {
        return '\0'; 
    }

    if (s[index] >= 'A' && s[index] <= 'Z') {
        return s[index];
    }

    return findFirstCapital(s, index + 1);
}

int main() {
    FILE* fptr = fopen("02_testcases.txt","r");

    if(fptr ==NULL){
        printf("Error Opening File.\n");
        return 1;
    }
    char s[100000];
    fscanf(fptr,"%[^\n]", s);
    fclose(fptr);

    char result = findFirstCapital(s, 0);
    
    if (result != '\0') {
        printf("%c\n", result);
    }

    return 0; 

}

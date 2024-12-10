/*
In a kingdom, there is a line of knights, and each knight has a letter on their armor. Some knights have the same letter, while others have unique ones. The king wants to find the first knight with a unique letter—the one that appears only once in the line.

You are given a string s that represents the order of the knights by their letters. Your task is to help the king find the position of the first knight with a unique letter. If all knights have repeating letters, print -1.

Input Format
A single line containing a string s.
Constraints
1 <= s.length <= 1000
s consists of only lowercase English letters.

Output Format
You just need print its index. If it does not exist, print -1.

Sample Input 0
aabbccdde
Sample Output 0
8
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fptr = fopen("02_testcases.txt","r");

    if(fptr ==NULL){
        printf("Error Opening File.\n");
        return 1;
    }
    
    char s[1000];
    fscanf(fptr,"%s", s);

    int freq[26] = {0};  

    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("%d\n", i);  
            fclose(fptr);
            return 0;
        }
    }

    // If no unique character is found
    printf("-1\n");

    fclose(fptr);
    return 0; 

}
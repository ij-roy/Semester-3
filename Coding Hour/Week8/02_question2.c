/*
Imagine a magical string where every time a number appears, it creates a powerful spell. The spell vanishes the number along with the closest letter to its left. Your mission is to keep casting the spell until all numbers are gone. If there are no numbers, the string stays safe!

Example

Input: s = "cb3"
Output: "c"

Explanation:
We apply the operation on s[2], and s becomes "c".

Input Format
A string s made up of lowercase letters and digits.
Constraints
1 <= s.length <= 100
s consists only of lowercase English letters and digits.
Output Format
The final string after all numbers and their left-side letters are removed.

Sample Input 0
abc
Sample Output 0
abc
*/

#include <stdio.h>
#include <stdlib.h>

void vanishNum(char* s) {
    int i = 0;
    char o[100];
    int j = 0;
    while(s[i] != '\0'){
        if(s[i] >47 && s[i] < 58){
            if(j!=0){
                j-=1;
            }
        }else{
            o[j] = s[i];
            j++;
        }
        i++;
    }
    o[j] = '\0';
    printf("%s",o);
}

int main() {
    FILE* fptr = fopen("02_testcases.txt","r");

    if(fptr ==NULL){
        printf("Error Opening File.\n");
        return 1;
    }

    char s[100];  

    fscanf(fptr,"%s",s);
    vanishNum(s);

    fclose(fptr);

    return 0; 

}

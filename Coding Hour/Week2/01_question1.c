/*
Given an input string s, reverse the order of the words. A word is defined as a 
sequence of non-space characters. The words in s are separated by exactly one space.

You do not need to handle multiple spaces between words, nor do you need to worry 
about leading or trailing spaces. Simply reverse the order of the words and return 
the resulting string.

Input Format

A single line containing a string s, which consists of words separated by spaces.
Constraints

1 <= s.length <= 10^4
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
The words in s are separated by exactly one space.
Output Format
Complete the function reverseWords() which takes string s as input parameter and 
returns a string containing the words in reversed order. Each word in the returning 
string should also be separated by space ' '.

Sample Input 0
the sky is blue
Sample Output 0
blue is sky the

Sample Input 1
hello world
Sample Output 1
world hello

*/

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * Complete the 'reverseWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
char* reverseWords(char* s) {
    // write your code here
    int length = strlen(s);
    char words[100][100];
    int wordCount = 0;

    int index = 0;
    for (int i = 0; i <= length; i++)
    {
        if (s[i] == ' ' || s[i] == '\0')
        {
            if (index>0)
            {
                words[wordCount][index] = '\0';
                wordCount++;
                index = 0;
            }
        }else
        {
            words[wordCount][index++] = s[i];
        }
    }
    int resultlength = 0;
    for (int i = wordCount - 1; i >=0; i--)
    {
        resultlength += strlen(words[i]);
        if (i!=0)
        {
            resultlength++;
        }
    }
    char * result = malloc((resultlength+1) * sizeof(char));
    result[0] = '\0';
    for (int i = wordCount-1; i >= 0 ; i--)
    {
        strcat(result, words[i]);
        if (i!=0)
        {
            strcat(result," ");
        }
        
    }
    
    return result;

}

int main()
{
    FILE* fptr = fopen("01_testcases.txt","r");

    if(fptr ==NULL){
        printf("Error Opening File.\n");
        return 1;
    }

    char s[1024];

    fgets(s, sizeof(s),fptr);

    char* result = reverseWords(s);

    printf("%s\n",result);

    fclose(fptr);

    return 0;
}
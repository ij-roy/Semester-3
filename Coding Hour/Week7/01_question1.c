/*
In the enchanted forest, there's a mystical door that only opens with a special key sequence. The door has three types of locks: round ( ), square [ ], and curly { }.

To open the door:

Each lock must be closed with the matching key, like ( with ), { with }, and [ with ].
Locks must be closed in the reverse order they were opened, meaning you can't close a lock before finishing the previous one.
A young wizard, Elara, finds multiple sequence of such keys. She needs to know if it's valid to open the door. Can you help Elara determine if the key sequence works by checking if all locks are opened and closed correctly?

Explaination Test Case 0: ({[]})

1.  The first three brackets (, {, [ are opening brackets, so we expect to close them in reverse order.
2.  We encounter ], which correctly closes the last opened bracket [.
3.  Next, } closes the second last opened bracket {.
4.  Finally, ) closes the first opened bracket (.

All brackets are matched in the correct order.

Output: 1 (Valid sequence).

Input Format
A string s representing the sequence of keys, which contains only the characters: (), [], and {}.

Constraints
0<=strlen(s)<=200

Output Format
Print 1 if the sequence is valid.
Print 0 if the sequence is invalid.

Sample Input 0
({[]})
Sample Output 0
1
*/

#include <stdio.h>
#include <stdlib.h>

int isValid(char* s) {
    char stack[200];
    int top = -1;
    int i = 0;
    
    while (s[i] != '\0') {
        char ch = s[i];
        
        if (ch == '(' || ch == '[' || ch == '{') {
            stack[++top] = ch;
        } else {
            if (top == -1) {
                return 0;     
            }
            
            if ((ch == ')' && stack[top] == '(') ||
                (ch == ']' && stack[top] == '[') ||
                (ch == '}' && stack[top] == '{')) {
                top--;  
            } else {
                return 0;     
            }
        }
        i++;
    }
    
    // If the stack is empty, all brackets matched, otherwise invalid
    int result = (top == -1);
    return result;
}

int main() {
    FILE* fptr = fopen("01_testcases.txt","r");

    if(fptr ==NULL){
        printf("Error Opening File.\n");
        return 1;
    }
    char s[200];
    fscanf(fptr,"%s", s);
    if (isValid(s)) {
        printf("1\n");  // Valid sequence
    } else {
        printf("0\n");  // Invalid sequence
    }

    fclose(fptr);
    return 0; 

}
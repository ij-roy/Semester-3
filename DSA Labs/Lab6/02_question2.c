/*
Question 2. Write a program to check if a given string has balanced bracket 
expression using a stack. Test your program for:  
    a. ()) 
    b. {}([]) 
Optional: Remove the main method from Q1 and include it as  #include “filename.c” in 
this file. You will be able to directly use the push, pop, top functions in this new 
file. You don’t have to code it again.
*/

#include <stdio.h>
#include "stack.c"

void checkBalanced(stack*,char []);

int main(){
    stack ij;
    ij.top = -1;
    char input[20];
    printf("Enter The Brackets : ");
    scanf(" %[^\n]%*c",input);
    checkBalanced(&ij,input);
    return 0;
}

void checkBalanced(stack* ij,char input[]){
    for (int i = 0;input[i] != 0; i++)
    {
        if (input[i] == '(' || input[i] == '{' || input[i] == '[')
        {
            push(ij,input[i]);
        }else if (input[i] == ')')
        {
            if (peek(ij) == '(')
            {
                pop(ij);
            }else{
                push(ij,input[i]);
            }
        }else if (input[i] == '}')
        {
            if (peek(ij) == '{')
            {
                pop(ij);
            }else{
                push(ij,input[i]);
            }
        }else if (input[i] == ']')
        {
            if (peek(ij) == '[')
            {
                pop(ij);
            }else{
                push(ij,input[i]);
            }
        }else{
            printf("Invalid Input");
            return;
        }
    }
    if (ij->top == -1)
    {
        printf("String is Balanced");
    }else{
        printf("String is not Balanced");
    }   
}
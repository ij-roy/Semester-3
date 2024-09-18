#include <stdio.h>

#define MAX 100

typedef struct 
{
    char arr[MAX];
    int top;
}stack;

void push(stack*,char);
void pop(stack *);
char peek(stack *);
void printStack(stack*);


void push(stack*ij,char data){
    if (ij->top == MAX-1)
    {
        printf("Pushing will lead top overflow\n");
    }else{
        ij->top++;
        ij->arr[ij->top] = data;
    }
}

void pop(stack * ij){
    if (ij->top == -1)
    {
        printf("Popping will lead to underflow\n");
    }else{
        ij->top--;
    }
}

char peek(stack * ij){
    char num;
    if (ij->top == -1)
    {
        return -1 ;
    }else{
        num = ij->arr[ij->top];
        return num;
    }
}

void printStack(stack*ij){
    int temp = ij->top;
    while (temp != -1)
    {
        printf("%c\n",ij->arr[temp]);
        temp--;
    }
}
/*
Question 1. Write a program to implement a stack using an array. For this define a stack as a 
struct:

typedef struct{
char arr[100];
int top;
} stack;

In the main method perform the following operations:
Push: A
Print the top of the stack
Push: B
Print the top of the stack
Pop
Pop
Pop
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char arr[100];
    int top;
}stack;

void push(stack *s, char value);
char pop(stack *s);
char peek(stack *s);
void printStack(stack *s);

int main() {
    stack s;
    s.top = -1; 

    push(&s, 'AB');
    printStack(&s);

    push(&s, 'B');
    printStack(&s);

    pop(&s);
    pop(&s);
    pop(&s);

    return 0;
}

void push(stack *s, char element) {
    if (s->top == 99) {
        printf("Stack overflow! cannot push %c\n", element);
        return;
    }
    s->arr[++s->top] = element;
}

char pop(stack *s) {
    if (s->top == -1) {
        printf("Stack underflow! Cannot pop\n");
        return '\0';
    }
    return s->arr[s->top--];
}

char peek(stack *s) {
    if (s->top == -1) {
        printf("Stack is empty! Cannot get top\n");
        return '\0';
    }
    return s->arr[s->top];
}

void printStack(stack *s) {
    printf("Top of the stack: %c\n", peek(s));
}
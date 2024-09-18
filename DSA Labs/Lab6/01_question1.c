/*
Question 1. Q1. Write a program to implement a stack using an array. 
For this define a stack as a struct:
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

int main(){
    stack ij;
    ij.top = -1;
    char data,num;
    int choice;
    do {
        printf("\nPress\n1 to push in Stack\n2 to pop\n3 to peek\n4 to print the stack\n5 to end\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf(" %c", &data);
                push(&ij, data);
                break;
            case 2:
                pop(&ij);
                break;
            case 3:
                num = peek(&ij);
                if (num != -1) {
                    printf("Top element of Stack is %c\n",num);
                }else{
                    printf("Stack is Empty");
                }
                break;
            case 4:
                printf("Printing the Stack\n");
                printStack(&ij);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

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
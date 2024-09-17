/*
Question 1. Implementation of  a stack using a singly linked list . 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode
{
    int data;
    struct stackNode * next;
}stackNode;

stackNode * push(stackNode*,int);
stackNode * pop(stackNode*);
int peek(stackNode*);
void printStack(stackNode*);

int main(){
    int choice;
    stackNode * st = NULL;
    printf("stack created :)");
    do{
        printf("\nPress\n1 to push\n2 to pop\n3 to peek\n4 to print the stack\n5 to end");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        int data,num;
        switch (choice)
        {
        case 1:
            printf("Enter element to push : ");
            scanf("%d",&data);
            st = push(st,data);
            break;
        case 2:
            st = pop(st);
            break;
        case 3:
            num = peek(st);
            printf("Top element is %d",num);
            break;
        case 4:
            printStack(st);
            break;
        default:
            choice = 37;
            break;
        }
    }while (choice != 37);
    
}

stackNode * push(stackNode* top,int ele){
    stackNode * pnode = (stackNode*)malloc(sizeof(stackNode));
    pnode->data = ele;
    if (top == NULL)
    {
        top = pnode;
        pnode->next = NULL;
    }else{
        pnode->next = top;
        top = pnode;
    }
    return top;
}


stackNode * pop(stackNode * top){
    if (top == NULL)
    {
        printf("Popping will lead to underflow");
    }else{
        stackNode * temp = top;
        top = top->next;
        printf("Popped element is %d",temp->data);
        free(temp);
    }
    return top;
}

int peek(stackNode* top){
    if (top ==  NULL)
    {
        return -1;
    }else{
        return top->data;
    }
}

void printStack(stackNode * top){
    stackNode * temp = top;
    if (top == NULL)
    {
        printf("Stack is empty");
    }
    printf("The Current Stack is : \n");
    while (temp != NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}
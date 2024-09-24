/*
1. Copy a stack onto another stack without changing the order: 
(A) using another temporary stack 
(B) using recursion
*/

#include<stdio.h>
#include "stack.c"

void copy(stack*,stack*);
void printStack(stack*);
void copyUsingtemp(stack*,stack *);

int main(){
    stack s1,s2,s3;
    s1 = init();
    s2 = init();
    s3 = init();
    int size;
    printf("Enter Number of elements in the Stack : ");
    scanf("%d",&size);
    for (int i = 0; i < size; i++)
    {   
        int temp;
        printf("Enter Data : ");
        scanf("%d",&temp);
        push(&s1,temp);
    }
    
    copyUsingtemp(&s1,&s3);
    printf("Printing Using Temporary Pointer");
    printStack(&s3);

    copyUsingtemp(&s3,&s1);
    copy(&s1,&s2);
    printf("Printing Using Recursion Method");
    printStack(&s2);
    return 0;
}

void copy(stack * s1,stack * s2){
    if (isEmpty(s1))
    {
        return;
    }
    int ele = pop(s1);
    copy(s1,s2);
    push(s2,ele);
    return;
}

void copyUsingtemp(stack* s1,stack * s3){
    stack temp = init();
    while (!isEmpty(s1))
    {
        push(&temp,pop(s1));
    }
    while (!isEmpty(&temp))
    {
        push(s3,pop(&temp));
    }
}

void printStack(stack*st){
    int temp = st->top;
    printf("Printing the stack :\n");
    while (temp!= -1)
    {
        printf("%d\n",st->arr[temp]);
        temp--;
    }
    
}

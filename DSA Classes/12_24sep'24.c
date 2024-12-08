/*
WAP to copy a stack to another Stack
without auxiliary
*/

#include<stdio.h>
#include<stdlib.h>
#include "stack.c"

int main(){
    stack s1,s2;
    s1 = init();
    s2 = init();
    push(&s1,15);
    push(&s1,17);
    copy(&s1,&s2);
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

void printStack(stack*st){
    int temp = st->top;
    printf("Printing the stack :");
    while (temp!= -1)
    {
        printf("%d\n",st->arr[temp]);
        temp--;
    }
    
}
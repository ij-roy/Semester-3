/*
3. Write a program to return max element in a stack. For this, use two stacks. 
Stack S1 that maintains ALL the elements and auxiliary/temp stack S2 that maintains the
current maximum.
a. Write a function push that 
    (i) pushes an element onto S1 
    (ii) pushes the element onto your S2 if it is the maximum element.
b. Write a function pop that 
    (a) checks if element exists on both stacks and if TRUE
        pops the element from both stacks, If FALSE pops from S1.
c. Write a function getMaximum that returns the top of S2
*/


#include<stdio.h>
#include "stack.c"

void printStack(stack*);
void maxpush(stack *,stack *);
void maxpop(stack *,stack *);
void flip(stack *);

int main(){
    stack s1,s2,s3,s1flip;
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
        push(&s3,temp);
    }
    flip(&s1);

    while (!isEmpty(&s1))
    {
        maxpush(&s1,&s2);
    }

    printf("\nPrinting after pushing into S2 :\n");
    printStack(&s2);

    int choice;
    printf("Enter number of elements to pop : ");
    scanf("%d",&choice);
    for (int i = 0; i < choice; i++)
    {
        maxpop(&s3,&s2);
    }
    printf("Both Stacks After Popping %d Elements",choice);
    printf("Original Queue:\n");
    printStack(&s3);
    printf("Ascending Queue:\n");
    printStack(&s2);

    printf("Maximum Element in the Stack is %d",top(&s2));
    return 0;
}

void maxpush(stack * s1,stack * s2){
    int ele = pop(s1);
    if (isEmpty(s2))
    {
        push(s2,ele);
        return;
    }
    int max = top(s2);
    if(ele>= max){
        push(s2,ele);
    } 
    return;
}

void maxpop(stack * s1 , stack * s2){
    int garbage;
    if (isEmpty(s1))
    {
        return;
    }
    if (top(s1) == top(s2))
    {
        garbage = pop(s1);
        garbage = pop(s2);
    }else{
        garbage = pop(s1);
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

void flip(stack * s1){
    stack temp1 = init();
    stack temp2 = init();
    while (!isEmpty(s1))
    {
        push(&temp1,pop(s1));
    }
    while (!isEmpty(&temp1))
    {
        push(&temp2,pop(&temp1));
    }
    while (!isEmpty(&temp2))
    {
        push(s1,pop(&temp2));
    }
}
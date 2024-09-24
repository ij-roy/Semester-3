/*
2. Write a program that deletes the middle element from the stack. Use a recursive 
function for this.
*/

#include<stdio.h>
#include "stack.c"

void printStack(stack*);
void deleteElement(stack *,stack *,int);

int main(){
    stack s1,s2,s3;
    s1 = init();
    s2 = init();
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
    printf("Enter Number to delete : ");
    int numberToDelete;
    scanf("%d",&numberToDelete);

    deleteElement(&s1,&s2,numberToDelete);
    printf("Stack After Deleting The Number \n");
    printStack(&s2);
    return 0;
}

void deleteElement(stack * s1,stack * s2,int numberToDelete){
    if (isEmpty(s1))
    {
        return;
    }
    int ele = pop(s1);
    if (ele != numberToDelete)
    {
        push(s2,ele);
    }
    deleteElement(s1,s2,numberToDelete);
    return;
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
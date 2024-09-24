#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

typedef struct {
    int arr [MAX];
    int top;
}stack;

stack init(){
    stack s;
    s.top = -1;
    return s;
}

int isEmpty(stack * ps){
    return (ps->top ==-1);
}

int isFull(stack * ps){
    return(ps->top ==MAX-1);
}

int top(stack * ps){
    if(isEmpty(ps))
    {
    printf("\nStack is empty");
    return 0;
    }
    return ps->arr[ps->top];
}

void push(stack * ps , int a){
    if(isFull(ps)){
    printf("\nno space: will overflow");
    }
    else{
    ps->top = ps->top+1;
    ps->arr[ps->top] = a;
    }
}

int pop(stack * ps){
    if(isEmpty(ps))
    {
    printf("\nno element: will underflow");
    return -1;
    }
    int ele = ps->arr[ps->top];
    ps->top --;
    return ele;
}

/*
int main(){
stack st;
st = init();
printf("\nCurrent stack: ");
push(&st,12);
printf("\ntop = %d \n",top(&st));
push(&st,22);
printf("\ntop = %d \n",top(&st));
printf("\nPopped ele = %d \n", pop(&st));
printf("\ntop = %d \n",top(&st));
printf("\nPopped ele = %d \n", pop(&st));
printf("\ntop = %d \n",top(&st));
printf("\nPopped ele = %d \n", pop(&st));
}
*/
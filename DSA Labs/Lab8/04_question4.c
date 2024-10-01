/*
4. Write a program to reverse a queue using a stack.
*/

#include<stdio.h>
#include "stack.c"

#define MAX 1000

typedef struct {
    int arr [MAX];
    int front;
    int rear;
}queue;

queue initq(){
    queue q;
    q.front = -1;
    q.rear = -1;
    return q;
}

int isEmptyq(queue * q){
    if(q->front == -1 && q->rear == -1){
    return 1;
    }
    else if(q->front > q->rear ){
        return 1;
    }else{
        return 0;
    }
}

int isFullq(queue * q){
    return(q->rear == MAX-1);
}

void enqueue(queue * q , int a){
    if(q->front == -1){
        q->front = q->rear = 0;
        q->arr[q->front] = a;
    }
    else if(isFullq(q)){
    printf("\nno space: will overflow");
    }
    else{
    q->rear = q->rear+1;
    q->arr[q->rear] = a;
    }
}

int dequeue(queue * q){
    if(isEmptyq(q))
    {
    printf("\nno element: will underflow");
    return -1;
    }
    int ele = q->arr[q->front];
    q->front++;
    return ele;
}

void displayqueue(queue * q){
    int temp = q->front;
    printf("Printing the queue : \n");
    printf("%d",q->arr[temp++]);
    while(temp <= q->rear){
        printf("-> %d",q->arr[temp]);
        temp+=1;
    }
}

int main(){
    int n;
    queue q;
    q = initq();
    stack s;
    s = init();
    
    printf("Enter Number of elements in queue : ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int data;
        printf("Enter data : ");
        scanf("%d",&data);
        enqueue(&q,data);
    }
    displayqueue(&q);
    // Reversing the queue 
    int temp = q.front;
    while (!isEmptyq(&q))
    {
        push(&s,dequeue(&q));
    }
    while (!isEmpty(&s))
    {
        enqueue(&q,pop(&s));
    }
    printf("\nAfter Reversing : \n");
    displayqueue(&q);
}
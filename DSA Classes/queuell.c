#include<stdio.h>
#include<stdlib.h>

typedef struct queueNode{
    int data;
    struct queueNode * next;
}queueNode;

typedef struct queue {
    queueNode * f;
    queueNode * r;
}queue;

queueNode * createNode(int data){
    queueNode * q =(queueNode *)malloc(sizeof(queueNode));
    q->data = data;
    q->next = NULL;
    return q;
}

queue * init(){
    queue * q =(queue *)malloc(sizeof(queue));
    q->f = NULL;
    q->r = NULL;
    return q;
}

int isEmpty(queue * q){
    return (q->f == NULL);
}

void enqueue(queue * q, int ele){
    queueNode * pnode =createNode(ele);
    if(isEmpty(q) ){
    q->f = pnode;
    q->r = pnode;
    printf("Enqueued element is:%d\n", ele);
    }
    else{
    q->r->next = pnode;
    q->r = pnode;
    printf("Enqueued element is:%d\n", ele);
    }
}

int dequeue(queue *q){
    if(isEmpty(q)){
    printf("queue is empty");
    return -1;
}

int ele = q->f->data;
    queueNode * ptr = q->f;
    q->f = q->f->next;
    if(q->f == NULL){
    q->r = NULL;
    }
    free(ptr);
    return ele;
}


/*
int main(){
queue * q;
q= init();
enqueue(q,10);
enqueue(q,20);
enqueue(q,30);
int i=0, ele;
for(; i<4;i++){
if((ele = dequeue(q))!= -1)
printf("Dequeued elelment is: %d\n",ele);
else
printf("\n");
}
enqueue(q,40);
}
*/

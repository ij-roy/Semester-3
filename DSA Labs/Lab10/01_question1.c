/*
Question 1. Write functions to implement a queue like behaviour using two stacks. This means
a FIFO behaviour is to be implemented on LIFO data structures.
    a. Use stack, s1, to enqueue the elements. When you need to enqueue, push onto
        s1. O(1) complexity
b. To simulate “first out”-> Use stack, s2, to dequeue.
    i. If s2 is not empty, pop from s2.
    ii. If s2 is empty then move elements from s1 to s2. The top of s2 is the
    “first in” element. POP from s2 so FIFO is successful!!!
    iii. What is complexity of your code?
*/

#include <stdio.h>
#include "stack.c"


typedef struct Queue {
    stack s1, s2;
} Queue;

void initQueue(Queue* q) {
    q->s1 = init();  
    q->s2 = init();  
}


void enqueue(Queue* q, int value) {
    push(&q->s1, value);
}

int dequeue(Queue* q) {
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }

    if (isEmpty(&q->s2)) {
        printf("Queue is empty\n");
        return -1;
    }

    return pop(&q->s2);
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 11);
    enqueue(&q, 12);
    enqueue(&q, 13);

    printf("dequeued:%d\n", dequeue(&q)); 
    printf("dequeued:%d\n", dequeue(&q)); 

    enqueue(&q, 15);

    printf("dequeued:%d\n", dequeue(&q)); 
    printf("dequeued:%d\n", dequeue(&q)); 

    return 0;
}
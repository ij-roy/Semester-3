/*
Questin 2. Circular Queue using Linked List
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct circularQueue
{
    int data;
    struct circularQueue * next;
}circularQueue;

circularQueue * enqueue(circularQueue*,int);
circularQueue * dequeue(circularQueue*);
void displayQueue(circularQueue*);

int main(){
    int choice;
    circularQueue * rear = NULL;
    printf("queue created :)");
    do{
        printf("\nPress\n1 to enqueue\n2 to dequeue\n3 to display the queue\n4 to end");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        int data,num;
        switch (choice)
        {
        case 1:
            printf("Enter element to queue : ");
            scanf("%d",&data);
            rear = enqueue(rear,data);
            break;
        case 2:
            rear = dequeue(rear);
            break;
        case 3:
            displayQueue(rear);
            break;
        default:
            choice = 37;
            break;
        }
    }while (choice != 37);
    
}

circularQueue * enqueue(circularQueue* rear,int ele){
    circularQueue * pnode = (circularQueue*)malloc(sizeof(circularQueue));
    pnode->data = ele;
    if (rear == NULL)
    {
        rear = pnode;
        pnode->next = pnode;
    }else{
        circularQueue * front = rear->next;
        rear->next = pnode;
        pnode->next = front;
        rear = pnode;
    }
    return rear;
}


circularQueue * dequeue(circularQueue * rear){
    circularQueue * front = rear->next;
    if (front == NULL)
    {
        printf("Dequeue will lead to underflow");
    }else{
        circularQueue * temp = front;
        front = front->next;
        rear->next = front;
        printf("Dequeued element is %d",temp->data);
        free(temp);
    }
    
    return rear;
}

void displayQueue(circularQueue * rear){
    circularQueue * front = rear->next;
    circularQueue * temp = front;
    if (front == NULL)
    {
        printf("Queue is empty");
    }
    printf("The Current Queue is : \n");
    printf("%d",temp->data);
    temp = temp->next;
    while (temp != front){
        printf("-> %d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
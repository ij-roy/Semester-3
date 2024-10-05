/*
Priority Queue
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct priorityQueue
{
    int data;
    int priority;
    struct priorityQueue * next;
}priorityQueue;

priorityQueue * enqueue(priorityQueue*,int,int);
priorityQueue * dequeue(priorityQueue*);
void displayQueue(priorityQueue*);

int main(){
    int choice;
    priorityQueue * head = NULL;
    printf("queue created :)");
    do{
        printf("\nPress\n1 to enqueue\n2 to dequeue\n3 to display the queue\n4 to end");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        int data,num,priority; 
        switch (choice)
        {
        case 1:
            printf("Enter element to queue : ");
            scanf("%d",&data);
            printf("Enter priority : ");
            scanf("%d",&priority);
            head = enqueue(head,data,priority);
            break;
        case 2:
            head = dequeue(head);
            break;
        case 3:
            displayQueue(head);
            break;
        default:
            choice = 37;
            break;
        }
    }while (choice != 37);
    
}

priorityQueue * enqueue(priorityQueue* head,int ele,int priority){
    priorityQueue * pnode = (priorityQueue*)malloc(sizeof(priorityQueue));
    pnode->data = ele;
    pnode->priority = priority;
    pnode->next = NULL;
    if (head == NULL)
    {
        head = pnode;
        pnode->next = NULL;
    }else if(priority<head->priority){
        pnode->next = head;
        head=pnode;
    }else{
        priorityQueue*prev = head;
        priorityQueue* temp = head->next;
        while (temp != NULL)
        {
            if (priority<temp->priority){
                pnode->next = temp;
                prev->next = pnode;
                return head;
            }
            prev = temp;
            temp = temp->next;
        }
        prev->next = pnode;
        
    }
    return head;
}


priorityQueue * dequeue(priorityQueue * front){
    if (front == NULL)
    {
        printf("Dequeue will lead to underflow");
    }else{
        priorityQueue * temp = front;
        front = front->next;
        printf("Dequeued element is %d",temp->data);
        printf("Its Priority is %d\n",temp->priority);
        free(temp);
    }
    
    return front;
}

void displayQueue(priorityQueue * front){
    priorityQueue * temp = front;
    if (front == NULL)
    {
        printf("Queue is empty");
    }
    printf("The Current Queue is : \n");
    printf("%d[%d]",temp->data,temp->priority);
    temp = temp->next;
    while (temp != NULL){
        printf("-> %d[%d]",temp->data,temp->priority);
        temp = temp->next;
    }
    printf("\n");
}
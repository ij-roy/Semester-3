/*
Question 2. Consider a petrol filling station with a single filling booth. Cars line up to fill fuel as they 
come into the filling station and are serviced on a first come first serve basis. However, if an 
ambulance arrives then it jumps the line and becomes the first in the waiting queue. Write a 
program to simulate the petrol filling station. Assume the ambulance is represented by a special 
integer number.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct petrolQueue
{
    int data;
    struct petrolQueue * next;
}petrolQueue;

petrolQueue * enqueueVehicle(petrolQueue*,int);
petrolQueue * enqueueAmbulance(petrolQueue*,int);
petrolQueue * dequeue(petrolQueue*);
void displayQueue(petrolQueue*);

int main(){
    int choice;
    petrolQueue * head = NULL;
    printf("Welcome to the Gas Station :)");
    do{
        printf("\nPress\n1 to enqueue a vehicle\n2 to enqueue an ambulance\n3 to fill petrol\n4 to display the queue\n5 to end");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        int data,num; 
        switch (choice)
        {
        case 1:
            printf("Enter Vehicle number to enqueue : ");
            scanf("%d",&data);
            head = enqueueVehicle(head,data);
            break;
        case 2:
            printf("Enter Ambulance number to enqueue(Fastt!) : ");
            scanf("%d",&data);
            head = enqueueAmbulance(head,data);
            break;
        case 3:
            head = dequeue(head);
            break;
        case 4:
            displayQueue(head);
            break;
        default:
            choice = 37;
            break;
        }
    }while (choice != 37);
    
}

petrolQueue * enqueueVehicle(petrolQueue* head,int data){
    petrolQueue * pnode = (petrolQueue*)malloc(sizeof(petrolQueue));
    pnode->data = data;
    pnode->next = NULL;
    if (head == NULL)
    {
        head = pnode;
        pnode->next = NULL;
    }else
    {
        petrolQueue * temp = head;
        while (temp ->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = pnode;
        
    }
    return head;
}

petrolQueue * enqueueAmbulance(petrolQueue* head,int data){
    petrolQueue * pnode = (petrolQueue*)malloc(sizeof(petrolQueue));
    pnode->data = data;
    if (head == NULL)
    {
        head = pnode;
        pnode->next = NULL;
    }else
    {
     pnode->next = head;
     head = pnode;   
    }
    return head;
}

petrolQueue * dequeue(petrolQueue * front){
    if (front == NULL)
    {
        printf("No Vehicle to fill gas\n");
    }else{
        petrolQueue * temp = front;
        front = front->next;
        printf("Petrol filled in %d\n",temp->data);
        free(temp);
    }
    return front;
}

void displayQueue(petrolQueue * front){
    petrolQueue * temp = front;
    if (front == NULL)
    {
        printf("Queue is empty:(\n");
        return;
    }
    printf("The Current Queue is : \n");
    printf("%d",temp->data);
    temp = temp->next;
    while (temp != NULL){
        printf("-> %d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
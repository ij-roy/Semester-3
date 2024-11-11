/*
Question 1. Consider a parking lane with 10 slot number numbered 0...9. Cars enter the lane from one 
end and park their cars. Cars exit the parking lane from the other end. If a car, e.g. in slot 4, has 
to exit, then all the cars in slots 0 to 3 are put into a temporary queue. Once a car in slot 4 exits, 
cars are put back in the same order. 
Assume that each car is an integer number. Write a program to simulate the parking lane. You 
can  use  any  data  structure/combination  of  data  structures  from  stacks/queues-
circular/priority/simple of your choice. 
Input: [0,1,2,3,4,5,6,7,8,9] Want to remove car 4 Output: [0,1,2,3,  , 5,6,7,8,9] 
Input: [0,1,2,3,  , 5,6,7,8,9] Want to add car 44  Output: [0,1,2,3, 44, 5,6,7,8,9]
*/

#include <stdio.h>
#include <stdlib.h>

#define N 10

//for parking lane
int parkingLane[N];

//for temp queue
int tempQueue[N];
int frontTemp = -1;
int rearTemp = -1;

void tempEnqueue(int);
int tempDequeue();
void parkVehicle(int);
void pickVehicle(int);
void displayParkingLane();

int main(){
    int choice;
    for (int i = 0; i < N; i++)
    {
        parkingLane[i] = -1;
    }
    
    do{
        printf("\nPress\n1 to Park Vehicle\n2 to Pick Vehicle\n3 to display the Parking Lane\n4 to end");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        int data,num;
        switch (choice)
        {
        case 1:
            printf("Enter Vehicle Number to park: ");
            scanf("%d",&data);
            parkVehicle(data);
            break;
        case 2:
            printf("Enter Vehicle Number to pick: ");
            scanf("%d",&data);
            pickVehicle(data);
            break;
        case 3:
            displayParkingLane();
            break;
        default:
            choice = 37;
            break;
        }
    }while (choice != 37);
}

void tempEnqueue(int x){
    if (frontTemp == -1 && rearTemp == -1)
    {
        frontTemp = rearTemp = 0;
        tempQueue[rearTemp] = x;
    }else if ((rearTemp+1)%N == frontTemp){
        printf("Temporary queue is full");
    }else{  
        rearTemp = (rearTemp+1)%N;
        tempQueue[rearTemp] = x;
    }
}

int tempDequeue(){
    int data ;
    if (frontTemp == -1 && rearTemp == -1)
    {
        printf("Temporary Queue is empty");
    }else if (frontTemp == rearTemp)
    {
        data = tempQueue[frontTemp];
        frontTemp = rearTemp = -1;
    }else{
        data = tempQueue[frontTemp];
        frontTemp = (frontTemp+1)%N;
    }
    return data;
}

void parkVehicle(int num){
    int flag = 1;
    for (int i = 0; i < N; i++)
    {
        if (parkingLane[i] == num)
        {
            printf("Vehicle %d already exists:\n",num);
            flag = 0;
            break;
            
        }else if (parkingLane[i] == -1){
            parkingLane[i] = num;
            flag = 0;
            break;
        }
        
    }
    if (flag)
    {
        printf("Parking lane is Full :(\n");
    }
}

void pickVehicle(int num){
    int flag = 1;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (parkingLane[i] != num)
        {
            tempEnqueue(parkingLane[i]);
            parkingLane[i] = -1;
            count+=1;
        }else if (parkingLane[i] == num)
        {
            flag = 0;
            printf("Vehicle number %d is picked successfully :)",num);
            parkingLane[i] = -1;
            break;
        }
    }
    for (int i = 0; i < count; i++)
    {
        parkVehicle(tempDequeue());
    }
    if (flag)
    {
        printf("Vehicle number %d is not found in parking lane :(",num);
    }
    printf("\n");
}

void displayParkingLane(){
    printf("Displaying the parking lane\n':(' this represents no vehicle\n[");
    if (parkingLane[0] != -1)
        {
            printf("%d",parkingLane[0]);
        }else if (parkingLane[0] == -1){
            printf(":(");
        }
    for ( int i = 1; i < N; i++)
    {
        if (parkingLane[i] != -1)
        {
            printf(",%d",parkingLane[i]);
        }else if (parkingLane[i] == -1){
            printf(",:(");
        }
    }
    printf("]\n");
}
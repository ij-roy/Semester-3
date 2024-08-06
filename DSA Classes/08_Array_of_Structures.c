// Array of Structures

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[20];
    int rollNo;
}student;

int main(){
    // student arr[5] or
    student*ptr = (student*)malloc(5*sizeof(student));

    for (int i = 0; i < 5; i++)
    {
        printf("Enter Name : ");
        scanf(" %[^\n]%*c",ptr[i].name);
        printf("Enter Roll Number : ");
        scanf("%d",&ptr[i].rollNo);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("Name : %s\n",ptr[i].name);
        printf("Roll Number : %d\n",ptr[i].rollNo);
    }

    return 0;
}
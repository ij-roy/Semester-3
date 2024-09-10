/*
Question 3 . Create a single linked list of non-negative integers. 
Write a function to display the nodes of your list. 
This should be a menu driven program.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number ;
    struct node * next;
}node;

int main(){
    int size;
    node * pnode = NULL;//Temp
    node * pstart = NULL;
    node * ptr = NULL;//Current 
    printf("Enter Size of array : ");
    scanf("%d",&size);
    for (int i = 0; i < size; i++){

        pnode = (node*)malloc(sizeof(node));

        printf("Enter data for node %d : ",i+1);
        scanf("%d",&pnode->number);
        pnode->next = NULL;

        if (pstart == NULL)
        {
        pstart = pnode;
        }else{
            ptr->next = pnode;
        }
        ptr = pnode;
    }

    printf("Printing the nodes : \n");
    ptr = pstart;
    while (ptr != NULL)
    {
        printf("%d\n",ptr->number);
        ptr = ptr->next;
    } 
    //Free Memory Allocated
    ptr = pstart;
    while (ptr != NULL) {
        node *temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    return 0;
}

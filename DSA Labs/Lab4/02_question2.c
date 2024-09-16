/*
Question 2.Write a function to create a circular linked list. Insert values 12, 13, 88, 99 in it. Write a display
function to display the values. 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node;

node * createNode(node *);
void displayCLL(node *);

int main(){
    int size;
    node * pnode = NULL; //Temp
    node * pstart = NULL;
    node * ptr = NULL; //Current 
    printf("Enter Size of array : ");
    scanf("%d",&size);
    for (int i = 0; i < size; i++)
    {
        pstart = createNode(pstart);
    } 
    displayCLL(pstart);
}

node * createNode(node * pstart){
    node * ptr = pstart; //Current 
    node * pnode = (node*)malloc(sizeof(node));
    printf("Enter data for node : ");
    scanf("%d",&pnode->data);
    pnode->next = NULL;


    if (pstart == NULL)
    {
        pstart = pnode;
    }else{
        while (ptr->next != pstart)
        {
            ptr = ptr->next;
        }
        ptr->next = pnode;
    }
    pnode -> next = pstart;
    return pstart;
}

void displayCLL(node * pstart){
    node * temp = pstart;
    do{
        printf("%d->",temp->data);
        temp = temp->next;
    }while (temp != pstart);
    printf("%d ... ",temp->data);
}

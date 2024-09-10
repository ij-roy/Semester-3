/*
Question 3 . Write a program to create a single linked list of non-negative integers.
Note: No global pointer variables should be used.
    a. Write a function to create the linked list. Call this method from main so 
    that a list of 5 elements can be created. 
    Take the integer of the node from the user.
    b. Write a function to display the nodes of your list.
    c. Write a function to insert a node at the beginning of the linked list. 
    Again take the integer to be inserted from the user
    d. Call your function to display your list again.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    unsigned int number;
    struct node * next;
}node;

node * createNode(node* pstart);
void displayll(node*pstart);
node * insertAtBeginning(node* pstart);

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
    displayll(pstart);
    pstart = insertAtBeginning(pstart);
    displayll(pstart);
}

node * createNode(node* pstart){
    node * ptr = NULL; //Current 
    node * pnode = (node*)malloc(sizeof(node));

    printf("Enter data for node : ");
        scanf("%d",&pnode->number);
        pnode->next = NULL;

    if (pstart == NULL)
    {
        pstart = pnode;
    }else{
        node * ptr = pstart;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = pnode;
    }
    return pstart;
}

void displayll(node*pstart){
    if (pstart == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    node*ptr = pstart;
    while (ptr != NULL)
    {
        printf("%d -> ",ptr->number);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

node * insertAtBeginning(node* pstart){
    node * pnode = (node*)malloc(sizeof(node));
    printf("Inserting At Beginning\n");
    printf("Enter data for node : ");
    scanf("%d",&pnode->number);
    pnode->next = pstart;
    pstart = pnode;
    return pstart;
}
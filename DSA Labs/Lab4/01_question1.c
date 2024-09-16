/*
Question 1. 1. Modify Q3 done in Lab 3 to add the following: Note: No global pointer 
variables should be used.
    a. Write a function to insert a node at the end of the linked list. Again, 
    take the integer to be inserted from the user
    b. Call your function to display your list again.
    c. Write a function to insert a node with integer 12 after a particular node with 
    integer value, x, in the linked list. Take the value of x from the user.
    d. Call your function to display your modified list
    e. Write a function to insert a node before the node with value 12. Take the 
    value of the node to be inserted from the user.
    f. Call your function to display your modified list
    g. Write a function to delete a node of your linked list. Take the choice of the 
    node from the user. Test your code for a node for the first node, last node and 
    any other node of the linked list. Call your function to display your modified list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    unsigned int number;
    struct node * next;
}node;

node * createNode(node* );
void displayll(node*);
node * insertAtBeginning(node* );
node * insertAtEnd(node *);
node * insertAfterN(node*);
node * insertBeforeN(node*);
node * deleteNode(node*);

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
    // pstart = insertAtBeginning(pstart);
    // displayll(pstart);
    pstart = insertAtEnd(pstart);
    displayll(pstart);
    pstart = insertAfterN(pstart);
    displayll(pstart);
    pstart = insertBeforeN(pstart);
    displayll(pstart);
    pstart = insertAtEnd(pstart);
    displayll(pstart);
    pstart = deleteNode(pstart);
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
    printf("Enter data for insert at beginning : ");
    scanf("%d",&pnode->number);
    pnode->next = pstart;
    pstart = pnode;
    return pstart;
}

node * insertAtEnd(node * pstart){
    node * temp = pstart;
    node * pnode = (node*)malloc(sizeof(node));
    printf("Enter data for insert at end : ");
    scanf("%d",&pnode->number);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = pnode;
    pnode->next = NULL;
    return pstart;
}

node* insertAfterN(node* pstart){
    node * temp = pstart;
    node * pnode = (node*)malloc(sizeof(node));
    int number;
    printf("Enter Data you want to insert : ");
    scanf("%d",&pnode->number);
    printf("Enter Number After Which you want to insert : ");
    scanf("%d",&number);
    while (temp->number != number)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("%d doesnot exist in list\n",number);
            return pstart;
        }
    }
    pnode->next = temp->next;
    temp->next = pnode;
    return pstart;
}

node* insertBeforeN(node* pstart){
    node * temp = pstart;
    node * pnode = (node*)malloc(sizeof(node));
    int number;
    printf("Enter Data you want to insert : ");
    scanf("%d",&pnode->number);
    printf("Enter Number Before Which you want to insert : ");
    scanf("%d",&number);
    if (pstart->number == number)
    {
        pnode->next = pstart;
        pstart = pnode;
        return pstart;
    }
    
    while (temp->next->number != number)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("%d doesnot exist in list\n",number);
            return pstart;
        }
    }
    pnode->next = temp->next;
    temp->next = pnode;
    return pstart;
}

node * deleteNode(node* pstart){
    node * temp = pstart;
    node * prev = pstart;
    int number;
    printf("Write the number you want to delete : ");
    scanf("%d",&number);
    if (pstart->number == number)
    {
        pstart = pstart ->next;
        free(temp);
    }else{
        while (temp->number != number)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);  
    }
    return pstart;
}

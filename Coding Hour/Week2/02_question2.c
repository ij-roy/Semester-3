/*
You are given a pointer to the head node of a singly linked list and an integer value that you need to insert at a specified position in the list. Your task is to create a new node with the given integer as its value, insert this node at the specified position, and return the pointer to the head of the modified list.

A position of 0 indicates that the new node should be inserted at the head of the list.
A position of 1 indicates that the new node should be inserted immediately after the head, and so on.
The given head pointer may be null, indicating that the initial list is empty.
Function Description:

Complete the function insertNodeAtPosition below. It must return a pointer to the head node of the updated list.

Parameters:

head (SinglyLinkedListNode): A pointer to the head of the linked list.
data (int): The integer value to be inserted into the new node.
position (int): The zero-based index at which the new node should be inserted.
Returns:

SinglyLinkedListNode: A pointer to the head of the updated list.
Input Format

The first line contains an integer n, the number of elements in the linked list.
Each of the next n lines contains an integer SinglyLinkedListNode[i].data.
The next line contains an integer data, the data of the node that is to be inserted.
The last line contains an integer position.
Constraints

1<=n<=1000.
O<=position<=n.
1<=SingleLinkedListNode[i].data<=1000,where SingleLinkedListNode[i] is the ith element of the linkedlist.
Output Format

Print the elements of the modified linked list after the insertion of the new node.
The elements should be printed in a single line, separated by spaces.
Sample Input 0
5
10
20
30
40
50
25  
2   
Sample Output 0
10 20 25 30 40 50
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    unsigned int number;
    struct node * next;
}node;

node * createNode(node* ,int);
void displayll(node*);
node * insertAtBeginning(node* ,int);
node * insert(node *,int,int);

int main()
{
    FILE* fptr = fopen("02_testcases.txt","r");

    if(fptr ==NULL){
        printf("Error Opening File.\n");
        return 1;
    }

    node * pstart = NULL;
    int n ;
    fscanf(fptr, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        int number ;
        fscanf(fptr, "%d", &number);
        pstart = createNode(pstart, number);
    }
    int number ;
    fscanf(fptr, "%d", &number);
    int position ;
    fscanf(fptr, "%d", &position);
    pstart = insert(pstart,number,position);

    displayll(pstart);

    fclose(fptr);

    return 0;
}

node * createNode(node* pstart,int number){
    node * ptr = NULL; //Current 
    node * pnode = (node*)malloc(sizeof(node));

    pnode->number = number;
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
        printf("%d ",ptr->number);
        ptr = ptr->next;
    }
}

node* insert(node* pstart,int number,int position){
    if (position == 0)
    {
        pstart= insertAtBeginning(pstart,number);
        return pstart;
    }
    
    node * temp = pstart;
    node * pnode = (node*)malloc(sizeof(node));
    pnode->number = number;
    int i = 1;
    while (i<position)
    {
        temp = temp->next;
        i++;
    }
    pnode->next = temp->next;
    temp->next = pnode;
    return pstart;
}

node * insertAtBeginning(node* pstart,int number){
    node * pnode = (node*)malloc(sizeof(node));
    pnode->number = number;
    pnode->next = pstart;
    pstart = pnode;
    return pstart;
}
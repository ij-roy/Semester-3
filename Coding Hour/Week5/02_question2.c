/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

image

Input Format

First Line: An integer n, the number of nodes in the linked list.
Next n Lines: Each line contains a single integer representing the data for each node in the linked list, listed from the head to the end.
Constraints

The number of nodes in the list is in the range [1, 1000].
0 <= Node.val <= 9
Output Format

The head of the reordered singly linked list, where all odd-indexed nodes come before even-indexed nodes, while preserving their original relative order.

Sample Input 0
5
1
2
3
4
5
Sample Output 0
1 3 5 2 4
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node * next;
}node;

node * createNode(node* ,int);
void displayll(node*);
node * oddEvenLinkedList(node*);

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

    pstart = oddEvenLinkedList(pstart);

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

node * oddEvenLinkedList(node * pstart){
    node * odd = NULL;
    node * even = NULL;
    node * temp = pstart;
    int i =0;
    while (temp != NULL)
    {
        if (i%2 == 0)
        {
            odd = createNode(odd,temp->number);
        }else
        {
            even = createNode(even,temp->number);
        }
        i++;
        temp = temp->next;
    }
    temp = odd;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = even;
    return odd;
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
/*
iven the head of a linked list and an integer k, complete the function deleteKthFromLast 
that deletes the k-th node from the end of the linked list and returns the head of the 
modified linked list.

Input Format

First Line: An integer n, the number of nodes in the linked list.
Next n Lines: Each line contains a single integer representing the data for each node in 
the linked list, listed from the head to the end.
Last Line: An integer k, the position from the end of the linked list indicating the node 
that should be deleted.

Constraints
1<=n<=1000.
O<=k<=n.

Output Format
Print the elements of the modified linked list after the deletion of the node.

Sample Input 0
4
1
2
3
4
2
Sample Output 0
1 2 4
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node * next;
}node;

node * createNode(node* ,int);
void displayll(node*);
node * deleteKthFromLast(node *,int);

int main()
{
    FILE* fptr = fopen("01_testcases.txt","r");

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
    int position ;
    fscanf(fptr, "%d", &position);
    pstart = deleteKthFromLast(pstart,position);

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

node* deleteKthFromLast(node* pstart,int position){
    int total = 0;
    node * temp = pstart;
    node * prev = NULL;
    while (temp!=NULL)
    {
        temp = temp->next;
        total++;
    }
    temp  = pstart;
    int count = total - position;
    for (int i = 0; i < count; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    return pstart;
}

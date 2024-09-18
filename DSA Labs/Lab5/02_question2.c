/*
Question 2. Represent a sparse matrix as a linked list. Consider the matrix given 
below
0 0 1
0 3 0
0 0 2
the only elements of interest are at index (0,2), (1,1) and (2.2). Thus, create a 
linked list where each node has the following elements:
𝑡𝑦𝑝𝑒𝑑𝑒𝑓 𝑠𝑡𝑟𝑢𝑐𝑡{𝑖𝑛𝑡 𝒓𝒐𝒘, 𝑖𝑛𝑡 𝒄𝒐𝒍, 𝑖𝑛𝑡 𝒗𝒂𝒍𝒖𝒆, 𝑠𝑡𝑟𝑢𝑐𝑡 𝑛𝑜𝑑𝑒 ∗ 𝒏𝒆𝒙𝒕} node;
Your program must do the following:
a. Take the n*n sparse matrix from the user.
b. Store only non-zero elements of the matrix in the linked list.
c. Print the linked list.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int row;
    int col;
    int value;
    struct node * next;
}node;

node * createNode(node*,int,int,int);
void printMatrix(node *,int);

int main(){
    int n;
    node * pstart = NULL;
    printf("Enter value of n in n*n square matrix : ");
    scanf("%d",&n);
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            int temp = 0;
            printf("enter value of A(%d*%d) : ",i,j);
            scanf("%d",&temp);
            if (temp != 0)
            {
                pstart = createNode(pstart,i,j,temp);
            }
        }
    }
    printf("Only non Zero elements are stored in the list\n");
    printf("Printing the Linked List : \n");
    printMatrix(pstart,n);
}

node * createNode(node*pstart,int i,int j,int value){
    node * pnode = (node*)malloc(sizeof(node));
    pnode->row = i;
    pnode->col = j;
    pnode->value = value;
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


void printMatrix(node * pstart,int n){
    node * ptr = pstart;
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if (ptr!= NULL && ptr->row == i && ptr->col == j)
            {
                printf("%d\t",ptr->value);
                ptr = ptr->next;
            }else{
                printf("0\t");
            }
        }
        printf("\n");
    }
    
}
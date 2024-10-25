/*
ou are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
Example

image
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation: The above figure represents the given linked list. The indices of the nodes are written below. Since n = 7, node 3 with value 7 is the middle node, which is marked in red. We return the new list after removing this node.

Input Format

First Line: An integer n, the number of nodes in the linked list.
Next n Lines: Each line contains a single integer representing the data for each node in the linked list, listed from the head to the end.
Constraints

The number of nodes in the list is in the range [1, 100000].
1 <= Node.val <= 105
Output Format

Print the elements of the modified linked list after the deletion of the node.
Sample Input 0

7
1
3
4
7
1
2
6
Sample Output 0

1 3 4 1 2 6
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node * next;
}node;

node * createNode(node* ,int);
void displayll(node*);
node * deleteMiddle(node *);

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

    pstart = deleteMiddle(pstart);

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

node* deleteMiddle(node* pstart){
    int total = 0;
    node * temp = pstart;
    node * prev = NULL;
    while (temp!=NULL)
    {
        temp = temp->next;
        total++;
    }
    temp  = pstart;
    printf("%d\n", total);
    int count = (total+1)/2;
    for (int i = 1; i < count; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    return pstart;
}

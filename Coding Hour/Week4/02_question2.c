/*
Given the head of a singly linked list, return 1 as true if it is a palindrome or 0 as false otherwise.

Example 1:

Input: head = [1,2,3,2,1]
Output: 1
image

Input Format

First Line: An integer n, the number of nodes in the linked list.
Next n Lines: Each line contains a single integer representing the data for each node in the linked list, listed from the head to the end.
Constraints

The number of nodes in the list is in the range [1, 10000].
0 <= Node.val <= 9
Output Format

For each test case, the only line of output that print '1' for true if the list is Palindrome or 0 for false otherwise.
Sample Input 0

5
1  
2 
3
2
1
Sample Output 0

1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node * next;
}node;

node * createNode(node* ,int);
void displayll(node*);
int checkPalindrome(node*);

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

    printf("%d",checkPalindrome(pstart));

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

int checkPalindrome(node *pstart){
    int arr[1000];
    int i = 0;
    for (node* temp = pstart;temp != NULL;temp = temp->next)
    {
        arr[i++] = temp->number;
    }
    for (int start = 0, end = i - 1; start < end; start++, end--) {
        if (arr[start] != arr[end]) {
            return 0; // Not a palindrome
        }
    }
    return 1;
}

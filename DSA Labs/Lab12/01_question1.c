/*
Question 1. Write a function to sort an array by of integers by their absolute values. If
two integers have the same absolute value, then the negative number
comes before the positive number.
Input: 9, -1, 4, 8, -11, -5, 1
Output: -1, 1, 4, -5, 8, 9, -11
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node * next;
}node;

node * createNode(node* , int);
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
    pstart = absoluteSort(pstart); 
}
node * absoluteSort(node * pstart){
    node * temp = pstart;
    node * head = NULL;
    while (temp != NULL)
    {
        int data = temp->number;
        int mod = data>0?data:data*(-1);
        node * tempnew = head;
        while (tempnew != NULL)
        {
            if (tempnew->number < mod)
            {
                tempnew = tempnew->next;
                continue;
            }else if (tempnew->number > mod){
                head = insertBeforeN(head, data);
            }else if (tempnew->number == mod)
            {
                /* code */
            }
            
            tempnew = tempnew->next;
        }
        temp = temp->next;
    }
    
}
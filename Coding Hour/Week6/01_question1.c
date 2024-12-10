/*
Write a C program to implement a Stack using a Linked List with the following menu options:

Push: Add an element to the stack.
Pop: Remove the top element from the stack. If the stack is empty, display "Stack is Empty".
Display Stack Top: Display the top element of the stack. If the stack is empty, display "Stack is Empty".
Exit: Exit the program.
Input Format

1 for Push (requires an additional input for the element to be pushed onto the stack).
2 for Pop.
3 for Display Stack Top.
4 for Exit.
Constraints

There are no specific constraints for input values, but the stack operates in standard LIFO (Last In, First Out) fashion.

Output Format

For Push (1), no output is needed.
For Pop (2), "Stack is Empty" if the stack was already empty otherwise remove element.
For Display Stack Top (3), display the top element, or "Stack is Empty" if the stack is empty.
For Exit (4), terminate the program.
Sample Input 0
1
101
1
201
1
102
2
2
3
4
Sample Output 0
101
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}node;

node * push(node*pstart,int data);
node * pop(node*pstart);
void peek(node * pstart);

int main() {
    int choice ;
    int data;
    node * pstart = NULL;

    FILE* fptr = fopen("01_testcases.txt","r");

    if(fptr ==NULL){
        printf("Error Opening File.\n");
        return 1;
    }

    do{
        fscanf(fptr,"%d",&choice);
        if(choice == 1){
            fscanf(fptr,"%d",&data);
            pstart = push(pstart , data);
        }else if(choice == 2){
            pstart = pop(pstart);
        }else if(choice == 3){
            peek(pstart);
        }else{
            choice = 4;
        }
    }while(choice !=4);
    return 0;
}

node * push(node*pstart,int data){
    node * pnode = NULL;
    pnode = (node*)malloc(sizeof(node));
    pnode->data = data;
    pnode->next = NULL;
    if(pstart == NULL){
        pstart = pnode;
    }else{
        pnode -> next = pstart;
        pstart = pnode;
    }
    return pstart;
}

node * pop(node*pstart){
    if(pstart == NULL){
        printf("Stack is Empty\n");
    }else{
        pstart = pstart->next;
    }
    return pstart;
}

void peek(node * pstart){
    if (pstart == NULL){
        printf("Stack is Empty\n");
    }else{
        printf("%d\n",pstart->data);
    }
}



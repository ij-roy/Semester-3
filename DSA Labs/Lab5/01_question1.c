/*
Question 1. Represent a polynomial using a linked list. Each node contains three 
parts: Coefficient, Exponent, Next Pointer. For example, a polynomial
will be represented as
    Write a program to:
    a. Write a function to create a linked list for two polynomials given by the 
    user.
    b. Write a function to print the linked list
    c. Write a function add, that adds two polynomials and store the result in a 
    new linked list. This function should traverse both linked lists and add the 
    terms with the same exponents.
    d. Call the print function 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coeff;
    int expo;
    struct node * next;
}node;

node * createNode(node *,int,int);
void displayPolynomial(node *);
node * addPolynomial(node*,node*);


int main(){
    int num;
    node * pstart1 = NULL;
    node * pstart2 = NULL;
    node * sum = NULL;
    printf("Enter number of terms in polynomial 1 : ");
    scanf("%d",&num);
    for (int i = 0; i < num; i++)
    {
        int coeff , expo;
        printf("Enter coefficient : ");
        scanf("%d",&coeff);
        printf("Enter exponent : ");
        scanf("%d",&expo);
        pstart1 = createNode(pstart1,coeff,expo);

    }
    printf("Enter number of terms in polynomial 2 : ");
    scanf("%d",&num);
    for (int i = 0; i < num; i++)
    {
        int coeff , expo;
        printf("Enter coefficient : ");
        scanf("%d",&coeff);
        printf("Enter exponent : ");
        scanf("%d",&expo);
        pstart2 = createNode(pstart2,coeff,expo);

    }
    printf("Polynomial 1 : ");
    displayPolynomial(pstart1);
    printf("Polynaomial 2 : ");
    displayPolynomial(pstart2);

    printf("\nPrinting The Sum : ");
    sum = addPolynomial(pstart1,pstart2);
    displayPolynomial(sum);
    
}

node * createNode(node * pstart, int coefficient , int exponent){
    
    node * temp = pstart;
    node * pnode = (node*)malloc(sizeof(node));
    pnode->coeff = coefficient;
    pnode->expo = exponent;
    pnode->next = NULL;

    if (pstart == NULL)
    {
        pstart = pnode;
    }else{
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = pnode;
    }
    return pstart;
}

void displayPolynomial(node * pstart){
    node * temp = pstart;
    while (temp != NULL)
    {
        printf("%dX^%d",temp->coeff,temp->expo);
        if (temp->next != NULL)
        {
            printf(" + ");
        }
        temp = temp->next;
        
    }
    
}

node * addPolynomial(node * pstart1 , node * pstart2){
    node * pstart = NULL;
    node * temp;
    while (pstart1!=0 && pstart2!=0)
    {
        if (pstart1->expo > pstart2->expo)
        {
            pstart = createNode(pstart,pstart1->coeff,pstart1->expo);
            pstart1 = pstart1->next;
        }else if (pstart1->expo < pstart2->expo)
        {
            pstart = createNode(pstart,pstart2->coeff,pstart2->expo);
            pstart2 = pstart2->next;
        }else{
            pstart = createNode(pstart,pstart1->coeff+pstart2->coeff,pstart1->expo);
            pstart1 = pstart1->next;
            pstart2 = pstart2->next;
        }
        
    }
    return pstart;
    
}
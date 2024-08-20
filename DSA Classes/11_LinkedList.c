#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int number;
    struct node * next ;
}node;
void display(node *);
node * create(node *);
node * insertStart(node *);

int main(){
    node * pstart = NULL;
    printf("Enter Number of elements : ");
    int N;
    scanf("%d",&N);
    for (int i = 0; i < N; i++)
    {
        pstart = create(pstart);
    }
    display(pstart);
    pstart = insertStart(pstart);
    printf("Printing New List : \n");
    display(pstart);
    return 0;
}
node * create(node * pstart){
    node * ptr;
    node * pnode = (node*)malloc(sizeof(node));
    if (pnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter a number: ");
    scanf("%d", &pnode->number);
    pnode->next = NULL;
    if (pstart == NULL)
    {
        pstart = pnode;
    }else{
        ptr = pstart;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = pnode;
    }
    return pstart;
}
void display(node * pstart){
    node * ptr = pstart;
    while (ptr != NULL)
    {
        printf("%d\n",ptr->number);
        ptr = ptr->next;
    }
    
}
node * insertStart(node * pstart){
    node * pnode = (node*)malloc(sizeof(node));
    if (pnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter Number to insert at start : \n");
    scanf("%d",&pnode->number);
    pnode->next = pstart;
    pstart = pnode;
    
    printf("Data Added :) \n");
    return(pstart);
}
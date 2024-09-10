/*
Q6. Given a linked list of non-negative integers, write a function to swap every two adjacent nodes
and return its head pointer. Note: Do not swap by exchanging the values of the nodes
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;

void display(struct node *head);
struct node* swap(struct node* head);
struct node* create(struct node *head);

int main() {
    struct node *head = NULL;
    int n, i;

    printf("The number of episodes you need to enter in the linked list:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        head = create(head);
    }

    head = swap(head);

    display(head);

    return 0;
}

void display(struct node *head) {
    struct node *ptr = head;
    if (head == NULL) {
        printf("Linked list is empty\n");
    } else {
        while (ptr != NULL) {
            printf("The data of the linked list is: %d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

struct node* swap(struct node* head) {
    if (head == NULL || head->next == NULL) {
        return head;  
    }
    
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *newHead = curr->next;  
    
    while (curr != NULL && curr->next != NULL) {
        struct node *nex = curr->next;
        curr->next = nex->next;
        nex->next = curr;

        if (prev != NULL) {
            prev->next = nex;
        }
        
       
        prev = curr;
        curr = curr->next;
    }
    
    return newHead;  
}

struct node* create(struct node *head) {
    struct node *ptr;
    struct node *pnode = (struct node *)malloc(sizeof(struct node));
    if (pnode == NULL) {
        return NULL;
    }
    
    printf("Enter the serial id of the web series:\n");
    scanf("%d", &pnode->data);
    pnode->next = NULL;

    if (head == NULL) {
        head = pnode;  
    } else {
        ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = pnode;
    }
    return head;
}
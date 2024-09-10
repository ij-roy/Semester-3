/*
Q5. Read a very very long integer as a string (greater than the size of long integer) and then convert
each character digit into a number and then store it in a linked list. Split this linked list into two
sub-lists as follows: The first sub-list consists of the odd integers, and the second sub-list the
even integers of the original list
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int data;
    struct Node*next;
}Node;

void display(Node *head);

int main() {
    char st[2000];
    printf("Enter string : \n");
    scanf("%s", st);

    struct Node *head = NULL, *pp = NULL;
    struct Node *odd = NULL, *oddTail = NULL;
    struct Node *even = NULL, *evenTail = NULL;

    for (int i = 0; st[i] != '\0'; i++) {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p->data = st[i] - '0';  
        p->next = NULL;
        
        if (head == NULL) {
            head = p;
            pp = head;
        } else {
            pp->next = p;
            pp = pp->next;
        }
    }

    struct Node *current = head;
    while (current != NULL) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = current->data;
        newNode->next = NULL;

        if (current->data % 2 == 0) {
            if (even == NULL) {
                even = newNode;
                evenTail = even;
            } else {
                evenTail->next = newNode;
                evenTail = evenTail->next;
            }
        } else {
            if (odd == NULL) {
                odd = newNode;
                oddTail = odd;
            } else {
                oddTail->next = newNode;
                oddTail = oddTail->next;
            }
        }
        current = current->next;
    }

    printf("The list having even data is:\n");
    display(even);

    printf("The list having odd data is:\n");
    display(odd);

    return 0;
}


void display(Node *head) {
    struct Node *ptr = head;
    if (head == NULL) {
        printf("Linked list is empty\n");
    } else {
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
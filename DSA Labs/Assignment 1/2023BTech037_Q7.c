/*
. You are given two sorted linked lists list1 and list2 of non-negative integers. Merge the two
lists into one sorted list. 
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node*next;
}Node;

struct Node* create(struct Node* head);
struct Node* sorted_merge(struct Node* a, struct Node* b);
void linkedlisttraversal(struct Node* ptr);
void free_list(struct Node* head);

int main() {
    struct Node* head1 = NULL;
    int n, i;
    printf("Enter the number of elements for the first linked list:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        head1 = create(head1);
    }

    struct Node* head2 = NULL;
    int n1;
    printf("Enter the number of elements for the second linked list:\n");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        head2 = create(head2);
    }

    struct Node* mergedHead = sorted_merge(head1, head2);
    printf("Merged sorted list:\n");
    linkedlisttraversal(mergedHead);

    return 0;
}

void linkedlisttraversal(struct Node* ptr) {
    if (ptr == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* sorted_merge(struct Node* a, struct Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    struct Node* head = NULL;
    struct Node* tail = NULL;

    if (a->data < b->data) {
        head = tail = a;
        a = a->next;
    } else {
        head = tail = b;
        b = b->next;
    }

    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            tail->next = a;
            tail = a;
            a = a->next;
        } else {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }

    if (a == NULL) {
        tail->next = b;
    } else {
        tail->next = a;
    }

    return head;
}

struct Node* create(struct Node* head) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }
    printf("Enter the data:\n");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    return head;
}

void free_list(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
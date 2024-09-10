/*
Q4. There are several episodes for a web series. The details of each episode are stored as a node
in a linked list. The data of each node contains serial id, episode number, array of customer
numbers. Create a linked list for your favourite web series and add 8 episodes to it. Next,
modify the list from some position, n, such that the episode at position n is the first node of
the linked list. For this, write two functions:
    a. Rotate the list from n, in the clockwise direction
    b. Rotate the list from n, in the anti-clockwise direction
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct EpisodeNode {
    int serial_id;
    int episode_number;
    int num_customers; 
    int *customer_numbers; 
    struct EpisodeNode* next;
} EpisodeNode;

EpisodeNode* createNode(int serial_id, int episode_number, int* customer_numbers, int num_customers);
EpisodeNode* appendNode(EpisodeNode* head, int serial_id, int episode_number, int* customer_numbers, int num_customers);
EpisodeNode* rotateClockwise(EpisodeNode* head, int n);
EpisodeNode* rotateAntiClockwise(EpisodeNode* head, int n);
void printList(EpisodeNode* head);



int main() {
    EpisodeNode* head = NULL;
    int num_episodes = 8;

    // Input episodes from user
    for (int i = 1; i <= num_episodes; i++) {
        int serial_id, episode_number, num_customers;
        int* customer_numbers;

        printf("Enter details for Episode %d:\n", i);
        printf("Serial ID: ");
        scanf("%d", &serial_id);
        printf("Episode Number: ");
        scanf("%d", &episode_number);
        printf("Enter number of customers: ");
        scanf("%d", &num_customers);

        customer_numbers = (int*)malloc(num_customers * sizeof(int));
        printf("Enter %d customer numbers (space separated): ", num_customers);
        for (int j = 0; j < num_customers; j++) {
            scanf("%d", &customer_numbers[j]);
        }

        head = appendNode(head, serial_id, episode_number, customer_numbers, num_customers);
    }

    printf("\nOriginal List:\n");
    printList(head);

    // Take rotation input
    int rotate_pos, choice;
    printf("\nEnter the position from which to rotate the list: ");
    scanf("%d", &rotate_pos);

    printf("Choose rotation direction:\n1. Clockwise\n2. Anti-Clockwise\n");
    scanf("%d", &choice);

    if (choice == 1) {
        head = rotateClockwise(head, rotate_pos);
        printf("\nList after clockwise rotation from position %d:\n", rotate_pos);
        printList(head);
    } else if (choice == 2) {
        head = rotateAntiClockwise(head, rotate_pos);
        printf("\nList after anti-clockwise rotation from position %d:\n", rotate_pos);
        printList(head);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

EpisodeNode* createNode(int serial_id, int episode_number, int* customer_numbers, int num_customers) {
    EpisodeNode* newNode = (EpisodeNode*)malloc(sizeof(EpisodeNode));
    newNode->serial_id = serial_id;
    newNode->episode_number = episode_number;
    newNode->num_customers = num_customers;
    newNode->customer_numbers = customer_numbers;
    newNode->next = NULL;
    return newNode;
}

EpisodeNode* appendNode(EpisodeNode* head, int serial_id, int episode_number, int* customer_numbers, int num_customers) {
    EpisodeNode* newNode = createNode(serial_id, episode_number, customer_numbers, num_customers);
    if (head == NULL) {
        return newNode;
    }
    
    EpisodeNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    
    return head;
}

EpisodeNode* rotateClockwise(EpisodeNode* head, int n) {
    if (head == NULL || n <= 0) return head;

    EpisodeNode* temp = head;
    int count = 1;

    while (count < n && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL) return head; // If n is greater than the number of nodes or n is the last node

    EpisodeNode* nthNode = temp;
    EpisodeNode* newHead = nthNode->next;

    temp = newHead;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head;
    nthNode->next = NULL;

    return newHead;
}

EpisodeNode* rotateAntiClockwise(EpisodeNode* head, int n) {
    if (head == NULL || n <= 0) return head;

    EpisodeNode* temp = head;
    EpisodeNode* prev = NULL;
    int count = 1;

    while (count < n && temp != NULL) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL) return head;

    if (prev == NULL) return head;

    EpisodeNode* newHead = temp;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head;
    prev->next = NULL;

    return newHead;
}

void printList(EpisodeNode* head) {
    while (head != NULL) {
        printf("Serial ID: %d, Episode Number: %d\n", head->serial_id, head->episode_number);
        head = head->next;
    }
}


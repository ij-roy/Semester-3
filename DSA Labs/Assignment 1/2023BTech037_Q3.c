/*
Q3. Assume that there is a sequence of song tracks that has to be played. Create a linked list of
songs where each song is a node with song id and song’s name as the data part of the node.
Write a menu driven program to perform the following operations:
    a. Write a function to insert a new song at the beginning of the list
    b. Write a function to insert a new song at the end of the list
    c. Write a function to insert a new song after the node with song id = x. Take x from the
    user.
    d. Write a function to insert a new song before the node with song id = x. Take x from
    the user.
    e. Write a function to print the entire linked list
    f. Write a function to search for a song in the linked list (assume the list is not sorted).
    The name of the song is to be an input from the user
    g. Write a recursive function to print the entire linked list but in reverse direction
    h. Write a function to count the number of elements of a linked list.
    i. Convert the above function, count, to a recursive function.
    j. Write a function to delete the song with song id = x. Take x from the user.
    k. Write a function to delete the last song of the linked list
    l. Write a function to delete the first song of the linked list
    m. Write a function to delete ALL the nodes of the linked list using the:
        i. Iterative approach
        ii. Recursive approach
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    char name[100];
    struct Node *next;
} Node;

Node* insertAtBeginning(Node *head, int id, const char *name);
Node* insertAtEnd(Node *head, int id, const char *name);
Node* insertAfterNode(Node *head, int x, int new_id, const char *new_name);
Node* insertBeforeNode(Node *head, int x, int new_id, const char *new_name);
void printList(Node *head);
Node* searchSong(Node *head, const char *name);
void printReverse(Node *head);
int countNodes(Node *head);
int countNodesRecursive(Node *head);
Node* deleteSongById(Node *head, int id);
Node* deleteLastSong(Node *head);
Node* deleteFirstSong(Node *head);
Node* deleteAllSongsIterative(Node *head);
Node* deleteAllSongsRecursive(Node *head);

int main() {
    Node *head = NULL;
    int choice, id, new_id, x;
    char name[100];
    Node *found;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a song ID\n");
        printf("4. Insert before a song ID\n");
        printf("5. Print list\n");
        printf("6. Search for a song\n");
        printf("7. Print list in reverse\n");
        printf("8. Count nodes\n");
        printf("9. Count nodes (recursive)\n");
        printf("10. Delete a song by ID\n");
        printf("11. Delete last song\n");
        printf("12. Delete first song\n");
        printf("13. Delete all songs (iterative)\n");
        printf("14. Delete all songs (recursive)\n");
        printf("15. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter song ID: ");
                scanf("%d", &id);
                printf("Enter song name: ");
                scanf(" %[^\n]", name);
                head = insertAtBeginning(head, id, name);
                break;
            case 2:
                printf("Enter song ID: ");
                scanf("%d", &id);
                printf("Enter song name: ");
                scanf(" %[^\n]", name);
                head = insertAtEnd(head, id, name);
                break;
            case 3:
                printf("Enter song ID to insert after: ");
                scanf("%d", &x);
                printf("Enter new song ID: ");
                scanf("%d", &new_id);
                printf("Enter new song name: ");
                scanf(" %[^\n]", name);
                head = insertAfterNode(head, x, new_id, name);
                break;
            case 4:
                printf("Enter song ID to insert before: ");
                scanf("%d", &x);
                printf("Enter new song ID: ");
                scanf("%d", &new_id);
                printf("Enter new song name: ");
                scanf(" %[^\n]", name);
                head = insertBeforeNode(head, x, new_id, name);
                break;
            case 5:
                printList(head);
                break;
            case 6:
                printf("Enter song name to search: ");
                scanf(" %[^\n]", name);
                found = searchSong(head, name);
                if (found) {
                    printf("Song found - ID: %d, Name: %s\n", found->id, found->name);
                } else {
                    printf("Song not found.\n");
                }
                break;
            case 7:
                printReverse(head);
                break;
            case 8:
                printf("Total number of songs: %d\n", countNodes(head));
                break;
            case 9:
                printf("Total number of songs (recursive): %d\n", countNodesRecursive(head));
                break;
            case 10:
                printf("Enter song ID to delete: ");
                scanf("%d", &id);
                head = deleteSongById(head, id);
                break;
            case 11:
                head = deleteLastSong(head);
                break;
            case 12:
                head = deleteFirstSong(head);
                break;
            case 13:
                head = deleteAllSongsIterative(head);
                break;
            case 14:
                head = deleteAllSongsRecursive(head);
                break;
            case 15:
                head = deleteAllSongsIterative(head); 
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

Node* insertAtBeginning(Node *head, int id, const char *name) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->id = id;
    strncpy(new_node->name, name, sizeof(new_node->name));
    new_node->next = head;
    return new_node;
}

Node* insertAtEnd(Node *head, int id, const char *name) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->id = id;
    strncpy(new_node->name, name, sizeof(new_node->name));
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

Node* insertAfterNode(Node *head, int x, int new_id, const char *new_name) {
    Node *temp = head;
    while (temp != NULL && temp->id != x) {
        temp = temp->next;
    }

    if (temp != NULL) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->id = new_id;
        strncpy(new_node->name, new_name, sizeof(new_node->name));
        new_node->next = temp->next;
        temp->next = new_node;
    } else {
        printf("Song with ID %d not found.\n", x);
    }
    return head;
}

Node* insertBeforeNode(Node *head, int x, int new_id, const char *new_name) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->id = new_id;
    strncpy(new_node->name, new_name, sizeof(new_node->name));

    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }

    if (head->id == x) {
        new_node->next = head;
        return new_node;
    }

    Node *prev = NULL, *current = head;
    while (current != NULL && current->id != x) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        prev->next = new_node;
        new_node->next = current;
    } else {
        printf("Song with ID %d not found.\n", x);
    }
    return head;
}

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("ID: %d, Name: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

Node* searchSong(Node *head, const char *name) {
    Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void printReverse(Node *head) {
    if (head == NULL) return;
    printReverse(head->next);
    printf("ID: %d, Name: %s\n", head->id, head->name);
}

int countNodes(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int countNodesRecursive(Node *head) {
    if (head == NULL) return 0;
    return 1 + countNodesRecursive(head->next);
}

Node* deleteSongById(Node *head, int id) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }

    if (head->id == id) {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node *prev = NULL, *current = head;
    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        prev->next = current->next;
        free(current);
    } else {
        printf("Song with ID %d not found.\n", id);
    }
    return head;
}

Node* deleteLastSong(Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

Node* deleteFirstSong(Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* deleteAllSongsIterative(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return NULL;
}

Node* deleteAllSongsRecursive(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    head->next = deleteAllSongsRecursive(head->next);
    free(head);
    return NULL;
}
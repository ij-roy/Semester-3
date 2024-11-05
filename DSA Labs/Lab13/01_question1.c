/*
Write separate functions to perform the following for a binary search tree
1. Insert an element
2. Display the preorder traversal
3. Display the inorder traversal
4. Display the postorder traversal
5. Find the smallest element in the BST
6. Find the largest element in the BST
7. Delete any element in the BST
8. Count the total number of nodes in the BSR
9. Count the total number of external nodes
10.Count the total number of internal nodes
11.Determine the height of the tree
12.Find the mirror image of the tree
Finally, convert your functions into a menu driven program.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
}node;

node * insert(node *, int);
node * preorder(node *);
node * inorder(node *);
node * postorder(node *);
node * findmin(node *);

int main() {
    struct node* root = NULL;
    int choice, data;

    while (1) {
        printf("\nBinary Search Tree Menu\n");
        printf("1. Insert an element\n");
        printf("2. Preorder traversal\n");
        printf("3. Inorder traversal\n");
        printf("4. Postorder traversal\n");
        printf("5. Find the smallest element\n");
        // printf("6. Find the largest element\n");
        // printf("7. Delete an element\n");
        // printf("8. Count total nodes\n");
        // printf("9. Count external nodes\n");
        // printf("10. Count internal nodes\n");
        // printf("11. Determine the height of the tree\n");
        // printf("12. Find the mirror image of the tree\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                if (root) {
                    node* minNode = findmin(root);
                    printf("Smallest element: %d\n", minNode->data);
                } else {
                    printf("Tree is empty\n");
                }
                break;
            case 13:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}


node * insert(node * head , int data){
    node * pnode = (node *) malloc(sizeof(node));
    if (pnode == NULL) {
        printf("Memory allocation failed\n");
        return head; 
    }
    pnode->data = data;
    pnode->left = pnode->right = NULL;
    if (head == NULL)
    {
        return pnode;
    }
    if (data < head->data)
    {
        head->left = insert(head->left, data);
    }else if (data > head->data){
        head->right = insert(head->right, data);
    }
    return head;
}

node * preorder(node *root){
    if (root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

node * inorder(node *root){
    if (root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

node * postorder(node *root){
    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

node * findmin(node * root){
    node * temp = root;
    while (temp != NULL && temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;  
    int exp;    
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

struct Node* addNode(struct Node* poly, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (poly == NULL) {
        return newNode;
    } else {
        struct Node* temp = poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        return poly;
    }
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node *p1 = poly1, *p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            result = addNode(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            result = addNode(result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            result = addNode(result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result = addNode(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = addNode(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

void printPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

struct Node* inputPolynomial() {
    struct Node* poly = NULL;
    int n, coeff, exp;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        poly = addNode(poly, coeff, exp);
    }

    return poly;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;
    
    printf("Input first polynomial:\n");
    poly1 = inputPolynomial();

    printf("Input second polynomial:\n");
    poly2 = inputPolynomial();

    result = addPolynomials(poly1, poly2);

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    printf("Sum: ");
    printPolynomial(result);

    return 0;
}
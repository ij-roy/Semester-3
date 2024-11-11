/*
Question 4. The daily price of stock of a company ABC is given. You have to determine, it’s span. For 
this,  look  at  the  maximum  number  of  consecutive  days  (starting  from  today  and  going 
backwards) for which the price of the ABC’s stock was  less  than or  equal  to  today's price. 
Write  a  program  to  determine  the  span  of  ABC’s  stock.  Find  out  the  complexity  of  your 
program. 
Input: [50] Output: [1] 
Input: [50, 40]  Output: [1, 1] 
Input: [50, 40, 30]  Output: [1, 1, 1] 
Input: [50, 40, 30, 35, 37, 20, 35]  Output: [1, 1, 1, 2, 3, 1, 2]
*/

#include <stdio.h>
#include <stdlib.h>


int *stack;  // Global stack
int top = -1; // Stack pointer

void push(int index) {
    stack[++top] = index; // O(1)
}

int pop() {
    if (top == -1) { // O(1)
        return -1;  
    }
    return stack[top--];
}

int peek() {
    if (top == -1) { // O(1)
        return -1;  
    }
    return stack[top];
}


void calculateSpan(int prices[], int n, int span[]) {
    // Outer loop runs for each stock price - O(n)
    for (int i = 0; i < n; i++) {
         // O(1)
        // each element can be pushed and popped at most once.
        while (top != -1 && prices[peek()] <= prices[i]) {
            pop(); // O(1)
        }

        span[i] = (top == -1) ? i + 1 : i - peek(); // O(1)

        push(i); // O(1)
    }
}

int main() {
    int n;

    printf("Enter the number of stock prices: ");
    scanf("%d", &n);

    int *prices = (int *)malloc(n * sizeof(int));
    int *span = (int *)malloc(n * sizeof(int));
    stack = (int *)malloc(n * sizeof(int));

    printf("Enter the stock prices:\n"); // O(1)
    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]); // O(1)
    }

    calculateSpan(prices, n, span);

    printf("Span of stock prices: [");
    for (int i = 0; i < n; i++) {
        printf("%d", span[i]); // O(1)
        if (i != n - 1) printf(", "); // O(1)
    }
    printf("]\n"); // O(1)

    // Freeing the allocated memory
    free(prices);
    free(span);
    free(stack);

    return 0;
}

// Final Time Complexity: O(n)
// Best Case Time Complexity: O(n) (strictly decreasing prices).
// Worst Case Time Complexity: O(n) (strictly increasing prices).
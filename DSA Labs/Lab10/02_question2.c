/*
Question 2. Write functions to implement a queue like behaviour using a single stack. 
You will have to use recursion for this. 
Recursion will reorder the elements during the dequeue operation. 
Perform the following:
    a. For enqueue: push onto stack. O(1) complexity
    b. For dequeue: create a recursive function that returns an integer. Do the
    following in sequence:
        i. pop the top of the stack and store in a local element, ele
        ii. Write the base condition with of an empty stack and return ele.
        iii. Make the recursive call. Remember, your call returns an integer and so
        store that in another local variable, temp.
        iv. Push onto stack, ele.
        v. Return temp
    How does this program work? Understand it by writing the pseudocode and drawing
    the stack frame of each recursive call on paper first. After you have understood it, code
    the steps mentioned. Run for code by enqueueing 12,22,23,24,25 and one dequeue
    operation.
    c. What is the complexity of your dequeue operation?

*/

#include <stdio.h>
#include "stack.c"  

void enqueue(stack* s, int value) {
    push(s, value);
}

int dequeue(stack* s) {
    if (isEmpty(s)) {
        printf("Queue is empty\n");
        return -1;
    }

    int ele = pop(s);

    if (isEmpty(s)) {
        return ele;
    }

    int temp = dequeue(s);

    push(s, ele);

    return temp;
}

int main() {
    stack s = init();

    enqueue(&s, 12);
    enqueue(&s, 22);
    enqueue(&s, 23);
    enqueue(&s, 24);
    enqueue(&s, 25);

    printf("Dequeued element: %d\n", dequeue(&s)); 

    enqueue(&s, 30);

    printf("Dequeued element: %d\n", dequeue(&s));
    printf("Dequeued element: %d\n", dequeue(&s));

    return 0;
}

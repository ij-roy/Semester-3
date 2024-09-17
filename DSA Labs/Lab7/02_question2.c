/*
Question 2. WAP two stacks sharing a space of single array 
*/

#include <stdio.h>
#include <stdlib.h>

# define MAX 100

typedef struct stack
{
    int arr[MAX];
    int top1;
    int top2;
}stack;

stack init();
int isEmpty(stack *ps);  
int isFull(stack *ps);           
void push(stack *ps, int ele, int ch); 
void pop(stack *ps, int ch);      
int peek(stack *ps, int ch);      
void printStack(stack *ps); 

int main(){
    stack s = init();
    int ch,data,choice,num;
    printf("stack created :)");
    do {
        printf("\nPress\n1 to push in Stack\n2 to pop\n3 to peek\n4 to print the stack\n5 to end\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &ch);
                printf("Enter element to push: ");
                scanf("%d", &data);
                push(&s, data, ch);
                break;
            case 2:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &ch);
                pop(&s, ch);
                break;
            case 3:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &ch);
                num = peek(&s, ch);
                if (num != -1) {
                    printf("Top element of Stack %d is %d\n", ch, num);
                }
                break;
            case 4:
                printStack(&s);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);
    
}

stack init(){
    stack s;
    s.top1 = -1;
    s.top2 = MAX;
    return s;
}

int isEmpty(stack * ps){
    return (ps->top1 == -1 && ps->top2 == MAX);
}

int isFull(stack * ps){
    return (ps->top1 + 1 == ps->top2);
}

void push(stack * ps,int ele,int ch){
    if (isFull(ps))
    {
        printf("Stack is Full");
    }else{
        if (ch==1)
        {
            ps->top1++;
            ps->arr[ps->top1] = ele;
        }else if (ch == 2)
        {
            ps->top2--;
            ps->arr[ps->top2] = ele;
        }   
    }
}

void pop(stack * ps, int ch){
    int num;
    if (isEmpty(ps))
    {
        printf("Stack is Empty");
    }else{
        if (ch == 1)
        {
            if (ps->top1 == -1)
            {
                printf("Cannot pop Stack 1 is Empty");
            }else{
                printf("Popped element is %d",ps->arr[ps->top1]);
                ps->top1--;
            }
            
        }else if(ch == 2){
            if (ps->top2 == MAX)
            {
                printf("Cannot pop Stack 2 is Empty");
            }else{
                printf("Popped element is %d",ps->arr[ps->top2]);
                ps->top2++;
            }   
        }
    }
}

int peek(stack* ps, int ch) {
    if (isEmpty(ps)) {
        printf("Both stacks are Empty\n");
        return -1;
    } else {
        if (ch == 1) {
            if (ps->top1 != -1) {
                return ps->arr[ps->top1];
            } else {
                printf("Stack 1 is Empty\n");
                return -1;
            }
        } else if (ch == 2) {
            if (ps->top2 != MAX) {
                return ps->arr[ps->top2];
            } else {
                printf("Stack 2 is Empty\n");
                return -1;
            }
        }
    }
    return -1;
}

void printStack(stack* ps) {
    printf("Stack 1: ");
    if (ps->top1 == -1) {
        printf("Empty");
    } else {
        for (int i = 0; i <= ps->top1; i++) {
            printf("%d ", ps->arr[i]);
        }
    }

    printf("\nStack 2: ");
    if (ps->top2 == MAX) {
        printf("Empty");
    } else {
        for (int i = MAX - 1; i >= ps->top2; i--) {
            printf("%d ", ps->arr[i]);
        }
    }
    printf("\n");
}
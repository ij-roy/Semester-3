/*
Q3. Write a program to convert any infix expression to a post fix notation 
using a stack.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode
{
    char data;
    struct stackNode * next;
}stackNode;

stackNode * push(stackNode*,char);
stackNode * pop(stackNode*);
char peek(stackNode*);
void printStack(stackNode*);
const char* infixToPostfix(char[]);
int isOperand(char);
int isOperator(char); 
int precedence(char);


int main(){

    stackNode * pstart = NULL;
    char input[500];
    printf("Enter the Infix Expressions : ");
    scanf(" %[^\n]%*c",input);

    const char * postfix = infixToPostfix(input);
    printf("Postfix Expression : %s",postfix);

    return 0;
}

stackNode * push(stackNode* top,char ele){
    stackNode * pnode = (stackNode*)malloc(sizeof(stackNode));
    pnode->data = ele;
    if (top == NULL)
    {
        top = pnode;
        pnode->next = NULL;
    }else{
        pnode->next = top;
        top = pnode;
    }
    return top;
}

stackNode * pop(stackNode * top){
    if (top == NULL)
    {
        printf("Popping will lead to underflow");
        return NULL;
    }else{
        stackNode * temp = top;
        top = top->next;
        free(temp);
    }
    return top;
}

char peek(stackNode* top){
    if (top ==  NULL)
    {
        return '\0';
    }else{
        return top->data;
    }
}

void printStack(stackNode * top){
    stackNode * temp = top;
    if (top == NULL)
    {
        printf("Stack is empty");
    }
    printf("The Current Stack is : \n");
    while (temp != NULL)
    {
        printf("%c\n",temp->data);
        temp = temp->next;
    }
}

const char* infixToPostfix(char input[]){
    static char output[500];
    int j = 0;
    stackNode * top = NULL;

    for (int i = 0; input[i]!= '\0'; i++)
    {
        if (isOperand(input[i]))
        {
            output[j] = input[i];
            j++;
        }
        else if (input[i] == '(')
        {
            top = push(top , input[i]);
        }else if (input[i] == ')')
        {
            while (top != NULL && peek(top) != '(')
            {
                output[j] = peek(top);
                j++;
                top = pop(top);
            }
            top = pop(top);
            
        }else if (isOperator(input[i]))
        {
            if (precedence(input[i]) > precedence(peek(top)))
            {
                top = push(top,input[i]);
            }else if (precedence(input[i]) == precedence(peek(top))) 
            {
                while (top != NULL && precedence(input[i]) <= precedence(peek(top))) {
                    output[j++] = peek(top);
                    top = pop(top);
                }
                top = push(top, input[i]);
            }
            
            // else if (precedence(input[i]) == precedence(peek(top)))
            // {
            //     if (input[i] == '^')
            //     {
            //         top = push(top,input[i]);
            //     }else{
            //         output[j] = peek(top);
            //         top = pop(top);
            //         top = push(top,input[i]);
            //     }
            // }
            
            else
            {
                while (top != NULL && precedence(input[i]) < precedence(peek(top)))
                {
                    output[j] = peek(top);
                    j++;
                    top = pop(top);
                }
                if (top != NULL && precedence(peek(top)) == precedence(input[i]) && input[i] != '^')
                {
                    output[j++] = peek(top);
                    top = pop(top);
                }
                top = push(top, input[i]);
                }   
        }   
    }   
    while (top != NULL)
    {
        output[j] = peek(top);
        j++;
        top = pop(top);
    }
    output[j] = '\0';
    return output;
}

int isOperand(char input){
    if (input >=48 && input<=57)
    {
        return 1;
    }else if (input >=65 && input<=90)
    {
        return 1;
    }else if (input >=97 && input<=122)
    {
        return 1;
    }else{
        return 0;
    }
}

int isOperator(char input){
    if (input == '+' || input == '-' || input == '/' || input == '*' || input == '^')
    {
        return 1;
    }
    return 0;
}

int precedence(char input){
    switch (input)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
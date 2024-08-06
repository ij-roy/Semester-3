/*
3.	Create a structure to represent a book (title, author, price). 
Dynamically allocate memory for an array of books. 
Take the input from the user and store the details in the array. 
Write a function to print the book details.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char title[20];
    char author[20];
    float price;
}book;

void print(book);

int main(){
    int N ;
    printf("Enter number of Books : ");
    scanf("%d",&N);

    book*ptr = (book *)malloc(N*sizeof(book));

    for (int i = 0; i < N; i++)
    {
        printf("For Book %d\n",i+1);
        printf("Enter The Title of the Book : ");
        // scanf("%s",&ptr[i].title);
        scanf(" %[^\n]%*c", ptr[i].title);
        printf("Enter The Author of The Book : ");
        // scanf("%s",&ptr[i].author);
        scanf(" %[^\n]%*c", ptr[i].author);
        printf("Enter The Price of The Book : ");
        scanf("%f",&ptr[i].price);
    }
    printf("Printing The Details\n");
    for (int i = 0; i < N; i++)
    {
        printf("Book%d\n",i+1);
        print(ptr[i]);
    }
    free(ptr);

    return 0;
}
void print(book ptr){
    printf("Title : %s\n",ptr.title);
    printf("Author : %s\n",ptr.author);
    printf("Price : %.1f\n",ptr.price);
}
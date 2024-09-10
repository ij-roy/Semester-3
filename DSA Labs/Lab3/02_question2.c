/*
Question 2. Add a function deleteBook to delete one book from the array of books. 
The book to be deleted should be an input from the user. 
Resize your array. No new array should be created.
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
void deleteBook(int,book *,int);

int main(){
    int N , location;
    book b1;
    printf("Enter number of Books : ");
    scanf("%d",&N);

    book*ptr = (book *)malloc(N*sizeof(book));

    for (int i = 0; i < N; i++)
    {
        printf("For Book %d\n",i+1);
        printf("Enter The Title of the Book : ");
        scanf(" %[^\n]%*c", ptr[i].title);
        printf("Enter The Author of The Book : ");
        scanf(" %[^\n]%*c", ptr[i].author);
        printf("Enter The Price of The Book : ");
        scanf("%f",&ptr[i].price);
    }
    printf("Now Give Details for Deletion\n");
    printf("Enter Index of book to delete : ");
    scanf("%d",&location);
    deleteBook(location,ptr,N);
    
    ptr = (book*)realloc(ptr,sizeof(book)*(N-1));

    printf("Printing The Details\n\n");
    for (int i = 0; i < N-1; i++)
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
    printf("Price : %.1f\n\n",ptr.price);
}

void deleteBook(int location,book *ptr,int N){
    for (int i = location-1; i < N-1; i++)
    {
        ptr[i] = ptr[i+1];
    }
}
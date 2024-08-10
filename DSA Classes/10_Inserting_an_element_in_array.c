/*
Create a book data type . Write a function insertBook to insert one book in an 
existing array . The array should be dynamically created . The position of 
insertion is an input from the user. 
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
void insertBook(int,book,book *,int);

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
        // scanf("%s",&ptr[i].title);
        scanf(" %[^\n]%*c", ptr[i].title);
        printf("Enter The Author of The Book : ");
        // scanf("%s",&ptr[i].author);
        scanf(" %[^\n]%*c", ptr[i].author);
        printf("Enter The Price of The Book : ");
        scanf("%f",&ptr[i].price);
    }
    printf("Now Give Details for Insertion\n");
    printf("Enter Location where to insert : ");
    scanf("%d",&location);
    printf("Enter Title of the Book : ");
    scanf(" %[^\n]%*c", b1.title);
    printf("Enter The Author of The Book : ");
    scanf(" %[^\n]%*c", b1.author);
    printf("Enter The Price of The Book : ");
    scanf("%f",&b1.price);

    ptr = (book*)realloc(ptr,sizeof(book)*(N+1));

    insertBook(location,b1,ptr,N+1);

    printf("\nPrinting The Details\n\n");
    for (int i = 0; i < N+1; i++)
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
void insertBook(int location,book b1,book *ptr,int size){
    for (int i = size; i > location; i--){
        ptr[i-1] = ptr[i-2];
    }
    ptr[location-1] = b1;    
}
// void insertBook(int location, book b1, book *ptr, int size) {
//     for (int i = size - 1; i >= location; i--) {
//         ptr[i] = ptr[i - 1];
//     }
//     ptr[location - 1] = b1;
// }
//Pointer To Structures

#include <stdio.h>

typedef struct {
    char title[20];
    char author[20];
}book;

book*ptr;
book b1;
ptr = &b1;

//Access the title 
// 1. w/o pointer = b1.title
// 2. using the ptr
//     (*ptr).title
//   or ptr->author
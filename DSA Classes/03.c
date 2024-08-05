/*
Create a memory dynamically that stores 200 times the size of int
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *pi = (int*)malloc(sizeof(int)*200);
    free(pi); //free the memory allocated
    return 0;
}
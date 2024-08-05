// Memory Allocation


#include <stdio.h>
int main(){
    // printf("Hello World");
    char * cards = "JQK";
    cards[2] = cards[1];
    puts(cards);   // NO OUTPUT
    return 0;
}
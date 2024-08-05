// Memory Allocation


#include <stdio.h>
int main(){
    char cards[] = "JQK";
    cards[2] = cards[1];
    puts(cards);   // JQQ
    return 0;
}
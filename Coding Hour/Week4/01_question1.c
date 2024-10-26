/*
You are designing a system for a person who goes to the market with a list of items they want to buy. Each item on the list has the following details:

Item Name: A string of maximum 30 characters
Quantity: An integer representing the number of items to buy
Price: An integer representing the price per item
Requirements

Define a structure named ShoppingItem to store the details of an item on the shopping list.
Read the details of n items (where n is entered by the user) and store them in an array of ShoppingItem structures.
Implement a function int calculateTotalPrice(struct ShoppingItem items[], int size) that calculates and returns the total price of all items.
Example Input

2
Apple
4
25
Orange
3
20
Explanation

Apple: Quantity = 4, Price per item = 25. Total = 4 * 25 = 100.
Orange: Quantity = 3, Price per item = 20. Total = 3 * 20 = 60.
Total Price = 100 + 60 = 160.
Input Format

First line: An integer n, the number of items. Next n blocks, each containing:

A line with the item name (a string, up to 30 characters).
A line with an integer quantity, representing the number of items.
A line with a int price, representing the price per item.
Constraints

1<=n<=100
1<=quantity<=1000
1<=price<=1000
Output Format

The total price of all items.
Sample Input 0
2
Apple
4
25
Orange
3
20
Sample Output 0
160
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>




int main() {

    FILE* fptr = fopen("01_testcases.txt","r");

    if(fptr ==NULL){
        printf("Error Opening File.\n");
        return 1;
    }

    int n; 
    fscanf(fptr,"%d", &n);

    int total = 0; 

    for (int i = 0; i < n; ++i) {
        char Name[100]; 
        int quantity;
        int price;

        fscanf(fptr,"%s", Name);      
        fscanf(fptr,"%d", &quantity);     
        fscanf(fptr,"%d", &price); 

        total += quantity * price;
    }

    printf("%d\n", total);

    return 0;
}
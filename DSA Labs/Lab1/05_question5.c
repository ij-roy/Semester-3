/*
Question 5.	Create a structure to represent a product (name, price, quantity). 
    Read product details from a file into an array of structures. 
    Write the updated product details back to the file.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char name[20];
    float price;
    int quantity;
}product;


int main(){
    FILE * productpointer = fopen("05_products.txt","r");
    if (productpointer == NULL)
    {
        printf("Could not Open File for reading");
        return 1;
    }
    int productcount;
    fscanf(productpointer,"%d",&productcount);
    product * Product = (product*)malloc(productcount*sizeof(product));
    for (int i = 0; i < productcount; i++)
    {
        fscanf(productpointer," %[^\n]%*c",Product[i].name);
        fscanf(productpointer,"%f",&Product[i].price);
        fscanf(productpointer,"%d",&Product[i].quantity);
    }
    fclose(productpointer);
    printf("Producs read from File : \n");
    for (int i = 0; i < productcount; i++)
    {
        printf("Product %d : \n",i+1);
        printf("Name : %s\n",Product[i].name);
        printf("Price : %.2f\n",Product[i].price);
        printf("Quantity : %d\n",Product[i].quantity);
    }
    
    float inflationPercent;
    printf("\nEnter Inflation Percentage : ");
    scanf("%f",&inflationPercent);
    printf("\n");
    
    for (int i = 0; i < productcount; i++)
    {
        Product[i].price = Product[i].price * (1+inflationPercent/100);
    }
    productpointer = fopen("05_products.txt","w");
    if (productpointer == NULL)
    {
        printf("Could not Open File for writing.\n");
        free(Product);
        return 1;
    }
    fprintf(productpointer,"%d\n",productcount);
    
    for (int i = 0; i < productcount; i++)
    {
        fprintf(productpointer,"%s\n",Product[i].name);
        fprintf(productpointer,"%.2f\n",Product[i].price);
        fprintf(productpointer,"%d\n",Product[i].quantity);
    }
    fclose(productpointer);
    printf("Producs typed in File : \n");
    for (int i = 0; i < productcount; i++)
    {
        printf("Product %d : \n",i+1);
        printf("Name : %s\n",Product[i].name);
        printf("Price : %.2f\n",Product[i].price);
        printf("Quantity : %d\n",Product[i].quantity);
    }
    free(Product);

    return 0;
}
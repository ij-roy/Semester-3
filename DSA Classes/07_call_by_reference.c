/*
Question. For the Struct Program on complex numbers. 
Subtract complex numbers and store the result in a third complex number . 
Use call by reference 
*/

#include <stdio.h>

typedef struct {
    float real;
    float imaginary;
}complex;

void subtract(complex*,complex*,complex*);
void print(complex);

int main(){
    complex a,b,result;

    printf("Enter the 1st Complex number/n");
    printf("Enter the value of a and b in a+bi : ");
    scanf("%f %f",&a.real,&a.imaginary);
    printf("Enter the 2nd Complex number/n");
    printf("Enter the value of a and b in a+bi : ");
    scanf("%f %f",&b.real,&b.imaginary);

    subtract(&a,&b,&result);
    printf("\nThe Subtraction is : ");
    print(result);

    return 0;
}

//Call by reference
void subtract(complex *a,complex*b,complex*result){
    result->real = (a->real) - (b->real);
    (*result).imaginary = (*a).imaginary - (*b).imaginary;
}

void print(complex c ){
    printf("%.1f+%.1fi",c.real,c.imaginary);
}
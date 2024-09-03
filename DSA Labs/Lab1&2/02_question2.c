/*
2.	Create a structure to represent a complex number. Write functions for adding, 
    subtracting, and multiplying complex numbers 
a.	Adding by using call by value
b.	Subtracting and Multiplying by using call by reference
*/

//I also did Division
#include <stdio.h>

// Struct of Complex Number
typedef struct {
    float real;
    float imaginary;
}complex;

complex add(complex,complex);
complex multiply(complex ,complex );
void subtract(complex*,complex*,complex*);
void divide(complex *,complex *,complex *);
void print(complex);

int main(){
    complex a,b,result;

    printf("Enter the 1st Complex number/n");
    printf("Enter the value of a and b in a+bi : ");
    scanf("%f %f",&a.real,&a.imaginary);
    printf("Enter the 2nd Complex number/n");
    printf("Enter the value of a and b in a+bi : ");
    scanf("%f %f",&b.real,&b.imaginary);

    result = add(a,b);
    printf("The Sum is : ");
    print(result);

    result = multiply(a,b);
    printf("\nThe Multiplication is : ");
    print(result);

    subtract(&a,&b,&result);
    printf("\nThe Subtraction is : ");
    print(result);

    divide(&a,&b,&result);
    printf("\nThe Division is : ");
    print(result);

    return 0;
}

//Call by value
complex add(complex a,complex b){
    complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;

    return result;
}
complex multiply(complex a,complex b){
    complex result;
    result.real = (b.real*a.real) - (b.imaginary*a.imaginary);
    result.imaginary = (b.imaginary*a.real) + (b.real*a.imaginary);

    return result;
}

//Call by reference
void subtract(complex *a,complex*b,complex*result){
    result->real = (a->real) - (b->real);
    (*result).imaginary = (*a).imaginary - (*b).imaginary;
}
void divide(complex *a,complex *b,complex *result){
    result->real = ((a->real * b->real)+(a->imaginary * b->imaginary))/(b->real * b->real)+(b->imaginary * b->imaginary);
    result->imaginary = ((a->imaginary * b->real)-(a->real * b->imaginary))/(b->real * b->real)+(b->imaginary * b->imaginary);
}


void print(complex c ){
    printf("%.1f+%.1fi",c.real,c.imaginary);
}
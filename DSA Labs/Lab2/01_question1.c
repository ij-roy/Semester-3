/*
Create a structure for a complex number and create a two complex numbers a and b .
Write a function to add them and store the result in a third complex number 

Caution: Making the add function print the result is bad programming 
            Write a print function to print the result.
*/

#include <stdio.h>

typedef struct {
    float real;
    float imaginary;
}complex;

complex add(complex,complex);
void print(complex);

int main(){
    complex a,b,c;

    printf("Enter the 1st Complex number/n");
    printf("Enter the value of a and b in a+bi : ");
    scanf("%f %f",&a.real,&a.imaginary);
    printf("Enter the 2nd Complex number/n");
    printf("Enter the value of a and b in a+bi : ");
    scanf("%f %f",&b.real,&b.imaginary);

    c = add(a,b);
    printf("The Sum is : ");
    print(c);

    return 0;
}
complex add(complex a,complex b){
    complex c;
    c.real = a.real + b.real;
    c.imaginary = a.imaginary + b.imaginary;

    return c;
}
void print(complex c ){
    printf("%.1f+%.1fi",c.real,c.imaginary);
}
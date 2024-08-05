/*
Calculate the average height of N patients . 
Use dynamic memory allocation to store the height of patient.

Remember to free your heap!
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
    int N;
    float sum = 0,avg;
    float *ph;

    printf("Enter number of students : ");
    scanf("%d",&N);

    if (ph == NULL)
    {
        printf("Memory Allocation Failed");
        return 1;
    }
    

    ph = (float*)malloc(sizeof(float)*N);
    for (int i = 0;i<N;i++){
        printf("Enter Height of student %d : ",i+1);
        scanf("%f",&ph[i]);
        sum += ph[i];
    };
    free(ph);
    avg = sum/(float)N ;
    printf("The Average Height is: %.2f",avg);
    return 0;
}

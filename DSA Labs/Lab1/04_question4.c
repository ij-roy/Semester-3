/*
Question 4. Write a program to perform the following:
        1. Create an array of 5 student structures, each containing name, 
            roll number, and marks.
        2. Write functions to return the student with the highest marks by
            1. call by value
            2. Call by reference.
        Write another function to print the student with the highest marks. 
        Note: No global variables should be used.
        3.  Modify the above program so that you read the data of students from file 
            and write the output also to a file. Add a function search in the above 
            program that displays the details of student if the roll number of the 
            student is given.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char name[20];
    int rollnumber;
    float marks;
}student;

void printstruct(student);
student HighestMarks(student*);
void HighestMarksReference(student *,student *);

int main(){
    // student arr[5] or
    student*ptr = (student*)malloc(5*sizeof(student));
    student withHighestMarks ;
    for (int i = 0; i < 5; i++)
    {   printf("For Student %d\n",i+1);
        printf("Enter Name : ");
        scanf(" %[^\n]%*c",ptr[i].name);
        printf("Enter Roll Number : ");
        scanf("%d",&ptr[i].rollnumber);
        printf("Enter Marks : ");
        scanf("%f",&ptr[i].marks);
    }
    //using call by value
    withHighestMarks = HighestMarks(ptr);
    printf("Student With Highest Marks is !!\n");
    printstruct(withHighestMarks);

    //using call by reference
    HighestMarksReference(ptr,&withHighestMarks);
    printf("Student With Highest Marks is !!\n");
    printstruct(withHighestMarks);

    return 0;
}

//Assuming only 1 topper
student HighestMarks(student ptr[]){
    student topper = ptr[0];
    for (int i = 0; i < 5; i++)
    {
        if (ptr[i].marks > topper.marks)
        {
            topper = ptr[i];
        }
        
    }
    return topper;
}

void HighestMarksReference(student *ptr,student *topper){
    for (int i = 0; i < 5; i++)
    {
        *topper = ptr[0];
        if (ptr[i].marks > topper->marks)
        {
            *topper = ptr[i];
        }
        
    }
}

void printstruct(student topper){
    printf("Name : %s\n",topper.name);
    printf("Roll Number : %d\n",topper.rollnumber);
    printf("Marks : %.1f\n",topper.marks);
}


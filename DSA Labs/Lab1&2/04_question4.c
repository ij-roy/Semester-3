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
#include <string.h>

typedef struct 
{
    char name[20];
    int rollnumber;
    float marks;
}student;

void printstruct(student);
student HighestMarks(student*);
void HighestMarksReference(student *,student *);
student SearchStudent(student *, int);

int main(){
    // student arr[5] or
    student*ptr = (student*)malloc(5*sizeof(student));
    student withHighestMarks ;
    student studentDetails;
    int rollnumberToSearch ;

    FILE *inputflie = fopen("04_inputfile.txt","r");
    FILE *outputfile = fopen("04_outputfile.txt","w");

    if (inputflie == NULL || outputfile == NULL)
    {
        printf("Error Opening File\n");
    }

    //Reading Data from file
    for (int i = 0; i < 5; i++)
    {
        fscanf(inputflie," %[^\n]%*c",ptr[i].name);
        fscanf(inputflie,"%d",&ptr[i].rollnumber);
        fscanf(inputflie,"%f",&ptr[i].marks);
    }

    //Using Call by Value
    withHighestMarks = HighestMarks(ptr);
    fprintf(outputfile,"Student With Highest Marks (Call by Value) is !!\n");
    fprintf(outputfile,"Name: %s\nRoll Number: %d\nMarks: %.1f\n\n",withHighestMarks.name, withHighestMarks.rollnumber, withHighestMarks.marks);
    
    //Using Call by Reference 
    HighestMarksReference(ptr,&withHighestMarks);
    fprintf(outputfile,"Student With Highest Marks (Call by Reference) is !!\n");
    fprintf(outputfile,"Name: %s\nRoll Number: %d\nMarks: %.1f\n\n",withHighestMarks.name, withHighestMarks.rollnumber, withHighestMarks.marks);

    printf("Enter roll number to search : ");
    scanf("%d",&rollnumberToSearch);

    studentDetails = SearchStudent(ptr,rollnumberToSearch);

    //Handling not found case
    if (strlen(studentDetails.name) != 0)
    {
        printf("Details of that Student : \n");
        printstruct(studentDetails);
    }else{
        printf("Student with roll number %d not found.\n", rollnumberToSearch);
    }

    
    // printf("Details of that Student : \n");
    // printstruct(studentDetails);

    /*

    Till Second part to print

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
    printf("Student With Highest Marks (Call by Value) is !!\n");
    printstruct(withHighestMarks);

    //using call by reference
    HighestMarksReference(ptr,&withHighestMarks);
    printf("Student With Highest Marks (Call by Reference) is !!\n");
    printstruct(withHighestMarks);

    */

    fclose(inputflie);
    fclose(outputfile);
    free(ptr);

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
    *topper = ptr[0];
    for (int i = 0; i < 5; i++){
        if (ptr[i].marks > topper->marks){
            *topper = ptr[i];
        }
        
    }
}

void printstruct(student topper){
    printf("Name : %s\n",topper.name);
    printf("Roll Number : %d\n",topper.rollnumber);
    printf("Marks : %.1f\n",topper.marks);
}

student SearchStudent(student *ptr , int rollnumberToSearch){
    student studentDetails;
    strcpy(studentDetails.name, "");  // Initialize with empty string
    for (int i = 0; i < 5; i++)
    {
        if (ptr[i].rollnumber == rollnumberToSearch)
        {
            studentDetails = ptr[i];
            break;
        }
        
    }
    return studentDetails;
}
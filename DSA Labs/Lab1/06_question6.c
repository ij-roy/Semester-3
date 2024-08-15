/*
Question 6.	Dynamic allocate memory for a one-dimensional array that stores your 
input string. Write a program which implements all the given string functions
    a.	Finding length of a string
    b.	Converting characters of string into upper case
    c.	Concatenating two strings to form a new string
    d.	Appending strings
    e.	Comparing strings
    f.	Reversing a string
    g.	Extracting a substring from the left of a string
    h.	Extracting a string from the right of a string
    i.	Extracting a substring from the middle of a string
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int stringLength(char *);
char * stringToUpper(char *);
char * stringConcat(char *,char *);
void appendString(char*,char*);
int stringCompare(char*,char*);
void stringReverse(char*);
char * substringLeft(char*,int);
char * substringRight( char*,int);
char * substringMiddle(char *,int,int);


int main(){
    char * str1 = (char*)malloc(100*sizeof(char));
    char * str2 = (char*)malloc(100*sizeof(char));

    printf("Enter the 1st String : ");
    fgets(str1,100,stdin);
    str1[strcspn(str1,"\n")] = '\0'; //Remove newline character
    printf("Enter the 2nd String : ");
    fgets(str2,100,stdin);
    str2[strcspn(str2,"\n")] = '\0';

    // A part
    printf("Length of 1st String : %d\n",stringLength(str1));

    // B part
    char * upperString = stringToUpper(str1);
    printf("UpperCase 1st String : %s\n",upperString);

    // C part
    char * concatenated = stringConcat(str1,str2);
    printf("Concatinating two strings to form a new string : %s\n",concatenated);

    // D part 
    appendString(str1,str2);
    printf("Appending String 1 in String 2 : %s \n",str2);

    // E part 
    int compare = stringCompare(str1,str2);
    printf("Comparing Both Strings : ");
    if (compare == 0)
    {
        printf("Strings are equal\n");
    }else{
        printf("Strings are not equal\n");
    }
    
    // F part
    stringReverse(str1);
    printf("Reversing 1st String : %s\n",str1);
    stringReverse(str1);

    // G part
    int n ;
    printf("Enter lenght of Substring : ");
    scanf("%d",&n);
    char * substring = substringLeft(str1,n);
    printf("Substring of 1st %d Characters : %s\n",n,substring);

    // F part
    substring = substringRight(str1,n);
    printf("Substring from last %d Characters : %s\n",n,substring);

    // G part
    int start;
    printf("From Which index you want to start : ");
    scanf("%d",&start);
    substring = substringMiddle(str1,start,n);
    printf("Substring from index %d : %s\n",start,substring);



    return 0;
}

int stringLength(char * str){
    int lenght = 0;
    while (str[lenght] != '\0')
    {
        lenght++;
    }
    return lenght;

}
char * stringToUpper(char * str){
    int len = stringLength(str);
    char * string = (char*)malloc(len*sizeof(char));
    int i = 0;
    while (str[i] != '\0')
    {
        string[i] = toupper(str[i]);
        i++;
    }
    string[i] = '\0';
    return string;
}
char * stringConcat(char * str1,char * str2){
    int len1 = stringLength(str1);
    int len2 = stringLength(str2);
    char * result = (char*)malloc((len1+len2+1)*sizeof(char));
    strcpy(result,str1);
    strcat(result,str2);
    return result ;
}
void appendString(char*str1,char*str2){
    strcat(str2,str1);
}
int stringCompare(char *str1,char*str2){
    return strcmp(str1,str2);
}
void stringReverse(char * str1){
    int len = stringLength(str1);
    for (int i = 0; i < (len/2); i++)
    {
        char temp = str1[i];
        str1[i] = str1[len-i-1];
        str1[len-i-1] = temp;
    }
}
char * substringLeft(char * str1,int n){
    char * subString = (char*)malloc((n+1)*sizeof(char));
    strncpy(subString,str1,n);
    subString[n] = '\0';
    return subString ;
}
char * substringRight( char * str1,int n){
    char * subString = (char*)malloc((n+1)*sizeof(char));
    int len = stringLength(str1);
    strncpy(subString,&str1[len-n],n);
    subString[n] = '\0';
    return subString;
}
char * substringMiddle(char * str1,int start,int n){
    char * subString = (char*)malloc((n+1)*sizeof(char));
    strncpy(subString,&str1[start],n);
    subString[n] = '\0';
    return subString;
}
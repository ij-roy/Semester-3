#include <stdio.h>
#include <stdlib.h>

void mergeSort(int [],int);
void divide(int [],int,int);
void conquer(int [],int,int,int);

int main(){
    int n;
    int arr[100];
    printf("Enter number of elements : ");
    scanf("%d",&n);
    printf("Enter %d numbers : ",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,n);
    printf("Printing the data : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}

void mergeSort(int arr[],int n){
    divide(arr,0,n-1);
}

void divide(int arr[],int si,int ei){
    if (si>=ei)
        return;
    
    int mid = (si+ei)/2;
    divide(arr,si,mid);
    divide(arr,mid+1,ei);
    conquer(arr,si,mid,ei);
}

void conquer(int arr[],int si,int mid,int ei){
    int x = 0 ;//Counter;
    int*newarr = (int*)malloc((ei-si+1)*sizeof(int));
    int indx1 = si;
    int indx2 = mid+1;
    while (indx1<=mid && indx2<=ei)
    {
        if (arr[indx1]<=arr[indx2])
        {
            newarr[x++] = arr[indx1++];
        }
        else{
            newarr[x++] = arr[indx2++];
        }
    }
    while (indx1<=mid)
    {
        newarr[x++] = arr[indx1++];
    }
    while (indx2<=ei){
        newarr[x++] = arr[indx2++];
    }
    for (int i = 0,j=si; i < x; i++,j++)
    {
        arr[j] = newarr[i];
    }
    
}
// Merge Sort

#include <stdio.h>

void mergeSort(int arr[],int);
void conquer(int arr[],int,int,int);
void divide(int arr[],int,int);

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
    // base case
    if (si >= ei)
    {
        return;
    }
    int mid = si + (ei - si)/2 ;
    divide(arr,si,mid);
    divide(arr,mid+1,ei);
    conquer(arr,si,mid,ei);
    
}

void conquer(int arr[],int si,int mid ,int ei){
    int* merged = (int*)malloc((ei - si + 1) * sizeof(int));
    int idx1 = si;  
    int idx2 = mid + 1; 
    int x = 0;  
    while (idx1 <= mid && idx2 <= ei) {
        if (arr[idx1] <= arr[idx2]) {
            merged[x++] = arr[idx1++];
        } else {
            merged[x++] = arr[idx2++];
        }
    }
    while (idx1 <= mid) {
        merged[x++] = arr[idx1++];
    }
    while (idx2 <= ei) {
        merged[x++] = arr[idx2++];
    }
    for (int i = 0, j = si; i < x; i++, j++) {
        arr[j] = merged[i];
    }
}
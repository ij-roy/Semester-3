#include <stdio.h>
void insertionSort(int [],int);

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
    insertionSort(arr,n);
    printf("Printing the data : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}

void insertionSort(int arr[],int n){
    for(int i = 1; i < n; i++){
        int current = i;
        int previous  = i-1;
        while (previous>=0 && arr[previous]>current){
            arr[previous+1] = arr[previous];
            previous--;
        }
        arr[previous+1] = current;
    }
}
// Quick Sort

#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main(){
    int n;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    printf("Enter %d numbers : ",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    quickSort(arr,0,n-1);
    printf("Printing the data : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    free(arr);
}

void quickSort(int arr[],int low,int high){
    if (low < high)
    {
        int pidx = partition(arr,low,high);
        quickSort(arr,low,pidx-1);
        quickSort(arr,pidx+1,high);
    }
}

int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low-1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            //swap
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = pivot;
    arr[high] = temp;
    return i;
}
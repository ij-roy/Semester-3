#include <stdio.h>
void selectionSort(int [],int);

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
    selectionSort(arr,n);
    printf("Printing the data : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}

void selectionSort(int arr[],int n){
    for (int i = 0; i < n-1; i++)
    {
        int smallest = i;
        for (int j = i+1; j <n;j++){
            if (arr[j] < arr[smallest])
            {
                smallest = j;
            }
        }
        if (smallest!=i)
        {
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = arr[i];
        }
    }
}
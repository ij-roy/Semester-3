#include <stdio.h>
void bubbleSort(int [],int);

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
    bubbleSort(arr,n);
    printf("Printing the data : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}

void bubbleSort(int arr[],int n){
    for (int i = 0; i < n-1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if (flag)
        break;
    } 
}
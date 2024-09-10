/*
Q2. You are given two sorted arrays arr1 and arr2 of integers. Merge the two arrays into one sorted
    array. Handle all the test cases.
*/

#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int size);
int isSorted(int *array, int size);
void bubbleSort(int *array, int size);
void mergeArrays(int *arr1, int size1, int *arr2, int size2, int *mergedArray);
void inputArray(int **array, int *size);

int main() {
    int size1, size2;
    int *arr1 = NULL, *arr2 = NULL;
    char choice;

    while (1) {
        printf("Input for the first array:\n");
        inputArray(&arr1, &size1);
        
        if (!isSorted(arr1, size1)) {
            printf("The first array is not sorted. Do you want me to sort it for you? (y/n): ");
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y') {
                bubbleSort(arr1, size1);
            } else {
                printf("Please re-enter the first array in sorted order.\n");
                continue; 
            }
        }

        printf("Input for the second array:\n");
        inputArray(&arr2, &size2);

        if (!isSorted(arr2, size2)) {
            printf("The second array is not sorted. Do you want me to sort it for you? (y/n): ");
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y') {
                bubbleSort(arr2, size2);
            } else {
                printf("Please re-enter the second array in sorted order.\n");
                continue; 
            }
        }

        int *mergedArray = (int *)malloc((size1 + size2) * sizeof(int));
        if (mergedArray == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            free(arr1);
            free(arr2);
            return 1;
        }

        mergeArrays(arr1, size1, arr2, size2, mergedArray);

        printf("Merged array:\n");
        printArray(mergedArray, size1 + size2);

        free(arr1);
        free(arr2);
        free(mergedArray);

        printf("Do you want to merge another pair of arrays? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break; 
        }
    }

    return 0;
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int isSorted(int *array, int size) {
    for (int i = 1; i < size; i++) {
        if (array[i] < array[i - 1]) {
            return 0; 
        }
    }
    return 1;
}

void mergeArrays(int *arr1, int size1, int *arr2, int size2, int *mergedArray) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            mergedArray[k++] = arr1[i++];
        } else {
            mergedArray[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        mergedArray[k++] = arr1[i++];
    }

    while (j < size2) {
        mergedArray[k++] = arr2[j++];
    }
}

void bubbleSort(int *array, int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void inputArray(int **array, int *size) {
    free(*array); // Free previously allocated memory if any

    printf("Enter the number of elements in the array: ");
    scanf("%d", size);
    *array = (int *)malloc(*size * sizeof(int));
    if (*array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < *size; i++) {
        scanf("%d", &(*array)[i]);
    }
}
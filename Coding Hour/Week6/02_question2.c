/*
Given a sorted array of distinct integers (0 based indexed) and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an Binary Search algorithm with O(log n) runtime complexity.

Input Format

First line contains an integer N aka arr_count denoting the size of the array.
Second line contains target element need to be serach.
Third line contains N size array arr.
Constraints

1 <= nums.length <= 10000
-10000 <= nums[i] <= 10000
nums contains distinct values sorted in ascending order.
-10000 <= target <= 10000
Output Format

You do not need to print anything; simply return the index position of the target element.
Sample Input 0
4
5
1 3 5 6
Sample Output 0
2
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * Complete the 'searchInsert' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER target
 */

int searchInsert(int arr_count, int* arr, int target) {
    int low = 0, high = arr_count - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            return mid;  // Target found, return its index
        }
        
        if (arr[mid] < target) {
            low = mid + 1;  // Target is greater, search the right half
        } else {
            high = mid - 1;  // Target is smaller, search the left half
        }
    }
    
    // If not found, return the index where the target should be inserted
    return low;
}

int main() {
    FILE* fptr = fopen("02_testcases.txt","r");

    if(fptr ==NULL){
        printf("Error Opening File.\n");
        return 1;
    }

    int arr_count, target;
    fscanf(fptr, "%d", &arr_count);  
    fscanf(fptr, "%d", &target);    

    int* arr = (int*)malloc(arr_count * sizeof(int));
    for (int i = 0; i < arr_count; i++) {
        fscanf(fptr, "%d", &arr[i]);  
    }

    fclose(fptr);

    int result = searchInsert(arr_count, arr, target);
    printf("%d\n", result);

    return 0; 

}
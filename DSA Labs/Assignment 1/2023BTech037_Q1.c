/*
Q1. Temperature data is stored as a struct. The elements are city, date and array of temperature
readings taken over the day. Dynamically create an array of temperature data. Write a menu
driven program to perform the following operations:
    a. Write a function to insert a new element at any user given position of the array. Test
    your program by inserting an element
        i. At the beginning of the array
        ii. At the end of the array
        iii. after the second element
        iv. before the third element
    b. Write a function to search for a user given city in the array
    c. Write a function to print the entire array.
    d. Write a function to print the entire array but in reverse direction
    e. Write a function to delete an element from any position in the array. There should be
    no empty slot in the array. Resize your array using dynamic memory allocation. Test
    your program by deleting from
        i. the beginning of the list
        ii. the end of the list
        iii. after the second element
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char city[50];
    char date[11];
    float *temperatures;
    int readingsCount;
} Temperature;

void insertElement(Temperature *data, int *size, int position, Temperature newElement);
void deleteElement(Temperature *data, int *size, int position);
void searchCity(Temperature *data, int size, char city[]);
void printArray(Temperature *data, int size);
void printArrayReverse(Temperature *data, int size);
Temperature inputNewElement();
void freeMemory(Temperature *data, int size);

int main() {
    int size = 0;                // Initial size of the array
    int capacity = 10;           // Initial capacity for dynamic array
    Temperature *data = (Temperature *) malloc(capacity * sizeof(Temperature)); // Dynamic memory allocation for the array
    int choice, position;
    char city[50];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert new element\n");
        printf("2. Delete an element\n");
        printf("3. Search for a city\n");
        printf("4. Print all elements\n");
        printf("5. Print all elements in reverse order\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert a new element
                if (size == capacity) {
                    capacity *= 2; // Double the capacity if full
                    data = (Temperature *) realloc(data, capacity * sizeof(Temperature));
                }
                printf("Enter position to insert (0 to %d): ", size);
                scanf("%d", &position);
                insertElement(data, &size, position, inputNewElement());
                break;

            case 2:
                // Delete an element
                printf("Enter position to delete (0 to %d): ", size - 1);
                scanf("%d", &position);
                deleteElement(data, &size, position);
                break;

            case 3:
                // Search for a city
                printf("Enter city to search: ");
                scanf("%s", city);
                searchCity(data, size, city);
                break;

            case 4:
                // Print all elements
                printArray(data, size);
                break;

            case 5:
                // Print all elements in reverse order
                printArrayReverse(data, size);
                break;

            case 6:
                // Exit the program
                freeMemory(data, size); // Free allocated memory before exiting
                free(data);
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

Temperature inputNewElement() {
    Temperature newElement;

    printf("Enter city name: ");
    scanf("%s", newElement.city);

    printf("Enter date (DD/MM/YYYY): ");
    scanf("%s", newElement.date);

    printf("How many temperature readings do you want to provide? ");
    scanf("%d", &newElement.readingsCount);

    newElement.temperatures = (float *)malloc(newElement.readingsCount * sizeof(float));

    for (int i = 0; i < newElement.readingsCount; i++) {
        printf("Temperature at reading %d: ", i + 1);
        scanf("%f", &newElement.temperatures[i]);
    }

    return newElement;
}

void insertElement(Temperature *data, int *size, int position, Temperature newElement) {
    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = *size; i > position; i--) {
        data[i] = data[i - 1]; 
    }

    data[position] = newElement;

    (*size)++;
}

void deleteElement(Temperature *data, int *size, int position) {

    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return;
    }

    free(data[position].temperatures);

    for (int i = position; i < *size - 1; i++) {
        data[i] = data[i + 1];
    }

    (*size)--;
}

void searchCity(Temperature *data, int size, char city[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(data[i].city, city) == 0) {
            printf("City Found \n");
            printf("City: %s, \nDate: %s, \nTemperatures: \n", data[i].city, data[i].date);
            for (int j = 0; j < data[i].readingsCount; j++) {
                printf("\t%.1f \n", data[i].temperatures[j]);
            }
            printf("\n");
            return;
        }
    }
    printf("City not found!\n");
}

void printArray(Temperature *data, int size) {
    printf("Printing all elements : \n");
    for (int i = 0; i < size; i++) {
        printf("City: %s, \nDate: %s, \nTemperatures: \n", data[i].city, data[i].date);
        for (int j = 0; j < data[i].readingsCount; j++) {
            printf("\t%.1f \n", data[i].temperatures[j]);
        }
        printf("\n");
    }
}

void printArrayReverse(Temperature *data, int size) {
    printf("Printing all elements (Reversed) : \n");
    for (int i = size - 1; i >= 0; i--) {
        printf("City: %s, \nDate: %s, \nTemperatures: \n", data[i].city, data[i].date);
        for (int j = 0; j < data[i].readingsCount; j++) {
            printf("\t%.1f \n", data[i].temperatures[j]);
        }
        printf("\n");
    }
}

void freeMemory(Temperature *data, int size) {
    for (int i = 0; i < size; i++) {
        free(data[i].temperatures);
    }
}

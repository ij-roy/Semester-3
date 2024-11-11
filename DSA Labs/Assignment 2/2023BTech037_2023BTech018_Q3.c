/*
Question 3.  112321
    a) You have to maintain a separate list of employees for every department. Use linked 
    lists for this. The employees may be connected to each other in any order. 
    Create an array of departments such that each department points to the correct list of 
    employees. 
    b) Write a menu driven program to  
        a. retrieve all the employees of a user given department. 
        b. Retrieve a specific employee detail 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define MAX_EMPLOYEES 100

typedef struct Employee {
    int employeeID;
    char employeeName[NAME_LENGTH];
    struct Employee *next;
} Employee;

typedef struct Department {
    char departmentName[NAME_LENGTH];
    Employee *employeeList;
} Department;

// Global list to store employee names by ID
typedef struct {
    int employeeID;
    char employeeName[NAME_LENGTH];
} EmployeeDatabase;

EmployeeDatabase employeeDatabase[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee(Department departments[], int departmentCount);
void displayEmployees(Department departments[], int departmentIndex);
void retrieveEmployee(Department departments[], int departmentCount);
const char* findEmployeeName(int employeeID);

int main(){
    int departmentCount; // number of department

    printf("Enter the number of departments: ");
    scanf("%d", &departmentCount);

    Department *departments = (Department *)malloc(departmentCount * sizeof(Department));
    if (departments == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the names of the departments:\n");
    for (int i = 0; i < departmentCount; i++) {
        printf("Department %d: ", i + 1);
        scanf(" %[^\n]s", departments[i].departmentName); 
        departments[i].employeeList = NULL;
    }

    int choice;
    do
    {
        printf("\nMenu:\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees in a Department\n");
        printf("3. Retrieve Specific Employee Details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addEmployee(departments, departmentCount);
            break;
        case 2:
            displayEmployees(departments, departmentCount);
            break;
        case 3:
        retrieveEmployee(departments, departmentCount);
        break;
        case 4:
            choice = 37;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice!=37);
    

    // Freeing Memory Allocation
    for (int i = 0; i < departmentCount; i++) {
        Employee *current = departments[i].employeeList;
        while (current != NULL) {
            Employee *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(departments);

    return 0;
}

void addEmployee(Department departments[], int departmentCount){
    int departmentIndex,employeeID;

    printf("Select department:\n");
    for (int i = 0; i < departmentCount; i++) {
        printf("%d: %s\n", i + 1, departments[i].departmentName);
    }

    printf("Enter department number: ");
    scanf("%d", &departmentIndex);
    departmentIndex--; //for 0-based indexing

    if (departmentIndex < 0 || departmentIndex >= departmentCount) {
        printf("Invalid department selection.\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &employeeID);

    // Checking if employee ID exists in the selected department
    Employee *current = departments[departmentIndex].employeeList;
    while (current != NULL) {
        if (current->employeeID == employeeID) {
            printf("Error: Employee ID %d already exists in %s department.\n", employeeID, departments[departmentIndex].departmentName);
            return;
        }
        current = current->next;
    }

    // Checking if the employee is already in the global database
    const char *employeeName = findEmployeeName(employeeID);
    if (employeeName == NULL) {
        // If not found, adding new entry in global database
        if (employeeCount >= MAX_EMPLOYEES) {
            printf("Employee database is full.\n");
            return;
        }
        printf("Enter Employee Name: ");
        scanf(" %[^\n]s", employeeDatabase[employeeCount].employeeName);
        employeeDatabase[employeeCount].employeeID = employeeID;
        employeeName = employeeDatabase[employeeCount].employeeName;
        employeeCount++;
    }else {
        printf("Employee already exists in the system with ID %d and Name %s.\n", employeeID, employeeName);
    }

    // Allocating memory for the new employee in the department
    Employee *newEmployee = (Employee *)malloc(sizeof(Employee));
    if (newEmployee == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newEmployee->employeeID = employeeID;
    strcpy(newEmployee->employeeName, employeeName);
    newEmployee->next = departments[departmentIndex].employeeList;
    departments[departmentIndex].employeeList = newEmployee;

    printf("Employee added successfully to %s department.\n", departments[departmentIndex].departmentName);
}

// Function to find an employee name by ID in the global database
const char* findEmployeeName(int employeeID) {
    for (int i = 0; i < employeeCount; i++) {
        if (employeeDatabase[i].employeeID == employeeID) {
            return employeeDatabase[i].employeeName;
        }
    }
    return NULL;
}

void displayEmployees(Department departments[], int departmentCount) {
    
    int departmentIndex;
    printf("Select department to display employees:\n");
    for (int i = 0; i < departmentCount; i++) {
        printf("%d: %s\n", i + 1, departments[i].departmentName);
    }
    printf("Enter department number: ");
    scanf("%d", &departmentIndex);
    departmentIndex--; // 0-based indexing

    if (departmentIndex < 0 || departmentIndex >= departmentCount) {
        printf("Invalid department selection.\n");
        return;
    }

    Employee *current = departments[departmentIndex].employeeList;

    if (current == NULL) {
        printf("No employees found in %s department.\n", departments[departmentIndex].departmentName);
        return;
    }

    printf("Employees in %s department:\n", departments[departmentIndex].departmentName);
    while (current != NULL) {
        printf("ID: %d, Name: %s\n", current->employeeID, current->employeeName);
        current = current->next;
    }
}

void retrieveEmployee(Department departments[], int departmentCount) {
    int searchChoice, employeeID;
    char employeeName[NAME_LENGTH];
    int found = 0;

    printf("Retrieve Employee by:\n");
    printf("1. Employee ID\n");
    printf("2. Employee Name\n");
    printf("Enter your choice: ");
    scanf("%d", &searchChoice);

    switch (searchChoice) {
        case 1: {
            printf("Enter Employee ID: ");
            scanf("%d", &employeeID);

            for (int i = 0; i < departmentCount; i++) {
                Employee *current = departments[i].employeeList;
                while (current != NULL) {
                    if (current->employeeID == employeeID) {
                        if (!found) {
                            printf("Employee Details:\n");
                            printf("ID: %d, Name: %s\n", current->employeeID, current->employeeName);
                            printf("Departments: ");
                        }
                        printf("%s ", departments[i].departmentName);
                        found = 1;
                        break;
                    }
                    current = current->next;
                }
            }
            if (found) {
                printf("\n");
            } else {
                printf("Employee with ID %d not found in any department.\n", employeeID);
            }
            break;
        }

        case 2: {
            printf("Enter Employee Name: ");
            scanf(" %[^\n]s", employeeName);

            for (int i = 0; i < departmentCount; i++) {
                Employee *current = departments[i].employeeList;
                while (current != NULL) {
                    if (strcmp(current->employeeName, employeeName) == 0) {
                        if (!found) {
                            printf("Employee Details:\n");
                            printf("ID: %d, Name: %s\n", current->employeeID, current->employeeName);
                            printf("Departments: ");
                        }
                        printf("%s ", departments[i].departmentName);
                        found = 1;
                        break;
                    }
                    current = current->next;
                }
            }
            if (found) {
                printf("\n");
            } else {
                printf("Employee with name %s not found in any department.\n", employeeName);
            }
            break;
        }

        default:
            printf("Invalid choice.\n");
            break;
    }
}

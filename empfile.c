/**
 * @file employee_sorter.c
 * @brief A program to read employee data from a file, sort it by age, and write it to another file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 1000
#define MAX_AGE 100

/**
 * @brief A struct to represent an employee.
 */
typedef struct Employee {
    char name[50]; /**< Employee name */
    int age; /**< Employee age */
} Employee;

/**
 * @brief Partitions the array of employees based on the pivot element.
 * 
 * @param arr The array of employees to be partitioned.
 * @param low The lower bound of the partition range.
 * @param high The upper bound of the partition range.
 * @return The index of the pivot element in the partitioned array.
 */
int partition(Employee arr[], int low, int high) {
    Employee pivot = arr[high];
    int i = low - 1, j;
    Employee temp;
    for (j = low; j <= high - 1; j++) {
        if (arr[j].age <= pivot.age) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

/**
 * @brief Recursively sorts the array of employees using the quicksort algorithm.
 * 
 * @param arr The array of employees to be sorted.
 * @param low The lower bound of the sort range.
 * @param high The upper bound of the sort range.
 */
void quickSort(Employee arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/**
 * @brief The main function to read employee data from a file, sort it, and write it to another file.
 * 
 * @return 0 on success, 1 on failure.
 */
int main() {
    FILE *fp, *fp2;
    char filename[] = "employee.txt";
    char filename2[] = "sortedemponage.txt";
    char line[100];
    Employee employees[MAX_EMPLOYEES];
    int i = 0, j, n;

    /* Open the input file */
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file %s", filename);
        return 1;
    }

    /* Read employee data from the file */
    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%[^,],%d", employees[i].name, &employees[i].age);
        i++;
    }
    n = i;
    fclose(fp);

    /* Write the unsorted data to the output file */
    fp2 = fopen(filename2, "w");
    for (i = 0; i < n; i++) {
        fprintf(fp2, "%s,%d\n", employees[i].name, employees[i].age);
    }
    fclose(fp2);

    /* Sort the employee data by age */
    quickSort(employees, 0, n - 1);

    /* Write the sorted data to the output file */
    fp2 = fopen(filename2, "w");
    for (i = 0; i < n; i++) {
        fprintf(fp2, "%s,%d\n", employees[i].name, employees[i].age);
    }
    fclose(fp2);

    printf("Data sorted and written to file %s successfully.\n", filename2);
    return 0;
}

/**
 * @example
 * Suppose we have a file `employee.txt` containing the following data:
 * ```
 * John,25
 * Alice,30
 * Bob,20
 * Charlie,35
 * ```
 * Running this program will sort the data by age and write it to `sortedemponage.txt`:
 * ```
 * Bob,20
 * John,25
 * Alice,30
 * Charlie,35
 * ```
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct employee {
  char name[50];
  int age;
} employee;

void counting_sort(employee *employees, int n) {
  // Find the maximum age
  int max_age = 0;
  for (int i = 0; i < n; i++) {
    if (employees[i].age > max_age) {
      max_age = employees[i].age;
    }
  }

  // Create a count array to store the frequency of each age
  int count[max_age + 1];
  for (int i = 0; i <= max_age; i++) {
    count[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    count[employees[i].age]++;
  }

  // Calculate the cumulative count
  for (int i = 1; i <= max_age; i++) {
    count[i] += count[i - 1];
  }

  // Create a sorted array
  employee *sorted_employees = malloc(sizeof(employee) * n);
  for (int i = 0; i < n; i++) {
    sorted_employees[count[employees[i].age] - 1] = employees[i];
    count[employees[i].age]--;
  }

  // Copy the sorted array to the original array
  for (int i = 0; i < n; i++) {
    employees[i] = sorted_employees[i];
  }

  free(sorted_employees);
}

void quick_sort(employee *employees, int low, int high) {
  if (low < high) {
    // Choose a pivot element
    int pivot = employees[low].age;

    // Partition the array around the pivot element
    int i = low - 1;
    int j = high + 1;
    while (i < j) {
      while (employees[++i].age < pivot);
      while (employees[--j].age > pivot);

      if (i < j) {
        employee temp = employees[i];
        employees[i] = employees[j];
        employees[j] = temp;
      }
    }

    // Recursively sort the two subarrays
    quick_sort(employees, low, i - 1);
    quick_sort(employees, i, high);
  }
}

int main() {
  // Open the employee.txt file
  FILE *employee_file = fopen("employee.txt", "r");
  if (employee_file == NULL) {
    printf("Error opening employee.txt file.\n");
    return 1;
  }

  // Read the employee data from the file
  int n;
  fscanf(employee_file, "%d\n", &n);
  employee *employees = malloc(sizeof(employee) * n);
  for (int i = 0; i < n; i++) {
    fscanf(employee_file, "%s,%d", employees[i].name, &employees[i].age);
  }

  // Close the employee.txt file
  fclose(employee_file);

  // Sort the employee data using counting sort
  counting_sort(employees, n);

  // Sort the employee data using quick sort
  quick_sort(employees, 0, n - 1);

  // Open the sortedemponage.txt file
  FILE *sorted_employee_file = fopen("sortedemponage.txt", "w");
  if (sorted_employee_file == NULL) {
    printf("Error opening sortedemponage.txt file.\n");
    return 1;
  }
}

  // Write the sorted employee data to the file
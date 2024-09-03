// Include the standard input/output library
#include <stdio.h>

// Define a function to merge two sorted subarrays
void merge(int arr[], int left, int mid, int right) {
  // Declare variables to store the sizes of the subarrays
  int n1 = mid - left + 1;
  int n2 = right - mid;
  // Declare temporary arrays to store the subarrays
  int L[n1], R[n2];
  // Copy the elements from the original array to the temporary arrays
  for (int i = 0; i < n1; i++) {
    L[i] = arr[left + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = arr[mid + 1 + j];
  }
  // Declare variables to track the indices of the subarrays and the merged array
  int i = 0, j = 0, k = left;
  // Merge the subarrays by comparing the elements and copying the smaller one to the merged array
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  // Copy the remaining elements of the subarrays to the merged array if any
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

// Define a function to sort an array using merge sort
void mergeSort(int arr[], int left, int right) {
  // Check if the left index is smaller than the right index
  if (left < right) {
    // Find the middle index of the array
    int mid = left + (right - left) / 2;
    // Recursively sort the left and right subarrays
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    // Merge the sorted subarrays
    merge(arr, left, mid, right);
  }
}

// Define a function to print an array
void printArray(int arr[], int size) {
  // Loop through the array elements
  for (int i = 0; i < size; i++) {
    // Print each element
    printf("%d ", arr[i]);
  }
  // Print a new line
  printf("\n");
}

// Define the main function
int main() {
  // Declare an array of numbers
  int arr[] = {12, 11, 13, 5, 6, 7};
  // Get the size of the array
  int size = sizeof(arr) / sizeof(arr[0]);
  // Print the original array
  printf("Original array: \n");
  printArray(arr, size);
  // Sort the array using merge sort
  mergeSort(arr, 0, size - 1);
  // Print the sorted array
  printf("Sorted array: \n");
  printArray(arr, size);
  // Return 0 as a successful exit code
  return 0;
}

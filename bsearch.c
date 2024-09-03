// Include necessary header files for input/output operations
#include<stdio.h>
#include<conio.h>

// Define the main function where program execution begins
void main()
{
    // Declare variables
    int a[100];  // Array to store elements
    int ele;     // Element to be searched
    int i;       // Loop counter
    int n;       // Number of elements
    int pos = -1;  // Position of the element, initialized to -1 (not found)

    // Function prototype for binary search
    int bsearch(int a[], int start, int end, int ele);

    // Prompt user to enter the number of elements
    printf("Enter the number of elements\n");
    scanf("%d", &n);

    // Prompt user to enter the elements
    printf("Enter the elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Prompt user to enter the element to be searched
    printf("Enter the element to find: ");
    scanf("%d", &ele);

    // Call the binary search function
    pos = bsearch(a, 0, n - 1, ele);

    // Check if the element is found
    if (pos == -1)
        printf("Element not found");
    else
        printf("Element found at %d index", pos);

    // Wait for a key press before exiting
    getch();
}

// Define the binary search function
int bsearch(int a[], int start, int end, int ele)
{
    // **IMPORTANT**: Binary search requires the array to be sorted
    // This implementation assumes the array is already sorted

    // Continue searching while the start index is less than or equal to the end index
    while (start <= end)
    {
        // Calculate the middle index
        int mid = (start + end) / 2;

        // Check if the middle element is the one we're looking for
        if (a[mid] == ele)
            return mid;

        // If the middle element is less than the target element, move the start index to mid + 1
        if (a[mid] < ele)
            start = mid + 1;
        else
            // If the middle element is greater than the target element, move the end index to mid - 1
            end = mid - 1;
    }

    // If the element is not found, return -1
    return -1;
}
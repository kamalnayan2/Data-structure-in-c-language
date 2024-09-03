/**
 * @brief Sorts an array of integers using the Counting Sort algorithm.
 * 
 * This function sorts an array of integers in ascending order using the Counting Sort algorithm.
 * The algorithm works by creating a temporary array to store the count of each element in the input array,
 * then iterating through the temporary array to construct the sorted output array.
 * 
 * @param a The input array to be sorted.
 * @param n The number of elements in the input array.
 * @param max The maximum value in the input array.
 */
void countsort(int a[], int n, int max)
{
    int *temp = (int *)malloc((max + 1) * (sizeof(int)));
    int i, j;
    for (i = 0; i <= max; i++)
    {
        temp[i] = 0;
    }
    for (i = 0; i < n; i++)
        temp[a[i]] = temp[a[i]] + 1;
    i = 0;
    j = 0;
    while (i <= max)
    {
        if (temp[i] > 0)
        {
            a[j] = i;
            temp[i] = temp[i] - 1;
            j++;
        }
        else
            i++;
    }
    printf("Count sort is..\n");
    for (i = 0; i < n; i++)
        printf("%d", a[i]);
}

/**
 * @brief Main function to demonstrate the Counting Sort algorithm.
 * 
 * This function prompts the user to input the number of elements and the elements themselves,
 * then calls the countsort function to sort the array and prints the sorted result.
 * 
 * @example
 * Enter the number of elements: 5
 * Enter the elements: 4 2 7 1 3
 * Max is 7
 * Original array: 4 2 7 1 3
 * Count sort is..
 * 1 2 3 4 7
 */
void main()
{
    int a[20], n, i, max = 0;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    printf("Max is %d\n", max);
    for (i = 0; i < n; i++)
        printf("%d", a[i]);
    countsort(a, n, max);

    getch();
}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>      // For INT MIN

void countSort(int array[], int size)
{
    // int max = 0;
    int max = INT_MIN;     // Since array may have a smaller value than 0 so int min gives the smallest int value possible.
    int j = 0;             // For index of given array in last loop

    for (int i = 0; i < size; i++)          // Time  = n
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    int *count = calloc(max + 1, sizeof(int)); // Used calloc to initiate

    for (int i = 0; i < size; i++)            // Time  = n
    {
        count[array[i]]++; // Increment count value according to index
    }

    for (int i = 0; i < max + 1; i++)        // Time = max+1 = n + c (where c is any integer)
    {
        while (count[i] > 0)
        {
            array[j] = i;

            count[i]--;
            j++;
        }
    }
}

void display(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
}

int main()
{
    int arr[] = {5, 3, 7, 3, 1, 9};
    // int arr[] = {5, 4, 23, 6, 7, 58, 4, 52, 35, 5375, 688, 6324, 53425, 1};       // IS input ke liye bahut 
    int size = 6;

    printf("List before sort: ");
    display(arr, size);

    countSort(arr, size);

    printf("\nSorted List : ");
    display(arr, size);

    return 0;
}
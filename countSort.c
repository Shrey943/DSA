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

    for (int i = 0; i < max + 1; i++)        // Time = max+1 = n + c (where c is max element{range of array})
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
    int arr[] = {5, 3, 7, 3, 1, 2, 1, 1, 3, 5, 1, 1,1, 0, 9}; // GREAT!! I mean best for small range or repeated values!
    // int arr[] = {5, 4, 23, 6, 7, 58, 4, 52, 35, 5375, 688, 6324, 53425, 1}; // Bhai saab, iss input ke liye isko 53,425 memory blocks lag jaate 
    int size = 15;

    printf("List before sort: ");
    display(arr, size);

    countSort(arr, size);

    printf("\nSorted List : ");
    display(arr, size);

    return 0;
}
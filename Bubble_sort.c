#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int *arr, int length);

int main()
{
    int arr[10] = {5, 34, 62, 43, 1, 34, 68, 90, 2, 3};
    // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 

    BubbleSort(arr, 10); // Its already a pointer to int at first position hence & is not needed

    printf("\nSorted array : ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    return 0;
}

void BubbleSort(int *arr, int length)
{
    // int length = (sizeof(arr) / sizeof(int)) + 1; //length of array - since its just a pointer hence will give size of pointer
    // printf("\nLength : %d\n", length);

    int alreadySorted = 0;
    int temp;

    for (int i = length - 1; i > 0; i--) // Since we just want n-1 times and also to represent index length-1. This loop is representing pass
    {                                    // Loop is backward so we can use i as the length for checking pass as it decreases with each pass
        int isSorted = 1;                  // Loop to check each item
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                isSorted = 0;
            }
        }
        // printf("Loop run for %d\n", i);
        if (isSorted) // Making bubble sort adaptive. Now as soon as its sorted, it stops (if already sorted then only run 1 time making O(n))
        {
            break;
        }
    }
}
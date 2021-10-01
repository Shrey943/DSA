#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *, int);
void display(int *, int);

int main()
{
    int arr[] = {5, 4, 23, 6, 7, 58, 4, 52, 35, 5375, 688, 6324, 53425, 1};

    printf("List before sort: ");
    display(arr, 14);

    selectionSort(arr, 14);

    printf("\nSorted List : ");
    display(arr, 14);
    return 0;
}

void selectionSort(int *arr, int size)
{

    int bestMin; // Its the index of best minimum
    int temp;

    for (int i = 0; i < size - 1; i++)
    {
        bestMin = i;
        temp = arr[i];

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[bestMin])
            {
                bestMin = j;
            }
        }

        arr[i] = arr[bestMin];
        arr[bestMin] = temp;
    }
}

void display(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
}
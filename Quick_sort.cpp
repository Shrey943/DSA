#include <stdio.h>

void display(int *, int);

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    } while (i < j);

    arr[low] = arr[j];
    arr[j] = pivot;

    return j;
}

void quickSort(int *arr, int low, int high)
{

    int pivotIndex;
    if (low < high)
    {

        pivotIndex = partition(arr, low, high);
        partition(arr, low, pivotIndex - 1);
        partition(arr, pivotIndex + 1, high);
    }
}

int main()
{

    // int arr[] = {5, 3, 7, 3, 1, 9};
    int arr[] = {5, 4, 23, 6, 7, 58, 4, 52, 35, 5375, 688, 6324, 53425, 1};
    int size = 14;

    printf("List before sort: ");
    display(arr, size);

    quickSort(arr, 0, size - 1);

    printf("\nSorted List : ");
    display(arr, size);

    return 0;
}

void display(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
}
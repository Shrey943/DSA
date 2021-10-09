#include <stdio.h>
#include <stdlib.h>

void display(int *, int);
void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int high);

int main()
{
    int arr[] = {5, 3, 7, 3, 1, 9};
    // int arr[] = {5, 4, 23, 6, 7, 58, 4, 52, 35, 5375, 688, 6324, 53425, 1};
    int size = 6;

    printf("List before sort: ");
    display(arr, size);

    mergeSort(arr, 0, size - 1);

    printf("\nSorted List : ");
    display(arr, size);

    return 0;
}

void mergeSort(int arr[], int low, int high)
{

    if (low < high)
    {

        int mid = (high + low) / 2; // To get the mid value even when low is greater than 0
        mergeSort(arr, low, mid);   // Divide
        mergeSort(arr, mid + 1, high);
        merge(arr, low, high); // when above both will return, then array on left of mid(including mid) and array on right of mid would be sorted
    }
}

void merge(int arr[], int low, int high)
{

    int tempArr[(high - low) + 1];
    int mid = (high + low) / 2;
    int i = low, j = mid + 1;

    // while (i < mid + 1 || j < high + 1) {
    for (int k = 0; k < (high - low) + 1; k++)
    {

        if (i <= mid && j <= high)
        {
            if (arr[i] <= arr[j])
            {

                tempArr[k] = arr[i];
                i++;
            }
            else
            {

                tempArr[k] = arr[j];
                j++;
            }
        }
        else
        {
            if (i > mid)
            {
                tempArr[k] = arr[j];
                j++;
            }
            else
            {
                tempArr[k] = arr[i];
                i++;
            }
        }
    }

    j = 0;
    for (int i = low; i <= high; i++)
    {
        arr[i] = tempArr[j];
        j++;
    }
}

void display(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
}
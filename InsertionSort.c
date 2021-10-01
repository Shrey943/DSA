#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int size);
void display(int *, int);

int main()
{
    int arr[] = {5, 4, 23, 6, 7, 58, 4, 52, 35, 5375, 688, 6324, 53425, 1};

    printf("List before sort: ");
    display(arr, 14);

    insertionSort(arr, 14);
    
    printf("\nSorted List : ");
    display(arr, 14);
    
    return 0;
}

void insertionSort(int *arr, int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++) // pass, which are n-1 hence size -1
    {
        for (int j = i; j >= 0; j--)   // decreasing value of i till smaller number is found or list reached -1
        {
            if (arr[j] > arr[j + 1])   // Compairing j +1 which is i at starting every time till a number smaller or equal than it is reached
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
            else
            {
                break;
            }
        }
    }
}

void display(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
}
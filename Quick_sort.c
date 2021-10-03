#include <stdio.h>

void display(int *, int);
void swap(int *, int *);

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do // Used do while so it also works when its only a 2 element array, then i and j are same, hence to check if they are sorted or not
    {
        while (arr[i] <= pivot && i <= j) // Will only look for greater element && Used i,j condition so it does not look for element once
        {                                 // Crossed j
            i++;
        }
        while (arr[j] > pivot) // Will look for smaller and equal element also // It do not need i,j condition as it will automatically
        {                      // stop at pivot if any other element not found
            j--;
        }

        if (i < j) // So they do not swap when i had crossed j
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    } while (i < j);

    /* Above, looking at 2 loops, you may think that array is transversed 2 times but, actually it is only transversed 1 time, if i needs to 
       move all the way to end to get bigger element then, j will find smaller element at second last position only.*/

    arr[low] = arr[j];
    arr[j] = pivot;

    return j;
}

int partitionFromLast(int *arr, int low, int high) // Pivot as last element
{
    int pivot = arr[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // swap(&pivot, &arr[i + 1]); // WRONG : This will pass the address of variable instead of address of arr[high]

    swap(&arr[high], &arr[i + 1]);

    return i + 1;
}

void quickSort(int *arr, int low, int high)
{

    int partitionIndex; // final index of pivot(its correct position)
    if (low < high)
    {

        // partitionIndex = partition(arr, low, high);         // Pivot as first element
        partitionIndex = partitionFromLast(arr, low, high);    // Pivot as last element
        quickSort(arr, low, partitionIndex - 1); // Ye toda 2 hisso mai
        quickSort(arr, partitionIndex + 1, high);
    }
}

// void quickSortUsingIteration(int *arr, int low, int high)
// {
//     while (low < high){

//     }
// } 

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

void swap(int *a, int *b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}
#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int resMemory;
    int usedMemory;
    int *ptr;
};

void createArray(struct myArray *array, int resMemory, int usedMemory);
void setArray(struct myArray *array);
void display(struct myArray *array);
void append(struct myArray *array, int element);
void insert(struct myArray *array, int element, int index);
void delete (struct myArray *array, int index);
int linearSearch(struct myArray *array, int n);
int binarySearch(struct myArray *array, int n);

int main()
{
    struct myArray array1;
    createArray(&array1, 20, 15);
    setArray(&array1);
    display(&array1);
    // append(&array1, 9999);
    // display(&array1);
    // insert(&array1, 100001, 2);
    // display(&array1);
    // delete (&array1, 3);
    // display(&array1);
    int n;
    printf("\nEnter element to be searched: ");
    scanf("%d", &n);

    int a = linearSearch(&array1, n);
    if (a == -1)
    {
        printf("\nElement not found");
    }else{
        printf("\nElement found at index %d\n", a);
    }
    int b = linearSearch(&array1, n);
    if (b == -1)
    {
        printf("\nElement not found");
    }
    else
    {
        printf("\nElement found at index %d\n", b);
    }
  
    return 0;
}

void createArray(struct myArray *array, int resMemory, int usedMemory)
{

    array->resMemory = resMemory;
    array->usedMemory = usedMemory;
    array->ptr = (int *)malloc(sizeof(int) * resMemory);
};

void setArray(struct myArray *array)
{

    printf("\nEnter elements :-");
    for (int i = 0; i < array->usedMemory; i++)
    {
        printf("\nEnter element for position %d: ", i + 1);
        scanf("%d", &array->ptr[i]);
    }
    printf("\n\nElements saved successfully");
}

void display(struct myArray *array)
{ //Its known as transversing.

    printf("\n\nElements in array are :- ");
    for (int i = 0; i < array->usedMemory; i++)
    {
        printf("\nElement at position %d is: %d", i + 1, array->ptr[i]);
    }
}

void append(struct myArray *array, int n)
{

    if (array->usedMemory < array->resMemory)
    {
        array->ptr[array->usedMemory] = n;
        array->usedMemory++;
        printf("\n\nArray appended.");
    }
    else
    {
        printf("\n\nArray Full.");
    }
}

void insert(struct myArray *array, int element, int index)
{
    if (array->usedMemory < array->resMemory)
    {
        // int temp, new;
        // new = element;
        // for (int i = index; i < array->usedMemory + 1; i++)
        // {
        //     temp = array->ptr[i];
        //     array->ptr[i] = new;
        //     new = temp;
        // }
        // array->usedMemory++;

        for (int i = array->usedMemory - 1; i >= index; i--)
        {
            array->ptr[i + 1] = array->ptr[i];
        }
        array->ptr[index] = element;
        array->usedMemory++;

        printf("\n\nInserted %d at positon %d", element, index + 1);
    }
    else
    {
        printf("\n\nArray full");
    }
}

void delete (struct myArray *array, int index)
{
    for (int i = index; i < array->usedMemory - 1; i++)
    {
        array->ptr[i] = array->ptr[i + 1];
    }
    array->usedMemory--;
    printf("\n\nElement deleted successfully.");
}

int linearSearch (struct myArray *array, int n)
{
    printf("\n\nLinear Searching...");
    for (int i = 0; i < array->usedMemory; i++)
    {
       if (array->ptr[i] == n){
           return i;
       }
    }
    return -1;
}

int binarySearch(struct myArray *array,int n){

    printf("Binary Searching...");
    int low = 0, high = array->usedMemory -1, mid;

    while (low<=high){
        if (array->ptr[low] == n){

            return low;
        }else if (array->ptr[high] == n){

            return high;
        }else if (array->ptr[mid] == n){

            return mid;
        }else{

            if (array->ptr[mid] < n){

                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }
    return -1;
}
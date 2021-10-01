#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int resMemory;   //Reserved Memory
    int usedMemory;
    int *ptr;
};

void createArray(struct myArray *array, int resMemory, int usedMemory);
void setArray(struct myArray *array);
void display(struct myArray *array);
void append(struct myArray *array, int element);
void insert(struct myArray *array, int element, int index);
void delete (struct myArray *array, int index);

int main()
{
    struct myArray array1;
    int appendInt, insertInt, deleteInt, insertIndex;

    createArray(&array1, 10, 5);

    setArray(&array1);
    display(&array1);

    printf("\n\nEnter element to be appended: ");
    scanf("%d", &appendInt);
    append(&array1, appendInt);
    display(&array1);

    printf("\n\nEnter element to be inserted and its index: ");
    scanf("%d%d", &insertInt, &insertIndex);
    insert(&array1, insertInt, insertIndex);
    display(&array1);

    printf("\n\nEnter index of element to be Deleted: ");
    scanf("%d", &deleteInt);
    delete (&array1, deleteInt);
    display(&array1);

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

    printf("Enter elements :-");
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
        printf("\nArray appended.");
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

        printf("\nInserted %d at positon %d", element, index + 1);
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
    printf("\nElement deleted successfully.");
}

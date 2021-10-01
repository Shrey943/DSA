#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *nextNode;
};

struct Node *push(struct Node *top, int data);
// int pop(struct Node **top);
int pop(struct Node *node);
int peek(struct Node *top, int positions);
void transverse(struct Node *top);
int stackTop(struct Node *top);
int stackBottom(struct Node *top);
int isEmpty(struct Node *top);
int isFull(struct Node *top);

struct Node *top = NULL; // Declaring globally so we can change its value from functions(also after it we need not to return
                         // anything from push also)

int main()
{
    // struct Node *top = NULL;

    printf("Stack isEmpty : %d \t isFull : %d\n\n", isEmpty(top), isFull(top));

    top = push(top, 123);
    top = push(top, 234);
    top = push(top, 345);
    top = push(top, 456);
    top = push(top, 555);

    printf("\nStack isEmpty : %d \t isFull : %d\n\n", isEmpty(top), isFull(top));

    transverse(top);

    // top = pop(top);
    // top = pop(top);

    printf("\nPoped out element is %d\n", pop(top));
    printf("\nPoped out element is %d\n", pop(top));

    transverse(top);

    printf("\nElement at position 1 is %d\n", peek(top, 1));

    printf("\ntransverse using peek :-\n");
    int i = 1;
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("Element at position %d is %d\n", i, peek(top, i));
        temp = temp->nextNode;
        i++;
    }
    transverse(top);
    printf("\nStackTop : %d \t StackBottom : %d\n", stackTop(top), stackBottom(top));
    return 0;
}

struct Node *push(struct Node *top, int data)
{

    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    if (new == NULL)
    {
        printf("\nStack Overflow : No memory left.\n");
        return top;
    }
    else
    {
        new->data = data;
        new->nextNode = top;
        return new;
    }
}

// int pop(struct Node **top)    // To update the value of top in main function we need to call by reference
// {

//     if (*top == NULL)
//     {
//         printf("\nStack Underflow : stack is empty.\n");
//         return -1;
//     }
//     else
//     {
//         struct Node *temp = *top;
//         int poped_data = (*top)->data;
//         *top = (*top)->nextNode;
//         free(temp);
//         return poped_data;
//     }
// }

int pop(struct Node *node) // To update the value of top in main function we need to call by reference(pointer of pointer)
{                          // But We can declare top globally and then we can change its value from anywhere.
    if (node == NULL)      // Also, since top is already a global variable, therefore we can't have a local variable with name
    {                      // top(well we can have but then we cant change the global one)
        printf("\nStack Underflow : stack is empty.\n");
        return -1;
    }
    else
    {
        int poped_data = node->data;
        top = node->nextNode; //Since we had declared top globally, we can change
        free(node);
        return poped_data;
    }
}

int peek(struct Node *top, int position)
{
    struct Node *temp = top;
    int i = 1;
    // for (int i = 1; i < position && temp != NULL; i++)
    // {
    //     temp = temp->nextNode;
    // }
    while (temp != NULL && i < position)
    {
        temp = temp->nextNode;
        i++;
    }
    if (temp == NULL)
    {
        printf("Position Not Valid.\n");
        return -1;
    }
    return temp->data;
}

int isEmpty(struct Node *top)
{

    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Node *top)
{

    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    if (new == NULL)
    {
        return 1;
    }
    return 0;
}

int stackTop(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack Empty!");
        return -1;
    }
    return top->data;
}

int stackBottom(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack Empty!");
        return -1;
    }
    struct Node *temp = top;
    while (temp->nextNode != NULL)
    {
        temp = temp->nextNode;
    }
    return temp->data;
}

void transverse(struct Node *top)
{
    printf("\n");
    while (top != NULL)
    {
        printf("Element : %d\n", top->data);
        top = top->nextNode;
    }
}

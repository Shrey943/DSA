#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h> // Important needed library to use bool but better not use here

struct Stack
{
    int size; // Size of stack
    int top;  // Index of stack top
    int *ptr; // pointer to array
};

void createStack(struct Stack *stack, int size);
void push(struct Stack *stack, int data);
int pop(struct Stack *stack); // Return is important
int peek(struct Stack *stack, int position);
void transverse(struct Stack *stack);
int isEmpty(struct Stack *stack);
int isFull(struct Stack *stack);
int stackTop(struct Stack *stack);
int stackBottom(struct Stack *stack);

int main()
{

    struct Stack stack;
    createStack(&stack, 7);

    push(&stack, 1);
    push(&stack, 12);
    push(&stack, 434);
    push(&stack, 356);
    push(&stack, 234);
    push(&stack, 3342);

    // transverse(&stack);

    push(&stack, 2342);
    push(&stack, 23242);

    printf("\nPoped element is : %d\n", pop(&stack));
    // printf("\nPoped element is : %d\n", pop(&stack));

    printf("\n");
    for (int i = 1; i <= stack.top + 1; i++) // Better way to transverse stack
    {
        printf("Element at position %d is : %d\n", i, peek(&stack, i)); // ITS THE WAY TO PRINT STACK
    }

    printf("Top element is : %d\n", stackTop(&stack));
    printf("Bottom element is : %d\n", stackBottom(&stack));
    transverse(&stack);

    printf("\nElement at position 10 is %d\n", peek(&stack, 10));

    return 0;
}

void createStack(struct Stack *stack, int size)
{

    stack->size = size;
    stack->top = -1;
    stack->ptr = (int *)malloc(sizeof(int) * size);
}

void push(struct Stack *stack, int data)
{
    if (!isFull(stack))
    {

        stack->top++;
        stack->ptr[stack->top] = data;
        // printf("Element inserted sucessfully....\n");
    }
    else
    {
        printf("Stack overflow\n");
    }
}

int pop(struct Stack *stack)
{

    if (stack->top != -1) // iski jagah isEmpty ya isFull ka bhi use kr skte
    {
        stack->top--;
        return stack->ptr[stack->top + 1];
    }
    else
    {
        printf("Stack Underflow : Stack is empty.\n");
        return -1;
    }
}

void transverse(struct Stack *stack) //Using peek to transverse is also good
{
    printf("\n");
    int j = 1;
    for (int i = stack->top; i >= 0; i--)
    {
        printf("Element at position %d is : %d\n", j, stack->ptr[i]);
        j++;
    }
}

int isEmpty(struct Stack *stack)
{

    if (stack->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Stack *stack)
{

    if (stack->top == stack->size - 1)
    {
        return 1; // BAdhiya toh h bool but faltu mai ek lib import karo
    }             // Isse accha khud hi false ko 0 aur true to 1 likh do
    return 0;
}

int peek(struct Stack *stack, int position)
{                                          // We assume position starting from 1, also since its stack so position 1 is element
                                           // at last and so on.
    int index = stack->top - position + 1; // Since top is the index of last element(starting from 0) while, position start's with 1
    if (index < 0)
    {                                    // so we need need to add 1 in order to maintain index(for further explain try taking real example)
        printf("Not a valid position."); // ex : for getting element at position 1(last element), if i subtract only position then i get
        return -1;                       //      element at position 2
    }
    else
    {
        return stack->ptr[index]; // Arrey sb bakwas chod ye dekh : top - (position - 1) = top - position + 1
    }
}

int stackTop(struct Stack *stack)
{
    if (isEmpty(stack)){
        printf("Stack Empty");
        return -1;
    }
    return stack->ptr[stack->top];
}

int stackBottom(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Empty");
        return -1;
    }
    return stack->ptr[0];
}
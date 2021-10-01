#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    char *ptr;
};

void createStack(struct Stack *stack, int size);
void push(struct Stack *stack, char data);
char pop(struct Stack *stack);
int isEmpty(struct Stack *stack);
int isFull(struct Stack *stack);
int checkParenthesis(char exp[100]);
int main()
{
    char exp[100];
    int popResult = 1;

    printf("Enter a expression: ");
    gets(exp);

    if (checkParenthesis(exp))
    {

        printf("\nExpression is completly balanced.");
    }
    else
    {
        printf("\nExpression is not balanced.");
    }

    // fgets(exp, 20, stdin);
    // fgets(exp, 20, stdin);

    // for (int i = 0; exp[i] != '\0'; i++)
    // {
    //     // printf("inloop\n");
    //     if (exp[i] == '(')
    //     {

    //         push(&stack, '(');
    //     }
    //     else if (exp[i] == ')')
    //     {
    //         popResult = pop(&stack);

    //         if (!popResult)
    //         {
    //             printf("\nExpression Is Unbalanced.\n");
    //             break;
    //         }
    //     }
    // }
    // if (popResult && isEmpty(&stack))
    // {
    //     printf("\nExpression Is Balanced.\n");
    // }
    // else
    // {
    //     printf("\nExpression Is Unbalanced.\n");
    // }
    return 0;
}

void createStack(struct Stack *stack, int size)
{

    stack->size = size;
    stack->top = -1;
    stack->ptr = (char *)malloc(sizeof(char) * size);
}

int checkParenthesis(char exp[100])
{

    struct Stack stack;
    createStack(&stack, 100);

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(&stack, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty(&stack))
            {
                return 0;
            }
            char result = pop(&stack);
            if (exp[i] == ')' && result != '(')
            {
                return 0;
            }
            else if (exp[i] == ']' && result != '[')
            {
                return 0;
            }
            else if (exp[i] == '}' && result != '{')
            {
                return 0;
            }
        }
    }
    if (!isEmpty(&stack))
    {
        return 0;
    }
    return 1;
}

void push(struct Stack *stack, char data)
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

char pop(struct Stack *stack)
{

    if (stack->top != -1) // iski jagah isEmpty ya isFull ka bhi use kr skte
    {
        stack->top--;
        return stack->ptr[stack->top + 1];
    }
    else
    {
        printf("Stack Underflow : Stack is empty.\n");
        return 'F';
    }
}

void transverse(struct Stack *stack) //Using peek to transverse is also good
{
    printf("\n");
    int j = 1;
    for (int i = stack->top; i >= 0; i--)
    {
        printf("Element at position %d is : %c\n", j, stack->ptr[i]);
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

char peek(struct Stack *stack, int position)
{                                          // We assume position starting from 1, also since its stack so position 1 is element
                                           // at last and so on.
    int index = stack->top - position + 1; // Since top is the index of last element(starting from 0) while, position start's with 1
    if (index < 0)
    {                                    // so we need need to add 1 in order to maintain index(for further explain try taking real example)
        printf("Not a valid position."); // ex : for getting element at position 1(last element), if i subtract only position then i get
        return 'f';                      //      element at position 2
    }
    else
    {
        return stack->ptr[index]; // Arrey sb bakwas chod ye dekh : top - (position - 1) = top - position + 1
    }
}

int stackTop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
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
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
char pop(struct Stack *stack); // Return is important
int isEmpty(struct Stack *stack);
int isFull(struct Stack *stack);
char stackTop(struct Stack *stack);
int precedence(char ch);
char *getPostfix(char *infix);

int main()
{
    // char *infix = "a*b+c-d/r";
    // char *infix = "a*(b+c)";
    char *infix = "a*(b/c)+i"; // jaise brackets agar pehle se lage h toh toh pehle vo hi krna padega. Jo ki mera program krta h
                              // Ye manual mai bhi kr ke dekh, iski value iabc/*+ nai abc/*i+ hogi(sequence baby sequence)

    printf("\nPostfix of %s is : %s\n\n", infix, getPostfix(infix));

    return 0;
}

int precedence(char ch)
{
    if (ch == '(')
    {
        return 4;
    }
    else if (ch == '*' || ch == '/' || ch == '%')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

char *getPostfix(char *infix)
{
    struct Stack stack;
    createStack(&stack, 20);
    char *postfix = (char *)malloc(sizeof(char) * (strlen(infix) + 1));
    int i = 0; // For index of infix
    int j = 0; // For index of our new postfix expression
    while (infix[i] != '\0')
    {
        if (!(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '%' || infix[i] == ')' || infix[i] == '(')) // checking if not operator
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            // printf("\nprecedence of %c is %d\n", infix[i], precedence(infix[i]));
            if ((precedence(infix[i]) > precedence(stackTop(&stack))) || stackTop(&stack) == '(')
            {
                push(&stack, infix[i]);
                i++; // Since postfix exp isn't incremented, therefore j++ is not written
            }
            else if (infix[i] == ')')
            {
                while (stackTop(&stack) != '(')
                {
                    postfix[j] = pop(&stack);
                    j++;
                }
                pop(&stack);
                i++;
            }
            else
            {

                postfix[j] = pop(&stack);
                j++; // Since we want to check the same conditions again for same infix value till precedence of top is not less, hence i++ not written
            }
        }
    }
    while (!isEmpty(&stack))
    {

        postfix[j] = pop(&stack); // Adding all the stack elements to our expression
        j++;
    }
    postfix[j] = '\0'; //Completing our string

    return postfix;
}

void createStack(struct Stack *stack, int size)
{
    stack->size = size;
    stack->top = -1;
    stack->ptr = (char *)malloc(sizeof(char) * size);
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
        return -1;
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

char stackTop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        return -1;
    }
    return stack->ptr[stack->top];
}

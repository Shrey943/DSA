#include <stdio.h>
#include <stdlib.h>

typedef struct NodeStruct
{
    struct NodeStruct *prevNode;
    int data;
    struct NodeStruct *nextNode;
} Node;

typedef struct   // Dekho yaar, pehle bikul sahi sooche the tum, ki initially, front = rare = NULL and jaise hi pehla element aayega, front
{                // and rare usko bana denge, but tum yaha pe isko null nai kr skte
    Node *front; // pehle Queue naam ka struct create toh karo
    Node *rare;
} Queue;

void createQueue(Queue *queue);
void enqueueF(Queue *queue, int data);
void enqueueB(Queue *queue, int data);
void display(Queue *queue);
void reverse(Queue *queue);
int dequeueF(Queue *queue);
int dequeueB(Queue *queue);

int peek(Queue *queue, int position);
int queueTop(Queue *queue);
int queueBottom(Queue *queue);

int main()
{

    Queue queue;
    createQueue(&queue);

    enqueueF(&queue, 1);
    enqueueF(&queue, 2);
    enqueueF(&queue, 3);
    enqueueF(&queue, 4);
    enqueueB(&queue, 5);
    enqueueB(&queue, 6);
    enqueueB(&queue, 7);
    enqueueB(&queue, 8);

    display(&queue);

    dequeueF(&queue);
    dequeueB(&queue);

    display(&queue);

    printf("\nElemet at position %d is %d\n", 1, peek(&queue, 1));
    printf("\nElemet at position %d is %d\n", 3, peek(&queue, 3));
    printf("\nElemet at position %d is %d\n", 5, peek(&queue, 5));
    printf("\nElemet at position %d is %d\n", 6, peek(&queue, 6));
    printf("\nElemet at position %d is %d\n", 7, peek(&queue, 7));
    printf("\nElemet at position %d is %d\n", 8, peek(&queue, 8));

    printf("\nTop element is : %d\n", queueTop(&queue));
    printf("\nBottom element is : %d\n", queueBottom(&queue));

    reverse(&queue);
    return 0;
}

void createQueue(Queue *queue)
{
    queue->front = NULL;
    queue->rare = NULL;
}

void enqueueF(Queue *queue, int data)
{
    Node *new = (Node *)malloc(sizeof(Node));
    if (new == NULL)
    {
        printf("\nSorry! Queue is full.\n");
    }
    new->prevNode = NULL;
    new->data = data;
    new->nextNode = NULL;

    if (queue->front == NULL)
    {
        queue->front = queue->rare = new;
    }
    else
    {
        new->nextNode = queue->front;
        (queue->front)->prevNode = new;
        queue->front = new;
    }
}
void enqueueB(Queue *queue, int data)
{
    Node *new = (Node *)malloc(sizeof(Node));
    if (new == NULL)
    {
        printf("\nSorry! Queue is full.\n");
    }
    new->prevNode = queue->rare;
    new->data = data;
    new->nextNode = NULL;

    if (queue->rare == NULL)
    {
        queue->front = queue->rare = new;
    }
    else
    {
        (queue->rare)->nextNode = new;
        queue->rare = new;
    }
}

int dequeueF(Queue *queue)
{
    Node *temp = queue->front;

    if (queue->front == NULL)
    {
        printf("\nQueue Underflow : queue is empty.\n");
        return -1;
    }

    int data = temp->data;

    if (queue->front == queue->rare)
    {
        free(queue->front);
        queue->front = queue->rare = NULL;
        return data;
    }
    (temp->nextNode)->prevNode = NULL;
    queue->front = temp->nextNode;
    free(temp);
    return data;
}
int dequeueB(Queue *queue)
{
    Node *temp = queue->rare;

    if (queue->rare == NULL)
    {
        printf("\nQueue Underflow : queue is empty.\n");
        return -1;
    }

    int data = temp->data;

    if (queue->front == queue->rare)
    {
        free(queue->rare);
        queue->front = queue->rare = NULL;
        return data;
    }

    (temp->prevNode)->nextNode = NULL;
    queue->rare = temp->prevNode;
    free(temp);
    return data;
}

void display(Queue *queue)
{
    printf("\nQueue: ");

    Node *temp = queue->front;
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->nextNode;
    }
}
void reverse(Queue *queue)
{

    printf("\nReverse Queue : ");
    Node *temp = queue->rare;
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->prevNode;
    }
}

int peek(Queue *queue, int position)
{

    if (queue->rare == NULL)
    {
        printf("\nQueue Underflow : queue is empty.\n");
        return -1;
    }

    Node *temp = queue->front;

    for (int i = 0; (i < position - 1 && temp != NULL); i++)
    {
        temp = temp->nextNode;
    }
    if (temp == NULL)
    {
        printf("\nPlease enter a valid position.\n");
        return -1;
    }
    return temp->data;
}
int queueTop(Queue *queue)
{

    if (queue->rare == NULL)
    {
        printf("Queue Empty\n");
        return -1;
    }
    return queue->front->data;
}

int queueBottom(Queue *queue)
{

    if (queue->rare == NULL)
    {
        printf("Queue Empty\n");
        return -1;
    }
    return queue->rare->data;
}
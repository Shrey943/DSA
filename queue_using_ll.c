#include <stdio.h>
#include <stdlib.h>

typedef struct NodeStruct
{
    int data;
    struct NodeStruct *nextNode;
} Node;

typedef struct   // Dekho yaar, pehle bikul sahi sooche the tum, ki initially, front = rare = NULL and jaise hi pehla element aayega, front
{                // and rare usko bana denge, but tum yaha pe isko null nai kr skte
    Node *front; // pehle Queue naam ka struct create toh karo
    Node *rare;
} Queue;

void createQueue(Queue *queue);
void enqueue(Queue *queue, int data);
void display(Queue *queue);
int dequeue(Queue *queue);

int peek(Queue *queue, int position);
int queueTop(Queue *queue);
int queueBottom(Queue *queue);

int main()
{

    Queue queue;
    createQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    enqueue(&queue, 6);
    enqueue(&queue, 7);
    enqueue(&queue, 8);

    display(&queue);

    dequeue(&queue);
    dequeue(&queue);

    display(&queue);

    printf("\nElemet at position %d is %d\n", 1, peek(&queue, 1));
    printf("\nElemet at position %d is %d\n", 3, peek(&queue, 3));
    printf("\nElemet at position %d is %d\n", 5, peek(&queue, 5));
    printf("\nElemet at position %d is %d\n", 6, peek(&queue, 6));
    printf("\nElemet at position %d is %d\n", 7, peek(&queue, 7));
    printf("\nElemet at position %d is %d\n", 8, peek(&queue, 8));

    printf("\nTop element is : %d\n", queueTop(&queue));
    printf("\nBottom element is : %d\n", queueBottom(&queue));
    return 0;
}

void createQueue(Queue *queue)
{
    queue->front = NULL;
    queue->rare = NULL;
}

void enqueue(Queue *queue, int data)
{
    Node *new = (Node *)malloc(sizeof(Node));
    if (new == NULL)
    {
        printf("\nSorry! Queue is full.\n");
    }

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

int dequeue(Queue *queue)
{
    Node *temp = queue->front;

    if (queue->rare == NULL)
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

    queue->front = temp->nextNode;
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
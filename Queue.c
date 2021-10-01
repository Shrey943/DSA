#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front;
    int rare;
    int size;
    int *ptr;
};

void createQueue(struct Queue *queue, int size);
int isEmpty(struct Queue *queue);
int isFull(struct Queue *queue);
void enqueue(struct Queue *queue, int data);
int dequeue(struct Queue *queue);
int peek(struct Queue *queue, int position);
void display(struct Queue *queue);
int queueTop(struct Queue *queue);
int queueBottom(struct Queue *queue);

int main()
{
    struct Queue queue;

    createQueue(&queue, 10);

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

void createQueue(struct Queue *queue, int size)
{

    int *new = (int *)malloc(sizeof(int) * size);
    queue->front = -1;
    queue->rare = -1;
    queue->size = size;
    queue->ptr = new;
}

int isEmpty(struct Queue *queue)
{

    if (queue->front == queue->rare)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Queue *queue)
{

    if (queue->rare == queue->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *queue, int data)
{

    if (isFull(queue))
    {
        printf("Queue OverFlow\n");
    }
    else
    {
        queue->rare++;
        queue->ptr[queue->rare] = data;
    }
}

int dequeue(struct Queue *queue)
{

    if (isEmpty(queue))
    {
        printf("Queue Underflow.\n");
        return -1;
    }

    queue->front++;
    return queue->ptr[queue->front];
}

int peek(struct Queue *queue, int position)
{
    printf("%d\n", queue->rare);
    if (isEmpty(queue))
    {
        printf("Queue Empty.\n");
        return -1;
    }
    else if (position > queue->rare - queue->front)
    {
        printf("\nPosition not valid.\n");
        return -1;
    }
    return queue->ptr[queue->front + position];
}

void display(struct Queue *queue)
{
    printf("\n");
    for (int i = queue->front + 1; i <= queue->rare; i++)
    {
        printf("Element : %d\n", queue->ptr[i]);
    }
}

int queueTop(struct Queue *queue)
{

    if (isEmpty(queue))
    {
        printf("Queue Empty\n");
        return -1;
    }
    return queue->ptr[queue->front + 1];
}

int queueBottom(struct Queue *queue)
{

    if (isEmpty(queue))
    {
        printf("Queue Empty\n");
        return -1;
    }
    return queue->ptr[queue->rare];
}
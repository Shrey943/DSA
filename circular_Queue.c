#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front; // In circular queue, now front and rare will be incremented using special formula (i+1)%size
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
int count(struct Queue *queue);

int main()
{
    struct Queue queue;

    createQueue(&queue, 10);

    enqueue(&queue, 1); // Remember: Only 9 elements will be saved as 1 block remains blank
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    enqueue(&queue, 6);
    enqueue(&queue, 7);
    enqueue(&queue, 8);
    enqueue(&queue, 9);
    enqueue(&queue, 10);
    enqueue(&queue, 11);

    display(&queue);

    dequeue(&queue);
    dequeue(&queue);

    display(&queue);

    enqueue(&queue, 10);
    // enqueue(&queue, 11);

    display(&queue);

    printf("\nElemet at position %d is %d\n", 1, peek(&queue, 1));
    printf("\nElemet at position %d is %d\n", 3, peek(&queue, 3));
    printf("\nElemet at position %d is %d\n", 5, peek(&queue, 5));
    printf("\nElemet at position %d is %d\n", 8, peek(&queue, 8));
    printf("\nElemet at position %d is %d\n", 15, peek(&queue, 15));

    printf("\nTop element is : %d\n", queueTop(&queue));
    printf("\nBottom element is : %d\n", queueBottom(&queue));

    printf("\nTotal number of elements are: %d\n", count(&queue));
    return 0;
}

void createQueue(struct Queue *queue, int size)
{

    int *new = (int *)malloc(sizeof(int) * size);
    queue->front = 0; //So that 1 empty position is reserved for front(it also helps in calculations of special formula, as it do not for with -1)
    queue->rare = 0;  // front waali position toh hamessa khaali rehti hi h na yaar,toh kahe bharega
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

    if ((queue->rare + 1) % queue->size == queue->front) // If rare+1 = front then full(used formula because if front = 0 & rare = last then will get correct value)
    {                                                    // Yes, 1 block will remain empty always
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
        queue->rare = (queue->rare + 1) % queue->size;
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

    queue->front = (queue->front + 1) % queue->size;
    return queue->ptr[queue->front];
}

int peek(struct Queue *queue, int position)
{

    if (isEmpty(queue))
    {
        printf("Queue Empty.\n");
        return -1;
    }
    else if (position > count(queue))
    {
        printf("\nPosition not valid.\n");
        return -1;
    }
    return queue->ptr[(queue->front + position) % queue->size]; // dekho ye formula size ye bada jo bhi number hoga usko zero se fir suru kr dega
                                                                // jaise maan lo list size = 10 front = 8 rare = 4 toh value at 4 position
                                                                // krne mai ye 1 return karega, jo apan ko chaiye
}

void display(struct Queue *queue)
{
    printf("\n");
    int i = (queue->front + 1) % queue->size;
    while (i != queue->rare)
    {
        printf("Element : %d\n", queue->ptr[i]);
        i = (i + 1) % queue->size;
    }
    printf("Element : %d\n", queue->ptr[i]);
   
}
int queueTop(struct Queue *queue)
{

    if (isEmpty(queue))
    {
        printf("Queue Empty\n");
        return -1;
    }
    return queue->ptr[(queue->front + 1) % queue->size];
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

int count(struct Queue *queue)
{

    // int count = 0;
    // int i = (queue->front + 1) % queue->size;
    // while (i != queue->rare + 1)
    // {
    //     count++;
    //     i = (i + 1) % queue->size;
    // }

    // printf("\nCount : %d\n", count);
    // return count;

    //But Above code have time complexity of O(n) which...is not good when we can do same in O(1) time so below is the thing

    if (queue->rare < queue->front)
    {
        return queue->size - queue->front + queue->rare;
    }
    return queue->rare - queue->front;
}
#include <stdio.h>
#include <stdlib.h>

const int V = 6; // Global variable will be needed

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

void init(int arr[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {   
            arr[i][j] = 0; // Initiating every value with 0
        }
    }
}

void addEdge(int arr[][V], int src, int des)
{
    arr[src][des] = 1;
    // For undirected
    arr[des][src] = 1;
} 

void BFS(int arr[][V], int startNode)
{

    struct Queue exploreQueue;
    createQueue(&exploreQueue, V);

    int *visited = (int *)calloc(V, sizeof(int));

    int i = 1;

    enqueue(&exploreQueue, startNode);
    visited[startNode] = i;

    printf("\nBFS2: %d, ", startNode);

    while (!isEmpty(&exploreQueue))
    {
        i = dequeue(&exploreQueue);
        for (int k = 0; k < V; k++)
        {
            if (arr[i][k] == 1 && visited[k] != 1)
            {
                visited[k] = 1;
                enqueue(&exploreQueue, k);
                printf("%d, ", k);
            }
        }
    }
}

void printGraph(int arr[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", arr[i][j]);
        }
        /* code */
        printf("\n");
    }
}
int main()
{

    int graph[6][6];

    init(graph);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 0, 5);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 5);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    /*
    |          3
    |         |  \
    |         1 - 5
    |         | X |
    |     2 - 4 - 0

    */
    printGraph(graph);
    BFS(graph, 0);

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
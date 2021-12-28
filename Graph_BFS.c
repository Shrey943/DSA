#include <stdio.h>
#include <stdlib.h>

struct AdjListNode
{
    int des;
    struct AdjListNode *next;
};

struct AdjList
{

    struct AdjListNode *head;
};

struct Graph
{
    int V;                 // Ye total number of vertices h.
    struct AdjList *array; // Aur ye main array(Array jo vertically banate h na) uska pointer store karega
};

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

struct AdjListNode *newAdjListNode(int des) // Kuch nai yaar bs ek node initilize krne function h, ll mai bhi toh tha
{
    struct AdjListNode *new = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    new->des = des;
    new->next = NULL;

    return new;
}

struct Graph *createGraph(int v)
{

    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));           // graph ka skeleton, basic detail ke saath
    struct AdjList *array = (struct AdjList *)malloc(v * sizeof(struct AdjList)); // Uper jo gyan pela h, vahi h

    graph->V = v;
    graph->array = array;

    // Initialize bhi kr hi dete h
    for (int i = 0; i < v; i++)
    {
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int des)
{

    struct AdjListNode *check; // NULL Check krne lagega aage
    struct AdjListNode *newNode = newAdjListNode(des);

    if (graph->array[src].head == NULL)
    {
        newNode->next = NULL; // Well iski zarurat toh nai thi as pehle se hi null kr diya tha apan ne function mai
        graph->array[src].head = newNode;
    }
    else
    {
        check = graph->array[src].head;
        while (check->next != NULL)
        {
            check = check->next;
        }

        check->next = newNode;
    }

    newNode = newAdjListNode(src);
    if (graph->array[des].head == NULL)
    {
        newNode->next = NULL;
        graph->array[des].head = newNode;
    }
    else
    {
        check = graph->array[des].head;
        while (check->next != NULL)
        {
            check = check->next;
        }

        check->next = newNode;
    }
}

void printGraph(struct Graph *graph)
{
    struct AdjListNode *check;
    for (int i = 0; i < graph->V; i++)
    {

        // printf("%c : ", graph->array[i].data);
        printf("%d : ", i);
        check = graph->array[i].head;

        if (check != NULL)
        {
            while (check != NULL)
            {
                printf("%d -> ", check->des);
                check = check->next;
            }
            printf("NULL\n");
        }
        else
        {
            printf("NULL\n");
        }
    }
}

int in(int *array, int size, int check) // To check if a number is in an array or not
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == check)
        {
            return 1;
        }
    }
    return 0;
}

void BFS(struct Graph *graph, int startNode)
{
    // struct Queue *queue; // This would just create a container to hold queue, you need a queue object.
    struct Queue exploreQueue;
    createQueue(&exploreQueue, graph->V); // no. of vertices size ka queue chahiye

    int *visited = (int *)malloc(sizeof(int) * graph->V); // Dynamic array banaya h ji
    struct AdjListNode *check;                            // Neeche lagega ye
    int i = 0;                                            // ye bhi lagega

    enqueue(&exploreQueue, startNode); // start element ko queue and visited  mai daal diya
    visited[i++] = startNode;

    while (!isEmpty(&exploreQueue))
    {

        check = graph->array[queueTop(&exploreQueue)].head; // Queue ke top element ke head pointer ko nikaala
        while (check != NULL)
        {
            if (!in(visited, graph->V, check->des)) // Bs yahi check kr raye h ki ye elements visited list mai h ya nai
            {
                visited[i] = check->des; // Agar nai h toh visited and queue mai add kia
                enqueue(&exploreQueue, check->des);
                i++; // i mai kuch add kia h toh increment bhi toh krna padega na
            }
            check = check->next;
        }
        dequeue(&exploreQueue); // Ab saare connected nodes visit kr liye h toh queue se hata bhi do ab
    }

    // return visited;
    // Breadth first search transversal h bhai, print bhi function ke ander kr ke do

    printf("\nBFS : ");
    for (int i = 0; i < graph->V; i++)
    {
        printf("%d, ", visited[i]);
    }
}
void BFS2(struct Graph *graph, int startNode) // Smjhne ke liye uper waala dekh lo aur thode advance ke liye neeche waala
{

    struct Queue exploreQueue;
    createQueue(&exploreQueue, graph->V); // no. of vertices size ka queue chahiye

    // Look, is baar apan visited array mai sirf 0 and 1 rakhenge, and element ka index represent karega vertex.
    int *visited = (int *)calloc(graph->V, sizeof(int)); // Calloc use kia taaki saare elements 0 se initialized mile
    struct AdjListNode *check;
    int i = 1; // Uper apan ne 0 rakha tha kyoki apan ko index ke liye chaiye tha, ab apan i ko as true lenge

    enqueue(&exploreQueue, startNode); // start element ko queue and visited  mai daal diya
    visited[startNode] = i;            // Visited ke start index ko true kia, as i represent true
    printf("\nBFS2: %d, ", startNode);   // Alag se na print kr ke saath mai hi kr raye

    while (!isEmpty(&exploreQueue))
    {

        // check = graph->array[queueTop(&exploreQueue)].head;
        i = dequeue(&exploreQueue); // Are dekho, queueTop ko use karne ki jagah bs dequeue kia h, as apan ko aage
                                    // dequeue toh krna hi tha na and saath mai jo element pop hua h vo bhi milega

        check = graph->array[i].head;
        while (check != NULL)
        {

            // if (!in(visited, graph->V, check->des)) // isbaar in function nai chaiye padega.
            if (visited[check->des] != 1)
            { 
                printf("%d, ", check->des);
                visited[check->des] = 1; // check->des index ko true kia
                enqueue(&exploreQueue, check->des);
                // i ka bhi kaam nai
            }
            check = check->next;
        }
    }

    // Breadth first search transversal h bhai, print bhi function ke ander kr ke do

    // printf("\nBFS2 : ");
    // for (int i = 0; i < graph->V; i++)
    // {
    //     if (visited[i] == 1)
    //     {

    //         printf("%d, ", i);
    //     }
    // }
}

int main()
{

    struct Graph *graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 0, 5);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 5);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printGraph(graph);

    /*
    |          3
    |         |  \
    |         1 - 5
    |         | X |
    |     2 - 4 - 0

    */

    BFS(graph, 0);
    BFS2(graph, 0);

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
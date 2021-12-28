#include <stdio.h>
#include <stdlib.h>


struct AdjListNode
{
    int des; // Destination node store krne
    struct AdjListNode *next;
};

struct AdjList
{
    // char data;             // Using this we can store data also, But as of now jaha jaha maine implementations dekhi h, toh
    // Ye smjh aaya h hi graph data ko store krne se jyada more of connectivity ko store krne ke kaam
    // Aata h. isiliye data storage pe focus nai krte. ya shayad aage jaake ho data bhi, pata nai
    struct AdjListNode *head; // Ye kyo banaya iska jawab neeche h
};

struct Graph
{
    int V;                 // Ye total number of vertices h.
    struct AdjList *array; // Aur ye main array(Array jo vertically banate h na) uska pointer store karega

    /*
    Important: Well is code mai vertice ke data ko store nai kr raye h, vertice sirf index number se represent ho
               rahi h. Isiliye jo vertical array banate h na VO SIRF HEADS KO STORE KRNE H, Adjacent linked list ke.
               Aur isiliye... struct AdjList banayi thi...Smjhe.
               Also basically array, bs AdjListNode pointer  ka array h.

               ** isimai(AdjList mai) agar data ka option de toh, data bhi store kr skte h **
    */
};


struct AdjListNode *newAdjListNode(int des) // Kuch nai yaar bs ek node initilize krne function h, ll mai bhi toh tha
{
    struct AdjListNode *new = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    new->des = des;
    new->next = NULL;

    return new;
}

// struct Graph *createGraph(int v, char data[])
struct Graph *createGraph(int v)
{
    // V ko kaha multiply kia h Dhyaan dena
    // int v = sizeof(data) / sizeof(char); // Bete function mai array paas krte ho toh first element ka pointer jaata h
    // Isiliye sizeof function kaam ka nai
    // printf("V: %d\n", v);

    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));           // graph ka skeleton, basic detail ke saath
    struct AdjList *array = (struct AdjList *)malloc(v * sizeof(struct AdjList)); // Uper jo gyan pela h, vahi h

    graph->V = v;
    graph->array = array;

    // Initialize bhi kr hi dete h
    for (int i = 0; i < v; i++)
    {
        // graph->array[i].data = data[i]; // Kyoki main toh array h
        graph->array[i].head = NULL; // Dekho, graph ek pointer h struct GRAPH ka isiliye arrow operator use krna pada
                                     // but array[i] mai ek struct AdjList h(not uska pointer) isiliye dot use hua
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

    // Aur bs ho gaya kaam but BETE ye toh ek side se hua na connection, Undirected mai dono se rehta h isiliye,

    // addEdge(graph, des, src); // Well Bete....Ye naadaani pehle hi kr chuke h hum, this will start an infinite loop
    // As Next waale ke liye fir src and des flip ho jayenge isiliye uper ke code
    // ko hi copy kia, bs src ki jagah des and des ki jagah src

    newNode = newAdjListNode(src);
    if (graph->array[des].head == NULL)
    {
        newNode->next = NULL; // Well iski zarurat toh nai thi as pehle se hi null kr diya tha apan ne function mai
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


int main()
{
    // char data[6] = {'A', 'B', 'C', 'D', 'E', 'F'}; // Fully tested and correct h
    // struct Graph *graph = createGraph(6, data);
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

    return 0;
}
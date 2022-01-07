#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

const int V = 7;

void init(int arr[][V]) //  **This time we need a cost adjacency matrix, hence will initialize with -1
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            arr[i][j] = -1; // Initiating every value with -1
        }
    }
}

void addEdge(int arr[][V], int src, int des, int cost) // Cost bhi chahiye padegi
{
    arr[src][des] = cost;
    // For undirected
    arr[des][src] = cost;
}
void printGraph(int arr[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        /* code */
        printf("\n");
    }
}

int check(int graph[][V], int mstVertex[], int leftVertex[], int store[])
{
    printf("IN CHECK FUNC\n");
    int min = INT_MAX, minIndex2, minIndex1;

    for (int i = 0; i < V; i++)
    {
        printf("IN CHECK loop1\n");
        if (mstVertex[i] == 1)
        {
            for (int j = 0; j < V; j++)
            {
                if (leftVertex[j] != 0 && graph[i][j] > -1 && graph[i][j] < min)
                {
                    min = graph[i][j];
                    minIndex1 = i;
                    minIndex2 = j;
                }
            }
        }
    }
    if (store[minIndex1] < INT_MAX)
    {
        store[minIndex2] = minIndex1;
    }else{
        store[minIndex1] = minIndex2;
    }
    
    return minIndex2;
}

void primsSpanningTree(int graph[][V])
{

    int leftVertex[V] ; // Array to store all the veritces
    int mstVertex[V] ;  // Array to store vertices in minimum spanning tree(mst)
    int store[V];                              //  To store the vertices
    int vertex;

    for (int i = 0; i < V; i++)
    {
        leftVertex[i] = 1;
        mstVertex[i] = 0;
        store[i] =INT_MAX;
    }
    
    leftVertex[0] = 0;
    mstVertex[0] = 1;
    
    for (int j = 1; j < V; j++)
    {
        printf("IN SPANNING TREE LOOP\n");
        vertex = check(graph, mstVertex, leftVertex, store);
        mstVertex[vertex] = 1;
        leftVertex[vertex] = 0;
       
    }

    printf("MST : ");
    for (int i = 0; i < V; i++)
    {
        printf("%d, ", mstVertex[i]);
    }
    
    printf("\nstore : ");
    for (int i = 0; i < V; i++)
    {
        printf("%d, ", store[i]);
    }
    
    printf("\nleft : ");
    for (int i = 0; i < V; i++)
    {
        printf("%d, ", leftVertex[i]);
    }
    
}

int main()
{
    int graph[7][7];
    init(graph);

    addEdge(graph, 0, 5, 17); //               6 ---- 1
    addEdge(graph, 0, 4, 2);  //              /        \                      
//  addEdge(graph, 1, 6, 6);  //             5 -- 0     2
    addEdge(graph, 1, 2, 11); //              \  /     /
    addEdge(graph, 2, 3, 5);  //               4 ---- 3
    addEdge(graph, 3, 4, 23); //
    addEdge(graph, 4, 5, 19); //
    addEdge(graph, 5, 6, 10); //
    addEdge(graph, 6, 1, 6);

    // printGraph(graph);
    printf("\n V: %d", V);
    primsSpanningTree(graph);

    return 0;
}
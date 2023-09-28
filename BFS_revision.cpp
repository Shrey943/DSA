# include <iostream>
# include <string>
# include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> graph[], int src, int des){
    graph[src].push_back(des);
    graph[des].push_back(src);
}

// In Breadth First Search, We do the level wise traversal. A level of the node is the depth of it. It always reach the node with shortest path.
// As instead of moving deep into any node, it says, let me first see all the nodes possible at this point of time. Instead of child ke andar child
// it says, let me first see all the childs.
// But which child first? obviously, the first come first serve one. Hence it uses a queue. The concept is to push all the childs in queue and
// explore nodes one by one, by poping.
// Note: A a point of time, node of only maximum 2 consecutive levels are present in our queue, as we pop all the nodes and then the child on childs
// are explored, in graph, their can be many possible way to reach a node, but the shortest path, first visit is the level of node.
void BFS(vector<int> graph[],vector<int>& visited,vector<int>& levels,  int vertex = 0){
    
    // Entry of bfs
    queue<int> queue;
    queue.push(vertex);
    // do tasks on the starting node.
    visited[vertex] = 1;
    levels[vertex] = 0;

    while(!queue.empty()){ // Note: It's not a loop like a for loop
        vertex = queue.front();
        queue.pop();
        // looking at a vertex, before going to childs
        cout << vertex << ", ";
        // For matrix questions, in place of childs, have a movement structure to traverse for each position.
        // vector<pair<int, int>> movements = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}} for down, right, top, left respectively
        // for diagonal, add {1, 1}, {-1, -1}, {1, -1}, {-1, 1}} 
        // Just add pair.first to x and pair.second to y to have a possible child. remember to check for out of range conditions 
        for(int child: graph[vertex]){// O(E)
        // Just seen childs, not and stored for future
            if(!visited[child]){
                 queue.push(child);
                 visited[child] = 1;
                 levels[child] = levels[vertex] + 1;
            }
            // Nothing like after child as its a loop
        }
    }
    // Looked all the nodes.

    // Looking for the time complexity, look actually both, dfs and bfs has a loop inside loop or recursion but it do not have n^2 time complexity
    // as Its not running same things on loop, the loop will only call the function E times(no. of edges) you may say for every vertex v but
    // as nodes are explored, it would return. Making an effective time complexity of O(V+E)
}

int main()
{
    int v = 11;
    vector<int> graph[v];
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 5, 6);
    addEdge(graph, 5, 9);
    addEdge(graph, 6, 10);
    addEdge(graph, 3, 8);
    addEdge(graph, 3, 7);

    vector<int> visited(v, 0);
    vector<int> levels(v); // Will store the levels
    BFS(graph, visited, levels);
    cout << endl
         << "Levels of BFS are: " << endl;
    for (int i = 0; i < v; i++){
        cout<<i<< " : "<< levels[i]<<endl;
    }
    // Below is a mxm matrix, give me a shortest path or return the minimum no of moves requrired to reach the end home 
    return 0;
}
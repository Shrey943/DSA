# include <iostream>
# include <string>
# include <bits/stdc++.h>

using namespace std;

// Depth First Search (DFS)
/*
DFS ka seedha kehna h ki karne toh saare path h explore but jaise hi rasta mile, ghuste jaao, tb tk ghuste jaao
jb tk return na ho jaao, repeat for all the other paths too. But han yaad rakhna ki visited nodes pr aage nai jaana
h. Just return ho jaao.

Ab dekho, tree mai jb apan inorder lagate h toh vo actually DFS hi h, we keep on going to the left most child till
it automatically starts returning, while exploring all the possible childs in the path or each node which we enter.
Since tree mai koi bhi cycle nai hoti, and we already have minimum edges, hence we don't need a visited array. As
its not possible to go to any explored node, just the return of recursion(stack) is sufficient.

But in graph, it is a must to have a visited array(except in the case of matrix representation as we can directly
change its value) to not get trapped in a infinite cycle of child and parent(as parent is also a child of child in
undirected graph) or even other cycle. Code is very simple and is implemented as below:
*/
vector<int> visited;
vector<int> depth;
vector<int> height;
vector<int> sumSub;
vector<int> evens;
vector<int> parents;

// Using a traditinal graph method with modern 
// O(V+E)
// void DFS(vector<vector<int>>& graph, int vertex){
void DFS(vector<int> graph[], int vertex){
    /* 1) This is the part which will be called for each vertex when it is explored. It contains the code which we need 
    before it goes to it's children.*/

    visited[vertex] = 1; // Marking visited
    cout << vertex << ", ";
    for (int child: graph[vertex]){

        // 2) In this section we write the code we want to implement on each child before it enter the child.
        if (visited[child] == 1)
            continue;
        
        DFS(graph, child);

        // 3) Here we can write program to do task on each child after it returns to vertex
    }
    // 4) This is the section were we can write the program we want to do run when the vertex had explored it's child and 
    // is returned. This is the program which is ran before the vertext reach it's parent.

    // NOTE: section 1 and 2 are when we moving down the tree/graph. section 3 and 4 are when we moving up the tree/graph.
}

// Okay so the concept is, for each vertex, check if the childs are already discovered.
// But, since parent is also one of the child in undirected graph, we need to exclude parent from above condition
// Hence we will be passing parent as an parameter
// bool isAcyclic(vector<vector<int>> &graph, int vertex, int parent){
bool isAcyclic(vector<int> graph[], int vertex, int parent){ // Since it passes the pointer of first object, hence we do not need reference variable

    visited[vertex] = 1;
    bool acyclic = true;

    for (int child: graph[vertex]){
        // cout << "child: " << child << endl;
        // since it's an and condition, hence if first is false, it won't check the second, as for 1st element, parent is not defined.
        if (visited[child] == 1 && child != parent) {
            // cout<<"found cycle at: "<<child<< " parent: " << parent <<endl;
            return false;
        }
        if (visited[child] == 1){
            continue;
        }
        // Neeche logical AND statement lagakar reassign kr diya h, agar ek bhi baar false hua toh false rahega, 
        acyclic = acyclic && isAcyclic(graph, child, vertex);
    }

    return acyclic;
}

int MinDiff = INT_MAX;
int MaxProduct = INT_MIN;
pair<int, int> Remove;
int totalSum = 0;

// We need parent to void infinite self loop, and totalSum to calculate difference if vertex is detached
void DFS_TREES(vector<int> graph[], int vertex = 0, int parent = -1){

    // This section is when we are going down the tree and encounter a node

    // Since depth is calculated down the graph
    if(parent != -1)
        depth[vertex] = depth[parent] + 1;
    
    sumSub[vertex] = vertex;
    parents[vertex] = parent;

    for(int child : graph[vertex]){

        // This section is before entering the child of the vertex
        if (child != parent){ DFS_TREES(graph, child, vertex);

        // This section is after exiting a child, when it returns to vertex for other childs.
        height[vertex] = max(height[vertex], height[child] + 1);
        sumSub[vertex] += sumSub[child];
        }
    }
    // This section is after exploring all the childs, it's about to exit the vertex and go to parent node.

    // Now, Since vertex had explored its all the childs, we have a final value of it's subtree.
    // If we make it a separate tree then the sum of original sum tree will become (totalSum - sum of this subtree)
    // Since we want difference between them, we need to separate sum of this sub tree from (totalSum-Sum of this subtree)
    // Making it tatalSum - 2*subSub[vertex]  // need to take absolute value, as total can be negative
    
    // MinDiff = min(MinDiff, abs(totalSum - 2*sumSub[vertex]));
    // MaxProduct = max(MaxProduct, (totalSum -sumSub[vertex])*sumSub[vertex]);
    if (vertex!=0 && abs(totalSum - 2*sumSub[vertex]) < MinDiff){ // note vertex!=0, it's necessary as it would run first for 0 only, but zero has no parent, also it makes no sense to check for 0 
        MinDiff = abs(totalSum - 2 * sumSub[vertex]);
        MaxProduct = (totalSum - sumSub[vertex])*sumSub[vertex];
        Remove = make_pair(parent, vertex);
    }

    // Instead of returning, I used a better approach (zyada soochne ka hi nai)
}



int main()
{
    
    // In graph we had seen that a their are 2 types of representation: adjacency list and matrix, both being 
    // traditionally applied through list and 2d array respectively. But now we can use vectors to implement them both.
    //   0
    /*  /\      */ 
    // 1--3--4
    /* \    /  */
    //   2
    
    // Traditional - Space Complexity O(V^2), time complexity to check edge: O(1)
    // int graph1[V][V]; // use malloc to initialize with 0 or use a init function, then using index, just do the required edges as 1(remember to be bidirectional)


    // Traditional list - Space Complexity: O(V+E) E<=V, time complexity to check edge: O(E)
    // struct *listNode graph2[v]; // Keeps the pointer to linked list head, list contain all the connected edges. Needs to traverse to check edge
                                   // But have better space complexity.

    // We can use below to implement both the above types 
     // Initialized a vector of vector of size V and empty arrays. we can use graph[0].push_back() to add edges.
    
    // vector<vector<int>> graph(V, vector<int> (V, 0)); // inititalizes a 2D array of size V*V with all nodes as zero, we can have random access

    // vector<int> graph[v]; This will create an array of vectors. With vectors initialized

    int vertex, des;
    int V, E;
    cout << "NO of vertex: ";
    cin >> V;
    // vector<vector<int>> graph(V); // Vector of vector
    vector<int> graph[V]; // Array of vector
    cout << "Enter No of edges: ";
    cin >> E;
    cout << "Edges: " << endl;
    for (int i = 0; i < E; i++){
        cin >> vertex >> des;
        visited.push_back(0);
        parents.push_back(0);
        depth.push_back(0);
        height.push_back(0);
        sumSub.push_back(0);
        graph[vertex].push_back(des);
        graph[des].push_back(vertex); // undirected

    }
    DFS(graph, 0);

    cout << "NEXT "<<endl;
    for (int k = 0; k < V; k++){
        visited[k] = 0;
    }
        // We can check connected components, cycles and colour change in matrix representation using this.
        // For connected component: Check each component as some may be disconnected.

    int counter = 0;
    for(int j = 0; j < V; j++){
        if (visited[j] == 1)
            continue; // As this means this node is connected.
        DFS(graph, j);
        counter++;
    }
    cout << "Connected components: " << counter << endl;

    // Ab isme thode changes lagenge apne function mai
    cout << "Checking for cycles: " << endl;
    for (int m = 0; m < V; m++)
    {
        visited[m] = 0;
    }
    // cout << "Out for check"<<endl;
    bool acyclic = true;
    for(int q = 0; q < V; q++){
        // cout << "Checking for: " << q;
        if (visited[q] == 1)
            continue;
        if(!isAcyclic(graph, q, 0)){
            acyclic = false;
            break;
        }
    }
    if (acyclic)
        {cout << "Given graph is Acyclic!" << endl;}
    else{
        cout << "Given graph is Cyclic!" << endl;
    }

    cout<<"TREES:"<<endl;
    // DFS IN TREES (for trees, we won't really be needing visited array)
    // Below is a code to remove an edge from a tree such that the sum of the 2 separte trees form is maximum.
    // Also store the depth, height and parent of each vertex; Also write code to find me the lowest common ancestor.

    int total= 0; // For finding minimum difference edge to delete.
    for (int o = 0; o < V; o++){
        total+= o; // We would had used cost[i] instead, if separate cost would have written.
    }
    totalSum = total;

    DFS_TREES(graph);
    
    for (int w = 0; w <V; w++){
        cout << "Depth of " << w << " is " <<depth[w] << endl;
        cout << "Height of " << w << " is " <<height[w] << endl;
        cout << "Sum of subtree " << w << " is "<< sumSub[w] << endl;
        cout << "Parent of " << w << " is " <<parents[w] << endl;
    }

    // Common ancestor of 9 and 10
    vector<int> arr1;
    vector<int> arr2;
    int temp = 9;
    while(temp>-1){
        arr1.push_back(temp);
        temp = parents[temp];
    }
    temp = 10;
    while (temp > -1)
    {
        arr2.push_back(temp);
        temp = parents[temp];
    }
    reverse(arr1.begin(), arr1.end());
    reverse(arr2.begin(), arr2.end());
    int l;
    for (l= 0; l < V; l++)
    {
        if (arr1[l] != arr2[l])
            break;
    }
    cout << "Last Common ancestor of 9 and 10 is: " << arr1[l - 1] << endl<< endl;

    cout<<"We must remove edge between "<<Remove.first<< " and "<<Remove.second<<" to have maximum product of "<< MaxProduct<< " and a minimum difference of " << MinDiff<<endl;
    

    return 0;
}
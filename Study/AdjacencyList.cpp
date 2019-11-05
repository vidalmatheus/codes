#include <bits/stdc++.h>

using namespace std;

// A utility function to add an edge in an 
// undirected graph. 
void addEdge(vector<int> adj[], const int &u, const int &v) // HERE WE DON'T NEED TO ADD '&', BECAUSE ARRAYS ARE PASSED AUTOMATICALLY BY REFERENCE!!!
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
  
// A utility function to print the adjacency list 
// representation of graph 
void printGraph(vector<int> adj[], const int& V) 
{ 
    for (int v = 0; v < V; ++v) 
    { 
        cout << "|" << v << "| ";
        for (auto x : adj[v]) 
           cout << "-> " << x; 
        cout << endl;
    } 
} 

// A utility function to do DFS of graph 
// recursively from a given vertex u. 
void dfs (int u, vector<int> adj[],vector<bool>& visited){
    visited[u] = true;
    cout << u << " ";
    for (int v:adj[u])
        if (!visited[v])
            dfs(v,adj,visited);
}
  
// This function does DFSUtil() for all  
// unvisited vertices. 
void DFS(vector<int> adj[], const int &V){
    vector<bool> visited(V,false);
    cout << "DFS: ";
    for (int u=0;u<V;u++)
        if (!visited[u])
            dfs(u,adj,visited);
}

// Driver code 
int main() 
{   
    int V = 5; // number of vertices    
    // The below line may not work on all 
    // compilers.  If it does not work on 
    // your compiler, please replace it with 
    // following 
    // vector<int> *adj = new vector<int>[V]; 
    vector<int> adj[V]; // Array of vectors, but each vector has its size
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    printGraph(adj, V);
    DFS(adj,V); 
    return 0; 
} 

// OK!
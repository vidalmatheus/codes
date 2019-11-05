// C++ program to represent undirected and weighted graph 
// using STL. The program basically prints adjacency list 
// representation of graph 
#include <bits/stdc++.h> 
using namespace std; 
  
// To add an edge 
void addEdge(vector <pair<int, int> > adj[], const int& u,const int& v, const int& wt) 
{ 
    adj[u].push_back(make_pair(v, wt)); 
    adj[v].push_back(make_pair(u, wt)); 
} 
// OK!

// Print adjacency list representaion ot graph 
void printGraph(vector<pair<int,int> > adj[], const int &V) 
{ 
    int v, w; 
    for (int u = 0; u < V; u++){ 
        cout << "|" << u << "| "; 
        for (auto v:adj[u]){  
            cout << "(" << v.first << ","<< v.second << ") ";
        } 
        cout << endl;
    } 
} 
// OK!
  
// Driver code 
int main() 
{ 
    int V = 5; 
    vector<pair<int, int> > adj[V]; // array of vector of pairs
    addEdge(adj, 0, 1, 10); 
    addEdge(adj, 0, 4, 20); 
    addEdge(adj, 1, 2, 30); 
    addEdge(adj, 1, 3, 40); 
    addEdge(adj, 1, 4, 50); 
    addEdge(adj, 2, 3, 60); 
    addEdge(adj, 3, 4, 70); 
    printGraph(adj, V); 
    return 0; 
} 
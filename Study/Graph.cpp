// Program to print BFS traversal from a given 
// source vertex. BFS(int s) traverses vertices 
// reachable from s. 
#include<bits/stdc++.h>

using namespace std; 

// This class represents a directed graph using 
// adjacency list representation 
class Graph{ 
	int V; // No. of vertices 

	// Pointer to an array containing adjacency 
	// lists 
	map<int,vector<int>> adj; 
public: 
	Graph(int V); // Constructor 

	// function to add an edge to graph 
	void addEdge(int v, int w); 

	// prints BFS traversal from a given node 
	void BFS(int node);

	// prints DFS traversal from a given node 
	void DFS(int node);

	// prints recursive DFS from a given node
	void DFS_Traversal (int node); // necessary for directed graphs
	void DFS_R (int node, bool visited[]);
}; 

Graph::Graph(int V){ 
	this->V = V;
} 

void Graph::addEdge(int v, int w){
	adj[v].push_back(w); // Add w to v’s list. 
} 

void Graph::BFS(int node){ 
	// Mark all the vertices as not visited 
	bool visited[V]; 

	// Create a queue for BFS 
	queue<int> q;

	// Mark the current node as visited and enqueue it 
	visited[node] = true; 
	q.push(node); 

	while(!q.empty()){
		// Dequeue a vertex from queue and print it 
		node = q.front(); 
		cout << node << " "; 
		q.pop(); 

		// Get all adjacent vertices of the dequeued 
		// vertex s. If a adjacent has not been visited, 
		// then mark it visited and enqueue it 
		for (auto e:adj[node]){ 
			if (!visited[e]){ 
				visited[e] = true; 
				q.push(e); 
			} 
		} 
	} 
} 

void Graph::DFS(int node){ 
	// Mark all the vertices as not visited 
	bool visited[V]; 

	// Create a stack for BFS 
	stack<int> s;

	// Mark the current node as visited and enqueue it 
	visited[node] = true; 
	s.push(node); 

	while(!s.empty()){
		// Dequeue a vertex from queue and print it 
		node = s.top(); 
		cout << node << " "; 
		s.pop(); 

		// Get all adjacent vertices of the dequeued 
		// vertex s. If a adjacent has not been visited, 
		// then mark it visited and enqueue it 
		for (auto v:adj[node]){
			if (!visited[v]){
				visited[v] = true;
				s.push(v);
			}
		}

/* 		for (int i=adj[node].size()-1;i>=0;i--){ // inorder to have the same result of recursive DFS!
			if (!visited[adj[node][i]]){ 
				visited[adj[node][i]] = true; 
				s.push(adj[node][i]); 
			} 
		}  */
	} 
} 

void Graph::DFS_Traversal(int node){
	bool visited[V];
	DFS_R(node, visited);
	for (auto v:adj){
		if (!visited[v.first]){
			DFS_R(v.first,visited);
		}
	}
}

void Graph::DFS_R(int node,bool visited[]){
	visited[node]=true;
	cout << node << " ";
	for(int e:adj[node]){
		if (!visited[e]){
			DFS_R(e,visited);
		}
	}
}

// Driver program to test methods of graph class 
int main() 
{ 
	// Create a graph given in the above diagram 
	Graph g(4); 
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(1, 2); 
	g.addEdge(2, 0); 
	g.addEdge(2, 3); 
	g.addEdge(3, 3); 

	cout << "Following is BFS and DFS Traversals "
		<< "(starting from vertex 2) \n"; 
	cout << "BFS: ";
	g.BFS(2);
	cout << "\nDFS: ";
	g.DFS(2); 
	cout << "\n";
	cout << "DFS_Recursive: ";
	g.DFS_Traversal(2);

	cout << "\n";
	cout << "Note that both DFS versions are correct!!! Draw the stack!\n";
	cout << "In recursive DFS, I've added some code in order to get the same result!\n";

	return 0; 
} 

#include <bits/stdc++.h>

using namespace std;

/*
All nodes have 0, 1, or multiple parent given the realitionship in pairs ((0,1),(1,2),(1,4)).
For example, (0,1) -> 0 is a parent of 1.

Find the node has no parent or exactly 1 parent.
*/

#define BLANK 0
#define DISCOVERED 1
#define VISITED 2

void buildGraph(unordered_map<int,list<int>>& graph, vector<vector<int>>& relations, unordered_map<int,int>& status){
    for (auto relation : relations){
        graph[relation[0]].push_back(relation[1]);
        graph[relation[1]] = {}; // VERY IMPORTANT, WHEN USING HASHMAP WITH DIRECTED GRAPH !!!
        status[relation[0]] = BLANK;
        status[relation[1]] = BLANK;
    }
}

void topSort(unordered_map<int,list<int>>& graph, int node, stack<int>& topSortElements, unordered_map<int,int>& status){
    status[node] = DISCOVERED;

    for (int neighbor : graph[node]){
        if (status[neighbor] == BLANK)
            topSort(graph, neighbor, topSortElements, status);
    }

    topSortElements.push(node);
    status[node] = VISITED;
}

void printGraph(unordered_map<int,list<int>>& graph){
    for (auto elem : graph){
        cout << elem.first << ": ";
        for (int i:elem.second)
            cout << i << " ";
        cout << endl;
    }
}

int getNodeWithNoParent(vector<vector<int>>& relations){
    if (relations.size() == 0)
        return 0;
    
    unordered_map<int,list<int>> graph;
    unordered_map<int,int> status;
    buildGraph(graph, relations, status);

    stack<int> topSortElements;
    for (auto elem : graph){
        int node = elem.first;
        if (status[node] == BLANK){
            topSort(graph, node, topSortElements, status);
        }
    }
    
    int ans = topSortElements.top();
    cout << "Top Sort: ";
    while (!topSortElements.empty()){
        cout << topSortElements.top() << " ";
        topSortElements.pop();
    }
    cout << endl;
    return ans;
}
// Time: O(n)
// Space: O(n)

int main(){
    vector<vector<int>> relations = { {0,1},{1,2},{1,4} };
    cout << getNodeWithNoParent(relations) << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        // build graph
        unordered_map<int,vector<pair<int,int>>> graph;
        buildGraph(graph,n,flights);
        
        
        // for (auto elem: graph){
        //     cout << "[" << elem.first << "]: ";
        //     for (auto i:elem.second)
        //         cout << "<" << i.first << ", " << i.second << "> ";
        //     cout << endl;
        // }
        
        
        // dfs
        unordered_set<int> visited;
        int minCost = INT_MAX;
        dfs(graph,visited,src,dst,K,0,minCost);
        
        return minCost == INT_MAX ? -1 : minCost;
    }
    
    void buildGraph (unordered_map<int,vector<pair<int,int>>>& graph, int n, vector<vector<int>>& flights){
        for (int i=0;i<flights.size();i++){
            int node = flights[i][0];
            int neigh = flights[i][1];
            int distance = flights[i][2];
            graph[node].push_back({neigh,distance});
        }
    }
    
    void dfs(unordered_map<int,vector<pair<int,int>>>& graph, unordered_set<int>& visited, int node, int dst, int k, int currCost, int& minCost){
        if (k < -1)
            return;
        
        if (node == dst){
            minCost = min(minCost,currCost);
            return;
        }
        
        if (currCost >= minCost)
            return;
        
        visited.insert(node);        
        for (auto neigh:graph[node]){
            int neighbor = neigh.first;
            int distance = neigh.second;
            if (visited.find(neighbor) == visited.end()) // not found
                dfs(graph,visited,neighbor,dst,k-1,currCost+distance,minCost);
        }    
        
        visited.erase(node); // restore the state of the recursion, since we're trying every possible path to dst
        
    }
};
// Time: O(n)
// Space: O(k)

int main(){
    int n = 3; 
    vector<vector<int>> edges = {{0,1,100},{1,2,100},{0,2,500}};
    int src = 0, dst = 2, k = 0;

    Solution sol;
    cout << sol.findCheapestPrice(n,edges,src,dst,k) << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
v    v
0--->1
|    |
v    v
2--->3
    
path: 0,1,3

    
dfs(0):
    dfs(1):
        dfs(3): ok
            


    dfs(2):
    
    
ans: [0,1,3]

*/

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if (graph.size() == 0)
            return {};
        
        int begin = 0;
        int end = graph.size()-1;
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> visited(end+1,false);
        dfs(graph,begin,end,path,ans,visited);
        
        return ans;
    }
    
    void dfs(vector<vector<int>>& graph, int node, int end, vector<int>& path,vector<vector<int>>& ans, vector<bool>& visited){
        path.push_back(node);
        visited[node] = true;
        
        if (node == end){
            ans.push_back(path);
            visited[end] = false;
            path.pop_back();
            return;
        }
        
        for (int neighbor:graph[node]){
            if (!visited[neighbor])
                dfs(graph,neighbor,end,path,ans,visited);
        }
        
        visited[node] = false;
        path.pop_back();
    }
};

// Time: O(n)
// Space: O(n)

int main(){
    vector<vector<int>> graph = {
        {1,2}, {3}, {3}, {} 
    };

    Solution sol;
    vector<vector<int>> ans = sol.allPathsSourceTarget(graph);

    for (auto path:ans){
        cout << "[ ";
        for (int n:path)
            cout << n << " ";
        cout << "]";
        cout << endl;
    }

    return 0;
}

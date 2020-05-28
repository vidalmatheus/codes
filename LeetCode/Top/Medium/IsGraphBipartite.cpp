#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class WrongSolution {
private:
    static const int BLUE = 0;
    static const int RED = 1;
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if (graph.size()==0)
            return false;
        
        vector<int> color(graph.size(),-1);
        vector<bool> visited(graph.size(),false);
        
        for (int i=0;i<graph.size();i++){
            if (!visited[i]){
                int colorCounter = BLUE;
                dfs(graph,i,visited,color,colorCounter);
            }
        }
        
        for (int i=0;i<color.size();i++){
            for (int j=i+1;j<color.size();j++){
                if (areNeighbours(graph,i,j) && color[i] == color[j])
                    return false;
            }
        }
        
        return true;
    }
    
    void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited, vector<int>& color, int& colorCounter){
        visited[node] = true;
        color[node] = colorCounter%2;
        
        for (int i=0;i<graph[node].size();i++){
            int neighbour = graph[node][i];
            if (!visited[neighbour])
                dfs(graph,neighbour,visited,color,++colorCounter);   
        }
    }
    
    bool areNeighbours(vector<vector<int>>& graph, int node1, int node2){
        for (int i=0;i<graph[node1].size();i++){
            if (graph[node1][i] == node2)
                return true;
        }
        
        return false;
    }
};

class NotGoodSolution {
private:
    static const int BLUE = 0;
    static const int RED = 1;
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if (graph.size()==0)
            return false;
        
        vector<int> color(graph.size(),-1);
        vector<bool> visited(graph.size(),false);
        
        for (int i=0;i<graph.size();i++){
            if (!visited[i]){
                int colorCounter = BLUE;
                bfs(graph,i,visited,color,colorCounter);
            }
        }
        
        for (int i=0;i<color.size();i++){
            for (int j=i+1;j<color.size();j++){
                if (areNeighbours(graph,i,j) && color[i] == color[j])
                    return false;
            }
        }
        
        return true;
    }
    
    void bfs(vector<vector<int>>& graph, int startNode, vector<bool>& visited, vector<int>& color, int& colorCounter){
        queue<int> q;
        q.push(startNode);
        int currColor = BLUE;
        while (!q.empty()){
            int size = q.size();
            for (int j=0;j<size;j++){
                int node = q.front();
                color[node] = currColor;
                visited[node] = true;
                q.pop();
                for (int i=0;i<graph[node].size();i++){
                    int neighbour = graph[node][i];
                    if (!visited[neighbour])
                        q.push(neighbour);
                }                
            }
            ++currColor%=2;
        }
    }
    
    bool areNeighbours(vector<vector<int>>& graph, int node1, int node2){
        for (int i=0;i<graph[node1].size();i++){
            if (graph[node1][i] == node2)
                return true;
        }
        
        return false;
    }
};
// Time: O(n^2)
// Space: O(n)

class Solution {
private:
    static const int BLUE = 0;
    static const int RED = 1;
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if (graph.size()==0)
            return false;
        
        vector<int> color(graph.size(),-1);
        vector<bool> visited(graph.size(),false);
        
        for (int i=0;i<graph.size();i++){
            if (!visited[i]){
                int colorCounter = BLUE;
                if (!bfs(graph,i,visited,color,colorCounter))
                    return false;
            }
        }
        
        return true;
    }
    
    bool bfs(vector<vector<int>>& graph, int startNode, vector<bool>& visited, vector<int>& color, int& colorCounter){
        queue<int> q;
        q.push(startNode);
        int currColor = BLUE;
        while (!q.empty()){
            int size = q.size();
            for (int j=0;j<size;j++){
                int node = q.front();
                color[node] = currColor;
                visited[node] = true;
                q.pop();
                for (int i=0;i<graph[node].size();i++){
                    int neighbour = graph[node][i];
                    if (!visited[neighbour])
                        q.push(neighbour);
                    else if(color[node]==color[neighbour])
                        return false;
                }                
            }
            ++currColor%=2;
        }
        return true;
    }
};
// Time: O(n+m)
// Space: O(n)

int main(){
    vector<vector<int>> graph{{4},{},{4},{4},{0,2,3}};

    Solution sol;
    sol.isBipartite(graph) ? cout << "true\n" : cout << "false\n";

    return 0;
}

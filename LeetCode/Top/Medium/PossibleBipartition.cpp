#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class WrongSolution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        if (N==1)
            return true;
        if (dislikes.size()==0)
            return true;
        
        
        unordered_map<int,unordered_set<int>> dislikesMap;
        for (int i=0;i<dislikes.size();i++){
            dislikesMap[dislikes[i][0]].insert(dislikes[i][1]);
            dislikesMap[dislikes[i][1]].insert(dislikes[i][0]);
        }
        
        for (auto elem:dislikesMap){
            cout << elem.first << ": ";
            for (auto e:dislikesMap[elem.first])
                cout << e << " ";
            cout << endl;
        }
        
        unordered_set<int> groupA;
        unordered_set<int> groupB;
        for (int i=1;i<=N;i++){
            if (isPossible2Insert(dislikesMap,i,groupA))
                groupA.insert(i);
            else if (isPossible2Insert(dislikesMap,i,groupB))
                groupB.insert(i);   
            else return false;
        }
        
        return true;    
    }

    bool isPossible2Insert(unordered_map<int,unordered_set<int>>& dislikesMap, int num, unordered_set<int>& group){
        if (group.size()==0) // not found
            return true;
        for (auto elem:dislikesMap[num])
            if (group.find(elem)!=group.end()) // found
                return false;
        return true;
    }    
};

class Solution {
private:
    const int BLANK = -1;
    const int RED = 0;
    const int BLUE = 1;
    
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        // edge cases
        if (N==1)
            return true;
        if (dislikes.size()==0)
            return true;
        
        // build graph
        vector<int> color(N+1,BLANK);
        unordered_map<int,vector<int>> graph;
        buildGraph(graph,dislikes);
        
        // color the graph
        vector<bool> visited(N+1,false);
        for (int i=1;i<=N;i++){
            if (!visited[i]){
                int colorCounter = RED;
                if (!bfsColor(graph,i,visited,color))
                    return false;
            }
        }
        
        return true;
    }
    
    void buildGraph(unordered_map<int,vector<int>>& graph, vector<vector<int>>& dislikes){
        for (int i=0;i<dislikes.size();i++){
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
    }
    
    bool bfsColor(unordered_map<int,vector<int>>& graph, int start, vector<bool>& visited, vector<int>& color){
        if (graph.size() == 0)
            return {};
        queue<int> q;
        q.push(start);
        int currColor = RED;
        while (!q.empty()){
            int size = q.size();
            for (int i=0;i<size;i++){
                int node = q.front();
                q.pop();
                if (color[node] == BLANK)
                    color[node] = currColor;
    
                visited[node] = true;
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
// Time: O(N+M), where M is the size of dislikes
// Space: O(N)

int main(){
    int N = 3;
    vector<vector<int>> dislikes{
        {1,2},
        {1,3},
        {2,4}
    };

    Solution sol;
    sol.possibleBipartition(N,dislikes) ? cout << "true\n" : cout << "false\n";

    return 0;
}

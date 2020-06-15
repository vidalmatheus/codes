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
    int shortestBridge(vector<vector<int>>& A) {
        // identify these two islands (DFS)    
        vector<vector<bool>> visited(A.size(),vector<bool>(A[0].size(),false));
        bool done = false;
        for (int i=0;i<A.size();++i){
            for (int j=0;j<A[0].size();++j){
                if (A[i][j] == 1 && !visited[i][j]){
                    dfs(A,visited,i,j,2);
                    done = true;
                    break;
                }
            }
            if (done) // I just need to paint one island
                break;
        }            
        
        // BFS to return the shortest path between them
        fill(visited.begin(), visited.end(), vector<bool>(A[0].size(),false));
        return bfs(A,visited,1,2);
    }
      
    void dfs(vector<vector<int>>& A, vector<vector<bool>>& visited, int i, int j, int val){
        if (isOuttaBounds(A,i,j) || A[i][j] == 0 || visited[i][j])
            return;
        
        A[i][j] = val;
        visited[i][j] = true;
        
        dfs(A,visited,i-1,j,val);
        dfs(A,visited,i+1,j,val);
        dfs(A,visited,i,j-1,val);
        dfs(A,visited,i,j+1,val);
    }
    
    bool isOuttaBounds(vector<vector<int>>& A, int i, int j){
        if (i<0 || j<0 || i>=A.size() || j>=A[0].size())
            return true;
        return false;
    }
    
    int bfs(vector<vector<int>>& A, vector<vector<bool>>& visited, int startIsland, int lastIsland){
        queue<pair<int,int>> q;
        
        // multiple source nodes
        for (int i=0;i<A.size();++i){
            for (int j=0;j<A[0].size();++j){
                if (A[i][j] == startIsland)
                    q.push({i,j});
            }
        }
        
        int level = -1;
        int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
        while (!q.empty()){
            int size = q.size();
            for (int i=0;i<size;++i){
                pair<int,int> node = q.front();
                q.pop();
                if (A[node.first][node.second] == lastIsland)
                    return level;

                // add neighbors
                for (int k=0;k<4;++k){
                    pair<int,int> neighbor = {node.first + dir[k][0], node.second + dir[k][1]};
                    if (!isOuttaBounds(A,neighbor.first,neighbor.second) && !visited[neighbor.first][neighbor.second]){
                        visited[neighbor.first][neighbor.second] = true;
                        q.push(neighbor);
                    }
                }   
            }
            
            level++;
        }
        
        return -1;
    }
};
// Time: O(n*m)
// Space: O(n*m)

int main(){

    vector<vector<int>> A{
        {1,1,1,1,1},
        {1,0,0,0,1},
        {1,0,1,0,1},
        {1,0,0,0,1},
        {1,1,1,1,1}
    };

    Solution sol;
    cout << sol.shortestBridge(A) << endl;

    return 0;
}
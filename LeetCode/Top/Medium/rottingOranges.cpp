#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define  endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        
        int minMinutes = bfs(grid);           
        for (int i=0;i<grid.size();i++)
            for (int j=0;j<grid[0].size();j++)
                if (grid[i][j] == 1)
                    return -1;
    
        return minMinutes;    
    }
    
    bool isValid(vector<vector<int>>& grid, int i, int j){
        return i>=0 && j>=0 && i<grid.size() && j<grid[0].size();
    }
    
    int bfs(vector<vector<int>>& grid){
        
        queue<pair<int,int>> q;
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        
        int minMinutes = -1;
        while (!q.empty()){
            int size = q.size();
            for (int m=0;m<size;m++){
                pair<int,int> curr = q.front();
                q.pop();
                int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
                for (int k=0;k<4;k++){
                    int next_i = curr.first + dir[k][0];
                    int next_j = curr.second + dir[k][1];
                    if (isValid(grid,next_i,next_j) && grid[next_i][next_j] == 1){
                        grid[next_i][next_j] = 2; // turn this orange into a rotten one
                        q.push({next_i,next_j});
                    }
                }
            }
            minMinutes++;
        }
        
        return minMinutes == -1 ? 0 : minMinutes;
    }
};
// Time: O(n*m)
// Space: O(n+m)

int main(){
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};

    Solution sol;

    assert (sol.orangesRotting(grid) == 4);

    cout << "Passed!" << endl;

    return 0;
}

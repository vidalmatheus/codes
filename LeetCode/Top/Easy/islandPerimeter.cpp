#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
    
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j] == 1)
                    return dfs(grid,i,j);
            }
        }        
            
        return 0;
    }
    
    bool valid(vector<vector<int>>& grid, int i, int j){
        return i>=0 && j>=0 && i<grid.size() && j<grid[0].size();
    }
    
    int dfs(vector<vector<int>>& grid, int i, int j){
        if (!valid(grid,i,j) || grid[i][j] == 0)
            return 1;
        
        if (grid[i][j] == -1)
            return 0;
        
        int prev = grid[i][j];
        grid[i][j] = -1; // used
        
        int counter = 0;
        int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
        for (int k=0;k<4;k++){
            int ni = i + dir[k][0];
            int nj = j + dir[k][1];
            counter += dfs(grid,ni,nj);
        }
        
        // grid[i][j] = prev; // restore the grid -> this will cause overcounting, because we can't use a number more than once -> use visited matrix to work around this problem
        return counter;
    }
};
// Time: O(n*m)
// Space: O(n+m)

int main(){
    vector<vector<int>> grid{
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };

    Solution sol;
    cout << sol.islandPerimeter(grid) << endl;

    return 0;
}

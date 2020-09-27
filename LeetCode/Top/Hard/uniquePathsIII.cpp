#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

    
/*

[1,0,0,0],
[0,0,0,0],
[0,0,2,-1]

1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

*/

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        
        int zerosLeft = 0;
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j] == 0){
                    zerosLeft++;
                }
            }
        }
        
        int ans = 0;
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j] == 1){
                    dfs(grid,i,j,zerosLeft,ans);
                    break;
                }
            }
        }
        
        return ans;
    }
    
    bool valid(vector<vector<int>>& grid, int i, int j){
        return i>=0 && j>=0 && i<grid.size() && j<grid[0].size();
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int zerosLeft, int& ans){
        if (!valid(grid,i,j) || grid[i][j] == -1 || grid[i][j] == 3)
            return;
        
        if (grid[i][j] == 2){
            if (zerosLeft == 0)
                ans++;
            return;
        }
        
        if (grid[i][j] == 0)
            zerosLeft--;
        
        int tmp = grid[i][j];
        grid[i][j] = 3;
        
        int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
        for (int k=0;k<4;k++){
            int next_i = i + dir[k][0];
            int next_j = j + dir[k][1];
            dfs(grid,next_i,next_j,zerosLeft,ans);
        }
        
        grid[i][j] = tmp; // in order to reuse squares in the backtracking
    }
};
// Time: O(n*m)
// Space: O(n+m)

int main(){
    Solution sol;

    vector<vector<int>> grid1{
        {1,0,0,0},
        {0,0,0,0},
        {0,0,2,-1}
    };
    assert(sol.uniquePathsIII(grid1) == 2);

    vector<vector<int>> grid2{
        {1,0,0,0},
        {0,0,0,0},
        {0,0,0,2}
    };
    assert(sol.uniquePathsIII(grid2) == 4);

    vector<vector<int>> grid3{
        {0,1},
        {2,0}
    };
    assert(sol.uniquePathsIII(grid3) == 0);
    cout << "Passed!" << endl;
    return 0;
}
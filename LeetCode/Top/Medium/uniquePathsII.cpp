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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        if (m==0 || n==0 || obstacleGrid[0][0])
            return 0;
        
        vector<vector<unsigned int>> dp(n,vector<unsigned int>(m));
        dp[0][0]=1;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (i>=1 && !obstacleGrid[i][j])
                    dp[i][j]+=dp[i-1][j];
                if (j>=1 && !obstacleGrid[i][j])
                    dp[i][j]+=dp[i][j-1];
            }
        }
        
        return dp[n-1][m-1];
    }
};
// Time: O(n^2)
// Space: O(n^2)

class MemoSolution {
private:
    vector<vector<int>> memo;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0)
            return 0;
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        memo.resize(m,vector<int>(n,-1));
        
        return rec(obstacleGrid,0,0);
    }
    
    int rec(vector<vector<int>>& grid, int i, int j){    
        if (i == grid.size() || j == grid[0].size())
            return 0;
        
        if (grid[i][j] == 1)
            return 0;
        
        if (i == grid.size()-1 && j == grid[0].size()-1)
            return 1;
        
        if (memo[i][j] != -1)
            return memo[i][j];
        
        return memo[i][j] = rec(grid,i+1,j) + rec(grid,i,j+1);
    }
};
// Time: O(m*n)
// Space: O(m*n)

int main(){
    vector<vector<int>> obstacleGrid = {
      {0,0,0},
      {0,1,0},
      {0,0,0}  
    };

    Solution sol;
    cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}
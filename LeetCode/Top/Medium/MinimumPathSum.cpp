#include <bits/stdc++.h>

using namespace std;

static auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size()==0) 
            return 0;
        vector<vector<int>> dp(grid.size());
        for (int i=0;i<dp.size();i++){
            dp[i].resize(grid[0].size());
        }
        
        for (int i=0;i<dp.size();i++){
            for (int j=0;j<dp[0].size();j++){
                dp[i][j]+=grid[i][j];
                if (i>0 && j>0)
                    dp[i][j]+=min(dp[i][j-1],dp[i-1][j]);
                else if (i>0)
                    dp[i][j]+=dp[i-1][j];
                else if (j>0)
                    dp[i][j]+=dp[i][j-1];
            }
        }

        // Tracing
        stack<int> s;
        s.push(grid[grid.size()-1][grid[0].size()-1]);
        for (int i=grid.size()-1;i>0;){
            for (int j=grid[i].size()-1;j>0;){
                if (i>0 && j>0){
                    if (grid[i][j-1]<grid[i-1][j]){
                        s.push(grid[i][j-1]);
                        j--;
                    }
                    else{
                        s.push(grid[i-1][j]);
                        i--;
                    } 
                }
                else if (i>0){
                    s.push(grid[i-1][j]);
                    i--;
                }
                else if (j>0){
                    s.push(grid[i][j-1]);
                    j--;
                }
            }
        }
        while (!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
        return dp[dp.size()-1][dp[0].size()-1];
    }
};

int main(){
/*     
  [1,3,1]
  [1,5,1]
  [4,2,1]
*/
    vector<vector<int>> grid = { {1,3,1},{1,5,1},{4,2,1}};

    for (int i=0;i<grid.size();i++){
        for (int j=0;j<grid[i].size();j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    Solution sol;
    cout << sol.minPathSum(grid) << endl;

    return 0;
}
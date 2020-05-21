#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
private:
    vector<vector<int>> dp;
public:
    int countSquares(vector<vector<int>>& matrix) {
        dp.resize(matrix.size(),vector<int>(matrix[0].size(),-1));
        
        int counter = 0;
        for (int i=0;i<dp.size();i++){
            dp[i][0] = matrix[i][0];
            counter += dp[i][0];
        }
        
        for (int j=1;j<dp[0].size();j++){
            dp[0][j] = matrix[0][j];
            counter += dp[0][j];
        }
        
        for (int i=1;i<matrix.size();i++){
            for (int j=1;j<matrix[0].size();j++){
                if (matrix[i][j]==1){
                    dp[i][j] = 1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
                    counter += dp[i][j];
                }
                else dp[i][j] = 0;
            }
        }
        
        return counter;
    }
};
// Time: O(m*n)
// Space: O(m*n)

int main(){
    vector<vector<int>> matrix{
        {0,1,1,1},
        {1,1,1,1},
        {0,1,1,1}
    };

    Solution sol;
    cout << sol.countSquares(matrix) << endl;

    return 0;
}

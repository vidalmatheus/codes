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
    int uniquePaths(int m, int n) {
        if (m==0 || n==0)
            return 0;
        
        vector<vector<int>> dp(n,vector<int>(m));
        dp[0][0]=1;
        for (int i=0;i<dp.size();i++){
            for (int j=0;j<dp[0].size();j++){
                if (i>=1)
                    dp[i][j]+=dp[i-1][j];
                if (j>=1)
                    dp[i][j]+=dp[i][j-1];
            }
        }
        
        return dp[n-1][m-1];
    }
};
// Time: O(n^2)
// Space: O(n^2)

int main(){
    int m = 7;
    int n = 3;

    Solution sol;
    cout << sol.uniquePaths(m,n) << endl;

    return 0;
}
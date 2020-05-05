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
    int maxProfit(vector<int>& prices) {
        return maxProfit(2,prices);
    }
    
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size()==0 || k==0)
            return 0;
        
        if (k>prices.size()/2)
            return maxProfitUnlimited(prices);
        
        vector<vector<int>> dp(k+1,vector<int>(prices.size(),0));
        for (int i=1;i<dp.size();i++){
            int maxBefore = INT_MIN;
            for (int j=1;j<dp[0].size();j++){
                maxBefore = max(maxBefore,dp[i-1][j-1] - prices[j-1]);
                dp[i][j] = max(dp[i][j-1],prices[j]+maxBefore);
            }
        }
        
        return dp[k][prices.size()-1];
    }
    
    int maxProfitUnlimited(vector<int>& prices) {
        int ans = 0;
        for (int i=1;i<prices.size();i++)
            ans += max(0,prices[i]-prices[i-1]);

        return ans;
    }
    
};
// Time: O(n)
// Space: O(n)

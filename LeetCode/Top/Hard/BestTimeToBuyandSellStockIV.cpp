#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class FirstSolution { // Out of memory
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size()==0 || k==0)
            return 0;
        
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
};
// Time: O(n*k)
// Space: O(n*k)

class TLESolution { // Time Limit Exceeded
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size()==0 || k==0)
            return 0;
        
        vector<int> curr(prices.size(),0);
        for (int i=1;i<k+1;i++){
            vector<int> prev(curr);
            int maxBefore = INT_MIN;
            for (int j=1;j<prices.size();j++){
                maxBefore = max(maxBefore,prev[j-1] - prices[j-1]);
                curr[j] = max(curr[j-1],prices[j]+maxBefore);
            }
            
        }
        
        return curr[prices.size()-1];
    }
};
// Time: O(n^2k)
// Space: O(n)

class OTHERSolution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size()==0 || k==0)
            return 0;
        
        vector<int> buy(k+1,INT_MIN); // buy[i]: profit with i times (buy or not the current stock)
        vector<int> sell(k+1,0); // sell[i]: profit with i times (sell or not the current stock)
        
        for (int priceToday:prices){
            buy[1] = max(buy[1],-priceToday);
            sell[1] = max(sell[1],buy[1]+priceToday);
            
            for (int i=2;i<k+1;i++){
                buy[i] = max(buy[i],sell[i-1]-priceToday);
                sell[i] = max(sell[i],buy[i]+priceToday);
            }
        }
        
        return sell[k];
    }
};
// Time: O(n*k)
// Space: O(n)

class Solution {
public:
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
// Time: O(n*k)
// Space: O(n*k)

int main(){
    vector<int> prices{5,11,3,50,60,90};
    int k = 2;

    Solution sol;
    cout << sol.maxProfit(k,prices) << endl;

    return 0;
}

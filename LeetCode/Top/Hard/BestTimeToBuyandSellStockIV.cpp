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

class MemoizationSolution {
private:
    vector<vector<vector<vector<int>>>> memo;
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        
        int n = prices.size();
        int states = 2;
        memo.resize(n, vector<vector<vector<int>>>(states, vector<vector<int>>(k+1, vector<int>(k+1,-1))));

        return rec(prices,0,0,0,0,k);
    }
    
    int rec(vector<int>& prices, int pos, int state, int buy, int sell, int k){
        if (pos == prices.size())
            return 0;
        
        if (buy == k && sell == k)
            return 0;
        
        if (memo[pos][state][buy][sell] != -1)
            return memo[pos][state][buy][sell];
        
        if (state == 0)
            return memo[pos][state][buy][sell] = max( rec(prices,pos+1,0,buy,sell,k), rec(prices,pos+1,1,buy+1,sell,k)-prices[pos] );
        else // state == 1
            return memo[pos][state][buy][sell] = max( rec(prices,pos+1,1,buy,sell,k), rec(prices,pos+1,0,buy,sell+1,k)+prices[pos] );
    }
};
// Time: O(n*k^2)
// Space: O(n*k^2)

class Solution {
private:
    vector<vector<vector<int>>> memo;
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        
        if (k>prices.size()/2)
            return maxProfitUnlimited(prices);
        
        int n = prices.size();
        int states = 2;
        memo.resize(n,vector<vector<int>>(states, vector<int>(k+1,-1)));

        return rec(prices,0,0,k);
    }
    
    int rec(vector<int>& prices, int pos, int state, int k){
        if (pos == prices.size())
            return 0;
        
        if (k == 0)
            return 0;
        
        if (memo[pos][state][k] != -1)
            return memo[pos][state][k];
        
        if (state == 0)
            return memo[pos][state][k] = max( rec(prices,pos+1,0,k), rec(prices,pos+1,1,k)-prices[pos] );
        else  // state == 1
            return memo[pos][state][k] = max( rec(prices,pos+1,1,k), rec(prices,pos+1,0,k-1)+prices[pos] );
    }
    
        
    int maxProfitUnlimited(vector<int>& prices) { // O(n)
        int ans = 0;
        for (int i=1;i<prices.size();i++)
            ans += max(0,prices[i]-prices[i-1]);

        return ans;
    }
};
// Time: O(n*k*states) -> O(n*k)
// Space: O(n*k)

int main(){
    vector<int> prices{5,11,3,50,60,90};
    int k = 2;

    Solution sol;
    cout << sol.maxProfit(k,prices) << endl;

    return 0;
}

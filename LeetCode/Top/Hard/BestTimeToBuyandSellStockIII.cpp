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

class RecursiveSolution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        
        return rec(prices,0,0,0,0);
    }
    
    int rec(vector<int>& prices, int pos, int state, int buy, int sell){
        if (pos == prices.size())
            return 0;
        
        if (buy == 2 && sell == 2)
            return 0;
        
        if (state == 0)
            return max( rec(prices,pos+1,0,buy,sell), rec(prices,pos+1,1,buy+1,sell)-prices[pos] );
        else // state == 1
            return max( rec(prices,pos+1,1,buy,sell), rec(prices,pos+1,0,buy,sell+1)+prices[pos] );
    }
};
// Time: O(2^n)
// Space: O(n)

class MemoizationSolution {
private:
    vector<vector<vector<vector<int>>>> memo;
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        
        int n = prices.size();
        int k = 2;
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
// Time: O(n*k^2*states) -> O(n)
// Space: O(n*k^2)

class Solution {
private:
    vector<vector<vector<int>>> memo;
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        
        int n = prices.size();
        int states = 2;
        int k = 2;
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
};
// Time: O(n*k*states) -> O(n*k)
// Space: O(n*k)

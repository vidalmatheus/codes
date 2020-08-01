#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class MemoizationSolution { // memoty limit exceeded
private:
    vector<vector<vector<vector<int>>>> memo;
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.size() == 0)
            return 0;
        
        int n = prices.size();
        int states = 2;
        int k = n/2;
        memo.resize(n, vector<vector<vector<int>>>(states, vector<vector<int>>(k+1, vector<int>(k+1,-1))));

        return rec(prices,0,0,0,0,fee);
    }
    
    int rec(vector<int>& prices, int pos, int state, int buy, int sell, int fee){
        if (pos == prices.size())
            return 0;
        
        if (memo[pos][state][buy][sell] != -1)
            return memo[pos][state][buy][sell];
        
        if (state == 0)
            if (buy+1 == sell)
                return memo[pos][state][buy][sell] = max( rec(prices,pos+1,0,buy,sell,fee), rec(prices,pos+1,1,buy+1,sell,fee)-prices[pos]-fee );
            else return memo[pos][state][buy][sell] = max( rec(prices,pos+1,0,buy,sell,fee), rec(prices,pos+1,1,buy+1,sell,fee)-prices[pos] );
        else { // state == 1
            if (buy == sell+1)
                return memo[pos][state][buy][sell] = max( rec(prices,pos+1,1,buy,sell,fee), rec(prices,pos+1,0,buy,sell+1,fee)+prices[pos]-fee );
            else return memo[pos][state][buy][sell] = max( rec(prices,pos+1,1,buy,sell,fee), rec(prices,pos+1,0,buy,sell+1,fee)+prices[pos] );
        }
    }
};
// Time: O(n*k^2)
// Space: O(n*k^2)

class Solution {
private:
    vector<vector<int>> memo;
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.size() == 0)
            return 0;
        
        memo.resize(prices.size(),vector<int>(2,-1));
        
        return rec(prices,0,0,fee);
    }
    
    int rec(vector<int>& prices, int pos, int state, int fee){
        if (pos == prices.size())
            return 0;
        
        if (memo[pos][state] != -1)
            return memo[pos][state];
        
        if (state == 0)
            return memo[pos][state] = max( rec(prices,pos+1,0,fee), rec(prices,pos+1,1,fee)-prices[pos] );
        else // state == 1
            return memo[pos][state] = max( rec(prices,pos+1,1,fee), rec(prices,pos+1,0,fee)+prices[pos]-fee );
    }
};
// Time: O(n)
// Space: O(n)

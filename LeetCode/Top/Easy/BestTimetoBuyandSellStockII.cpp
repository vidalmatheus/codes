#include <bits/stdc++.h>

using namespace std;

auto speedup=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class FirstSolution {
public:
    int maxProfit(vector<int>& prices) {
        int index_min, index_max;
        index_max = 1, index_min =  0;
        int profit, profit_sum = 0;
        while(index_min<prices.size() && index_max<prices.size()){
            profit = -prices[index_min] + prices[index_max];
            if (profit>0){
                profit_sum+=profit;
            } 
            index_min = index_max;
            index_max++;
        }
        return profit_sum;
    }
};
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i=1;i<prices.size();i++)
            ans += max(0,prices[i]-prices[i-1]);

        return ans;
    }
};
// Time: O(n)
// Space: O(1)

class MemoizationSolution {
private:
    vector<vector<int>> memo;
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        
        memo.resize(prices.size(),vector<int>(2,-1));
        
        return rec(prices,0,0);
    }
    
    int rec(vector<int>& prices, int pos, int state){
        if (pos == prices.size())
            return 0;
        
        if (memo[pos][state] != -1)
            return memo[pos][state];
        
        if (state == 0)
            return memo[pos][state] = max( rec(prices,pos+1,0), rec(prices,pos+1,1)-prices[pos] );
        else // state == 1
            return memo[pos][state] = max( rec(prices,pos+1,1), rec(prices,pos+1,0)+prices[pos] );
    }
};
// Time: O(n)
// Space: O(n)

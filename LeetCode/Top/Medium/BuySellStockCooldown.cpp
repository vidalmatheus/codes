#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class RecursiveSolution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        
        return rec(prices,0,0);
    }
    
    int rec(vector<int>& prices, int pos, int state){
        if (pos == prices.size())
            return 0;
        
        if (state == 0)
            return max( rec(prices,pos+1,1)-prices[pos], rec(prices,pos+1,0) );
        else if (state == 1)
            return max( rec(prices,pos+1,2)+prices[pos], rec(prices,pos+1,1) );
        else // state == 2
            return rec(prices,pos+1,0);
    }
};
// Time: O(2^n)
// Space: O(n)

class Solution { // memoization
private:
    vector<vector<int>> memo;
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        
        memo.resize(prices.size(),vector<int>(3,-1));
        
        return rec(prices,0,0);
    }
    
    int rec(vector<int>& prices, int pos, int state){
        if (pos == prices.size())
            return 0;
        
        if (memo[pos][state] != -1)
            return memo[pos][state];
        
        if (state == 0)
            return memo[pos][state] = max( rec(prices,pos+1,1)-prices[pos], rec(prices,pos+1,0) );
        else if (state == 1)
            return memo[pos][state] = max( rec(prices,pos+1,2)+prices[pos], rec(prices,pos+1,1) );
        else // state == 2
            return memo[pos][state] = rec(prices,pos+1,0);
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    vector<int> prices{1,2,3,0,2};

    Solution sol;
    cout << sol.maxProfit(prices) << endl;

    return 0;
}

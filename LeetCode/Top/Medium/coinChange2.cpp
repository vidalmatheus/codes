#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*

amount = 5, coins = [1, 2, 5]

rec(0,5):
    rec(1,4):

    rec(1,3): 
    
    rec(1,0): add

*/

class RecursiveSolution { // TLE
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0)
            return 1;
        
        set<vector<int>> ans;
        vector<int> curr;
        rec(ans,coins,amount,curr);
        
        return ans.size();
    }
    
    void rec(set<vector<int>>& ans, vector<int>& coins, int amount, vector<int>& curr){
        if (amount < 0)
            return;
        
        if (amount == 0){
            sort(curr.begin(),curr.end());
            ans.insert(curr);
            return;
        }
        
        for (int i=0;i<(int)coins.size();++i){
            curr.push_back(coins[i]);
            rec(ans,coins,amount-coins[i],curr);
            curr.pop_back();
        }    
    }
};
// Time: O(3^n * n*log^2(n))
// Space: O(amount)

/*
         0 1 2 3 4 5
[]       1 0 0 0 0 0
[1]      1 1 1 1 1 1   
[1,2]    1 1 2 2 3 3
[1,2,5]  1 1 2 2 3 4 

dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];

    0 1 2 3
[]  1 0 0 0
[2] 1 0 1 0

*/

class NormalSolution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int m = amount;
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        for (int i=0;i<=n;++i)
            dp[i][0] = 1;
        
        for (int j=1;j<=m;++j)
            dp[0][j] = 0;
        
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
                dp[i][j] = j-coins[i-1] >=0 ? dp[i-1][j] + dp[i][j-coins[i-1]] : dp[i-1][j];

        return dp[n][m];
    }
};
// Time: O(n*m)
// Space: O(n*m)

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);

        dp[0] = 1;

        for (int c:coins)
            for (int i=c;i<=amount;++i)
                dp[i] += dp[i-c];
        
        return dp[amount];
    }
};
// Time: O(n*m), actually it's be better than this
// Space: O(n)

int main(){
    int amount = 5;
    vector<int> coins{1,2,5};

    Solution sol;
    cout << sol.change(amount,coins) << endl;

    return 0;
}

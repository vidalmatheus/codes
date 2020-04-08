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
    int coinChange(vector<int>& coins, int amount, vector<int>& lastCoinUsed) {
        if (amount==0)
            return 0;
        
        vector<int> dp(amount+1);
        
        for (int i=1;i<dp.size();i++){
            dp[i]=amount+1;
        }
    
        for (int i=1;i<dp.size();i++){
            for (int j=0;j<coins.size();j++){
                int coin = coins[j];
                if (i>=coin){
                    dp[i]=min(dp[i-coin]+1,dp[i]);
                    lastCoinUsed[i]=j;
                }
            }
        }
        
        // if none of the coins was used, then coin change it's not possible
        return (dp.back()>amount) ? -1 : dp.back();
    }

    void traceCoinChange(vector<int>& coins, int amount, vector<int>& trace, vector<int>& lastCoinUsed){
        for (int i=amount;i>=0;i-=coins[lastCoinUsed[i]]){
            trace[lastCoinUsed[i]]++;
        }

        for (int i=0;i<trace.size();i++)
            cout << coins[i] << ": " << trace[i] << " coins" << endl;
    }

};
// Time: O(n*m), n: coins.size() and m: amount
// Space: O(m)

int main(){
    vector<int> coins = {1,2,5};
    int amount = 11;

    vector<int> lastCoinUsed(amount+1,-1);

    Solution sol;
    cout << "Minimum Amount of Coins: " << sol.coinChange(coins,amount,lastCoinUsed) << endl;

    vector<int> trace(coins.size(),0);
    sol.traceCoinChange(coins,amount,trace,lastCoinUsed);


    return 0;
}
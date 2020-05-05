#include <bits/stdc++.h>

using namespace std;

// To Speed Up
auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxProfit(vector<int>& prices) { // ---- Time: O(n) and Space: O(1)
        int minprice = INT_MAX;
        int maxprofit = 0;
        for (int i = 0; i < prices.size();i++){
            if (prices[i] < minprice) // if we find the minimum, we set new minmum
                minprice = prices[i];
            else if (prices[i]-minprice > maxprofit) 
                maxprofit = prices[i]-minprice; // otherwise, we find new maxprofit
        }
        return maxprofit;
    }   
};
// Time: O(n)
// Space: O(1)

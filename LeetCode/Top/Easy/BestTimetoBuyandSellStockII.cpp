#include <bits/stdc++.h>

using namespace std;

auto speedup=[](){
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

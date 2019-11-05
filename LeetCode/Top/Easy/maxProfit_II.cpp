/*Best Time to Buy and Sell Stock II
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int index_min, index_max;
        index_max = 1, index_min =  0;
        int profit, profit_sum = 0;
        while(index_min<prices.size() && index_max<prices.size()){ // vector size doesn't allow you to compare with negative values!!!! Unless you use cast 
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

int main(){
    vector<int> input = {7,1,5,3,6,4};
    //int v[] = {7,1,5,3,6,4};
    //vector<int> input = {7,6,4,3,1};
    Solution *obj = new Solution();
    //cout << input.capacity()*sizeof(int) << " " <<   sizeof(input) << endl;
    //cout << "Teste: " << max_element(input.begin()+2,input.end())-input.begin() << endl; // return the max element index
    int ans = obj->maxProfit(input);
    //cout << distance(input.begin(),min_element(input.begin(),input.end())) << endl;
    //cout << min_element(input.begin(),input.end())-input.begin() << endl;
    cout << "Profit: " << ans << endl;
    return 0;
}
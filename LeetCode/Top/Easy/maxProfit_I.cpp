/* Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

#include <bits/stdc++.h>

using namespace std;

// To Speed Up
auto speedup=[](){
    std::ios::sync_with_stdio(false);
    /*
    It toggles on or off the synchronization of all the C++ standard streams with their corresponding standard C streams 
    if it is called before the program performs its first input or output operation. 
    Adding ios_base::sync_with_stdio (false); (which is true by default) before any I/O operation avoids this synchronization. 
    It is a static member of function of std::ios_base.
    */
    cin.tie(NULL);
    cout.tie(NULL);
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
            else if (prices[i]-minprice > maxprofit) maxprofit = prices[i]-minprice; // otherwise, we find new maxprofit
        }
        return maxprofit;
    }   
};

int main(){
    vector<int> input = {7,1,5,3,6,4};
    //int v[] = {7,1,5,3,6,4}; 
    //vector<int> input = {7,6,4,3,1};
    Solution *obj = new Solution();
    //cout << input.capacity()*sizeof(int) << " " <<   sizeof(input) << endl;
    //cout << "Teste: " << max_element(input.begin()+2,input.end())-input.begin() << endl; // return the max element index
    //cout << distance(input.begin(),min_element(input.begin(),input.end())) << endl; // return the min element index
    int ans = obj->maxProfit(input);
    cout << "Profit: " << ans << endl;
    return 0;
}
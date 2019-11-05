#include <bits/stdc++.h>

using namespace std;

static int speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> dp;
    int climbStairsMEMO(int n) { // memoization technique (top-down approach)
        if (n+1>dp.size()){
            dp.clear();
            dp.resize(n+1,-1);
        } 
        if (n==0 || n==1) return dp[n]=1;
        if (dp[n]!=-1) return dp[n];
        return dp[n]=climbStairsMEMO(n-1)+climbStairsMEMO(n-2);
    }
    // Time: O(n)
    // Space: O(n)
    //----------------------
    int climbStairsDP(int n) { // dynamic programming (bottom-up approach)
        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        for (int i=2;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
    // Time: O(n)
    // Space: O(n)
    //--------------------
    int climbStairsREC(int n) { // pure recursion
        if (n==0 || n==1) return 1;
        return climbStairsREC(n-1)+climbStairsREC(n-2);
    }
    // Time: O(2^n)
    // Space: O(1)
};

int main(){
    Solution sol;
    cout << "Pure:" << endl;
    for (int i=0;i<45;i++)
        cout << sol.climbStairsREC(i) << endl;
    cout << "END" << endl;
    cin.get();
    cout << "Memoization (top-down)" << endl;
    for (int i=0;i<45;i++)
        cout << sol.climbStairsMEMO(i) << endl;
    cout << "END" << endl;
    cin.get();
    cout << "Dynamic Programming (bottom-up)" << endl;
    for (int i=0;i<45;i++)
        cout << sol.climbStairsDP(i) << endl;
    cout << "END" << endl;
    cin.get();
    return 0;
}
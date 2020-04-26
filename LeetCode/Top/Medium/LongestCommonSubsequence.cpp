#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*

dp[i][j] = text1[j-1] == text2[i-1] ? dp[i-1][j-1]+1 : max(dp[i-1][j],dp[i][j-1])

  # a b c d e
# 0 0 0 0 0 0  
a 0 1 1 1 1 1
c 0 1 1 2 2 2 
e 0 1 1 2 2 3

eca -> ace

ans: dp[text2.size()][text1.size()] = 3

*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size()==0 || text2.size()==0)
            return 0;
        
        vector<vector<int>> dp(text2.size()+1,vector<int>(text1.size()+1,0));
        
        for (int i=1;i<=text2.size();i++)
            for (int j=1;j<=text1.size();j++)
                dp[i][j] = text1[j-1] == text2[i-1] ? dp[i-1][j-1]+1 : max(dp[i-1][j],dp[i][j-1]);
        
        return dp[text2.size()][text1.size()];
    }
};
// Time: O(n*m)
// Space: o(n*m)

int main(){
    string text1 = "abcde";
    string text2 = "ace";

    Solution sol;
    cout << sol.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}

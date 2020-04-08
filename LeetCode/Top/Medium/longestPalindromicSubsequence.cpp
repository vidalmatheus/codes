#include <bits/stdc++.h>

using namespace std;

static int speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// Keywords: Longest <propriety> subsequence --> dp with sliding window
// CAUTION! WRONG SOLUTION(ALMOST RIGHT) It doeS not include odd-sized palindrome
// The correct solution is the following:
class Solution {    
public:
    int longestPalindromeSubseq(string s) {
        if (s.size()==0)
            return 0;
                
        vector<vector<int>> dp(s.size(),vector<int>(s.size()));
        for (int i=0;i<dp.size();i++){
            dp[i][i]=1;
        }
        
        return recursive(s,0,s.size()-1,dp);
    }
    
    int recursive(const string& s, int start, int end, vector<vector<int>>& dp){
        if (start>end)
            return 0;

        if (dp[start][end]!=0)
            return dp[start][end];
        else{
            if (s[start]==s[end])
                return dp[start][end] = 2+recursive(s,start+1,end-1,dp);
            else return dp[start][end] = max(recursive(s,start+1,end,dp),recursive(s,start,end-1,dp));
        } 
    }
};
// Time: O(n^2)
// Space: (n^2)

int main(){
    string s = "bbbab";

    Solution sol;
    cout << sol.longestPalindromeSubseq(s) << endl;

    return 0;
}

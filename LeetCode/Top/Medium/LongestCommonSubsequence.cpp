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
// Space: O(n*m)

/*
        i
    abcde
    
      j
    ace

rec(i,j):
    // base case
    if (i > s1.length() or j > s2.length())
        return 0;
    
    if (s1[i] == s2[j])
        return 1+rec(i+1,j+1);
    else return max(rec(i+1,j),rec(i,j+1));
    
    
rec(0,0): 1 + rec(1,1) = 3
    rec(1,1):
        rec(2,1): 1 + rec(3,2) = 2
            rec(3,2): max(rec(4,2), rec(3,3)) = 1
                rec(4,2): 1 + rec(5,3) = 1
                    rec(5,3) = 0
                    
                
                rec(3,3): 0
                
            
        rec(1,2): max(rec(2,2), rec(1,3)) =  1
            rec(2,2): max(rec(3,2), rec(2,3)) = 1
                rec(3,2): max(rec(4,2), rec(3,3)) = 1
                    rec(4,2): 1
                        
                        
                    rec(3,3): 0
                    
                    
                rec(2,3): 0
                
            
            rec(1,3): 0
*/

class TopDownSolution { // easy to come up with
private:
    vector<vector<int>> memo;
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        memo.resize(text1.size(),vector<int>(text2.size(),-1));
        
        return LCS(text1,text2,0,0);
    }
    
    int LCS(string& text1, string& text2, int i, int j){
        if (i >= text1.size() || j >= text2.size())
            return 0;
        
        if (memo[i][j] != -1)
            return memo[i][j];
        
        if (text1[i] == text2[j])
            return memo[i][j] = 1 + LCS(text1,text2,i+1,j+1);
        else return memo[i][j] = max(LCS(text1,text2,i+1,j), LCS(text1,text2,i,j+1));
    }
};
// Time: O(n*m)
// Space: O(n*m)


int main(){
    string text1 = "abcde";
    string text2 = "ace";

    Solution sol;
    cout << sol.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}

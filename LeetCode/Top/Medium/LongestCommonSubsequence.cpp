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
private:
    vector<vector<int>> dp;
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size()==0 || text2.size()==0)
            return 0;
        
        dp.resize(text2.size()+1,vector<int>(text1.size()+1,0));
        
        for (int i=1;i<=text2.size();i++)
            for (int j=1;j<=text1.size();j++)
                dp[i][j] = text1[j-1] == text2[i-1] ? dp[i-1][j-1]+1 : max(dp[i-1][j],dp[i][j-1]);
        
        return dp[text2.size()][text1.size()];
    }

    string LCS(string& text1, string& text2){
        string lcs = "";
        int i = 1;
        int j = 1;
        while (i < dp.size() && j < dp[0].size()){
            cout << i << ", " << j << endl;
            if (text2[i-1] == text1[j-1]){
                lcs.push_back(text2[i-1]);
                i++;
                j++;
            }
            else{
                if (i+1 == dp.size() || dp[i][j+1] > dp[i+1][j])
                    j++;
                else i++;
            }
        }

        return lcs;
    }

    string LCS(string& text1, string& text2, int len){ // Maybe this is a better way to trace the LCS
        string lcs = "";
        int i = dp.size()-1;
        int j = dp[0].size()-1;
        while (lcs.size() != len){
            if (text2[i-1] == text1[j-1]){
                lcs = text2[i-1] + lcs;
                i--;
                j--;
            }
            else{
                if (i-1 == 0 || dp[i][j-1] > dp[i-1][j])
                    j--;
                else i--;
            }
        }

        return lcs;
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
    int len = sol.longestCommonSubsequence(text1, text2);
    cout << len << endl;
    cout << sol.LCS(text1,text2,len) << endl;

    return 0;
}

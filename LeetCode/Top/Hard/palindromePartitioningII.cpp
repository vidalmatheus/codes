#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int minCut(string s) {
        if (s.size() == 0)
            return {};
        
        int ans = INT_MAX;
        rec(s,ans,0,0);
        
        return ans-1;
    }
    
    void rec(string& s, int& ans, int curr, int start){
        if (start == s.size()){
            ans = min(ans,curr);
            return;
        }
        
        for (int i=start;i<s.size();i++){
            int len = i-start+1;
            if (!isPalindrome(s.substr(start,len)))
                continue;
            rec(s,ans,curr+1,i+1);
        }
    }
    
    bool isPalindrome(string s){
        if (s.size() == 0)
            return true;
        for (int i=0,j=s.size()-1;i<j;i++,j--)
            if (s[i] != s[j])
                return false;
        return true;
    }
};
// Time: O(2^(n-1))
// Space: O(n)

class MemoSolution {
private:
    vector<int> memo;
public:
    int minCut(string s) {
        if (s.size() == 0)
            return {};
        
        memo.resize(s.size(),-1);
        
        return rec(s,0)-1;
    }
    
    int rec(string& s, int start){
        if (start == s.size())
            return 0;
        
        if (memo[start] != -1)
            return memo[start];
        
        int response = INT_MAX;
        for (int i=start;i<s.size();i++){
            int len = i-start+1;
            if (!isPalindrome(s.substr(start,len)))
                continue;
            response = min(response,1+rec(s,i+1));
        }
        
        return memo[start] = response;
    }
    
    bool isPalindrome(string s){ // O(n/2) && O(1)
        if (s.size() == 0)
            return true;
        for (int i=0,j=s.size()-1;i<j;i++,j--)
            if (s[i] != s[j])
                return false;
        return true;
    }
};
// Time: O(n^3)
// Space: O(n^3)

class FasterSolution {
private:
    vector<int> memo;
    vector<vector<bool>> palin;
public:
    int minCut(string s) {
        if (s.size() == 0)
            return {};
        
        palin.resize(s.size(),vector<bool>(s.size(),false));
        builIsPalindrome(s);
        
        memo.resize(s.size(),-1);
        return rec(s,0)-1;
    }
    
    int rec(string& s, int start){
        if (start == s.size())
            return 0;
        
        if (memo[start] != -1)
            return memo[start];
        
        int response = INT_MAX;
        for (int i=start;i<s.size();i++){
            int len = i-start+1;
            if (!palin[start][i]){
                continue;
            }
            response = min(response,1+rec(s,i+1));
        }
        
        return memo[start] = response;
    }
    
//      aab
//    a 110      
//    a x10
//    b xx1
         
    void builIsPalindrome(string& s){ // O(n^2)
        for (int i=(int)palin.size()-1;i>=0;i--){
            for (int j=(int)palin.size()-1;j>=i;j--){
                if (i == j)
                    palin[i][j] = true;
                else if (s[i] != s[j])
                    palin[i][j] = false;
                else if (j-i+1 == 2)
                    palin[i][j] = true;
                else // if (i+1<palin.size())
                    palin[i][j] = palin[i+1][j-1];
            }
        }
    }
};
// Time: O(n^2)
// Space: O(n^2)

int main(){
    Solution sol;

    assert(sol.minCut("aab") == 1);
    assert(sol.minCut("aabcd") == 3);
    assert(sol.minCut("a") == 0);

    cout << "Passed!" << endl;
    return 0;
}
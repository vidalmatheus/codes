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
    vector<vector<string>> partition(string s) {
        if (s.size() == 0)
            return {};
        
        vector<vector<string>> ans;
        vector<string> curr;
        rec(s,ans,curr,0);
        
        return ans;
    }
    
    void rec(string& s, vector<vector<string>>& ans, vector<string>& curr, int start){
        if (start == s.size()){
            ans.push_back(curr);
            return;
        }
        
        for (int i=start;i<s.size();i++){
            int len = i-start+1;
            string str = s.substr(start,len);
            if (!isPalindrome(str))
                continue;
            curr.push_back(s.substr(start,len));
            rec(s,ans,curr,i+1);
            curr.pop_back();
        }
    }
    
    bool isPalindrome(string& s){
        if (s.size() == 0)
            return true;
        for (int i=0,j=s.size()-1;i<j;i++,j--)
            if (s[i] != s[j])
                return false;
        return true;
    }
};
// Time: O(n*2^(n-1))
// Space: O(n)

int main(){
    Solution sol;
    string s = "aab";

    vector<vector<string>> ans = sol.partition(s);
    vector<vector<string>> expected = { {"a", "a", "b"}, {"aa", "b"} };
    assert(ans == expected);
    cout << "Passed!" << endl;
    return 0;
}
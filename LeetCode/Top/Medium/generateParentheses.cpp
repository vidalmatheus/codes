#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<string> generateParenthesis_WORNG(int n) { // This is WRONG
        if (n==0)
            return {};
        if (n==1)
            return {"()"};
        
        vector<string> previous = generateParenthesis_WORNG(n-1);
        unordered_set<string> hash_set;
        for (int i=0;i<previous.size();i++) {
            hash_set.insert("()" + previous[i]);
            hash_set.insert("(" + previous[i] + ")");
            hash_set.insert(previous[i] + "()");
        }
        
        vector<string> ans;
        for (string word:hash_set) {
            ans.push_back(word);
        }

        return ans;
    }

    vector<string> generateParenthesis(int n) {
        if (n == 0)
            return {};
        
        vector<string> ans;

        genParen(ans,n,n,"");

        return ans;
    }

    void genParen(vector<string> &ans, int open, int close, string word) {
        if (close == 0) {
            ans.push_back(word);
            return;
        }
        
        if (open < close && open!=0) {
            genParen(ans,open-1,close,word+"(");
            genParen(ans,open,close-1,word+")");
        }
        
        else if (open == 0 && close>0)
            genParen(ans,open,close-1,word+")");
        
        else if (open == close && open !=0)
            genParen(ans,open-1,close,word+"(");
    }
    
};

int main() {
    int n = 3;

    Solution sol;
    vector<string> ans = sol.generateParenthesis(n);

    for (string word:ans)
        cout << word << endl;

    return 0;
}
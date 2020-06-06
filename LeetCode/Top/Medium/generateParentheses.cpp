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

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0)
            return {};
        
        vector<string> ans;
        rec(ans,n,n,"");
        
        return ans;
    }
    
    void rec(vector<string>& ans, int open, int close, string curr){
        if (open == 0 && close == 0){
            ans.push_back(curr);
            return;
        }
        
        if (open != 0){
            if (open < close){
                rec(ans,open-1,close,curr+"(");
                rec(ans,open,close-1,curr+")");
            }
            else // if (open == close)
                rec(ans,open-1,close,curr+"(");   
        }
        else // open == 0 && close != 0 
            rec(ans,open,close-1,curr+")");
    }
};
// Time: O(Catalan(n) = [1/(n+1)] * (2n choose n) )
// Space: O(n)

/*

Cn is the number of Dyck words[3] of length 2n. 
A Dyck word is a string consisting of n X's and n Y's such that no initial segment of the string has more Y's than X's. 
For example, the following are the Dyck words of length 6:
XXXYYY     XYXXYY     XYXYXY     XXYYXY     XXYXYY.

Re-interpreting the symbol X as an open parenthesis and Y as a close parenthesis, 
Cn counts the number of expressions containing n pairs of parentheses which are correctly matched:
((()))     ()(())     ()()()     (())()     (()())

*/

int main() {
    int n = 3;

    Solution sol;
    vector<string> ans = sol.generateParenthesis(n);

    for (string word:ans)
        cout << word << endl;

    return 0;
}

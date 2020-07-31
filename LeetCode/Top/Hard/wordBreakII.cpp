#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class RecursiveSolution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        
        vector<string> ans;
        string curr = "";
        rec(s,dict,curr,ans);
        return ans;
    }
    
    void rec(string& s, unordered_set<string>& dict, string& curr, vector<string>& ans){
        if (s.size() == 0){
            curr.pop_back();
            ans.push_back(curr);
            curr.push_back(' ');
            return;
        }
        
        string word = "";
        for (int i=0;i<s.size();i++){
            word.push_back(s[i]);
            if (dict.find(word) != dict.end()){
                curr.append(word+" ");
                string str = s.substr(i+1);
                rec(str,dict,curr,ans);
                curr.erase((int)curr.size()-word.size()-1,word.size()+1);
            }
        }
    }
};
// Time: O(m^n)
// Space: O(content_of_answer)

class Solution { // Memoization solution
private:
    unordered_map<string,vector<string>> memo;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0)
            return {};
        
        if (memo.find(s) != memo.end())
            return memo[s];
            
        vector<string> ans;
        for (string w : wordDict){
            if (s.substr(0,w.size()) == w){
                if (s.size() == w.size())
                    ans.push_back(w);
                else {
                    vector<string> subproblem = wordBreak(s.substr(w.size()),wordDict);
                    for (string str:subproblem){
                        string curr = w;
                        curr.push_back(' ');
                        curr.append(str);
                        ans.push_back(curr);
                    }
                }
            }
        }
        
        return memo[s] = ans;
    }
};
// Time: O(m*n/k), where m is the size of wordDict, n is the length of s and k is the average size of a word in wordDict
// Space: O(content_of_answer)

int main(){
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};

    Solution sol;
    vector<string> ans = sol.wordBreak(s,wordDict);

    for (string s:ans)
        cout << s << endl;

    return 0;
}

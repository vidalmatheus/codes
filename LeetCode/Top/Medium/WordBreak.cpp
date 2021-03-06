#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
rec("leetcode"):
    rec("code"):
        rec(""):
         true
         
*/

class WRONGSolution { // This is Wrong!!!
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        
        string word = "";
        int counter = 0;
        for (int i=0;i<=s.size();++i){
            if (dict.find(word)!=dict.end()){ // found
                counter += word.size();
                if (i<s.size())
                    word = s[i];
            }
            else // not found yet
                word += s[i];
        }

        return counter==s.size();                            
    }
};
// Time: O(n+m)
// Space: O(m)

class TLESolution { // Time Limit Exceeded
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        
        return rec(s,dict);   
    }
    
    bool rec(string s, unordered_set<string>& dict){
        if (s.size()==0)
            return true;
        
        string word = "";
        for (int i=0;i<s.size();i++){
            word +=s[i];
            if (dict.find(word)!=dict.end())
                if (rec(s.substr(i+1),dict))
                    return true;
        }
        
        return false;
    }
};
// Time: O(n*m)
// Space: O(m)


class Solution { // Dynamic Programming (memoization) - Top-Down
private:
    unordered_map<string,bool> memo;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        
        memo.reserve(dict.size());
    
        return rec(s,dict);   
    }
    
    bool rec(string& s, unordered_set<string>& dict){
        if (s.size()==0)
            return true;
        
        if (memo.find(s)!=memo.end())
            return memo[s];
        
        string word = "";
        for (int i=0;i<s.size();i++){
            word +=s[i];
            if (dict.find(word)!=dict.end()){
                string str = s.substr(i+1);
                if (rec(str,dict))
                    return memo[s] = true;
            }
        }
        
        return memo[s] = false;
    }
};
// Time: O(n^2)
// Space: O(m)

class OtherSolution {
private:
    vector<int> memo;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0 && wordDict.size() > 0)
            return false;
        
        if (s.size() > 0 && wordDict.size() == 0)
            return false;
        
        if (s.size() == 0 && wordDict.size() == 0)
            return true;
        
        unordered_set<string> dict;
        for (string & w : wordDict)
            dict.insert(w);
        
        memo.resize(s.size(),-1);
        return rec(s,0,dict);
    }
    
    bool rec(string& s, int start, unordered_set<string> dict){
        if (start == s.size())
            return true;
        
        if (memo[start] != -1)
            return memo[start];
        
        for (int i=start;i<s.size();i++){
            int len = i-start+1;
            if (dict.find(s.substr(start,len)) != dict.end())
                if (rec(s,i+1,dict))
                    return memo[start] = true;
        }
        
        return memo[start] = false;
    }
};
// Time: O(n^2)
// Space: O(n)

int main(){
    string s = "leetcode";
    vector<string> wordDict{"leet","code"};

    OtherSolution sol;
    sol.wordBreak(s,wordDict) ? cout << "true\n" : cout << "false\n";

    return 0;
}

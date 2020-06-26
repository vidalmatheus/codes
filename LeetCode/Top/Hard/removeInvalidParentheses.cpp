#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class BruteForceSolution {
public:
    vector<string> removeInvalidParentheses(string s) {
        if (s.size() == 0)
            return {""};
        
        unordered_set<string> all;
        string curr = "";
        rec(s,all,0,curr);
        
        // get the maximum
        int maxSize = INT_MIN;
        for (auto elem:all)
            maxSize = max(maxSize,(int)elem.size());
        
        vector<string> ans;
        for (auto elem:all){
            if (elem.size() == maxSize)
            ans.push_back(elem);
        }
        
        return ans;
    }
    
    void rec(string& s, unordered_set<string>& all, int pos, string curr){
        if (pos == s.size() && isValid(curr)){
            all.insert(curr);
            return;
        }
        if (pos == s.size())
            return;
        
        char c = s[pos];
        if (c == '(' || c == ')'){
            rec(s,all,pos+1,curr);
            rec(s,all,pos+1,curr+c);
        }
        else {
            rec(s,all,pos+1,curr+c);
        }    
    }
    
    bool isValid(string& s){
        if (s.size() == 0)
            return true;
        
        int balance = 0;
        for (int i=0;i<s.size();++i){
            if (s[i] == '(')
                balance++;
            else if (s[i] == ')')
                balance--;
            
            if (balance < 0)
                return false;
        }
        
        return balance == 0;
    }
};
// Time: O(n^2*2^n)
// Space: O(n)

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        if (s.size() == 0)
            return {""};
        
        unordered_set<string> all;
        string curr = "";
        rec(s,all,0,curr);
        
        // get the maximum
        int maxSize = INT_MIN;
        for (auto elem:all)
            maxSize = max(maxSize,(int)elem.size());
        
        vector<string> ans;
        ans.reserve(all.size());
        for (auto elem:all){
            if (elem.size() == maxSize)
                ans.push_back(elem);
        }

        /* If you had decided to do those two for loops above together, that would cost more time, because of the push_back()
        
        for (auto elem:all){
            if (elem.size() > maxSize){
                maxSize = elem.size();
                ans.clear();
                ans.push_back(elem);
            }
            else if (elem.size() == maxSize){
                ans.push_back(elem);
            }
        }
        
        */

        return ans;
    }
    
    void rec(string& s, unordered_set<string>& all, int pos, string& curr){
        if (pos == s.size() && isValid(curr)){
            all.insert(curr);
            return;
        }
        if (pos == s.size())
            return;
        
        char c = s[pos];
        if (c == '(' || c == ')'){
            rec(s,all,pos+1,curr);
            curr.push_back(c);
            rec(s,all,pos+1,curr);
            curr.pop_back();
        }
        else {
            curr.push_back(c);
            rec(s,all,pos+1,curr);
            curr.pop_back();
        }    
    }
    
    bool isValid(string& s){
        if (s.size() == 0)
            return true;
        
        int balance = 0;
        for (int i=0;i<s.size();++i){
            if (s[i] == '(')
                balance++;
            else if (s[i] == ')')
                balance--;
            
            if (balance < 0)
                return false;
        }
        
        return balance == 0;
    }
};
// Time: O(2^n)
// Space: O(n)

int main(){
    string s = "()())()";

    BruteForceSolution sol;
    vector<string> ans = sol.removeInvalidParentheses(s);

    return 0;
}

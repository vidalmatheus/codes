#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
lee(t(c)o)de)
            i

ans: lee(t(c)o)de

stack: 

*/

class WrongSolution { // It doesn't work for every case
public:
    string minRemoveToMakeValid(string s) {
        if (s.size()==0)
            return s;
        
        if (s[0]==')')
            return "";
        
        string ans = "";
        stack<char> st;
        int index = 0;
        while (index<s.size()){
            if (s[index]!=')'){
                st.push(s[index]);
            }
            else { 
                while (!st.empty() && st.top()!='('){
                    st.pop();
                }
                if (!st.empty()){
                    st.pop();
                }
                if (st.empty()) break;
            }
            ans+=s[index];
            index++;
        }
        
        return ans;
    }
};
// Time: O(n)
// Space: O(n)

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for (auto i = 0; i < s.size(); ++i) {
            if (s[i] == '(') 
                st.push(i);
            if (s[i] == ')') {
                if (!st.empty()) 
                    st.pop();
                else s[i] = '*';
            }
        }
            
        while (!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }
        
        auto pend = remove(s.begin(), s.end(), '*');

        // for (int i=0;i<s.size();i++)
        //     if (s[i] == '*')
        //         s.erase(i--,1);

        s.erase(pend,s.end());
        return s;
    }
};
// Time: O(n)
// Space: O(n)

class BetterSolution {
public:
    string minRemoveToMakeValid(string s) {
        if (s.size() == 0)
            return "";
        
        int closed = 0; // max to close
        for (char c:s)
            if (c == ')')
                closed++;
        
        int opened = 0;
        string ans;
        for (char c:s){
            if (c == '('){
                if (opened == closed) continue; // I can't open parentheses anymore
                opened++;
            }
            else if (c == ')') {
                closed--;
                if (opened == 0) continue; // I can't close parentheses anymore
                opened--;
            }
            ans += c;
        }
        
        return ans;
    }
};
// Time: O(n), two-pass
// Space: O(1)

class ReviewdSolution {
public:
    string minRemoveToMakeValid(string s) {
        if (s.size() == 0)
            return "";
        
        int max_open = 0;
        for (char c:s)
            if (c == ')')
                max_open++;
        
        string ans = "";
        int open = 0;
        for (char c:s){
            if (c == '('){
                // if I don't have any closing parentheses to match, I can't open any parentheses further
                if (open == max_open) continue; // skip when I can't open parentheses
                
                open++;
            }
            else if (c == ')'){
                max_open--;
                // if I don't have any openning parentheses to match, I can't close any parentheses further
                if (open == 0) continue; // skip when I can't close parentheses
                
                open--;
            }
            
            ans += c;        
        }
        
        return ans;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    // string s = "lee(t(c)o)de)";
    // string s = "a)b(c)d";
    // string s = "))((";
    string s = "(a(b(c)d)";

    Solution sol;
    cout << sol.minRemoveToMakeValid(s) << endl;

    return 0;
}

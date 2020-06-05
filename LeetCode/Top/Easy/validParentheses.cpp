#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class FirstSolution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push('#');
        if (s.size()==0) return true;
        for (int i=0;i<s.size();i++){ 
            if (s[i]=='(' || s[i]=='[' || s[i]=='{') 
                st.push(s[i]);
            else {
                if ( (s[i]==')' && st.top()=='(') || (s[i]==']' && st.top()=='[') || (s[i]=='}' && st.top()=='{') )
                    st.pop();
                else return false;
            }
        }
        if (st.top()=='#')
            return true;
        return false;
    }
};

class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0)
            return true;
        
        stack<char> open;
        for (int i=0;i<s.size();i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                open.push(s[i]);
            else if (!open.empty()){
                if (s[i] == ')' && open.top() == '(')
                    open.pop();
                else if (s[i] == ']' && open.top() == '[')
                    open.pop();
                else if (s[i] == '}' && open.top() == '{')
                    open.pop();
                else return false;
            }
            else return false;
        }
        
        return open.empty() ? true : false;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    string s = "(])";
    /* string s = "]"; */
    Solution sol;
    sol.isValid(s)?(cout << "true" << endl):(cout << "false" << endl);
    return 0;
}
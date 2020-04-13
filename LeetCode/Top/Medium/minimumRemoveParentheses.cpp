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
            if (s[i] == '(') st.push(i);
            if (s[i] == ')') {
            if (!st.empty()) st.pop();
            else s[i] = '*';
            }
        }
            
        while (!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }
        
        auto pend = remove(s.begin(), s.end(), '*');
        s.erase(pend,s.end());
        return s;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    // string s = "lee(t(c)o)de)";
    // string s = "a)b(c)d";
    // string s = "))((";
    string s = "(a(b(c)d)";

    Solution sol;
    cout << sol.minRemoveToMakeValid(s) << endl;

    return 0;
}
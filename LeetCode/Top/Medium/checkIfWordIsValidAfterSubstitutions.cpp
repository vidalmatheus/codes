#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class FirstSolution {
public:
    bool isValid(string& S) {
        if (S.size() == 0)
            return true;
        int index = findABC(S);
        if (index == S.size()) return false;
        S.erase(index, 3); // O(n)
        return isValid(S);
    }
    
    int findABC(string& s){
        for (int i=0;i<s.size()-2;i++){
            if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c')
                return i;
        }
        return s.size();
    }
};
// Time: O(n^2)
// Space: O(n)

class Solution { // very much alike the easy problem called Valid Parentheses from leetcode
public:
    bool isValid(string& S) {
        if (S.size() == 0)
            return true;
        
        stack<char> st;
        for (char c : S){
            if (c == 'a' || c == 'b')
                st.push(c);
            else if (!st.empty()){
                if (c == 'c' && st.top() == 'b'){
                    st.pop();
                    if (!st.empty() && st.top() == 'a')
                        st.pop();
                    else return false;
                }
                else return false;
            }
            else return false;
        }
        
        return st.empty() ? true : false;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    Solution sol;

    string s = "aabcbc";
    assert(sol.isValid(s) == true);
    
    s = "abcabcababcc";
    assert(sol.isValid(s) == true);

    s = "abccba";
    assert(sol.isValid(s) == false);

    s = "cababc";
    assert(sol.isValid(s) == false);

    cout << "Passed!" << endl;

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool checkValidString(string s) {
        if (s.size()==0)
            return true;
        
        stack<int> open, star;
               
        // closing brackets
        for (int i=0;i<(int)s.size();i++){
            if (s[i]=='(')
                open.push(i);
            else if (s[i]=='*')
                star.push(i);
            else { // s[i] == ')'
                if (!open.empty())
                    open.pop();
                else if (!star.empty())
                    star.pop();
                else return false;
            }
        }
        
        // openning brackets
        while (!open.empty()){
            
            if (star.empty())
                return false;
            else if (open.top()<star.top()){
                open.pop();
                star.pop();
            }
            else return false;    
        }
        
        return true;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    string s = "(*))";

    Solution sol;
    sol.checkValidString(s) ? cout << "true\n" : cout << "false\n";

    return 0;
}

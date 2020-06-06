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
    int minAddToMakeValid(string s) {
        stack<int> open;
        int counter = 0;
        for (int i=0;i<s.size();i++){
            if (s[i] == '(')
                open.push(i);
            else if (s[i] == ')'){
                if (!open.empty())
                    open.pop();
                else counter++;
            }
        }
        
        counter += open.size();
        
        return counter;
    }
};
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int balance = 0;
        for (int i=0;i<s.size();i++){
            balance += s[i] == '(' ? 1:-1;
            if (balance == -1){
                ans++;
                balance = 0;
            }
        }
        
        return ans+balance;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    string s = "()))((";

    Solution sol;
    cout << sol.minAddToMakeValid(s) << endl;

    return 0;
}
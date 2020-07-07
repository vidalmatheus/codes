#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
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

class ReviewdSolution { // better coded
public:
    int minAddToMakeValid(string S) {
         if (S.size() == 0)
             return 0;
        
        int opened_needed = 0;
        int open = 0;
        for (char c:S){
            open += c == '(' ? 1 : -1;
            if (open < 0){
                open = 0;
                opened_needed++;
            }
        }
        
        int closed_needed = open;
        return opened_needed + closed_needed;
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

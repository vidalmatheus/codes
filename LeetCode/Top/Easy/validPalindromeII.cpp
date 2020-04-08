#include <bits/stdc++.h>


using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool validPalindrome(string s) {
        for (int i=0;i<s.size();i++){
            int j = s.size()-1-i;
            if (s[i]!=s[j]){
                return isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1); 
            }
        }
        
        return true;
    }
    
    bool isPalindrome(string s, int i, int j) {
        for (int k=i,q=j;k<q;k++,q--){
            if (s[k]!=s[q])
                return false;
        }
        
        return true;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    string s = "abc";

    Solution sol;
    sol.validPalindrome(s) ? cout << "true\n" : cout << "false\n";

    return 0;
}
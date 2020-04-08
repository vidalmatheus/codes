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
    string longestPalindrome(string s) {
        if (s.size()==1)
            return s;
        
        string maxStr = "";

        for (int i=0;i<s.size();i++){
            for (int j=i;j<s.size();j++){
                string str = s.substr(i,j-i+1); 
                if (isPalindrome(str,maxStr.size()))
                    maxStr=str;
            }
        }
        
        return maxStr;
    }
    
    bool isPalindrome(const string& s, int max){ // O(n)
        if (s.size()<=max)
            return false;

        for (int i=0,j=s.size()-1;i<=j;i++,j--){
            if (s[i]!=s[j])
                return false;
        }
        
        return true;
    }
};
// Time: O(n^3)
// Space: O(1)

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size()==1)
            return s;
        
        int L=0;
        int R=0;
        for (int i=0;i<s.size();i++){
            int lenOdd = expand(s,i,i);
            int lenEven = expand(s,i,i+1);
            int len = max(lenOdd,lenEven);
            if (len>R-L+1){
                L = i - (len-1)/2;
                R = i + (len)/2;
            }
        }
        
        return s.substr(L,R-L+1);
    }
    
    int expand(const string& s, int left, int right){
        int i = left;
        int j = right;
        while (i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
        }
        return j-i-1; // size
    }
};
// Time: O(n^2)
// Space: O(1)


int main(){
    // string  s = "babad";
    // string s = "bb";
    // string s = "abb";
    // string s = "ac";
    string s = "aaaa";

    Solution sol;
    string ans = sol.longestPalindrome(s);

    cout << ans << endl;

    return 0;
}
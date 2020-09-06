#include <bits/stdc++.h>

using namespace std;

/*
i   j
abc abcabcabc ->  i == 0 and j == length  true

str = abc


i      j
abc abcd ->  s[i] != s[j]  false

str: abc

 i  j
ab a -> i != 0 and j == length false

str: ab
*/

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() <= 1)
           return false;
        
        int n = s.size();
        int j;
        for (j=1;j<n;j++)
            if (s[j] == s[0])
                if (isPossible(s,j))
                    return true;
                
        return false;

    }
    
    bool isPossible(string& s, int j){
        int n = s.size();
        string str = s.substr(0,j);
        int sizeSub = str.size();
        int i = 0;
        while (j < n){
            if (s[i] != s[j])
                return false;
            
            i = (i + 1) % sizeSub;
            j++;    
        }
        
        return i == 0 ? true : false;
    }
    
};
// Time: O(n^2)
// Space: O(n/2)

class FasterSolution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() <= 1)
           return false;
        
        string str = s+s;
        string sub = str.substr(1,str.size()-2);
        
        return sub.find(s) != string::npos ? true : false;
    }
    
};
// Time: O(n)
// Space: O(n)

int main(){
    Solution sol;

    string s = "abcabc";
    assert(sol.repeatedSubstringPattern(s) == true);

    s = "aba";
    assert(sol.repeatedSubstringPattern(s) == false);

    s = "a";
    assert(sol.repeatedSubstringPattern(s) == false);

    s = "abaababaab";
    assert(sol.repeatedSubstringPattern(s) == true);

    cout << "Passed!" << endl;

    return 0;
}
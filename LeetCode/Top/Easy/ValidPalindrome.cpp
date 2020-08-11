/* Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false */

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
    bool isPalindrome(string s) {
        bool ans = true;
        string t;
        for (int i=0;i<s.size();i++){
            if ( isalnum(s[i]) )            // store only letters
                t.insert(t.end(),s[i]);
        }
        cout << t << endl;
        for (int i=0,j=t.size()-1;i<j;i++,j--){
            if (tolower(t[i])!=tolower(t[j]))
                return false;
        }
        return true;   
    }
};
// Time: O(n)
// Space: O(n)

class BestSolution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0)
            return true;
        
        int n = s.size();
        for (int i=0,j=n-1;i<j;){
            if (!isalnum(s[i]))
                i++;
            else if (!isalnum(s[j]))
                j--;
            else if (tolower(s[i++]) != tolower(s[j--]))
                return false;        
        }
        
        return true;
    }
};
// Time: O(n)
// Space: O(1)

int main(){

    string s;
    getline(cin,s);
    Solution sol;
    cout << (sol.isPalindrome(s) ? "true":"false") << endl;
    return 0;
}

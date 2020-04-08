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
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size()-1;
        
        while (left<right){
            if (!isVowel(s[left]))
                left++;
            else if (!isVowel(s[right]))
                right--;
            else { // (isVowel(s[left]) && isVowel(s[right])){
                swap(s[left],s[right]);
                left++;
                right--;
            }
        }
        
        return s;
    }
    
    bool isVowel(const char c){
        if (tolower(c)=='a' || tolower(c)=='e' || tolower(c)=='i' || tolower(c)=='o' || tolower(c)=='u')
            return true;
        return false;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    string s = "hello";

    Solution sol;
    cout << sol.reverseVowels(s) << endl;

    return 0;
}
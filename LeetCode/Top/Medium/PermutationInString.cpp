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
    bool checkInclusion(string s1, string s2) {
        if (s1.size()>s2.size())
            return false;
        
        vector<int> charCounter(26,0);
        for (char c:s1)
            charCounter[c-'a']++;
        
        // sliding window
        int left = 0;
        int right = 0;
        int counter = 0;
        while (right < s2.size()){
            if (charCounter[s2[right]-'a']>=1)
                counter++;
            
            charCounter[s2[right++]-'a']--;
            
            if (counter == s1.size())
                return true;
            
            if (right - left == s1.size()){
                if (charCounter[s2[left]-'a']>=0)
                    counter--;
                charCounter[s2[left++]-'a']++;
            }
        }
        
        return false;
    }
};
// Time: O(n), where n is the size of s2
// Space: O(1)

int main(){
    string s1 = "ab", s2 = "eidbaooo";

    Solution sol;
    sol.checkInclusion(s1,s2) ? cout << "true\n" : cout << "false\n";

    return 0;
}

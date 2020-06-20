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
    string minWindow(string s, string p) {
        if (s.size()==0 || s.size()<p.size())
            return {};
        
        unordered_map<char,int> charCounter;
        for (char c:p)
            charCounter[c]++;
        
        int left = 0;
        int right = 0;
        int counter = 0;
        
        int minLen = INT_MAX;
        int minStart = -1;
        
        
        while (right < s.size()){
            if (charCounter[s[right]] > 0)
                counter++;
            
            charCounter[s[right++]]--;
            
            if (counter==p.size()){
                // move forward left as long as we see a character not in the pattern
                while (left < right && charCounter[s[left]] < 0 )
                    charCounter[s[left++]]++;
                
                
                // update the minimum window
                if (minLen > right - left){
                    minLen = right - left;
                    minStart = left;
                }
                
                // move forward left
                charCounter[s[left++]]++;
                counter--;
                
            }
            
        }
        
        return minStart == -1 ? "" : s.substr(minStart,minLen);
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    string S = "ADOBECODEBANC", T = "ABC";

    Solution sol;
    cout << sol.minWindow(S,T) << endl;

    return 0;
}

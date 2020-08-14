#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int longestPalindrome(string s) {
        if (s.size() == 0)
            return 0;
        
        unordered_map<char,int> counter;
        for (char c : s)
            counter[c]++;
        
        int ans = 0;
        bool oddFound = false;
        for (auto elem : counter){
            if (elem.second % 2 == 0)
                ans += elem.second;
            else{
                oddFound = true;
              ans += elem.second - 1;  
            } 
        }    
    
        return oddFound ? ans + 1 : ans;
    }
};
// Time: O(n)
// Space: O(n)

int main() {
    vector<string> in = {"abccccdd","bb"};
    vector<int> out = {7,2};

    Solution sol;
    for (int i=0;i<in.size();i++)
        assert(out[i] == sol.longestPalindrome(in[i]));

    cout << "Passed!" << endl;

    return 0;
}

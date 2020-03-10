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
    int balancedStringSplit(string s) {
        if (s.size()==0)
            return 0;
        
        int balencedStrings = 0;
        int count = 0;
        
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='L')
                count++;
            if (s[i]=='R')
                count--;
            
            if (count == 0)
                balencedStrings++;
        }
        
        return balencedStrings++;
    }
};

int main() {
    string s = "RLRRLLRLRL";

    Solution sol;
    cout << sol.balancedStringSplit(s) << endl;

    return 0;
}
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
    int minimumSwap(string s1, string s2) {
        if (s1 == s2)
            return 0;
        
        int amount_x = 0;
        int amount_y = 0;
        for (int i=0;i<s1.size();++i){
            if (s1[i] != s2[i])
                if (s1[i] == 'x') amount_x++;
                else amount_y++;
        }
        
        if (( amount_x%2 + amount_y%2 ) == 1)
            return -1;
        else return amount_x/2 + amount_x%2 + amount_y/2 + amount_y%2;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    string s1 = "xy";
    string s2 = "yx";

    Solution sol;
    cout << sol.minimumSwap(s1,s2) << endl;
    
    return 0;
}

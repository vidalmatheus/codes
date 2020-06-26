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
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        
        int j = 0;
        int counter = strs.size();
        string ans = "";
        while (j < strs[0].size()){
            counter = 0;
            for(int i=0;i<strs.size();i++){
                if (strs[i][j] == strs[0][j])
                    counter++;
                else break;
            }
            if (counter < strs.size()) break;
            ans += strs[0][j];
            j++;
        }
        
        return ans;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    vector<string> strs{
        {"flower"},
        {"flow"},
        {"flight"}
    };

    Solution sol;
    cout << sol.longestCommonPrefix(strs) << endl;

    return 0;
}

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
    int maximumSwap(int num) {
        if (num < 10)
            return num;
        
        string s = to_string(num);
        
        int max = num;
        for (int i=0;i<s.size();++i){
            for (int j=0;j<s.size();++j){
                if (i!=j){
                    swap(s[i],s[j]);
                    max = std::max(max,stoi(s));
                    swap(s[i],s[j]);
                }
            }
        }
    
        return max;
    }
};
// Time: O(n^2)
// Space: O(1)

int main(){
    int num = 99368;

    Solution sol;
    cout << sol.maximumSwap(num) << endl;
    
    return 0;
}

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
    int trailingZeroes(int n) {
        int count = 0;
        int p = 5;
        unsigned long long int d = p;
        while (d<=n){
            count+=n/d;
            d*=p;
        }
        
        return count;
    }
};
// Time: O(log_d n)
// Space: O(1)

int main(){
    int n = 1808548329;

    Solution sol;
    cout << sol.trailingZeroes(n) << endl;

    return 0;
}
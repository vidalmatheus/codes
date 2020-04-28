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
    double myPow(double x, int n) {
        if (x==0)
            return 0;
        
        if (n>0)
            return exp(n*log(abs(x)))*(x<0 && n%2 == 1 ? -1 : 1);
        
        return exp(n*log(abs(x)))*(x<0 && n%2 == 1 ? -1 : 1);
    }
};
// Time: O(1)
// Space: O(1)

int main(){
    double x = 2.0;
    int n = -2;

    Solution sol;
    cout << sol.myPow(x,n) << endl;

    return 0;
}

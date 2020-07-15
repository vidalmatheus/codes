#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    double angleClock(int h, int m) {
        double angle = abs((h*30 + m*0.5) - (m*6));
        return min(angle,360-angle);
    }
};
// Time: O(1)
// Space: O(1)

int main(){
    int h = 3;
    int m = 15;

    Solution sol;
    cout << sol.angleClock(h,m) << endl;

    return 0;
}

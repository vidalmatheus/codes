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
    int numOfWays(int n) {
        unsigned long int twoColors = 6;
        unsigned long int threeColors = 6;

        unsigned long int ansTwo = 6;
        unsigned long int ansThree = 6;
        for (int i=2;i<=n;i++){
            ansTwo = (3*twoColors + 2*threeColors)%(1000000007);
            ansThree = (2*twoColors + 2*threeColors)%(1000000007);
            twoColors = ansTwo;
            threeColors = ansThree;
        }
        return (ansTwo + ansThree)%(1000000007);
    }
};
// Time: O(N)
// Space: O(1)

int main(){
    int n = 3;

    Solution sol;
    cout << sol.numOfWays(n) << endl;

    return 0;
}

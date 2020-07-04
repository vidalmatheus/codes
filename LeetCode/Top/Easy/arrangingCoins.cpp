#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*

1 + 2 + 3 + ... + k + a = n
k(k+1)/2 + a = n, a <= k

k*(k+1) = (n-a)*2, try 

exact solution:
x(x+1)/2 = n
x² + x -2n = 0
x(n) = [ -1 + sqrt(1+8*n) ]/2

x (5) = (-1 + sqrt(41))/2

*/

class Solution {
public:
    int arrangeCoins(int n) {
        return floor( (-1+sqrt(1+(long int)8*n))/2 );
    }
};
// Time: O(1)
// Space: O(1)

int main(){
    int n = 8;

    Solution sol;
    cout << sol.arrangeCoins(n) << endl;

    return 0;
}
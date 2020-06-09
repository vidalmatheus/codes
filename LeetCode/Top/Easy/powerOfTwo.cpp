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
    bool isPowerOfTwo(int n) {
        if(n == 0)
            return false;
        
        while (n%2 == 0) n/=2;
        
        return n == 1;
    }
};
// Time: O(log(n))
// Space: O(1)

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0)
            return false;
        
        return ceil(log2(n)) == floor(log2(n));
    }
};
// Time: O(1)
// Space: O(1)

int main(){
    int n = 16;

    Solution sol;
    sol.isPowerOfTwo(n) ? cout << "true\n" : cout << "false\n";

    return 0;
}

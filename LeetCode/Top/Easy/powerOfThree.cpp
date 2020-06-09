#include <bits/stdc++.h>

using namespace std;

// To Speed Up
auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n==0) return false;
        while (n%3==0)  n=n/3;
        return (n==1);
    }
};
// Time: O(log n)
// Space: O(1)

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0)
            return false;
        
        return ceil(log(n)/log(3)) - log(n)/log(3) < exp(-10*log(10));
    }
};
// Time: O(1)
// Space: O(1)

int main(){
    int n = 243;

    Solution sol;
    sol.isPowerOfThree(n) ? cout << "true\n" : cout << "false\n";

    return 0;
}

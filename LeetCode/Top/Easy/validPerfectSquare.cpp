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
    bool isPerfectSquare(int num) {
        if (num==1)
            return true;
        
        for (unsigned int i=2;i<num && i*i<=num;i++){ // unsigned to avoid overflow
            if (num%i==0 && num/i==i)
                return true;
        }
        
        return false;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    int num = 2147483647;

    Solution sol;
    sol.isPerfectSquare(num) ? cout << "true\n" : cout << "false\n";

    return 0;
}
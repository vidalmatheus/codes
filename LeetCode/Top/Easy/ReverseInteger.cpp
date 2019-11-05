/* Reverse Integer
Solution
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows. */

#include <bits/stdc++.h>

using namespace std;

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        int signal = 1;
        while(x!=0){
            if (ans>INT_MAX/10 || ans<INT_MIN/10)
                return 0;
            ans=(x%10)+10*ans;
            x/=10;

        }
        return ans*signal; 
    }
};

int main(){
    int x = 1534236469;
    //cout << x << endl;
    cout << "INT_MAX = " << INT_MAX << endl; // 2147483647
    cout << "INT_MIN = " << INT_MIN << endl; // -2147483648
    Solution sol;
    int ans = sol.reverse(x);
    cout << ans << endl;

    return 0;
}
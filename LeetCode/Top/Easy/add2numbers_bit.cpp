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
    int getSum(int a, int b) {
        int sum = a^b;
        int carry = (a&b);
        while (carry!=0){
            carry = (unsigned int)carry<<1;
            int sum_tmp = sum;
            sum = sum^carry;
            carry = sum_tmp&carry;
        }
        return sum;
    }
};

int main(){
    int a = -2;
    int b = 2;
    Solution sol;
    cout << sol.getSum(a,b) << endl;
    return 0;
}
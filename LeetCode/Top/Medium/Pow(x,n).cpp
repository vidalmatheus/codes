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

class OtherSolution {
public:
    double myPow(double x, int n) {
        if (x == 0)
            return 0;
        
        if (n == 0)
            return 1;
        
        int sign = 1;
        if (x < 0 && n % 2 == 1)
            sign = -1;
            
        return sign*exp(n*log(abs(x)));
    }
};
// Time: O(1)
// Space: O(1)

class RecursiveSolution {
public:
    double myPow(double x, int n) {
        if (x == 0)
            return 0;
        
        if (n == 0)
            return 1;

        double _sqrt = myPow(x,n/2);

        double ans = _sqrt*_sqrt;
        if (n < 0 && n % 2 != 0)
            ans *= ans*(1/x);
        else if (n % 2 != 0)
            ans *= ans*(x);

        return ans;
    }
};
// Time: O(log n)
// Space: O(log n)

int main(){
    double x = 2.0;
    int n = -2;

    Solution sol;
    cout << sol.myPow(x,n) << endl;

    return 0;
}

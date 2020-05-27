#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class LinearSolution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        
        long int i;
        for (i=1;i*i<=x;i++)
            if (x%i == 0 && i*i == x)    
                return i;
        
        return i-1;
    }
};
// Time: O(sqrt(n))
// Space: O(1)

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        
        long int left = 1;
        long int right = x-1;
        while (left < right){
            int mid = left + (right-left)/2;
            if (mid < x/mid)
                left = mid+1;
            else if (mid > x/mid) right = mid-1;
            else return mid;
        }
        
        return left>x/left ? left-1 : left;
    }
};
// Time: O(log n)
// Space: O(1)

int main(){
    int x = 8;

    Solution sol;
    cout << sol.mySqrt(x) << endl;

    return 0;
}

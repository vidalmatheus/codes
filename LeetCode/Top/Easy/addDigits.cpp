#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class RecursiveSolution {
public:
    int addDigits(int num) {
        if (num < 10)
            return num;
        return addDigits(num%10 + addDigits(num/10));
    }
};
// Time: O(log n)
// Space: O(log n)
 
class Solution {
public:
    int addDigits(int num){
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
};
// Time: O(1)
// Space: O(1)

int main(){
    int num = 34;

    Solution sol;
    cout << sol.addDigits(num) << endl;

    return 0;
}

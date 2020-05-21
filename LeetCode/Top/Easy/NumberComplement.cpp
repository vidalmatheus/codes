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
    int findComplement(int num) {
        int n = num==0 ? 1 : (int)log2(num)+1;
        for (int i=0;i<n;i++)
            if (num&(1<<i))
                num &= (~(1<<i)); // clear ith bit
            else num |= (1<<i); // set ith bit
        return num;
    }
};
// Time: O(1)
// Space: O(1)

int main(){
    int num = 5;

    Solution sol;
    cout << sol.findComplement(num) << endl;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int hammingDistance(int x, int y) {
        int counter = 0;
        for (int i=0;i<32;i++){
            bool ith_bit_x = x & (1<<i);
            bool ith_bit_y = y & (1<<i);
            if (ith_bit_x != ith_bit_y)
                counter++;
        }
        
        return counter;
    }
};
// Time: O(1)
// Space: O(1)

int main(){
    int x = 5;
    int y = 9;
    
    Solution sol;
    cout << sol.hammingDistance(x,y) << endl;

    return 0;
}

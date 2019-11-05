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
    int hammingDistance(int x, int y) {
        int n = x^y;
        int w=0;
        for (int i=0;i<32;i++){
            int b_i = ((n&(1<<i))!=0);
            w+=b_i;
        }
        return w;
    }
    int hammingWeight(uint32_t n) {
        int w=0;
        for (int i=0;i<32;i++){
            int b_i = ((n&(1<<i))!=0);
            w+=b_i;
        }
        return w;
    }
};

/* class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        int diff = x^y;
        while(diff>0){
            result += diff&1;
            diff >>= 1;
        }
        return result;
    }
}; */

int main(){
    uint32_t n = 7;
    Solution sol;
    cout << sol.hammingWeight(n) << endl;
    return 0;
}
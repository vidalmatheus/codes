#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution { // mine
public:
    uint32_t reverseBits(uint32_t n) {
        for (int i=0, j=31;i<j;i++,j--){
            int b_i = getIthBit(n,i);
            int b_j = getIthBit(n,j);
            int tmp = b_i;
            setIthBit(n,i,b_j);
            setIthBit(n,j,tmp);   
        }
        return n;
    }
    int getIthBit(uint32_t &n,int i){
        return ((n&(1<<i))!=0);
    }
    void setIthBit(uint32_t &n,int i,int bit){
        if (getIthBit(n,i)!=bit) 
            n = n^(1<<i);
    }
};

class DifferentSolution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i =0 ; i< 32;i++){
            res <<=1;
            res+=(n&1); // look to the first bit;
            n>>=1;
        }
        return res;
    }
};

class ReviewdSolution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i=0,j=31;i<j;i++,j--){
            int elem_i = ( (n & (1<<i)) != 0 );
            int elem_j = ( (n & (1<<j)) != 0 );
            
            if (elem_i == 1) 
                ans |= (1<<j);
            
            if (elem_j == 1)
                ans |= (1<<i);
        }
        
        return ans;
    }
};
// Time: O(1)
// Space: O(1)

int main(){
    int n = 43261596;
    Solution sol;
    cout << sol.reverseBits(n) << endl;
    return 0;
}

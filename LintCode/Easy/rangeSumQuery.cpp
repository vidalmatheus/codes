#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class NumArray {
private:
    vector<int> prefixSum;
public:
    NumArray(vector<int> nums) {
        prefixSum.resize(nums.size()+1,0);
        for (int i=1;i<prefixSum.size();i++)
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
    }
    
    int sumRange(int i, int j) {
        return prefixSum[j+1] - prefixSum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
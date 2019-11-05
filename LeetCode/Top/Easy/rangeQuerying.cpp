#include <bits/stdc++.h>

using namespace std;

class NumArray {
private:
    vector<int> cache;      
public:
    NumArray(vector<int>& nums) {
        cache.resize(nums.size()+1);
        cache[0]=0;
        for (int i=0;i<nums.size();i++)
            cache[i+1]=cache[i]+nums[i];
    }
    
    int sumRange(int i, int j) {
        return cache[j+1]-cache[i];
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray sol = NumArray(nums);
    cout << sol.sumRange(2,5) << endl;
    return 0;
}
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
    int maxProduct(vector<int>& nums) {
        int currMaxProduct = nums[0];
        int currMinProduct = nums[0];
        int maxProduct = nums[0];
        for (int i=1;i<nums.size();i++){
            int prevMaxProduct = currMaxProduct;
            currMaxProduct = max(max(nums[i]*currMaxProduct,nums[i]*currMinProduct),nums[i]);
            currMinProduct = min(min(nums[i]*prevMaxProduct,nums[i]*currMinProduct),nums[i]);
            maxProduct = max(maxProduct,currMaxProduct);
        }
        
        return maxProduct;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    vector<int> nums{-1,-2,-9,-6};

    Solution sol;
    cout << sol.maxProduct(nums) << endl;

    return 0;
}

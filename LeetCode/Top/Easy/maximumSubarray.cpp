#include <bits/stdc++.h>

using namespace std;

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution { // Kadane's Algorithm
public:
    int maxSubArray(vector<int>& nums) {
        int prev = nums[0];
        int maxSum = nums[0];
        for (int i=1;i<nums.size();i++){
            int curr=max(prev+nums[i],nums[i]); // just switch to min if you want the minimum subarray
            if (curr>maxSum)
                maxSum=curr;
            prev = curr;
        }
        
        return maxSum;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    Solution sol;
    cout << sol.maxSubArray(nums) << endl;

    return 0;
}

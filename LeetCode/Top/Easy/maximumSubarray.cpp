#include <bits/stdc++.h>

using namespace std;

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class KadaneSolution { // Kadane's Algorithm
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

//   [ -2, 1,-3,4,-1,2,1,-5,4]
//  0  -2 -1 -4 0 -1 1 3 -2 2

class Solution {
public:
    int maxSubArray (vector<int>& nums){
        if (nums.size() == 0)
            return 0;
        
        int n = nums.size();
        vector<int> prefixSum(nums.size()+1,0);
        for (int i=1;i<=n;i++)
            prefixSum[i] = prefixSum[i-1]+nums[i-1];

        int maxSubarraySum = INT_MIN;
        int minValue = 0;
        for (int i=1;i<=n;i++){
            minValue = min(minValue,prefixSum[i-1]);
            maxSubarraySum = max(maxSubarraySum, prefixSum[i] - minValue);
        }
        
        return maxSubarraySum;
    }
};
// Time: O(n)
// Space: O(n)

class BestSolution {
public:
    int maxSubArray (vector<int>& nums){
        if (nums.size() == 0)
            return 0;
        
        int maxSubarraySum = INT_MIN;
        int minValue = 0;
        
        int prevPrefixSum = 0;
        int currPrefixSum = 0;
        for (int i:nums){
            currPrefixSum += i;
            minValue = min(minValue,prevPrefixSum);
            maxSubarraySum = max(maxSubarraySum, currPrefixSum - minValue);
            prevPrefixSum = currPrefixSum;
        }
        
        return maxSubarraySum;
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

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool sum2ToTarget(const vector<int>& nums, int left, int right, int target){
        if (nums[right]+nums[right-1]<target)
            return false;
        
        while (left<right){
            if (nums[left]+nums[right]>target)
            right--;
            else if (nums[left]+nums[right]<target)
            left++;
            else // (nums[left]+nums[right]==target)
            return true;
        }
        
        return false;
    }

    bool sum3ToZero(const vector<int>& nums){
        if (nums.size()<3)
            return false;
        
        sort(nums.begin(),nums.end());
        
        if (nums[0]>0 || nums[nums.size()-1]<0)
            return false;
        
        for (int i=nums.size()-1;i>=0;i--){
            int target = -nums[i];
            if (sum2ToTarget(nums,0,i-1,target))
            return true;
        }
        
        return false;
    }
    // Time: O(n*log n + n^2) = O(n^2)
    // Space: O(log n)
};

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
    int maxSubarraySumCircular(vector<int>& A) {
        if (A.size()==1)
            return A[0];
        
        bool allNegative = true;
        int maxValue = INT_MIN;
        for (int i=0;i<A.size();i++){
            maxValue = max(maxValue,A[i]);
            if (A[i]>=0){
                allNegative = false;
                break;
            }
        }

        if (allNegative)
            return maxValue;
        
        int totalSubArraySum = 0;
        for (int e:A)
            totalSubArraySum += e;
        
        int minSubArraySum = minSubArray(A);
        
        return max(maxSubArray(A), totalSubArraySum - minSubArraySum);
    }
    
    int minSubArray(vector<int>& nums) { // Kadane's Algorithm
        int prev = nums[0];
        int minSum = nums[0];
        for (int i=1;i<nums.size();i++){
            int curr=min(prev+nums[i],nums[i]);
            if (curr<minSum)
                minSum=curr;
            prev = curr;
        }
        
        return minSum;
    }
    
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
    vector<int> nums{1,-2,3,-2};

    Solution sol;
    cout << sol.maxSubarraySumCircular(nums) << endl;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


class TLESolution { // TLE
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return false;
        
        int totalSum = nums[0];
        bool hasSubArrayOfZeros = false;
        for (int i=1;i<nums.size();i++){
            totalSum += nums[i];
            if (nums[i] == nums[i-1] && nums[i] == 0)
                hasSubArrayOfZeros = true;
        }
    
        // k == 0
        if (k == 0 && hasSubArrayOfZeros)
            return true;
        
        if (k == 0 && !hasSubArrayOfZeros)
            return false;
        
        // target sum = 0
        if (hasSubArrayOfZeros)
            return true;
        
        // target sum != 0
        int n = nums.size();
        long int targetSum = abs(k);
        int i = 1;
        while (targetSum <= totalSum){
            // cout << "targetSum: " << targetSum << endl;
            if (subarraySum(nums,targetSum))
                return true;
            targetSum = abs(k)*(++i);
        }
        
        return false;
    }
    
    bool subarraySum(vector<int>& nums, long int targetSum){  // Time: O(n) & Space: O(n)
        map<int,int> seen2index;
        seen2index[0] = -1; // empty subarray
        int prefixSumSoFar = 0;
        int index = 0;
        for (int num:nums){
            prefixSumSoFar +=num;
            // prefixSum[i] - prefixSum[j] = targetSum 
            int prevPrefixSum = prefixSumSoFar - targetSum;
            if (seen2index.find(prevPrefixSum) != seen2index.end()){
                int size = index - seen2index[prevPrefixSum];
                if (size >= 2)
                    return true;
            }
            seen2index[prefixSumSoFar] = index++;
        }
            
        return false;
    }
};
// Time: O(n*TotalSum)
// Space: O(n)

// it's pretty much like the 2-sum problem !!!
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return false;
        
        unordered_map<int,int> seen2index;
        seen2index[0] = -1;
        int prefixSumSoFar = 0;
        int n = nums.size();
        for (int i=0;i<n;++i){
            prefixSumSoFar +=nums[i];
            
            // prefixSum[i] - prefixSum[j] = m*k
            if (k != 0) prefixSumSoFar %= k;
            if (seen2index.find(prefixSumSoFar) != seen2index.end()){
                if (i-seen2index[prefixSumSoFar] >= 2)
                    return true;
            }
            else seen2index[prefixSumSoFar] = i; // notice that we need a else here !
        }
        
        return false;
    }
};
// Time: O(n)
// Space: O(n)

int  main(){
    // vector<int> nums{23, 2, 4, 6, 7};
    // int k = 6;

    vector<int> nums{0,0};
    int k = 0;

    Solution sol;
    sol.checkSubarraySum(nums,k) ? cout << "true\n" : cout << "false\n";

    return 0;
}

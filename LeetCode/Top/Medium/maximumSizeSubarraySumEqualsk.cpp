#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
[1, -1, 5, -2, 3] and k = 3

    
prefixSum: 6
prefixSum - k: 3
seen2Index:
[0]: -1
[1]: 0
[5]: 2
[3]: 3

    maxSize = max(INT_MIN,4) = 4
    maxSize = max(4,1) = 4
*/

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return 0;
        
        unordered_map<int,int> seen2Index;
        seen2Index[0] = -1;
        int prefixSum = 0;
        int maxSize = 0;
        for (int i=0;i<nums.size();i++){
            prefixSum += nums[i];
            
            // prefixSum_i - prefixSum_j = k
            if (seen2Index.find(prefixSum-k) != seen2Index.end()){
                maxSize = max(maxSize,i - seen2Index[prefixSum-k]);
            }
            
            if (seen2Index.find(prefixSum) != seen2Index.end())
                seen2Index[prefixSum] = min(seen2Index[prefixSum], i);
            else seen2Index[prefixSum] = i;
        }
        
        return maxSize;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    Solution sol;

    vector<int> nums = {1, -1, 5, -2, 3};
    int k = 3;
    assert(sol.maxSubArrayLen(nums,k) == 4);

    nums = {-2, -1, 2, 1};
    k = 1;
    assert(sol.maxSubArrayLen(nums,k) == 2);
    cout << "Passed!" << endl;
    return 0;
}
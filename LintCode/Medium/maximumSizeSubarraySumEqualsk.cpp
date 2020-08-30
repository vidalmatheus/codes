#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * @param nums: an array
     * @param k: a target value
     * @return: the maximum length of a subarray that sums to k
     */
    int maxSubArrayLen(vector<int> &nums, int k) {
        // Write your code here
        if (nums.size() == 0)
            return 0;
        
        unordered_map<int,int> index; 
        int prefix_sum_i = 0;
        index[0] = -1;
        int max_size = nums[0] == k ? 1 : 0;
        for (int i=0;i<nums.size();i++){
            prefix_sum_i += nums[i];
                
            //  j     i  -> i-(j+1)+1
            // [0,1,2,3,4]
            
            // prefix_sum_i - prefix_sum_j = k
            int prefix_sum_j = prefix_sum_i - k;
            if (index.find(prefix_sum_j) != index.end()){
                int j = index[prefix_sum_j];
                max_size = max(max_size, i-j);
            }
            
            if (index.find(prefix_sum_i) != index.end())
                index[prefix_sum_i] = min(index[prefix_sum_i],i);
            else index[prefix_sum_i] = i;
        }
        
        return max_size;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    Solution sol;
    vector<int> nums{1, -1, 5, -2, 3};
    int k = 3;
    assert(sol.maxSubArrayLen(nums,k) == 4);

    nums = {-2, -1, 2, 1};
    k = 1;
    assert(sol.maxSubArrayLen(nums,k) == 2);

    nums = {-1};
    k = -1;
    assert(sol.maxSubArrayLen(nums,k) == 1);

    cout << "Passed!" << endl;
    return 0;
}
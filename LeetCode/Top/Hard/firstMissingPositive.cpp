#include <bits/stdc++.h>

using namespace std;

/*
[1,2,0]

min: 0 -> max: 2
    
    0 1 2 -> 3
    
    
[3,4,-1,1]

1 2 4        
*/
static int speedup=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0)
            return 1;
        
        int max = INT_MIN;
        unordered_set<int> set;
        for (int& num : nums){
            max = std::max(max,num);
            set.insert(num);
        }
        
        if (max < 0)
            return 1;
        
        for (int i = 1; i <= max; i++){
            if (set.find(i) == set.end())
                return i;
        }
        
        return max+1;
    }
};
// Time: O(n)
// Space: O(n)

class BestSolution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 1;
        
        bool hasOne = false;
        for (int & num:nums){
            if (num ==  1){
                hasOne = true;
                break;
            }
        }
        
        if (!hasOne)
            return 1;
        
        if (n == 1)
            return 2;
        
        // clean up
        // [1,2,3,4]
        for (int & num:nums){
            if (num <= 0 || num > n)
                num = 1;
        }
            
        // mark the presence
        for (int & num:nums)
            if (abs(num) == n)
                nums[0] = -abs(nums[0]);
            else nums[abs(num)] = -abs(nums[abs(num)]);
        
        // find the answer
        // [1,2,3]
        // [-1,-2,-3]
        for (int i=1;i<n;i++)
            if (nums[i] > 0)
                return i;
        
        if (nums[0] > 0)
            return n;
        
        return n+1;        
    }
};
// Time: O(n)
// Space: O(1)


int main(){
    Solution sol;
    
    vector<int> nums1{1,2,0};
    assert(sol.firstMissingPositive(nums1) == 3);

    vector<int> nums2{3,4,-1,1};
    assert(sol.firstMissingPositive(nums2) == 2);

    vector<int> nums3{7,8,9,11,12};
    assert(sol.firstMissingPositive(nums3) == 1);

    cout << "Passed!" << endl;
    return 0;
}
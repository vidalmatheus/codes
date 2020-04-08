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
    int pivotIndex(vector<int>& nums) {
        if (nums.size()==1)
            return 0;
        
        int totalSum = 0;
        
        for (int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }
        
        int leftSum = 0;
        for (int i=0;i<nums.size();i++){
            if (i>0)
                leftSum+=nums[i-1];
            int rightSum = totalSum-leftSum-nums[i];
            if (leftSum == rightSum)
                return i;
        }
        
        return -1;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    vector<int> nums = {1, 7, 3, 6, 5, 6};

    Solution sol;
    cout << sol.pivotIndex(nums) << endl;

    return 0;
}
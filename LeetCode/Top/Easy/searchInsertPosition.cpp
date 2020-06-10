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
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while (left <= right){
            int mid = left + (right-left)/2;
            if (target > nums[mid])
                left = mid+1;
            else if (target < nums[mid])
                right = mid-1;
            else return mid;
        }
        
        return left;
    }
};
// Time: O(log n)
// Space: O(1)

int main(){
    vector<int> nums{0,2,4,5};
    int target = 1;

    Solution sol;
    cout << sol.searchInsert(nums,target) << endl;

    return 0;
}
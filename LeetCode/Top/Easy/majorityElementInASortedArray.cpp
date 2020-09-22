#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        if (nums.size() == 1)
            return nums[0] == target;
        int mid = ((int)nums.size()-1)/2;
        return nums[mid] == target && nums[mid+1] == target;
    }
};
// Time: O(1)
// Space: O(1)

int main(){
    Solution sol;
    vector<int> nums{2,4,5,5,5,5,5,6,6};
    int target = 5;
    assert(sol.isMajorityElement(nums, target) == true);

    nums = {10,100,101,101};
    target = 101;
    assert(sol.isMajorityElement(nums, target) == false);

    nums = {1,2,3,4,5};
    target = 3;
    assert(sol.isMajorityElement(nums, target) == false);
    cout << "Passed!" << endl;
    return 0;
}
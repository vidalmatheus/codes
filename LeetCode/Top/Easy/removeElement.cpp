#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0)
            return 0;
        
        int j = 0;
        for (int i=0;i<nums.size();i++){
            if (nums[i] != val)
                nums[j++] = nums[i];
        }
        
        return j;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    vector<int> nums{0,1,2,2,3,0,4,2};
    int val = 2;

    Solution sol;
    cout << sol.removeElement(nums,val) << endl;

    return 0;
}

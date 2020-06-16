#include <bits/stdc++.h>

using namespace std;

static auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int max = 1;
        int curr = 1;
        if (nums.size()==0) return 0;
        for (int i=1;i<nums.size();i++){
            if (nums[i]>nums[i-1]){
                curr++;
                if (curr>max)
                        max = curr;
            }
            else curr = 1;
        }
        return max;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    vector<int> nums{1,0,3,5,4,7};

    Solution sol;
    cout << sol.findLengthOfLCIS(nums) << endl;

    return 0;
}

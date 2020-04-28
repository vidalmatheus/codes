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
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        
        vector<vector<int>> ans;

        permutation(ans,nums,0);

        return ans;
    }

    void permutation(vector<vector<int>> &ans, vector<int> &nums, int start) {
        if (start == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i=start;i<nums.size();i++) {
            swap(nums[start],nums[i]);
            permutation(ans,nums,start+1);
            swap(nums[start],nums[i]);
        }
    }
};
// Time: O(n*n!)
// Space: O(n*n!), because of the array as answer

int main() {
    vector<int> nums = {1,2,3};

    Solution sol;
    vector<vector<int>> ans = sol.permute(nums);

    for (int a:nums)
        cout << a << " ";
    cout << endl;

    for (vector<int> line:ans) { 
        cout << "[ ";
        for (int e:line)
            cout << e << " ";
        cout << "]\n";
    }

    return 0;
}

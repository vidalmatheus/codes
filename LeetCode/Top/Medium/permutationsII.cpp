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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
            if (shouldSwap(nums,start,i)){
                swap(nums[start],nums[i]);
                permutation(ans,nums,start+1);
                swap(nums[start],nums[i]);
            }
        }
    }
    
    bool shouldSwap(vector<int>& nums, int start, int curr) { 
        for (int i = start; i < curr; i++)  
            if (nums[i] == nums[curr]) 
                return false; // if the current element have happened before, don't swap
        return true; // otherwise, swap
    } 
    
};
// Time: O(n^2*n!)
// Space: O(n*n!), because of the array as answer

int main(){
    vector<int> nums{1,2,2};

    Solution sol;
    vector<vector<int>> ans = sol.permuteUnique(nums);

    for (vector<int> row:ans){
        for (int e:row)
            cout << e << " ";
        cout << endl;
    }

    return 0;
}

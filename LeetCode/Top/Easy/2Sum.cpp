#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums,int target) { // Time: O(n) - Space: O(1)
        if (nums.size()<2)
            return {};
        // now we find all possibilities with a given target
        vector<vector<int>> v;
        sort(nums.begin(),nums.end()); // O(nlogn)
        int start = 0;
        int end = nums.size()-1;
        while (start<end){ // like in twoSum problem
            if (nums[start]+nums[end]==target){
                v.push_back({nums[start],nums[end]});
                int currentStart = start;
                while (nums[currentStart]==nums[start] && start<end) // avoid duplicates
                    start++;
                int currentEnd = end;
                while (nums[currentEnd]==nums[end] && start<end) // avoid duplicates
                    end--;
            }
            else if (nums[start]+nums[end]<target){
                start++;
            }
            else {
                end--;
            }
        }
        return v;
    }
};

int main(){
    vector<int> nums = {2, 7, 11, 15, 1, 8};
    int target = 9;
    Solution sol;
    vector<vector<int>> ans = sol.twoSum(nums,target);
    for (auto i:ans){
        for (auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
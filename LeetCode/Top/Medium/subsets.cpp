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
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size()==0)
            return {};
        
        vector<vector<int>> ans;
        
        subsetsRecursive(nums,ans,{},0);
        
        return ans;
    }
    
    void subsetsRecursive(const vector<int> &nums,vector<vector<int>> &ans,vector<int> current,int pos) {
        if (pos == nums.size()){
            ans.push_back(current);
            return;
        }
        
        current.push_back(nums[pos]); // with element num[pos]
        subsetsRecursive(nums,ans,current,pos+1);
        current.pop_back(); // without element num[pos]
        subsetsRecursive(nums,ans,current,pos+1);        
    }
};
// Time: O(2^n)
// Space: O(2^n)

int main() {

    vector<int> nums = {0,1,2};

    Solution sol;
    vector<vector<int>> ans = sol.subsets(nums);

    for (vector<int> line:ans){
        for (int a:line){
            cout << a << " ";
        }
        cout << endl;
    }


    return 0;
}
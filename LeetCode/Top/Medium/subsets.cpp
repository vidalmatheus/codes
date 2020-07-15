#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class RecursiveSolution {
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
// Time: O(n*2^n)
// Space: O(n^2*2^n)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        
        vector<vector<int>> ans;
        vector<int> curr;
        rec(nums,ans,0,curr);
        
        return ans;
    }
    
    void rec(vector<int>& nums, vector<vector<int>>& ans, int pos, vector<int>& curr){
        if (pos == nums.size()){
            ans.push_back(curr);
            return;
        }
        
        curr.push_back(nums[pos]);
        rec(nums,ans,pos+1,curr);
        curr.pop_back();
        rec(nums,ans,pos+1,curr);
    }
};
// Time: O(n*2^n)
// Space: O(n*2^n)

class IterativeSolution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> results;
        for (int i = 0; i < pow(2, n); i++) {
            vector<int> v;
            for (int j = 0; j < n; j++) {
                if (i & (1<<j)) {
                    v.push_back(nums[j]);
                }
            }
            results.push_back(move(v));
        }
        return results;
    }
};
// Time: O(n*2^n)
// Space: O(n*2^n)

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
#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class LinearTimeSpaceSolution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        
        unordered_set<int> s;
        for (int i=0;i<nums.size();i++){
            if (s.find(nums[i])==s.end())
                s.insert(nums[i]);
            else ans.push_back(nums[i]);
        }
        
        for (int i=1;i<=nums.size();i++){
            if (s.find(i)==s.end()){ // not found
                ans.push_back(i);
                break;
            }
        }
        
        return ans;
    }
};
// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicated = -1;
        int missing = -1;
        
        for (int k:nums){
            if (nums[abs(k)-1]<0)
                duplicated = abs(k);
            else nums[abs(k)-1]*=-1;
        }
        
        for (int i=1;i<=nums.size();i++)
            if (nums[i-1]>0)
                missing = i;
    
        
        return {duplicated,missing};
    }
};
// Time: O(n)
// Space: O(1)



int main() {
    vector<int> nums = {1,2,2,4};

    Solution sol;
    vector<int> ans = sol.findErrorNums(nums);

    cout << "[ ";
    for (int e:ans)
        cout << e << " ";
    cout << "]\n";

    return 0;
}
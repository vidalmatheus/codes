#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
[1,0]
 i
left:[1,1]
right:[1,1]
*/
class LinearSpaceSolution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size()==0)
            return {};
        
        vector<int> left(nums.size(),1);
        vector<int> right(nums.size(),1);
        
        for (int i=1;i<nums.size();i++)
            left[i]*=nums[i-1]*left[i-1];
        
        for (int i=(int)nums.size()-2;i>=0;i--)
            right[i]*=nums[i+1]*right[i+1];
                
        vector<int> ans(nums.size(),1);
        for (int i=0;i<nums.size();i++)
            ans[i]=left[i]*right[i];
        
        return ans;
    }
};
// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size()==0)
            return {};
        
        vector<int> ans(nums.size(),1);
        
        for (int i=1;i<nums.size();i++)
            ans[i]*=nums[i-1]*ans[i-1];
        
        int right = 1;
        for (int i=(int)nums.size()-1;i>=0;i--){
            ans[i]*=right;
            right*=nums[i];
        }
                
        return ans;
    }
};
// Time: O(n)
// Space: O(n), only for the answer, no extra space was needed

int main(){
    vector<int> nums = {1,2,3,4};

    Solution sol;
    vector<int> ans = sol.productExceptSelf(nums);

    for (int e:ans)
        cout << e << " ";

    return 0;
}

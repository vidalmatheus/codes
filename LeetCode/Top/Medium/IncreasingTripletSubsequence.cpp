#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class DPSolution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size()<3)
            return false;
        
        vector<int> dp(nums.size());
        for (int i=0;i<nums.size();i++){
            dp[i]=1;
            for (int j=0;j<i;j++){
                if (nums[j]<nums[i]){
                    dp[i]=dp[j]+1;
                    if (dp[i]==3)
                        return true;
                }
            }
        }
        
        return false;
    }
};
// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)
            return false;
        
        vector<int> right(nums.size(),INT_MAX); // max value from a value of a current index
        vector<int> left(nums.size(),INT_MIN); // min value until a value of a current index
        
        for(int i=nums.size()-1;i>=0;i--){
            if(i!=nums.size()-1)
            {
                right[i]=max(right[i+1],nums[i]);
            }
            else
                right[i]=nums[i];
        }
        
        for(int i=0;i<nums.size();i++){
            if(i!=0)
                left[i]=min(left[i-1],nums[i]);
            else
                left[i]=nums[i];
        }
        
        for(int i=1;i<nums.size()-1;i++){
            // if the current value is less than the max from it and more than the min until it, then we have a increasing triplet subsequence
            if(nums[i]<right[i+1] && nums[i]>left[i-1]) 
                return true;
        }
        return false;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    vector<int> nums = {1,2,3,4,5};

    Solution sol;
    sol.increasingTriplet(nums) ? cout << "true\n" : cout << "false\n";

    return 0;
}
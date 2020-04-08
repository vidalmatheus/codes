#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class MemoSolution { /*memoization technique  (top-dowm approach)*/
private:
    vector<int> memo;
public:
    int rob(vector<int>& nums) {
        memo.resize(nums.size()+1,-1);
        return robRecursion(nums,nums.size());
    }
    int robRecursion(vector<int>&nums,int n){
        if (n==0) return memo[n]=0;
        if (n==1) return memo[n]=nums[0];
        if (n==2) return memo[n]=max(nums[0],nums[1]);
        if (memo[n]!=-1) return memo[n];
        return memo[n]=max(nums[n-1]+robRecursion(nums,n-2),robRecursion(nums,n-1));
    }
};

class DPSolution { /*dynamic programming technique (bottom-up approach)*/
private:
    vector<int> dp; /*dp[n] stores the maximum amount of money that we can rob from n houses*/
public:
    int rob(vector<int>& nums){
        int dp[nums.size()+1];
        dp[0]=0;
        dp[1]=nums[0];
        dp[2]=max(nums[0],nums[1]);
        for (int i=3; i <= nums.size(); i++)
            dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
        return dp[nums.size()];
    }
};

class Solution {
public:
    int rob(vector<int>& nums){
        if (nums.size()==0) return 0;
        if (nums.size()==1) return nums[0];
        int dp[nums.size()];
        int pp=nums[0];
        int p=max(nums[0],nums[1]);
        int curr=p;
        for (int i=2;i<nums.size();i++){
            curr=max(nums[i]+pp,p);
            pp=p;
            p=curr;
        }
        
        return curr;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    vector<int> nums = {2,7,9,3,1};
    MemoSolution memo;
    cout << memo.rob(nums) << endl;
    DPSolution dp;
    cout << dp.rob(nums) << endl;
    Solution ConstantSpaceSol;
    cout << ConstantSpaceSol.rob(nums) << endl;
    return 0;
}

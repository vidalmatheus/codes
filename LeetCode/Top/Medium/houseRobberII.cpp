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
    int rob(vector<int>& nums) {
        if (nums.size()==0)
            return 0;
        
        if (nums.size()==1)
            return nums[0];
        
        int n = nums.size();
        
        return max(rob(nums,0,n-2,1),rob(nums,n-1,1,-1)); // rob the first house and not the last or rob the last and not the first
    }
    
    int rob(vector<int>& nums, int start, int end, int dir){
        int size = abs(end-start)+1;
        if (size==1) return nums[start];
        int dp[size];
        int pp=nums[start];
        int p=max(nums[start],nums[start+dir]);
        int curr=p;
        for (int i=start+2*dir;i!=end;i=i+dir){
            curr=max(nums[i]+pp,p);
            pp=p;
            p=curr;
        }

        return curr;
    }
};
// Time: O(n)
// Space: O(1)

class BetterSolution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        
        if (n == 1)
            return nums[0];
        
        return max(robLinear(nums,0,n-2), robLinear(nums,1,n-1));
    }
    
    int robLinear(vector<int>& nums, int start, int end){
        int n = end-start+1;
        if (n == 0)
            return 0;
        
        if (n == 1)
            return nums[start];
        
        vector<int> dp(n);
        int prevPrev = 0;
        int prev = nums[start];
        int curr;
        for (int i=start+1;i<=end;i++){
            curr = max(prev, prevPrev + nums[i]);
            prevPrev = prev;
            prev = curr;
        }
        
        return curr;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    vector<int> nums = {1,2,1,1};

    Solution sol;
    cout << sol.rob(nums) << endl;

    return 0;
}

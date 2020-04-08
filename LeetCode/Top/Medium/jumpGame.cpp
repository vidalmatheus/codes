#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class DPSolution { // Dynamic Programming
public:
    bool canJump(vector<int>& nums) {
        if (nums.size()==0)
            return true;
        
        vector<bool> dp(nums.size(),false);
        dp[0]=true;
        
        for (int i=1;i<dp.size();i++){
            for (int j=0;j<i;j++){
                if (dp[j] && (i-j)<=nums[j])
                    dp[i]=true|dp[i];
            }
        }
        
        return dp.back();
    }
};
// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size()==0)
            return true;
        
        int furthestReachSoFar = 0;
        for (int i=0;i<nums.size() && i<=furthestReachSoFar;i++){
            if (i>furthestReachSoFar)
                break;
            if (i+nums[i] > furthestReachSoFar)
                furthestReachSoFar = i+nums[i];
        }
        
        return furthestReachSoFar>=(nums.size()-1);
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    // vector<int> nums = {2,3,1,1,4};
    vector<int> nums = {3,2,1,0,4};

    Solution sol;
    sol.canJump(nums) ? cout << "true\n" : cout << "false\n";

    return 0;
}

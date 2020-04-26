#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*

17:05h

[1] and [5,11,5]
[5] and [1,11,5]
[11] and [1,5,5] ok --> true;
[5] and [1,5,11]

[1] and [2,3,5]
[2] and [1,3,5]
[3] and [1,2,5]
[5] and [1,2,3]

sumA + sumB = globalSum --> find linear time
sumA = sumB --> sumA = sumB = globalSum/2

All I need is to find if there is a subset with sum globalSum/2

rec(nums,pos,sum,gloablSum):
    if sum == globalSum/2
        return true
    if pos == numsLength
        return false

    return rec(nums,pos+1,sum+nums[pos],globalSum) || rec(nums,pos+1,sum,globalSum);

// first example

globalSum: 22

rec(0,0):
    return rec(1,1) || rec(1,0) = true
    
    rec(1,1):
        return rec(2,6) || rec(2,1) = true
        
        rec(2,6): 
            return rec(3,17) || rec(3,6) = true
            
            rec(3,17): false
            
            rec(3,6): 
                return rec(4,11) + rec(4,6) = true
                
                rec(4,11): true
                rec(4,6): false


// other example
[1,2,3,5]

//globaSum: 11
globalSum/2: 5.5

        
        /    |     |    \
       1     2     3     5
      /|\   /|\   /|\   /|\
     2 3 5 1 3 5 1 2 5 1 2 3
    /\/\/\/\/\/\/\/\/\/\/\/\    
        
        
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size()==0)
            return true;
        
        int globalSum = 0;
        for (int num:nums)
            globalSum += num;
        
        if (globalSum%2!=0)
            return false;
        
        return rec(nums,0,0,globalSum);
    }
    
    bool rec(vector<int>& nums, int pos, int sum, int globalSum){
        if (sum == globalSum/2)
            return true;
        if (pos == nums.size())
            return false;

        return rec(nums,pos+1,sum+nums[pos],globalSum) || rec(nums,pos+1,sum,globalSum);
    }
};
// Time: O(2^n)
// Space: O(n)

class Solution { // Dynamic Programming (memoization) - Top-Down
private:
    vector<vector<int>> dp;
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size()==0)
            return true;
        
        int globalSum = 0;
        for (int num:nums)
            globalSum += num;
        
        if (globalSum%2!=0)
            return false;
        
        int targetSum = globalSum/2;
        dp.resize(nums.size(),vector<int>(targetSum+1,-1));
        
        return rec(nums,0,0,targetSum);
    }
    
    bool rec(vector<int>& nums, int pos, int sum, int targetSum){
        if (sum == targetSum)
            return true;
        if (pos == nums.size() || sum > targetSum)
            return false;

        if (dp[pos][sum]!=-1)
            return dp[pos][sum];
        
        return dp[pos][sum] = rec(nums,pos+1,sum+nums[pos],targetSum) || rec(nums,pos+1,sum,targetSum);
    }
};
// Time: O(n*SUM/2)
// Space: O(n*SUM/2)

class BottomUpSolution { // Dynamic Programming - Bottom-Up
private:
    vector<vector<int>> dp;
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size()==0)
            return true;
        
        int globalSum = 0;
        for (int num:nums)
            globalSum += num;
        
        if (globalSum%2!=0)
            return false;
        
        int targetSum = globalSum/2;
        dp.resize(nums.size(),vector<int>(targetSum+1,-1));
        
        /*
            0 1 2 3 4 5 6 7 8 9 10 11
        1   T T F F F F F F F F F F F
        5   T T F F F T T 
        11  T
        5   T                      []
    
        */
    
        for (int j=0;j<dp[0].size();j++)
            dp[0][j] = nums[0] == j ? true : false;
        
        for (int i=0;i<dp.size();i++)
            dp[i][0] = nums[i] >= 0 ? true : false;
        
        for (int i=1;i<dp.size();i++)
            for (int j=1;j<dp[0].size();j++)
                dp[i][j] = j >= nums[i] ? dp[i-1][j-nums[i]] || dp[i-1][j] : dp[i-1][j];
        
        return dp[nums.size()-1][targetSum];
    }
};
// Time: O(SUM/2)
// Space: O(SUM/2)

class BetterBottomUpSolution { // Dynamic Programming - Bottom-Up
private:
    vector<int> dp;
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size()==0)
            return true;
        
        int globalSum = 0;
        for (int num:nums)
            globalSum += num;
        
        if (globalSum%2!=0)
            return false;
        
        int targetSum = globalSum/2;
        dp.resize(targetSum+1,false);
        
        /*
            0 1 2 3 4 5 6 7 8 9 10 11
        1   T T F F F F F F F F F F F
        5   T T F F F T T 
        11  T
        5   T                      []
    
        */
    
        for (int j=0;j<dp.size();j++)
            dp[j] = (nums[0] == j || j == 0) ? true : false;
        
        vector<int> curr(targetSum+1,false);
        for (int i=1;i<nums.size();i++){
            for (int j=0;j<dp.size();j++)
                curr[j] = j >= nums[i] ? dp[j-nums[i]] || dp[j] : dp[j];
            dp = curr;
        }
        
        return dp[targetSum];
    }
};
// Time: O(n*SUM)
// Space: O(SUM)

int main(){
    vector<int> nums = {1,5,11,5};

    Solution sol;
    sol.canPartition(nums) ? cout << "true\n" : cout << "false\n";

    return 0;
}

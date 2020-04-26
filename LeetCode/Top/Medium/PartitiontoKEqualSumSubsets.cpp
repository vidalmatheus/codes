#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
[4,3,2,3,5,2,1], k=4 

targetSum: 5
counter: 0+1+1+1...

rec(0,0):
    rec(1,4):
        rec(2,7): +0
            
        rec(2,4):
            rec(3,6): +0
            
            rec(3,4):
                rec(4,7):+0
                
                rec(4,4): 
                    rec(5,9):+0
                    
                    rec(5,4): 
                        rec(6,6):+0
                        
                        rec(6,5):+1
    
    rec(1,0): 
        rec(2,3):
            rec(3,5):+1
            
            rec(3,3):
                rec(4,6):+0
                
                rec(4,3):
                    rec(5,8):+0
                    
                    rec(5,3): 
                        rec(6,5):+1
                        
                        rec(6,3):
                            rec(7,4):+0
                            
                            rec(7,3):+0
        rec(2,0):
                 ...   

*/

class RecursiveSolution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (nums.size()==0)
            return true;
        
        int globalSum = 0;
        for (int num:nums)
            globalSum += num;
        
        if (globalSum%k!=0)
            return false;
        
        int targetSum = globalSum/k;
        
        vector<bool> used(nums.size(),false);        
        
        return rec(nums,0,0,targetSum,k,used);
    }
    
    bool rec(vector<int>& nums, int pos, int sum, int targetSum, int k, vector<bool>& used){
        if (k==1)
            return true;
        
        if (sum > targetSum)
            return false;
        
        if (sum == targetSum)
            return rec(nums,0,0,targetSum,k-1,used);
        
        for (int i=pos;i<nums.size();i++){
            if (!used[i]){
                used[i]=true;
                if (rec(nums,i+1,sum+nums[i],targetSum,k,used))
                    return true;
                used[i]=false;
            }
        }
        
        return false;        
    }
};
// Time: O(?)
// Space: O(n)

class BitMaskSolution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (nums.size()==0)
            return true;
        
        int globalSum = 0;
        for (int num:nums)
            globalSum += num;
        
        if (globalSum%k!=0)
            return false;
        
        int targetSum = globalSum/k;        
        int used = 0;
        
        return rec(nums,0,0,targetSum,k,used);
    }
    
    bool rec(vector<int>& nums, int pos, int sum, int targetSum, int k, int& used){
        if (k==1)
            return true;
        
        if (sum > targetSum)
            return false;
        
        if (sum == targetSum)
            return rec(nums,0,0,targetSum,k-1,used);
        
        int n = nums.size();
        for (int i=pos;i<n;i++){
            if ((used&(1<<(n-i-1)))==0){
                used |= (1<<(n-i-1));
                if (rec(nums,i+1,sum+nums[i],targetSum,k,used))
                    return true;
                used &= ~(1<<(n-i-1));
            }
        }
        
        return false;        
    }
};
// Time: O(n*2^n)
// Space: O(n)


class Solution { // memoization with bit masking
private:
    unordered_map<int,bool> memo;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (nums.size()==0)
            return true;
        
        int globalSum = 0;
        for (int num:nums)
            globalSum += num;
        
        if (globalSum%k!=0)
            return false;
        
        int targetSum = globalSum/k;        
        int used = 0;
        
        return rec(nums,0,0,targetSum,k,used);
    }
    
    bool rec(vector<int>& nums, int pos, int sum, int targetSum, int k, int& used){
        if (k==1)
            return true;
        
        if (sum > targetSum)
            return false;
        
        if (sum == targetSum)
            return memo[used] = rec(nums,0,0,targetSum,k-1,used);
        
        if (memo.find(used)!=memo.end()) // found
            return memo[used];
        
        int n = nums.size();
        for (int i=pos;i<n;i++){
            if ((used&(1<<(n-i-1)))==0){
                used |= (1<<(n-i-1));
                if (rec(nums,i+1,sum+nums[i],targetSum,k,used))
                    return memo[used] = true;
                used &= ~(1<<(n-i-1));
            }
        }
        
        return memo[used] = false;        
    }
};
// Time: O(n*2^n)
// Space: O(n)

int main() {
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;

    Solution sol;
    sol.canPartitionKSubsets(nums,k) ? cout << "true\n" : cout << "false\n";

    return 0;
}

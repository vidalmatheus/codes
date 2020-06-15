#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class BruteForceSolution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        
        vector<int> currSubset;
        vector<int> maxSubset;
        rec(nums,0,currSubset,maxSubset);
        
        return maxSubset;
    }
    
    
    void rec(vector<int>& nums, int pos, vector<int>& currSubset, vector<int>& maxSubset){
        if (pos  == nums.size()){
            
            // check the specific property
            bool valid = true;
            for (int i=0;i<currSubset.size();i++){
                for (int j=i+1;j<currSubset.size();j++){
                    if (currSubset[i] % currSubset[j] != 0 && currSubset[j] % currSubset[i] != 0){
                        valid = false;
                        break;
                    }
                }
            }
            
            if (valid && currSubset.size() > maxSubset.size())
                maxSubset = currSubset;
                
            return;    
        }
        

        rec(nums,pos+1,currSubset,maxSubset);
        currSubset.push_back(nums[pos]);
        rec(nums,pos+1,currSubset,maxSubset);
        currSubset.pop_back();
    }
};
// Time: O(2^n * n^2)
// Space: O(n)

class AnotherBruteForceSolution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        
        vector<int> currSubset;
        vector<int> maxSubset;
        rec(nums,0,currSubset,maxSubset);
        
        return maxSubset;
    }
    
    
    void rec(vector<int>& nums, int pos, vector<int>& currSubset, vector<int>& maxSubset){
        if (pos  == nums.size()){
            if (currSubset.size() > maxSubset.size())
                maxSubset = currSubset;
                
            return;    
        }
        

        rec(nums,pos+1,currSubset,maxSubset);
        
        // check if we can add
        bool valid = true;
        for (int i=0;i<currSubset.size();i++){
            if (currSubset[i] % nums[pos] != 0 && nums[pos] % currSubset[i] != 0){
                valid = false;
                break;
            }
        }
        
        if (valid){
            currSubset.push_back(nums[pos]);
            rec(nums,pos+1,currSubset,maxSubset);
            currSubset.pop_back();
        }
    }
};
// Time: O(2^n * n^2)
// Space; O(n)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size()==0) 
            return {};
        
        sort(nums.begin(),nums.end());
        
        int max=1;      //  longest divisible subsequence length
        int max_index = 0;
        vector<int> dp(nums.size());
        for (int i=0;i<dp.size();i++)
            dp[i]=1;
        for (int i=1;i<nums.size();i++){
            for (int j=0;j<i;j++){
                if ( nums[i] % nums[j] == 0 && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    if (dp[i]>max){
                        max = dp[i];
                        max_index=i;
                    }
                }                
            }
        }

        vector<int> LDS;
        int i = max_index;
        int counter = dp[max_index];
        while (i>=0 && LDS.size() != max){
            LDS.push_back(nums[i]);
            counter = dp[i];
            int j = i;
            i--;
            while (i >= 0 && (dp[i] != counter-1 || nums[j] % nums[i] != 0))
                i--;
            
        }
        
        return LDS;
    }
};
// Time: O(n^2)
// Space; O(n)

int main(){
    vector<int> nums{1,2,3};

    Solution sol;
    vector<int> ans = sol.largestDivisibleSubset(nums);

    for (int i:ans)
        cout << i << " ";
    cout << endl;

    return 0;
}
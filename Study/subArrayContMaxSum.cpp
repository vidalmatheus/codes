#include <bits/stdc++.h>

using namespace std;

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution { // Time: O(n) - Space: O(n) (Dynamic Programming)
public:
    vector<int> maxContiguousSubArray (vector<int> &nums){
        if (nums.size()==0) return {};
        vector<int> ans;
        int dp[nums.size()]; // it stores answers to the subproblems
        dp[0]=nums[0];
        int maxIndex = 0;
        int maxSum = dp[maxIndex];
        for (int i=1;i<nums.size();i++){
            dp[i] = max(dp[i-1]+nums[i],nums[i]); // start a new subarray or extends the previous one
            if (dp[i]>maxSum){
                maxSum=dp[i];
                maxIndex = i;
            }
        }
        int i = maxIndex;
        while (dp[i]!=nums[i]){
            ans.insert(ans.begin(),nums[i]);
            i--;
        }
        ans.insert(ans.begin(),nums[i]);
        return ans;
    }
};

class KadaneAlgorithm { // Time: O(n) - Space: O(1) (optimal solution)
public:
    int kadane (vector<int> &nums){
        if (nums.size()==0) return 0;
        int max_so_far = nums[0]; 
        int curr_max = nums[0]; 
        for (int i = 1; i < nums.size(); i++){
                curr_max = max(nums[i], curr_max+nums[i]); 
                max_so_far = max(max_so_far, curr_max); 
        }
        return max_so_far; 
    }
    vector<int> maxContiguousSubArray (vector<int> &nums){
        if (nums.size()==0) return {};
        int max_so_far = nums[0]; 
        int curr_max = nums[0]; 
        int start = 0;
        int end = 0;
        for (int i = 1; i < nums.size(); i++){
            curr_max = max(nums[i], curr_max+nums[i]);
            max_so_far = max(max_so_far, curr_max); 
            if (max_so_far==curr_max){ // a new max was setted 
                if (curr_max==nums[i])
                    start = i;
                end = i;
            }
        }
        vector<int> ans;
        for (int i=start;i<=end;i++)
            ans.push_back(nums[i]);
        return ans;
    }
};

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    KadaneAlgorithm sol;
    cout << "Max Contiguous Subarray Sum: ";
    vector<int> subArray = sol.maxContiguousSubArray(nums);
    int maxSum = 0;
    for (auto i:subArray){
        maxSum+=i;
        cout << i << " ";
    }
    cout << "\n" << maxSum << endl;
    return 0;
}
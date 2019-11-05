#include <bits/stdc++.h>

using namespace std;

static auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size()==0) return 0;
        vector<int> LIS;
        int max=1;      //  longest increasing subsequence length
        int max_index;
        vector<int> dp(nums.size());
        for (int i=0;i<dp.size();i++)
            dp[i]=1;
        for (int i=1;i<nums.size();i++){
            for (int j=0;j<i;j++){
                if (nums[i]>nums[j] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    if (dp[i]>max){
                        max = dp[i];
                        max_index=i;
                    }
                }                
            }
        }
        cout << "dp: ";
        for (auto e:dp)
            cout << e << " ";
        cout << endl;
        for (int i=0;i<max_index;i++){
            if (nums[i+1]>nums[i])
                LIS.push_back(nums[i]);
        }
        LIS.push_back(nums[max_index]);
        cout << "LIS: ";
        for (auto e:LIS)
            cout << e << " ";
        cout << endl;
        return max;
    }
};
// TIME: O(n^2)
// SPACE: O(n)

class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size()==0) return 0;
        vector<int> LIS;
        LIS.push_back(nums[0]);
        unordered_map<int,int> parent;
        for (int i=1;i<nums.size();i++){
            auto it = lower_bound(LIS.begin(),LIS.end(),nums[i]); // binary search
            int index = it-LIS.begin();
            if (index>=LIS.size())
                LIS.push_back(nums[i]);
            else LIS[index] = nums[i];
            parent[nums[i]] = LIS[index-1];
        }

        // show LIS
        cout << "LIS: ";
        int k = LIS[LIS.size()-1];
        cout << k << " ";
        for (int i=LIS.size()-1;i>=1;i--){
            cout << parent[k] << " ";
            k = parent[k];
        }
        cout << endl;
        
        return LIS.size();
    }

};

int main(){
    vector<int> nums={10,9,2,5,3,7,101,18};
    /* vector<int> nums={3,1,5,2,6,4,9,10,7}; */
    Solution sol;
    cout << sol.lengthOfLIS(nums) << endl;
    Solution2 sol2;
    cout << sol2.lengthOfLIS(nums) << endl;
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class SolutionBAD { // TIME LIMIT EXCEEDED!!!
public:
    vector<vector<int>> threeSum(vector<int>& nums) { // Time: O(n^2) - Space: O(n)
        if (nums.size()<3)
            return {};
        unordered_map<int,int> targets;
        for (int i=0;i<nums.size();i++){ // save unique values
            targets[-nums[i]]=i;
        }
        // now we find all possibilities with a given target
        vector<vector<int>> ans;
        for (auto i=targets.begin();i!=targets.end();++i){
            vector<vector<int>> v = twoSum(nums,i->first,i->second); 
            if (v.size()!=0)
                concatenate(ans,v);
        }
        return ans;
    }
    vector<vector<int>> twoSum(vector<int>&nums,int target,int targetIndex){ // Time: O(n) - Space: O(n)
        vector<vector<int>> v;
        unordered_set<int> hashSet;
        for (int i=0;i<nums.size();i++){
            if (i==targetIndex){
                i++;
                if (i==nums.size())
                    break;
            }
            if (hashSet.count(target-nums[i])!=0){ // if it's in hashSet
                int a = target-nums[i];
                int b = nums[i];
                int c = -target;
                if (a<=b && a<=c){
                    if (b<=c)
                        v.push_back({a,b,c});
                    else v.push_back({a,c,b});
                }
                else if (b<=a && b<=c){
                    if (a<=c)
                        v.push_back({b,a,c});
                    else v.push_back({b,c,a});
                }
                else{ // (c<=a && c<=b)
                    if (a<=b)
                        v.push_back({c,a,b});
                    else v.push_back({c,b,a});
                }
            }
            else{
                hashSet.insert(nums[i]);
            }
        }
        return v;
    }
    void concatenate(vector<vector<int>> &ans, vector<vector<int>> &v){ // Time: O(n^2) - Space: O(1)
        for (int i=0;i<v.size();i++){
            bool alreadyExists = false;
            for (auto ans_line:ans){
                if (ans_line==v[i]){
                    alreadyExists = true;
                    break;
                }    
            }
            if (!alreadyExists)
                ans.push_back(v[i]);
        }
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) { // Time: O(n^2) - Space: O(1)
        if (nums.size()<3)
            return {};
        // now we find all possibilities with a given target
        vector<vector<int>> v;
        sort(nums.begin(),nums.end()); // O(nlogn)
        for (int i=0;i<=nums.size()-3;i++){
            if (i==0 || nums[i]>nums[i-1]){ // if statment to avoid dulicates
                int start = i+1;
                int end = nums.size()-1;
                int target = 0;
                int sum = target - nums[i];
                while (start<end){ // like in twoSum problem
                    if (nums[start]+nums[end]==sum){
                        v.push_back({nums[i],nums[start],nums[end]});
                        int currentStart = start;
                        while (nums[currentStart]==nums[start] && start<end) // avoid duplicates
                            start++;
                        int currentEnd = end;
                        while (nums[currentEnd]==nums[end] && start<end) // avoid duplicates
                            end--;
                    }
                    else if (nums[start]+nums[end]<sum){
                        start++;
                    }
                    else {
                        end--;
                    }
                }
            }
        }
        return v;
    }
};

class SolutionSet {
public:
    vector<vector<int>> threeSum(vector<int>& nums) { // Time: O(n^2) - Space: O(1)

    }
};

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution sol;
    vector<vector<int>> ans = sol.threeSum(nums);
    for (auto i:ans){
        for (auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
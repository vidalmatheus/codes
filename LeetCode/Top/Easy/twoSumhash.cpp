/* Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
#include <bits/stdc++.h>

using namespace std;

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/*
class Solution { // O(nlog(n))
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2); // answer
        unordered_map<int,int> hash(nums.size());
        int dif;
        for (int i = 0; i < nums.size(); i++){
            dif = target - nums[i];
            // find method searchs by key!!
            if (hash.find(dif)!=hash.end()){ // verfies if dif is in it
                ans[0] = hash.find(dif)->second;
                ans[0] = i;  // store (i,index(dif))
                return ans;
            }
            else{
                hash.insert(make_pair(nums[i],i));
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash(nums.size());
        for (int i=0; i<nums.size(); i++){
            int n = target - nums[i];
            if (hash.count(n)!=0)
                return {hash[n], i};
            else
                hash[nums[i]] = i;
        }
        return {0,0}; // just to return something, but it will never be executed, because each input has exactly ONE solution
    }
};


int main()
{
    vector<int> v = {2,7,11,15};
    int target = 9;
    Solution *obj = new Solution();
    vector<int> ans;
    /*     
    unordered_map<int,int> umap(5);
    umap.insert(make_pair(1,2));
    umap[3] = 5;    
    for (auto it:umap){
        cout << it.first << " " << it.second << endl;
    }
    cout << umap.find(1)->second << endl; 
    */
    ans = obj->twoSum(v, target);
    cout << ans[0] << " " << ans[1] << endl;

    
    return 0;
}
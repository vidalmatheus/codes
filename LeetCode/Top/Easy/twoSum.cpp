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

class Solution { // O(nlog(n))
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<int> aux;
        aux = nums;
        sort(aux.begin(),aux.end()); // nlog(n)
        bool finish = false;
        for (int i = 0; i<aux.size() && !finish; i++){
            if (binary_search(aux.begin(),aux.end(),target-aux[i])){ // log(n)
                std::vector<int>::iterator it0,it1;
                it0 = find(nums.begin(),nums.end(),aux[i]); // find the first appereance in vector
                it1 = find(nums.begin(),it0,target-aux[i]); // find on the left side
                if (it1==it0 && nums.size()>1)
                    it1 = find(it0+1,nums.end(),target-aux[i]); // find on the right side
                if (it0-nums.begin() != it1-nums.begin()){
                    ans.push_back(it0-nums.begin());
                    ans.push_back(it1-nums.begin());
                    finish = true;
                }
            } 
        }
        return ans;
    }
};

int main()
{
    vector<int> v = {0,4,3,0};
    int target = 0;
    Solution *obj = new Solution();
    vector<int> ans;
    ans = obj->twoSum(v, target);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    
    return 0;
}
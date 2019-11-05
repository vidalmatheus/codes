/* Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
 */

#include <bits/stdc++.h>

using namespace std;

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s; 
        for (int i=0;i<nums.size();i++){
            if (s.find(nums[i])!=s.end())
                return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
// Time: O(n)
// Space: O(n)
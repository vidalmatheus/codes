/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
*/
#include <bits/stdc++.h>

using namespace std;

//----------Naive Solution---------- 
// Time: O(n^2)
// Space: O(1)
/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        for (auto a:nums)
            cout << a << " ";
        cout << endl;
        for (int i = 0, j = 1; j < nums.size(); i++){
            while(nums[j] == nums[i]){
                j++;
            }
            if (j < nums.size()){
                nums[i+1] = nums[j];
                count++;
            } 
            for (auto a:nums)
                cout << a << " ";
            cout << endl;
        }
        return count;
    }
};
*/

//----------Desired Solution---------- 
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1; // the first element is always unique
        int len = nums.size();
        if (nums.size() == 0) return 0;
        for (int i = 0; i < len-1; i++){
            if (nums[i]!=nums[i+1]){
                nums[count] = nums[i+1];
                count++;
            }
        }
        return count;
    }
};



int main(){
    //ector<int> v = {1,1,2};
    //vector<int> v = {0,0,1,1,1,2};
    vector<int> v = {};
    Solution *obj = new Solution();
    int ans = obj->removeDuplicates(v);
    cout << "Initial length: " << v.size() << endl;
    cout << "Final length: " << ans << endl;
    
    return 0;
}
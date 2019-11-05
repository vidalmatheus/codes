/* Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations. */

#include <bits/stdc++.h>

using namespace std;

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/* class Solution { // Solution: copying values
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> nz;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)
                nz.push_back(nums[i]);
        }
        for(auto e:nz)
            cout << e << " ";
        cout << endl;
        for(int i=0;i<nums.size();i++){
            if(i<nz.size()) nums[i]=nz[i];
            else nums[i]=0;
        }
    }
};
*/
class Solution {
public:
    void moveZeroes(vector<int> &nums){
        int index=0;
        for (int i=0;i<nums.size();i++){ // O(n) to put non-zero values at the beginning of nums
            if(nums[i]!=0){
                nums[index]=nums[i];
                index++;
            }   
        }
        for(int i=index;i<nums.size();i++){ // O(n-index) to put null values at the end of nums 
            nums[i]=0;
        }
    }
};


int main(){
    vector<int> nums={0,1,0,3,12};
    Solution sol;
    sol.moveZeroes(nums);
    for(auto e:nums)
        cout << e << " ";
    cout << endl;
 
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size()==0)
            return;
        
        int pivot = findPivot(nums);
        swapNext(nums,pivot);
        reverseArray(nums,pivot,nums.size()-1);
    }
    
    int findPivot(vector<int>& nums){ // Time: O(n) & Space: O(1)
        for (int i=nums.size()-1;i>0;i--){
            if (nums[i-1]<nums[i])
                return i;
        }
        return 0;
    }
    
    void swapNext(vector<int>&nums, int pivot){ // Time: O(n) & Space: O(1)
       if (pivot==0)
            return;
        for (int i=nums.size()-1;i>=pivot;i--){
            if (nums[i]>nums[pivot-1]){
                swap(nums[i],nums[pivot-1]);
                break;
            }
        }
    }
    
    void reverseArray(vector<int>& nums, int left, int right){ // Time: O(n) & Space: O(1)
        for (int i=left,j=right;i<j;i++,j--)
            if (nums[i]!=nums[j])
                swap(nums[i],nums[j]);
    }
    
};
// Time: O(n)
// Space: O(1)

int main(){
    vector<int> nums{1,2,3};

    Solution sol;
    sol.nextPermutation(nums);

    cout << "[ ";
    for (int e:nums)
        cout << e << " ";
    cout << "]";

    return 0;
}

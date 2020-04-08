#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size()==0)
            return -1;
        
        int pivotIndex = findPivot(nums,0,nums.size()-1);
        cout << "Pivot: " << nums[pivotIndex] << endl;
        
        int left = 0;
        int right = nums.size()-1;
        if (pivotIndex+1<nums.size() && nums[pivotIndex+1]<=target && target<=nums[nums.size()-1]){
            left = pivotIndex+1;
            right = nums.size()-1;
        }
        else {
            left = 0;
            right = pivotIndex;
        }
        
        cout << "left: " << left << endl;
        cout << "right: " << right << endl;
        
        return binarySearch(nums,left,right,target);
    }
    
    int findPivot(const vector<int>& nums, int left, int right){
        while(left<right){
            int mid = left + (right-left)/2;
            if (nums[left]<nums[mid])
                left=mid;
            else right = mid;
        }
        
        return left;
    }
    
    int binarySearch(const vector<int>& nums, int left, int right, int target){
            while(left<=right){
            int mid = left+(right-left)/2;
            if (target<nums[mid])
                right=mid-1;
            else if (target>nums[mid])
                left=mid+1;
            else return mid;
        }
        
        return -1;
    }
    
};
// Time: O(log n)
// Space: O(1)

int main(){
    vector<int> nums = {3,4,5,6,1,2};
    int target = 2;

    Solution sol;
    cout << sol.search(nums,target) << endl;

    return 0;
}
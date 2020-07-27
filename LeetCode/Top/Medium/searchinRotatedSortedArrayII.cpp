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
    bool search(vector<int>& nums, int target) {
        if (nums.size()==0)
            return false;
        
        int pivotIndex = findPivot(nums,0,nums.size()-1);

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
        
        return binarySearch(nums,left,right,target);
    }
    
    int findPivot(const vector<int>& nums, int left, int right){            
        while(left < right){
            int mid=left+(right-left)/2;
            if (nums[left] == nums[left+1])
                left++;
            else if (nums[right-1] == nums[right])
                right--;
            else if(nums[mid]>nums[right])
                left=mid+1;
            else right=mid;
        }
        
        return left;
    }
    
    bool binarySearch(const vector<int>& nums, int left, int right, int target){
            while(left<=right){
            int mid = left+(right-left)/2;
            if (target<nums[mid])
                right=mid-1;
            else if (target>nums[mid])
                left=mid+1;
            else return true;
        }
        
        return false;
    }
    
};
// Time: O(log n), when we don't have duplicates, and O(n), when we have duplicates
// Space: O(1)

int main(){
    vector<int> nums{2,5,6,0,0,1,2};

    int target = 0;

    Solution sol;
    sol.search (nums,target) ? cout << "true\n" : cout << "false\n";

    return 0;
}

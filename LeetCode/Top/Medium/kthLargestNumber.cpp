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
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size()-1;
        while (left < right){
            int index = partition(nums,left,right);
            if (index == nums.size()-k)
                return nums[index];
            else if (index < nums.size()-k)
                left = index+1;
            else
                right = index-1;
        }
        return -1;
    }
    // The following implementation of quicksort doesn't returns the correct index for the pivot;
    // Sometimes it works, sometimes it doesn't 
    int partitionGayle (vector<int> &nums,int left, int right){ // the same as in quicksort!!! 
        int pivot = nums[left + (right-left)/2]; // median point
        while (left<right){
            while (nums[left]<pivot)
                left++;
            while (nums[right]>pivot)
                right--;
            if (left<right){
                swap(nums[left],nums[right]);
                left++;
                right--;
            }
        }
        return left;
    }

    int partition (vector<int> &nums,int left,int right){
        int pivotIndex = left+(right-left)/2;
        int pivot = nums[pivotIndex];
        swap(nums[pivotIndex],nums[right]); // put the median value on right corner an then the code is just like we're already know
        int i = left;
        for (int j=left;j<right;j++){
            if (nums[j]<pivot){
                swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[i],nums[right]);
        return i; 
    }
};
// Time: O(n)
// Space: O(1) --> inplace solution!

int main(){
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    Solution sol;
    cout << sol.findKthLargest(nums,k) << endl;
    return 0;
}
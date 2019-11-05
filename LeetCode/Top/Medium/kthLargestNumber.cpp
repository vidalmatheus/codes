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
    int partition (vector<int> &nums,int left, int right){ // the same as in quicksort!!!
        int pivot = nums[left + (right-left)/2]; // median point
        while (left<right){
            while (nums[left]<pivot)
                left++;
            while (nums[right]>pivot)
                right--;
            if (left<right){
                swap(nums,left,right);
                left++;
                right--;
            }
        }
        return left;
    }
    void swap (vector<int> &nums,int i,int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j]=tmp;
    }
};
// Time: O(n)
// Space: O(1) --> inplace solution!

int main(){

    vector<int> nums = {1,2,3,4,5,6};
    int k = 2;
    Solution sol;
    cout << sol.findKthLargest(nums,k) << endl;
    return 0;
}
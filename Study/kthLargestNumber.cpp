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
        while (left<=right){
            int index = partition(nums,left,right);
            cout << "index: " << index << " n-k: " << nums.size()-k << endl;
            for (auto i:nums)
                cout << i << " "; 
            cout << endl;
            if (index == nums.size()-k)
                return nums[index];
            else if (index < nums.size()-k)
                left = index;
            else if (index > nums.size()-k)
                right = index-1;
        }
        return -1;
    }
    int partitionR (vector<int> &nums,int left, int right){ // the same as in quicksort!!!
        int pivot = nums[right]; // pivot is the always at the right pointer
        int i = left-1;
        for (int j=left;j<right;j++){
            if (nums[j]<pivot){
                i++;
                swap(nums,i,j);
            }
        }
        swap(nums,i+1,right);
        return i+1;  
    }
    int partition (vector<int> &nums,int left,int right){
        int pivotIndex = left+(right-left)/2;
        int pivot = nums[pivotIndex];
        swap(nums,pivotIndex,right); // put the median value on right corner an then the code is just like we're already know
        int i = left-1;
        for (int j=left;j<right;j++){
            if (nums[j]<pivot){
                i++;
                swap(nums,i,j);
            }
        }
        swap(nums,i+1,right);
        return i+1; 
    }
    void swap (vector<int> &nums,int i,int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    void quicksort(vector<int> &nums,int left,int right){
        if (left>=right) return;
        int index = partition(nums,left,right);
        quicksort(nums,left,index-1);
        quicksort(nums,index,right);
    }
};
// Time: O(n)
// Space: O(1) --> inplace solution!

int main(){

    /* vector<int> nums = {3,2,1,5,6,4}; // 1,2,3,4,5,6 */
    /* vector<int> nums = {1,2,6,4,3,5,9}; */
    vector<int> nums = {5,2,4,1,3,6,0};
    int k = 4;
    Solution sol;
    //sol.quicksort(nums,0,nums.size()-1);
/*     for (auto i:nums)
        cout << i << " "; */
    cout << sol.findKthLargest(nums,k) << endl;
    return 0;
}
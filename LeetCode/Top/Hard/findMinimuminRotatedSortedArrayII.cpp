#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
[4,5,6,7,0,1,2]
       l r   
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        int pivot = findPivot(nums);
        return nums[pivot];
    }
    
    int findPivot (vector<int>& nums){
        int left = 0;
        int right = nums.size()-1;
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
};
// Time: O(n)
// Space: O(1)

int main(){
    vector<int> nums{2,2,2,0,1};

    Solution sol;
    cout << sol.findMin(nums) << endl;

    return 0;
}

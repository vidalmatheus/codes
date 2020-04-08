#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution_Linear {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size()==0)
            return 0;
        
        int max = nums[0];
        int max_index = 0;
        for (int i=1;i<nums.size();i++)
            if (nums[i]>max){
                max = nums[i];
                max_index = i;
            }

        return max_index;
    }
};
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size()==0)
            return 0;
        
        int low = 0;
        int high = nums.size()-1;
        
        while (low<high){
            int mid = low + (high-low)/2;
            if (nums[mid] < nums[mid+1])
                low = mid+1;
            else high = mid;
        }
        
        return low;
    }
};
// Time: O(lg(n))
// Space: O(1)

int main(){
    vector<int> nums = {1,2,3,1};

    Solution sol;
    cout << sol.findPeakElement(nums) << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return 0;
        
        if (k <= 1)
            return 0;
        
        int left = 0;
        int right = 0;
        int product = 1;
        int counter = 0;
        while (right < nums.size()){
            product *= nums[right];
            
            while (product >= k){
                product /= nums[left];
                left++;
            }
            
            counter += right-left+1;
            right++;        
        }
        
        return counter;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    Solution sol;
    
    vector<int> nums1{10, 5, 2, 6};
    int k1 = 100;
    assert(sol.numSubarrayProductLessThanK(nums1,k1) == 8);

    vector<int> nums2{10,5,2,6,6,4,8,1};
    int k2 = 58;
    assert(sol.numSubarrayProductLessThanK(nums2,k2) == 16);

    vector<int> nums3{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int k3 = 3;
    assert(sol.numSubarrayProductLessThanK(nums3,k3) == 136);

    cout << "Passed!" << endl;
    return 0;
}
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
    int singleNonDuplicate(vector<int>& nums) {
        int XOR = nums[0];
        for (int i=1;i<nums.size();i++){
            XOR ^= nums[i];
        }
        
        return XOR;
    }
};
// Time: O(n)
// Space: O(1)

/*
 0 1 2 3 4 5 6 7 8
[1,1,2,3,3,4,4,8,8] 
           m

The first ocurrences happens at even indexes!
If not, we have to analyze 

*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        
        while (left < right){
            int mid = left + (right-left)/2;
            if (mid%2 == 0){ // even index (start of a pair)
                if (nums[mid]!=nums[mid+1])
                    right = mid;
                else left = mid+2;
            }
            else { // odd index (end of a pair)
                if (nums[mid]!=nums[mid-1])
                    right = mid-1;
                else left = mid+1;
            }
        }
        
        return nums[left];
    }
};
// Time: O(log n)
// Space: O(1)


int main(){
    vector<int> nums{1,1,2,3,3,4,4,8,8};

    Solution sol;
    cout << sol.singleNonDuplicate(nums) << endl;

    return 0;
}

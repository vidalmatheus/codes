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
    int findDuplicate(vector<int>& nums) { // Time: O(n) and Space: O(n)
        if (nums.size()==0)
            return 0;
        unordered_set<int> s;
        
        for (int i=0;i<nums.size();i++){
            if (s.find(nums[i])!=s.end())
                return nums[i];
            else s.insert(nums[i]);
        }
        return 0;
    }

    int findDuplicate_fast(vector<int>& nums) { // Time: O(n) and Space: O(1)
        if (nums.size()==0)
            return 0;
        
        int slow, fast;
        slow = fast = nums[0];
        
        do {
            slow=nums[slow];
            fast=nums[nums[fast]];
        } while (slow!=fast);
        
        int ptr1 = nums[0];
        int ptr2 = slow;
        while (ptr1 != ptr2) {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }
        
        return ptr1;
    }
};

int main() {
    vector<int> nums = {3,1,3,4,2};

    Solution sol;
    cout << sol.findDuplicate_fast(nums) << endl;

    return 0;
}
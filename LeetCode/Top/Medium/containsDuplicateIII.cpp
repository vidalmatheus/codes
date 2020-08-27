#include <bits/stdc++.h>

using namespace std;

static int speedup=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() == 0)
            return false;
        
        unordered_map<int,int> seen;
        for (int i=0;i<nums.size();i++){
            int num = nums[i];
            for (int j=0;j<=t;j++){
                if (seen.find(abs(num-j)) != seen.end())
                    if (i - seen[abs(num-j)] <= k)
                        return true;
                seen[abs(num-j)] = i;
            }
        }
        return false;
    }
};
// Time: O(n*t)
// Space: O(n)

int main(){
    Solution sol;

    vector<int> nums = {1,2,3,1};
    int k = 3; 
    int t = 0;
    assert(sol.containsNearbyAlmostDuplicate(nums,k,t) == true);

    cout << "Passed!" << endl;

    return 0;
}
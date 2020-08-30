#include <bits/stdc++.h>

using namespace std;

static int speedup=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class BruteForceSolution { // TLE
public:
    /**
     * @param nums: the given array
     * @param k: the given k
     * @param t: the given t
     * @return: whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
     */
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (nums.size() == 0)
            return false;
        
        for (int i=0;i<nums.size();i++){
            int end = i+k < nums.size() ? i+k : nums.size()-1;
            for (int j=i+1;j<=end;j++){
                long dif = (long)abs((long)nums[j]-(long)nums[i]);
                if (dif <= t)
                    return true;
            }
        }
        
        return false;
    }
};
// Time: O(n*k)
// Space: O(1)

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() == 0 || k <= 0 || t < 0)
            return false;
        
        set<long> kLastSet;
        for (int i=0;i<nums.size();i++){
            if (i > k) 
                kLastSet.erase(nums[i-k-1]);

            auto it = kLastSet.lower_bound((long)nums[i] - t); //  nums[i] - t <= *it
            
            if (it != kLastSet.end() && *it <= (long)nums[i] + t)
                return true;
            
            kLastSet.insert(nums[i]);
        }
        
        return false;
    }
};
// Time: O(n*log(k))
// Space: O(k)

int main(){
    BruteForceSolution sol;

    vector<int> nums = {1,2,3,1};
    int k = 3; 
    int t = 0;
    assert(sol.containsNearbyAlmostDuplicate(nums,k,t) == true);

    cout << "Passed!" << endl;

    return 0;
}
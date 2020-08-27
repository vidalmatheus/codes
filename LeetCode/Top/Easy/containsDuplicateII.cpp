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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return false;
        
        unordered_map<int,int> seen;
        for (int i=0;i<nums.size();i++){
            int num = nums[i];
            if (seen.find(num) != seen.end()){
                if (i - seen[num] <= k)
                    return true;
            }
            seen[num] = i;
        }
        return false;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    Solution sol;
    
    vector<int> A = {1,2,3,1};
    int k = 3;
    assert(sol.containsNearbyDuplicate(A,k) == true);

    A = {1,0,1,1};
    k = 1;
    assert(sol.containsNearbyDuplicate(A,k) == true);

    A = {1,2,3,1,2,3};
    k = 2;
    assert(sol.containsNearbyDuplicate(A,k) == false);

    cout << "Passed!" << endl;

    return 0;
}
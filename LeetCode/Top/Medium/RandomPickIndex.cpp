#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
private:
    unordered_map<int,vector<int>> m;
public:
    Solution(vector<int>& nums) {
        for (int i=0;i<nums.size();i++)
            m[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        if (m.find(target)!=m.end()){ // found
            int randomIndex = rand() % m[target].size();
            return m[target][randomIndex];
        }
        else return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

int main(){
    vector<int> nums{1,2,3,3,3};
    int target = 3;
    Solution* obj = new Solution(nums);
    cout << obj->pick(target) << endl;

    return 0;
}

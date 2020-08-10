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
    vector<int> findDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        
        int n = nums.size();
        vector<bool> seen(n+1,false);
        vector<int> ans;
        for (int i=0;i<n;++i){
            if (seen[nums[i]])
                ans.push_back(nums[i]);
            else seen[nums[i]] = true;
        }

        return ans;
    }
};
// Time: O(n)
// Space: O(n)

/*
     0 1 2 3 4 5 6 7
    [4,3,2,7,8,2,3,1]

1. do a traversal from index 0 to n-1
    1.1 tag elements once you see it with a minus symbol, since they are all positive integers
    1.2 if it is tag already, then add to the answer
2. return the answer

*/

class OptimumSolution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        
        int n = nums.size();
        vector<int> ans;
        for (int i=0;i<n;++i){
            int index_to_tag = abs(nums[i])-1;
            if (nums[index_to_tag] > 0) 
                nums[index_to_tag] *= -1;
            else ans.push_back(index_to_tag+1);        
        }
        
        return ans;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    vector<int> nums = {1,2,4,2,5,5,0,9};

    Solution sol;
    vector<int> ans = {2,5};
    assert(sol.findDuplicates(nums) == ans);

    cout << "Passed!" << endl;
    return 0;
}

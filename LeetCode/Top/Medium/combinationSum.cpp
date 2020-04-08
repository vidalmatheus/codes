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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size()==0)
            return {};

        vector<vector<int>> ans;
        vector<int> curr;
        findCombinations(candidates,0,target,curr,ans);
        
        return ans;
    }
    
    void findCombinations(vector<int>& candidates, int index, int target, vector<int>& curr, vector<vector<int>>& ans){
        if (target==0){
            ans.push_back(curr);
            return;
        }
        
        if (target<0)
            return;
        
        for (int i=index;i<candidates.size();i++){
            curr.push_back(candidates[i]);
            findCombinations(candidates,i,target-candidates[i],curr,ans);
            curr.pop_back();
        }
    }
};
// Time: 2^n
// Space: O(n)

int main(){
    vector<int> candidates = {2,3,6,7};
    int target = 7;

    Solution sol;
    vector<vector<int>> ans = sol.combinationSum(candidates,target);

    for (vector<int> line:ans){
        cout << "[ "; 
        for (int e:line)
            cout << e << " ";
        cout << "]\n";
    }

    return 0;
}
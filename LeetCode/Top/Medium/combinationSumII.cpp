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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size()==0)
            return {};
        
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end()); // smart way to deal with only unique candidate numbers
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
            if (i==index || candidates[i]!=candidates[i-1]){ // if clause to make sure that we're not taking the same candidate number
                curr.push_back(candidates[i]);
                findCombinations(candidates,i+1,target-candidates[i],curr,ans); // simulates taking candidates[i], notice that we move forward index to i+1
                curr.pop_back(); // simulates not taking candidates[i]
            }
        }
    }
};
// Time: O(2^n)
// Space: O(n)

int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    return 0;
}
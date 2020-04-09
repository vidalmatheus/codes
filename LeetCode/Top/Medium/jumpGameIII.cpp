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
    vector<int> memo;
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr.size()==0)
            return true;
        
        if (start>=arr.size() || start<0)
            return false;
        
        memo.resize(arr.size(),-1);
        
        return dfs(arr,start);
    }
    
    
    bool dfs(vector<int>& arr, int pos){
        if (pos<0 || pos>=arr.size())
            return false;
        
        if (memo[pos] != -1)
            return memo[pos];
        
        if (arr[pos]==0)
            return memo[pos] = true;
        
        return memo[pos] = dfs(arr,pos+arr[pos]) || dfs(arr,pos-arr[pos]);
    }
};
// Time: O(2^n)
// Space: O(2^n)

int main(){
    vector<int> arr = {3,0,2,1,2};
    int start = 2;

    Solution sol;
    sol.canReach(arr,start) ? cout << "true\n" : cout << "false\n";

    return 0;
}

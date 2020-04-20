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
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        if (arr.size()==0)
            return {};
        
        sort(arr.begin(),arr.end());
        
        vector<vector<int>> ans;
        int minDif = INT_MAX;
        for (int i=1;i<arr.size();i++){
            if (arr[i]-arr[i-1]<minDif){
                minDif = arr[i]-arr[i-1];
                ans.clear();
            }
            if (arr[i]-arr[i-1]==minDif)
                ans.push_back({arr[i-1],arr[i]});
        }
        
        return ans;
    }
};
// Time: O(n log n)
// Space: O(n)

int main(){
    vector<int> arr = {4,2,1,3};

    Solution sol;
    vector<vector<int>> ans = sol.minimumAbsDifference(arr);

    cout << "[\n";
    for (auto row:ans){
        cout << "[ ";
        for (int e:row)
            cout << e << " ";
        cout << "]\n";
    }
    cout << "]\n";

    return 0;
}

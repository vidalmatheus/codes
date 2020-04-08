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
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if (max(A.size(),A[0].size())<=1)
            return A;
        
        int n = A.size();
        int m = A[0].size();
        
        vector<vector<int>> ans(m,vector<int>(n));
        
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                ans[j][i]=A[i][j];
            }
        }
        
        return ans;
    }
};
// Time: O(n*m)
// Space: O(n*m)

int main(){
    vector<vector<int>> A = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    for (vector<int> line:A){
        for (int e:line){
            cout << e << " ";
        }
        cout << endl;
    }
    cout << endl;

    Solution sol;
    vector<vector<int>> ans = sol.transpose(A);

    for (vector<int> line:ans){
        for (int e:line){
            cout << e << " ";
        }
        cout << endl;
    }

    return 0;
}
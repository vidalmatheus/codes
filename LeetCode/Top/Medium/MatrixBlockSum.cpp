#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class BruteForceSolution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        if (mat.size()==0)
            return {};
        
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),0));
        for (int i=0;i<mat.size();i++){
            for (int j=0;j<mat[0].size();j++){               
                ans[i][j] = somation(mat,i,j,K);
            }
        }
        
        return ans;
    }
    
    
    int somation(vector<vector<int>>& mat,int i, int j, int k){
        int sum=0;
        
        for (int r=max(0,i-k);r<min((int)mat.size(),i+k+1);r++){
            for (int c=max(0,j-k);c<min((int)mat[0].size(),j+k+1);c++){
                sum+=mat[r][c];
            }
        }
        
        return sum;
    }
};
// Time: O(n*m*k^2)
// Space: O(n*m)

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        if (mat.size()==0)
            return {};
        
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> prefixSum(m,vector<int>(n,0));
        buildPrefixSum(prefixSum,mat);
        
        vector<vector<int>> ans(m,vector<int>(n,0));
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){    
                int r1 = i-k-1;
                int r2 = min(i+k,m-1);
                int c1 = j-k-1;
                int c2 = min(j+k,n-1);
                ans[i][j] = prefixSum[r2][c2];
                ans[i][j] -=  (r1>=0) ? prefixSum[r1][c2] : 0; 
                ans[i][j] -= (c1>=0) ? prefixSum[r2][c1] : 0;
                ans[i][j] += (r1>=0 && c1>=0) ? prefixSum[r1][c1] : 0;
            }
        }
        
        return ans;
    }
    
    void buildPrefixSum(vector<vector<int>>& prefixSum, vector<vector<int>>& mat){
        for (int i=0;i<mat.size();i++){
            for (int j=0;j<mat[0].size();j++){
                prefixSum[i][j] = mat[i][j];
                prefixSum[i][j] -= (i-1>=0 && j-1>=0) ? prefixSum[i-1][j-1] : 0;
                prefixSum[i][j] += (i-1>=0) ? prefixSum[i-1][j] : 0;
                prefixSum[i][j] += (j-1>=0) ? prefixSum[i][j-1] : 0;
            }
        }
    }
};
// Time: O(n*m)
// Space: O(n*m)

int main(){
    vector<vector<int>> mat{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int k = 1;

    Solution sol;
    vector<vector<int>> ans = sol.matrixBlockSum(mat,k);

    for (auto row:ans){
        for (int e:row)
            cout << e << " ";
        cout << endl;
    }

    return 0;
}

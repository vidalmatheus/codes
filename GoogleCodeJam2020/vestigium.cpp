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
    int trace(vector<vector<int>>& matrix) {
        int ans=0;
        for (int i=0;i<matrix.size();i++)
            ans+=matrix[i][i];

        return ans;    
    }

    bool isThereRepinArray(vector<int>& nums){
        unordered_set<int> s;
        for (int i=0;i<nums.size();i++){
            if (s.find(nums[i])==s.end()) // not found
                s.insert(nums[i]);
            else return true;
        }

        return false;
    }

    int repRow(vector<vector<int>>& matrix) {
        int ans=0;
        for (int i=0;i<matrix.size();i++){
            if (isThereRepinArray(matrix[i]))
                ans++;
        }

        return ans;
    }

    bool isThereRepinCol(vector<vector<int>>& matrix, int col){
        int ans=0;
        unordered_set<int> s;
        for (int i=0;i<matrix.size();i++){
            if (s.find(matrix[i][col])==s.end()) // not found
                s.insert(matrix[i][col]);
            else return true;
        }

        return false;
    }

    int repCol(vector<vector<int>>& matrix) {
        int ans=0;
        for (int i=0;i<matrix[0].size();i++){
            if (isThereRepinCol(matrix,i))
                ans++;
        }

        return ans;
    }

    vector<vector<int>> readMatrix(int n){
        vector<vector<int>> matrix(n,vector<int>(n));
        
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cin >> matrix[i][j];
            }
        }

        return matrix;
    }
};

int main(){
    int T,N;
    cin >> T;

    vector<int> k(T),r(T),c(T);
    Solution sol;
    for (int i=0;i<T;i++){
        cin >> N;
        vector<vector<int>> matrix = sol.readMatrix(N);
        k[i] = sol.trace(matrix);
        r[i] = sol.repRow(matrix);
        c[i] = sol.repCol(matrix);
    }

    for (int i=1;i<=T;i++){
        cout << "Case #" << i << ": " << k[i-1] << " " << r[i-1] << " " << c[i-1];
        if (i<T)
            cout << "\n";
    }
    
    return 0;
}

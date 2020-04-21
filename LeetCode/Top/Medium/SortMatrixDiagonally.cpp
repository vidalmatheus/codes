#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class WronSolution { // THIS IS WRONG!!!
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        if (mat.size()==0)
            return {};
        
        int m = mat.size();
        int n = mat[0].size();
        
        // sort from left to right
        for (int i=0;i<m;i++)
            sort(mat[i].begin(),mat[i].end());
        
        // sort from top to bottom
        for (int j=0;j<n;j++){
            vector<int> col(m,0);
            for (int i=0;i<m;i++)
                col[i] = mat[i][j];
            
            sort(col.begin(),col.end());
            
            for (int i=0;i<m;i++)
                mat[i][j] = col[i];
        }
        
        return mat;
    }
};
// Time: O(m*n*log n + n*(m+m*log m + m)) = O(n*m*(log n +log m))
// Space: O(m + log m + log n) = O(m + log n)

class OtherProblemSolution { // YOU'VE JUST SOLVED ANOTHER PROBLEM!!!
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        if (mat.size()==0)
            return {};
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> all;
        buildVector(mat,all,m,n); // O(MAX^2)
        
        for (int e:all)
            cout << e << " ";
        cout << endl;

        sort(all.begin(),all.end()); // O((n+m)*log(n+m))
        
        for (int e:all)
            cout << e << " ";
        cout << endl;

        vector<vector<int>> ans(m,vector<int>(n,0));
        buildMatrix(all,ans,m,n); // O(MAX^2)

        return ans;
    }
    
    void buildMatrix(vector<int>& all, vector<vector<int>>& ans, int m, int n){ 
        int len = max(m,n);
        int nextIndex = 0;
        for (int i=0;i<len;i++){
            if (i<m)
                for (int j=i;j<n;j++)
                    ans[i][j] = all[nextIndex++];
            
            
            if (i<n-1)
                for (int j=i+1;j<m;j++)
                    ans[j][i] = all[nextIndex++];
        }
    }
    
    void buildVector(vector<vector<int>>& mat, vector<int>& all, int m, int n){ 
        int len = max(m,n);
        for (int i=0;i<len;i++){
            vector<int> tmp;
            getRow(mat,i,i,n-1,tmp);
            all.insert(all.end(),tmp.begin(),tmp.end());
            
            tmp.clear();
            getCol(mat,i,i+1,m-1,tmp);
            all.insert(all.end(),tmp.begin(),tmp.end());
        }
    }
    
    void getRow(vector<vector<int>>& mat, int rowIndex, int start, int end, vector<int>& row){
        if (rowIndex>=mat.size())
            return;
        for (int i=start;i<=end;i++)
            row.push_back(mat[rowIndex][i]);
    }
    
    void getCol(vector<vector<int>>& mat, int colIndex, int start, int end, vector<int>& col){
        if (colIndex>=mat[0].size())
            return;
        for (int i=start;i<=end;i++)
            col.push_back(mat[i][colIndex]);
    }
};
// Time: O(MAX^2)
// Space: O(m*n)

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        if (mat.size()==0)
            return {};
        
        int m = mat.size();
        int n = mat[0].size();
     
        unordered_map<int,list<int>> diag;
        
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                diag[i-j].push_back(mat[i][j]);
        
        for (auto it=diag.begin();it!=diag.end();++it)
            it->second.sort();        
        
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                mat[i][j] = diag[i-j].front();
                diag[i-j].pop_front();
            }
        }
    
        return mat;
    }
};
// Time: O(m*n + MIN^2*(log(MIN)))
// Space: O(m*n)


int main(){
    vector<vector<int>> mat {
      {3,3,1,1},
      {2,2,1,2},
      {1,1,1,2}  
    };

    Solution sol;
    mat = sol.diagonalSort(mat);

    for (auto row:mat){
        for (int elem:row)
            cout << elem << " ";
        cout << endl;
    }

    return 0;
}

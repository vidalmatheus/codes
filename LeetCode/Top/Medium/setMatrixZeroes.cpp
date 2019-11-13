#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) { // Time: O(row*column) - Space: O(#zeroes)
        if (matrix.size()==0)
            return;
        set<pair<int,int>> s;
        for (int i=0;i<matrix.size();i++){
            for (int j=0;j<matrix[0].size();j++){
                if (matrix[i][j]==0){
                    s.insert({i,j});
                }
            }
        }
        for (auto it = s.begin();it!=s.end();++it){
            blank(matrix,it->first,it->second);
        }
    }
    void blank(vector<vector<int>> &matrix, int x, int y){ // Time: O(row+column) - Space: O(1)
        // erase line
        for (int i=0;i<matrix[x].size();i++){
            matrix[x][i]=0;
        }
        for (int i=0;i<matrix.size();i++){
            matrix[i][y]=0;
        }
    }
};

/* class Solution2 { // WRONG!
public:
    void setZeroes(vector<vector<int>>& matrix) { // Time: O(row*column) - Space: O(#zeroes)
        if (matrix.size()==0)
            return;
        for (int i=0;i<matrix.size();i++){
            for (int j=0;j<matrix[0].size();j++){
                if (matrix[i][j]==0){
                    matrix[i][0]=0; // flag on row
                    matrix[0][j]=0; // flag on column
                }
            }
        }

    }
}; */

int main(){
    vector<vector<int>> matrix = { {0,1,2,0},
                                    {3,4,5,2},
                                    {1,3,1,5} };
    Solution sol;
    sol.setZeroes(matrix);
    for (auto i:matrix){
        for (auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
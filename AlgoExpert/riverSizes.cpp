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
    vector<int> riverSizes(vector<vector<int>>& matrix) {
        if (matrix.size()==0)
            return {};
    
        vector<int> ans;
        
        for (int i=0;i<matrix.size();i++){
            for (int j=0;j<matrix[0].size();j++){
                if (matrix[i][j]){
                    int counter = 0;
                    rec(matrix,i,j,counter);
                    ans.push_back(counter);
                }
            }
        }
        
        return ans;
    }

    bool isOutbound(vector<vector<int>>& matrix, int i, int j){
        if (i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size())
            return true;
        return false;
    }

    void rec(vector<vector<int>>& matrix, int i, int j, int& counter){
        if (isOutbound(matrix,i,j))
            return;
        
        if (!matrix[i][j])
            return;
        
        counter++;
        matrix[i][j]=0;
        
        rec(matrix,i+1,j,counter);
        rec(matrix,i-1,j,counter);
        rec(matrix,i,j+1,counter);
        rec(matrix,i,j-1,counter);
    }
};
// Time: O(n*m)
// Space: O(n*m)

int main(){
    vector<vector<int>> matrix = {
        {1, 0, 0, 1, 0},
        {1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 0}
    };

    Solution sol;
    vector<int> ans = sol.riverSizes(matrix);

    cout << "matrix after: " << endl;
    for (auto row:matrix){
        for (int e:row)
            cout << e << " ";
        cout << endl;
    }

    cout << "answer: " << endl;
    for (int e:ans)
        cout << e << " ";
    cout << endl;
    
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

void fillRowRight(vector<vector<int>>& matrix, int row, int start, int end, vector<int>& ans){
  for (int i=start;i<=end;i++)
    ans.push_back(matrix[row][i]);
}


void fillRowLeft(vector<vector<int>>& matrix, int row, int start, int end, vector<int>& ans){
  for (int i=end;i>=start;i--)
    ans.push_back(matrix[row][i]);
    
}

void fillColDown(vector<vector<int>>& matrix, int col, int start, int end, vector<int>& ans){
  for (int i=start;i<=end;i++)
    ans.push_back(matrix[i][col]);
}

void fillColUp(vector<vector<int>>& matrix, int col, int start, int end, vector<int>& ans){
  for (int i=end;i>=start;i--)
    ans.push_back(matrix[i][col]);
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size()==0)
            return {};
        
        vector<int> ans;
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int endRow = n-1;
        int endCol = m-1;
        int startRow = 0;
        int startCol = 0;

        while (startRow<=endRow && startCol<=endCol){
            fillRowRight(matrix,startRow,startCol,endCol,ans);
            startRow++;
            fillColDown(matrix,endCol,startRow,endRow,ans);
            endCol--;

            if (startRow<=endRow){
              fillRowLeft(matrix,endRow,startCol,endCol,ans);
              endRow--;
            }
            
            if(startCol<=endCol){
              fillColUp(matrix,startCol,startRow,endRow,ans);
              startCol++;
            }
        }
        
        return ans;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    Solution sol;
    vector<int> spiral = sol.spiralOrder(matrix);

    for (int e:spiral)
        cout << e << " ";
    cout << endl;

    return 0;
}

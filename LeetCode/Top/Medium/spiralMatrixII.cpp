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
    void fillRowRight(vector<vector<int>>& matrix, int row, int start, int end, int& num){
      for (int i=start;i<=end;i++){
        matrix[row][i]=num;
        num++;
      }
    }


    void fillRowLeft(vector<vector<int>>& matrix, int row, int start, int end, int& num){
      for (int i=end;i>=start;i--){
        matrix[row][i]=num;
        num++;
      }
    }

    void fillColDown(vector<vector<int>>& matrix, int col, int start, int end, int& num){
      for (int i=start;i<=end;i++){
        matrix[i][col]=num;
        num++;
      }
    }

    void fillColUp(vector<vector<int>>& matrix, int col, int start, int end, int& num){
      for (int i=end;i>=start;i--){
        matrix[i][col]=num;
        num++;
      }
    }


    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> matrix(n,vector<int>(n));

      int endRow = n-1;
      int endCol = n-1;
      int startRow = 0;
      int startCol = 0;

      int num = 1;
      while (startRow<=endRow && startCol<=endCol){

        fillRowRight(matrix,startRow,startCol,endCol,num);
        startRow++;
        fillColDown(matrix,endCol,startRow,endRow,num);
        endCol--;

        if (startRow<=endRow){
          fillRowLeft(matrix,endRow,startCol,endCol,num);
          endRow--;
        }
        if(startCol<=endCol){
          fillColUp(matrix,startCol,startRow,endRow,num);
          startCol++;
        }
      }

      return matrix;
    }
};
// Time: O(n)
// Space: O(n^2)

int main(){
    int n = 3;

    Solution sol;
    vector<vector<int>> matrix = sol.generateMatrix(n);

    for (vector<int> line:matrix){
        for (int e:line){
            cout << e << " ";
        }
        cout << endl;
    }

    return 0;
}

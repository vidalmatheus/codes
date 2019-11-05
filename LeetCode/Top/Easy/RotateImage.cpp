/*   Rotate Image
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
] */

#include <bits/stdc++.h>

using namespace std;

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int receptor, trans;
         for(int i=0;i<n/2;i++){
             for(int j=0;j<n-1-2*i;j++){
                receptor = matrix[i+j][n-1-i];
                matrix[i+j][n-1-i]=matrix[i][i+j];

                cout << endl;
                for (auto a: matrix){
                    for(auto b:a){
                        cout << b << " ";
                    }
                    cout << endl;
                }
                 
                trans = receptor;
                receptor = matrix[n-1-i][n-1-j-i]; 
                matrix[n-1-i][n-1-j-i]=trans;

                cout << endl;
                for (auto a: matrix){
                    for(auto b:a){
                        cout << b << " ";
                    }
                    cout << endl;
                }

                trans = receptor;
                receptor = matrix[n-1-j-i][i]; 
                matrix[n-1-j-i][i]=trans;

                cout << endl;
                for (auto a: matrix){
                    for(auto b:a){
                        cout << b << " ";
                    }
                    cout << endl;
                }

                trans = receptor;
                //receptor = matrix[i][i+1]; não é necessário
                matrix[i][i+j]=trans;

                cout << endl;
                for (auto a: matrix){
                    for(auto b:a){
                        cout << b << " ";
                    }
                    cout << endl;
                }
             }
         }
    }
};


/*
Clever Solution!!! Reverse top to down and transpose the matrix
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
     
        if (matrix.size() == 0) {
            return;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        // Reverse top to down
        for (int i = 0; i < rows / 2; i++) {
            for (int j = 0; j < cols; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[rows-i-1][j];
                matrix[rows-i-1][j] = temp;
            }
        }
        // Swap the symmetry
        for (int i = 0; i < rows; i++) {
            for (int j = i; j < cols; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
};
*/

int main(){
    vector<vector<int>> matrix={{5, 1, 9,11},{2, 4, 8,10},{13, 3, 6, 7},{15,14,12,16}};

    for (auto a: matrix){
        for(auto b:a){
            cout << b << " ";
        }
        cout << endl;
    }

    Solution sol;
    sol.rotate(matrix);

    cout << endl;
    for (auto a: matrix){
        for(auto b:a){
            cout << b << " ";
        }
        cout << endl;
    }

    return 0;
}
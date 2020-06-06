#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// 000001111
// 000111111
// 000000011
// 000001111
// 000011111

/*

Brtute force: O(m * n)

O(n + m)

n >> m ?
O(m * log n)

*/

int solution1(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    
    int i = 0;     // row
    int j = n-1;   // ultimo 0
    
    // go up
    while (i < m){
        // go left
        while (j>=0 && matrix[i][j] != 0) {
            j--;
        }
        i++;
    }
    
    return j+1; 
}

int solution2(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    
    int i = 0;       // row
    int j = n-1;     // col
    
    while (i<m && j>=0){
        if (matrix[i][j] == 0)
            i++;
        else j--;
    }
    
    return j+1; 
}

int main(){

// 000001111
// 000111111
// 000000011
// 000001111
// 000011111


    vector<vector<int>> matrix{
        {0,0,0,0,0,1,1,1,1},
        {0,0,0,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,1,1},
        {0,0,0,0,0,1,1,1,1},
        {0,0,0,0,1,1,1,1,1}
    };

    cout << solution1(matrix) << endl;
    cout << solution2(matrix) << endl;

    return 0;
}
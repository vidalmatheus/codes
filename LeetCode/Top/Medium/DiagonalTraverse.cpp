#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*

(0,0) (0,1) (0,2)
(1,0) (1,1) (1,2)
(2,0) (2,1) (2,2)

(0,0): i+j = {0}
(0,1) -> (1,0): i+j = {1,1}
(2,0) -> (1,1) -> (0,2): i+j = {2,2,2}
(1,2) -> (2,1): i+j = {3,3,3}
(2,2): i+j = {4}

even-> push_front(element)
odd-> push_back(element)

front:  [0]: 1
back:   [1]: 2,4
front:  [2]: 7,5,3
back:   [3]: 6,8
front:  [4]: 9

ans: 1,2,4,7,5,3,6,8,9

*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.size()==0)
            return {};
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        unordered_map<int,list<int>> hash;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                int sum = i+j;
                int elem = matrix[i][j];
                if (sum%2==0)
                    hash[sum].push_front(elem);
                else hash[sum].push_back(elem);
            }
        }
        
        vector<int> ans(m*n,0);
        int index = 0;
        for (int i=0;i<=m+n-2;i++)
            for (auto elem:hash[i])
                ans[index++] = elem;
        
        return ans;    
    }
};
// Time: O(m*n)
// Space: O(m*n)

class BetterSolution {
private:
    const bool UP = true;
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.size()==0)
            return {};
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row = 0;
        int col = 0;
        
        bool dir = UP;
        vector<int> ans(m*n);
        int index = 0;
        
        while (row < m && col < n){
            ans[index++] = matrix[row][col];
            
            int newRow = row + (dir==UP ? -1: 1);
            int newCol = col + (dir==UP ?  1:-1);
            
            if (newRow>=0 && newRow<m && newCol>=0 && newCol<n){ // valid
                row = newRow;
                col = newCol;
            }
            else { // outtabounds
                if (dir==UP){
                    row += (col==n-1 ? 1:0);
                    col += (col<n-1  ? 1:0);
                }
                else { // going down
                    col += (row==m-1 ? 1:0);
                    row += (row<m-1 ? 1:0);
                }
                dir = !dir;
            }
        }
        
        return ans;    
    }
};
// Time: O(m*n)
// Space: O(1), no extra space

int main(){
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };

    BetterSolution sol;
    vector<int> ans = sol.findDiagonalOrder(matrix);

    cout << "[ ";
    for (int e:ans)
        cout << e << " ";
    cout << "]";

    return 0;
}

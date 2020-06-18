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
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0)
            return;
        
        int m = board.size();
        int n = board[0].size();
        for (int i=0;i<m;i++){
            if (board[i][0] == 'O')
                dfs(board,i,0);
            
            if (board[i][n-1] == 'O')
                dfs(board,i,n-1);
        }
        
        for (int i=0;i<n;i++){
            if (board[0][i] == 'O')
                dfs(board,0,i);
            
            if (board[m-1][i] == 'O')
                dfs(board,m-1,i);
        }
        
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                
                if (board[i][j] == '1')
                    board[i][j] = 'O';
            }
        }
                
    }
    
    bool isValid(vector<vector<char>>& board, int i, int j){
        return i>=0 && j>=0 && i<board.size() && j<board[0].size();
    }

    void dfs(vector<vector<char>>& board, int i, int j){
        if (!isValid(board,i,j) || board[i][j] != 'O')
            return;

        board[i][j] = '1';
        
        int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };    
        for (int k=0;k<4;k++){
            int next_i = i+dir[k][0];
            int next_j = j+dir[k][1];
            if (isValid(board,next_i,next_j))
                dfs(board,next_i,next_j);
        }   
    }
};
// Time: O(n*m)
// Space: O(1)

int main(){
    vector<vector<char>> grid{
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    Solution sol;
    sol.solve(grid);

    for (auto row:grid){
        for (char c:row)
            cout << c << " ";
        cout << endl;
    }

    return 0;
}

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
    void solveSudoku(vector<vector<char>>& board) {
        rec(board,0,0);
    }
    
    bool rec(vector<vector<char>>& board, int i, int j){
        if (j == board[0].size()){
            j = 0;
            i++;
            if (i == board.size())
                return true;
        }

        if (board[i][j] != '.')
            return rec(board,i,j+1);
        
        for (char k='1';k<='9';k++){
            if (tryValueK(board,i,j,k)){
                board[i][j] = k;
                if (rec(board,i,j+1))
                    return true;
                board[i][j] = '.';
            }
        }

        return false;   
    }

    bool tryValueK(vector<vector<char>>& board, int i, int j, char k){ // Time: O(1) & Space: O(1)
        // try every possibilitie and pick the first one which does not break the board
        bool broken = false;
        unordered_set<char> set;
        // check if it breaks the row
        for (int row=0;row<board.size();row++){
            if (set.find(k) != set.end())
                return false;
            else if (board[row][j] != '.') 
                set.insert(board[row][j]);
        }

        // check if it breaks the col
        set.clear();
        for (int col=0;col<board[0].size();col++){
            if (set.find(k) != set.end())
                return false;
            else if (board[i][col] != '.') 
                set.insert(board[i][col]);
        }

        // check if it breaks the current 3x3 sub-grid
        set.clear();
        // (i,j) = (4,5) --> (3,3)
        int start_row = (i/3)*3;
        int start_col = (j/3)*3;
        for (int r=start_row;r<start_row+3;r++){
            for (int c=start_col;c<start_col+3;c++){
                if (set.find(k) != set.end())
                     return false;
                else if (board[r][c] != '.') 
                    set.insert(board[r][c]);
            }
        }

        return true;
    }
};
// Time(Brute Force): O(81^k), where k is the amount of element that needs to be filled
// Space: O(1)

int main(){
    // vector<vector<char>> board{
    //     {'5','3','.','.','7','.','.','.','.'},
    //     {'6','.','.','1','9','5','.','.','.'},
    //     {'.','9','8','.','.','.','.','6','.'},
    //     {'8','.','.','.','6','.','.','.','3'},
    //     {'4','.','.','8','.','3','.','.','1'},
    //     {'7','.','.','.','2','.','.','.','6'},
    //     {'.','6','.','.','.','.','2','8','.'},
    //     {'.','.','.','4','1','9','.','.','5'},
    //     {'.','.','.','.','8','.','.','7','9'}
    // };

    vector<vector<char>> board {
        {'.','.','9','7','4','8','.','.','.'},
        {'7','.','.','.','.','.','.','.','.'},
        {'.','2','.','1','.','9','.','.','.'},
        {'.','.','7','.','.','.','2','4','.'},
        {'.','6','4','.','1','.','5','9','.'},
        {'.','9','8','.','.','.','3','.','.'},
        {'.','.','.','8','.','3','.','2','.'},
        {'.','.','.','.','.','.','.','.','6'},
        {'.','.','.','2','7','5','9','.','.'}
    };


    cout << "Initial board: " << endl;
    for (auto row:board){
        for (char e:row)
            cout << e << " ";
        cout << endl;
    }
    cout << "----------------------" << endl;

    Solution sol;
    sol.solveSudoku(board);

    cout << "Final board: " << endl;
    for (auto row:board){
        for (char e:row)
            cout << e << " ";
        cout << endl;
    }

    return 0;
}

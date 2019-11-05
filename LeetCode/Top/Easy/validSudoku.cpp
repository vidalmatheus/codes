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
    bool isValidSudoku(vector<vector<char>>& board) {
        if (validRows(board))
            if (validColumns(board))
                if (validBoxes(board))
                    return true;
        return false;
    }
    bool validRows(vector<vector<char>>& board){
        for (int i=0;i<9;i++){
            unordered_set<int> set;
            for (int j=0;j<9;j++){
                if (set.find(board[i][j])!=set.end())
                    return false;
                if (board[i][j]!='.')    
                    set.insert(board[i][j]);
            }
        }
        return true;
    }
    bool validColumns(vector<vector<char>>& board){
        for (int i=0;i<9;i++){
            unordered_set<int> set;
            for (int j=0;j<9;j++){
                if (set.find(board[j][i])!=set.end())
                    return false;
                if (board[j][i]!='.') 
                    set.insert(board[j][i]);
            }
        }
        return true;
    }
    bool validBoxes(vector<vector<char>>& board){
        unordered_set<int> set;
        for (int b=0;b<=6;b+=3){
            // 3 boxes in line
            for (int a=0;a<=6;a+=3){
                for (int i=0;i<3;i++){
                    for (int j=0;j<3;j++){
                        if (set.find(board[i+a][j+b])!=set.end())
                            return false;
                        if (board[i+a][j+b]!='.') 
                            set.insert(board[i+a][j+b]);
                    }
                }
                set.clear();
            }
        }
        return true;
    }
};

int main(){

    vector<vector<char>> board = 
/* {
  {'8','3','.','.','7','.','.','.','.'},
  {'6','.','.','1','9','5','.','.','.'},
  {'.','9','8','.','.','.','.','6','.'},
  {'8','.','.','.','6','.','.','.','3'},
  {'4','.','.','8','.','3','.','.','1'},
  {'7','.','.','.','2','.','.','.','6'},
  {'.','6','.','.','.','.','2','8','.'},
  {'.','.','.','4','1','9','.','.','5'},
  {'.','.','.','.','8','.','.','7','9'}
}; */
{
  {'5','3','.','.','7','.','.','.','.'},
  {'6','.','.','1','9','5','.','.','.'},
  {'.','9','8','.','.','.','.','6','.'},
  {'8','.','.','.','6','.','.','.','3'},
  {'4','.','.','8','.','3','.','.','1'},
  {'7','.','.','.','2','.','.','.','6'},
  {'.','6','.','.','.','.','2','8','.'},
  {'.','.','.','4','1','9','.','.','5'},
  {'.','.','.','.','8','.','.','7','9'}
};
    Solution sol;
    sol.isValidSudoku(board)?(cout << "true" << endl):(cout << "false" << endl);


    return 0;
}
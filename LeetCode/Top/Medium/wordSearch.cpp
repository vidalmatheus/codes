#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// class Solution { // That solution is wrong, because you are using letter that have been used before in the same searching 
// public:
//     const int LEFT = 0;
//     const int RIGHT = 1;
//     const int UP = 2;
//     const int DOWN = 3;
//     const int NONE = 4;

//     bool exist(vector<vector<char>>& board, string word) {
//         if (board.size()==0 || word.size()==0)
//             return false;
        
//         int previous = NONE;
//         for (int i=0;i<board.size();i++){
//             for (int j=0;j<board[0].size();j++){
//                 string candidate;
//                 if (board[i][j]==word[0]){
//                     DFS(board,word,i,j,0,candidate,previous);
//                     if (candidate == word)
//                         return true;
//                 }
//             }
//         }
        
//         return false;
//     }
    
//     void DFS(vector<vector<char>> &board, string &word, int i, int j, int counter, string &candidate, int previous) {
//         if (counter == word.size() || board[i][j] != word[counter])
//             return;
        
//         if (board[i][j] == word[counter]){
//             candidate.push_back(board[i][j]);
//             counter++;
//             if (candidate==word)
//                 return;
//         }
        
//         if (i-1>=0 && previous!= DOWN) 
//             DFS(board,word,i-1,j,counter,candidate,UP);
//         if (i+1<board.size() && previous!=UP) 
//             DFS(board,word,i+1,j,counter,candidate,DOWN);
//         if (j-1>=0 && previous!=RIGHT) 
//             DFS(board,word,i,j-1,counter,candidate,LEFT);
//         if (j+1<board[0].size() && previous!=LEFT) 
//             DFS(board,word,i,j+1,counter,candidate,RIGHT);
//     }
// };
// // Time: O(n)
// // Space: O(n)

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size()==0 || word.size()==0)
            return false;
        
        vector<vector<bool>> used(board.size());
        for (int i=0;i<board.size();i++){
            used[i].resize(board[0].size());
        }

        for (int i=0;i<board.size();i++){
            for (int j=0;j<board[0].size();j++){
                string candidate;
                if (board[i][j]==word[0]){
                    DFS(board,word,i,j,0,candidate,used);
                    if (candidate == word)
                        return true;
                }
            }
        }
        
        return false;
    }
    
    void DFS(vector<vector<char>> &board, string &word, int i, int j, int pos, string &candidate, vector<vector<bool>> &used) {
        if (pos == word.size() || board[i][j] != word[pos])
            return;
        
        if (board[i][j] == word[pos]){
            used[i][j] = true;
            candidate.push_back(board[i][j]);
            pos++;
        }
        
        if (i-1>=0 && !used[i-1][j]) 
            DFS(board,word,i-1,j,pos,candidate,used);
        if (i+1<board.size() && !used[i+1][j]) 
            DFS(board,word,i+1,j,pos,candidate,used);
        if (j-1>=0 && !used[i][j-1]) 
            DFS(board,word,i,j-1,pos,candidate,used);
        if (j+1<board[0].size() && !used[i][j+1]) 
            DFS(board,word,i,j+1,pos,candidate,used);
        
        if (candidate.size() != word.size()){
            candidate.pop_back();
            used[i][j] = false;
        }
        
    }
};
// Time: O(n*m*4^k), where k is the length of the fiven word
// Space: O(n*m)


int main() {
    vector<vector<char>> board = {
        {'C','A','A'},
        {'A','A','A'},
        {'B','C','D'}
    };

    string word = "AAB";

    Solution sol;
    sol.exist(board,word) == true ? cout << "true\n" : cout << "false\n";

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution_withoutTrie {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (words.size()==0)
            return {};
        
        vector<string> ans;
        for (int i=0;i<words.size();i++){
            if (exist(board, words[i]))
                ans.push_back(words[i]);
        }
        
        return ans;
    }
    
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
    
    void DFS(vector<vector<char>> &board, string &word, int i, int j, int counter, string &candidate, vector<vector<bool>> &used) {
        if (counter == word.size() || board[i][j] != word[counter])
            return;
        
        if (board[i][j] == word[counter]){
            used[i][j] = true;
            candidate.push_back(board[i][j]);
            counter++;
        }
        
        if (i-1>=0 && !used[i-1][j]) 
            DFS(board,word,i-1,j,counter,candidate,used);
        if (i+1<board.size() && !used[i+1][j]) 
            DFS(board,word,i+1,j,counter,candidate,used);
        if (j-1>=0 && !used[i][j-1]) 
            DFS(board,word,i,j-1,counter,candidate,used);
        if (j+1<board[0].size() && !used[i][j+1]) 
            DFS(board,word,i,j+1,counter,candidate,used);
        
        if (candidate != word){
            candidate.resize(candidate.size()-1);
            used[i][j] = false;
        }   
    }
};
// Time: O(L*n*m*k)
// Space: O(L*n*m*k)

class DFSSolution { // Better written solution than that before
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (words.size() == 0)
            return {};
        
        vector<string> ans;
        for (string word:words){
            if (found(board,word))
                ans.push_back(word);
        }
        
        return ans;
    }
    
    bool found(vector<vector<char>>& board, string& word){
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        
        for (int i=0;i<board.size();i++){
            for (int j=0;j<board[0].size();j++){
                if (board[i][j] == word[0]){
                    if (dfs(board,word,visited,i,j,0))
                        return true;
                }
            }
        }
        
        return false;
    }
    
    bool valid(vector<vector<char>>& board, int i, int j){
        return i >= 0 && j >= 0 && i < board.size() && j < board[0].size();
    }
    
    bool dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int i, int j, int pos){
        if (pos == word.size())
            return true;
        
        if (!valid(board,i,j) || visited[i][j])
             return false;

        visited[i][j] = true;
        if (board[i][j] == word[pos]){
            int dir[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };
            for (int k=0;k<4;k++){
                int ni = i + dir[k][0];
                int nj = j + dir[k][1];
                if (dfs(board,word,visited,ni,nj,pos+1))
                    return true;
            }
        }
        
        visited[i][j] = false;
        return false;
     }
};
// Time: O(k*n*m*L), board(n,m); k words to search; L is the maximum length of a searching word
// Space: O(k*n*m*L)


struct TrieNode{
    bool isWord;
    string word;
    unordered_map<char,struct TrieNode*> children;
    TrieNode() : isWord(false) {}
};

class Trie{
public:
    struct TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word){
        struct TrieNode* crawler = root;
        string str = "";
        for (int i=0;i<word.size();i++){
            if (crawler->children.find(word[i])==crawler->children.end())
                crawler->children[word[i]] = new TrieNode();
            str+=word[i];
            crawler->word = str;
            if (i == word.size()-1)
                crawler->isWord = true;
            crawler = crawler->children[word[i]];
        }        
    }

    bool search(string word){
        struct TrieNode* crawler = root;
        for (int i=0;i<word.size();i++){
            if (crawler->children.find(word[i])==crawler->children.end())
                return false;
            if (i!=word.size()-1) 
                crawler = crawler->children[word[i]];
        }

        return crawler->isWord;
    }
};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {        
        if (words.size()==0 || board.size()==0) 
            return {};
    
        Trie trie;
        for (string s:words)
            trie.insert(s);

        vector<string> ans;
        for (int i=0;i<board.size();i++){
            for (int j=0;j<board[0].size();j++){
                char c = board[i][j];
                if (trie.root->children.find(c)!=trie.root->children.end())
                    DFS(board,ans,i,j,trie.root);
            }
        }

        return ans;
    }

    bool outside (vector<vector<char>> &board, int i, int j){
        if (i<0 || i>=board.size() || j<0 || j>board[0].size())
            return true;
        return false;
    }

    vector<int> x = {-1,1,0,0}; // up, down, left, right
    vector<int> y = {0,0,-1,1};

    void DFS (vector<vector<char>>& board, vector<string>& ans, int i, int j, struct TrieNode* curr){
        if (board[i][j] == '#' || curr->children.find(board[i][j])==curr->children.end())
            return;

        char t = board[i][j];
        board[i][j] = '#';
        if (curr->isWord)
            ans.push_back(curr->word);
        curr = curr->children[t];
        
        for (int k=0;k<x.size();k++){
            int row = i + x[k];
            int col = j + y[k];
            if (!outside(board,row,col))
                DFS(board,ans,row,col,curr);
        }

        board[i][j] = t;
    }
};

int main() {

    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };

    vector<string> words = {"oath","pea","eat","rain"};

    // vector<vector<char>> board = {
    //     {'a'}
    // };

    // vector<string> words = {"a"};

    Solution sol;
    vector<string> ans = sol.findWords(board,words);

    for (string w:ans)
        cout << w << " ";
    cout << endl;

    return 0;
}

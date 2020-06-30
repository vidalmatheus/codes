#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct TrieNode {
    bool isWord;
    vector<struct TrieNode*> children;
    TrieNode() : isWord(false) {
        children.resize(26,nullptr);
    }
};

class Trie {
public:
    struct TrieNode *root;

    Trie(){
        root = new TrieNode();
    }
    
    void insert(string& word){ // O(L)
        struct TrieNode *curr = root;
        for (char c:word){
            if (curr->children[c-'a'] == nullptr)
                curr->children[c-'a'] = new TrieNode();
            curr = curr->children[c-'a'];
        }
        
        curr->isWord = true;
    }
    
    bool search(string& word){ // O(L)
        struct TrieNode *curr = root;
        for (char c:word){
            if (curr->children[c-'a'] == nullptr)
                return false;
            curr = curr->children[c-'a'];
        }
        
        return curr->isWord;
    }
    
    bool isPrefix(string& word){ // O(L)
        struct TrieNode *curr = root;
        for (char c:word){
            if (curr->children[c-'a'] == nullptr)
                return false;
            curr = curr->children[c-'a'];
        }
        return true;
    }
};

class TLE1Solution {
private:
    Trie* trie = new Trie();
public:    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (words.size() == 0)
            return {};
        
        // build a trie -> O(words)
        for (string word:words)
            trie->insert(word);
        
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
                    string candidate = "";
                    if (dfs(board,word,visited,candidate,i,j,0))
                        return true;
                }
            }
        }
        
        return false;
    }
    
    bool valid(vector<vector<char>>& board, int i, int j){
        return i >= 0 && j >= 0 && i < board.size() && j < board[0].size();
    }
    
    bool dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, string& candidate, int i, int j, int pos){
        if (pos == word.size())
            return true;
        
        if (!trie->isPrefix(candidate))
            return false;
        
        if (!valid(board,i,j) || visited[i][j])
             return false;
        
        visited[i][j] = true;
        if (board[i][j] == word[pos]){
            candidate.push_back(board[i][j]);
            int dir[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };
            for (int k=0;k<4;k++){
                int ni = i + dir[k][0];
                int nj = j + dir[k][1];
                if (dfs(board,word,visited,candidate,ni,nj,pos+1))
                    return true;
            }
            candidate.pop_back();
        }
        
        visited[i][j] = false;
        return false;
     }
};
// Time: O(A), where A is the words content
// Space: O(A)

class TLE2Solution {
private:
    Trie* trie = new Trie();
public:    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (words.size() == 0)
            return {};
        
        // build a trie -> O(words)
        for (string word:words)
            trie->insert(word);
        
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
                    string candidate = "";
                    if (dfs(board,word,visited,candidate,i,j,trie->root))
                        return true;
                }
            }
        }
        
        return false;
    }
    
    bool valid(vector<vector<char>>& board, int i, int j){
        return i >= 0 && j >= 0 && i < board.size() && j < board[0].size();
    }
    
    bool dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, string& candidate, int i, int j, struct TrieNode* curr){
        if (curr->isWord && candidate == word)
            return true;
        
        if (!valid(board,i,j) || visited[i][j])
             return false;
        
        if (curr->children[board[i][j]-'a'] == nullptr)
            return false;
        
        visited[i][j] = true;
        candidate.push_back(board[i][j]);
        int dir[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };
        for (int k=0;k<4;k++){
            int ni = i + dir[k][0];
            int nj = j + dir[k][1];
            if (dfs(board,word,visited,candidate,ni,nj,curr->children[board[i][j]-'a']))
                return true;
        }
        
        visited[i][j] = false;
        if (candidate.size() > 0)
            candidate.pop_back();
        return false;
     }
};
// Time: O(A), where A is the words content
// Space: O(A)

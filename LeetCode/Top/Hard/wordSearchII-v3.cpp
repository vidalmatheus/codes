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
};

class Solution {
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
        unordered_set<string> set;
        for (int i=0;i<board.size();i++){
            for (int j=0;j<board[0].size();j++){
                char c = board[i][j];
                string candidate = "";
                if (trie->root->children[c-'a'] != nullptr)
                    dfs(board,set,candidate,i,j,trie->root);
            }
        }

        for (string w:set)
            ans.push_back(w);
        
        return ans;
    }

    bool valid(vector<vector<char>>& board, int i, int j){
        return i >= 0 && j >= 0 && i < board.size() && j < board[0].size();
    }
    
    void dfs (vector<vector<char>>& board, unordered_set<string>& set, string& candidate, int i, int j, struct TrieNode* curr){
         if (curr->isWord)
            set.insert(candidate);
        
        if (!valid(board,i,j) || board[i][j] == '#')
            return;
    
        if (curr->children[board[i][j]-'a'] == nullptr)
            return;
        
        char t = board[i][j];
        board[i][j] = '#';
        
        candidate.push_back(t);
        int dir[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };
        for (int k=0;k<4;k++){
            int row = i + dir[k][0];
            int col = j + dir[k][1];
            dfs(board,set,candidate,row,col,curr->children[t-'a']);
        }
        
        if (candidate.size() > 0)
            candidate.pop_back();
        board[i][j] = t;
    }
};
// Time: O(A), where A is the words content
// Space: O(A)

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

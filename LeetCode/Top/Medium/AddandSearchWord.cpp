#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

const int ALPHABET_SIZE = 26;

struct TrieNode {
    bool isEndWord;
    struct TrieNode * children[ALPHABET_SIZE];
    TrieNode() {
        isEndWord = false;
        for (int i=0;i<ALPHABET_SIZE;i++)
            children[i]=nullptr;
    }
};

class WordDictionary {
private:
    struct TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) { // O(m)
        struct TrieNode* crawler = root;
        for (int i=0;i<word.size();i++){
            int index = word[i]-'a';
            if (!crawler->children[index])
                crawler->children[index] = new TrieNode();
            crawler = crawler->children[index];
        }
        
        crawler->isEndWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(root,word,0);
    }
    
    bool dfs(struct TrieNode* crawler,string& word, int index){ // Time: O(m*n) & Space: O(n)
        if (crawler==nullptr)
            return false;
        if (crawler->isEndWord && index == word.size())
            return true;
        if (index == word.size())
            return false;
        if (word[index]=='.'){
            for (int i=0;i<ALPHABET_SIZE;i++){
                if (crawler->children[i]){
                    if (dfs(crawler->children[i],word,index+1))
                        return true;
                }
            }
            return false;
        }
        int child = word[index]-'a';
        return dfs(crawler->children[child],word,index+1);       
    }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(){
    WordDictionary* obj = new WordDictionary();
    // obj->addWord("bad");
    // obj->addWord("dad");
    // obj->addWord("mad");
    // obj->search("pad") ? cout << "true\n" : cout << "false\n";
    // obj->search("bad") ? cout << "true\n" : cout << "false\n";
    // obj->search(".ad") ? cout << "true\n" : cout << "false\n";
    // obj->search("b..") ? cout << "true\n" : cout << "false\n";

    obj->addWord("a");
    obj->addWord("a");
    obj->search(".") ? cout << "true\n" : cout << "false\n";
    obj->search("aa") ? cout << "true\n" : cout << "false\n";
    obj->search("a") ? cout << "true\n" : cout << "false\n";
    obj->search(".a") ? cout << "true\n" : cout << "false\n";
    obj->search("a.") ? cout << "true\n" : cout << "false\n";

    return 0;
}

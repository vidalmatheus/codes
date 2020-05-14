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
class Trie {
private:
    struct TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) { // O(m)
        struct TrieNode* crawler = root;
        for (int i=0;i<word.size();i++){
            int index = word[i]-'a';
            if (!crawler->children[index])
                crawler->children[index] = new TrieNode();
            crawler = crawler->children[index];
        }
        
        crawler->isEndWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) { // O(m)
        struct TrieNode* crawler = root;
        for (int i=0;i<word.size();i++){
            int index = word[i]-'a';
            if (!crawler->children[index])
                return false;
            crawler = crawler->children[index];
        }
        
        return crawler && crawler->isEndWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) { // O(prefix)
        struct TrieNode* crawler = root;
        for (int i=0;i<prefix.size();i++){
            int index = prefix[i]-'a';
            if (!crawler->children[index])
                return false;
            crawler = crawler->children[index];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(){
    Trie *trie = new Trie();
    trie->insert("apple");
    trie->search("apple") ? cout << "true\n" : cout << "false\n";
    trie->search("app") ? cout << "true\n" : cout << "false\n";
    trie->startsWith("app") ? cout << "true\n" : cout << "false\n";
    trie->insert("app");
    trie->search("app");

    return 0;
}

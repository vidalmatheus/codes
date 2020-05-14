#include <bits/stdc++.h>

using namespace std;

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

class Trie /*Used for store characters, TO MAKE AN DICTIONARY (or one alphabet)*/
/*
    Isert and Search = O(m) or time complexity
    Space complexity = O(AlPHABET_SIZE)*M*N
    // M: length  of key
    // N: number of keys in trie;
*/
{
private:
    struct TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert (string key) { // insert words: O(m), where m is the length of a key
        struct  TrieNode * crawler = root;
        for (int i=0;i<key.size();i++){ // goes for every character
            int index = key[i]-'a'; // it saves the character as index  
            if (!crawler->children[index])  // if it doesn't have  a children with that character already,
                crawler->children[index] = new TrieNode(); // then create a new one
            crawler = crawler->children[index]; // crawl down the tree 
        }
        crawler->isEndWord=true; // when we've inerted all the characters of the word, mark the end of the word
    }
    bool search (string key){ // search for a word: O(m), where m is the length of the string we're searching for.
        struct TrieNode *crawler = root; // logic quite similar
        for (int i=0;i<key.size();i++){ 
            int index = key[i]-'a';
            if (!crawler->children[index]) // if it doesn't have  a children with that character already,
                return false; // then the word doesn't exist
            crawler=crawler->children[index]; 
        }
        return (crawler!=nullptr && crawler->isEndWord); // true if we've achieved the end of the word
    }
};

int main(){
    Trie trie = Trie();
    trie.insert("matheus");
    trie.insert("vidal");
    trie.insert("de");
    trie.insert("menezes");

    trie.search("matheus")?(cout << "true\n") : (cout << "false\n");
    trie.search("vidal")?(cout << "true\n") : (cout << "false\n");
    trie.search("de")?(cout << "true\n") : (cout << "false\n");
    trie.search("menezes")?(cout << "true\n") : (cout << "false\n");
    cout << "\n";
    trie.search("vida")?(cout << "true\n") : (cout << "false\n");
    return 0;
}

// Obs.: For pattern matching, we build the trie with O(N^2) only once, and then for each search we just spend O(m) in time complexity




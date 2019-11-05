#include <bits/stdc++.h>

using namespace std;

/*
Tries is a tree that stores strings. Maximum number of children of a node is equal to size of alphabet. 
Trie supports search, insert and delete operations in O(L) time where L is length of key.

Hashing:- In hashing, we convert key to a small value and the value is used to index data. Hashing supports search, 
insert and delete operations in O(L) time on average.

Self Balancing BST : The time complexity of search, insert and delete operations in a self-balancing Binary Search Tree (BST) 
(like Red-Black Tree, AVL Tree, Splay Tree, etc) is O(L Log n) where n is total number words and L is length of word. 
The advantage of Self balancing BSTs is that they maintain order which makes operations like minimum, maximum, closest (floor or ceiling) and k-th largest faster. 
Please refer Advantages of BST over Hash Table for details.


Why Trie? :

- With Trie, we can insert and find strings in O(L) time where L represent the length of a single word. This is obviously faster than BST. 
    This is also faster than Hashing because of the ways it is implemented. 
    We do not need to compute any hash function. No collision handling is required (like we do in open addressing and separate chaining)
- Another advantage of Trie is, we can easily print all words in alphabetical order which is not easily possible with hashing.
- We can efficiently do prefix search (or auto-complete) with Trie.
*/

//const int ALPHABET_SIZE = 26; // WE DON'T NEED THAT ANYMORE! :)

struct TrieNode {
    bool isEndWord;
    unordered_map<char,struct TrieNode*> children; // with HASHMAP we don't need the alphabet size anymore, and the access still O(1), because of the HASHTABLE!
    TrieNode() {
        isEndWord = false;
    }
};

class Trie /*Used for store characters, TO MAKE AN DICTIONARY (or one alphabet)*/
/*
    Complexities analisys:
    Insert and Search = O(M)
    Space complexity = O(M*N)
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
            if (crawler->children.find(key[i])==crawler->children.end())  // if it doesn't have  a children with that character already,
                crawler->children[key[i]] = new TrieNode(); // then create a new one
            crawler = crawler->children[key[i]]; // crawl down the tree 
        }
        crawler->isEndWord=true; // when we've inerted all the characters of the word, mark the end of the word
    }
    bool search (string key){ // search for a word: O(m), where m is the length of the string we're searching for.
        struct TrieNode *crawler = root; // logic quite similar
        for (int i=0;i<key.size();i++){ 
            if (crawler->children.find(key[i])==crawler->children.end()) // if it doesn't have  a children with that character already,
                return false; // then the word doesn't exist
            crawler=crawler->children[key[i]]; 
        }
        return (crawler->isEndWord); // true if we've achieved the end of the word
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
    trie.search("fernanda")?(cout << "true\n") : (cout << "false\n");
    trie.search("vida")?(cout << "true\n") : (cout << "false\n");

    return 0;
}
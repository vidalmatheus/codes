#include <bits/stdc++.h>

using namespace std;

/*
A SufixTrie (or SufixTree) is a Trie that stores all sufixes from a given text. 
with that in hands, we can search for patterns.
*/

//const int ALPHABET_SIZE = 26; // WE DON'T NEED THAT ANYMORE! :)

struct TrieNode {
    bool isEndWord; 
    list<int> start;
    unordered_map<char,struct TrieNode*> children; // with HASHMAP we don't need the alphabet size anymore, and the access still O(1), because of the HASHTABLE!
    TrieNode() {
        isEndWord = false;
    }
};

class SufixTrie /*Used for store characters, TO MAKE AN DICTIONARY (or one alphabet)*/
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
    int start=0;
    string txt;
public:
    SufixTrie() {
        root = new TrieNode();
    }
    void insert (string txt){
        this->txt=txt;
        for (int i=0;i<txt.size();i++){
            insertWord(txt.substr(i,txt.size()-i));
            cout << txt.substr(i,txt.size()-i) << endl;
        }
    }
    void insertWord (string key) { // insert words: O(m), where m is the length of a key
        struct  TrieNode * crawler = root;
        for (int i=0;i<key.size();i++){ // goes for every character
            if (crawler->children.find(key[i])==crawler->children.end())  // if it doesn't have  a children with that character already,
                crawler->children[key[i]] = new TrieNode(); // then create a new one
            crawler = crawler->children[key[i]]; // crawl down the tree 
        }
        crawler->isEndWord=true; // when we've inerted all the characters of the word, mark the end of the word
        crawler->start.push_back(start++);
    }
    bool search (string key){ // search for a word: O(m), where m is the length of the string we're searching for.
    
    }


        
/*         int j=txt.find_first_of(key[key.size()-1]);
        for (int i=j+1;i<txt.size();i++)
            crawler=crawler->children[txt[i]];
        cout << "start: " << crawler->start << endl;  
        cout << "end: " << crawler->start + key.size() - 1 << endl;   */
};

int main(){
    string txt = "abcde";
    SufixTrie trie = SufixTrie();
    trie.insert(txt);

    trie.search("ab")?(cout << "true\n"):(cout << "false\n");
    trie.search("cd")?(cout << "true\n"):(cout << "false\n");
    trie.search("ae")?(cout << "true\n"):(cout << "false\n");
    trie.search("bd")?(cout << "true\n"):(cout << "false\n");

    return 0;
}
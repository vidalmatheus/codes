#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class SlowSolution{ // Just One BFS
public:
  	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.size()==0)
            return 0;
      
        queue<string> q;
        unordered_set<string> used;
        q.push(beginWord);
        used.insert(beginWord);
	    int currLevel = 0;
        while (!q.empty()){
            int size = q.size();
            for (int i=0;i<size;i++){
                string node = q.front();
                if (node==endWord)
                    return currLevel+1;
                q.pop();
                for (int j=0;j<wordList.size();j++) // add neighbours
			    if (used.find(wordList[j])==used.end() && dist(node,wordList[j])==1){
                    q.push(wordList[j]);
                    used.insert(wordList[j]);
                }
            }    
            currLevel++;    
        }
      
        return 0;
    }
  
  	int dist(string& A, string& B){ // O(m), m: length  of the words
	    int counter = 0;
        for (int i=0;i<A.size();i++){
            if (A[i]!=B[i])
                counter++;
        }
      
      return counter;
    }
};
// Time: O(n)
// Space: O(n)

class Solution{ // Bidirectional BFS
public:
  	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.size()==0)
            return 0;
      
        wordList.push_back(beginWord);
        queue<string> q;
        queue<string> qBack;
        unordered_set<string> used;
        unordered_set<string> usedBack;
        q.push(beginWord);
        used.insert(beginWord);
        qBack.push(endWord);
        usedBack.insert(endWord);
	    int len = 1;
        int lenBack = 1;
        string node = "";
        string nodeBack = ""; 
        while (!q.empty() && !usedBack.empty()){
            int size = q.size();
            int sizeBack = qBack.size();
            for (int i=0,j=0;i<=size || j<=sizeBack;i++,j++){
                if (i<size){
                    node = q.front();
                    q.pop();
                    for (int k=0;k<wordList.size();k++) // add neighbours
                    if (used.find(wordList[k])==used.end() && dist(node,wordList[k])==1){
                        q.push(wordList[k]);
                        used.insert(wordList[k]);
                    }
                }
                if (i==size) len++;
                if (j<sizeBack){
                    string nodeBack = qBack.front();
                    qBack.pop();
                    for (int k=0;k<wordList.size();k++) // add neighbours
		    	        if (usedBack.find(wordList[k])==usedBack.end() && dist(nodeBack,wordList[k])==1){
                            qBack.push(wordList[k]);
                            usedBack.insert(wordList[k]);
                    }
                }
                if (j==sizeBack) lenBack++;

                for (auto elem:used)
                    if (usedBack.find(elem)!=usedBack.end()) // found
                        return len+lenBack;
            }
        }
      
        return 0;
    }
  
  	int dist(string& A, string& B){ // O(m), m: length  of the words
	    int counter = 0;
        for (int i=0;i<A.size();i++){
            if (A[i]!=B[i])
                counter++;
        }
      
      return counter;
    }
};
// Time: O(n*m)
// Space: O(n*m)

int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    Solution sol;
    cout << sol.ladderLength(beginWord,endWord,wordList) << endl;

    return 0;
}

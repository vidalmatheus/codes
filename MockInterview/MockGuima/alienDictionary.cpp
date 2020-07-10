/*
Input:  words[] = {"baa", "abcd", "abca", "cab", "cad"}
Output: Order of characters is 'b', 'd', 'a', 'c'

  a b c d
  x	x x
  
1)  b a c 
2)  d a
3)  b d

M words

N -> Time: O(N! * M * N)


->   . . . .


->   

---------------------------------------------------------

1. traversal words[]
2. look for the ith char
	2.1 Generate the constraints

3. Generate Permutaions
 3.1 if valid, return it

---------------------------------------------------------

Input:  words[] = {"caa", "aaa", "aab"}
Output: Order of characters is 'c', 'a', 'b'

*/

/*

Input:  words[] = {"baa", "abcd", "abca", "abc", "cab", "cad"}

M words
N char

Time: O(N*M + N+M)
Space: O(M)

b->a
d->a
a->c
b->d

b     v v v
b->  d->a->c

top: c a d b
reverte: b d a c

*/

#include <bits/stdc++.h>

using namespace std;

string alphabet(vector<string> &words){

  int minSize = INT_MAX;
  for (int i=0;i<words.size();++i)
    minSize = min(minSize,(int)words[i].size());
  
  // build constraints
  vector<vector<char>> constraints;
  for (int j=0;j<minSize;++j){
    vector<char> tmp;
    tmp.push_back(words[0][j]);
  	for (int i=1;i<words.size();++i){
		if (words[i][j] != words[i-1][j])
          tmp.push_back(words[i][j]);      
    }
    constraints.push_back(tmp);
  }
  
  // pick the alphabet 
  vector<char> alphabet;
  unordered_set<char> set;
  for (int i=0;i<words.size();++i){
  	for (int j=0;j<words[i].size();++j){
    	if (set.find(words[i][j]) == set.end())
    		alphabet.push_back(words[i][j]);
        else set.insert(words[i][j]);
    }
  }
  
  // generate permutaitons
  // rec();
}

// -------------------------------------------------------------------------------

/*

    Actually this problem is the same as Course Schedule II.
    You just have to find the prerequisites first, then all goes pretty much the same way of it.

*/

// -------------------------------------------------------

/*

    Some discussion about other problems: 
    https://leetcode.com/problems/shortest-bridge/
    https://leetcode.com/problems/remove-invalid-parentheses/

*/


/*
class Solution {
    int n, m;
    void dfs(int i, int j, vector<vector<int>> &A){
        if(i < 0 || j < 0 || i >= n || j >= m){
            return;
        }
        if(A[i][j] != 1) return;
        
        A[i][j] = 2; 
        dfs(i+1, j, A);
        dfs(i-1, j, A);
        dfs(i, j+1, A);
        dfs(i, j-1, A);
    }
public:
    int shortestBridge(vector<vector<int>>& A) {
        n = A.size();
        m = A[0].size();
        bool foi = false;
        for(int i = 0; i < n; i++){
            if(foi) break;
            for(int j = 0; j < m; j++){
                if(A[i][j] == 1){
                    dfs(i,j, A);
                    foi =  true;
                    break;
                }
            }
        }
        
        int dist = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(A[i][j] == 1){
                    for(int a = 0; a < n; a++){
                        for(int b = 0; b < m; b++){
                            if(A[a][b] == 2){
                                dist = min(dist, abs(a-i)+abs(j-b)-1);
                            }
                        }
                    }
                }
            }
        }
        return dist;
    }
};

*/




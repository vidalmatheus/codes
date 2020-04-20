#include <bits/stdc++.h>

using namespace std;

/*
Given two words A and B, and a dictionary, C, find the length of shortest transformation sequence from A to B, such that:

    You must change exactly one character in every transformation.
    Each intermediate word must exist in the dictionary.

 A = "hit"
 B = "cog"
 C = ["hit", "hot", "dot", "dog", "lot", "log", "cog"]
      <0,3>  <1,2>  <2,2>  <3,1>  <2,2>   <3,1>  <3,0>
      
      hit->hot
      
      		 hot-> dot or lot
    
      					 dot -> dog
      					 
                 				dog -> cog
                 
                 lot -> log
                				
                        log -> cog
      
      
Output 1:
    5

Explanation 1:
    "hit" -> "hot" -> "dot" -> "dog" -> "cog"
    
    "hit"->"hot"->                      "cog"

All words have the same length.
All words contain only lowercase alphabetic characters.

*/

class Solution{
public:
  	int shortestPath(string A, string B, vector<string>& C){
    	// edge cases
      
      queue<int> q;
      vector<bool> used(C.size(),false);
      
      int indexA = -1;
      for (int i=0;i<C.size();i++)
      if(A==C[i])
        indexA = i;
      
      q.push(indexA);
      used[indexA]=true;
			int currLevel = 0;
      while (!q.empty()){
        int size = q.size();
        for (int i=0;i<size;i++){
          int nodeIndex = q.front();
          if (C[nodeIndex]==B)
            return currLevel;
          
          for (int j=0;j<C.size();j++) // add neighbours
						if (!used[j] && dist(C[nodeIndex],C[j])==1){
              q.push(j);
              used[j] = true;
            }
        }
        
        currLevel++;    
      }
      
      return -1; // compiler warnning
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

https://www.interviewbit.com/problems/word-ladder-ii/

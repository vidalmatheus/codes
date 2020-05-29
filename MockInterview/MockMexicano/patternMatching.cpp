#include<bits/stdc++.h>

using namespace std;

// Question:
// string T and P
// return whether or not P is a substring of T

// T: ABACDABACBACDF -> n
//        i
// P:  BACA -> m
// O(n*m) -> Time

/*
Rabin-Karp

T: ABACABACBACDF
ABAC
BACA
ACAB

P: BACA

*/

/*

// ABACDABACBACDF
      i
   s
// BACA
    . 
indexP: 2
start: 0
i: 2

*/

class Solution {
public:
    int findPattern(string& t, string& p){
       if (p.size()>t.size())
           return false;
           
       int indexP = 0;
       int start = 0;
       for (int i=start;i<t.size();i++){
           if (t[i]==p[indexP]){
                indexP++;
                if (indexP == p.size())
                    return i-p.size()+1;
           }
           else { 
               i=i-indexP;
               indexP=0;
           }
        }
        
        return -1;
     }
};

int main(){
    string T = "ABACDBACAABACBACDF";
    string P = "BACA";

    Solution sol;
    cout << sol.findPattern(T,P) << endl;

    return 0;
}
 
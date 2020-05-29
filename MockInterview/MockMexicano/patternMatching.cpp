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
    vector<int> findPattern(string& t, string& p){
       if (p.size()>t.size() || p.size() == 0)
           return {};
           
       int j = 0;
       vector<int> index;
       for (int i=0;i<t.size();i++){
           if (t[i]==p[j]){
                j++;
                if (j == p.size())
                    index.push_back(i-p.size()+1);
           }
           else { 
               i=i-j;
               j=0; // in KMP algorithm only changes here!!! F[j-1]
           }
        }
        
        return index;
     }

    vector<int> strStr(string& haystack, string& needle) {
        if (needle.empty()) return {};
        if (needle.size()>haystack.size()) return {};
        vector<int> indexes;
        for (int i=0;i<=haystack.size()-needle.size();i++){
            bool found = true;
            for (int j=0;j<needle.size();j++){
                if (needle[j]!=haystack[i+j]){
                    found = false;
                    break;
                }
            }
            if (found) 
                indexes.push_back(i);
        }
        return indexes; // not founded
    }
};
// Time: O(n*m)
// Space: O(1), no extra space

int main(){
    string T = "ABACDBACAABACABACDF";
    string P = "BACA";

    Solution sol;
    vector<int> indexes = sol.findPattern(T,P);

    for (int i:indexes)
        cout << i << " ";
    cout << endl;

    indexes = sol.strStr(T,P);

    for (int i:indexes)
        cout << i << " ";
    cout << endl;

    return 0;
}
 
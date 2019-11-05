#include <bits/stdc++.h>

using namespace std;

/* This algorithm finds all occurrences of a pattern in a text in linear time. Let length of text be n and of pattern be m,
then total time taken is O(m + n) with linear space complexity. Now we can see that both time and space complexity
is same as KMP algorithm but this algorithm is Simpler to understand. 

Complexities:
Time: O(n+m) == KMP
Space: O(n+m) != KMP-->O(m) KMP is more economic here!!!

*/

class Solution {
public:
    list<int> search(string txt, string pattern){
        // concatenate 
        string concat = pattern + '$' + txt;
        
        // construct Z array
        int Z[concat.size()];
        getZarr(concat,Z);

        list<int> ans;
        // now we just have to search where Z[i] is equal to the size of the pattern
        for (int i=0;i<concat.size();i++){
            if (Z[i]==pattern.size()){
                ans.push_back(i-pattern.size()-1); // easy to find all occurrences
            }
        }
        return ans;

    }
    void getZarr(string str, int Z[]){ // not quite trivial as I thought
        int n = str.length(); 
        int L, R; // left, right
    
        // [L,R] make a window which matches with prefix of s 
        L = R = 0; 
        for (int i = 1; i < n; ++i) { // iterates a window starts at i 
            // if i>R nothing matches so we will calculate. 
            // Z[i] using naive way. 
            if (i > R) { 
                L = R = i; 
    
                // R-L = 0 in starting, so it will start 
                // checking from 0'th index. For example, 
                // for "ababab" and i = 1, the value of R 
                // remains 0 and Z[i] becomes 0. For string 
                // "aaaaaa" and i = 1, Z[i] and R become 5 
                while (R<n && str[R-L] == str[R]) 
                    R++; 
                Z[i] = R-L; 
                R--; // goes back because of the while loop
            } 
            else { // now we're in [L,R]
                // k = i-L so k corresponds to number which 
                // matches in [L,R] interval. 
                int k = i-L; 
    
                // if Z[k] is less than remaining interval 
                // then Z[i] will be equal to Z[k]. 
                // For example, str = "ababab", i = 3, R = 5 
                // and L = 2 
                if (Z[k] < R-i+1) // if it's possible to just copy values without comparisons 
                    Z[i] = Z[k]; 
    
                // For example str = "aaaaaa" and i = 2, R is 5, 
                // L is 0 
                else { // if it's not possible, then we do the same that we did before when "i" is after the window [L,R] 
                    // else start from R and check manually 
                    L = i; 
                    while (R<n && str[R-L] == str[R]) 
                        R++; 
                    Z[i] = R-L; 
                    R--; 
                } 
            } 
        } 
    }
};

int main(){
    string txt = "matheus vidal de menezes";
    string pattern = "faca";

    Solution sol;
    list<int> ans = sol.search(txt,pattern);

    if (ans.size()==0)
        cout << "No matches" << endl;
    else {
        for (auto i:ans)
            cout << "Pos: " << i << endl;
    }

    return 0;
}
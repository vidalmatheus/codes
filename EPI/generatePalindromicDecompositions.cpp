#include <bits/stdc++.h>

using namespace std;

/*

"0204451881"

[
    ["020","44","5","1881"]
    ["020","44","5","1","88","1"]
    ...
]

*/

class BruteForceSolution {
public:
    bool isPalindrome(string& s){ // O(n)
        for (int i=0,j=s.size()-1; i<j; i++,j--)
            if (s[i] != s[j])
                return false;
        return true;
    }

    bool isPalindromeDecomposition(vector<string>& decom){ // sum (O(n-x) + O(x)), for all x in [1,n-1] => O(n^2)
        for (int i=0;i<decom.size();i++)
            if (!isPalindrome(decom[i]))
                return false;
        return true;
    }

    void gen(string& s, vector<string>& ans, int start, vector<string>& curr){
        if (start == s.size()){
            if (isPalindromeDecomposition(curr)){
                string str = "";
                for (int i=0; i<curr.size(); i++)
                    str.append(curr[i] + " ");
                ans.push_back(str);
            }
            return;
        }

        for (int i=start;i<s.size();i++){
            int len = i-start+1;
            curr.push_back(s.substr(start, len));
            gen(s, ans, i+1, curr);
            curr.pop_back();
        }
    }

    vector<string> generatePalindromicDecompositions(string& s){
        if (s.size() == 0)
            return {};
        
        vector<string> ans;
        vector<string> curr = {};
        gen(s,ans,0,curr);

        return ans;
    }
    // Time: O(n^2*n*2^(n-1))
    // Space: O(n^2*n*2^(n-1))
};


int main(){
    string s = "0204451881";

    BruteForceSolution bfsol;
    cout << "\nGenerate All Palindromic Decompositions:" << endl;
    vector<string> ans = bfsol.generatePalindromicDecompositions(s);

    for (string s : ans)
        cout << s << endl;

    return 0;
}
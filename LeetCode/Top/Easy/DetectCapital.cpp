#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size()==0)
            return false;
        
        int counter = 0;
        for (int i=0;i<word.size();i++)
            if (isCapitalLetter(word[i]))
                counter++;
        
        return counter == word.size() || counter == 1 && isCapitalLetter(word[0]) || counter==0;
    }
    
    bool isCapitalLetter(char c){
        return (c>='A' && c<='Z');
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    string word = "USA";

    Solution sol;
    sol.detectCapitalUse(word) ? cout << "true\n" : cout << "false\n";

    return 0;
}

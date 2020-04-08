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
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};
        
        unordered_map<int,string> map(8);
        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz";
        
        vector<string> ans;
        string word;
        search(map,digits,ans,word,0);

        return ans;
    }

    void search(unordered_map<int,string> &map,string &digits,vector<string> &ans,string word,int pos) {
        if (pos == digits.size()){
            ans.push_back(word);
            return;
        }
        
        string letters = map[digits[pos]-'0'];
        for (int i=0;i<letters.size();i++){
            search(map,digits,ans,word+letters[i],pos+1);
        }
    }
};
// Time: O(3^n)
// Space: O(3^n)

int main() {
    string digits = "7";

    vector<string> ans;

    Solution sol;
    ans = sol.letterCombinations(digits);

    for (string word:ans)
        cout << word << " ";
    cout << endl;

    return 0;
}

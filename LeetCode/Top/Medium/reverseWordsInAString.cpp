#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
"  hello world!  "

c: world!
word: "hello"
words: "world! hello"
*/

class SlowSolution { // because of ' += ' and that works with a copy: O(n^2)
public:
    string reverseWords(string s) {
        if (s.size() == 0)
            return "";
        
        string words = "";
        string word = "";
        for (int i=0;i<(int)s.size();i++){
            char c = s[i];
            if (c != ' '){
                word += c;
            }
            else {
                if (word != "")
                    words = words == "" ? word : word + " " + words;
                word = "";
            }
        }
        
        if (word != "")
            words = words == "" ? word : word + " " + words;
        return words;
    }
};
// Time: O(A)
// Space: O(A)

class Solution {
public:
    string reverseWords(string s) {
        if (s.size() == 0)
            return "";
        
        vector<string> words;
        string word = "";
        for (int i=0;i<(int)s.size();i++){
            char c = s[i];
            if (c != ' '){
                word += c; // you could save runtime here, by using substr() method
            }
            else {
                if (word != "") words.push_back(word);
                word = "";
            }
        }
        
        if (word != "") words.push_back(word);
        
        reverse(words);
        
        string ans = "";
        for (int i=0;i<(int)words.size();i++)
            ans += words[i] + " ";
        
        if (ans.size() > 0) ans.pop_back();
        return ans;
    }
    
    void reverse(vector<string>& words){ // Time: O(n), n: number of words ; Space: O(1)
        if (words.size() == 0)
            return;
        for (int i=0,j=(int)words.size()-1;i<j;i++,j--)
            swap(words[i],words[j]);
    }
};
// Time: O(A)
// Space: O(A)

int main(){
    string s = "  hello   world!    ";

    Solution sol;
    cout << sol.reverseWords(s) << endl;

    return 0;
}

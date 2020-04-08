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
    bool wordPattern(string pattern, string str) {
        if (str.size()==0 && pattern.size()!=0)
            return false;
        
        string word;
        unordered_map<char,string> patternToStr(pattern.size());
        unordered_map<string,char> strToPattern(pattern.size());
        int j = 0;
        for (int i=0;i<=str.size();i++){
            if (str[i]!=' ' && i!=str.size()) 
                word.push_back(str[i]);
            else {
                if (patternToStr.find(pattern[j])!=patternToStr.end() || strToPattern.find(word)!=strToPattern.end()){
                    if (patternToStr[pattern[j]]!=word || strToPattern[word]!=pattern[j])
                        return false;
                }
                else{
                    patternToStr[pattern[j]]=word;
                    strToPattern[word]=pattern[j];
                }
                j++;
                word.clear();
            }
        }
        
        return true;
    }
};
// Time: O(n), n: str.size()
// Space: O(m), m: pattern.size() 

int main(){
    string pattern = "abba";
    string str = "dog dog dog dog";

    Solution sol;
    sol.wordPattern(pattern,str) ? cout << "true\n" : cout << "false\n";

    return 0;
}
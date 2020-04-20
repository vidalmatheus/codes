#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class FirstSolution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        if (paragraph.size()==0)
            return "";
        
        unordered_map<string,int> counter;
        int maxFrequency = 0;
        vector<string> mostFreq;
        string word = "";
        string ans = "";
        for (int i=0;i<=paragraph.size();i++){
            if (i<paragraph.size() && !isPunctuationSymbol(paragraph[i]))
                word+=paragraph[i];
            else if (word!="") {
                toLowercase(word);
                if (!belongs2(banned,word)){
                    if (counter.find(word)!=counter.end()) // found
                        counter[word]++;
                    else counter[word]=1;
                    
                    if (counter[word]>maxFrequency){
                        maxFrequency = counter[word];
                        ans = word;
                    }
                }
                word = "";
            }
        }
        
        return ans;
    }
    
    bool isPunctuationSymbol(char c){
        if (c!=' ' && c!='!' && c!='?' && c!='\'' && c!=',' && c!=';' && c!='.')
            return false;
        return true;
    }
    
    bool belongs2(vector<string>& ignore, string& word){
        for (string word2Ignore:ignore)
            if (word==word2Ignore)
                return true;
        return false;
    }
    
    void toLowercase(string& word){
        for (int i=0;i<word.size();i++)
            word[i]=tolower(word[i]);
    }
};
// Time: O(n*m), n words and m forbidden words
// Space: O(n)

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        if (paragraph.size()==0)
            return "";
        
        unordered_map<string,int> counter;
        string word = "";
        for (int i=0;i<=paragraph.size();i++){
            if (i<paragraph.size() && !isPunctuationSymbol(paragraph[i]))
                word+=paragraph[i];
            else if (word!="") {
                toLowercase(word);
                if (counter.find(word)!=counter.end()) // found
                    counter[word]++;
                else counter[word]=1;
                
                word = "";
            }
        }
        
        for (string word2ban:banned)
            if (counter.find(word2ban)!=counter.end()) // found
                counter.erase(word2ban);

        int maxFreq = 0;
        string ans = "";
        for (auto elem:counter)
            if (elem.second>maxFreq){
                maxFreq = elem.second;
                ans = elem.first;
            }

        return ans;
    }
    
    bool isPunctuationSymbol(char c){
        if (c!=' ' && c!='!' && c!='?' && c!='\'' && c!=',' && c!=';' && c!='.')
            return false;
        return true;
    }

    void toLowercase(string& word){
        for (int i=0;i<word.size();i++)
            word[i]=tolower(word[i]);
    }
};
// Time: O(n+m)
// Space: O(n)



int main(){
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = {"hit"};

    Solution sol;
    cout << sol.mostCommonWord(paragraph,banned) << endl;

    return 0;
}

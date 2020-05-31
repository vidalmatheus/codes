#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class WrongSolution {
public:
    int minDistance(string word1, string word2) {
        // edge cases
        if (word2.size()==0)
            return word1.size();
        if (word1.size()==0)
            return word2.size();
        
        return word1.size() > word2.size() ? helper(word1,word2) : helper(word2,word1);
    }
    
    int helper(string& word1, string& word2){ // word1.size() >= word2.size()
        int op = 0;
        
        int start = 0;
        long int lastMatch = INT_MAX;
        // we need to find where to begin
        int maxMatch = INT_MIN;
        for (int i=0;i<=(int)(word1.size()-word2.size());i++){
            int counter = 0;
            for (int j=0;j<word2.size();j++){
                if (word1[i+j] == word2[j]){
                    counter++;
                    lastMatch = min<long int>(lastMatch,i+j);
                }
            }
            if (maxMatch < counter)
                start = i;
            maxMatch = max(maxMatch,counter);
        }


        op += word2.size() - maxMatch;

        cout << "start: " << start << endl; 
        // we need to delete everything from 0 up to start-1
        word1.erase(0,start);
        op += start;            

        // deleting tail
        op += word1.size()-word2.size();

        cout << "op: " << op << endl;

        int deletingTail = start;

        cout << word1 << endl;
        cout << "lastMatch: " << lastMatch << endl;            

        long int i=lastMatch+1;
        if (lastMatch < word2.size()-1){
            while (word1.substr(0,word2.size()) != word2 && i<word1.size()){
                word1.erase(i++,1);
                deletingTail++;
            }

            cout << word1 << endl;
            cout << word2 << endl;
            cout << deletingTail << endl;         

            // do the replaces
            for (int j=0;j<lastMatch;j++){
                if (word1[j] != word2[j]){
                    word1[j] = word2[j];
                    deletingTail++;
                }
            }

            if (word1 == word2)
                return min(op,deletingTail); 
        }

        return op;
    }
};

class RecursiveSolution {
public:
    int minDistance(string word1, string word2) {
        if (word2.size()==0)
            return word1.size();
        if (word1.size()==0)
            return word2.size();
          
        if (word1[word1.size()-1] == word2[word2.size()-1])
            return minDistance(word1.substr(0,word1.size()-1),word2.substr(0,word2.size()-1));
        
        int insertion = minDistance(word1,word2.substr(0,word2.size()-1)) + 1;
        int deletion = 1 + minDistance(word1.substr(0,word1.size()-1),word2);
        int replacement = 1 + minDistance(word1.substr(0,word1.size()-1),word2.substr(0,word2.size()-1));
        
        return min(insertion,min(deletion,replacement));      
    }     
};
// Time: O(3^(n+m))
// Space: O(n+m)

class Solution {
private:
    vector<vector<int>> memo;
public:
    int minDistance(string word1, string word2) {
        memo.resize(word1.size()+1,vector<int>(word2.size()+1,-1));
        
        return rec(word1,word2);
    }     
    
    int rec(string word1, string word2){
        if (word2.size()==0)
            return word1.size();
        if (word1.size()==0)
            return word2.size();
         
        if (memo[word1.size()][word2.size()] != -1)
            return memo[word1.size()][word2.size()];
    
        if (word1[word1.size()-1] == word2[word2.size()-1])
            return memo[word1.size()][word2.size()] = rec(word1.substr(0,word1.size()-1),word2.substr(0,word2.size()-1));
        
        int insertion = rec(word1,word2.substr(0,word2.size()-1)) + 1;
        int deletion = 1 + rec(word1.substr(0,word1.size()-1),word2);
        int replacement = 1 + rec(word1.substr(0,word1.size()-1),word2.substr(0,word2.size()-1));
        
        return memo[word1.size()][word2.size()] = min(insertion,min(deletion,replacement)); 
    }
};
// Time: O(n*m)
// Space: O(n*m)

int main(){
    // string word1 = "horse";
    // string word2 = "ros";

    string word1 = "intention";
    string word2 = "execution";

    Solution sol;
    cout << sol.minDistance(word1,word2) << endl;

    return 0;
}
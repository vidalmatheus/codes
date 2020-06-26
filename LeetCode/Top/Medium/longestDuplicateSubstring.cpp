#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
private:
    vector<long int> roll;
    const int p = 10000007;
public:
    string longestDupSubstring(string S) {
        if (S.size() == 0)
            return "";
        
        int size = S.size();
        roll.resize(size);
        roll[0] = 1;
        for (int i=1;i<size;++i)
            roll[i] = (26*roll[i-1])%p;
            
        int left = 1;
        int right = size;
        string curr = "";
        string LDS = "";
        while (left <= right){
            int mid = left + (right-left)/2;
            if (isMatch(S,mid,curr)){
                if (curr.size() > LDS.size())
                    LDS = curr;
                left = mid + 1;
            }
            else right = mid-1;
        }
        
        return LDS;
    }
    
    
    bool isMatch(string& s, int size, string& curr){ // Rabin-Karp (must know)
        unordered_map<int,vector<int>> hashValue;
        int hash = 0;
        for (int i=0;i<size;++i)
            hash = (hash*26 + (s[i]-'a'))%p;
            
        hashValue[hash].push_back(0);
        // sliding window
        for (int j=size;j<s.size();++j){
            hash = ((hash-roll[size-1]*(s[j-size]-'a'))%p + p)%p;
            hash = (hash*26 + (s[j]-'a'))%p;
            if (hashValue.find(hash) != hashValue.end()){
                for (int start : hashValue[hash]){
                    if (s.substr(start,size) == s.substr(j-size+1,size)){
                        curr = s.substr(start,size);
                        return true;
                    }
                }
            }
            hashValue[hash].push_back(j-size+1);
        }
        
        return false;
    }
};
// Time: O(n*log n), on average
// Space: O(1)

class KMPSolution { // This solution was worth to understand that essentially KMP looks for non-overlapping substrings.
public:
    string longestDupSubstring(string S) {
        
        int size = S.size();
        int max_occurrences = INT_MIN;
        int suffix_size = 0;
        int last_occurrence = -1;
        for (int i=1;i<size;i++){
            
            string suffix = S.substr(i,size-i);
            cout << suffix << endl;
            pair<int,int> occurrences = kmp(S,suffix); // {last_occurrence, amount_of_occurrences}
            
            if (occurrences.second > max_occurrences){
                max_occurrences = occurrences.second;
                suffix_size = size-i;
                last_occurrence = occurrences.first;
            }
        }
        if (max_occurrences < 2)
            return "";

        return S.substr(last_occurrence,suffix_size);
    }
    
    // abcd
    //     i
    // bcd
    //    j
    
    pair<int,int> kmp (string& s, string& p){
        if (s.size() == 0 || p.size() > s.size())
            return {-1,0};
        
        vector<int> F;
        getFailureFunction(p,F);
        
        int counter = 0;
        
        int end_pattern = -1;
        
        int i = 0; // goes through the text
        int j = 0; // goes through the pattern
        while (i < s.size()){
            if (s[i] == p[j]){ // match
                i++;
                j++;
                if (j == p.size()){
                    counter++;
                    if (counter > p.size()){
                        counter = 1;
                        break;
                    }
                    j = 0;
                    end_pattern = --i;
                }
            }
            else { // mismatch
                if (j != 0) 
                    j = F[j-1];
                else i++;
            }
        }
        
        // end - begin + 1 = size
        return {end_pattern-p.size()+1, counter};
    }
    
    // i j
    // aacdcd
    // 010
    //
    void getFailureFunction(string& p, vector<int>& F){ // longest suffix that it is also a prefix
        F.resize(p.size());
        F[0] = 0;
        int i = 0; // goes for the prefixes
        int j = 0; // goes for the suffixes
        while (j < p.size()){
            if (p[j] == p[i]){
                F[j++] = ++i;
            }
            else {
                if (i != 0)
                    i = F[i-1]; // you don't go all the way back!
                else F[j++] = 0;
            }
        }
    }
};
// Time: O(n^2)
// Space: O(n)

int main(){
    string S = "banana";

    Solution sol;
    cout << sol.longestDupSubstring(S) << endl;

    return 0;
}

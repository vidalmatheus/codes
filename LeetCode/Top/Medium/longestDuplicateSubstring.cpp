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

int main(){
    string S = "banana";

    Solution sol;
    cout << sol.longestDupSubstring(S) << endl;

    return 0;
}

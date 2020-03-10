#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() == 0 && magazine.size() == 0)
            return true;
        
        if (ransomNote.size() != 0 && magazine.size() == 0)
            return false;
        
        if (ransomNote.size() == 0 && magazine.size() != 0)
            return true;
        
        unordered_map<char,int> m;
        
        for (char c:ransomNote) {
            if (m.find(c)!=m.end())
                m[c]++;
            else m[c]=1;
        }
        
        for (char c:ransomNote) {
            int count = 0;
            for (int i=0;i<magazine.size();i++) {
                if (magazine[i] == c)
                    count++;
            }
            
            if (count < m[c])
                return false;
        }
        
        return true;
    }
    // Time: O(n*m)
    // Space: O(1)

    bool canConstruct_fast(string ransomNote, string magazine) {
        if (ransomNote.size() == 0 && magazine.size() == 0)
            return true;
        
        if (ransomNote.size() != 0 && magazine.size() == 0)
            return false;
        
        if (ransomNote.size() == 0 && magazine.size() != 0)
            return true;
        
        unordered_map<char,int> m;
        
        for (char c:magazine) {
            if (m.find(c)!=m.end())
                m[c]++;
            else m[c]=1;
        }
        
        for (char c:ransomNote) {
            if (m.find(c)!=m.end()){
                m[c]--;
                if (m[c]<0)
                    return false;
            }
            else return false;
        }
        
        return true;
    }
    // Time: O(n+m)
    // Space: O(1)
};

int main() {
    string ransomNote = "aa";
    string magazine = "ab";

    Solution sol;
    sol.canConstruct_fast(ransomNote,magazine) ? cout << "true\n" : cout << "false\n";

    return 0;
}
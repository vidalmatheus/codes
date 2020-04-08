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
    bool isIsomorphic(string s, string t) {
        if (s.size()!=t.size())
            return false;
        
        unordered_map<char,char> s2t(s.size());
        unordered_map<char,char> t2s(s.size());
        
        for (int i=0;i<s.size();i++){
            if (s2t.find(s[i])==s2t.end()) // not found
                s2t[s[i]] = t[i];
            else if (s2t[s[i]]!=t[i])
                    return false;
            
            if (t2s.find(t[i])==t2s.end()) // not found
                t2s[t[i]] = s[i];
            else if (t2s[t[i]]!=s[i])
                    return false;
        }
        
        return true;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    string s = "egg";
    string t = "add";

    Solution sol;
    sol.isIsomorphic(s,t) ? cout << "true\n" : cout << "false\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class InplaceSolution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size()>t.size())
            return false;
        
        if (s.size()==0)
            return true;
        
        int start = 0;
        for (int i=0;i<s.size();i++){
            bool found = false;
            for (int j=start;j<t.size();j++){
                if (t[j]==s[i]){
                    start = j+1;
                    found = true;
                    break;
                }
            }
            if (!found)
                return false;
        }
        
        return true;
    }
};
// Time: O(n*m)
// Space: O(1)

class RecursiveSolution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size()>t.size())
            return false;
        
        if (s.size()==0)
            return true;

        return isSub(s,0,t,0);
    }

    bool isSub(string& s, int startS, string& t, int startT){
        if (startS==s.size())
            return true;    
        
        if (startT==t.size())
            return false;

        if (s[startS]==t[startT])
            return isSub(s,startS+1,t,startT+1);
        else return isSub(s,startS,t,startT+1);
    }

};
// Time: O(n*m)
// Space: O(n)

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size()>t.size())
            return false;
        
        if (s.size()==0)
            return true;
        
        int index = 0; // goes through string s
        for (int j=0;j<t.size();j++){
            if (t[j]==s[index])
                index++;
            if (index==s.size())
                return true;
        }

        return false;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    string s = "abc";
    string t = "ahbgdc";

    Solution sol;
    sol.isSubsequence(s,t) ? cout << "true\n" : cout << "false\n";

    return 0;
}
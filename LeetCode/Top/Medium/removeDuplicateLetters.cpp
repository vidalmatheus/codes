#include <bits/stdc++.h>

using namespace std;

auto speedup=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.size() == 0)
            return "";
        
        string ans = "";
        string curr = "";
        unordered_set<char> seen;
        rec(s,ans,curr,seen,0);
        
        
        return ans;
    }
    
    void rec(string& s, string& ans, string& curr, unordered_set<char>& seen, int pos){
        if (pos == s.size()){
            if (isOk(curr,ans))
                ans = curr;
            return;
        }
        
        if (seen.find(s[pos]) != seen.end()){
            rec(s,ans,curr,seen,pos+1);
        }
        else {
            // with
            curr.push_back(s[pos]);
            seen.insert(s[pos]);
            rec(s,ans,curr,seen,pos+1);
            
            // without
            curr.pop_back();
            seen.erase(s[pos]);
            rec(s,ans,curr,seen,pos+1);
        }
    }
    
    bool isOk(string& curr, string& ans){ // O(n)
        if (ans.size() == 0)
            return true;
        
        if (curr.size() == 0)
            return false;
        
        if (curr.size() < ans.size())
            return false;
        
        int n = ans.size();
        int pos = 0;
        for (int i=0;i<n;i++){
            if (curr[i] == ans[i])
                continue;
            else {
                pos = i;
                break;
            }
        }
        
        return curr[pos] < ans[pos];
    }
};
// Time: O(n*log n * 2^n)
// Space: O(n*2^n)

int main(){
    Solution sol;
  
    string s1 = "cbacdcbc";
    assert(sol.removeDuplicateLetters(s1) == "acdb");

    string s2 = "bcabc";
    assert(sol.removeDuplicateLetters(s2) == "abc");

    string s3 = "sdgssd";
    assert(sol.removeDuplicateLetters(s3) == "dgs");

    string s4 = "aoskdmaosmkdas";
    assert(sol.removeDuplicateLetters(s4) == "admoks");

    string s5 = "sdddf";
    assert(sol.removeDuplicateLetters(s5) == "sdf");

    string s6 = "lfklsdfkoandsmasmasidnfnvc";
    assert(sol.removeDuplicateLetters(s6) == "fkldoamsinvc");

    string s7 = "aaaaaaaaaabb";
    assert(sol.removeDuplicateLetters(s7) == "ab");


    cout << "Passed!" << endl;
    return 0;
}
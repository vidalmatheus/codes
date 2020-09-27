#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    char findTheDifference(string s, string t) {
        if (s.size() == 0)
            return t[0];
        
        unordered_map<char,int> freq;
        for (char c : s)
            freq[c]++;
        
        for (char c : t){
            freq[c]--;
            if (freq[c] == -1)
                return c;
        }
        
        return -1;
    }
};
// Time: O(n)
// Space: O(n)

class BetterSolution {
public:
    char findTheDifference(string s, string t) {
        if (s.size() == 0)
            return t[0];
        
        vector<int> freq(26,0);
        for (char c : s)
            freq[c-'a']++;
        
        for (char c : t){
            freq[c-'a']--;
            if (freq[c-'a'] == -1)
                return c;
        }
        
        return -1;
    }
};
// Time: O(n)
// Space: O(n)

class BestSolution {
public:
    char findTheDifference(string s, string t) {
        if (s.size() == 0)
            return t[0];
        
        int XOR = 0;
        int n = s.size();
        for (int i=0;i<n;i++){
            XOR ^= s[i];
            XOR ^= t[i];
        }
        
        return XOR ^ t[n];
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    Solution sol;

    string s1 = "abcd";
    string t1 = "abcde";
    assert(sol.findTheDifference(s1,t1) == 'e');

    cout << "Passed!" << endl;
    return 0;
}
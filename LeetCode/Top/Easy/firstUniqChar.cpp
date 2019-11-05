/* First Unique Character in a String
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters. */

#include <bits/stdc++.h>

using namespace std;

static int speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int> counter;
        for (int i=0;i<s.size();i++){ // finds the occurrences
            counter[s[i]-'a']++;
        }
        // Finds the first unique character
        for (int i=0;i<s.size();i++){
            if (counter[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};
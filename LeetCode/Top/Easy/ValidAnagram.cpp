/* Valid Anagram
Solution
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case? */

#include <bits/stdc++.h>

using namespace std;

static auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/* class Solution{
public:
    bool isAnagram(string s, string t) { // O(n)
        if (s.size()!=t.size())
            return false;
        vector<int> counter(26);
        for (int i=0;i<s.size();i++){
            counter[s[i]-'a']++;
            counter[t[i]-'a']--;
        }
        // Check is counter == [0,0,...]
        for (int i:counter){
            if (i!=0)
                return false;
        }
        return true;
    }
}; */

class Solution{ // Using HashTable instead of fixed size counter
public:
    bool isAnagram(string s, string t) { // O(n)
        if (s.size()!=t.size())
            return false;
        unordered_map<int,int> counter;
        for (int i=0;i<s.size();i++){
            counter[s[i]-'a']++;
            counter[t[i]-'a']--;
        }
        // Check is counter == [0,0,...]
        for (auto i:counter){
            if (i.second!=0)
                return false;
        }
        return true;
    }
};

int main(){
    string s1,s2;
    cin >> s1;
    cin >> s2;
    Solution sol;
    if (sol.isAnagram(s1,s2)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
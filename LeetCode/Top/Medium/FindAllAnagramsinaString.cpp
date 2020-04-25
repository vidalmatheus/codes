#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class SlowSolution { // TLE
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size()==0 || s.size()<p.size())
            return {};
        
        vector<int> ans;
        sort(p.begin(),p.end());
        unordered_map<int,string> sub;
        int index = 0;
        while (index<=s.size()-p.size()){
            string str = s.substr(index,p.size());
            sort(str.begin(),str.end());
            if (str==p)
                ans.push_back(index);
            index++;
        }
        
        return ans;
    }  
};
// Time: O(n*m*(log(m))
// Space: O(log m)

class StillSlowSolution { // Time Limit Exceeded !!! 
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size()==0 || s.size()<p.size())
            return {};
        
        vector<int> ans;
        for (int i=0;i<s.size();i++){
            if (isAnagram(s,p,i))
                ans.push_back(i);
        }
        
        return ans;
    }
    
    bool isAnagram(string& s, string& p, int index){
        unordered_map<char,int> letters;
        for (int i=index;i<index+p.size() && i<s.size();i++)
            if (letters.find(s[i])!=letters.end()) // found
                letters[s[i]]++;
            else letters[s[i]]=1;
        
        int maxCounter = INT_MIN;
        for (char c:p){
            if (letters.find(c)==letters.end()) // not found
                return false;
            letters[c]--;
            if (letters[c]<0)
                return false;
        }

        for (auto elem:letters)
            if (elem.second>0)
                return false;

        return true;
    }
    // Time: O(m)
    // Space: O(m)
};
// Time: O(n*m)
// Space: O(m)

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size()==0 || s.size()<p.size())
            return {};
        
        vector<int> ans;
        vector<int> charCounter(26,0);
        for (char c:p)
            charCounter[c-'a']++;
        
        int left = 0;
        int right = 0;
        int counter = 0;
        
        while (right < s.size()){
            if (charCounter[s[right]-'a'] >= 1)
                counter++;
            
            charCounter[s[right++]-'a']--;
            
            if (counter==p.size())
                ans.push_back(left);
            
            if (right - left == p.size()){
                if (charCounter[s[left]-'a'] >= 0)
                    counter--;
                charCounter[s[left++]-'a']++;
            }
        }
        
        return ans;
    }
};
// Time: O(n)
// Space: O(1)

class HashSolution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size()==0 || s.size()<p.size())
            return {};
        
        vector<int> ans;
        

        unordered_map<char,int> charCounter;

        for (char c:p)
            if (charCounter.find(c)!=charCounter.end()) // found
                charCounter[c]++;
            else charCounter[c]=1;
            // you could have done that without this else clause
        
        int left = 0;
        int right = 0;
        int counter = 0;
        
        while (right < s.size()){
            if (charCounter.find(s[right])!=charCounter.end()){ // found;
                if (charCounter[s[right]] >= 1){
                    counter++;
                    charCounter[s[right]]--;
                }
            }
            right++;
            
            if (counter==p.size())
                ans.push_back(left);
            
            if (right - left == p.size()){
                if (charCounter.find(s[left])!=charCounter.end()){ // found
                    counter--;
                    charCounter[s[left]]++;
                }
                left++;
            }
        }
        
        return ans;
    }
};
// Time: O(n)
// Space: O(1)


int main(){
    string s = "cbaebabacd";
    string p = "abc";

    // string s = "baa";
    // string p = "aa";

    Solution sol;
    vector<int> ans = sol.findAnagrams(s,p);

    cout << "[ ";
    for (int e:ans)
        cout << e << " ";
    cout << "]";

    return 0;
}

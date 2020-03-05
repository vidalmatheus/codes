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
    int lengthOfLongestSubstring(string s) {
        if (s.size()==0)
            return 0;
        int max_length = 0;
        unordered_set<char> hashSet;
        int start=0;
        for (int i=start;i<s.size();i++){
            if (hashSet.find(s[i])!=hashSet.end()){
                while (s[start]!=s[i]){
                    hashSet.erase(s[start]);
                    start++;
                }
                hashSet.erase(s[start]);
                start++;
                hashSet.insert(s[i]);
            }
            else{ 
                hashSet.insert(s[i]);
                if (hashSet.size() > max_length)
                    max_length = hashSet.size();
            }
        }
        return max_length;
    }
    // Time: O(n²)
    // Space: O(n)

    int lengthOfLongestSubstringFast(string s) {
        int st = 0;
        int cnt[256] = {0};
        int ans=0;
        for(int i=0;s[i];i++){
            cnt[s[i]]++; 
            while(cnt[s[i]]>1){
                cnt[s[st++]]--;
            }
            ans = max(ans,i-st+1);
        }
        return ans;
    }
};

int main(){
    string s ="abcabcbb";

    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;

    return 0;
}
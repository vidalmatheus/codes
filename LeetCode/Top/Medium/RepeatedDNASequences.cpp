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
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size()==0)
            return {};
        
        vector<string> ans;
        unordered_map<string,int> map;
        for (int i=0;i+9<s.size();i++){
            string sub = s.substr(i,10);
            if (map.find(sub)==map.end()) // not found
                map[sub]=1;
            else{ 
                map[sub]++;
                if (map[sub]==2)
                    ans.push_back(sub);
            }
        }
        
        return ans;
    }
};
// Time: O(n)
// Space: O(k), where k is the number of repeated 10-letter-long sequences

int main(){
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

    Solution sol;
    vector<string> ans = sol.findRepeatedDnaSequences(s);

    for (string s:ans)
        cout << s << " ";
    cout << endl;

    return 0;
}

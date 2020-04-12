#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct  myComparator {
    bool operator() (string& e1, string& e2){
        return e1.size()<e2.size();
    }
};

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        if(words.size()==0)
            return {};
        
        struct myComparator obj;
        sort(words.begin(),words.end(),obj);
        
        for (string e:words)
            cout << e << " ";
        cout << endl;

        vector<string> ans;
        unordered_set<string> s;
        for (int i=0;i<words.size();i++){
            for (int j=i+1;j<words.size();j++){
                if (words[j].find(words[i])!=string::npos)
                    s.insert(words[i]);
            }
        }

        for (auto e:s)
            ans.push_back(e);
        
        return ans;
    }
};
// Time: O(n^3)
// Space: O(log (n))

int main(){
    vector<string> words = {"leetcoder","leetcode","od","hamlet","am"};

    Solution sol;
    vector<string> ans = sol.stringMatching(words);

    for (string e:ans)
        cout << e << " ";
    cout << endl;

    return 0;
}

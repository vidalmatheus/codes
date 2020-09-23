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
    vector<string> reorderLogFiles(vector<string>& logs) {
        if (logs.size() == 0)
            return {};
        
        int n = logs.size();
        vector<pair<string,string>> let;
        vector<string> dig;
        for (int i=0;i<n;i++){

            string id = "";
            for (int j=0;logs[i][j] != ' ';j++){
                char c = logs[i][j];
                id += c;
            }
            
            string content = logs[i].substr(id.size()+1);            
            int m = content.size();
            if (isalpha(content[m-1]))
                let.push_back({content,id});
            else
                dig.push_back(logs[i]);
        }
        
        sort(let.begin(),let.end());
        
        vector<string> ans(let.size());
        for (int i=0;i<let.size();i++)
            ans[i] = let[i].second + " " + let[i].first;
        
        ans.insert(ans.end(),dig.begin(),dig.end());
        
        return ans;
    }
};
// Time: O(M*N*log N), N is the size of input, M is the maximum length of a log
// Space: O(M*N)

int main(){
    Solution sol;
    vector<string> logs1{"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
    vector<string> ans1{"let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"};
    assert(sol.reorderLogFiles(logs1) == ans1);

    vector<string> logs2{"t kvr", "r 3 1", "i 403", "7 so", "t 54"};
    vector<string> ans2{"t kvr","7 so","r 3 1","i 403","t 54"};
    assert(sol.reorderLogFiles(logs2) == ans2);
    cout << "Passed!" << endl;
    return 0;
}
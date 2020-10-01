#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    unordered_set<string> visited;
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        if (words.size() == 0)
            return {};
        
        int m = words[0].size(); // size of the square
        vector<vector<string>> ans;
        vector<string> curr;
        string row(m,'#');
        for (int i=0;i<m;i++)
            curr.push_back(row);
        
        for (int i=0;i<words.size();i++){
            swap(words[0],words[i]);
            cout << "Starting with: " << words[0] << endl;
            dfs(ans,curr,words,0,0);
            for (int j=0;j<m;j++)
                curr[j] = row;
            visited.clear();
        }
        
        return ans;
    }
    
    /*
             i
    "wall","area","lead","lady","ball"
    
    [
        wall
        a
        l
        l
        
    ]
    */
    
    void dfs(vector<vector<string>>& ans, vector<string>& curr, vector<string>& words, int pos, int start){
        if (pos < words.size() && visited.find(words[pos]) != visited.end())
            return;
        
        if ((pos == words.size() && start != words[0].size()))
            return;
        cout << "word: " << words[pos] << endl;
        for (auto s : curr)
            cout << s << endl;
        
        if (start == words[0].size()){
            ans.push_back(curr);
            return;
        }
        if (0 < start)
            cout << curr[start][start-1] << " == " << words[pos][start-1] << endl;
        
        if (start > 0 && curr[start][start-1] != words[pos][start-1])
            return;
        
        for (int i=start;i<words[0].size();i++)
            curr[start][i] = words[pos][i];
        
        for (int i=start;i<words[0].size();i++)
            curr[i][start] = words[pos][i];
    
        visited.insert(words[pos]);
        
        for (int k=pos+1;k<=words.size();k++)
            dfs(ans,curr,words,k,start+1);
        
        for (int i=start;i<words[0].size();i++)
            curr[start][i] = '#';
        
        for (int i=start;i<words[0].size();i++)
            curr[i][start] = '#';
        
    }
};
// Time: O(n*m^2)
// Space: O(n*m^2)

int main(){
    Solution sol;

    vector<string> words{"area","lead","wall","lady","ball"};
    vector<vector<string>> ans{
        {
            "wall",
            "area",
            "lead",
            "lady"
        },
        {
            "ball",
            "area",
            "lead",
            "lady"
        }
    };
    assert(sol.wordSquares(words) == ans);


    cout << "Passed!" << endl;
    return 0;
}
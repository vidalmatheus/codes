#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

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

class SlowSolution { // TLE
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
            dfs(ans,curr,words,0,0);
            for (int j=0;j<m;j++)
                curr[j] = row;
        }
        
        return ans;
    }
    
    void dfs(vector<vector<string>>& ans, vector<string>& curr, vector<string>& words, int pos, int start){
        if (start == words[0].size()){
            if (ans.size() == 0 || (ans.size() > 0 && curr != ans.back()))
                ans.push_back(curr);
            return;
        }

        if (pos == words.size())
            return;

        if (curr[start].substr(0,start) != words[pos].substr(0,start))
            return;
        
        for (int i=start;i<words[0].size();i++)
            curr[start][i] = words[pos][i];
        
        for (int i=start;i<words[0].size();i++)
            curr[i][start] = words[pos][i];
        
        for (int k=0;k<=words.size();k++)
            dfs(ans,curr,words,k,start+1);
        
        for (int i=start;i<words[0].size();i++)
            curr[start][i] = '#';
        
        for (int i=start;i<words[0].size();i++)
            curr[i][start] = '#';
        
    }
};
// Time: O(n*m^3)
// Space: O(n*m^3)

int main(){
    SlowSolution sol;

    vector<string> words1{"area","lead","wall","lady","ball"};
    vector<vector<string>> ans1{
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

    vector<vector<string>> resp1 = sol.wordSquares(words1);
    assert(resp1 == ans1);


    vector<string> words2{"abat","baba","atan","atal"};
    vector<vector<string>> ans2{
        {
            "baba",
            "abat",
            "baba",
            "atan"
        },
        {
            "baba",
            "abat",
            "baba",
            "atal"
        }
    };

    vector<vector<string>> resp2 = sol.wordSquares(words2);
    assert(resp2 == ans2);
    
    cout << "Passed!" << endl;
    return 0;
}
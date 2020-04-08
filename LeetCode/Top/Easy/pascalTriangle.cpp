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
    vector<vector<int>> generate(int numRows) {
        if (numRows==0) return {};
        vector<vector<int>> ans;
        int size = 0;
        for (int i=0;i<numRows;i++){
            size++;
            vector<int> line(size);
            line[0]=1;
            for (int j=1;j<size-1;j++){
                line[j] = ans[i-1][j] + ans[i-1][j-1];
            }                
            line[size-1]=1;
            ans.push_back(line);
        }
        return ans;
    }
};

int main(){
    int n = 5;
    vector<vector<int>> matrix;
    Solution sol;
    matrix = sol.generate(n);
    for (auto i:matrix){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
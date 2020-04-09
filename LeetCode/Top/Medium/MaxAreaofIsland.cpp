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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size()==0)
            return 0;
        
        // vector<vector<int>> copy = grid;
        int max = 0;
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j]){
                    int counter = 0;
                    dfs(grid,i,j,counter);
                    if (counter>max)
                        max = counter;
                }
            }
        }
        
        return max;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int& counter){
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
            return;
        
        grid[i][j]=0;
        counter++;
        
        dfs(grid,i+1,j,counter); //down
        dfs(grid,i-1,j,counter); // up
        dfs(grid,i,j-1,counter); // left
        dfs(grid,i,j+1,counter); // right
    }
};
// Time: O(n*m)
// Space: O(n*m)

int main(){
    vector<vector<int>> grid = {
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,0,1,1},
        {0,0,0,1,1},
    };

    cout << "Before: " << endl;
    for (auto row:grid){
        for (int e:row){
            cout << e << " ";
        }
        cout << endl;
    }

    Solution sol;
    cout << sol.maxAreaOfIsland(grid) << endl;

    cout << "After: " << endl;
    for (auto row:grid){
        for (int e:row){
            cout << e << " ";
        }
        cout << endl;
    }

    return 0;
}

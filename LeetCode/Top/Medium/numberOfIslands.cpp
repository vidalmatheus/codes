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
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size()==0)
            return 0;
        int numIslands = 0;
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j]=='1'){ // we've found an island
                    // sink this island
                    sink(grid,i,j);
                    numIslands++;
                    for (auto i:grid){
                        for (auto j:i)
                            cout << j << " ";
                        cout << endl;
                    }
                    cout << "--------" << endl;
                }
            }
        }
        return numIslands;
    }

    void sink (vector<vector<char>> &grid,int i,int j){
        // if we're out of boundries or we've found a zero, do nothing
        if (i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0') 
            return; 
        // sink the element
        grid[i][j] = '0';
        // sink other around that element
        sink(grid,i-1,j);
        sink(grid,i+1,j);
        sink(grid,i,j-1);
        sink(grid,i,j+1);
    }
/*     void sinkIterative (vector<vector<char>> &grid,int i,int j){ // THAT'S WRONG!
        // sink the element
        grid[i][j] = '0';
        // sink other around that element
        for (int k=i-1;k>=0 && grid[k][j]=='1';k--)
            grid[k][j] = '0';
        for (int k=i+1;k<grid.size() && grid[k][j]=='1';k++)
            grid[k][j] = '0';   
        for (int k=j-1;k>=0 && grid[i][k]=='1';k--)
            grid[i][k] = '0';
        for (int k=j+1;k<grid[0].size() && grid[i][k]=='1';k++)
            grid[i][k] = '0';     
    } */
};


int main(){
    vector<vector<char>> grid = { {'1','1','0','0','0'}, {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'} };
    for (auto i:grid){
        for (auto j:i)
            cout << j << " ";
        cout << endl;
    }
    cout << "--------" << endl;
    Solution sol;
    cout << sol.numIslands(grid) << endl;
    return 0;
}

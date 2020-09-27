#include <bits/stdc++.h>

using namespace std;


static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*

11000
11000
00011
00011

*/

class FirstSolution { // slow
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        
        set<set<pair<int,int>>> islands;
        set<pair<int,int>> island; // set of points
        for (int i=0;i<(int)grid.size();i++){
            for (int j=0;j<(int)grid[0].size();j++){
                if (grid[i][j] == 1){
                    int minI = grid.size();
                    int minJ = grid[0].size();
                    dfs(grid,i,j,island,minI,minJ);
                    
                    // tranlation
                    if (max(minI,minJ) != 0)
                        for (set<pair<int,int>>::iterator it=island.begin();it!=island.end();++it){
                            int x = it->first;
                            int y = it->second;
                            island.erase(*it);
                            island.insert({x-minI,y-minJ});
                        }
                    
                    // store island
                    islands.insert(island);
                    island.clear();
                }
            }
        }
    
        return islands.size();
    }
    
    bool valid(vector<vector<int>>& grid, int i, int j){
        return i>=0 && j>=0 && i<grid.size() && j<grid[0].size();
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, set<pair<int,int>>& island, int& minI, int& minJ){
        if (!valid(grid,i,j) || grid[i][j] != 1)
            return;
        
        grid[i][j] = 2;
        minI = min(minI,i);
        minJ = min(minJ,j);
        island.insert({i,j});
        int dir[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
        for (int k=0;k<4;k++){
            int next_i = i + dir[k][0];
            int next_j = j + dir[k][1];
            dfs(grid,next_i,next_j,island,minI,minJ);
        }
    }
};
// Time: O(n^2*m^2*log(n*m))
// Space: O(n*m)

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        
        set<vector<pair<int,int>>> islands;
        vector<pair<int,int>> island; // set of points
        for (int i=0;i<(int)grid.size();i++){
            for (int j=0;j<(int)grid[0].size();j++){
                if (grid[i][j] == 1){
                    int minI = grid.size();
                    int minJ = grid[0].size();
                    dfs(grid,i,j,island,minI,minJ);
                    
                    // tranlation
                    if (max(minI,minJ) != 0)
                        for (int k=0;k<island.size();k++){
                            island[k].first -= minI;
                            island[k].second -= minJ;                         
                        }
                    
                    // store island
                    islands.insert(island);
                    island.clear();
                }
            }
        }
    
        return islands.size();
    }
    
    bool valid(vector<vector<int>>& grid, int i, int j){
        return i>=0 && j>=0 && i<grid.size() && j<grid[0].size();
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, vector<pair<int,int>>& island, int& minI, int& minJ){
        if (!valid(grid,i,j) || grid[i][j] != 1)
            return;
        
        grid[i][j] = 2;
        minI = min(minI,i);
        minJ = min(minJ,j);
        island.push_back({i,j});
        int dir[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
        for (int k=0;k<4;k++){
            int next_i = i + dir[k][0];
            int next_j = j + dir[k][1];
            dfs(grid,next_i,next_j,island,minI,minJ);
        }
    }
};
// Time: O(n*m)
// Space: O(n*m)

int main(){
    vector<vector<int>> grid{
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,0,1,1},
        {0,0,0,1,1}
    };

    vector<vector<int>> grid2{
        {1,1,0,1,1},
        {1,0,0,0,0},
        {0,0,0,0,1},
        {1,1,0,1,1}
    };

    Solution sol;
    assert(sol.numDistinctIslands(grid) == 1);
    assert(sol.numDistinctIslands(grid2) == 3);
    cout << "Passed!" << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

bool isValid (vector<vector<int>>& image, int i, int j){
    return i>=0 && j>=0 && i<image.size() && j<image[0].size();
}

void dfs(vector<vector<int>>& image, vector<vector<int>>& ans, int i, int j, int& x, int& y){
    if (!isValid(image,i,j) || image[i][j] != 0)
        return;
    
    image[i][j] = 2;
    x = i;
    y = j;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    for (int k=0;k<4;k++){
        int next_i = i + dir[k][0];
        int next_j = j + dir[k][1];
        dfs(image,ans,next_i,next_j,x,y);
    }
}

vector<vector<int>> getRectangles(vector<vector<int>>& image){
    
    vector<vector<int>> ans;
    for (int i=0;i<(int)image.size();i++){
        for (int j=0;j<(int)image[0].size();j++){
            if (image[i][j] == 0){
                int x,y;
                dfs(image,ans,i,j,x,y);
                ans.push_back({i,j,x,y});
            }
        }
    }

    return ans;
}
// Time: O(n*m)
// Space: O(n+m)

int main(){

    vector<vector<int>> image = {
        {0,1,1,1,1,1,1},
        {1,0,1,0,0,0,1},
        {0,1,1,0,0,0,1},
        {1,0,0,1,1,1,0},
    };

    vector<vector<int>> ans = getRectangles(image);
    for (auto v : ans){
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
    
    return 0;
}
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
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (newColor == image[sr][sc])
            return image;
        dfs(image,sr,sc,image[sr][sc],newColor);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int i, int j, int oldColor, int newColor){
        if (i<0 || i>=image.size() || j<0 || j>=image[0].size() || image[i][j]!=oldColor)
            return;
        
        image[i][j] = newColor;
        dfs(image,i-1,j,oldColor,newColor);
        dfs(image,i+1,j,oldColor,newColor);
        dfs(image,i,j-1,oldColor,newColor);
        dfs(image,i,j+1,oldColor,newColor);
    }
};
// Time: O(m*n)
// Space: O(n+m)

int main(){
    vector<vector<int>> image{
        {0,0,0},
        {0,1,1}
    };

    int sr = 1;
    int sc = 1;
    int newColor = 1;

    Solution sol;
    sol.floodFill(image,sr,sc,newColor);

    for (auto row:image){
        for (int e:row)
            cout << e << " ";
        cout << endl;
    }

    return 0;
}

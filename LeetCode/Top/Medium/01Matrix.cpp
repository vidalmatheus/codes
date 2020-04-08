#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class WRONGSolution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.size()==0)
            return {};
        
        for (int i=0;i<matrix.size();i++){
            for (int j=0;j<matrix[0].size();j++){
                if (matrix[i][j]){
                    int minimum = INT_MAX;
                    rec(matrix,i,j,0,minimum);
                    matrix[i][j]=minimum;
                }
            }
        }
        
        return matrix;
    }
    
    bool isOutbound(vector<vector<int>>& matrix, int i, int j){
        if (i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size())
            return true;
        return false;
    }
    
    void rec(vector<vector<int>>& matrix, int i, int j, int counter, int& minimum){
        if (isOutbound(matrix,i,j) || matrix[i][j]==-1)
            return;
        
        if (!matrix[i][j]){ // if it's zero
            return;
        }
        
        matrix[i][j]=-1;
        counter++;

        int down = counter;
        int up = counter;
        int right = counter;
        int left = counter;

        rec(matrix,i+1,j,counter,down);
        rec(matrix,i-1,j,counter,up);
        rec(matrix,i,j+1,counter,right);
        rec(matrix,i,j-1,counter,left);

        matrix[i][j]=1;
        
        minimum = min(minimum,down);
        minimum = min(minimum,up);
        minimum = min(minimum,right);
        minimum = min(minimum,left);
    }
};
// Time: O(n*m)
// Space: O(n*m)

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.size()==0)
            return {};
        
        bfs(matrix);    
        
        return matrix;
    }
    
    bool isOutOfBounds(vector<vector<int>>& matrix, pair<int,int>& p){
        if (p.first<0 || p.second<0 || p.first>=matrix.size() || p.second>-matrix[0].size())
            return true;
        return false;
    }
    
    void bfs(vector<vector<int>>& matrix){
        queue<pair<int,int>> q;
        for (int i=0;i<matrix.size();i++){
            for (int j=0;j<matrix[0].size();j++){
                if (matrix[i][j]==0){
                    q.push({i,j});
                }
                else matrix[i][j]=INT_MAX;
            }
        }
        
        int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} }; // good way to traversal a graph as matrix
        while (!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            for (int i=0;i<4;i++){
                pair<int,int> next = {curr.first+dir[i][0],curr.second+dir[i][1]};
                if (!isOutOfBounds(matrix,next)){
                    if (matrix[next.first][next.second] > matrix[curr.first][curr.second]+1){ // if the neighbor has distance greater than 1, then update it
                        matrix[next.first][next.second] = matrix[curr.first][curr.second]+1;
                        q.push({next.first,next.second});
                    }
                }
            }
        }
    }
};
// Time: O(n*m)
// Space: O(n*m)

class DPSolution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.size()==0)
            return {};

        for (int i=0;i<matrix.size();i++){
            for (int j=0;j<matrix[0].size();j++){
                if (matrix[i][j]){
                    matrix[i][j] = INT_MAX-1;
                    if (i>0)
                        matrix[i][j]=min(matrix[i][j],matrix[i-1][j]+1);
                    if (j>0)
                        matrix[i][j]=min(matrix[i][j],matrix[i][j-1]+1);
                }
            }
        }

        for (int i=matrix.size()-1;i>=0;i--){
            for (int j=matrix[0].size()-1;j>=0;j--){
                if (matrix[i][j]){
                    if (i<matrix.size()-1)
                        matrix[i][j]=min(matrix[i][j],matrix[i+1][j]+1);
                    if (j<matrix[0].size()-1)
                        matrix[i][j]=min(matrix[i][j],matrix[i][j+1]+1);
                }
            }
        }

        return matrix;
    }
};
// Time: O(n*m)
// Space: O(1)

int main(){
    vector<vector<int>> matrix = {
      {0,0,0},
      {0,1,0},
      {1,1,1}  
    };

    cout << "Matrix: " << endl;
    for (auto row:matrix){
        for (int e:row)
            cout << e << " ";
        cout << "\n";
    }

    Solution sol;
    matrix = sol.updateMatrix(matrix);

    cout << "Updated: " << endl;
    for (auto row:matrix){
        for (int e:row)
            cout << e << " ";
        cout << "\n";
    }

    return 0;
}

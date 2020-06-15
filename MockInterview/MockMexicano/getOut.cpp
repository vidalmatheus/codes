#include <bits/stdc++.h>

using namespace std;

// 12  3   5    2
// 13  1  74   66
// 14 77 418    6
// 15 16  335 999


/*

Time: O(4^(n*m))

Memoization -> Time: O(n*m)
							Space: O(n*m)


DP -> Time: O(n*m)
			Space: O(1), without answer space

*/

typedef vector< vector<int> > matrixInt;
typedef vector< vector<bool> > matrixBool;

bool valid(int i, int j, int n, int m) {
	return i >= 0 && j >= 0 && i < n && j < m;
}

void dfs(int i, int j, matrixInt &input, matrixBool &output) {
  if (output[i][j]) return;
	output[i][j] = true;
  int n = input.size();
  int m = input[0].size();
  int di[4] = {0, 1, 0, -1};
  int dj[4] = {1, 0, -1, 0};
  for (int dir = 0; dir < 4; dir++) {
  	int ni = i + di[dir];
    int nj = j + dj[dir];
    if (!valid(ni, nj, n, m)) {
    	continue;
    }
    if (input[i][j] < input[ni][nj]) dfs(ni, nj, input, output);
  }
}

matrixBool solutionTB(matrixInt &input) {
  int n = input.size();
  int m = input[0].size();
	matrixBool output(n, vector<bool>(m));
  for (int i = 0; i < n; i++) {
  	dfs(i, 0, input, output);
    dfs(i, m-1, input, output);
  }
  for (int j = 0; j < m; j++) {
  	dfs(0, j, input, output);
    dfs(n-1, j, input, output);
  }
  return output;
}

matrixBool solutionBT(matrixInt &input) {
	int n = input.size();
  int m = input[0].size();
	matrixBool output(n, vector<bool>(m));
  stack<int> qi, qj;
  for (int i = 0; i < n; i++) {
  	qi.push(i);
  	qj.push(0);
   	output[i][0] = true;
  	qi.push(i);
  	qj.push(m-1);
   	output[i][m-1] = true;
  }
  for (int j = 0; j < m; j++) {
  	qi.push(0);
  	qj.push(j);
   	output[0][j] = true;
  	qi.push(n-1);
  	qj.push(j);
   	output[n-1][j] = true;
  }
  
  int di[4] = {0, 1, 0, -1};
  int dj[4] = {1, 0, -1, 0};
  while(!qi.empty() && !qj.empty()) {
  	int i = qi.top(); qi.pop();
  	int j = qj.top(); qj.pop();
    for (int dir = 0; dir < 4; dir++) {
      int ni = i + di[dir];
      int nj = j + dj[dir];
      if (!valid(ni, nj, n, m)) {
        continue;
      }
      if (input[i][j] < input[ni][nj] && !output[ni][nj]) {
      	qi.push(ni);
        qj.push(nj);
   			output[i][j] = true;
      }
    }
  }
}

vector<vector<bool>> solution(vector<vector<int>>& matrix){
	if (matrix.size() == 0)
    return {};
  
  // edge cases
  
  vector<vector<bool>> dp(matrix.size(),vector<bool>(matrix[0].size(),true));
  
  // T   T  T    T
  // T   F  T    T
  // T   T  T    T
  // T   T  T    T

  /*
  (0,1)
  (1,1)
  
  T-> above
  T-> below
  ...
  */
  
// 	for (int i=1;i<dp.size()-1;++i){
//   	for (int j=1;j<dp[0].size()-1;++j){
//       	bool canMove = false;
//       	dp[i][j]=false;
//       	if (matrix[i-1][j] < matrix[i][j]){
//           dp[i][j] |= dp[i-1][j];
//           canMove = true;
//         }
        
//         if (matrix[i+1][j] < matrix[i][j]){
//           dp[i][j] |= dp[i+1][j]; 
//           canMove = true;
//         }
      
//         if (matrix[i][j-1] < matrix[i][j]){
//           dp[i][j] |= dp[i][j-1];
//           canMove = true;
//         }
      
//         if (matrix[i][j+1] < matrix[i][j]){
//           dp[i][j] |= dp[i][j+1];
//           canMove = true;
//         }
      	
//       	if (!canMove)
//           dp[i][j] = false;
      
//     }
//   }
  
  return dp;
}


// 12  3   5    2
// 13  1  74   66
// 14 77 418    6
// 15 16  335 999


//  T   T   T    T
//  T   F        T
//  T   T   T    T
//  T   T   T    T
 
class Solution {
public:
    vector<vector<bool>> getOut(vector<vector<int>>& matrix){
        if (matrix.size() == 0)
            return {};
        
        vector<vector<bool>> ans(matrix.size(),vector<bool>(matrix[0].size(),true));
        vector<vector<bool>> visited(matrix.size(),vector<bool>(matrix[0].size(),false));
        
        for (int i=1;i<matrix.size();i++){
            for (int j=1;j<matrix[0].size();j++){
                if (!visited[i][j]){
                    dfs(matrix,visited,ans,i,j);
                }
            }
        }

        return ans;
    }

    bool isValid(vector<vector<int>>& matrix, int i, int j){
        return i>=0 && j>=0 && i<matrix.size() && j<matrix[0].size();
    }

    bool dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, vector<vector<bool>>& ans, int i, int j){
        if (!isValid(matrix,i,j))
            return true;

        if (visited[i][j])
            return ans[i][j];

        visited[i][j] = true;
        if (i == 0  || i == matrix.size()-1 || j == 0 || j == matrix[0].size()-1)
            return true;

        int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        bool response = false;
        for (int k=0;k<4;++k){
            int next_i = i + dir[k][0];
            int next_j = j + dir[k][1];
            if (matrix[i][j] >= matrix[next_i][next_j])
                response |= dfs(matrix,visited,ans,next_i,next_j);
        }    

        return ans[i][j] = response;
    }
};


class LessSpaceSolution {
public:
    vector<vector<int>> getOut(vector<vector<int>>& matrix){
        if (matrix.size() == 0)
            return {};
        
        vector<vector<int>> ans(matrix.size(),vector<int>(matrix[0].size(),-1));
        for (int i=0;i<matrix.size();i++){
            for (int j=0;j<matrix[0].size();j++){
                if (ans[i][j] == -1){
                    dfs(matrix,ans,i,j);
                }
            }
        }

        return ans;
    }

    bool isValid(vector<vector<int>>& matrix, int i, int j){
        return i>=0 && j>=0 && i<matrix.size() && j<matrix[0].size();
    }

    bool dfs(vector<vector<int>>& matrix, vector<vector<int>>& ans, int i, int j){
        if (!isValid(matrix,i,j))
            return true;

        if (ans[i][j] != -1)
            return ans[i][j];

        if (i == 0  || i == matrix.size()-1 || j == 0 || j == matrix[0].size()-1)
            return ans[i][j] = true;

        int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        bool response = false;
        for (int k=0;k<4;++k){
            int next_i = i + dir[k][0];
            int next_j = j + dir[k][1];
            if (matrix[i][j] >= matrix[next_i][next_j])
                response |= dfs(matrix,ans,next_i,next_j);
        }    

        return ans[i][j] = response;
    }
};

// 12  3   5    2
// 13  1  74   66
// 14 77 418    6
// 15 16  335 999

// 9 9 9 9
// 9 2 1 1
// 9 9 9 9

int main(){
    // vector<vector<int>> matrix {
    //     {12,  3,   5,    2},
    //     {13,  1,  74,   66},
    //     {14, 77, 418,    6},
    //     {15, 16, 335,  999}
    // };

    vector<vector<int>> matrix {
        { 9,  9,   9,    9},
        { 9,  2,   1,    1},
        { 9,  9,   9,    9}
    };

    LessSpaceSolution sol;
    vector<vector<int>> ans = sol.getOut(matrix);

    for (auto row:ans){
        for (int i:row)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
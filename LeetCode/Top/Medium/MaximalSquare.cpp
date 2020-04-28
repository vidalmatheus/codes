#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class RecursiveSolution { // TIME LIMIT EXCEEDED
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size()==0)
            return 0;
        
        int maxSquare = 0;
        for (int i=0;i<matrix.size();i++)
            for (int j=0;j<matrix[0].size();j++)
                if (matrix[i][j]=='1')
                    maxSquare = max(maxSquare,rec(matrix,i,j));
        
        return maxSquare*maxSquare;
    }
    
    int rec(vector<vector<char>>& matrix, int i, int j){
        if (i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]=='0')
            return 0;
        
        int down = rec(matrix,i+1,j);
        int right = rec(matrix,i,j+1);
        int diag = rec(matrix,i+1,j+1);

        int minSquare = min(min(down,right),diag);

        return 1+minSquare;
    }
};
// Time: O((mn)^2)
// Space: O(m+n)

class TopDownDPSolution { // memoization
private:
    vector<vector<int>> memo;
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size()==0)
            return 0;
        
        memo.resize(matrix.size(),vector<int>(matrix[0].size(),-1));

        int maxSquare = 0;
        for (int i=0;i<matrix.size();i++)
            for (int j=0;j<matrix[0].size();j++)
                if (matrix[i][j]=='1')
                    maxSquare = max(maxSquare,rec(matrix,i,j));
        
        return maxSquare*maxSquare;
    }
    
    int rec(vector<vector<char>>& matrix, int i, int j){
        if (i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]=='0')
            return 0;
        
        if (memo[i][j]!=-1)
            return memo[i][j];

        int down = rec(matrix,i+1,j);
        int right = rec(matrix,i,j+1);
        int diag = rec(matrix,i+1,j+1);

        int minSquare = min(min(down,right),diag);

        return memo[i][j] = 1+minSquare;
    }
};
// Time: O(m*n)
// Space: O(m*n)

class BottomUpSolution { // dynamic programming - bottom- up approach
private:
    vector<vector<int>> dp;
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size()==0)
            return 0;
        
        dp.resize(matrix.size(),vector<int>(matrix[0].size(),-1));
        
        int maxSquare = 0;
        for (int i=0;i<dp.size();i++){
            dp[i][0] = matrix[i][0] - '0';
            maxSquare = max(maxSquare,dp[i][0]);
        }
        
        for (int j=0;j<dp[0].size();j++){
            dp[0][j] = matrix[0][j] - '0';
            maxSquare = max(maxSquare,dp[0][j]);
        }
        
        for (int i=1;i<matrix.size();i++)
            for (int j=1;j<matrix[0].size();j++)
                if (matrix[i][j]=='1'){
                    dp[i][j] = 1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
                    maxSquare = max(maxSquare,dp[i][j]);
                }
                else dp[i][j] = 0;
        
        return maxSquare*maxSquare;
    }
};
// Time: O(m*n)
// Space: O(m*n)

int main(){
    vector<vector<char>> matrix{
        {'1','1','0','1'},
        {'1','1','0','1'},
        {'1','1','1','1'}
    };

    TopDownDPSolution sol;
    cout << sol.maximalSquare(matrix) << endl;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

/*
(i,j)_A -> (i,j)_B
(i,j)_A -> (i,j+1)_B : 1 slide to the right
(i,j)_A -> (i,j-1)_B : 1 slide to the left
(i,j)_A -> (i+1,j)_B : 1 slide dowm
(i,j)_A -> (i-1,j)_B : 1 slide up
  
. . . x x x 
. . .
. . . 

1 + (n-1)^4 -> O(n^4) (Brute force)
*/

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
private:
    vector<vector<int>> memo;
    vector<vector<bool>> visited;
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        if (A.size() == 0)
            return 0;
        
        memo.resize(2*A.size(),vector<int>(2*A[0].size(),-1));
        visited.resize(2*A.size(),vector<bool>(2*A[0].size(),false));
        
        return rec(A,B,0,0);
    }
    
    int rec(vector<vector<int>>& A, vector<vector<int>>& B, int di, int dj){
        int r = di+A.size();
        int c = dj+A[0].size();
        if (abs(di) >= A.size() || abs(dj) >= A[0].size() || visited[r][c])
            return 0;
        
        if (memo[r][c] != -1)
            return memo[r][c];
        
        visited[r][c] = true;
            
        int counter = 0;
        for (int i=0;i<A.size();i++){
            for (int j=0;j<A[0].size();j++){
                int row = i + di;
                int col = j + dj;
                if (isValid(B,row,col) && A[i][j] == B[row][col] && A[i][j] == 1)
                    counter++;
            }
        }
    
        counter = max(counter,rec(A,B,di+1,dj));
        counter = max(counter,rec(A,B,di-1,dj));
        counter = max(counter,rec(A,B,di,dj+1));
        counter = max(counter,rec(A,B,di,dj-1));
        
        return memo[r][c] = counter;
    }
    
    bool isValid(vector<vector<int>>& A, int i, int j){
        return i >= 0 && j >= 0 && i < A.size() && j < A[0].size();
    }
};
// Time: O(n*m)
// Space: O(n*m)

class ConvSolution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        if (A.size() == 0)
            return 0;
        
        // n-1 + n-1 + n = 3n-2
        // m-1 + m-1 + m = 3m-2
        int n = A.size();
        int m = A[0].size();
        vector<vector<int>> Bpadded(3*n-2,vector<int>(3*m-2,0));
        
        int row = 0;
        for (int i=n-1;i<2*n-1;i++){
            int col = 0;
            for (int j=m-1;j<2*m-1;j++)
                Bpadded[i][j] = B[row][col++];
            row++;
        }
            
        int maxConv = 0;
        for (int i=0;i<=2*n-2;i++)
            for (int j=0;j<=2*m-2;j++)
                maxConv = max(maxConv,conv(Bpadded,A,i,j)); // O(n*m)
        
        return maxConv;
    }
    
    int conv(vector<vector<int>>& M, vector<vector<int>>& A, int startRow, int startCol){
        int n = A.size();
        int m = A[0].size();
        
        int ans = 0;
        int row = 0;
        for (int i=startRow;i<startRow+n;i++){
            int col = 0;
            for (int j=startCol;j<startCol+m;j++)
                ans += M[i][j]*A[row][col++];
            row++;
        }
            
        return ans;
    }    
};
// Time: O((n*m)^2)
// Space: O(n*m)

int main(){
    vector<vector<int>> A {
            {1,1,0},
            {0,1,0},
            {0,1,0}
    };
    vector<vector<int>> B {
            {0,0,0},
            {0,1,1},
            {0,0,1}
    };

    assert ((new Solution)->largestOverlap(A,B) == 3);   
    cout << "Passed!" << endl;
    return 0;
}
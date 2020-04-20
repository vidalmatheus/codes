#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
rec(house i, color j): 
  if i==(size of matrix)
    return 0

  return cost_of_color(i,j) + min(rec(house i+1, color != j))
*/

class SlowSolution { // TIME LIMIT EXCEEDED
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        if (A.size()==0)
            return 0;
        
        int n = A.size();
        int k = A[0].size();
        
        int minSum = INT_MAX;
        for (int i=0;i<k;i++)
            minSum = min(minSum,rec(A,0,i));
        
        return minSum;
    }
    
    int rec(vector<vector<int>>& A, int house, int color){
        if (house == A.size())
            return 0;
        
        int minSum = INT_MAX;
        for (int i=0;i<A[0].size();i++)
            if (i!=color)
                minSum = min(minSum,rec(A,house+1,i));
        
        return A[house][color] + minSum;
    }
};
// Time: O(k*(k-1)^(n-1)) = O(k^n)
// Space: (n)

class Solution { // Memoization
private: 
    vector<vector<int>> memo;
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        if (A.size()==0)
            return 0;
        
        memo.resize(A.size(),vector<int>(A[0].size(),-1));
        
        int n = A.size();
        int k = A[0].size();
        
        int minSum = INT_MAX;
        for (int i=0;i<k;i++)
            minSum = min(minSum,rec(A,0,i));
        
        return minSum;
    }
    
    int rec(vector<vector<int>>& A, int house, int color){
        if (house == A.size())
            return 0;
        
        if (memo[house][color]!=-1)
            return memo[house][color];
        
        int minSum = INT_MAX;
        for (int i=0;i<A[0].size();i++)
            if (i!=color)
                minSum = min(minSum,rec(A,house+1,i));
        
        return memo[house][color] = A[house][color] + minSum;
    }
};
// Time: O(n*k^2)
// Space: (n*k)

int main(){
    vector<vector<int>> A = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    Solution sol;
    cout << sol.minFallingPathSum(A) << endl;

    return 0;
}

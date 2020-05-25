#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class RecursionSolution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        if (A.size()==0 || B.size()==0)
            return 0;
        
        return rec(A,0,B,0);
    }
    
    int rec(vector<int>& A, int startA, vector<int>& B, int startB){
        if (startA == A.size() || startB == B.size())
            return 0;
        
        bool foundFromA2B = false;
        int indexFromA2B = startB;
        for (int i=startB;i<B.size();i++){
            if (A[startA] == B[i]){
                indexFromA2B = i;
                foundFromA2B = true;
                break;
            }
        }
        
        bool foundFromB2A = false;
        int indexFromB2A = startA;
        for (int i=startA;i<A.size();i++){
            if (B[startB] == A[i]){
                indexFromB2A = i;
                foundFromB2A = true;
                break;
            }
        }
        
        int A2B = foundFromA2B ? 1+rec(A,startA+1,B,indexFromA2B+1) : rec(A,startA+1,B,startB);
        int B2A = foundFromB2A ? 1+rec(A,indexFromB2A+1,B,startB+1) : rec(A,startA,B,startB+1);
        
        return max(A2B,B2A);
    }
};
// Time: O(n*2^n)
// Space: o(2^n)

class WrongSolution {
private:
    vector<vector<int>> memo;
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        if (A.size()==0 || B.size()==0)
            return 0;
        
        memo.resize(A.size(), vector<int>(B.size(),-1));
        
        return rec(A,0,B,0);
    }
    
    int rec(vector<int>& A, int startA, vector<int>& B, int startB){
        if (startA == A.size() || startB == B.size())
            return 0;
        
        if (memo[startA][startB]!=-1)
            return memo[startA][startB];
        
        bool foundFromA2B = false;
        int indexFromA2B = startB;
        for (int i=startB;i<B.size();i++){
            if (A[startA] == B[i]){
                indexFromA2B = i;
                foundFromA2B = true;
                break;
            }
        }
        
        bool foundFromB2A = false;
        int indexFromB2A = startA;
        for (int i=startA;i<A.size();i++){
            if (B[startB] == A[i]){
                indexFromB2A = i;
                foundFromB2A = true;
                break;
            }
        }
        
        int A2B = foundFromA2B ? 1+rec(A,startA+1,B,indexFromA2B+1) : rec(A,startA+1,B,startB);
        int B2A = foundFromB2A ? 1+rec(A,indexFromB2A+1,B,startB+1) : rec(A,startA,B,startB+1);
        
        return memo[startA][startB] = max(A2B,B2A);
    }
};
// Time: O(n^3), n = max(A.size(),B.size())
// Space: O(n^2)

// IT'S THE SAME OF LONGEST COMMON SUBSEQUENCE !!!!! VERY COOL!!!
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        if (A.size()==0 || B.size()==0)
            return 0;
        
        vector<vector<int>> dp(B.size()+1,vector<int>(A.size()+1,0));
        
        for (int i=1;i<=B.size();i++)
            for (int j=1;j<=A.size();j++)
                dp[i][j] = A[j-1] == B[i-1] ? dp[i-1][j-1]+1 : max(dp[i-1][j],dp[i][j-1]);
        
        return dp[B.size()][A.size()];
    }
};
// Time: O(n*m)
// Space: o(n*m)



int main(){
    // vector<int> A{1,4,2};
    // vector<int> B{1,2,4};

    vector<int> A{2,5,1,2,5};
    vector<int> B{10,5,2,1,5,2};

    Solution sol;
    cout << sol.maxUncrossedLines(A,B) << endl;

    return 0;
}

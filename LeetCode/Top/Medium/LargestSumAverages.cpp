#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*

Prefixes Sum:
0    []          --> 0
1    [9]         --> 9
2    [9,1]       --> 10
3    [9,1,2]     --> 12
4    [9,1,2,3]   --> 15

dp:
0   [9,1,2,3]-[]: [9,1,2,3]         --> (15-0)/4
1   [9,1,2,3]-[9]: [_,1,2,3]        --> (15-9)/3
2   [9,1,2,3]-[9,1]: [_,_,2,3]      --> (15-10)/2
3   [9,1,2,3]-[9,1,2]: [_,_,_,3]    --> (15-12)/1

*/

class Solution { // Slow Solution
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int N = A.size();
        vector<double> prefixSum(N+1,0);
        for (int i=1;i<prefixSum.size();i++)
            prefixSum[i] = A[i-1] + prefixSum[i-1];
        
        vector<double> dp(N,0);
        for (int i=0;i<N;i++)
            dp[i] = (prefixSum[N]-prefixSum[i])/(N-i);
        
        
        // dp
        for (int k=0;k<K-1;k++){
            // When I do these two for loops once, I'll have at most two partitions.
            // So, when i do these for M times, I'll have at most M+1 partitions.
            for (int i=0;i<N;i++)
                for (int j=i+1;j<N;j++)
                    dp[i] = max(dp[i], (prefixSum[j]-prefixSum[i])/(j-i) + dp[j]);
        }
        
        return dp[0];
    }
};
// Time: O(K*N^2)
// Space: O(N)

int main(){
    vector<int> A = {9,1,2,3,9};
    int K = 3;

    Solution sol;
    cout << sol.largestSumOfAverages(A,K) << endl;

    return 0;
}

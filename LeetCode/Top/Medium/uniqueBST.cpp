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
    int numTrees(int n) {
        double c = 1; 
        
        for (int i=0;i<n;i++){
            c*=(double)(2*n-i)/(n-i);
        }
        
        c/=(n+1);
        
        return round(c); // C_n: Catalan Number of n
    }
};
// Time: O(n)
// Space : O(1)

class IntuitiveSolution {
public:
    int numTrees(int n) {
        return C(n);
    }

    int C(int n){
        if (n==0 || n==1)
            return 1;
        
        int sum = 0;
        for(int i=1;i<=n;i++){
            sum+=F(i,n);
        }

        return sum;
    }

    int F(int i, int n){
        return C(i-1)*C(n-i);
    }
};
// Time: O(n^2)
// Space : O(n)


// OBS.: Another thing to know is that C_nn is the number of full binary trees with n + 1 leaves

class EasySolution {
public:
    int numTrees(int n) {
        vector<int> C(n + 1, 0);
        C[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // the current number of trees of size i is the sum from each subtree of size j, we have another subtree of size i-j-1
                C[i] += C[j] * C[i-j-1]; 
            }
        }
        return C[n];
    }
};


int main(){
    int n = 5;

    Solution sol;
    cout << sol.numTrees(n) << endl;

    return 0;
}

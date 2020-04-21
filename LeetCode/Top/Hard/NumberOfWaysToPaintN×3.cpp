#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class TopDowmSolution { // Top-Down Approach
public:
    int numOfWays(int n) {
        return solve2Colors(n) + solve3Colors(n);
    }

    int solve2Colors(int n){
        if (n==1)
            return 6;
        return 3*solve2Colors(n-1) + 2*solve3Colors(n-1);
    }

    int solve3Colors(int n){
        if (n==1)
            return 6;
        return 2*solve2Colors(n-1) + 2*solve3Colors(n-1);
    }
};
// Time: O(2^n)
// Space: O(n)

class TopDowmDPSolution { // Dynamic Programming (memoization) Top-Down Approach
private:
    vector<unsigned long int> memo2;
    vector<unsigned long int> memo3;
public:
    int numOfWays(int n) {
        memo2.resize(n+1,-1);
        memo3.resize(n+1,-1);
        
        return (solve2Colors(n) + solve3Colors(n))%(1000000007);
    }

    unsigned long int solve2Colors(int n){
        if (n==1)
            return memo2[n] = 6;
        
        if (memo2[n]!=-1)
            return memo2[n];

        return memo2[n] = (3*solve2Colors(n-1) + 2*solve3Colors(n-1))%1000000007;
    }

    unsigned long int solve3Colors(int n){
        if (n==1)
            return memo3[n] = 6;
        
        if (memo3[n]!=-1)
            return memo3[n];

        return memo3[n] = (2*solve2Colors(n-1) + 2*solve3Colors(n-1))%1000000007;
    }
};
// Time: O(n)
// Space: O(n)

class Solution { // Bottom-Up approach
public:
    int numOfWays(int n) {
        unsigned long int twoColors = 6;
        unsigned long int threeColors = 6;

        unsigned long int ansTwo = 6;
        unsigned long int ansThree = 6;
        for (int i=2;i<=n;i++){
            ansTwo = (3*twoColors + 2*threeColors)%(1000000007);
            ansThree = (2*twoColors + 2*threeColors)%(1000000007);
            twoColors = ansTwo;
            threeColors = ansThree;
        }
        return (ansTwo + ansThree)%(1000000007);
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    int n = 3;

    Solution sol;
    cout << sol.numOfWays(n) << endl;

    return 0;
}

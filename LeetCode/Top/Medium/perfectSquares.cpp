#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
Greedy Approach
rec(12): 1+rec(3) = 4 -> wrong!
        rec(3): 1+rec(2) = 3
            rec(2): 1+rec(1) = 2
                rec(1): 1
*/

class GreedySolution { // Greedy -> Wrong!
public:
    int numSquares(int n) {
        if (n == 0)
            return 0;
        
        if (n == 1)
            return 1;
        
        int squareRoot = (int)sqrt(n);

        if (n == squareRoot)
            return 1;
    
        return 1+numSquares(n-squareRoot*squareRoot);
    }
};

class RecursiveSolution {
public:
    int numSquares(int n) {
        if (n == 0)
            return 0;
        
        if (n == 1)
            return 1;
        
        int squareRoot = (int)sqrt(n);
        
        if (n == squareRoot)
            return 1;

        int response = INT_MAX;
        for (int i=1;i<=squareRoot;i++)
            response = min(response,1+numSquares(n-i*i));
    
        return response;
    }
};

class MemoSolution {
private:
    unordered_map<int,int> memo;
public:
    int numSquares(int n) {
        if (n == 0)
            return 0;
        
        if (n == 1)
            return 1;
        
        if (memo[n] != 0)
            return memo[n];
        
        int squareRoot = (int)sqrt(n);
        
        if (n == squareRoot)
            return memo[n] = 1;

        int response = INT_MAX;
        for (int i=1;i<=squareRoot;i++)
            response = min(response,1+numSquares(n-i*i));
    
        return memo[n] = response;
    }
};
// Time: O(n)
// Space: O(n)

class Solution {
private:
    vector<int> memo;
public:
    int numSquares(int n) {
        memo.resize(n+1,-1);
        return rec(n);
    }
    
    int rec(int n){
        if (n == 0)
            return 0;
        
        if (n == 1)
            return 1;

        if (memo[n] != -1)
            return memo[n];
        
        int squareRoot = (int)sqrt(n);

        if (n == squareRoot)
            return memo[n] = 1;
        
        int response = INT_MAX;
        for (int i=1;i<=squareRoot;i++)
            response = min(response,1+rec(n-i*i));
    
        return memo[n] = response;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    int n = 12;

    Solution sol;
    cout << sol.numSquares(n) << endl;

    return 0;
}

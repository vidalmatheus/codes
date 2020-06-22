#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class DFSSolution { // TLE
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.size() == 0)
            return 0;
        
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        int minHealth = INT_MAX;
        dfs(dungeon,0,0,0,1,minHealth);
        
        return minHealth;
    }
    
    bool isValid(vector<vector<int>>& dungeon, int i, int j){
        return i>=0 && j>=0 && i<dungeon.size() && j<dungeon[0].size();
    }
    
    void dfs(vector<vector<int>>& dungeon, int i, int j, int currSum, int pathHealth, int& minHealth){
        if (!isValid(dungeon,i,j))
            return;
        
        if (pathHealth > minHealth)
            return;
        
        if (i == dungeon.size()-1 && j == dungeon[0].size()-1){
            currSum += dungeon[i][j];
            pathHealth = max(pathHealth,1-currSum);
            minHealth = min(minHealth,pathHealth);
            return;
        }
        
        currSum += dungeon[i][j];
        pathHealth = max(pathHealth,1-currSum);
        
        int dir[2][2] = { {0,1},{1,0} };
        for (int k=0;k<2;k++){
            int next_i = i + dir[k][0];
            int next_j = j + dir[k][1];
            dfs(dungeon,next_i,next_j,currSum,pathHealth,minHealth);
        }
    }
};
// Time: O(2^(n+m))
// Space: O(n+m)

class MemoDFSSolution { // TLE
private:
    map<vector<int>,int> memo;
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.size() == 0)
            return 0;
        
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        int minHealth = INT_MAX;
        dfs(dungeon,0,0,0,1,minHealth);
        
        return minHealth;
    }
    
    bool isValid(vector<vector<int>>& dungeon, int i, int j){
        return i>=0 && j>=0 && i<dungeon.size() && j<dungeon[0].size();
    }
    
    void dfs(vector<vector<int>>& dungeon, int i, int j, int currSum, int pathHealth, int& minHealth){
        if (!isValid(dungeon,i,j))
            return;
        
        if (pathHealth > minHealth)
            return;
        
        if (i == dungeon.size()-1 && j == dungeon[0].size()-1){
            currSum += dungeon[i][j];
            pathHealth = max(pathHealth,1-currSum);
            minHealth = min(minHealth,pathHealth);
            memo[{i,j,currSum}] = minHealth;
            return;
        }
        
        if (memo.find({i,j,currSum}) != memo.end()){
            minHealth = min(minHealth,memo[{i,j,currSum}]);
            return;
        }
        
        currSum += dungeon[i][j];
        pathHealth = max(pathHealth,1-currSum);
        
        int dir[2][2] = { {0,1},{1,0} };
        for (int k=0;k<2;k++){
            int next_i = i + dir[k][0];
            int next_j = j + dir[k][1];
            dfs(dungeon,next_i,next_j,currSum,pathHealth,minHealth);
        }
    }
};
// Time: O((m*n)^2 * log (m*n))
// Space: O(m+n)

/*

     0    1   2
-----------------
0 | -2	 -3	  3
1 | -5	-10	  1
2 | 10	 30	 -5

     0    1    2
-----------------
0 |  6	  5    2
1 |  6	 11    5
2 |  1 	  1    6

f(i,j): answer from (i,j)

f(2,2) = max(1,x), from x + (-5) = 1 => x = 6
f(1,2) = max(1,x), from x + 1 + (-5) >= 1 => x = 5
                    curr + dungeon[i][j] + (1-prev) = 1 => curr + dungeon[i][j] - prev = 0 
                    curr = prev - dungeon[i][j]

f(2,1) = max(1,x), from x + 30 - 6 = 0 => x = -24
f(1,1) = max(1,x), from x + (-10) - 5 = 0 => x = 15 or x + (-10) - 1 = 0 => x = 11
f(0,2) = max(1,x), from x + 3 - 5 = 0 => x = 2
f(2,0) = max(1,x), from x + 10 - 1 = 0 => x = -9
f(1,0) = max(1,x), from x + (-5) - 1 = 0 => x = 6  
f(0,1) = max(1,x), from x + (-3) - 2 = 0 => x = 5
f(0,0) = max(1,x), from x + (-2) - 5 = 0 => x = 7

f(i,j) = max(1,  min(f(i+1,j), f(i,j+1)) - dungeon[i][j] )

*/

/* In this kind of problems, think in "back from the future", like "What if you had the next answer, could you tell the current answer?"  */
class BetterRecursionSolution { // TLE 
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.size() == 0)
            return 0;
        
        return rec(dungeon,0,0);
    }
    
    bool isValid (vector<vector<int>>& dungeon, int i, int j){
        return i>=0 && j>=0 && i<dungeon.size() && j<dungeon[0].size();
    }
    
    int rec(vector<vector<int>>& dungeon, int i, int j){
        if (i == dungeon.size()-1 && j == dungeon[0].size()-1)
            return dungeon[i][j] > 0 ? 1 : 1-dungeon[i][j];
        
        if (!isValid(dungeon,i,j))
            return INT_MAX;
        
        return max(1, min(rec(dungeon,i+1,j), rec(dungeon,i,j+1)) - dungeon[i][j]);
    }
};
// Time: O(2^(n+m))
// Space: O(n+m)

class Solution {
private:
    vector<vector<int>> memo;
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.size() == 0)
            return 0;
        
        int m = dungeon.size();
        int n = dungeon[0].size();
        memo.resize(m,vector<int>(n,-1));
        
        return rec(dungeon,0,0);
    }
    
    bool isValid (vector<vector<int>>& dungeon, int i, int j){
        return i>=0 && j>=0 && i<dungeon.size() && j<dungeon[0].size();
    }
    
    int rec(vector<vector<int>>& dungeon, int i, int j){
        if (!isValid(dungeon,i,j))
            return INT_MAX;
        
        if (i == dungeon.size()-1 && j == dungeon[0].size()-1)
            return memo[i][j] = dungeon[i][j] > 0 ? 1 : 1-dungeon[i][j];
        
        if (memo[i][j] != -1)
            return memo[i][j];
        
        return memo[i][j] = max(1, min(rec(dungeon,i+1,j), rec(dungeon,i,j+1)) - dungeon[i][j]);
    }
};
// Time: O(n*m)
// Space: O(n*m)

int main(){
    vector<vector<int>> dungeon{
        {-2,-3,3},
        {-5,-10,1},
        {10,30,-5}
    };

    Solution sol;
    cout << sol.dfs(dungeon) << endl;

    return 0;
}

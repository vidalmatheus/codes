#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class RecursiveSolution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        return rec(costs,0,0,0);
    }
    
    int rec(vector<vector<int>>& costs, int pos, int A, int B){
        if (pos==costs.size() || A>costs.size()/2 || B>costs.size()/2)
            return 0;
        
        if (A == costs.size()/2)
            return costs[pos][1]+rec(costs,pos+1,A,B+1);
        else if (B == costs.size()/2)
            return costs[pos][0]+rec(costs,pos+1,A+1,B);
        
        return min(costs[pos][0]+rec(costs,pos+1,A+1,B),costs[pos][1]+rec(costs,pos+1,A,B+1));
    }
};
// Time: O(2^(n/2))
// Space: O(n/2)

class Solution { // memo
private:
    map<vector<int>,int> memo;
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        return rec(costs,0,0,0);
    }
    
    int rec(vector<vector<int>>& costs, int pos, int A, int B){
        if (pos==costs.size() || A>costs.size()/2 || B>costs.size()/2)
            return 0;
        
        if (memo.find({pos,A,B}) != memo.end())
            return memo[{pos,A,B}];
        
        if (A == costs.size()/2)
            return memo[{pos,A,B}] = costs[pos][1]+rec(costs,pos+1,A,B+1);
        else if (B == costs.size()/2)
            return memo[{pos,A,B}] = costs[pos][0]+rec(costs,pos+1,A+1,B);
        
        return memo[{pos,A,B}] = min(costs[pos][0]+rec(costs,pos+1,A+1,B),costs[pos][1]+rec(costs,pos+1,A,B+1));
    }
};
// Time: O(n^3)
// Space: O(n^3)

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        priority_queue<pair<int,int>> h;
    
        for (int i=0;i<costs.size();i++)
            h.push({costs[i][0] - costs[i][1],i});
        
        int N = costs.size()/2;
        int minCost = 0;
        for (int i=0;i<N;i++){
            minCost += costs[h.top().second][1];
            h.pop();
        }
        
        for (int i=0;i<N;i++){
            minCost += costs[h.top().second][0];
            h.pop();
        }
        
        return minCost;
    }
};
// Time: O(n*log(n))
// Space: O(n)

struct Comparator {
    bool operator() (vector<int>& e1, vector<int>& e2){
        return e1[0] - e1[1] < e2[0] - e2[1];
    }
};
    
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        struct Comparator comp;
        sort (costs.begin(),costs.end(),comp);
        
        int minCost = 0;
        int N = costs.size()/2;
        for (int i=0;i<N;i++)
            minCost += costs[i][0];
        
        for (int i=N;i<2*N;i++)
            minCost += costs[i][1];
        
        
        return minCost;
    }      
};
// Time: O(n*log(n))
// Space: O(n)

int main(){
    vector<vector<int>> costs{
      {10,20},
      {30,200},
      {400,50},
      {30,20}  
    };

    Solution sol;
    cout << sol.twoCitySchedCost(costs) << endl;
    
    return 0;
}

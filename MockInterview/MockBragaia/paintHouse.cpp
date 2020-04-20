/*
21:39 -> 22:19

you should paint n houses using k colors but two subsequent houses cant have same color
when you paint house i using color j => it has a cost
using the costs I give you, what is minimum total cost to paint everyting?


Input: 
[
  [1,5,3],
  [2,9,4]
]
2 houses (two rows)
3 colors (three columns)

Output: 5
Explanation: Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5; 
             Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5. 

lets suppose you have only three colors (k=3)
Input: n*3



[
  [1,5,3],
  [2,9,4],
  [1,8,7],
  [0,5,1]
]

ans: 1+4+1+1 = 7
[
  [1    ],
  [    4],
  [1  , ],
  [    1]
]

////

ans:  9(first) + 1(middle) + 1 (last) 

[
  [1,   9,  10],
  [1, 100, 100],
  [100, 1, 100]
]


[
  [1,         ],
  [1, 100, 100],
  [     1     ]
]

rec(house i, color j): 
  if i==(size of matrix)
    return 0

  return cost_of_color(i,j) + min(rec(house i+1, color != j))

rec(0,0):
  return 1+min(rec(1,1),rec(1,2)) = 1+min(200,101) = 102
  
  rec(1,1):
    return 100+min(rec(2,0),rec(2,2)) = 100+100 = 200
    
    rec(2,0):
      return 100+0
    
    rec(2,2):
      return 100+0
  
  rec(1,2):
    return 100 + min(rec(2,0),rec(2,1))= 101
    
    rec(2,0):100
    rec(2,1): 1+0=1

rec(0,1): ...

rec(0,2): ...

global ans: min(rec(0,0), rec(0,1), rec(0,2))


// Time: O(k*(k-1)^(n-1)) --> DP: Time: O(n*k^2), Space: O(n*k)
ta ai?
tô!
travou tu

https://leetcode.com/problems/paint-house-ii/

[1,2,3,4]
minArray = [2, 1, 1, 1]
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        /*
            T: O(nk)
            M: O(k)
        */
        
        if(costs.size()==0)
            return 0;
        
        int n = (int)costs.size(), k = (int)costs[0].size();
        
        vector<int>DP = costs[0], minArrayExcludingSelf;
        
        for(int i=1;i<n;i++){
            minArrayExcludingSelf = getMinArrayExcludingSelf(DP);
            for(int j=0;j<k;j++)
                DP[j] = costs[i][j] + minArrayExcludingSelf[j];
        }
        
        int ans = DP[0];
        for(int j=0;j<k;j++)
            ans = min(ans, DP[j]);
        return ans;
    }
private:
    // O(k)
    vector<int> getMinArrayExcludingSelf(vector<int>DP){}
};

// //https://leetcode.com/problems/paint-house/

// 1a fase palantir
// https://leetcode.com/problems/minimum-time-difference/




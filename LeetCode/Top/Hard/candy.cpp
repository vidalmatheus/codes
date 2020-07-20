#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*

[1,0,2]
 2 1 2

[1,2,2]
 1 2 1
 
[1,0,2,5,1,2,0,1,7]
 2 1 2 3 1 2 1 2 3 -> 17

[1,3,2,2,1]
 1 2 1 2 1
 
[1,2,87,87,87,2,1]
 1 2  3  1  3 2 1
      i     j
->             <-

[1,3,4,5,2]
 1 2 3 1 1


[1,6,10,8,7,3,2]
 1 2  5 4 3 2 1
 
Algorithm:
1. first pass from left to right
2. second pass from right to left
    2.1 sum the values
3. return the min_candies

*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 0)
            return 0;
        
        if (ratings.size() == 1)
            return 1;
        
        vector<int> dp(ratings.size(),1);
        int min_candies = 0;
        
        // from left to right
        for (int i=0;i<dp.size();i++){
            if (i>=1 && ratings[i-1] < ratings[i])
                dp[i] = max(dp[i],dp[i-1]+1);
            if (i+1 < dp.size() && ratings[i] > ratings[i+1])
                dp[i] = max(dp[i],dp[i+1]+1);
        }

        // from right to left
        for (int i=dp.size()-1;i>=0;i--){
            if (i>=1 && ratings[i-1] < ratings[i])
                dp[i] = max(dp[i],dp[i-1]+1);
            if (i+1 < dp.size() && ratings[i] > ratings[i+1])
                dp[i] = max(dp[i],dp[i+1]+1);
            min_candies += dp[i];
        }
        
        return min_candies;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    vector<int> ratings{1,6,10,8,7,3,2};

    Solution sol;
    cout << sol.candy(ratings) << endl;

    return 0;
}

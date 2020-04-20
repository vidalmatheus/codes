#include <bits/stdc++.h>

using namespace std;

/*
Given an array of integers.

Create a function which returns the number of subarrays it has. 


[1, -2, 1995, 100, 0] : 15 sub arrays

length: 5
5+(5-1)+(5-2)+(5-3)+(5-4):15

*/

long long numOfSubArrays(vector<int>& arr){
    // edge case
    if (arr.size()==0)
        return 0;
   
    int n = arr.size();
    int numSubArrays = n*n;
    int sumFrom1toN = (n*(n-1))/2;
   
    return numSubArrays-sumFrom1toN;
}
// Time: O(1)
// Space: O(1)

/*
Given an array of integers.

Create a function which returns the number of subarrays that have even sum. 

[1, -2, 1995, 100, 0] : 

[1, -2, 1995] has even sum = 1994

[1,0,1,0,0]
 
   y
   |
   |*   *
-1*|0 *1 *2  3  4  5   : index in array
------------*--------->x


counter: -1 +1 -1 +1 = 0

[2, 2, 2, 2, 2]

counter: 0

// Brute Froce: O(n^2)

// 


[1 , 0 ,1 , 0 ,0]
[1, -2, 1995, 100, 0]

 2  ,   3          0 , 3             0, 1
[1995, 100] = [1, -2, 1995, 100] - [1, -2] 
subArray[2][3] = prefixParity[3] - prefixParity[1];


0 1 2 3 4
1
2
3
4
 

0: [1]
1: [1,-2]
2: [1, -2, 1995]
3: [1, -2, 1995, 100]
4: [1, -2, 1995, 100, 0]

                0 1 2 3 4
prefixParity = {1,1,0,0,0}
ones:2 --> (2 escolhe 2)
zeros:3 --> (3 escolhe 2)


start: 
end: 
               i
[1, -2, 1995, 100, 0]

[]
[1]
[1, -2]
[1, -2, 1995]

impar: 2
par: 1 +1

*/

long long evenSubArrays(vector<int> &arr){
    
    vector<pair<int,int>> dp(arr.size(),0);
    dp[0].first = arr[0]%2 ? 1 : 0;
    dp[0].second = arr[0]%2 ? 0 : 1;
    
    for (int i=1;i<dp.size();i++){
        dp[i].first = arr[i]%2 ? dp[i-1].first+1 : dp[i-1].first;
        dp[i].second = arr[i]%2 ? dp[i-1].second : dp[i-1].second+1;
    }
    
    return dp[dp.size()-1].second;
}


int kadane (vector<int> &nums){
    if (nums.size()==0) return 0;
    int max_so_far = nums[0]; 
    int curr_max = nums[0]; 
    for (int i = 1; i < nums.size(); i++){
            curr_max = max(nums[i], curr_max+nums[i]); 
            max_so_far = max(max_so_far, curr_max); 
    }
    return max_so_far; 
}

#include <bits/stdc++.h>

using namespace std;

/*
i   arr                         swap (indices)
0   [7, 1, 3, 2, 4, 5, 6]   swap (0,3)
1   [2, 1, 3, 7, 4, 5, 6]   swap (0,1)
2   [1, 2, 3, 7, 4, 5, 6]   swap (3,4)
3   [1, 2, 3, 4, 7, 5, 6]   swap (4,5)
4   [1, 2, 3, 4, 5, 7, 6]   swap (5,6)
5   [1, 2, 3, 4, 5, 6, 7]

     0  1  2  3  4  5  6
	[7, 1, 3, 2, 4, 5, 6]  swaps = 0
     
    [2, 1, 3]  [4]  [5]  [6] [7]          
            
	[1, 2, 3, 4, 5, 6, 7]
     0  1  2  3  4  5  6

	[2, 4, 5, 1, 3]
     0  1  2  3  4  
        
    [4, 2, 5, 1, 3]
        
    [1, 2, 5, 4, 3] 
    
    [1, 2, 3, 4, 5] 
  
   
    [1, 2, 3, 4, 5]
     0  1  2  3  4
    
    
    [1, 2, 3, 4, 5]
     0  1  2  3  4    
        
  
  
  
    [1, 2, 3, 4, 5]
     0  1  2  3  4
    
	[2]: 1
    
    
    counter : 0
    
    ans = 3
    
ans = 5

---------------------------------------------------

1. sort the array -> finalState  O(nlog n)
2. while counter != arr.size():  O(n^2)
2.1. look for incorrect numbers (positions): O(n)
	2.1.1 swap them
    
Time: O(n^2)
Space: O(n)

*/

int minSwaps(int arr[], int n) 
{ 
    // Create an array of pairs where first 
    // element is array element and second element 
    // is position of first element 
    pair<int, int> arrPos[n]; 
    for (int i = 0; i < n; i++) 
    { 
        arrPos[i].first = arr[i]; 
        arrPos[i].second = i; 
    } 
  
    // Sort the array by array element values to 
    // get right position of every element as second 
    // element of pair. 
    sort(arrPos, arrPos + n); 
  
    // To keep track of visited elements. Initialize 
    // all elements as not visited or false. 
    vector<bool> vis(n, false); 
  
    // Initialize result 
    int ans = 0; 
  
    // Traverse array elements 
    for (int i = 0; i < n; i++) 
    { 
        // already swapped and corrected or 
        // already present at correct pos 
        if (vis[i] || arrPos[i].second == i) 
            continue; 
  
        // find out the number of  node in 
        // this cycle and add in ans 
        int cycle_size = 0; 
        int j = i; 
        while (!vis[j]) 
        { 
            vis[j] = 1; 
  
            // move to next node 
            j = arrPos[j].second; 
            cycle_size++; 
        } 
  
        // Update answer by adding current cycle.  
        if (cycle_size > 0) 
        { 
            ans += (cycle_size - 1); 
        } 
    } 
  
    // Return result 
    return ans; 
} 


class Solution {
public:
    int minimumSwap(vector<int>& s1) {
        vector<int> s2 = s1;
        sort(s2.begin(),s2.end());

        unordered_map<int,int> s2Index;
        for (int i=0;i<s2.size();++i)
            s2Index[s2[i]] = i;
        
        int swaps = 0;
        vector<bool> visited(s1.size(),false);
        for (int i=0;i<s1.size();){
            if (s1[i] == s2[i]) ++i;
            else {
                int j = s2Index[s1[i]];
                swap(s1[i],s1[j]);
                swaps++;
            }
        }
        
        return swaps;
    }
};
// Time: O(nlog n + m)
// Space: O(m)

int main(){
    // vector<int> nums{7, 1, 3, 2, 4, 5, 6};

    vector<int> nums{2, 4, 5, 1, 3};

    Solution sol;
    std::cout << sol.minimumSwap(nums) << endl;

    return 0;
}

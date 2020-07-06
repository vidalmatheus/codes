#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class FirstSolution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size()==0)
            return 0;
        
        int n = nums.size();
        vector<int> prefixSum(n+1,0);
        for (int i=1;i<prefixSum.size();i++)
            prefixSum[i] = nums[i-1] + prefixSum[i-1];
        
        unordered_map<int,int> freq;
        int counter = 0;
        for (int e:prefixSum){
            if (freq.find(e-k)!=freq.end()) // found
                counter += freq[e-k];
            if (freq.find(e)!=freq.end()) // found
                freq[e]++;
            else freq[e]=1;
        }
    
        return counter;        
    }
};
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size()==0)
            return 0;
        
        int n = nums.size();
        unordered_map<int,int> freq;
        int counter = 0;
        freq[0] = 1;
        int prefixSumSoFar = 0;
        for (int e:nums){
            prefixSumSoFar += e;
            if (freq.find(prefixSumSoFar-k)!=freq.end()) // found
                counter += freq[prefixSumSoFar-k];
            if (freq.find(prefixSumSoFar)!=freq.end()) // found
                freq[prefixSumSoFar]++;
            else freq[prefixSumSoFar]=1;
        }
    
        return counter;        
    }
};
// Time: O(n)
// Space: O(n)

/*
k = 2
[1, 1, 1]
       i 

prefixSum_i: 2
prefixSum_j: 3-2=1
counter: 2
[0]: 1
[1]: 1
[2]: 

*/

class ReviewSolution { // reviewing
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return 0;
        
        unordered_map<int,int> freq; // prefixSum -> 'how many?'
        freq[0] = 1; // to assure that we'll cover the zero prefix sum 
        int prefixSum_i = 0;
        int counter = 0; // to keep in track how many solutions I have so far
        for (int num:nums){
            prefixSum_i += num;
            
            // prefixSum[i] - prefixSum[j] = k
            int prefixSum_j = prefixSum_i - k;
            if (freq.find(prefixSum_j) != freq.end())
                counter += freq[prefixSum_j];
            
            freq[prefixSum_i]++; // adding the current prefix sum
        }
        
        return counter;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    vector<int> nums = {1,1,1};
    int k = 2;


    Solution sol;
    cout << sol.subarraySum(nums,k) << endl;

    return 0;
}

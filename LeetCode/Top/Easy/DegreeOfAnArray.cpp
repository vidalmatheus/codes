#include <bits/stdc++.h>

using namespace std;


static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
 0 1 2 3 4
[1,2,2,3,1]
         i
 
[1]:<0,4,2> --> 5
[2]:<1,2,2> --> 2
[3]:<3,3,1> --> 1

degree: 2

*/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if (nums.size()==0)
            return 0;
        
        unordered_map<int,vector<int>> hash;
        int degreeNums = INT_MIN;
        for (int i=0;i<nums.size();i++){
            if (hash.find(nums[i])!=hash.end()){ // found
                hash[nums[i]][1] = i;
                hash[nums[i]][2]++;
            }    
            else { // haven't found
                hash[nums[i]] = {i,i,1};
            }
            
            degreeNums = max(degreeNums,hash[nums[i]][2]);
        }
        
        
        int minLen = INT_MAX;
        for (auto elem:hash)
            if (elem.second[2]==degreeNums)
                minLen = min(minLen,elem.second[1]-elem.second[0]+1);
        
        return minLen;
    }
};
// Time: O(n)
// Space: O(n)

class OtherSolution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if (nums.size()==0)
            return 0;
        
        unordered_map<int,vector<int>> hash;
        int degreeNums = INT_MIN;
        int minLen = INT_MAX;
        for (int i=0;i<nums.size();i++){
            if (hash.find(nums[i])!=hash.end()){ // found
                hash[nums[i]][1] = i;
                hash[nums[i]][2]++;
            }    
            else { // haven't found
                hash[nums[i]] = {i,i,1};
            }
            
            int begin = hash[nums[i]][0];
            int end = hash[nums[i]][1];
            int degreeSub = hash[nums[i]][2];
            if (degreeSub > degreeNums){
                degreeNums = degreeSub;
                minLen = end - begin + 1;
            }
            else if (degreeSub == degreeNums)
                minLen = min(minLen,end-begin+1);
        }
        
        return minLen;
    }
};
// Time: O(n)
// Space: O(n)


int main(){
    vector<int> nums = {1,2,2,3,1};

    Solution sol;
    cout << sol.findShortestSubArray(nums) << endl;

    return 0;
}

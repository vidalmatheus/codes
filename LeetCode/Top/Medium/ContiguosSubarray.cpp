#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class BFSolution {
public:
    int findMaxLength(vector<int>& nums) {
        if (nums.size()==0)
            return 0;
        
        int maxLen = 0;
        for (int i=0;i<nums.size();i++){
            int zeroes = 0;
            int ones = 0;
            for (int j=i;j<nums.size();j++){
                zeroes+=nums[j] ? 0 : 1;
                ones+=nums[j] ? 1 : 0;
                if (zeroes==ones)
                    maxLen = max(maxLen,zeroes+ones);
            }

        }
        
        return maxLen;
    }
};
// Time: O(n^2)
// Space: O(1)

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if (nums.size()==0)
            return 0;
        
        int maxSoFar = 0;
        
        unordered_map<int,int> m(nums.size()/2);
        m[0]=-1;
        int counter = 0;
        for (int i=0;i<nums.size();i++){
            counter+= nums[i] ? 1 : -1;
            
            if (m.find(counter)!=m.end()) // found
                maxSoFar = max(maxSoFar,i-m[counter]);
            else m[counter]=i;
        }
                
        return maxSoFar;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    vector<int> nums = {0,0,1,0,0,0,1,1};

    Solution sol;
    cout << sol.findMaxLength(nums) << endl;

    return 0;
}

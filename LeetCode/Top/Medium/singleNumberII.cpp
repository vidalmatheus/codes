#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class LinearSpaceSolution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<long int, unsigned int> m;
        int ans = nums[0];
        for (int i=0;i<nums.size();i++){
            if (m.find(nums[i])!=m.end()){ // not found
                m[nums[i]]++;
            }
            else m[nums[i]]=1;
        }
        
        for (unordered_map<long int, unsigned int>::iterator it=m.begin();it!=m.end();++it){
            if (it->second==1)
                return it->first;
        }
        
        return -1;
    }
};
// Time: O(n)
// Space: O(n)

/*
[2,2,3,2]

10
10
11
10
--
41 = 11 = 3
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 0;
    
        for (int i=0;i<32;i++){
            int counter = 0;
            for (int num:nums)
                counter+=((num&(1<<i))!=0);
            
            if (counter%3!=0)
                n = n|(1<<i);
        }
            
        return n;    
    }
};
// Time: O(n)
// Space: O(1)



int main(){
    vector<int> nums = {2,2,3,2};

    Solution sol;
    cout << sol.singleNumber(nums) << endl;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class HashMapSolution { // HashMap
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size()==0)
            return -1;
        
        int n = nums.size();
        
        unordered_map<int,int> m;
        int max = 0;
        for (int e:nums){
            if (m.find(e)==m.end()) // not found
                m[e]=1;
            else m[e]++;
            
            if (m[e]>n/2){
                return e;
            }
        }
        
        return -1;
    }
};
// Time: O(n)
// Space: O(n)

class Solution { // Boyer-Moore Voting Algorithm
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size()==0)
            return -1;
        
        int n = nums.size();
        int candidate = nums[0];
        int count = 0;
        for (int e:nums){
            if (count==0){
                candidate = e;
                count = 1;
            }
            else count+= (e==candidate) ? 1 : -1;
        }
        
        return candidate;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    vector<int> nums = {3,2,3};

    Solution sol;
    cout << sol.majorityElement(nums) << endl;

    return 0;
}
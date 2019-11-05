#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/* class Solution { // hash table solution
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> hash; // it guarantees O(1) for accessing an element
        int ans;
        for (auto i:nums){
            hash.insert(i);
        }
        int n = nums.size();
        for (int i=0;i<=n;i++){
            if (hash.find(i)==hash.end())
                ans = i;
        }
        return ans;
    }
};

/* class Solution { // sum solution
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int n = nums.size();
        return n*(n+1)/2-sum;
}; */ 

class Solution { // XOR solution
public:
    int missingNumber(vector<int>& nums) {
        int xor_all=0;
        int n = nums.size();
        for (int i=1;i<=n;i++){
            xor_all^=i;
        }
        int xor_nums=nums[0];
        for (int i=1;i<n;i++){
            xor_nums^=nums[i];
        }
        return xor_all^xor_nums;
    }
};

int main(){
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    Solution sol;
    cout << sol.missingNumber(nums) << endl;
    return 0;
}
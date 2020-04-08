#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> m(nums.size());
        for (int i=0;i<nums.size();i++){
            if (m.find(nums[i])==m.end()) // not found
                m[nums[i]]=1;
            else m[nums[i]]++;
        }
        
        vector<int> ans;
        for (unordered_map<int,int>::iterator it=m.begin();it!=m.end();++it){
            if (it->second==1)
                ans.push_back(it->first);
        }
        
        return ans;
    }
};
// Time: O(n)
// Space: O(n)

class Solution { // Linear Space, using bit manipulation
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorSum = 0;
        
        for(int i=0;i<nums.size();i++){
            xorSum^=nums[i];
        }
        
        int bit = 1;
        while ((bit&xorSum)==0)
            bit<<=1;
        
        int x=0;
        int y=0;
        for (int i=0;i<nums.size();i++){
            if ((nums[i]&bit)!=0)
                x^=nums[i];
            else y^=nums[i];
        }
        
        return {x,y};
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    vector<int> nums = {1,2,1,3,2,5};

    Solution sol;
    vector<int> ans = sol.singleNumber(nums);

    cout << "[ " << ans[0] << ", " << ans[1] << " ]" << endl;

    return 0;
}

/* Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4 */

#include <bits/stdc++.h>

using namespace std;

static int speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/* class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> umap;
        for (int i=0;i<nums.size();i++){
            unordered_map<int,int>:: iterator elem = umap.find(nums[i]); // or auto elem 
            if(elem!=umap.end()) // if already exists
                continue;
            else    umap.insert(make_pair(nums[i],1));
        }
        for(auto a:umap){
            if(a.second==1)
                return a.first;
        }
        return -1;
    }
};
// TIME: O(n)
// SPACE: O(n) */

/* class Solution {
public:
    int singleNumber(vector<int>& nums) {
        multiset<int> mset; // binary search trees
        for(int i=0;i<nums.size();i++){
            if (mset.count(nums[i])>0){ // if already exists, then erase it
                mset.erase(nums[i]);
            }
            else mset.insert(nums[i]);
        }
        return *mset.begin();
    }
};
// TIME: O(n)
// SPACE: O(1) */

// Solution foda
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=nums[0];
        for (int i=1;i<nums.size();i++)
            ans ^=nums[i]; //XOR
        return ans;
    }
};
// TIME: O(n)
// SPACE: O(1)

int main(){
    vector<int> nums = {2,2,1};
    Solution sol;
    cout << sol.singleNumber(nums) << endl;
/* 
    multiset<int> mset;
    mset.insert(1);
    mset.insert(2);
    mset.insert(2);
    for(auto a: mset)
        cout << a << " ";
    cout << endl;
    mset.erase(1);
    for(auto a: mset)
        cout << a << " ";
    cout << endl;

    cout << mset.count(2) << endl; */

    return 0;
}

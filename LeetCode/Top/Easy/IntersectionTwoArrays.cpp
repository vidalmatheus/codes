/* Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
 */
#include <bits/stdc++.h>

using namespace std;

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/* class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(max(nums1,nums2));
        if (nums1.size()==0 || nums2.size()==0) return {};
        sort(nums1.begin(),nums1.end());    // O(n1logn1)
        sort(nums2.begin(),nums2.end());    // O(n2logn2)
        auto it = set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),ans.begin()); // O(n1+n2)
        ans.resize(it-ans.begin()); // O(1)
        return ans;
    }
};
// TIME: O(n1logn1 + n2logn2 + n1 + n2)
// SPACE: O(min(n1,n2)) */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        if (nums1.size()==0 || nums2.size()==0) return {};
        sort(nums1.begin(), nums1.end());   // O(n1logn1)
        sort(nums2.begin(), nums2.end());   // O(n2logn2)
        
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) { // O(max(n1,n2))
            if (nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                i++;j++;
            }
            else if(nums1[i] < nums2[j])
                i++;
            else j++;
        }
        return ans;
    }
};

int main(){
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> ans;
    Solution sol;
    ans = sol.intersect(nums1,nums2);
    for(auto a:ans)
        cout << a << " ";

    return 0;
}
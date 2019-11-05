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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp(nums1.size());
        int i,j;
        i = j = 0;
        int index = 0;
        while (i<m || j<n){
            if (i<m && j<n){
                tmp[index++]=min(nums1[i],nums2[j]);
                if (nums1[i]<=nums2[j])
                    i++;
                else j++;
            }
            else if (i<m && j>=n)
                tmp[index++]=nums1[i++];
            else tmp [index++]=nums2[j++];
        }
        nums1 = tmp;
    }
};
// TIME: O(m+n)
// SPACE: O(m+n) */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i,j;
        i = m-1;
        j = n-1;
        int index = m+n-1;
        while (i>=0 || j>=0){
            if (i>=0 && j>=0){
                nums1[index--]=max(nums1[i],nums2[j]);
                if (nums1[i]>=nums2[j])
                    i--;
                else j--;
            }
            else if (i>=0 && j<0)
                nums1[index--]=nums1[i--];
            else nums1 [index--]=nums2[j--];
        }


    }
};
// TIME: O(m+n)
// SPACE: O(1)


int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    Solution sol;
    sol.merge(nums1,3,nums2,3);
    for (int e:nums1)
        cout << e << " ";
    cout << "\n";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
[[1,12],[2,9],[3,10],[13,14],[15,16],[16,17]]

idea: 
1. sort intervals -> nlog n
2. for each interval I can do a binary search for a element that it is greater than or equal to the end point
    -> nlog n

Time: O(n logn)

*/
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return {};
    
        if (intervals.size() == 1)
            return {-1};
        
        for (int i=0;i<intervals.size();i++)
            intervals[i].push_back(i);
        
        sort(intervals.begin(),intervals.end());
        vector<int> ans(intervals.size(),0);
        for (int i=0;i<intervals.size();i++){
            int leftIndex = intervals[i][2];
            int index = binarySearch(intervals, intervals[i][1]);
            int rightIndex = index != -1 ? intervals[index][2] : -1;
            ans[leftIndex] = rightIndex;
        }
        
        return ans;
    }
    
    int binarySearch(vector<vector<int>>& intervals, int val){
        int left = 0;
        int right = intervals.size()-1;
        while (left < right){
            int mid = left + (right-left)/2;
            if (intervals[mid][0] >= val)
                right = mid;
            else left = mid+1;
        }
        
        return intervals[left][0] >= val ? left : -1;
    }
};
// Time: O(nlog n)
// Space: O(n)

int main(){
    Solution sol;
    vector<vector<int>> intervals{{3,4}, {2,3}, {1,2}};

    vector<int> ans{-1,0,1};
    assert(sol.findRightInterval(intervals) == ans);

    cout << "Passed!" << endl;
    return 0;
}

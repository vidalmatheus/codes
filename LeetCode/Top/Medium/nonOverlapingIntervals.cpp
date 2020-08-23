#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*

[[1,2],[2,3],[3,4],[1,3]]

[1,2] [1,3] [2,3] [3,4]

[1,2] [2,3] [3,4] -> 4-3 = 1



[[1,2],[1,2],[1,2]]

[1,2] [1,2]

[1,2] -> 3-1 = 2


[[1,2],[2,3]] -> 2-2 = 0


[[0,2],[1,3],[2,4],[3,5],[4,6]]

[1,2],[2,4],[3,5],[4,6]

[1,2][3,4][4,6]

*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return 0;
        
        sort(intervals.begin(),intervals.end());
        stack<vector<int>> s;
        s.push(intervals[0]);
        
        int n = intervals.size();
        int counter = 0;
        for (int i=1;i<n;i++){
            if (overlaps(intervals[i],s.top())){
                counter++;
                vector<int> intersection = getIntersection(intervals[i],s.top());
                s.pop();
                s.push(intersection);
            }
            else s.push(intervals[i]);
        }
        
        return counter;
    }

    bool overlaps(vector<int>& A, vector<int>& B){
        if (A[1] <= B[0] || B[1] <= A[0])
            return false;
        return true;
    }
    
    vector<int> getIntersection(vector<int>& A, vector<int>& B){
        return {max(A[0],B[0]), min(A[1],B[1])};
    }
};
// Time: O(nlog n)
// Space: O(n)

int main(){
    Solution sol;

    vector<vector<int>> intervals{{1,2},{2,3},{3,4},{1,3}};
    assert(sol.eraseOverlapIntervals(intervals) == 1);

    intervals = {{1,2},{1,2},{1,2}};
    assert(sol.eraseOverlapIntervals(intervals) == 2);

    intervals = {{1,2},{2,3}};
    assert(sol.eraseOverlapIntervals(intervals) == 0);

    cout << "Passed!\n";
    return 0;
}

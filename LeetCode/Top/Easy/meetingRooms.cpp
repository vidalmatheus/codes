#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (intervals.size() == 0)
            return true;
        
        sort(intervals.begin(), intervals.end());
        
        int lastStart = intervals[0][0];
        int lastEnd = intervals[0][1];
        for (int i=1;i<n;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            if (lastStart <= start && start < lastEnd)
                return false;
    
            lastStart = start;
            lastEnd = end;    
        }
        
        return true;
    }
};
// Time: O(n* log n)
// Space: O(log n)

int main(){
    Solution sol;
    vector<vector<int>> intervals1{{8,11},{17,20},{17,20}};
    assert(sol.canAttendMeetings(intervals1) == false);

    vector<vector<int>> intervals2{{0,30},{5,10},{15,20}};
    assert(sol.canAttendMeetings(intervals2) == false);

    vector<vector<int>> intervals3{{7,10}, {2,4}};
    assert(sol.canAttendMeetings(intervals3) == true);
    cout << "Passed!" << endl;
    return 0;
}
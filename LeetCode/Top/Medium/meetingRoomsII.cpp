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
private:
    const int START = 1;
    const int END = 0;
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return 0;

        vector<pair<int,int>> all;
        all.reserve(intervals.size());
        for (auto & interval : intervals){
            all.push_back({interval[0], START});
            all.push_back({interval[1], END});
        }

        sort(all.begin(), all.end());

        int currHeight = 0;
        int maxHeight = 0;
        for (auto & elem : all){
            if (elem.second == START){
                currHeight++;
                maxHeight = max(maxHeight, currHeight);
            }
            else currHeight--;
        }

        return maxHeight;
    }
};
// Time: O(n* log n)
// Space: O(n)

int main(){
    Solution sol;
    vector<vector<int>> intervals1{{7,10},{2,4},{7,10},{7,10},{2,4},{0,30},{5,10},{15,20},{15,17}};
    assert(sol.minMeetingRooms(intervals1) == 5);

    vector<vector<int>> intervals2{{6,15},{13,20},{6,17}};
    assert(sol.minMeetingRooms(intervals2) == 3);
    cout << "Passed!" << endl;
    return 0;
}
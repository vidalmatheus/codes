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
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        int n = slots1.size();
        int m = slots2.size();
        if (n == 0 || m == 0)
            return {};
        
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        
        int i = 0;
        int j = 0;
        while (i < n && j < m){
            int start1 = slots1[i][0];
            int end1 = slots1[i][1];
            
            int start2 = slots2[j][0];
            int end2 = slots2[j][1];

            int s = max(start1, start2);
            int e = min(end1, end2);
            if (e - s >= duration)
                return {s,s+duration};
            
            if (end1 > end2)
                j++;
            else i++;
        }
        
        return {};
    }
};
// Time: O(n* log n)
// Space: O(log n)7

int main(){
    Solution sol;
    
    vector<vector<int>> slots1{{10,50},{60,120},{140,210}};
    vector<vector<int>> slots2{{0,15},{60,70}};
    int duration = 8;
    vector<int> ans = {60,68};
    assert(sol.minAvailableDuration(slots1, slots2, duration) == ans);

    slots1 = {{10,50},{60,120},{140,210}};
    slots2 = {{0,15},{60,70}};
    duration = 12;
    ans = {};
    assert(sol.minAvailableDuration(slots1, slots2, duration) == ans);

    slots1 = {{216397070,363167701},{98730764,158208909},{441003187,466254040},{558239978,678368334},{683942980,717766451}};
    slots2 = {{50490609,222653186},{512711631,670791418},{730229023,802410205},{812553104,891266775},{230032010,399152578}};
    duration = 456085;
    ans = {98730764,99186849};
    assert(sol.minAvailableDuration(slots1, slots2, duration) == ans);
    
    cout << "Passed!" << endl;
    return 0;
}
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
    string schedule(vector<vector<int>>& intervals){    
        vector<pair<vector<int>,int>> m;
        
        for(int i=0;i<intervals.size();i++)
            m.push_back({intervals[i],i});
        
        sort(m.begin(),m.end());

        string ans(intervals.size(),'?');
        int C = 0, J = 0;
        for (auto e:m){
            int low = e.first[0];
            int high = e.first[1];
            int index = e.second;
            if (C<=low){
                C = high;
                ans[index] = 'C';
            }
            else if (J<=low){
                J = high;
                ans[index] = 'J';
            }
            else return "IMPOSSIBLE";
        }

        return ans;
    }

    vector<vector<int>> readIntervals(int n){
        vector<vector<int>> intervals(n,vector<int>(2));

        for (int i=0;i<n;i++){
            cin >> intervals[i][0];
            cin >> intervals[i][1];
        }

        return intervals;
    }
};

int main(){
    int T,N;
    cin >> T;

    vector<string> y(T);
    Solution sol;
    for (int i=0;i<T;i++){
        cin >> N;
        vector<vector<int>> intervals = sol.readIntervals(N);
        y[i]=sol.schedule(intervals);
    }

    for (int i=1;i<=T;i++){
        cout << "Case #" << i << ": " << y[i-1];
        if (i<T)
            cout << "\n";
    }


    return 0;
}

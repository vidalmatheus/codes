#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/* 

[0, 0, 1, 1, 0, 0, 0, 0]

*/

class BruteForceSolution { // TLE -> O(8*N) = O(8*10^9) = O(10^10) --> 10^10/GHz > 1 s (TLE!) 
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if (N == 1)
            return cells;
        
        int size = cells.size();
        
        vector<int> prev = cells;
        // Day 1:
        for (int i=1;i<size-1;i++){
            if ( (prev[i-1] && prev[i+1]) || (!prev[i-1] && !prev[i+1]) )
                cells[i] = 1;
            else cells[i] = 0;
        }
        cells[0] = 0;
        cells[size-1] = 0;
        
        // Next Days;
        prev = cells;
        for (int n=1;n<N;n++){
            for (int i=1;i<size-1;i++){
                if ( (prev[i-1] && prev[i+1]) || (!prev[i-1] && !prev[i+1]) )
                    cells[i] = 1;
                else cells[i] = 0;
            }
            prev = cells;
        }
        
        return cells;
    }
};
// Time: O(8*N)
// Space: O(1), without extra space

class RecursiveSolution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_map<string,int> state2day;
        
        for (int i=0;i<N;i++){
            string curr_state(cells.begin(),cells.end());
            if (state2day.find(curr_state) != state2day.end()){
                int loop_size = i - state2day[curr_state];
                int remaining_days = (N-i) % loop_size;
                return prisonAfterNDays(cells,remaining_days);
            }
            else {
                state2day[curr_state] = i;
                int prev = cells[0];
                for (int j=1;j<7;j++){
                    int next = cells[j+1];
                    int curr = cells[j];
                    cells[j] = prev == next;
                    prev = curr;
                }
            }
            cells[0] = 0;
            cells[7] = 0;
        }
        
        return cells;
    }
};
// Time: O(log N)
// Space: O(log N)

/*

[0, 1, 0, 1, 1, 0, 0, 1] 0
[0, 1, 1, 0, 0, 0, 0, 0] 1
...
[0, 0, 1, 1, 0, 0, 0, 0] 7
[0, 0, 0, 0, 0, 1, 1, 0] 8
[0, 1, 1, 1, 0, 0, 0, 0] 9
[0, 0, 1, 0, 0, 1, 1, 0] 10
[0, 0, 1, 0, 0, 0, 0, 0] 11
[0, 0, 1, 0, 1, 1, 1, 0] 12
[0, 0, 1, 1, 0, 1, 0, 0] 13
[0, 0, 0, 0, 1, 1, 0, 0] 14 

[0, 1, 1, 0, 0, 0, 0, 0] 15 == 1 -> period

15 % 14 = 1

*/

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> prev = cells;
        
        int real_days = N % 14 == 0 ? 14 : N % 14;
        for (int i=0;i<real_days;i++){
            int prev = cells[0];
            for (int j=1;j<7;j++){
                int curr = cells[j];
                int next = cells[j+1];
                cells[j] = prev == next;
                prev = curr;
            }
            cells[0] = 0;
            cells[7] = 0;
        }
        
        return cells;
    }
};
// Time: O(1)
// Space: O(1)

int main(){
    vector<int> cells{0,1,0,1,1,0,0,1};
    int N = 7;

    Solution sol;
    vector<int> ans = sol.prisonAfterNDays(cells,N);

    for (int i:ans)
        cout << i << " ";
    cout << endl;

    return 0;
}

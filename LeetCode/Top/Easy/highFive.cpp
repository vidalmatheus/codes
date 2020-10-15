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
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        if (items.size() == 0)
            return {};
        
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> map;
        for(auto item : items){
            int id = item[0];
            int grade = item[1];
            
            if (map[id].size() < 5)
                map[id].push(grade);
            else if (grade > map[id].top()) {
                map[id].pop();
                map[id].push(grade);
            }
        }
        
        vector<vector<int>> ans;
        for (auto elem : map){
            int sum = 0;
            priority_queue<int, vector<int>, greater<int>> pq = elem.second;
            while (!pq.empty()){
                sum += pq.top();
                pq.pop();
            }
            ans.push_back({elem.first, sum/5});
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};
// Time: O(n*log(n))
// Space: O(n)

int main(){
    Solution sol;

    vector<vector<int>> nums{{1,91},{1,92},{2,93},{2,97},{1,60},{2,77},{1,65},{1,87},{1,100},{2,100},{2,76}};
    vector<vector<int>> expec = {{1,87},{2,88}};
    assert(sol.highFive(nums) == expec);
    cout << "Passed!" << endl;
    return 0;
}
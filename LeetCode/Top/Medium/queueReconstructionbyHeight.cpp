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
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if (people.size() == 0)
            return {};
        
        vector<vector<int>> ans(people.size(),vector<int>(2,-1));
        sort(people.begin(),people.end());
        
        for (int i=0;i<people.size();i++){
            int index = getPos(ans,people,i);
            ans[index] = people[i];
        }
        
        return ans;
    }
    // Time: O(n^2)
    // Space: O(n), no extra space
    
    int getPos(vector<vector<int>>& ans, vector<vector<int>>& people, int index){
        int counter = 0;
        int lastAvailable = 0;
        for (int i=0;i<ans.size();i++){
            if (ans[i][0] == -1 || ans[i][0] == people[index][0]){
                counter++;
                if (counter == people[index][1] + 1)
                    return i;
            }
        }
        
        return -1;
    }
    // Time: O(n)
    // Space: O(1)
};

int main(){
    vector<vector<int>> people{
        {7,0},
        {4,4},
        {7,1},
        {5,0},
        {6,1},
        {5,2}        
    };

    for (auto e:people)
        cout << "[" << e[0] << ", " << e[1] << "]" << " ";
    cout << endl;

    Solution sol;
    vector<vector<int>> ans = sol.reconstructQueue(people);

    for (auto e:ans)
        cout << "[" << e[0] << ", " << e[1] << "]" << " ";
    cout << endl;

    return 0;
}

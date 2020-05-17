#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
example1:
 (1) <- (0)

example2:

 (1) <-> (0)
*/

class Solution {
private:
    const int BLANK = 0;
    const int DISCOVERED = 1;
    const int VISITED = 2;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Check if threre is a cycle
        vector<int> status(numCourses,BLANK);
        
        // Build graph from a list of edges
        unordered_map<int, vector<int>> gr;
        gr.reserve(prerequisites.size());
        for (int i=0;i<prerequisites.size();i++){
            int node = prerequisites[i][1];
            int next = prerequisites[i][0];
            gr[node].push_back(next);
        }
        
        bool hasCycle = false;
        for (int i=0;i<numCourses;i++){
            if (status[i] == BLANK && dfsCycle(gr,i,status)){
                hasCycle = true;
                break;
            }
        }
        
        return !hasCycle;
    }
    
    bool dfsCycle(unordered_map<int, vector<int>>& gr, int node, vector<int>& status){
        status[node] = DISCOVERED;
        
        for (int neighbor:gr[node]){
            if (status[neighbor]==DISCOVERED)
                return true;

            if (status[neighbor]==BLANK && dfsCycle(gr,neighbor,status))
                return true;
        }
        
        status[node] = VISITED;
        return false;
    } 
};
// Time: O(n+m)
// Space: O(n)

int main(){
    int numCourses = 2;
    vector<vector<int>> prerequisites{
        {1,0},
        {0,1}
    };

    Solution sol;
    sol.canFinish(numCourses,prerequisites) ? cout << "true\n" : cout << "false\n";

    return 0;
}

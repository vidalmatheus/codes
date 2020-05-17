#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
private:
    const int BLANK = 0;
    const int DISCOVERED = 1;
    const int VISITED = 2;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> topOrder;
        topOrder.reserve(numCourses);
        
        unordered_map<int, vector<int>> gr;
        buildGraph(prerequisites,gr);
        
        if (!topSort(numCourses,gr,topOrder))
            return {};
        
        reverse(topOrder.begin(),topOrder.end());
        return topOrder;
    }
    
    void buildGraph(vector<vector<int>>& prerequisites, unordered_map<int, vector<int>>& gr){
        // Build graph from a list of edges
        gr.reserve(prerequisites.size());
        for (int i=0;i<prerequisites.size();i++){
            int node = prerequisites[i][1];
            int next = prerequisites[i][0];
            gr[node].push_back(next);
        }
    }
    
    bool topSort(int numCourses, unordered_map<int, vector<int>>& gr, vector<int>& topOrder) {
        // Check if threre is a cycle
        vector<int> status(numCourses,BLANK);
        
        bool hasCycle = false;
        for (int i=0;i<numCourses;i++){
            if (status[i] == BLANK && dfsCycle(gr,i,status,topOrder)){
                hasCycle = true;
                break;
            }
        }
        
        return !hasCycle;
    }
    
    bool dfsCycle(unordered_map<int, vector<int>>& gr, int node, vector<int>& status, vector<int>& topOrder){
        status[node] = DISCOVERED;
    
        for (int neighbor:gr[node]){
            if (status[neighbor]==DISCOVERED)
                return true;

            if (status[neighbor]==BLANK && dfsCycle(gr,neighbor,status,topOrder))
                return true;
        }
        
        topOrder.push_back(node);
        status[node] = VISITED;
        return false;
    } 
};
// Time: O(n+m)
// Space: O(n)

int main(){
    int numCourses = 4;
    vector<vector<int>> prerequisites{
        {1,0},
        {2,0},
        {3,1},
        {3,2},
    };

    Solution sol;
    vector<int> ans = sol.findOrder(numCourses,prerequisites);

    for (int i:ans)
        cout << i << " ";

    return 0;
}

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

1. build the graph from the list of edges (adjacency list -> neighbors in lexical order)
2. dfs from "JFK"
3. return the traversal

*/

class WrongSolution { // This does not cover all cases
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        if (tickets.size() == 0)
            return {};
        
        // 1. build the graph from the list of edges (adjacency list -> neighbors in lexical order)
        unordered_map<string,set<string>> graph;
        buildGraph(graph,tickets);
        
        // 2. dfs from "JFK"
        vector<string> ans;
        dfs(graph,"JFK",ans);
        
        // 3. return the traversal
        return ans;
    }
    
    void buildGraph(unordered_map<string,set<string>>& graph, vector<vector<string>>& tickets){
        for (auto edge:tickets)
            graph[edge[0]].insert(edge[1]);
    }
    
    void dfs(unordered_map<string,set<string>>& graph, string node, vector<string>& ans){
        ans.push_back(node);
        
        if (graph[node].size() > 0){
            string neighbor = *(graph[node].begin());
            graph[node].erase(neighbor);
            dfs(graph,neighbor,ans);    
        }
        else return;
    }
};


/*

A walk that crosses every bridge exactly once is called an
Eulerian path, and one that ends at the same place it began is
an Eulerian Circuit.

In fact for an Eulerian path to exist there must be exactly 0 or
2 vertices of odd degree!
For an Eulerian circuit to exist there must be no vertices of
odd degree.
It is assumed that the graph is connected.

*/

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        if (tickets.size() == 0)
            return {};
        
        // 1. build the graph from the list of edges (adjacency list -> neighbors in lexical order)
        unordered_map<string,multiset<string>> graph;
        buildGraph(graph,tickets);
        
        // 2. dfs from "JFK"
        vector<string> ans;
        dfs(graph,"JFK",ans);
        
        // 3. return the traversal
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void buildGraph(unordered_map<string,multiset<string>>& graph, vector<vector<string>>& tickets){
        for (auto edge:tickets)
            graph[edge[0]].insert(edge[1]);
    }
    
    void dfs(unordered_map<string,multiset<string>>& graph, string node, vector<string>& ans){ // "like in pos order or topological sort"
        
        while (graph[node].size() > 0){
            string neighbor = *(graph[node].begin());
            graph[node].erase(graph[node].begin());
            dfs(graph,neighbor,ans);    
        }
        
        ans.push_back(node);
    }
};
// Time: O(E* log(E/V))
// Space: O(V)

int main(){
    vector<vector<string>> tickets{
        {"JFK","KUL"},
        {"JFK","NRT"},
        {"NRT","JFK"}
    };

    Solution sol;
    vector<string> ans = sol.findItinerary(tickets);

    for (string s:ans)
        cout << s << " ";
    cout << endl;

    return 0;
}

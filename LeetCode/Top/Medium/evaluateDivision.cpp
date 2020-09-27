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
Graph representation:

   2    3
a  -> b -> c
|  <-   <-
|  1/2  1/3
|
V
d

*/

class Solution {
private:
    unordered_map<string,vector<pair<double,string>>> graph;
    unordered_set<string> visited;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        if (equations.size() == 0)
            return {};
        
        buildGraph(equations, values);
        
        // for (auto elem : graph){
        //     cout << elem.first << ": ";
        //     for (auto e : elem.second){
        //         cout << "{" << e.first << ", " << e.second << "} ";
        //     }
        //     cout << endl;
        // }
               
        vector<double> ans;
        for (auto querie : queries){
            if (graph.find(querie[0]) != graph.end()){
                double curr = 1;
                double val = -1;
                dfs(curr, val, querie[0], querie[1]);
                ans.push_back(val);
                visited.clear();
            }
            else ans.push_back(-1);
        }
        
        return ans;
    }
    
    void buildGraph(vector<vector<string>>& equations, vector<double>& values){
        int n = equations.size();
        for (int i=0;i<n;++i){
            auto eq = equations[i];
            graph[eq[0]].push_back({values[i],eq[1]});
            graph[eq[1]].push_back({1.0/values[i],eq[0]});
        }
    }
    
    void dfs(double& curr, double& val, string node, string last){
        if (visited.find(node) != visited.end())
            return;
        
        if (node == last){
            val = curr;
            return;
        }   
        
        visited.insert(node);
        
        for (auto neighbor : graph[node]){
             curr *= neighbor.first;
             dfs(curr, val, neighbor.second, last);
             curr /= neighbor.first;
        }
    }    
};
// Time: O(n*m), n is the number of equations and m is the number of  queries
// Space: O(n+m)

int main(){
    Solution sol;
    
    vector<vector<string>> equations1{
        {"a","b"},
        {"b","c"}
    };

    vector<double> values1{
        2.0,
        3.0
    };

    vector<vector<string>> queries1{
        {"a","c"},
        {"b","a"},
        {"a","e"},
        {"a","a"},
        {"x","x"}
    };

    vector<double> ans1{6.00000,0.50000,-1.00000,1.00000,-1.00000};
    assert(sol.calcEquation(equations1,values1,queries1) == ans1);


    vector<vector<string>> equations2{
        {"a","b"},
        {"b","c"},
        {"bc","cd"}
    };

    vector<double> values2{
        1.5,
        2.5,
        5.0
    };

    vector<vector<string>> queries2{
        {"a","c"},
        {"c","b"},
        {"bc","cd"},
        {"cd","bc"}
    };

    vector<double> ans2{3.75000,0.40000,5.00000,0.20000};
    assert(sol.calcEquation(equations2,values2,queries2) == ans2);


    vector<vector<string>> equations3{
        {"a","b"},
        {"b","c"},
        {"bc","cd"}
    };

    vector<double> values3{
        0.5
    };

    vector<vector<string>> queries3{
        {"a","b"},
        {"b","a"},
        {"a","c"},
        {"x","y"}
    };

    vector<double> ans3{0.50000,2.00000,-1.00000,-1.00000};
    assert(sol.calcEquation(equations3,values3,queries3) == ans3);

    cout << "Passed!" << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution { // it will return one possible solution
private:
    const int BLANK = 0;
    const int DISCOVERED = 1;
    const int VISITED = 2;
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        if (words.size() == 0)
            return "";
        
        if (words.size() == 1)
            return words[0];
        
        // build a graph from the constraints e get also the nodes
        unordered_map<char,unordered_set<char>> graph;
        unordered_set<char> nodes;
        buildGraph(graph,words,nodes);
        
        // topological sort 
        stack<char> topological_order;
        unordered_map<char,int> status;
        for (auto node:nodes)
            if (status[node] == BLANK)
                topSort(graph,node,topological_order,status); // start from the first node
        
        string alphabet = "";
        while (!topological_order.empty()){
            alphabet.push_back(topological_order.top());
            topological_order.pop();
        }
        
        return alphabet;
    }
    
    // Time: O(n*m) = O(A)
    void buildGraph(unordered_map<char,unordered_set<char>>& graph, vector<string>& words, unordered_set<char>& nodes){ 
        for (int i=0;i<words.size();i++){
            
            for (char c:words[i])
                nodes.insert(c);
            
            int j = i+1;
            if (j == words.size()) break;
            int min_length = min(words[i].size(),words[j].size());
            // adjacency words
            for (int k=0;k<min_length;k++){
                char node = words[i][k];
                char next = words[j][k];
                if (node != next){
                    graph[node].insert(next);
                    break;
                }
            }
        }
    }
    
    // Time: O(V + E) = O(n)
    void topSort(unordered_map<char,unordered_set<char>>& graph, char node, stack<char>& topological_order, unordered_map<char,int>& status){
        status[node] = DISCOVERED;
        
        for (auto neighbor:graph[node]){
            if (status[neighbor] == BLANK)
                topSort(graph,neighbor,topological_order,status);
        }
        
        status[node] = VISITED;
        topological_order.push(node);
    }
};
// Time: O(A)
// Space: O(A)

class HasCycleSolution { // check if has cycle and return the smallest alphabet (normal order)
private:
    const int BLANK = 0;
    const int DISCOVERED = 1;
    const int VISITED = 2;
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        if (words.size() == 0)
            return "";
        
        if (words.size() == 1)
            return words[0];
            
        // build a graph from the constraints e get also the nodes
        unordered_map<char,unordered_set<char>> graph;
        set<char> nodes;
        buildGraph(graph,words,nodes);
        
        // topological sort 
        stack<char> topological_order;
        unordered_map<char,int> status;
        auto it = nodes.end();
        bool hasCycle = false;
        while (it != nodes.begin()){
            --it;
            if (status[*it] == BLANK && !topSort(graph,*it,topological_order,status)){ // if it has a cycle
                hasCycle = true;
                break;
            }
        }
        
        if (hasCycle)
            return "";
        
        string alphabet = "";
        while (!topological_order.empty()){
            alphabet.push_back(topological_order.top());
            topological_order.pop();
        }
        
        return alphabet;
    }
    
    // Time: O(n*m) = O(A)
    void buildGraph(unordered_map<char,unordered_set<char>>& graph, vector<string>& words, set<char>& nodes){ 
        for (int i=0;i<words.size();i++){
            
            for (char c:words[i])
                nodes.insert(c);
            
            int j = i+1;
            if (j == words.size()) break;
            int min_length = min(words[i].size(),words[j].size());
            // adjacency words
            for (int k=0;k<min_length;k++){
                char node = words[i][k];
                char next = words[j][k];
                if (node != next){
                    graph[node].insert(next);
                    break;
                }
            }
        }
    }
    
    // Time: O(V + E) = O(n)
    bool topSort(unordered_map<char,unordered_set<char>>& graph, char node, stack<char>& topological_order, unordered_map<char,int>& status){
        status[node] = DISCOVERED;
        
        for (auto neighbor:graph[node]){
            if (status[neighbor] == DISCOVERED)
                return false;
            
            if (status[neighbor] == BLANK && !topSort(graph,neighbor,topological_order,status))
                return false;
                
        }
        
        status[node] = VISITED;
        topological_order.push(node);
        return true;
    }
};
// Time: O(A)
// Space: O(A)


int main(){
    // vector<string> words{"wrt","wrf","er","ett","rftt"};

    // vector<string> words{"zy","zx"};

    // vector<string> words{"ze","yf","xd","wd","vd","ua","tt","sz","rd", "qd","pz","op","nw","mt","ln","ko","jm","il", "ho","gk","fa","ed","dg","ct","bb","ba"};

    vector<string> words{"ab","cd","a"};

    Solution sol;
    cout << sol.alienOrder(words) << endl;

    HasCycleSolution sol2;
    cout << sol2.alienOrder(words) << endl;

    return 0;
}

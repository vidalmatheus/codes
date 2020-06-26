#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class FirstButWrongSolution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,vector<string>> map;
        
        vector<vector<string>> ans;
        ans.reserve(accounts.size()*accounts[0].size());
        for (int i=0;i<accounts.size();i++){
            if (map.find(accounts[i][0])!=map.end()){ // found
                bool found = false;
                unordered_set<int> indexes;
                for (int j=1;j<accounts[i].size();j++)
                    if (isFound(map[accounts[i][0]],accounts[i][j]))
                        found = true;
                    else indexes.insert(j);
                
                if (found)
                    for (auto j:indexes)
                        map[accounts[i][0]].push_back(accounts[i][j]);
                else {
                    sort(accounts[i].begin()+1,accounts[i].end());
                    ans.push_back(accounts[i]);
                }
            } 
                
            else map[accounts[i][0]] = accounts[i];
        }   
            
    
        for (auto it = map.begin();it!=map.end();++it){      
            sort(it->second.begin()+1,it->second.end());
            ans.push_back(it->second);
        }
                
        return ans;
    }
                
    bool isFound(vector<string>& words, string& target){
        for (int i=0;i<words.size();i++)
            if (words[i]==target)
                return true;
        
        return false;
    }
                
};
// Time: O(n*m^2)
// Space: O(n*m)

class StudySolution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        if (accounts.size()==0)
            return {};
        
        unordered_map<string,unordered_set<string>> graph;
        unordered_map<string,string> emailToName;
        
        buildGraph(graph,emailToName,accounts);
        
        unordered_set<string> visited;
        vector<vector<string>> accountdsMerged;
        for (auto elem:emailToName){
            string email = elem.first;
            if (visited.find(email)==visited.end()){
                vector<string> emails;
                dfs(graph,visited,email,emails); // Time: O(n) & Space: O(n)
                sort(emails.begin(),emails.end()); // Time: O(nlog n) & Space: O(log n)
                emails.insert(emails.begin(),emailToName[email]); // Time: O(n) & Space: O(n)
                accountdsMerged.push_back(emails);
            }
        }
        
        return accountdsMerged;
    }
    
    void buildGraph(unordered_map<string,unordered_set<string>>& graph, unordered_map<string,string>& emailToName, vector<vector<string>>& accounts){
        for (vector<string> account:accounts){
            string name = account[0];
            
            for (int i=1;i<account.size();i++){
                string email = account[i];
                emailToName[email] = name;
                
                if (i==1) continue;
                string prev = account[i-1];
                graph[prev].insert(email);
                graph[email].insert(prev);
            }
        }
    }
    
    void dfs(unordered_map<string,unordered_set<string>>& graph, unordered_set<string>& visited, string& node, vector<string>& group){
        visited.insert(node);
        group.push_back(node);
        
        for (string neighbour:graph[node])
            if (visited.find(neighbour)==visited.end())
                dfs(graph,visited,neighbour,group);
    }
};
// Time: O(n log n)
// Space: O(n)

/*

1. build a graph, using the given list of edges (accounts)
2. map email->name
3. do dfs in each component
    3.1 store the traversal
    3.2 sort them
    3.3 put the name at beginning
    3.4 add to the global answer

*/

class Solution { // Best Explained Solution
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        if (accounts.size() == 0)
            return {};
        
        // 1. build a graph
        // 2. map email->name
        unordered_map<string,vector<string>> graph;
        unordered_map<string,string> emailToName;
        buildGraph(graph,accounts,emailToName);
        
        // 3. do dfs in each component
        vector<vector<string>> merged;
        unordered_set<string> visited;
        for (auto elem:emailToName){
            string email_node = elem.first; 
            if (visited.find(email_node) == visited.end()){
                vector<string> emails_component;
                
                // 3.1 store the traversal
                dfs(graph,email_node,emails_component,visited);
                
                // 3.2 sort them
                sort(emails_component.begin(),emails_component.end());
                string name_node = emailToName[emails_component[0]];
                
                // 3.3 put the name at beginning
                emails_component.insert(emails_component.begin(),name_node);
                
                // 3.4 add to the global answer
                merged.push_back(emails_component);
            }
        }
        
        return merged;
    }
    
    void buildGraph(unordered_map<string,vector<string>>& graph, vector<vector<string>>& accounts, unordered_map<string,string>& emailToName){
        for (auto account:accounts){
            vector<string> emails;
            emailToName[account[1]] = account[0];
            for (int i=2;i<account.size();i++){
                graph[account[1]].push_back(account[i]);
                graph[account[i]].push_back(account[1]);
                emailToName[account[i]] = account[0];
            }
        }
    }
    
    void dfs(unordered_map<string,vector<string>>& graph, string& node, vector<string>& emails_component, unordered_set<string>& visited){
        visited.insert(node);
        emails_component.push_back(node);
        
        for (auto neighbor:graph[node])
            if (visited.find(neighbor) == visited.end())
                dfs(graph,neighbor,emails_component,visited);
    }
};
// Time: O([summatory]k log k)
// Space: O(A)

int main(){
    vector<vector<string>> accounts{
        {"John", "johnsmith@mail.com", "john00@mail.com"}, 
        {"John", "johnnybravo@mail.com"}, 
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, 
        {"Mary", "mary@mail.com"}
    };

    Solution sol;
    vector<vector<string>> ans = sol.accountsMerge(accounts);

    vector<vector<string>> output{
        {"John", "john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com"},  
        {"John", "johnnybravo@mail.com"}, 
        {"Mary", "mary@mail.com"}
    };

    sort(ans.begin(),ans.end());
    sort(output.begin(),output.end());

    ans == output ? cout << "Correct!\n" : cout << "Incorrect!\n";

    return 0;
}

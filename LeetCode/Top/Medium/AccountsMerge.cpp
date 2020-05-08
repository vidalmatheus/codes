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

class Solution {
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

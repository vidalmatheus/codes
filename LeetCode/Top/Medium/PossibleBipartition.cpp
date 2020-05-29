#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class WrongSolution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        if (N==1)
            return true;
        if (dislikes.size()==0)
            return true;
        
        
        unordered_map<int,unordered_set<int>> dislikesMap;
        for (int i=0;i<dislikes.size();i++){
            dislikesMap[dislikes[i][0]].insert(dislikes[i][1]);
            dislikesMap[dislikes[i][1]].insert(dislikes[i][0]);
        }
        
        for (auto elem:dislikesMap){
            cout << elem.first << ": ";
            for (auto e:dislikesMap[elem.first])
                cout << e << " ";
            cout << endl;
        }
        
        unordered_set<int> groupA;
        unordered_set<int> groupB;
        for (int i=1;i<=N;i++){
            if (isPossible2Insert(dislikesMap,i,groupA))
                groupA.insert(i);
            else if (isPossible2Insert(dislikesMap,i,groupB))
                groupB.insert(i);   
            else return false;
        }
        
        return true;    
    }

    bool isPossible2Insert(unordered_map<int,unordered_set<int>>& dislikesMap, int num, unordered_set<int>& group){
        if (group.size()==0) // not found
            return true;
        for (auto elem:dislikesMap[num])
            if (group.find(elem)!=group.end()) // found
                return false;
        return true;
    }    
};

class Solution {
private:
    unordered_map<int,vector<int>> gr;
    vector<int> color;
    const int BLANK = -1;
    const int RED = 0;
    const int BLUE = 1;
    
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        if (dislikes.size()==0)
            return true;
        
        color.resize(N+1,BLANK);
        
        // build graph
        buildGraph(dislikes);
        
        // try to divide the graph
        for (int i=1;i<=N;i++){
            if (color[i] == BLANK && !bfsColor(gr,i))
                return false;
        }
        
        return true;
    }
    
    void buildGraph(vector<vector<int>>& dislikes){
        for (int i=0;i<dislikes.size();i++){
            gr[dislikes[i][0]].push_back(dislikes[i][1]);
            gr[dislikes[i][1]].push_back(dislikes[i][0]);
        }
    }
    
    bool bfsColor(unordered_map<int,vector<int>>& gr, int start){
        queue<int> q;
        q.push(start);
        int currColor = RED;
        while (!q.empty()){
            int size = q.size();
            for (int i=0;i<size;i++){
                int node = q.front();
                q.pop();
                color[node] = currColor;
                
                for (int neighbor:gr[node]){
                    if (color[neighbor] == BLANK) 
                        q.push(neighbor);
                    else if (color[neighbor] == color[node])
                        return false;
                }
            }
            ++currColor%2;
        }
        
        return true;
    }
};
// Time: O(V+E)
// Space: O(V)

int main(){
    int N = 3;
    vector<vector<int>> dislikes{
        {1,2},
        {1,3},
        {2,4}
    };

    Solution sol;
    sol.possibleBipartition(N,dislikes) ? cout << "true\n" : cout << "false\n";

    return 0;
}

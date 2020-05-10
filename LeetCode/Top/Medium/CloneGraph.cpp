#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        
        unordered_map<Node*,Node*> visited;
        bfs(node,visited);
        
        return visited[node];
    }
    
    void bfs(Node* startNode, unordered_map<Node*,Node*>& visited){
        queue<Node*> q;
        q.push(startNode);
        visited[startNode] = new Node(startNode->val);
        while (!q.empty()){
            int size = q.size();
            for (int j=0;j<size;j++){
                Node* node = q.front();
                q.pop();
                for (Node* neighbor: node->neighbors){
                    if (visited.find(neighbor)==visited.end()){ // not visited
                        visited[neighbor] = new Node(neighbor->val);
                        q.push(neighbor);
                    }
                    visited[node]->neighbors.push_back(visited[neighbor]);
                }                
            }
        }
    }
};
// Time: O(|V| + |E|)
// Space: O(|V|), extra space

int main(){
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node3);
    node4->neighbors.push_back(node4);

    Solution sol;
    Node* ans = sol.cloneGraph(node1);

    return 0;
}

#include <bits/stdc++.h>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr)
            return {};
        
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()){
            int size = q.size();
            vector<int> level;
            level.reserve(size);
            for (int i=0;i<size;i++){
                Node* node = q.front();
                q.pop();
                level.push_back(node->val);
                
                for (Node* neighbor : node->children)
                    if (neighbor != nullptr)
                        q.push(neighbor);
            }
            ans.push_back(level);
        }
        
        return ans;
    }
};
// Time: O(n)
// Space: O(n)

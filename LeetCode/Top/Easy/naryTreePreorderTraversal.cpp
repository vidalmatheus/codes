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

class RecursiveSolution {
public:
    vector<int> preorder(Node* root) {
        if (root == nullptr)
            return {};
        
        vector<int> ans;
        dfs(root,ans);
        
        return ans;
    }
    
    void dfs(Node* root, vector<int>& ans){
        if (root == nullptr)
            return;
        
        ans.push_back(root->val);
        for (Node* child:root->children)
            if (child != nullptr)
                dfs(child,ans);
    }
};
// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> preorder(Node* root) {
        if (root == nullptr)
            return {};
        
        vector<int> ans;
        stack<Node*> s;
        s.push(root);
        while (!s.empty()){
            Node* node = s.top();
            s.pop();
            ans.push_back(node->val);
            
            for (int i=node->children.size()-1;i>=0;i--){
                Node* child = node->children[i];
                if (child != nullptr)
                    s.push(child);
            }
        }
        
        return ans;        
    }
};
// Time: O(n)
// Space: O(n)

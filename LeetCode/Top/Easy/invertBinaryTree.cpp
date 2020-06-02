#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class WrongSolution { // works only for totally balanced trees
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root==nullptr)
            return nullptr;
        
        map<vector<int>,TreeNode*> tag;
        tagNodes(root,0,0,tag);
        
        unordered_set<TreeNode*> visited;
        swapNodes(root,0,0,tag,visited);
        
        return root;
    }
    
    void tagNodes(TreeNode* root, int left, int right, map<vector<int>,TreeNode*>& tag){
        if (root==nullptr)
            return;
        
        tag[{left,right}] = root;
        tagNodes(root->left,left+1,right,tag);
        tagNodes(root->right,left,right+1,tag);
    }
    
    void swapNodes(TreeNode*& root, int left, int right, map<vector<int>,TreeNode*>& tag, unordered_set<TreeNode*>& visited){
        if (visited.find(root)!=visited.end())
            return;
        if (root==nullptr)
            return;
        
        vector<int> mirrored = {right,left};
        if (tag.find(mirrored)!=tag.end()){
            swap(root->val,tag[mirrored]->val);
            visited.insert(root);
            visited.insert(tag[mirrored]);
        }
        swapNodes(root->left,left+1,right,tag,visited);
        swapNodes(root->right,left,right+1,tag,visited);        
    }    
};
// Time: O(nlog n)
// Space: O(n)

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root==nullptr)
            return nullptr;
        
        dfs(root);
        
        return root;    
    }
    
    void dfs(TreeNode* root){
        if (root==nullptr)
            return;
        if (!root->left && !root->right)
            return;
        
        dfs(root->left);
        dfs(root->right);
        swap(root->left,root->right);
    }
};
// Time: O(n)
// Space: O(h)


void preorder(TreeNode* root){
    if (root==nullptr)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);

    Solution sol;
    preorder(root);
    cout << endl;

    return 0;
}
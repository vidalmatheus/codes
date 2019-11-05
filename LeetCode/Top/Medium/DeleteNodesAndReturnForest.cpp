#include <bits/stdc++.h>

using namespace std;

static auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution { // Time: O(n) - Space: O(2*n) = O(n), because n for hashset and n for DFS (recursion)
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> remaining; // to keep the ramaining nodes (forest)
        unordered_set<int> toDelete; // hashset to make O(1) the verification weather we'd keep a node or not 
        for (auto i:to_delete)
            toDelete.insert(i);
        // now remove the nodes (we're gonna do it recursively)
        removeNodes(root,toDelete,remaining); // remove the nodes from below the root
        // we need to verify weather the root should be also removed
        if (toDelete.find(root->val)==toDelete.end()) // if root not found in toDelete
            remaining.push_back(root);
        return remaining;
    }
    TreeNode* removeNodes (TreeNode* root, unordered_set<int> &toDelete, vector<TreeNode*> &remaining) {
        // first goes dowm the tree in post-order traversal (DFS)
        if (root==nullptr)
            return nullptr;
        root->left = removeNodes(root->left,toDelete,remaining);
        root->right = removeNodes(root->right,toDelete,remaining);
        // now we have to verify that we should delete the node that we're on
        if (toDelete.find(root->val)!=toDelete.end()){ // if we have to delete this node, then we have to save left and right nodes (if they exist!)
            if (root->left!=nullptr)
                remaining.push_back(root->left);
            if (root->right!=nullptr)
                remaining.push_back(root->right);
            return nullptr; // this node became null, because we have to delete it
        }
        // if we don't want to delete this current node
        return root;    
    }

};

int main(){
    /*root = [1,2,3,4,5,6,7], to_delete = [3,5]*/
    vector<int> to_delete = {3,5};
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<TreeNode*> forest = sol.delNodes(root,to_delete);

    for (int i=0;i<forest.size();i++)
        cout << forest[i]->val << " ";

    return 0;
}
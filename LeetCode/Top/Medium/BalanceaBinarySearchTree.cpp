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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        if (!root) return nullptr;
        vector<int> inorder = inOrderTraversal(root);
        TreeNode* newRoot;
        build(inorder,newRoot,0,inorder.size()-1);
        
        return newRoot;
    }
    
    void build(vector<int>& inorder, TreeNode*& root, int startInorder, int endInorder){
        if (startInorder>endInorder)
            return;
        
        int mid = startInorder + (endInorder-startInorder)/2;
        root = new TreeNode(inorder[mid]);
        
        build(inorder,root->left,startInorder,mid-1); // left subtree 
        build(inorder,root->right,mid+1,endInorder); // right subtree
    }
    
    vector<int> inOrderTraversal (TreeNode *root){
        if (root==nullptr)
            return {};
        stack<TreeNode*> s;
        TreeNode* curr = root;
        vector<int> inorder;
        while(!s.empty() || curr){
            while (curr){
                s.push(curr);
                curr=curr->left;
            }
            
            curr = s.top();
            inorder.push_back(curr->val);
            s.pop();
            curr=curr->right;
        }

        return inorder;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    root->right->right->right->right = new TreeNode(5);

    Solution sol;
    root = sol.balanceBST(root);

    return 0;
}

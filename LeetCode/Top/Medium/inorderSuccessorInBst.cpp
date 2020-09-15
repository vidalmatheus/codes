#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
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
 
class FirstSolution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == nullptr)
            return nullptr;
        
        if (!p->right){
            TreeNode* parent = getParent(root,p);
            while (parent && parent->left != p){
                p = parent;
                parent = getParent(root,parent);
            }
            return parent;
        }
        else {
            TreeNode* q = p->right;
            while (q->left)
                q = q->left;
            return q;
        }
    }
    
    TreeNode* getParent(TreeNode* root, TreeNode* p){
        if (root == nullptr)
            return nullptr;
        
        if (root->left == p || root->right == p)
            return root;
        
        TreeNode* fromLeft = getParent(root->left, p);
        if (fromLeft)
            return fromLeft;
        else return getParent(root->right, p);
    }
};
// Time: O(h)
// Space: O(h)

class BestSolution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == nullptr)
            return nullptr;
        
        TreeNode* candidate = nullptr;
        TreeNode* cur = root;
        
        while (cur){
            if (cur->val > p->val){
                candidate = cur;
                cur = cur->left;
            }
            else cur = cur->right;
        }
        
        return candidate;
    }
};
// Time: O(h)
// Space: O(1)

class SimplestSolution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == nullptr)
            return nullptr;
        
        vector<TreeNode*> inorder;
        int pos;
        dfs(root,inorder,p,pos);
        
        
        return pos+1 < inorder.size() ? inorder[pos+1] : nullptr;
    }
    
    void dfs(TreeNode* root, vector<TreeNode*>& inorder, TreeNode* p, int& pos){
        if (root == nullptr)
           return;
        
        dfs(root->left,inorder,p,pos);
        inorder.push_back(root);
        if (root == p)
            pos = (int)inorder.size()-1;
        dfs(root->right,inorder,p,pos);
    }
    
};
// Time: O(n)
// Space: O(n)
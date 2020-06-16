#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;
        
        if (root == p || root == q)
            return root;
        
        TreeNode* leftSearch = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightSearch = lowestCommonAncestor(root->right,p,q);
        
        if (leftSearch == nullptr)
            return rightSearch;
        
        if (rightSearch == nullptr)
            return leftSearch;
        
        return root;
    }
};
// Time: O(n)
// Space: O(h)

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    Solution sol;
    cout << sol.lowestCommonAncestor(root,root->left,root->right)->val << endl;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr)
            return nullptr;
        
        if (root->val == val)
            return root;
        
        if (val < root->val)
            return searchBST(root->left,val);
        else return searchBST(root->right,val);
    }
};
// Time: O(n)
// Space: O(h)

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);    

    int val = 2;

    Solution sol;
    TreeNode* ans = sol.searchBST(root,val);

    ans ? cout << ans->val << "\n" : cout << "null\n";

    return 0;
}

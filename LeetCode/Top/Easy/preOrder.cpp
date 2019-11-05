#include <bits/stdc++.h>

using namespace std;

static int speedup=[](){
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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root==nullptr) return {};
        vector<int> ans;
        stack<TreeNode*> s; // in levelOrder we use a queue
        s.push(root);
        while(!s.empty()){
            TreeNode *node = s.top();
            ans.push_back(node->val);
            s.pop();
            if (node->right!=nullptr) s.push(node->right); // in levelOrder we invert left and right, because of the queue logic
            if (node->left!=nullptr) s.push(node->left);
        }
        return ans;
    }
};

int main(){
/*     3
    /    \
    9     20
   / \   /  \
  2   1 15   7 */
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Not a Symmetric Tree
/*   1
    / \
    2  2
    \   \
    3    3 */
/*     TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(3); */

    /* TreeNode *root = new TreeNode(1); */

    vector<int> v;

    Solution sol;
    v=sol.preorderTraversal(root);

    cout << "[ ";
    for (auto i:v){
        cout << i << " ";
    }
    cout << "]" << endl;

    return 0;
}
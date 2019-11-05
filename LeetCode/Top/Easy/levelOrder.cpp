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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root==nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()){
            int size = q.size(); /*That was my difficulty! Whatch your back!*/
            vector<int> level;
            for (int i=0;i<size;i++){
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left!=nullptr) q.push(node->left);
                if (node->right!=nullptr) q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

int main(){
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

/*   3
    / \
    9  20
      /  \
    15    7 */
/*     TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7); */

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    vector<vector<int>> v;

    Solution sol;
    v=sol.levelOrder(root);

    cout << "[" << endl;
    for (auto i:v){
        cout << "[";
        for (auto j:i){
            cout << j << ",";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;

    return 0;
}
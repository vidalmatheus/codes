#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class intuitiveSolution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
            return new TreeNode(val);
        
        if (val > root->val)
            root->right = insertIntoBST(root->right, val);
        else root->left = insertIntoBST(root->left, val);
        
        return root;
    }
};
// Time: O(h)
// Space: O(h)

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
            return new TreeNode(val);
        
        TreeNode* node = root;
        while (node){
            if (val > node->val){
                if (!node->right){
                    node->right = new TreeNode(val);
                    return root;
                }
                else node = node->right;
            }
            else {
                if (!node->left){
                    node->left = new TreeNode(val);
                    return root;
                }
                else node = node->left;
            }
        }
        
        return nullptr;
    }
};
// Time: O(h)
// Space: O(1)

int main(){
    Solution sol;

    TreeNode* node4 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node7 = new TreeNode(7);

    node4->left = node2;
    node4->right = node7;
    node2->left = node1;
    node2->right = node3;

    int val = 5;
    TreeNode* ans = sol.insertIntoBST(node4,val);

    assert(ans->right->left->val == val);
    cout << "Passed!" << endl;
    return 0;
}
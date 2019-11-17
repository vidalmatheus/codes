#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root==nullptr)
            return 0; // we don't have any node, so sum is equal to zero
        // traversal the tree and whenever some value in a node is between [L,R], we add into a sum variable
        int sum = 0;
        // let's do a level (BFS) node traversal
        // for that we'll need a queue
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()){
            // check is the value is in [L,R]
            TreeNode *node = q.front();
            if (node->val>=L && node->val<=R){
                sum+=node->val;             
            }
            q.pop();
            if (node->left!=nullptr) q.push(node->left);
            if (node->right!=nullptr) q.push(node->right);   
        }
        return sum;
    }
};

class Solution2 {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root==nullptr)
            return 0; // we don't have any node, so sum is equal to zero
        // traversal the tree and whenever some value in a node is between [L,R], we add into a sum variable
        int sum = 0;
        // let's do the pre-order traversal
        preOrder(root,L,R,sum);
        return sum;
    }
    void preOrder (TreeNode* root,int L,int R, int &sum){
        if (root==nullptr)
            return ;
        if (root->val>=L && root->val<=R){
            sum+=root->val;
        }
        preOrder(root->left,L,R,sum);
        preOrder(root->right,L,R,sum);
    }
};


int main(){
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    Solution2 sol;
    cout << sol.rangeSumBST(root,7,15) << endl;

    return 0;
}
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
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        int H = height(root);
    
        levelOrderTraversal(root,sum,H,-1);
    
        return sum;
    }
    
//     void preOrder(TreeNode* root, int& sum, int H, int currLevel){
//         if (root==nullptr)
//             return;
        
//         currLevel++;
//         if (!root->left && !root->right && currLevel==H){
//             sum+=root->val;
//             return;
//         }
        
//         preOrder(root->left,sum,H,currLevel);
//         preOrder(root->right,sum,H,currLevel);
//     }
    
    // void preOrder(TreeNode* root, int& sum, int H, int currLevel){
    //     if (root==nullptr)
    //         return;
    //     stack<TreeNode*> s;
    //     s.push(root);
    //     while (!s.empty()){
    //         currLevel++;
    //         TreeNode* node = s.top();
    //         if (!node->left && !node->right && currLevel==H)
    //             sum+=node->val;
    //         s.pop();
    //         if (node->right!=nullptr)
    //             s.push(root->right);
    //         if (node->left!=nullptr)
    //             s.push(root->left);
    //     }
    // }
    
    void levelOrderTraversal (TreeNode *root, int& sum, int H, int currLevel){
        if (root==nullptr) return;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            currLevel++;
            for (int i=0;i<size;i++){
                TreeNode *node = q.front();
                if (!node->left && !node->right && currLevel==H)
                    sum+=node->val;
                q.pop();
                if (node->left!=nullptr) q.push(node->left);
                if (node->right!=nullptr) q.push(node->right);
            }   
        }
    }
    
    int height(TreeNode* root){
        if (root==nullptr)
            return -1;
        return 1+max(height(root->left),height(root->right));
    }
    
};
// Time: O(n)
// Space: O(n)

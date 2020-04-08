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
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root==nullptr)
            return true;
        
        bool ans = true;
        isBalancedRecursive(root,ans);
        
        return ans;
    }
    
    void isBalancedRecursive(TreeNode* root, bool &ans){
        if (root==nullptr)
            return;
        
        if (abs(height(root->left)-height(root->right))>1 ){
            ans = false;
            return;
        }
        else {
            isBalancedRecursive(root->left,ans);
            isBalancedRecursive(root->right,ans);
        }        
    }
    
    int height(TreeNode* root){
        if (root==nullptr)
            return -1;
        
        return (1+max(height(root->left),height(root->right)));   
    }
    
};
// Time: O(log n)
// Space: O(log n)

int main(){
    // TreeNode* root = new TreeNode(3);
    // root->left = new TreeNode(9);
    // root->right = new TreeNode(20);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(7);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(4);
    root->right = new TreeNode(2);

    Solution sol;
    sol.isBalanced(root) ? cout << "true\n" : cout << "false\n";
    cout << "Height: " << sol.height(root) << endl;

    return 0;
}
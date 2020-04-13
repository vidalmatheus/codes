#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        if (root==nullptr)
            return 0;
        
        return dfs(root,nullptr,nullptr);
    }
    
    int dfs(TreeNode* root, TreeNode* parent, TreeNode* grandParent){
        if (root==nullptr)
            return 0;
        
        int response = 0;
        if (grandParent!=nullptr && grandParent->val%2==0)
            response+=root->val;
        
        return response+dfs(root->left,root,parent)+dfs(root->right,root,parent);
    }
};
// Time: O(n)
// Space: O(n)

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
    vector<int> rightSideView(TreeNode* root) {
        if (root==nullptr)
            return {};
        
        vector<int> ans;
        preOrder(root,ans);
        
        return ans;
    }
    
    void preOrder(TreeNode* root, vector<int>& ans){
        if (root==nullptr)
            return;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for (int i=0;i<size;i++){
                TreeNode* node = q.front();
                if (i==size-1)
                    ans.push_back(node->val);
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
    }
};
// Time: O(n)
// Space: O(n)

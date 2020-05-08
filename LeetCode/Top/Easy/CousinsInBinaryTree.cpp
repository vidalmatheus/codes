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
    bool isCousins(TreeNode* root, int x, int y) {
        if (root==nullptr)
            return false;
        
        if (root->val == x || root->val == y)
            return false;
        
        pair<TreeNode*,int> parentLevelX = levelNode(root,x);
        pair<TreeNode*,int> parentLevelY = levelNode(root,y);
        
        return parentLevelX.first != parentLevelY.first && parentLevelX.second == parentLevelY.second;           
    }
    
    pair<TreeNode*,int> levelNode(TreeNode* root, int x){
        if (root == nullptr)
            return {nullptr,-1};
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()){
            int size = q.size();
            for (int i=0;i<size;i++){
                TreeNode* node = q.front();
                if (node->left && node->left->val == x || node->right && node->right->val == x)
                    return {node,level};
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            level++;
        }
        
        return {nullptr,-1};
    }  
};
// Time: O(n)
// Space: O(n)

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    int x = 5;
    int y = 4;

    Solution sol;
    sol.isCousins(root,x,y) ? cout << "true\n" : cout << "false\n";

    return 0;
}

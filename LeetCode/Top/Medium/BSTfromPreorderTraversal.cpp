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
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size()==0)
            return nullptr;
        
        TreeNode* root;
        build (preorder,root,0,preorder.size()-1);
        
        return root;
    }
    
    void build(vector<int>& preorder, TreeNode*& root, int startPreorder, int endPreorder){
        if (startPreorder>endPreorder)
            return;
        
        root = new TreeNode(preorder[startPreorder]);
        int posFirstBigger = endPreorder+1;
        for (int i=startPreorder;i<=endPreorder;i++){
            if (preorder[i]>root->val){
                posFirstBigger=i;
                break;
            }
        }
        
        build(preorder,root->left,startPreorder+1,posFirstBigger-1); // left subtree
        if (posFirstBigger<=endPreorder) 
            build(preorder,root->right,posFirstBigger,endPreorder); // right subtree
    }
};
// Time: O(n)
// Space: O(n)


void preOrder (TreeNode *root){
    if (root==nullptr)
        return ;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode *node = s.top();
        cout << node->val << " ";
        s.pop();
        if (node->right!=nullptr) s.push(node->right);
        if (node->left!=nullptr) s.push(node->left);
    }
}

int main(){
    vector<int> preorder = {8,5,1,7,10,12};
    // vector<int> preorder = {4,2};

    Solution sol;
    TreeNode* root = sol.bstFromPreorder(preorder);

    preOrder(root);

    return 0;
}
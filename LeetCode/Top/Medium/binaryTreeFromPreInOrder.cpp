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
    TreeNode *left, *right;
    TreeNode (int x) : val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size()==0 || inorder.size()==0)
            return nullptr;

        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }

    TreeNode* build(vector<int> &preorder,int startPreorder,int endPreorder,vector<int> &inorder,int startInorder,int endInorder){
        if (startInorder > endInorder)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[startPreorder]); // build root
        int posRoot = -1;

        for (int i=startInorder;i<=endInorder;i++){
            if (inorder[i]==root->val){
                posRoot = i;
                break;
            }
        }
        // posRoot-startInorder: # elements of left subtree
        root->left = build(preorder,startPreorder+1,startPreorder+posRoot-startInorder,inorder,startInorder,posRoot-1); // left subtree
        root->right = build(preorder,startPreorder+posRoot-startInorder+1,endPreorder,inorder,posRoot+1,endInorder); // right subtree
        return root;
    }
};

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

int main() {

    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    Solution sol;
    TreeNode *root = sol.buildTree(preorder,inorder);

    preOrder(root);

    return 0;
}
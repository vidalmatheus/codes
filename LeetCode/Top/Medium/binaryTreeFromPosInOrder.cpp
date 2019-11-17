#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode (int x) : val(x), left(nullptr), right(nullptr) {};
};
static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size()==0 || inorder.size()==0)
            return nullptr;
        return build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1);
    }

    TreeNode* build(vector<int> &postorder,int startPostorder,int endPostorder,vector<int> &inorder,int startInorder,int endInorder){ // O(n^2)
        if (startInorder > endInorder)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[endPostorder]); // build root
        int posRoot = -1;
        for (int i=startInorder;i<=endInorder;i++){
            if (inorder[i]==root->val){
                posRoot = i;
                break;
            }
        }
        root->left = build(postorder,startPostorder,startPostorder+(posRoot-startInorder)-1,inorder,startInorder,posRoot-1); // left subtree
        root->right = build(postorder,startPostorder+(posRoot-startInorder),endPostorder-1,inorder,posRoot+1,endInorder); // right subtree
        return root;
    }
};

class SolutionHash { // O(n)
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size()==0 || inorder.size()==0)
            return nullptr;
        unordered_map<int,int> m;
        for (int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,m);
    }

    TreeNode* build(vector<int> &postorder,int startPostorder,int endPostorder,vector<int> &inorder,int startInorder,int endInorder,unordered_map<int,int>& m){
        if (startInorder > endInorder)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[endPostorder]); // build root
        int posRoot = m[postorder[endPostorder]];
        root->left = build(postorder,startPostorder,startPostorder+(posRoot-startInorder)-1,inorder,startInorder,posRoot-1,m); // left subtree
        root->right = build(postorder,startPostorder+(posRoot-startInorder),endPostorder-1,inorder,posRoot+1,endInorder,m); // right subtree
        return root;
    }
};

void postOrder (TreeNode *root){
    if (root==nullptr)
        return ;
    stack<TreeNode*> s;
    stack<int> se;
    s.push(root);
    while(!s.empty()){
        TreeNode *node = s.top();
        se.push(node->val);
        s.pop();
        if (node->left!=nullptr) s.push(node->right);
        if (node->right!=nullptr) s.push(node->left);
    }
    while (!se.empty()){
        cout << se.top() << " ";
        se.pop();
    }
}

int main() {

    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    SolutionHash sol;
    TreeNode *root = sol.buildTree(inorder,postorder);

    postOrder(root);

    return 0;
}
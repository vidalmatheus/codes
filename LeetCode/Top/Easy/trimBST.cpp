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

class Solution_WorkableButComplex {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        preOrder(root,L,R);

        return root;
    }

    void preOrder(TreeNode* root, int L, int R){
        if (root == nullptr)
            return;

        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()){
            TreeNode* node = s.top();
            if (node->val < L || node->val > R)
                removeNode(root,node);
            s.pop();

            if (node->right!=nullptr) s.push(node->right);
            if (node->left!=nullptr) s.push(node->left);
        }
    }

    void removeNode(TreeNode* root, TreeNode* node){
        // we have three cases to consider --> to much work! Let's go use recursion!
    }
};
// Time: O(nlog n)
// Space: O(1)


class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == nullptr)
            return root;
        
        if (root->val > R) return trimBST(root->left,L,R);
        if (root->val < L) return trimBST(root->right,L,R);
        
        root->left = trimBST(root->left,L,R);
        root->right = trimBST(root->right,L,R);
        
        return root;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(2);

    int L = 1;
    int R = 2;

    Solution sol;
    root = sol.trimBST(root,L,R);

    return 0;
}
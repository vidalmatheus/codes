#include <bits/stdc++.h>

using namespace std;

//Definition for a binary tree node.
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
    int kthSmallest(TreeNode* root, int k) {
        if (root==nullptr)
            return 0;
        vector<int> elemInorder;
        inOrder(root,elemInorder);
        for (auto e:elemInorder)
            cout << e << " ";
        cout << endl;
        return elemInorder[k-1];
    }
    void inOrder (TreeNode* root, vector<int> &elemInorder){ // iterative inOrder traversal
        stack<TreeNode*> s;
        TreeNode * curr = root;
        s.push(curr);
        while (!s.empty() || curr!=nullptr){
            while (curr!=nullptr){
                s.push(curr);
                curr=curr->left;
            }
            curr = s.top();
            s.pop();
            elemInorder.push_back(curr->val);
            curr = curr->right;
        }
    }
};
#include <bits/stdc++.h>

using namespace std;

static int speedup=[](){
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root==nullptr) return {};
        vector<int> ans;
        stack<TreeNode*> s; // in levelOrder we use a queue
        TreeNode* curr = root;
        while(!s.empty() || curr!=nullptr){ // we are finished when we don't have any nodes to go down (left and right sides)
            while(curr!=nullptr){
                s.push(curr);
                curr=curr->left; // go down on leftside
            }
            // now we have a filled stack to goes through all its nodes, just popping them from the stack
            // we can use curr again
            curr = s.top();
            s.pop();
            ans.push_back(curr->val);
            // now we go rightside and after that repite all over again
            curr = curr->right;
        }
        return ans;
    }
};

int main(){
/*     3
    /    \
    9     20
   / \   /  \
  2   1 15   7 */
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    vector<int> v;

    Solution sol;
    v=sol.inorderTraversal(root);

    cout << "[ ";
    for (auto i:v){
        cout << i << " ";
    }
    cout << "]" << endl;

    return 0;
}
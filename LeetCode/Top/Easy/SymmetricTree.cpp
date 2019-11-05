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

class Solution { // Time: O(n) - Space: O(n)
    #define LEFT 0
    #define RIGHT 1
public:
    bool isSymmetric(TreeNode* root) {
        // we're gonna do a BFS (level-order traversal)
        if (root==nullptr) return true;
        string left2right;
        string right2left;
        levelOrder (root,left2right,LEFT);
        cout << left2right << endl;
        levelOrder (root,right2left,RIGHT);
        cout << right2left << endl;

        if (left2right==right2left) return true;
        else return false;
    }
    void levelOrder(TreeNode* root,string &tree,int from){
        // create a queue for a BFS traversal
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            if (node==nullptr) tree.push_back('#');
            else tree.push_back(node->val+'0');
            q.pop();         
            if (node!=nullptr){
                if (from==LEFT){
                    q.push(node->left);
                    q.push(node->right);
                }
                else {
                    q.push(node->right);
                    q.push(node->left);
                }
            }
        } 
    }
};

class RecursiveSolution { // Time: O(n) - Space: O(h)
public:
    bool isSymmetric(TreeNode* root) {
        if (root==nullptr) return true;
        return isSymmetric(root->left,root->right);
    }
private:    
    bool isSymmetric(TreeNode *left, TreeNode *right){
        if (left==nullptr || right==nullptr) /*cute way to check !a&b && a&!b*/
            return left==right;
        if (left->val!=right->val)
            return false;
        return isSymmetric(left->left,right->right) && isSymmetric(left->right,right->left);
    }

};

int main(){ 
    // Symmetric Tree
/*     TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    
    root->left->left = new TreeNode(3);
    root->right->right = new TreeNode(3);

    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4); */

    // Not a Symmetric Tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(3);

    Solution sol;
    sol.isSymmetric(root)?(cout << "yes" << endl):(cout << "false" << endl);

    RecursiveSolution rsol;
    rsol.isSymmetric(root)?(cout << "yes" << endl):(cout << "false" << endl);

    return 0;
}
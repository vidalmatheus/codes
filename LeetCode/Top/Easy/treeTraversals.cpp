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
    TreeNode(int x) : val(x),left(nullptr),right(nullptr) {}
};

class Solution {
    
public:
    /*
        1) quere.push(root)
        2) While queue not empty
            3) queue.front() & queue.pop()
            4) queue.push(leftNode) and after that queue.push(rightNode)
    */
    void levelOrderTraversal (TreeNode *root){
        if (root==nullptr) return;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front();
            cout << node->val << " ";
            q.pop();
            if (node->left!=nullptr) q.push(node->left);
            if (node->right!=nullptr) q.push(node->right);
        }
    }
    /*
        1) stack.push(root)
        2) While stack not empty
            3) stack.top() & stack.pop()
            4) stack.push(rightNode) and after that stack.push(leftNode)
    */
    void preOrderTraversal (TreeNode *root){
        if (root==nullptr) return;
        stack<TreeNode *> s;
        s.push(root);
        while(!s.empty()){
            TreeNode *node = s.top();
            cout << node->val << " ";
            s.pop();
            if (node->right!=nullptr) s.push(node->right);
            if (node->left!=nullptr) s.push(node->left);
        }
    }
    /*
        1) curr=root
        2) While stack not empty or curr!=null
            3) while curr!=null
                4) stack.push(curr)
                5) curr=curr->left
            6) stack.top() & stack.pop()
            7) curr=curr->right
    */
    void inOrderTraversal (TreeNode *root){
        if (root==nullptr) return;
        stack<TreeNode *> s;
        TreeNode *curr = root;
        while (!s.empty() || curr!=nullptr){
            while (curr!=nullptr){
                s.push(curr);
                curr=curr->left;
            }
            curr = s.top();
            cout << curr->val << " ";
            s.pop();

            curr=curr->right;
        }
    }
    /*
        1) stack_1.push(root)
        2) While stack_1 not empty
            3) node = stack_1.top() & stack_1.pop()
            4) stack_2.push(node)
            5) stack.push(leftNode) and after that stack.push(rightNode)
        6) visit all elements from stack_2
    */
    void postOrderTraversal (TreeNode *root){
        if (root==nullptr) return;
        stack<TreeNode *> s1,s2;
        s1.push(root);
        while(!s1.empty()){
            TreeNode *node = s1.top();
            s1.pop();
            s2.push(node); // key step
            if (node->left!=nullptr) s1.push(node->left);
            if (node->right!=nullptr) s1.push(node->right);
        }
        while (!s2.empty()){
            TreeNode *node = s2.top();
            cout << node->val << " ";
            s2.pop();
        }
    }
};

int main() {
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

    Solution sol;
    cout << "LevelOrderTraversal: ";
    sol.levelOrderTraversal(root);
    cout << endl;

    cout << "PreOderTraversal: ";
    sol.preOrderTraversal(root);
    cout << endl;

    cout << "InOrderTraversal: ";
    sol.inOrderTraversal(root);
    cout << endl;

    cout << "PostOrderTraversal: ";
    sol.postOrderTraversal(root);
    cout << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// we have 3 cases to consider:

// 1.      blue
//         /   
//        x
// We can color as blue #n-(sum(xChildren)+1) nodes
       
// 2.      x
//        / \   
//    blue  blank
// we can color as blue #leftXChildren nodes
     
// 2.      x
//        / \   
//    blank  blue
// we can color as blue #rightXChildren nodes

// return max>n/2;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    const int LEFT = 0;
    const int RIGHT = 1;
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if (root==nullptr)
            return false;
        
        int leftChildrenOfX = (n-1)/2;
        int rightChildrenOfX = (n-1)/2;
        
        TreeNode* redNode = findRedNode(root,x);
        
        leftChildrenOfX = countNodes(redNode->left);
        rightChildrenOfX = countNodes(redNode->right);
        
        int maxNodes = max(leftChildrenOfX,rightChildrenOfX);
        maxNodes = max(maxNodes,n-(leftChildrenOfX+rightChildrenOfX+1));
        
        return maxNodes>n/2;
    }
    
    TreeNode* findRedNode(TreeNode* root, int x){ // Time: O(n) & Space: O(n)
        if (root==nullptr)
            return nullptr;
        
        if (root->val==x)
            return root;
        
        TreeNode* left = findRedNode(root->left,x);
        
        if (left!=nullptr && left->val==x)
            return left;
        else return findRedNode(root->right,x);
    }
    
    int countNodes(TreeNode* root){ // Time: O(n) & Space: O(n)
        if (root==nullptr)
            return 0;
        else return 1+countNodes(root->left)+countNodes(root->right);
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);

    int n = 11;
    int x = 3;

    Solution sol;
    sol.btreeGameWinningMove(root,n,x) ? cout << "true\n" : cout << "false\n";

    return 0;
}

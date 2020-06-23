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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution { // count from roots
public:
    int countNodes(TreeNode* root) {
        if (root==nullptr)
            return 0;
        
        int left_counter = 1+countNodes(root->left);
        int right_counter = 1+countNodes(root->right);
        
        return left_counter+right_counter-1;
    }
};
// Time: O(n)
// Space: O(log n)

class BottomUPSolution { // count from leaves
public:
    int countNodes(TreeNode* root) {
        if (root==nullptr)
            return 0;
        
        int left_counter = countNodes(root->left);
        int right_counter = countNodes(root->right);
        
        return left_counter+right_counter+1;
    }
};
// Time: O(n)
// Space: O(log n)

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution sol;
    cout << sol.countNodes(root) << endl;

    return 0;
}

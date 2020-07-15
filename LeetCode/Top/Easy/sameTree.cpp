#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
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

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && q || p && !q)
            return false;
        
        if (p && q && p->val != q->val)
            return false;
        
        if (!p && !q)
            return true;
        
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
// Time: O(n)
// Space: O(h)

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution sol;
    sol.isSameTree(root,root) ? cout << "True\n" : cout << "False\n";

    return 0;
}

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
    bool isValidBST(TreeNode* root) {
        return valid(root);
    }

    bool valid(TreeNode* root,double lower=double(INT_MIN)-1,double upper=double(INT_MAX)+1) {
        if (root==nullptr) return true;
        
        if (root->val <= lower) return false;
        if (root->val >= upper) return false;
        
        if (valid(root->left,lower,(double)root->val) && valid(root->right,(double)root->val,upper))
            return true;

        return false;
    }
};

int main(){
/*     TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
 */
    TreeNode *root = new TreeNode(1);
    root->left= new TreeNode(INT_MIN);

/*     TreeNode * root=nullptr; */

    Solution sol;
    sol.isValidBST(root)?(cout << "true" << endl):(cout << "false" << endl);
    
/*     delete root->left;
    delete root->right; */
    delete root;

    return 0;
}

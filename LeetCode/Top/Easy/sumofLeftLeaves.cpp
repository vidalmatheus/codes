#include <bits/stdc++.h>

using namespace std;

namespace helper{
    #include "../Medium/BinaryTreeFromLevelOrder.cpp"
}

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int sumOfLeftLeaves(helper::TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        if (root->left && !root->left->left && !root->left->right)
            return root->left->val + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    vector<string> levelOrder = {"3","9","20","null","null","15","7"};

    helper::Solution build;
    helper::TreeNode * root = build.binaryTreeFromLevelOrder(levelOrder);

    Solution sol;
    assert(sol.sumOfLeftLeaves(root) == 24);

    cout << "Passed!" << endl;
    return 0;
}
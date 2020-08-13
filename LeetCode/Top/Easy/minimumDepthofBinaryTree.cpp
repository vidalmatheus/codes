#include <bits/stdc++.h>

namespace helper {
    #include "../Medium/BinaryTreeFromLevelOrder.cpp"
}

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int minDepth(helper::TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int min_depth = INT_MAX;
        dfs(root,min_depth,1);
        
        return min_depth;
    }
    
    void dfs(helper::TreeNode* root, int& min_depth, int level){
        if (root == nullptr)
            return;
        
        if (!root->left && !root->right){
            min_depth = min(min_depth,level);
            return;
        }
        
        dfs(root->left,min_depth,level+1);
        dfs(root->right,min_depth,level+1);
    }
};
// Time: O(n)
// Space: O(h)

class BetterSolution {
public:
    int minDepth(helper::TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        if (!root->left)
            return 1 + minDepth(root->right);
        
        if (!root->right)
            return 1 + minDepth(root->left);
        
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
// Time: O(n)
// Space: O(h)

int main(){
    vector<string> levelOrder = {"3","9","20","null","null","15","7"};
    
    helper::Solution gen;
    helper::TreeNode* root = gen.binaryTreeFromLevelOrder(levelOrder);

    BetterSolution sol;
    cout << sol.minDepth(root) << endl;

    return 0;

}

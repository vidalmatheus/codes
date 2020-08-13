#include <bits/stdc++.h>

using namespace std;

namespace helper {
    #include "../Medium/BinaryTreeFromLevelOrder.cpp"
}

auto speedup=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int pathSum(helper::TreeNode* root, int sum) {
        if (root == nullptr)
            return 0;
        
        int left = pathSum(root->left, sum);
        int right = pathSum(root->right, sum);
        int fromRoot = pathSumFromRoot(root, sum);
        
        return left + fromRoot + right;
    }
    
    int pathSumFromRoot(helper::TreeNode* root, int sum){ // using root -> Time: O(n) & Space: O(h)
        if (root == nullptr)
            return 0;
        
        int resp = 0;
        if (sum == root->val)
            resp++;
        
        resp += pathSumFromRoot(root->left, sum - root->val);
        resp += pathSumFromRoot(root->right, sum - root->val);
        
        return resp;
    }
};
// Time: O(2^n)
// Space: O(2^n)

int main(){
    vector<string> tree = {"10","5","-3","3","2","null","11","3","-2","null","1"};
    int sum = 8;

    helper::Solution gen;
    helper::TreeNode* root = gen.binaryTreeFromLevelOrder(tree);

    Solution sol;
    cout << sol.pathSum(root,sum) << endl;

    return 0;
}

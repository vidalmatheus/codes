#include <bits/stdc++.h>

using namespace std;

namespace helper {
    #include "BinaryTreeFromLevelOrder.cpp"
}

static int speedup=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> pathSum(helper::TreeNode* root, int sum) {
        if (root == nullptr)
            return {};
        
        vector<vector<int>> ans;
        vector<int> curr;
        pathSumFromRoot(root, sum, ans, curr);        
        return ans;
    }
    
    void pathSumFromRoot(helper::TreeNode* root, int sum, vector<vector<int>>& ans, vector<int>& curr){
        if (root == nullptr)
            return;
        
        curr.push_back(root->val);
        if (!root->left and !root->right and root->val == sum){
            ans.push_back(curr);
            curr.pop_back(); // Be careful with that! You always need to restore the current state of the recursion!
            return;
        }
            
        pathSumFromRoot(root->left, sum - root->val, ans, curr);
        pathSumFromRoot(root->right, sum - root->val, ans, curr);
        
        curr.pop_back();
    }
};
// Time: O(n*m), where m is the number of leaves
// Space: O(h*m), where h is the height of the tree

class SimilarSolution {
public:
    vector<vector<int>> pathSum(helper::TreeNode* root, int sum) {
        if (root == nullptr)
            return {};
        
        vector<vector<int>> ans;
        vector<int> curr;
        pathSumFromRoot(root, sum, ans, curr);        
        return ans;
    }
    
    void pathSumFromRoot(helper::TreeNode* root, int sum, vector<vector<int>>& ans, vector<int>& curr){
        if (root == nullptr)
            return;
        
        curr.push_back(root->val);

        pathSumFromRoot(root->left, sum - root->val, ans, curr);
        pathSumFromRoot(root->right, sum - root->val, ans, curr);

        if (!root->left and !root->right and root->val == sum)
            ans.push_back(curr);
        
        curr.pop_back();
    }
};
// Time: O(n*m), where m is the number of leaves
// Space: O(h*m), where h is the height of the tree

int main(){
    vector<string> tree = {"5","4","8","11","null","13","4","7","2","null","null","null","null","5","1"};
    int sum = 22;

    helper::Solution gen;
    helper::TreeNode* root = gen.binaryTreeFromLevelOrder(tree);

    cout << "Level Order: " << endl;
    gen.levelOrder(root);

    cout << "PreOrder: " << endl;
    gen.preOrder(root);
    cout << endl;

    Solution sol;
    vector<vector<int>> ans = sol.pathSum(root, sum);

    cout << "ans: " << endl;
    for (auto v : ans){
        for (int num : v)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}

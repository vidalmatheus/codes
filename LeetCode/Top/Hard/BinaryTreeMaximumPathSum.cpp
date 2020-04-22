#include<bits/stdc++.h>

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
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class SlowSolution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        
        int maxSum = INT_MIN;
        maxSumDFS(root,maxSum);
        
        return maxSum;
    }

    void maxSumDFS(TreeNode* root, int& maxSum){
        if (!root)
            return;
        
        maxSum = max(maxSum,maxSumFromTree(root));
        maxSumDFS(root->left,maxSum);
        maxSumDFS(root->right,maxSum);
    }
    
    int maxSumFromTree(TreeNode* root){
        int maxSum = INT_MIN;
        int fromLeft = INT_MIN;
        int fromRight = INT_MIN;
        if (root->left && root->right){
            dfs(root->left,0,fromLeft);
            dfs(root->right,0,fromRight);
            maxSum = max(maxSum,root->val);
            maxSum = max(maxSum,fromLeft+root->val+fromRight);
            maxSum = max(maxSum,fromLeft+root->val);
            maxSum = max(maxSum,root->val+fromRight);
            maxSum = max(maxSum,fromLeft);
            maxSum = max(maxSum,fromRight);
        }
        else if (root->left && !root->right){
            dfs(root->left,0,fromLeft);
            maxSum = max(maxSum,root->val);
            maxSum = max(maxSum,fromLeft+root->val);
            maxSum = max(maxSum,fromLeft);
        }
        else if (!root->left && root->right){
            dfs(root->right,0,fromRight);
            maxSum = max(maxSum,root->val);
            maxSum = max(maxSum,root->val+fromRight);
            maxSum = max(maxSum,fromRight);
        }
        else { // !root->left && !root->right
            maxSum = max(maxSum,root->val);
        }
        
        return maxSum;
    }


    void dfs(TreeNode* root, int sum,int& maxPathSum){
        if (!root)
            return;
        
        sum+=root->val;
        maxPathSum = max(maxPathSum,sum);
        
        dfs(root->left,sum,maxPathSum);
        dfs(root->right,sum,maxPathSum);
    }
};
// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        
        int maxSum = INT_MIN;
        rec(root,maxSum);

        return maxSum;
    }

    int rec(TreeNode* root, int& maxSum){
    // This does two things: returns the maximum path sum starting at the root, but also keep tracking the global maximum path sum! 
    // Tricky right? It's the same idea of an easy problem called Diameter of a Binary Tree. Beautiful!
        if (!root)
            return INT_MIN;
        
        int left = max(0,rec(root->left,maxSum));
        int right = max(0,rec(root->right,maxSum));

        maxSum = max(maxSum,root->val + left + right);

        return root->val + max(left,right);
    }
};
// Time: O(n)
// Spce: O(n)

int main(){
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // TreeNode* root = new TreeNode(2);
    // root->left = new TreeNode(-1);

    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(-2);
    // root->right = new TreeNode(3);

    Solution sol;
    cout << sol.maxPathSum(root) << endl;

    return 0;
}

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
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BruteForceSolution { // You are traversalling two times!
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root==nullptr)
            return 0;
        
        int maxDist = INT_MIN;
        dfs(root,maxDist);
        
        return maxDist;
    }
    
    void dfs(TreeNode* root, int& currMax){
        if (root==nullptr)
            return;
        
        int d = 2+height(root->left)+height(root->right);
        currMax = max(currMax,d);
        
        dfs(root->left,currMax);
        dfs(root->right,currMax);        
    }
    
    int height(TreeNode* root){ // Time: O(n) & Space: O(n)
        if (root==nullptr)
            return -1;
        return 1+max(height(root->left),height(root->right));
    }
};
// Time: O(n^2)
// Space: O(n)

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution { 
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root==nullptr)
            return 0;
        
        int maxDist = 0;
        height(root,maxDist);
        
        return maxDist;
    }
    
    int height(TreeNode* root, int& maxDist){ // Time: O(n) & Space: O(n)
        if (root==nullptr)
            return -1;
        int left = height(root->left,maxDist);
        int right = height(root->right,maxDist);
        maxDist = max(maxDist,2+left+right);
        return 1+max(left,right);
    }
};
// Time: O(n)
// Space: O(n)





#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class RecursiveSolution {
public:
    int longestZigZag(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        if (root->left == nullptr && root->right == nullptr)
            return 0;
        
        int max_len = INT_MIN;
        dfs(root,0,0,max_len,true);
        dfs(root,0,0,max_len,false);
        
        max_len = max(max_len,longestZigZag(root->left));
        max_len = max(max_len,longestZigZag(root->right));
        
        return max_len;
    }
    
    void dfs(TreeNode* root, int left, int right, int& max_len, bool goLeftFirst){
        if (root == nullptr)
            return;
        
        max_len = max(max_len, left + right);
    
        if (goLeftFirst){
            dfs(root->left,left+1,right,max_len,!goLeftFirst);
        }
        else{
            goLeftFirst = !goLeftFirst; // !false = true
            dfs(root->right,left,right+1,max_len,goLeftFirst);
        }
    }
};
// Time: O(2^n)
// Space: O(h)

class Solution { // memoization solution - O(n)
private:
    unordered_map<TreeNode*,int> memo;
public:
    int longestZigZag(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        if (root->left == nullptr && root->right == nullptr)
            return 0;
        
        int max_len = INT_MIN;
        if (memo.find(root->left) == memo.end()) zigzag_dfs(root,0,0,max_len,true);
        if (memo.find(root->right) == memo.end()) zigzag_dfs(root,0,0,max_len,false);
        
        max_len = max(max_len,longestZigZag(root->left));
        max_len = max(max_len,longestZigZag(root->right));
        
        return max_len;
    }
    
    void zigzag_dfs(TreeNode* root, int left, int right, int& max_len, bool goLeftFirst){
        if (root == nullptr)
            return;
            
        memo[root] = max_len = max(max_len, left + right);
        
        if (goLeftFirst){
            zigzag_dfs(root->left,left+1,right,max_len,!goLeftFirst);
        }
        else{
            goLeftFirst = !goLeftFirst; // !false = true
            zigzag_dfs(root->right,left,right+1,max_len,goLeftFirst);
        }
    }
};
// Time: O(n)
// Space: O(n)

class BestSolution {
public:
    int longestZigZag(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        if (root->left == nullptr && root->right == nullptr)
            return 0;
        
        int max_len = INT_MIN;
        zigzag_dfs(root,0,0,max_len,true);
        
        return max_len;
    }
        
    void zigzag_dfs(TreeNode* root, int left, int right, int& max_len, bool goLeftFirst){
        if (root == nullptr){
            max_len = max(max_len, left + right - 1);
            return;
        }
        
        if (goLeftFirst){
            zigzag_dfs(root->left,left+1,right,max_len,!goLeftFirst);
            zigzag_dfs(root->right,0,1,max_len,goLeftFirst);
        }
        else{
            goLeftFirst = !goLeftFirst; // !false = true
            zigzag_dfs(root->right,left,right+1,max_len,goLeftFirst);
            zigzag_dfs(root->left,1,0,max_len,!goLeftFirst);
        }
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    TreeNode * root = new TreeNode(1,new TreeNode(1), new TreeNode(1));

    Solution sol;
    cout << sol.longestZigZag(root) << endl;

    return 0;
}

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

class WrongSolution { // This is wrong!
public:
    int rob(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        vector<int> levelSum;
        bfs(root,levelSum);
        
        return robLinear(levelSum);
    }
    
    void bfs(TreeNode* root, vector<int>& levelSum){
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int size = q.size();
            int sum = 0;
            for (int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            levelSum.push_back(sum);
        }
    }
    
    int robLinear(vector<int>& nums){
        int n = nums.size();
        if (n == 0)
            return 0;
        
        if (n == 1)
            return 1;
        
        int pp = 0;
        int p = nums[0];
        int curr = 0;
        for (int i=1;i<n;i++){
            curr = max(p, pp + nums[i]);
            pp = p;
            p = curr;
        }
        
        return curr;
    }
};
// Time: O(n)
// Space: O(n)

class RecursionSolution { // TLE
public:
    int rob(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        return dfs(root, true);
    }
    
    int dfs(TreeNode* root, bool can){
        if (root == nullptr)
            return 0;
        
        if (can){
            // choosing
            int left = dfs(root->left, false);
            int right = dfs(root->right, false);
            int choosing = root->val + left + right;
            
            // not choosing
            left = dfs(root->left, true);
            right = dfs(root->right, true);
            int notChoosing = left + right;
            
            return max(choosing, notChoosing);
        }
        else return dfs(root->left, true) + dfs(root->right, true);
    }
};
// Time: O(n)
// Space: O(h)

class MemoSolution { // memoization - accepted
private:
    unordered_map<TreeNode*, int> canMemo;
    unordered_map<TreeNode*, int> cantMemo;
public:
    int rob(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        return dfs(root, true);
    }
    
    int dfs(TreeNode* root, bool can){
        if (root == nullptr)
            return 0;
        
        if (can){
            if (canMemo.find(root) != canMemo.end())
                return canMemo[root];
            else {
                // choosing
                int left = dfs(root->left, false);
                int right = dfs(root->right, false);
                int choosing = root->val + left + right;   
            
                // not choosing
                left = dfs(root->left, true);
                right = dfs(root->right, true);
                int notChoosing = left + right;
                
                return canMemo[root] = max(choosing, notChoosing);
            }
        }
        else {
            if (cantMemo.find(root) != cantMemo.end())
                return cantMemo[root];
            else {
                return cantMemo[root] = dfs(root->left, true) + dfs(root->right, true);
            }
        }
    }
};
// Time: O(n)
// Space: O(h)

int main(){
    MemoSolution sol;

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    
    assert(sol.rob(root) == 7);
    cout << "Passed!" << endl;
    return 0;
}
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

class FirstSolution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr)
            return nullptr;
        
        return dfs(cloned,target->val);
    }
    
    TreeNode* dfs(TreeNode* root, int val){
        if (root==nullptr)
            return nullptr;
        
        if (root->val==val)
            return root;
        
        TreeNode* response = dfs(root->left,val);
        if (!response)
            response = dfs(root->right,val);
        return response;
    }
};
// Time: O(n)
// Space: O(n)


class IterativeSolution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr)
            return nullptr;
        
        TreeNode* ans=nullptr;
        preOrderTraversal(cloned,target->val,ans);
        return ans;
    }
    
    void preOrderTraversal (TreeNode *root, int x, TreeNode*& ans){
        if (root==nullptr) return;
        stack<TreeNode *> s;
        s.push(root);
        while(!s.empty()){
            TreeNode *node = s.top();
            if (node->val==x){
                ans = node;
                return;
            }
            s.pop();
            if (node->right!=nullptr) s.push(node->right);
            if (node->left!=nullptr) s.push(node->left);
        }
    }
};
// Time: O(n)
// Space: O(n)

class VerySlowFollowUpSolution { // Follow up: Solve the problem if repeated values on the tree are allowed.
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr)
            return nullptr;
        
        TreeNode* ans=nullptr;
        string str = findPos(original,target,"");
        return dfs(cloned,"",str);
    }

    string findPos(TreeNode* root, TreeNode* x, string str){
        if (root==nullptr)
            return "";
        
        if (root==x)
            return str;
        
        string response = findPos(root->left,x,str+"L");
        if (response=="")
            response = findPos(root->right,x,str+"R");
        return response;
    }

    TreeNode* dfs(TreeNode* root, string curr, string& str){
        if (root==nullptr)
            return nullptr;
        
        if (curr==str)
            return root;
        
        TreeNode* response = dfs(root->left,curr+"L",str);
        if (!response)
            response = dfs(root->right,curr+"R",str);
        return response;
    }
};
// Time: O(n)
// Space: O(n)

class Solution { // Follow-up (Final solution)
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr)
            return nullptr;
        
        return dfs(original,cloned,target);
    }
    
    TreeNode* dfs(TreeNode* original, TreeNode* cloned, TreeNode* x){
        if (original==nullptr)
            return nullptr;
        
        if (original==x)
            return cloned;
        
        TreeNode* response = dfs(original->left,cloned->left,x);
        if (!response)
            response = dfs(original->right,cloned->right,x);
        return response;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    TreeNode* original = new TreeNode(7);
    original->left = new TreeNode(4);
    original->right = new TreeNode(3);
    original->right->left = new TreeNode(6);
    original->right->right = new TreeNode(19);

    TreeNode* target = original->right;

    TreeNode* cloned = new TreeNode(7);
    cloned->left = new TreeNode(4);
    cloned->right = new TreeNode(3);
    cloned->right->left = new TreeNode(6);
    cloned->right->right = new TreeNode(19);

    Solution sol;
    TreeNode* ans = sol.getTargetCopy(original,cloned,target);

    cout << ans->val << endl;

    return 0;
}

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

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr)
            return {};
        
        vector<string> ans;
        string curr = "";
        dfs(root,ans,curr);
        
        return ans;
    }
    
    void dfs(TreeNode *root, vector<string>& ans, string& curr){
        if (root == nullptr)
            return;
        
        if (!root->left && !root->right){
            ans.push_back(curr+to_string(root->val));
            return;
        }
        
        curr += to_string(root->val)+"->";
        dfs(root->left,ans,curr);
        dfs(root->right,ans,curr);
        int n = root->val == 0 ? 1 : floor(log10(abs(root->val)))+1; // number of digits
        if (root->val >= 0) curr.erase(curr.size()-n-2,n+2);
        else curr.erase(curr.size()-n-3,n+3);
    }
};
// Time: O(n)
// Space: O(h*M)

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);

    Solution sol;
    vector<string> ans = sol.binaryTreePaths(root);

    for (string s:ans)
        cout << s << endl;
        
    return 0;
}
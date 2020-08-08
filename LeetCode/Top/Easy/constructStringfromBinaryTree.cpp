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
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string tree2str(TreeNode* t) {
        if (!t)
            return "";
        if(!t->left && !t->right)
            return to_string(t->val);
        if(!t->right)
            return to_string(t->val)+"("+tree2str(t->left)+")";
        return to_string(t->val)+"("+tree2str(t->left)+")("+tree2str(t->right)+")";  
    }
};
// Time: O(n)
// Space: O(n)

class FasterSolution {
public:
    string tree2str(TreeNode* t) {
        if (t == nullptr)
            return "";
        
        string ans = "";
        dfs(t,ans);
        
        return ans;
    }
    
    void dfs(TreeNode* t, string& ans){
        if (t == nullptr)
            return;
    
        ans.append(to_string(t->val));
        if (t->right){
            ans.push_back('(');
            dfs(t->left,ans); // this maybe will do nothing, but it's fine
            ans.push_back(')');
            
            ans.push_back('(');
            dfs(t->right,ans);
            ans.push_back(')');
        }
        else if (t->left) {
            ans.push_back('(');
            dfs(t->left,ans);
            ans.push_back(')');
        }
    }   
};
// Time: O(n)
// Space: O(n)

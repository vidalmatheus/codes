#include <bits/stdc++.h>
using namespace std;

/*
20:34 - 21:14
             (0)
              1
            /   \
     (1) 2      3 (-1)
        /   \   / \
  (2) 4      5  6  7 (-2)
        \  (0) (0)
         8 (1)  
        /
  (2) 9 
  
  [4,2,8,1,5,6,3,7]

vertical level: 
1. [4], 
2. [2,8] or [8,2] 
3. [1,5,6],  => [5,1,6] is ok as well
4. [3], 
5. [7]
*/

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct TreeNode{
  int val;
  TreeNode* left, *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> solution(TreeNode* root){
        if (root==nullptr)
            return {};
        
        unordered_map<TreeNode*,int> tag;
        
        dfs(root,0,tag); // tag the nodes
        
        int minTag = INT_MAX;
        int maxTag = INT_MIN;
        for (auto e:tag){
            minTag = min(minTag,e.second);
            maxTag = max(maxTag,e.second);
        }
        
        vector<int> ans;
        for (int i=minTag;i<=maxTag;i++)
            dfs(root,ans,i,tag);
        
        return ans;
    }
    // Time: O(n^2)
    // Space: O(n^2)

    void dfs(TreeNode *root, int counter, unordered_map<TreeNode*,int>& tag){ // preorder 
        if (root==nullptr)
            return;
        
        tag[root]=counter; // O(1)
        dfs(root->left,counter-1,tag);
        dfs(root->right,counter+1,tag);
    }
    // Time: O(n)
    // Space: O(n)

    void dfs(TreeNode *root, vector<int>& ans, int lookingTag, unordered_map<TreeNode*,int>& tag){ // preorder
        if (root==nullptr)
            return;
        
        if (tag[root]==lookingTag)
            ans.push_back(root->val);
        
        dfs(root->left,ans,lookingTag,tag);
        dfs(root->right,ans,lookingTag,tag);
    }
};
// Time: O(n^2)
// Space: O(n^2)

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<int> ans = sol.solution(root);

    for (int e:ans)
        cout << e << " ";
  
    return 0;
}

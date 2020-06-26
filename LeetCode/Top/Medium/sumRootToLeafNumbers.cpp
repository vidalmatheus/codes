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

/*
    4
   / \
  9   0
 / \
5   1


    1
     \
      5
      
"1"

*/

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int sum = 0;
        string curr = "";
        dfs(root,curr,sum);
        
        return sum;
    }
    
    void dfs(TreeNode* root, string& curr, int& sum){
        if (root == nullptr)
            return;
        
        if (root->left == nullptr && root->right == nullptr){
            curr.push_back(to_string(root->val)[0]);
            sum += stoi(curr);
            return;
        }
        
        curr.push_back(to_string(root->val)[0]);
        dfs(root->left,curr,sum);
        if (root->left != nullptr) 
            curr.pop_back();
        dfs(root->right,curr,sum);
        if (root->right != nullptr)
            curr.pop_back();
    }
};
// Time: O(n)
// Space: O(h)

class OnlyIntegersSolution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int sum = 0;
        int curr = 0;
        dfs(root,curr,sum);
        
        return sum;
    }
    
    void dfs(TreeNode* root, int& curr, int& sum){
        if (root == nullptr)
            return;
        
        if (root->left == nullptr && root->right == nullptr){
            curr = curr*10 + root->val;
            sum += curr;
            return;
        }
        
        curr = curr*10 + root->val;
        dfs(root->left,curr,sum);
        if (root->left != nullptr) 
            curr /= 10;
        dfs(root->right,curr,sum);
        if (root->right != nullptr)
            curr /= 10;
    }
};
// Time: O(n)
// Space: O(h)


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution sol;
    cout << sol.sumNumbers(root) << endl;

    return 0;
}

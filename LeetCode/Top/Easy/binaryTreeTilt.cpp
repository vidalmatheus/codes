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
    #define  endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int findTilt(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int tiltSum = 0;
        dfs(root, tiltSum);
        
        return tiltSum;
    }
    
    int dfs(TreeNode* root, int& tiltSum){
        if (root == nullptr)
            return 0;
        
        int leftSum = dfs(root->left, tiltSum);
        int rightSum = dfs(root->right, tiltSum);
        int tilt = abs(leftSum-rightSum);
        tiltSum += tilt;
        
        return leftSum + rightSum + root->val;
    }
};
// Time: O(n)
// Space: O(h)

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  Solution sol;
  assert(sol.findTilt(root) == 1);
  cout << "Passed!" << endl;
  return 0;
}